/****************************************************************************
** Meta object code from reading C++ file 'mainwindowclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Deliverable_1/mainwindowclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindowClient_t {
    QByteArrayData data[8];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindowClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindowClient_t qt_meta_stringdata_MainWindowClient = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MainWindowClient"
QT_MOC_LITERAL(1, 17, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 32), // "on_queryPageSwitchButton_clicked"
QT_MOC_LITERAL(4, 73, 37), // "on_viewAnimalPageSwitchButton..."
QT_MOC_LITERAL(5, 111, 31), // "on_homePageSwitchButton_clicked"
QT_MOC_LITERAL(6, 143, 23), // "on_logoutButton_clicked"
QT_MOC_LITERAL(7, 167, 29) // "on_viewSelectedAnimal_clicked"

    },
    "MainWindowClient\0on_pushButton_clicked\0"
    "\0on_queryPageSwitchButton_clicked\0"
    "on_viewAnimalPageSwitchButton_clicked\0"
    "on_homePageSwitchButton_clicked\0"
    "on_logoutButton_clicked\0"
    "on_viewSelectedAnimal_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindowClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindowClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindowClient *_t = static_cast<MainWindowClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_queryPageSwitchButton_clicked(); break;
        case 2: _t->on_viewAnimalPageSwitchButton_clicked(); break;
        case 3: _t->on_homePageSwitchButton_clicked(); break;
        case 4: _t->on_logoutButton_clicked(); break;
        case 5: _t->on_viewSelectedAnimal_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindowClient::staticMetaObject = {
    { &cuACSMainWindow::staticMetaObject, qt_meta_stringdata_MainWindowClient.data,
      qt_meta_data_MainWindowClient,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindowClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowClient.stringdata0))
        return static_cast<void*>(this);
    return cuACSMainWindow::qt_metacast(_clname);
}

int MainWindowClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = cuACSMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
