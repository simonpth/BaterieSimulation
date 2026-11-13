#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QQmlEngine>
#include <QList>
#include <QDateTime>

#include <QUrl>

struct Datapoint {
    Q_GADGET
    QML_VALUE_TYPE(datapoint)   // exposes it to QML as "datapoint"

    Q_PROPERTY(QDateTime dateTime MEMBER mDateTime)
    Q_PROPERTY(double netzbezug   MEMBER mNetzbezug)
    Q_PROPERTY(double einspeisung MEMBER mEinspeisung)

public:
    QDateTime mDateTime;
    double mNetzbezug = 0.0;
    double mEinspeisung = 0.0;
};

struct SimulatedDatapoint {
    Q_GADGET
    QML_VALUE_TYPE(simulatedDatapoint)   // exposes it to QML as "simulatedDatapoint"

    Q_PROPERTY(QDateTime dateTime MEMBER mDateTime)
    Q_PROPERTY(double netzbezug   MEMBER mNetzbezug)
    Q_PROPERTY(double einspeisung MEMBER mEinspeisung)

    Q_PROPERTY(int batteryCharge MEMBER mBatteryCharge)

public:
    QDateTime mDateTime;
    double mNetzbezug = 0.0;
    double mEinspeisung = 0.0;

    double mBatteryCharge = 0;
};

class Data : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QList<QString> files READ files NOTIFY filesChanged FINAL)
    Q_PROPERTY(QList<Datapoint> datapoints READ datapoints NOTIFY datapointsChanged FINAL)

    Q_PROPERTY(QList<SimulatedDatapoint> simulatedDatapoints READ simulatedDatapoints NOTIFY simulatedDatapointsChanged FINAL)
    Q_PROPERTY(double batterySize MEMBER mBatterySize)
    Q_PROPERTY(double savings MEMBER mSavings)
    QML_SINGLETON
public:
    Data(QObject* parent = nullptr);

    void parseCsv(const QByteArray &content);
    void readFile(const QUrl &path);
    Q_INVOKABLE void selectFile();
    Q_INVOKABLE void loadFSVData(const QString &folderPath = ":/qt/qml/BaterieSimulation/CSV");

    void sortDataPoints();

    const QList<QString>& files() { return mFiles; }
    const QList<Datapoint>& datapoints() { return mDatapoints; }

    Q_INVOKABLE void calculate(double batterySize);
    const QList<SimulatedDatapoint>& simulatedDatapoints() { return mSimulatedDatapoints; }

signals:
    void filesChanged();
    void datapointsChanged();
    void simulatedDatapointsChanged();

private:
    QList<Datapoint> mDatapoints;
    QList<QString> mFiles;

    double mBatterySize;
    double mSavings;
    QList<SimulatedDatapoint> mSimulatedDatapoints;
};

#endif // DATA_H
