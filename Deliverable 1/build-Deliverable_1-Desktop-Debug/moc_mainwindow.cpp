/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Deliverable_1/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[453];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 31), // "on_homePageSwitchButton_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 32), // "on_queryPageSwitchButton_clicked"
QT_MOC_LITERAL(4, 77, 36), // "on_addAnimalPageSwitchButton_..."
QT_MOC_LITERAL(5, 114, 36), // "on_addClientPageSwitchButton_..."
QT_MOC_LITERAL(6, 151, 37), // "on_viewAnimalPageSwitchButton..."
QT_MOC_LITERAL(7, 189, 37), // "on_viewClientPageSwitchButton..."
QT_MOC_LITERAL(8, 227, 16), // "handleViewWindow"
QT_MOC_LITERAL(9, 244, 25), // "on_runQueryButton_clicked"
QT_MOC_LITERAL(10, 270, 26), // "on_addAnimalButton_clicked"
QT_MOC_LITERAL(11, 297, 26), // "on_addClientButton_clicked"
QT_MOC_LITERAL(12, 324, 35), // "on_viewSelectedAnimalButton_c..."
QT_MOC_LITERAL(13, 360, 35), // "on_viewSelectedClientButton_c..."
QT_MOC_LITERAL(14, 396, 23), // "on_logoutButton_clicked"
QT_MOC_LITERAL(15, 420, 32) // "on_runACMAlgorithmButton_clicked"

    },
    "MainWindow\0on_homePageSwitchButton_clicked\0"
    "\0on_queryPageSwitchButton_clicked\0"
    "on_addAnimalPageSwitchButton_clicked\0"
    "on_addClientPageSwitchButton_clicked\0"
    "on_viewAnimalPageSwitchButton_clicked\0"
    "on_viewClientPageSwitchButton_clicked\0"
    "handleViewWindow\0on_runQueryButton_clicked\0"
    "on_addAnimalButton_clicked\0"
    "on_addClientButton_clicked\0"
    "on_viewSelectedAnimalButton_clicked\0"
    "on_viewSelectedClientButton_clicked\0"
    "on_logoutButton_clicked\0"
    "on_runACMAlgorithmButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_homePageSwitchButton_clicked(); break;
        case 1: _t->on_queryPageSwitchButton_clicked(); break;
        case 2: _t->on_addAnimalPageSwitchButton_clicked(); break;
        case 3: _t->on_addClientPageSwitchButton_clicked(); break;
        case 4: _t->on_viewAnimalPageSwitchButton_clicked(); break;
        case 5: _t->on_viewClientPageSwitchButton_clicked(); break;
        case 6: _t->handleViewWindow(); break;
        case 7: _t->on_runQueryButton_clicked(); break;
        case 8: _t->on_addAnimalButton_clicked(); break;
        case 9: _t->on_addClientButton_clicked(); break;
        case 10: _t->on_viewSelectedAnimalButton_clicked(); break;
        case 11: _t->on_viewSelectedClientButton_clicked(); break;
        case 12: _t->on_logoutButton_clicked(); break;
        case 13: _t->on_runACMAlgorithmButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &cuACSMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return cuACSMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = cuACSMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
