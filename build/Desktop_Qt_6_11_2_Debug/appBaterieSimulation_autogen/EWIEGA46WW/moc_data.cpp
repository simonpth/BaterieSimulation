/****************************************************************************
** Meta object code from reading C++ file 'data.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../data.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'data.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN9DatapointE_t {};
} // unnamed namespace

template <> constexpr inline auto Datapoint::qt_create_metaobjectdata<qt_meta_tag_ZN9DatapointE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Datapoint",
        "QML.Element",
        "datapoint",
        "dateTime",
        "netzbezug",
        "einspeisung"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'dateTime'
        QtMocHelpers::PropertyData<QDateTime>(3, QMetaType::QDateTime, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'netzbezug'
        QtMocHelpers::PropertyData<double>(4, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'einspeisung'
        QtMocHelpers::PropertyData<double>(5, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<Datapoint, void>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject Datapoint::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9DatapointE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9DatapointE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9DatapointE_t>.metaTypes,
    nullptr
} };

void Datapoint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<Datapoint *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QDateTime*>(_v) = _t->mDateTime; break;
        case 1: *reinterpret_cast<double*>(_v) = _t->mNetzbezug; break;
        case 2: *reinterpret_cast<double*>(_v) = _t->mEinspeisung; break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: QtMocHelpers::setProperty(_t->mDateTime, *reinterpret_cast<QDateTime*>(_v)); break;
        case 1: QtMocHelpers::setProperty(_t->mNetzbezug, *reinterpret_cast<double*>(_v)); break;
        case 2: QtMocHelpers::setProperty(_t->mEinspeisung, *reinterpret_cast<double*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN18SimulatedDatapointE_t {};
} // unnamed namespace

template <> constexpr inline auto SimulatedDatapoint::qt_create_metaobjectdata<qt_meta_tag_ZN18SimulatedDatapointE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SimulatedDatapoint",
        "QML.Element",
        "simulatedDatapoint",
        "dateTime",
        "netzbezug",
        "einspeisung",
        "batteryCharge"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'dateTime'
        QtMocHelpers::PropertyData<QDateTime>(3, QMetaType::QDateTime, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'netzbezug'
        QtMocHelpers::PropertyData<double>(4, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'einspeisung'
        QtMocHelpers::PropertyData<double>(5, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'batteryCharge'
        QtMocHelpers::PropertyData<int>(6, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<SimulatedDatapoint, void>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject SimulatedDatapoint::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18SimulatedDatapointE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18SimulatedDatapointE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18SimulatedDatapointE_t>.metaTypes,
    nullptr
} };

void SimulatedDatapoint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<SimulatedDatapoint *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QDateTime*>(_v) = _t->mDateTime; break;
        case 1: *reinterpret_cast<double*>(_v) = _t->mNetzbezug; break;
        case 2: *reinterpret_cast<double*>(_v) = _t->mEinspeisung; break;
        case 3: *reinterpret_cast<int*>(_v) = _t->mBatteryCharge; break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: QtMocHelpers::setProperty(_t->mDateTime, *reinterpret_cast<QDateTime*>(_v)); break;
        case 1: QtMocHelpers::setProperty(_t->mNetzbezug, *reinterpret_cast<double*>(_v)); break;
        case 2: QtMocHelpers::setProperty(_t->mEinspeisung, *reinterpret_cast<double*>(_v)); break;
        case 3: QtMocHelpers::setProperty(_t->mBatteryCharge, *reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN4DataE_t {};
} // unnamed namespace

template <> constexpr inline auto Data::qt_create_metaobjectdata<qt_meta_tag_ZN4DataE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Data",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "filesChanged",
        "",
        "datapointsChanged",
        "simulatedDatapointsChanged",
        "selectFile",
        "loadFSVData",
        "folderPath",
        "calculate",
        "batterySize",
        "files",
        "datapoints",
        "QList<Datapoint>",
        "simulatedDatapoints",
        "QList<SimulatedDatapoint>",
        "savings"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'filesChanged'
        QtMocHelpers::SignalData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'datapointsChanged'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'simulatedDatapointsChanged'
        QtMocHelpers::SignalData<void()>(8, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'selectFile'
        QtMocHelpers::MethodData<void()>(9, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'loadFSVData'
        QtMocHelpers::MethodData<void(const QString &)>(10, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 11 },
        }}),
        // Method 'loadFSVData'
        QtMocHelpers::MethodData<void()>(10, 6, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Method 'calculate'
        QtMocHelpers::MethodData<void(double)>(12, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 13 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'files'
        QtMocHelpers::PropertyData<QList<QString>>(14, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Final, 0),
        // property 'datapoints'
        QtMocHelpers::PropertyData<QList<Datapoint>>(15, 0x80000000 | 16, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Final, 1),
        // property 'simulatedDatapoints'
        QtMocHelpers::PropertyData<QList<SimulatedDatapoint>>(17, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Final, 2),
        // property 'batterySize'
        QtMocHelpers::PropertyData<double>(13, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'savings'
        QtMocHelpers::PropertyData<double>(19, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<Data, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject Data::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN4DataE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN4DataE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN4DataE_t>.metaTypes,
    nullptr
} };

void Data::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Data *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->filesChanged(); break;
        case 1: _t->datapointsChanged(); break;
        case 2: _t->simulatedDatapointsChanged(); break;
        case 3: _t->selectFile(); break;
        case 4: _t->loadFSVData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->loadFSVData(); break;
        case 6: _t->calculate((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Data::*)()>(_a, &Data::filesChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Data::*)()>(_a, &Data::datapointsChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Data::*)()>(_a, &Data::simulatedDatapointsChanged, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QList<QString>*>(_v) = _t->files(); break;
        case 1: *reinterpret_cast<QList<Datapoint>*>(_v) = _t->datapoints(); break;
        case 2: *reinterpret_cast<QList<SimulatedDatapoint>*>(_v) = _t->simulatedDatapoints(); break;
        case 3: *reinterpret_cast<double*>(_v) = _t->mBatterySize; break;
        case 4: *reinterpret_cast<double*>(_v) = _t->mSavings; break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 3: QtMocHelpers::setProperty(_t->mBatterySize, *reinterpret_cast<double*>(_v)); break;
        case 4: QtMocHelpers::setProperty(_t->mSavings, *reinterpret_cast<double*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *Data::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Data::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN4DataE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Data::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Data::filesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Data::datapointsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Data::simulatedDatapointsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
