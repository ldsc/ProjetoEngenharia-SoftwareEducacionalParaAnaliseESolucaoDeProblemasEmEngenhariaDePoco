/****************************************************************************
** Meta object code from reading C++ file 'CSimuladorPerdaTubulacao.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../CSimuladorPerdaTubulacao.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
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
    "TempInicial",
    "TempFinal",
    "profundidade",
    "QCustomPlot*",
    "plot",
    "on_btnRemoverFluido_clicked",
    "on_btnRemoverTrecho_clicked",
    "makePlotPoco",
    "on_btnCalcularVariacoes_clicked",
    "on_actionArquivo_Dat_triggered"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN24CSimuladorPerdaTubulacaoE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    1 /* Private */,
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    4,   78,    2, 0x08,    5 /* Private */,
      12,    0,   87,    2, 0x08,   10 /* Private */,
      13,    0,   88,    2, 0x08,   11 /* Private */,
      14,    0,   89,    2, 0x08,   12 /* Private */,
      15,    0,   90,    2, 0x08,   13 /* Private */,
      16,    0,   91,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 10,    7,    8,    9,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CSimuladorPerdaTubulacao::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
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
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<QCustomPlot *, std::false_type>,
        // method 'on_btnRemoverFluido_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnRemoverTrecho_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'makePlotPoco'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnCalcularVariacoes_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionArquivo_Dat_triggered'
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
        case 4: _t->makePlotTemperatura((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QCustomPlot*>>(_a[4]))); break;
        case 5: _t->on_btnRemoverFluido_clicked(); break;
        case 6: _t->on_btnRemoverTrecho_clicked(); break;
        case 7: _t->makePlotPoco(); break;
        case 8: _t->on_btnCalcularVariacoes_clicked(); break;
        case 9: _t->on_actionArquivo_Dat_triggered(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 3:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QCustomPlot* >(); break;
            }
            break;
        }
    }
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
    return QMainWindow::qt_metacast(_clname);
}

int CSimuladorPerdaTubulacao::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
