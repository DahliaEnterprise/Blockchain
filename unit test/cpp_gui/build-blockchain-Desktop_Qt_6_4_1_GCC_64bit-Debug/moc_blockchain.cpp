/****************************************************************************
** Meta object code from reading C++ file 'blockchain.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../blockchain/blockchain.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blockchain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_blockchain_t {
    uint offsetsAndSizes[10];
    char stringdata0[11];
    char stringdata1[33];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_blockchain_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_blockchain_t qt_meta_stringdata_blockchain = {
    {
        QT_MOC_LITERAL(0, 10),  // "blockchain"
        QT_MOC_LITERAL(11, 32),  // "search_for_next_block_validation"
        QT_MOC_LITERAL(44, 0),  // ""
        QT_MOC_LITERAL(45, 20),  // "miner_new_connection"
        QT_MOC_LITERAL(66, 16)   // "miner_ready_read"
    },
    "blockchain",
    "search_for_next_block_validation",
    "",
    "miner_new_connection",
    "miner_ready_read"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_blockchain[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    1 /* Private */,
       3,    0,   33,    2, 0x08,    2 /* Private */,
       4,    0,   34,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject blockchain::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_blockchain.offsetsAndSizes,
    qt_meta_data_blockchain,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_blockchain_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<blockchain, std::true_type>,
        // method 'search_for_next_block_validation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'miner_new_connection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'miner_ready_read'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void blockchain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<blockchain *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->search_for_next_block_validation(); break;
        case 1: _t->miner_new_connection(); break;
        case 2: _t->miner_ready_read(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *blockchain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *blockchain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_blockchain.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int blockchain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
