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
    QByteArrayData data[11];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qtchart_kai_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qtchart_kai_t qt_meta_stringdata_Qtchart_kai = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Qtchart_kai"
QT_MOC_LITERAL(1, 12, 8), // "InitItem"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 17), // "clearPlainMessage"
QT_MOC_LITERAL(4, 40, 10), // "checkInput"
QT_MOC_LITERAL(5, 51, 8), // "writeTxt"
QT_MOC_LITERAL(6, 60, 11), // "return2Menu"
QT_MOC_LITERAL(7, 72, 6), // "runExe"
QT_MOC_LITERAL(8, 79, 7), // "readLog"
QT_MOC_LITERAL(9, 87, 14), // "slotUpdateDate"
QT_MOC_LITERAL(10, 102, 10) // "writePlain"

    },
    "Qtchart_kai\0InitItem\0\0clearPlainMessage\0"
    "checkInput\0writeTxt\0return2Menu\0runExe\0"
    "readLog\0slotUpdateDate\0writePlain"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qtchart_kai[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    1,   66,    2, 0x08 /* Private */,
      10,    1,   69,    2, 0x08 /* Private */,

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

       0        // eod
};

void Qtchart_kai::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Qtchart_kai *_t = static_cast<Qtchart_kai *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->InitItem(); break;
        case 1: _t->clearPlainMessage(); break;
        case 2: _t->checkInput(); break;
        case 3: _t->writeTxt(); break;
        case 4: _t->return2Menu(); break;
        case 5: _t->runExe(); break;
        case 6: _t->readLog(); break;
        case 7: _t->slotUpdateDate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->writePlain((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
