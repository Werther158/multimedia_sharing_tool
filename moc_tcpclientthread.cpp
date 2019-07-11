/****************************************************************************
** Meta object code from reading C++ file 'tcpclientthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "tcpclientthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpclientthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpClientThread_t {
    QByteArrayData data[6];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpClientThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpClientThread_t qt_meta_stringdata_TcpClientThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TcpClientThread"
QT_MOC_LITERAL(1, 16, 9), // "writeText"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "clientConnected"
QT_MOC_LITERAL(4, 43, 20), // "otherGuyDisconnected"
QT_MOC_LITERAL(5, 64, 24) // "stopReceivingVideoStream"

    },
    "TcpClientThread\0writeText\0\0clientConnected\0"
    "otherGuyDisconnected\0stopReceivingVideoStream"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpClientThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    0,   37,    2, 0x06 /* Public */,
       4,    0,   38,    2, 0x06 /* Public */,
       5,    1,   39,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void TcpClientThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpClientThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->writeText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->clientConnected(); break;
        case 2: _t->otherGuyDisconnected(); break;
        case 3: _t->stopReceivingVideoStream((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpClientThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClientThread::writeText)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpClientThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClientThread::clientConnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpClientThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClientThread::otherGuyDisconnected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TcpClientThread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClientThread::stopReceivingVideoStream)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TcpClientThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_TcpClientThread.data,
    qt_meta_data_TcpClientThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TcpClientThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpClientThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpClientThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int TcpClientThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TcpClientThread::writeText(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpClientThread::clientConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TcpClientThread::otherGuyDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TcpClientThread::stopReceivingVideoStream(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
