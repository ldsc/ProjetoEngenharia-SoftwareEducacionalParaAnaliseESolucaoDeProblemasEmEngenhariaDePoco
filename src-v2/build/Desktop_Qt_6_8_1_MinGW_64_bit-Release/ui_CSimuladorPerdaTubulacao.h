/********************************************************************************
** Form generated from reading UI file 'CSimuladorPerdaTubulacao.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSIMULADORPERDATUBULACAO_H
#define UI_CSIMULADORPERDATUBULACAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_CSimuladorPerdaTubulacao
{
public:
    QCustomPlot *customPlotPoco;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *btnAdicionarFluido;
    QPushButton *btnRemoverFluido;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tblFluidos;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QPushButton *btnAdicionarTrecho;
    QPushButton *btnRemoverTrecho;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tblTrechos;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *lbnTituloTemperaturaSuperiorInicial;
    QLabel *lbnTituloConfiguraoInicial;
    QLabel *lbnTituloTemperaturaFundoFinal;
    QLabel *lbnTituloConfiguraoFinal;
    QPushButton *btnAdicionarPropriedades;
    QLabel *lbnTituloProfunidadeTotal;
    QLabel *lbnTituloTemperaturaSuperiorFinal;
    QLineEdit *editProfundidadeTotal;
    QLineEdit *editTemperaturaFundoInicial;
    QCheckBox *checkBoxPacker;
    QLineEdit *editTemperaturaSuperiorFinal;
    QLineEdit *editTemperaturaFundoFinal;
    QLineEdit *editNomePoco;
    QSpacerItem *verticalSpacer;
    QPushButton *btnAtualizarDados;
    QLabel *lbnTituloNomePoco;
    QLabel *lbnTituloTemperaturaFundoInicial;
    QLineEdit *editTemperaturaSuperiorInicial;
    QLabel *lbnTituloProfundidadePacker;
    QLineEdit *editProfundidadePacker;
    QCustomPlot *customPlotTemperatura;

    void setupUi(QDialog *CSimuladorPerdaTubulacao)
    {
        if (CSimuladorPerdaTubulacao->objectName().isEmpty())
            CSimuladorPerdaTubulacao->setObjectName("CSimuladorPerdaTubulacao");
        CSimuladorPerdaTubulacao->resize(1432, 631);
        customPlotPoco = new QCustomPlot(CSimuladorPerdaTubulacao);
        customPlotPoco->setObjectName("customPlotPoco");
        customPlotPoco->setGeometry(QRect(1180, 230, 241, 391));
        gridLayoutWidget_2 = new QWidget(CSimuladorPerdaTubulacao);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(390, 10, 771, 321));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnAdicionarFluido = new QPushButton(gridLayoutWidget_2);
        btnAdicionarFluido->setObjectName("btnAdicionarFluido");

        gridLayout_2->addWidget(btnAdicionarFluido, 1, 0, 1, 1);

        btnRemoverFluido = new QPushButton(gridLayoutWidget_2);
        btnRemoverFluido->setObjectName("btnRemoverFluido");

        gridLayout_2->addWidget(btnRemoverFluido, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

        tblFluidos = new QTableWidget(gridLayoutWidget_2);
        if (tblFluidos->columnCount() < 5)
            tblFluidos->setColumnCount(5);
        QFont font;
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tblFluidos->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tblFluidos->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tblFluidos->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tblFluidos->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tblFluidos->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tblFluidos->setObjectName("tblFluidos");
        tblFluidos->horizontalHeader()->setDefaultSectionSize(153);

        gridLayout_2->addWidget(tblFluidos, 0, 0, 1, 3);

        gridLayoutWidget_3 = new QWidget(CSimuladorPerdaTubulacao);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(10, 340, 1151, 281));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        btnAdicionarTrecho = new QPushButton(gridLayoutWidget_3);
        btnAdicionarTrecho->setObjectName("btnAdicionarTrecho");

        gridLayout_3->addWidget(btnAdicionarTrecho, 1, 0, 1, 1);

        btnRemoverTrecho = new QPushButton(gridLayoutWidget_3);
        btnRemoverTrecho->setObjectName("btnRemoverTrecho");

        gridLayout_3->addWidget(btnRemoverTrecho, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        tblTrechos = new QTableWidget(gridLayoutWidget_3);
        if (tblTrechos->columnCount() < 9)
            tblTrechos->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tblTrechos->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tblTrechos->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        tblTrechos->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        tblTrechos->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font);
        tblTrechos->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        tblTrechos->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font);
        tblTrechos->setHorizontalHeaderItem(6, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font);
        tblTrechos->setHorizontalHeaderItem(7, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font);
        tblTrechos->setHorizontalHeaderItem(8, __qtablewidgetitem13);
        tblTrechos->setObjectName("tblTrechos");
        tblTrechos->setAutoScrollMargin(16);
        tblTrechos->horizontalHeader()->setMinimumSectionSize(37);
        tblTrechos->horizontalHeader()->setDefaultSectionSize(126);
        tblTrechos->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));

        gridLayout_3->addWidget(tblTrechos, 0, 0, 1, 3);

        gridLayoutWidget = new QWidget(CSimuladorPerdaTubulacao);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 371, 323));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 10, 0, 1, 2);

        lbnTituloTemperaturaSuperiorInicial = new QLabel(gridLayoutWidget);
        lbnTituloTemperaturaSuperiorInicial->setObjectName("lbnTituloTemperaturaSuperiorInicial");
        lbnTituloTemperaturaSuperiorInicial->setFont(font);
        lbnTituloTemperaturaSuperiorInicial->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloTemperaturaSuperiorInicial, 4, 0, 1, 1);

        lbnTituloConfiguraoInicial = new QLabel(gridLayoutWidget);
        lbnTituloConfiguraoInicial->setObjectName("lbnTituloConfiguraoInicial");
        lbnTituloConfiguraoInicial->setFont(font);
        lbnTituloConfiguraoInicial->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloConfiguraoInicial, 3, 0, 1, 3);

        lbnTituloTemperaturaFundoFinal = new QLabel(gridLayoutWidget);
        lbnTituloTemperaturaFundoFinal->setObjectName("lbnTituloTemperaturaFundoFinal");
        lbnTituloTemperaturaFundoFinal->setFont(font);
        lbnTituloTemperaturaFundoFinal->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloTemperaturaFundoFinal, 9, 0, 1, 1);

        lbnTituloConfiguraoFinal = new QLabel(gridLayoutWidget);
        lbnTituloConfiguraoFinal->setObjectName("lbnTituloConfiguraoFinal");
        lbnTituloConfiguraoFinal->setFont(font);
        lbnTituloConfiguraoFinal->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloConfiguraoFinal, 7, 0, 1, 3);

        btnAdicionarPropriedades = new QPushButton(gridLayoutWidget);
        btnAdicionarPropriedades->setObjectName("btnAdicionarPropriedades");

        gridLayout->addWidget(btnAdicionarPropriedades, 13, 0, 1, 1);

        lbnTituloProfunidadeTotal = new QLabel(gridLayoutWidget);
        lbnTituloProfunidadeTotal->setObjectName("lbnTituloProfunidadeTotal");
        lbnTituloProfunidadeTotal->setFont(font);
        lbnTituloProfunidadeTotal->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloProfunidadeTotal, 1, 0, 1, 1);

        lbnTituloTemperaturaSuperiorFinal = new QLabel(gridLayoutWidget);
        lbnTituloTemperaturaSuperiorFinal->setObjectName("lbnTituloTemperaturaSuperiorFinal");
        lbnTituloTemperaturaSuperiorFinal->setFont(font);
        lbnTituloTemperaturaSuperiorFinal->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloTemperaturaSuperiorFinal, 8, 0, 1, 1);

        editProfundidadeTotal = new QLineEdit(gridLayoutWidget);
        editProfundidadeTotal->setObjectName("editProfundidadeTotal");

        gridLayout->addWidget(editProfundidadeTotal, 1, 1, 1, 2);

        editTemperaturaFundoInicial = new QLineEdit(gridLayoutWidget);
        editTemperaturaFundoInicial->setObjectName("editTemperaturaFundoInicial");

        gridLayout->addWidget(editTemperaturaFundoInicial, 5, 1, 1, 2);

        checkBoxPacker = new QCheckBox(gridLayoutWidget);
        checkBoxPacker->setObjectName("checkBoxPacker");
        checkBoxPacker->setFont(font);

        gridLayout->addWidget(checkBoxPacker, 11, 0, 1, 2);

        editTemperaturaSuperiorFinal = new QLineEdit(gridLayoutWidget);
        editTemperaturaSuperiorFinal->setObjectName("editTemperaturaSuperiorFinal");

        gridLayout->addWidget(editTemperaturaSuperiorFinal, 8, 1, 1, 2);

        editTemperaturaFundoFinal = new QLineEdit(gridLayoutWidget);
        editTemperaturaFundoFinal->setObjectName("editTemperaturaFundoFinal");

        gridLayout->addWidget(editTemperaturaFundoFinal, 9, 1, 1, 1);

        editNomePoco = new QLineEdit(gridLayoutWidget);
        editNomePoco->setObjectName("editNomePoco");

        gridLayout->addWidget(editNomePoco, 0, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 2);

        btnAtualizarDados = new QPushButton(gridLayoutWidget);
        btnAtualizarDados->setObjectName("btnAtualizarDados");

        gridLayout->addWidget(btnAtualizarDados, 13, 1, 1, 2);

        lbnTituloNomePoco = new QLabel(gridLayoutWidget);
        lbnTituloNomePoco->setObjectName("lbnTituloNomePoco");
        lbnTituloNomePoco->setFont(font);
        lbnTituloNomePoco->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloNomePoco, 0, 0, 1, 1);

        lbnTituloTemperaturaFundoInicial = new QLabel(gridLayoutWidget);
        lbnTituloTemperaturaFundoInicial->setObjectName("lbnTituloTemperaturaFundoInicial");
        lbnTituloTemperaturaFundoInicial->setFont(font);
        lbnTituloTemperaturaFundoInicial->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloTemperaturaFundoInicial, 5, 0, 1, 1);

        editTemperaturaSuperiorInicial = new QLineEdit(gridLayoutWidget);
        editTemperaturaSuperiorInicial->setObjectName("editTemperaturaSuperiorInicial");

        gridLayout->addWidget(editTemperaturaSuperiorInicial, 4, 1, 1, 2);

        lbnTituloProfundidadePacker = new QLabel(gridLayoutWidget);
        lbnTituloProfundidadePacker->setObjectName("lbnTituloProfundidadePacker");
        lbnTituloProfundidadePacker->setFont(font);
        lbnTituloProfundidadePacker->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloProfundidadePacker, 12, 0, 1, 1);

        editProfundidadePacker = new QLineEdit(gridLayoutWidget);
        editProfundidadePacker->setObjectName("editProfundidadePacker");

        gridLayout->addWidget(editProfundidadePacker, 12, 1, 1, 1);

        customPlotTemperatura = new QCustomPlot(CSimuladorPerdaTubulacao);
        customPlotTemperatura->setObjectName("customPlotTemperatura");
        customPlotTemperatura->setGeometry(QRect(1180, 10, 241, 211));

        retranslateUi(CSimuladorPerdaTubulacao);

        QMetaObject::connectSlotsByName(CSimuladorPerdaTubulacao);
    } // setupUi

    void retranslateUi(QDialog *CSimuladorPerdaTubulacao)
    {
        CSimuladorPerdaTubulacao->setWindowTitle(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Dialog", nullptr));
        btnAdicionarFluido->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Adicionar Fluido", nullptr));
        btnRemoverFluido->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Remover Fluido", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblFluidos->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Nome", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblFluidos->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Densidade (lbm/gal)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblFluidos->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Viscosidade (cP)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblFluidos->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Prof. Inicial (ft)", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblFluidos->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Prof. Final (ft)", nullptr));
        btnAdicionarTrecho->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Adicionar Trecho", nullptr));
        btnRemoverTrecho->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Remover Trecho", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblTrechos->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Trecho", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblTrechos->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Prof. Inicial (ft)", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblTrechos->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Prof. Final (ft)", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblTrechos->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Diam. Externo (in)", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblTrechos->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Diam Interno (in)", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblTrechos->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Coef. Poisson", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblTrechos->horizontalHeaderItem(6);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Coef. Exp. T\303\251rm. (1/F)", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblTrechos->horizontalHeaderItem(7);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "M\303\263d. Elast. (psi)", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblTrechos->horizontalHeaderItem(8);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Peso/unid. (lb/ft)", nullptr));
        lbnTituloTemperaturaSuperiorInicial->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Temperatura de Superfice (\302\272F)", nullptr));
        lbnTituloConfiguraoInicial->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Configura\303\247\303\243o Inicial", nullptr));
        lbnTituloTemperaturaFundoFinal->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Temperatura de Fundo (\302\272F)", nullptr));
        lbnTituloConfiguraoFinal->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Configura\303\247\303\243o Final", nullptr));
        btnAdicionarPropriedades->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Adicionar Propriedade", nullptr));
        lbnTituloProfunidadeTotal->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Profundidade Total (ft)", nullptr));
        lbnTituloTemperaturaSuperiorFinal->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Temperatura de Superfice (\302\272F)", nullptr));
        checkBoxPacker->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "H\303\241 packer?", nullptr));
        btnAtualizarDados->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Atualizar Dados", nullptr));
        lbnTituloNomePoco->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Nome Po\303\247o", nullptr));
        lbnTituloTemperaturaFundoInicial->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Temperatura de Fundo (\302\272F)", nullptr));
        lbnTituloProfundidadePacker->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Profundidade do Packer (ft)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSimuladorPerdaTubulacao: public Ui_CSimuladorPerdaTubulacao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSIMULADORPERDATUBULACAO_H
