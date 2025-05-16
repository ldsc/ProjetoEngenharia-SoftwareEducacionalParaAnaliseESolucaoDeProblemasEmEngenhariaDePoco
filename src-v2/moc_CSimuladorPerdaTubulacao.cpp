/****************************************************************************
** Meta object code from reading C++ file 'CSimuladorPerdaTubulacao.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "CSimuladorPerdaTubulacao.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CSimuladorPerdaTubulacao.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CSimuladorPerdaTubulacao_t {
    QByteArrayData data[20];
    char stringdata0[447];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSimuladorPerdaTubulacao_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSimuladorPerdaTubulacao_t qt_meta_stringdata_CSimuladorPerdaTubulacao = {
    {
QT_MOC_LITERAL(0, 0, 24), // "CSimuladorPerdaTubulacao"
QT_MOC_LITERAL(1, 25, 35), // "on_btnAdicionarPropriedades_c..."
QT_MOC_LITERAL(2, 61, 0), // ""
QT_MOC_LITERAL(3, 62, 28), // "on_btnAtualizarDados_clicked"
QT_MOC_LITERAL(4, 91, 29), // "on_btnAdicionarTrecho_clicked"
QT_MOC_LITERAL(5, 121, 19), // "makePlotTemperatura"
QT_MOC_LITERAL(6, 141, 11), // "TempInicial"
QT_MOC_LITERAL(7, 153, 9), // "TempFinal"
QT_MOC_LITERAL(8, 163, 12), // "profundidade"
QT_MOC_LITERAL(9, 176, 12), // "QCustomPlot*"
QT_MOC_LITERAL(10, 189, 4), // "plot"
QT_MOC_LITERAL(11, 194, 27), // "on_btnRemoverFluido_clicked"
QT_MOC_LITERAL(12, 222, 27), // "on_btnRemoverTrecho_clicked"
QT_MOC_LITERAL(13, 250, 12), // "makePlotPoco"
QT_MOC_LITERAL(14, 263, 31), // "on_btnCalcularVariacoes_clicked"
QT_MOC_LITERAL(15, 295, 30), // "on_actionArquivo_Dat_triggered"
QT_MOC_LITERAL(16, 326, 15), // "EditarDadosPoco"
QT_MOC_LITERAL(17, 342, 32), // "on_actionNova_Simula_o_triggered"
QT_MOC_LITERAL(18, 375, 39), // "on_actionExportar_Como_Imagem..."
QT_MOC_LITERAL(19, 415, 31) // "on_actionSobre_o_SEEP_triggered"

    },
    "CSimuladorPerdaTubulacao\0"
    "on_btnAdicionarPropriedades_clicked\0"
    "\0on_btnAtualizarDados_clicked\0"
    "on_btnAdicionarTrecho_clicked\0"
    "makePlotTemperatura\0TempInicial\0"
    "TempFinal\0profundidade\0QCustomPlot*\0"
    "plot\0on_btnRemoverFluido_clicked\0"
    "on_btnRemoverTrecho_clicked\0makePlotPoco\0"
    "on_btnCalcularVariacoes_clicked\0"
    "on_actionArquivo_Dat_triggered\0"
    "EditarDadosPoco\0on_actionNova_Simula_o_triggered\0"
    "on_actionExportar_Como_Imagem_triggered\0"
    "on_actionSobre_o_SEEP_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSimuladorPerdaTubulacao[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    4,   82,    2, 0x08 /* Private */,
      11,    0,   91,    2, 0x08 /* Private */,
      12,    0,   92,    2, 0x08 /* Private */,
      13,    0,   93,    2, 0x08 /* Private */,
      14,    0,   94,    2, 0x08 /* Private */,
      15,    0,   95,    2, 0x08 /* Private */,
      16,    0,   96,    2, 0x08 /* Private */,
      17,    0,   97,    2, 0x08 /* Private */,
      18,    0,   98,    2, 0x08 /* Private */,
      19,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 9,    6,    7,    8,   10,
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

void CSimuladorPerdaTubulacao::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CSimuladorPerdaTubulacao *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btnAdicionarPropriedades_clicked(); break;
        case 1: _t->on_btnAtualizarDados_clicked(); break;
        case 2: _t->on_btnAdicionarTrecho_clicked(); break;
        case 3: _t->makePlotTemperatura((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< QCustomPlot*(*)>(_a[4]))); break;
        case 4: _t->on_btnRemoverFluido_clicked(); break;
        case 5: _t->on_btnRemoverTrecho_clicked(); break;
        case 6: _t->makePlotPoco(); break;
        case 7: _t->on_btnCalcularVariacoes_clicked(); break;
        case 8: _t->on_actionArquivo_Dat_triggered(); break;
        case 9: _t->EditarDadosPoco(); break;
        case 10: _t->on_actionNova_Simula_o_triggered(); break;
        case 11: _t->on_actionExportar_Como_Imagem_triggered(); break;
        case 12: _t->on_actionSobre_o_SEEP_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCustomPlot* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CSimuladorPerdaTubulacao::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CSimuladorPerdaTubulacao.data,
    qt_meta_data_CSimuladorPerdaTubulacao,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CSimuladorPerdaTubulacao::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSimuladorPerdaTubulacao::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CSimuladorPerdaTubulacao.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CSimuladorPerdaTubulacao::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
