/****************************************************************************
** Meta object code from reading C++ file 'camerathread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/camerathread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camerathread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CameraThread_t {
    QByteArrayData data[11];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraThread_t qt_meta_stringdata_CameraThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CameraThread"
QT_MOC_LITERAL(1, 13, 9), // "writeText"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "stopStream"
QT_MOC_LITERAL(4, 35, 17), // "setStreamingEnded"
QT_MOC_LITERAL(5, 53, 18), // "takeAScreenPicture"
QT_MOC_LITERAL(6, 72, 11), // "std::string"
QT_MOC_LITERAL(7, 84, 9), // "save_path"
QT_MOC_LITERAL(8, 94, 23), // "notifyAudioToMstCondVar"
QT_MOC_LITERAL(9, 118, 23), // "notifyVideoToMstCondVar"
QT_MOC_LITERAL(10, 142, 26) // "continueSendingScreenFrame"

    },
    "CameraThread\0writeText\0\0stopStream\0"
    "setStreamingEnded\0takeAScreenPicture\0"
    "std::string\0save_path\0notifyAudioToMstCondVar\0"
    "notifyVideoToMstCondVar\0"
    "continueSendingScreenFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    0,   52,    2, 0x06 /* Public */,
       4,    0,   53,    2, 0x06 /* Public */,
       5,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   57,    2, 0x0a /* Public */,
       9,    0,   58,    2, 0x0a /* Public */,
      10,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CameraThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CameraThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->writeText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->stopStream(); break;
        case 2: _t->setStreamingEnded(); break;
        case 3: _t->takeAScreenPicture((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: _t->notifyAudioToMstCondVar(); break;
        case 5: _t->notifyVideoToMstCondVar(); break;
        case 6: _t->continueSendingScreenFrame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CameraThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CameraThread::writeText)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CameraThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CameraThread::stopStream)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CameraThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CameraThread::setStreamingEnded)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CameraThread::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CameraThread::takeAScreenPicture)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CameraThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_CameraThread.data,
    qt_meta_data_CameraThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CameraThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CameraThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int CameraThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void CameraThread::writeText(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CameraThread::stopStream()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CameraThread::setStreamingEnded()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CameraThread::takeAScreenPicture(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
