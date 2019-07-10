/****************************************************************************
** Meta object code from reading C++ file 'frmrunning.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "frmrunning.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmrunning.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmRunning_t {
    QByteArrayData data[11];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmRunning_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmRunning_t qt_meta_stringdata_FrmRunning = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FrmRunning"
QT_MOC_LITERAL(1, 11, 18), // "on_btnStop_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 17), // "writeTextOnTxtBox"
QT_MOC_LITERAL(4, 49, 3), // "str"
QT_MOC_LITERAL(5, 53, 18), // "on_btnSend_clicked"
QT_MOC_LITERAL(6, 72, 15), // "clientConnected"
QT_MOC_LITERAL(7, 88, 20), // "otherGuyDisconnected"
QT_MOC_LITERAL(8, 109, 26), // "on_btnToggleConfig_clicked"
QT_MOC_LITERAL(9, 136, 17), // "startServerStream"
QT_MOC_LITERAL(10, 154, 24) // "on_btnStopStream_clicked"

    },
    "FrmRunning\0on_btnStop_clicked\0\0"
    "writeTextOnTxtBox\0str\0on_btnSend_clicked\0"
    "clientConnected\0otherGuyDisconnected\0"
    "on_btnToggleConfig_clicked\0startServerStream\0"
    "on_btnStopStream_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmRunning[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrmRunning::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmRunning *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnStop_clicked(); break;
        case 1: _t->writeTextOnTxtBox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_btnSend_clicked(); break;
        case 3: _t->clientConnected(); break;
        case 4: _t->otherGuyDisconnected(); break;
        case 5: _t->on_btnToggleConfig_clicked(); break;
        case 6: _t->startServerStream(); break;
        case 7: _t->on_btnStopStream_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmRunning::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FrmRunning.data,
    qt_meta_data_FrmRunning,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmRunning::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmRunning::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmRunning.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FrmRunning::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
