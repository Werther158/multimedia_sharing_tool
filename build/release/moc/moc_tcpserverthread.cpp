/****************************************************************************
** Meta object code from reading C++ file 'tcpserverthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/tcpserverthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserverthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpServerThread_t {
    QByteArrayData data[7];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpServerThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpServerThread_t qt_meta_stringdata_TcpServerThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TcpServerThread"
QT_MOC_LITERAL(1, 16, 9), // "writeText"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "clientConnected"
QT_MOC_LITERAL(4, 43, 20), // "otherGuyDisconnected"
QT_MOC_LITERAL(5, 64, 17), // "startServerStream"
QT_MOC_LITERAL(6, 82, 14) // "streamingEnded"

    },
    "TcpServerThread\0writeText\0\0clientConnected\0"
    "otherGuyDisconnected\0startServerStream\0"
    "streamingEnded"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpServerThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    0,   42,    2, 0x06 /* Public */,
       4,    0,   43,    2, 0x06 /* Public */,
       5,    0,   44,    2, 0x06 /* Public */,
       6,    0,   45,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpServerThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpServerThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->writeText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->clientConnected(); break;
        case 2: _t->otherGuyDisconnected(); break;
        case 3: _t->startServerStream(); break;
        case 4: _t->streamingEnded(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpServerThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServerThread::writeText)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpServerThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServerThread::clientConnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpServerThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServerThread::otherGuyDisconnected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TcpServerThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServerThread::startServerStream)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TcpServerThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServerThread::streamingEnded)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TcpServerThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_TcpServerThread.data,
    qt_meta_data_TcpServerThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TcpServerThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpServerThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpServerThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int TcpServerThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TcpServerThread::writeText(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpServerThread::clientConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TcpServerThread::otherGuyDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TcpServerThread::startServerStream()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void TcpServerThread::streamingEnded()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
