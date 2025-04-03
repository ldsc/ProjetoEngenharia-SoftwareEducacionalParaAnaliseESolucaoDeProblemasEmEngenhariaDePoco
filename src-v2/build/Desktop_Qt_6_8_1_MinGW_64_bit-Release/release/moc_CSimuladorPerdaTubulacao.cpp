/****************************************************************************
** Meta object code from reading C++ file 'CSimuladorPerdaTubulacao.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../CSimuladorPerdaTubulacao.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CSimuladorPerdaTubulacao.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN24CSimuladorPerdaTubulacaoE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN24CSimuladorPerdaTubulacaoE = QtMocHelpers::stringData(
    "CSimuladorPerdaTubulacao",
    "on_btnAdicionarFluido_clicked",
    "",
    "on_btnAdicionarPropriedades_clicked",
    "on_btnAtualizarDados_clicked",
    "on_btnAdicionarTrecho_clicked",
    "makePlotTemperatura",
    "on_btnRemoverFluido_clicked",
    "on_btnRemoverTrecho_clicked",
    "makePlotPoco"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN24CSimuladorPerdaTubulacaoE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // slots: parameters
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

Q_CONSTINIT const QMetaObject CSimuladorPerdaTubulacao::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ZN24CSimuladorPerdaTubulacaoE.offsetsAndSizes,
    qt_meta_data_ZN24CSimuladorPerdaTubulacaoE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN24CSimuladorPerdaTubulacaoE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CSimuladorPerdaTubulacao, std::true_type>,
        // method 'on_btnAdicionarFluido_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnAdicionarPropriedades_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnAtualizarDados_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnAdicionarTrecho_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'makePlotTemperatura'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnRemoverFluido_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnRemoverTrecho_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'makePlotPoco'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CSimuladorPerdaTubulacao::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<CSimuladorPerdaTubulacao *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_btnAdicionarFluido_clicked(); break;
        case 1: _t->on_btnAdicionarPropriedades_clicked(); break;
        case 2: _t->on_btnAtualizarDados_clicked(); break;
        case 3: _t->on_btnAdicionarTrecho_clicked(); break;
        case 4: _t->makePlotTemperatura(); break;
        case 5: _t->on_btnRemoverFluido_clicked(); break;
        case 6: _t->on_btnRemoverTrecho_clicked(); break;
        case 7: _t->makePlotPoco(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *CSimuladorPerdaTubulacao::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSimuladorPerdaTubulacao::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN24CSimuladorPerdaTubulacaoE.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CSimuladorPerdaTubulacao::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
