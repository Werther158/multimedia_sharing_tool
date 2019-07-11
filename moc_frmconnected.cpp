/****************************************************************************
** Meta object code from reading C++ file 'frmconnected.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "frmconnected.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmconnected.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmConnected_t {
    QByteArrayData data[14];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmConnected_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmConnected_t qt_meta_stringdata_FrmConnected = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FrmConnected"
QT_MOC_LITERAL(1, 13, 24), // "on_btnDisconnect_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 18), // "on_btnSend_clicked"
QT_MOC_LITERAL(4, 58, 17), // "writeTextOnTxtBox"
QT_MOC_LITERAL(5, 76, 3), // "str"
QT_MOC_LITERAL(6, 80, 15), // "clientConnected"
QT_MOC_LITERAL(7, 96, 20), // "otherGuyDisconnected"
QT_MOC_LITERAL(8, 117, 25), // "sendStartStreamingCommand"
QT_MOC_LITERAL(9, 143, 26), // "on_btnToggleConfig_clicked"
QT_MOC_LITERAL(10, 170, 28), // "on_btnStartStreaming_clicked"
QT_MOC_LITERAL(11, 199, 24), // "stopReceivingVideoStream"
QT_MOC_LITERAL(12, 224, 14), // "is_video_ended"
QT_MOC_LITERAL(13, 239, 14) // "streamingEnded"

    },
    "FrmConnected\0on_btnDisconnect_clicked\0"
    "\0on_btnSend_clicked\0writeTextOnTxtBox\0"
    "str\0clientConnected\0otherGuyDisconnected\0"
    "sendStartStreamingCommand\0"
    "on_btnToggleConfig_clicked\0"
    "on_btnStartStreaming_clicked\0"
    "stopReceivingVideoStream\0is_video_ended\0"
    "streamingEnded"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmConnected[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    1,   66,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    1,   74,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,

       0        // eod
};

void FrmConnected::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmConnected *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnDisconnect_clicked(); break;
        case 1: _t->on_btnSend_clicked(); break;
        case 2: _t->writeTextOnTxtBox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->clientConnected(); break;
        case 4: _t->otherGuyDisconnected(); break;
        case 5: _t->sendStartStreamingCommand(); break;
        case 6: _t->on_btnToggleConfig_clicked(); break;
        case 7: _t->on_btnStartStreaming_clicked(); break;
        case 8: _t->stopReceivingVideoStream((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->streamingEnded(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmConnected::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FrmConnected.data,
    qt_meta_data_FrmConnected,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmConnected::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmConnected::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmConnected.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FrmConnected::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
