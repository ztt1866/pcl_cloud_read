/****************************************************************************
** Meta object code from reading C++ file 'pcl_visualizer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pcl_visualizer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pcl_visualizer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_pcl_visualizer_t {
    QByteArrayData data[13];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pcl_visualizer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pcl_visualizer_t qt_meta_stringdata_pcl_visualizer = {
    {
QT_MOC_LITERAL(0, 0, 14), // "pcl_visualizer"
QT_MOC_LITERAL(1, 15, 9), // "onOpenpcl"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "onOpenpic"
QT_MOC_LITERAL(4, 36, 12), // "onOpenPicDir"
QT_MOC_LITERAL(5, 49, 14), // "onPushPrevious"
QT_MOC_LITERAL(6, 64, 10), // "onPushNext"
QT_MOC_LITERAL(7, 75, 9), // "onOpenBin"
QT_MOC_LITERAL(8, 85, 12), // "onOpenPcdDir"
QT_MOC_LITERAL(9, 98, 29), // "double_clicked_listwidget_pic"
QT_MOC_LITERAL(10, 128, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(11, 145, 4), // "item"
QT_MOC_LITERAL(12, 150, 29) // "double_clicked_listwidget_pcd"

    },
    "pcl_visualizer\0onOpenpcl\0\0onOpenpic\0"
    "onOpenPicDir\0onPushPrevious\0onPushNext\0"
    "onOpenBin\0onOpenPcdDir\0"
    "double_clicked_listwidget_pic\0"
    "QListWidgetItem*\0item\0"
    "double_clicked_listwidget_pcd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pcl_visualizer[] = {

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
      12,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void pcl_visualizer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pcl_visualizer *_t = static_cast<pcl_visualizer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onOpenpcl(); break;
        case 1: _t->onOpenpic(); break;
        case 2: _t->onOpenPicDir(); break;
        case 3: _t->onPushPrevious(); break;
        case 4: _t->onPushNext(); break;
        case 5: _t->onOpenBin(); break;
        case 6: _t->onOpenPcdDir(); break;
        case 7: _t->double_clicked_listwidget_pic((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->double_clicked_listwidget_pcd((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject pcl_visualizer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_pcl_visualizer.data,
      qt_meta_data_pcl_visualizer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pcl_visualizer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pcl_visualizer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pcl_visualizer.stringdata0))
        return static_cast<void*>(const_cast< pcl_visualizer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int pcl_visualizer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
