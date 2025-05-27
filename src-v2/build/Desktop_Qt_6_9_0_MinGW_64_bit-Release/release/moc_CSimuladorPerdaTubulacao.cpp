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
        "on_btnAdicionarPropriedades_clicked",
        "",
        "AtualizarDados",
        "on_btnAdicionarTrecho_clicked",
        "makePlotTemperatura",
        "TempInicial",
        "TempFinal",
        "profundidade",
        "QCustomPlot*",
        "plot",
        "on_btnRemoverTrecho_clicked",
        "makePlotPoco",
        "on_btnCalcularVariacoes_clicked",
        "on_actionArquivo_Dat_triggered",
        "EditarDadosPoco",
        "EditarLinhaTabela",
        "row",
        "on_actionNova_Simula_o_triggered",
        "on_actionExportar_Como_Imagem_triggered",
        "on_actionSobre_o_SEEP_triggered",
        "SalvarArquivo",
        "salvarComo",
        "on_actionSalvar_como_triggered",
        "on_actionSalvar_triggered",
        "NomeArquivo",
        "CaminhoArquivo",
        "nome",
        "caminho"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_btnAdicionarPropriedades_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'AtualizarDados'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnAdicionarTrecho_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'makePlotTemperatura'
        QtMocHelpers::SlotData<void(double, double, double, QCustomPlot *)>(5, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Double, 6 }, { QMetaType::Double, 7 }, { QMetaType::Double, 8 }, { 0x80000000 | 9, 10 },
        }}),
        // Slot 'on_btnRemoverTrecho_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'makePlotPoco'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnCalcularVariacoes_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionArquivo_Dat_triggered'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'EditarDadosPoco'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'EditarLinhaTabela'
        QtMocHelpers::SlotData<void(int)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Slot 'on_actionNova_Simula_o_triggered'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionExportar_Como_Imagem_triggered'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSobre_o_SEEP_triggered'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'SalvarArquivo'
        QtMocHelpers::SlotData<void(bool)>(21, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 22 },
        }}),
        // Slot 'on_actionSalvar_como_triggered'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSalvar_triggered'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'NomeArquivo'
        QtMocHelpers::SlotData<QString()>(25, 2, QMC::AccessPrivate, QMetaType::QString),
        // Slot 'CaminhoArquivo'
        QtMocHelpers::SlotData<QString()>(26, 2, QMC::AccessPrivate, QMetaType::QString),
        // Slot 'NomeArquivo'
        QtMocHelpers::SlotData<void(QString)>(25, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 27 },
        }}),
        // Slot 'CaminhoArquivo'
        QtMocHelpers::SlotData<void(QString)>(26, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 28 },
        }}),
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
        case 0: _t->on_btnAdicionarPropriedades_clicked(); break;
        case 1: _t->AtualizarDados(); break;
        case 2: _t->on_btnAdicionarTrecho_clicked(); break;
        case 3: _t->makePlotTemperatura((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QCustomPlot*>>(_a[4]))); break;
        case 4: _t->on_btnRemoverTrecho_clicked(); break;
        case 5: _t->makePlotPoco(); break;
        case 6: _t->on_btnCalcularVariacoes_clicked(); break;
        case 7: _t->on_actionArquivo_Dat_triggered(); break;
        case 8: _t->EditarDadosPoco(); break;
        case 9: _t->EditarLinhaTabela((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_actionNova_Simula_o_triggered(); break;
        case 11: _t->on_actionExportar_Como_Imagem_triggered(); break;
        case 12: _t->on_actionSobre_o_SEEP_triggered(); break;
        case 13: _t->SalvarArquivo((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->on_actionSalvar_como_triggered(); break;
        case 15: _t->on_actionSalvar_triggered(); break;
        case 16: { QString _r = _t->NomeArquivo();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 17: { QString _r = _t->CaminhoArquivo();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 18: _t->NomeArquivo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->CaminhoArquivo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
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
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
