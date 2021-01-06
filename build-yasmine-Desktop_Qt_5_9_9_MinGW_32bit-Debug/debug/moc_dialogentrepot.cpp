/****************************************************************************
** Meta object code from reading C++ file 'dialogentrepot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../yasmine/dialogentrepot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogentrepot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dialogentrepot_t {
    QByteArrayData data[17];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dialogentrepot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dialogentrepot_t qt_meta_stringdata_dialogentrepot = {
    {
QT_MOC_LITERAL(0, 0, 14), // "dialogentrepot"
QT_MOC_LITERAL(1, 15, 18), // "on_ajouter_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 19), // "on_tabent_activated"
QT_MOC_LITERAL(4, 55, 5), // "index"
QT_MOC_LITERAL(5, 61, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(6, 89, 14), // "on_del_clicked"
QT_MOC_LITERAL(7, 104, 14), // "on_edi_clicked"
QT_MOC_LITERAL(8, 119, 15), // "on_edit_clicked"
QT_MOC_LITERAL(9, 135, 17), // "on_editOk_clicked"
QT_MOC_LITERAL(10, 153, 21), // "on_delete_btn_clicked"
QT_MOC_LITERAL(11, 175, 21), // "on_search_textChanged"
QT_MOC_LITERAL(12, 197, 4), // "arg1"
QT_MOC_LITERAL(13, 202, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(14, 224, 19), // "on_prevcrud_clicked"
QT_MOC_LITERAL(15, 244, 31), // "on_search_cursorPositionChanged"
QT_MOC_LITERAL(16, 276, 4) // "arg2"

    },
    "dialogentrepot\0on_ajouter_clicked\0\0"
    "on_tabent_activated\0index\0"
    "on_tabWidget_currentChanged\0on_del_clicked\0"
    "on_edi_clicked\0on_edit_clicked\0"
    "on_editOk_clicked\0on_delete_btn_clicked\0"
    "on_search_textChanged\0arg1\0"
    "on_pushButton_clicked\0on_prevcrud_clicked\0"
    "on_search_cursorPositionChanged\0arg2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dialogentrepot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    1,   75,    2, 0x08 /* Private */,
       5,    1,   78,    2, 0x08 /* Private */,
       6,    0,   81,    2, 0x08 /* Private */,
       7,    0,   82,    2, 0x08 /* Private */,
       8,    0,   83,    2, 0x08 /* Private */,
       9,    0,   84,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    1,   86,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x08 /* Private */,
      14,    0,   90,    2, 0x08 /* Private */,
      15,    2,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   16,

       0        // eod
};

void dialogentrepot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dialogentrepot *_t = static_cast<dialogentrepot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ajouter_clicked(); break;
        case 1: _t->on_tabent_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_del_clicked(); break;
        case 4: _t->on_edi_clicked(); break;
        case 5: _t->on_edit_clicked(); break;
        case 6: _t->on_editOk_clicked(); break;
        case 7: _t->on_delete_btn_clicked(); break;
        case 8: _t->on_search_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_prevcrud_clicked(); break;
        //case 11: _t->on_search_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject dialogentrepot::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dialogentrepot.data,
      qt_meta_data_dialogentrepot,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *dialogentrepot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dialogentrepot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dialogentrepot.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int dialogentrepot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
