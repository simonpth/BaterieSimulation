#include "data.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QFileDialog>
#include <QApplication>

Data::Data(QObject *parent) : QObject(parent) {}


void Data::parseCsv(const QByteArray &content)
{
    QTextStream in(content);
    in.setEncoding(QStringConverter::Utf8);

    // Skip header line
    if (!in.atEnd())
        in.readLine();

    while (!in.atEnd()) {
        const QString line = in.readLine();
        if (line.isEmpty())
            continue;
        QStringList fields = line.split(';');
        if (fields.size() < 5)
            continue;
        // Strip surrounding quotes from each field
        for (QString &f : fields)
            f = f.remove('"');
        Datapoint dp;
        dp.mDateTime = QDateTime::fromString(fields[0], "yyyy-MM-dd HH:mm:ss");
        dp.mEinspeisung = fields[1].replace(',', '.').toDouble();
        dp.mNetzbezug   = fields[2].replace(',', '.').toDouble();
        // fields[3] = Direktverbrauch, fields[4] = Hausverbrauch — add if needed
        mDatapoints.append(dp);
    }
}

void Data::readFile(const QUrl &path)
{
    QString localPath = path.isLocalFile() ? path.toLocalFile() : path.toString();
    // Handles both file:// URLs (from FileDialog) and qrc:/ or : resource paths

    if (localPath.startsWith("qrc:"))
        localPath.remove(0, 3); // "qrc:/foo" -> ":/foo"

    if(mFiles.contains(localPath))
        return;

    QFile file(localPath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Could not open file:" << path;
        return;
    }
    const QByteArray content = file.readAll();
    file.close();

    parseCsv(content);

    mFiles.append(localPath);
    emit filesChanged();
    sortDataPoints();
    emit datapointsChanged();
}

void Data::selectFile()
{
    auto fileContentReady = [this](const QString &fileName, const QByteArray &fileContent) {
        if (fileName.isEmpty())
            return; // No file was selected

        if (mFiles.contains(fileName))
            return;

        parseCsv(fileContent);

        mFiles.append(fileName);
        emit filesChanged();
        sortDataPoints();
        emit datapointsChanged();
    };

    QFileDialog::getOpenFileContent("CSV Dateien (*.csv)", fileContentReady);
}

void Data::loadFSVData(const QString &folderPath) {
    QDir dir(folderPath);
    if (!dir.exists()) {
        qWarning() << "Folder does not exist:" << folderPath;
        return;
    }

    QStringList csvFiles = dir.entryList(QStringList() << "*.csv", QDir::Files);

    foreach (const QString &fileName, csvFiles) {
        QString fullPath = folderPath + "/" + fileName;
        QUrl url;

        if (folderPath.startsWith(":")) {
            // Resource path -> build a qrc:/ URL
            url = QUrl(QStringLiteral("qrc%1").arg(fullPath));
        } else {
            // Regular filesystem path -> build a file:// URL
            url = QUrl::fromLocalFile(fullPath);
        }

        readFile(url);
    }
}

void Data::sortDataPoints()
{
    std::sort(mDatapoints.begin(), mDatapoints.end(),
              [](const Datapoint &a, const Datapoint &b) {
                  return a.mDateTime < b.mDateTime;
              });
}

void Data::calculate(double batterySize)
{
    mSimulatedDatapoints.clear();
    mBatterySize = batterySize;
    mSavings = 0.0;

    double currentBatteryCharge = 0.0;

    foreach(Datapoint p, mDatapoints) {
        SimulatedDatapoint sp;
        sp.mDateTime = p.mDateTime;

        double change = 0.0;
        change -= p.mNetzbezug;
        change += p.mEinspeisung;

        change /= 6; // one data point every 10 min, so to get from W to Wh I have to divide by 6

        if(change > 0) {
            if(currentBatteryCharge < mBatterySize) {
                currentBatteryCharge += change;

                if(currentBatteryCharge > mBatterySize) {
                    sp.mEinspeisung = (currentBatteryCharge - mBatterySize) * 6;
                    currentBatteryCharge = mBatterySize;
                } else {
                    sp.mEinspeisung = 0.0;
                }
            } else {
                sp.mEinspeisung = change * 6;
            }
            sp.mNetzbezug = 0.0;
        } else {
            if (currentBatteryCharge > 0) {
                currentBatteryCharge += change;

                if(currentBatteryCharge < 0) {
                    sp.mNetzbezug = -currentBatteryCharge * 6;
                    currentBatteryCharge = 0;
                } else {
                    sp.mNetzbezug = 0.0;
                }
                mSavings += (p.mNetzbezug - sp.mNetzbezug) / 6;
            } else {
                sp.mNetzbezug = -change * 6;
            }
            sp.mEinspeisung = 0.0;
        }

        sp.mBatteryCharge = currentBatteryCharge;

        mSimulatedDatapoints.append(sp);
    }

    emit simulatedDatapointsChanged();
}