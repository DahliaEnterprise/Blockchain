/****************************************************************************
** Meta object code from reading C++ file 'blockchain_longest_chain_of_blocks.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../blockchain/blockchain_longest_chain_of_blocks.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blockchain_longest_chain_of_blocks.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_blockchain_longest_chain_of_blocks_t {
    uint offsetsAndSizes[2];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_blockchain_longest_chain_of_blocks_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_blockchain_longest_chain_of_blocks_t qt_meta_stringdata_blockchain_longest_chain_of_blocks = {
    {
        QT_MOC_LITERAL(0, 34)   // "blockchain_longest_chain_of_b..."
    },
    "blockchain_longest_chain_of_blocks"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_blockchain_longest_chain_of_blocks[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject blockchain_longest_chain_of_blocks::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_blockchain_longest_chain_of_blocks.offsetsAndSizes,
    qt_meta_data_blockchain_longest_chain_of_blocks,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_blockchain_longest_chain_of_blocks_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<blockchain_longest_chain_of_blocks, std::true_type>
    >,
    nullptr
} };

void blockchain_longest_chain_of_blocks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *blockchain_longest_chain_of_blocks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *blockchain_longest_chain_of_blocks::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_blockchain_longest_chain_of_blocks.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int blockchain_longest_chain_of_blocks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
