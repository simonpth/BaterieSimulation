/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<data.h>)
#  include <data.h>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_BaterieSimulation()
{
    qmlRegisterModule("BaterieSimulation", 254, 0);
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<Data>("BaterieSimulation", 254);
    qmlRegisterTypesAndRevisions<Datapoint>("BaterieSimulation", 254);
    QT_WARNING_POP
    qmlRegisterModule("BaterieSimulation", 254, 254);
}

static const QQmlModuleRegistration baterieSimulationRegistration("BaterieSimulation", qml_register_types_BaterieSimulation);
