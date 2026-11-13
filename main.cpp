#include <QGuiApplication>
#include <QApplication>
#include <QStyleHints>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGuiApplication::styleHints()->setColorScheme(Qt::ColorScheme::Light);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("BaterieSimulation", "Main");

    return QGuiApplication::exec();
}
