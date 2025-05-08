/****************************************************************************
** Meta object code from reading C++ file 'CSimuladorPerdaTubulacao.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
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
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
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

template <> constexpr inline auto CSimuladorPerdaTubulacao::qt_create_metaobjectdata<qt_meta_tag_ZN24CSimuladorPerdaTubulacaoE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
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
        "on_btnCalcularVariacoes_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_btnAdicionarFluido_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnAdicionarPropriedades_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnAtualizarDados_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnAdicionarTrecho_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'makePlotTemperatura'
        QtMocHelpers::SlotData<void(double, double, double, QCustomPlot *)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Double, 7 }, { QMetaType::Double, 8 }, { QMetaType::Double, 9 }, { 0x80000000 | 10, 11 },
        }}),
        // Slot 'on_btnRemoverFluido_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnRemoverTrecho_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'makePlotPoco'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnCalcularVariacoes_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<CSimuladorPerdaTubulacao, qt_meta_tag_ZN24CSimuladorPerdaTubulacaoE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject CSimuladorPerdaTubulacao::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24CSimuladorPerdaTubulacaoE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24CSimuladorPerdaTubulacaoE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN24CSimuladorPerdaTubulacaoE_t>.metaTypes,
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
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24CSimuladorPerdaTubulacaoE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CSimuladorPerdaTubulacao::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
