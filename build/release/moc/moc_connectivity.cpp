/****************************************************************************
** Meta object code from reading C++ file 'connectivity.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/connectivity.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectivity.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Connectivity_t {
    QByteArrayData data[10];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Connectivity_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Connectivity_t qt_meta_stringdata_Connectivity = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Connectivity"
QT_MOC_LITERAL(1, 13, 9), // "writeText"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "text"
QT_MOC_LITERAL(4, 29, 15), // "clientConnected"
QT_MOC_LITERAL(5, 45, 20), // "otherGuyDisconnected"
QT_MOC_LITERAL(6, 66, 17), // "startServerStream"
QT_MOC_LITERAL(7, 84, 24), // "stopReceivingVideoStream"
QT_MOC_LITERAL(8, 109, 14), // "streamingEnded"
QT_MOC_LITERAL(9, 124, 14) // "startStreaming"

    },
    "Connectivity\0writeText\0\0text\0"
    "clientConnected\0otherGuyDisconnected\0"
    "startServerStream\0stopReceivingVideoStream\0"
    "streamingEnded\0startStreaming"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Connectivity[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,
       6,    0,   54,    2, 0x06 /* Public */,
       7,    1,   55,    2, 0x06 /* Public */,
       8,    0,   58,    2, 0x06 /* Public */,
       9,    0,   59,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Connectivity::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Connectivity *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->writeText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->clientConnected(); break;
        case 2: _t->otherGuyDisconnected(); break;
        case 3: _t->startServerStream(); break;
        case 4: _t->stopReceivingVideoStream((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->streamingEnded(); break;
        case 6: _t->startStreaming(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Connectivity::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connectivity::writeText)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Connectivity::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connectivity::clientConnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Connectivity::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connectivity::otherGuyDisconnected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Connectivity::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connectivity::startServerStream)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Connectivity::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connectivity::stopReceivingVideoStream)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Connectivity::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connectivity::streamingEnded)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Connectivity::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connectivity::startStreaming)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Connectivity::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Connectivity.data,
    qt_meta_data_Connectivity,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Connectivity::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Connectivity::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Connectivity.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Connectivity::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Connectivity::writeText(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Connectivity::clientConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Connectivity::otherGuyDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Connectivity::startServerStream()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Connectivity::stopReceivingVideoStream(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Connectivity::streamingEnded()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Connectivity::startStreaming()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
