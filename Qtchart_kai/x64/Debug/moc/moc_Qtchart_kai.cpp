/****************************************************************************
** Meta object code from reading C++ file 'Qtchart_kai.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Qtchart_kai.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Qtchart_kai.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Qtchart_kai_t {
    QByteArrayData data[17];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtchart_kai_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtchart_kai_t qt_meta_stringdata_Qtchart_kai = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Qtchart_kai"
QT_MOC_LITERAL(1, 12, 9), // "senderMsg"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 3), // "msg"
QT_MOC_LITERAL(4, 27, 8), // "InitItem"
QT_MOC_LITERAL(5, 36, 17), // "clearPlainMessage"
QT_MOC_LITERAL(6, 54, 10), // "checkInput"
QT_MOC_LITERAL(7, 65, 8), // "writeTxt"
QT_MOC_LITERAL(8, 74, 11), // "return2Menu"
QT_MOC_LITERAL(9, 86, 6), // "runExe"
QT_MOC_LITERAL(10, 93, 7), // "readLog"
QT_MOC_LITERAL(11, 101, 14), // "slotUpdateDate"
QT_MOC_LITERAL(12, 116, 10), // "writePlain"
QT_MOC_LITERAL(13, 127, 8), // "onOutput"
QT_MOC_LITERAL(14, 136, 15), // "slotPointHoverd"
QT_MOC_LITERAL(15, 152, 5), // "point"
QT_MOC_LITERAL(16, 158, 5) // "state"

    },
    "Qtchart_kai\0senderMsg\0\0msg\0InitItem\0"
    "clearPlainMessage\0checkInput\0writeTxt\0"
    "return2Menu\0runExe\0readLog\0slotUpdateDate\0"
    "writePlain\0onOutput\0slotPointHoverd\0"
    "point\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtchart_kai[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   77,    2, 0x08 /* Private */,
       5,    0,   78,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    1,   84,    2, 0x08 /* Private */,
      12,    1,   87,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    2,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Bool,   15,   16,

       0        // eod
};

void Qtchart_kai::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Qtchart_kai *_t = static_cast<Qtchart_kai *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->senderMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->InitItem(); break;
        case 2: _t->clearPlainMessage(); break;
        case 3: _t->checkInput(); break;
        case 4: _t->writeTxt(); break;
        case 5: _t->return2Menu(); break;
        case 6: _t->runExe(); break;
        case 7: _t->readLog(); break;
        case 8: _t->slotUpdateDate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->writePlain((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->onOutput(); break;
        case 11: _t->slotPointHoverd((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Qtchart_kai::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Qtchart_kai::senderMsg)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Qtchart_kai::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Qtchart_kai.data,
      qt_meta_data_Qtchart_kai,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Qtchart_kai::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qtchart_kai::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Qtchart_kai.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Qtchart_kai::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Qtchart_kai::senderMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
