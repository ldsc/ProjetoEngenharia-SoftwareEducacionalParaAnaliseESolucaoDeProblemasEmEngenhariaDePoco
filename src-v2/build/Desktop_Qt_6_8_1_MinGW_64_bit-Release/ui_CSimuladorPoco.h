/********************************************************************************
** Form generated from reading UI file 'CSimuladorPoco.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSIMULADORPOCO_H
#define UI_CSIMULADORPOCO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_CSimuladorPoco
{
public:
    QAction *actionImportar_Dados;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *lbnTituloDiametroOD;
    QLabel *lbnTituloVazao;
    QPushButton *btnAtualizarDados;
    QLineEdit *editNomePoco;
    QLineEdit *editProfundidadeTotal;
    QLineEdit *editDiametroOD;
    QLabel *lbnTituloNomePoco;
    QLabel *lbnTituloProfunidadeTotal;
    QLineEdit *editDiametroID;
    QLabel *lbnTituloPressaoSuperficie;
    QSpacerItem *verticalSpacer;
    QLineEdit *editDiametroPoco;
    QLabel *lbnTituloDiametroPoco;
    QPushButton *btnAdicionarPropriedades;
    QLabel *lbnDensidadeMedia;
    QLabel *lbnTituloProfundidadeOcupada;
    QLabel *lbnViscosidadeMedia;
    QLabel *lbnProfundidadeOcupada;
    QLineEdit *editPressaoSuperficie;
    QLabel *lbnTituloDiametroID;
    QLineEdit *editVazao;
    QLabel *lbnTituloViscosidadeMedia;
    QLabel *lbnTituloDensidadeMedia;
    QSpacerItem *verticalSpacer_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *btnAdicionarFluido;
    QPushButton *btnRemoverFluido;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tblFluidos;
    QWidget *gridLayoutWidget_9;
    QGridLayout *gridLayout_9;
    QLabel *lbnTituloModeloNewtoniano;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *lbnTituloPerdaFriccionalPocoNewtoniano;
    QLabel *lbnTipoFluxoPocoNewtoniano;
    QLabel *lbnPerdaFriccionalPocoNewtoniano;
    QLabel *lbnTituloReynoldsPocoNewtoniano;
    QPushButton *btnCalcularModeloNewtonianoPoco;
    QLabel *lbnReynoldsPocoNewtoniano;
    QLabel *lbnTituloVelocidadePocoNewtoniano;
    QLabel *lbnTituloTipoFluxoPocoNewtoniano;
    QLabel *lbnVelocidadePocoNewtoniano;
    QWidget *tab_2;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLabel *lbnReynoldsAnularNewtoniano;
    QLabel *lbnTituloReynoldsAnularNewtoniano;
    QLabel *lbnVelocidadeAnularNewtoniano;
    QLabel *lbnTituloPerdaFriccionalAnularNewtoniano;
    QLabel *lbnTipoFluxoAnularNewtoniano;
    QLabel *lbnTituloTipoFluxoAnularNewtoniano;
    QLabel *lbnTituloVelocidadeAnularNewtoniano;
    QLabel *lbnPerdaFriccionalAnularNewtoniano;
    QPushButton *btnCalcularModeloNewtonianoAnular;
    QWidget *gridLayoutWidget_14;
    QGridLayout *gridLayout_14;
    QPushButton *btnCalcularPressaoHidroestatica;
    QLabel *lbnTituloProfundidadePressaoHidroestatica;
    QLabel *lbnTituloPressaoHidroestatica_2;
    QLabel *lbnPressaoHidroestatica;
    QLineEdit *editProfundidadePressaoHidroestatica;
    QSpacerItem *verticalSpacer_3;
    QLabel *lbnTituloPressaoHidroestatica;
    QWidget *gridLayoutWidget_10;
    QGridLayout *gridLayout_10;
    QLabel *lbnTituloModeloBigham;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QLabel *lbnTituloVelocidadePocoBigham;
    QLabel *lbnReynoldsPocoBigham;
    QLabel *lbnTituloPerdaFriccionalPocoBigham;
    QLabel *lbnVelocidadePocoBigham;
    QPushButton *btnCalcularModeloBighamPoco;
    QLineEdit *editPontoEscoamentoPoco;
    QLabel *lbnTituloHedstromPocoBigham;
    QLabel *lbnTituloViscosidadePlasticaPoco;
    QLabel *lbnPerdaFriccionalPocoBigham;
    QLineEdit *editViscosidadePlasticaPoco;
    QLabel *lbnTituloPontoEscoamentoPoco;
    QLabel *lbnTituloReynoldsPocoBigham;
    QLabel *lbnTituloTipoFluxoPocoBigham;
    QLabel *lbnTipoFluxoPocoBigham;
    QLabel *lbnTituloCriticoPocoBigham;
    QLabel *lbnReynoldsHedstromPocoBigham;
    QLabel *lbnReynoldsCriticoPocoBigham;
    QWidget *tab_4;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_6;
    QLineEdit *editPontoEscoamentoAnular;
    QLabel *lbnTituloHedstromAnularBigham;
    QPushButton *btnCalcularModeloBighamAnular;
    QLabel *lbnVelocidadeAnularBigham;
    QLabel *lbnReynoldsAnularBigham;
    QLabel *lbnTituloTipoFluxoAnularBigham;
    QLabel *lbnPerdaFriccionalAnularBigham;
    QLabel *lbnTituloPontoEscoamentoAnular;
    QLabel *lbnTituloReynoldsAnularBigham;
    QLineEdit *editViscosidadePlasticaAnular;
    QLabel *lbnTipoFluxoAnularBigham;
    QLabel *lbnTituloViscosidadePlasticaAnular;
    QLabel *lbnTituloVelocidadeAnularBigham;
    QLabel *lbnTituloPerdaFriccionalAnularBigham;
    QLabel *lbnTituloCriticoAnularBigham;
    QLabel *lbnReynoldsHedstromAnularBigham;
    QLabel *lbnReynoldsCriticoAnularBigham;
    QWidget *gridLayoutWidget_11;
    QGridLayout *gridLayout_11;
    QLabel *lbnTituloModeloBigham_2;
    QTabWidget *tabWidget_3;
    QWidget *tab_5;
    QWidget *gridLayoutWidget_7;
    QGridLayout *gridLayout_7;
    QLabel *lbnPerdaFriccionalPocoPotencia;
    QLabel *lbnTituloPerdaFriccionalPocoPotencia;
    QLabel *lbnVelocidadePocoPotencia;
    QLabel *lbnTipoFluxoPocoPotencia;
    QLabel *lbnTituloCriticoPocoPotencia;
    QLabel *lbnTituloReynoldsPocoPotencia;
    QLabel *lbnTituloVelocidadePocoPotencia;
    QLabel *lbnReynoldsPocoPotencia;
    QLabel *lbnTituloTipoFluxoPocoPotencia;
    QLabel *lbnReynoldsCriticoPocoPotencia;
    QPushButton *btnCalcularModeloPotenciaPoco;
    QLabel *lbnTituloIndiceConsistenciaPoco;
    QLineEdit *editIndiceConsistenciaPotenciaPoco;
    QWidget *tab_6;
    QWidget *gridLayoutWidget_8;
    QGridLayout *gridLayout_8;
    QLabel *lbnTipoFluxoAnularPotencia;
    QLabel *lbnTituloCriticoAnularPotencia;
    QLabel *lbnTituloTipoFluxoAnularPotencia;
    QLabel *lbnTituloReynoldsAnularPotencia;
    QLabel *lbnTituloVelocidadeAnularPotencia;
    QLabel *lbnReynoldsAnularPotencia;
    QLabel *lbnTituloPerdaFriccionalAnularPotencia;
    QLabel *lbnVelocidadeAnularPotencia;
    QLabel *lbnTituloIndiceConsistenciaAnular;
    QLabel *lbnPerdaFriccionalAnularPotencia;
    QLabel *lbnReynoldsCriticoAnularPotencia;
    QPushButton *btnCalcularModeloPotenciaAnular;
    QLineEdit *editIndiceConsistenciaPotenciaAnular;
    QCustomPlot *customPlotPoco;
    QMenuBar *menubar;
    QMenu *menuArquivo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CSimuladorPoco)
    {
        if (CSimuladorPoco->objectName().isEmpty())
            CSimuladorPoco->setObjectName("CSimuladorPoco");
        CSimuladorPoco->resize(1416, 732);
        actionImportar_Dados = new QAction(CSimuladorPoco);
        actionImportar_Dados->setObjectName("actionImportar_Dados");
        centralwidget = new QWidget(CSimuladorPoco);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 30, 371, 345));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lbnTituloDiametroOD = new QLabel(gridLayoutWidget);
        lbnTituloDiametroOD->setObjectName("lbnTituloDiametroOD");
        QFont font;
        font.setBold(true);
        lbnTituloDiametroOD->setFont(font);
        lbnTituloDiametroOD->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloDiametroOD, 4, 0, 1, 1);

        lbnTituloVazao = new QLabel(gridLayoutWidget);
        lbnTituloVazao->setObjectName("lbnTituloVazao");
        lbnTituloVazao->setFont(font);
        lbnTituloVazao->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloVazao, 6, 0, 1, 1);

        btnAtualizarDados = new QPushButton(gridLayoutWidget);
        btnAtualizarDados->setObjectName("btnAtualizarDados");

        gridLayout->addWidget(btnAtualizarDados, 13, 1, 1, 2);

        editNomePoco = new QLineEdit(gridLayoutWidget);
        editNomePoco->setObjectName("editNomePoco");

        gridLayout->addWidget(editNomePoco, 0, 1, 1, 2);

        editProfundidadeTotal = new QLineEdit(gridLayoutWidget);
        editProfundidadeTotal->setObjectName("editProfundidadeTotal");

        gridLayout->addWidget(editProfundidadeTotal, 1, 1, 1, 2);

        editDiametroOD = new QLineEdit(gridLayoutWidget);
        editDiametroOD->setObjectName("editDiametroOD");

        gridLayout->addWidget(editDiametroOD, 4, 1, 1, 2);

        lbnTituloNomePoco = new QLabel(gridLayoutWidget);
        lbnTituloNomePoco->setObjectName("lbnTituloNomePoco");
        lbnTituloNomePoco->setFont(font);
        lbnTituloNomePoco->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloNomePoco, 0, 0, 1, 1);

        lbnTituloProfunidadeTotal = new QLabel(gridLayoutWidget);
        lbnTituloProfunidadeTotal->setObjectName("lbnTituloProfunidadeTotal");
        lbnTituloProfunidadeTotal->setFont(font);
        lbnTituloProfunidadeTotal->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloProfunidadeTotal, 1, 0, 1, 1);

        editDiametroID = new QLineEdit(gridLayoutWidget);
        editDiametroID->setObjectName("editDiametroID");

        gridLayout->addWidget(editDiametroID, 5, 1, 1, 2);

        lbnTituloPressaoSuperficie = new QLabel(gridLayoutWidget);
        lbnTituloPressaoSuperficie->setObjectName("lbnTituloPressaoSuperficie");
        lbnTituloPressaoSuperficie->setFont(font);
        lbnTituloPressaoSuperficie->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloPressaoSuperficie, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 12, 0, 1, 3);

        editDiametroPoco = new QLineEdit(gridLayoutWidget);
        editDiametroPoco->setObjectName("editDiametroPoco");

        gridLayout->addWidget(editDiametroPoco, 3, 1, 1, 2);

        lbnTituloDiametroPoco = new QLabel(gridLayoutWidget);
        lbnTituloDiametroPoco->setObjectName("lbnTituloDiametroPoco");
        lbnTituloDiametroPoco->setFont(font);
        lbnTituloDiametroPoco->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloDiametroPoco, 3, 0, 1, 1);

        btnAdicionarPropriedades = new QPushButton(gridLayoutWidget);
        btnAdicionarPropriedades->setObjectName("btnAdicionarPropriedades");

        gridLayout->addWidget(btnAdicionarPropriedades, 13, 0, 1, 1);

        lbnDensidadeMedia = new QLabel(gridLayoutWidget);
        lbnDensidadeMedia->setObjectName("lbnDensidadeMedia");
        lbnDensidadeMedia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnDensidadeMedia, 10, 1, 1, 2);

        lbnTituloProfundidadeOcupada = new QLabel(gridLayoutWidget);
        lbnTituloProfundidadeOcupada->setObjectName("lbnTituloProfundidadeOcupada");
        lbnTituloProfundidadeOcupada->setFont(font);
        lbnTituloProfundidadeOcupada->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloProfundidadeOcupada, 9, 0, 1, 1);

        lbnViscosidadeMedia = new QLabel(gridLayoutWidget);
        lbnViscosidadeMedia->setObjectName("lbnViscosidadeMedia");
        lbnViscosidadeMedia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnViscosidadeMedia, 11, 1, 1, 2);

        lbnProfundidadeOcupada = new QLabel(gridLayoutWidget);
        lbnProfundidadeOcupada->setObjectName("lbnProfundidadeOcupada");
        lbnProfundidadeOcupada->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnProfundidadeOcupada, 9, 1, 1, 2);

        editPressaoSuperficie = new QLineEdit(gridLayoutWidget);
        editPressaoSuperficie->setObjectName("editPressaoSuperficie");

        gridLayout->addWidget(editPressaoSuperficie, 2, 1, 1, 2);

        lbnTituloDiametroID = new QLabel(gridLayoutWidget);
        lbnTituloDiametroID->setObjectName("lbnTituloDiametroID");
        lbnTituloDiametroID->setFont(font);
        lbnTituloDiametroID->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloDiametroID, 5, 0, 1, 1);

        editVazao = new QLineEdit(gridLayoutWidget);
        editVazao->setObjectName("editVazao");

        gridLayout->addWidget(editVazao, 6, 1, 1, 2);

        lbnTituloViscosidadeMedia = new QLabel(gridLayoutWidget);
        lbnTituloViscosidadeMedia->setObjectName("lbnTituloViscosidadeMedia");
        lbnTituloViscosidadeMedia->setFont(font);
        lbnTituloViscosidadeMedia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloViscosidadeMedia, 11, 0, 1, 1);

        lbnTituloDensidadeMedia = new QLabel(gridLayoutWidget);
        lbnTituloDensidadeMedia->setObjectName("lbnTituloDensidadeMedia");
        lbnTituloDensidadeMedia->setFont(font);
        lbnTituloDensidadeMedia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloDensidadeMedia, 10, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 8, 0, 1, 3);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(420, 30, 631, 311));
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
        tblFluidos->horizontalHeader()->setDefaultSectionSize(120);

        gridLayout_2->addWidget(tblFluidos, 0, 0, 1, 3);

        gridLayoutWidget_9 = new QWidget(centralwidget);
        gridLayoutWidget_9->setObjectName("gridLayoutWidget_9");
        gridLayoutWidget_9->setGeometry(QRect(250, 390, 261, 231));
        gridLayout_9 = new QGridLayout(gridLayoutWidget_9);
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        lbnTituloModeloNewtoniano = new QLabel(gridLayoutWidget_9);
        lbnTituloModeloNewtoniano->setObjectName("lbnTituloModeloNewtoniano");
        lbnTituloModeloNewtoniano->setFont(font);
        lbnTituloModeloNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_9->addWidget(lbnTituloModeloNewtoniano, 0, 0, 1, 1);

        tabWidget = new QTabWidget(gridLayoutWidget_9);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayoutWidget_3 = new QWidget(tab);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(0, 0, 251, 171));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lbnTituloPerdaFriccionalPocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnTituloPerdaFriccionalPocoNewtoniano->setObjectName("lbnTituloPerdaFriccionalPocoNewtoniano");
        lbnTituloPerdaFriccionalPocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lbnTituloPerdaFriccionalPocoNewtoniano, 3, 0, 1, 1);

        lbnTipoFluxoPocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnTipoFluxoPocoNewtoniano->setObjectName("lbnTipoFluxoPocoNewtoniano");
        lbnTipoFluxoPocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lbnTipoFluxoPocoNewtoniano, 2, 1, 1, 1);

        lbnPerdaFriccionalPocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnPerdaFriccionalPocoNewtoniano->setObjectName("lbnPerdaFriccionalPocoNewtoniano");
        lbnPerdaFriccionalPocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lbnPerdaFriccionalPocoNewtoniano, 3, 1, 1, 1);

        lbnTituloReynoldsPocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnTituloReynoldsPocoNewtoniano->setObjectName("lbnTituloReynoldsPocoNewtoniano");
        lbnTituloReynoldsPocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lbnTituloReynoldsPocoNewtoniano, 1, 0, 1, 1);

        btnCalcularModeloNewtonianoPoco = new QPushButton(gridLayoutWidget_3);
        btnCalcularModeloNewtonianoPoco->setObjectName("btnCalcularModeloNewtonianoPoco");

        gridLayout_3->addWidget(btnCalcularModeloNewtonianoPoco, 4, 0, 1, 2);

        lbnReynoldsPocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnReynoldsPocoNewtoniano->setObjectName("lbnReynoldsPocoNewtoniano");
        lbnReynoldsPocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lbnReynoldsPocoNewtoniano, 1, 1, 1, 1);

        lbnTituloVelocidadePocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnTituloVelocidadePocoNewtoniano->setObjectName("lbnTituloVelocidadePocoNewtoniano");
        lbnTituloVelocidadePocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lbnTituloVelocidadePocoNewtoniano, 0, 0, 1, 1);

        lbnTituloTipoFluxoPocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnTituloTipoFluxoPocoNewtoniano->setObjectName("lbnTituloTipoFluxoPocoNewtoniano");
        lbnTituloTipoFluxoPocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lbnTituloTipoFluxoPocoNewtoniano, 2, 0, 1, 1);

        lbnVelocidadePocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnVelocidadePocoNewtoniano->setObjectName("lbnVelocidadePocoNewtoniano");
        lbnVelocidadePocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lbnVelocidadePocoNewtoniano, 0, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayoutWidget_4 = new QWidget(tab_2);
        gridLayoutWidget_4->setObjectName("gridLayoutWidget_4");
        gridLayoutWidget_4->setGeometry(QRect(0, 0, 251, 171));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        lbnReynoldsAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnReynoldsAnularNewtoniano->setObjectName("lbnReynoldsAnularNewtoniano");
        lbnReynoldsAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lbnReynoldsAnularNewtoniano, 1, 1, 1, 1);

        lbnTituloReynoldsAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnTituloReynoldsAnularNewtoniano->setObjectName("lbnTituloReynoldsAnularNewtoniano");
        lbnTituloReynoldsAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lbnTituloReynoldsAnularNewtoniano, 1, 0, 1, 1);

        lbnVelocidadeAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnVelocidadeAnularNewtoniano->setObjectName("lbnVelocidadeAnularNewtoniano");
        lbnVelocidadeAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lbnVelocidadeAnularNewtoniano, 0, 1, 1, 1);

        lbnTituloPerdaFriccionalAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnTituloPerdaFriccionalAnularNewtoniano->setObjectName("lbnTituloPerdaFriccionalAnularNewtoniano");
        lbnTituloPerdaFriccionalAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lbnTituloPerdaFriccionalAnularNewtoniano, 3, 0, 1, 1);

        lbnTipoFluxoAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnTipoFluxoAnularNewtoniano->setObjectName("lbnTipoFluxoAnularNewtoniano");
        lbnTipoFluxoAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lbnTipoFluxoAnularNewtoniano, 2, 1, 1, 1);

        lbnTituloTipoFluxoAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnTituloTipoFluxoAnularNewtoniano->setObjectName("lbnTituloTipoFluxoAnularNewtoniano");
        lbnTituloTipoFluxoAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lbnTituloTipoFluxoAnularNewtoniano, 2, 0, 1, 1);

        lbnTituloVelocidadeAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnTituloVelocidadeAnularNewtoniano->setObjectName("lbnTituloVelocidadeAnularNewtoniano");
        lbnTituloVelocidadeAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lbnTituloVelocidadeAnularNewtoniano, 0, 0, 1, 1);

        lbnPerdaFriccionalAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnPerdaFriccionalAnularNewtoniano->setObjectName("lbnPerdaFriccionalAnularNewtoniano");
        lbnPerdaFriccionalAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lbnPerdaFriccionalAnularNewtoniano, 3, 1, 1, 1);

        btnCalcularModeloNewtonianoAnular = new QPushButton(gridLayoutWidget_4);
        btnCalcularModeloNewtonianoAnular->setObjectName("btnCalcularModeloNewtonianoAnular");

        gridLayout_4->addWidget(btnCalcularModeloNewtonianoAnular, 4, 0, 1, 2);

        tabWidget->addTab(tab_2, QString());

        gridLayout_9->addWidget(tabWidget, 1, 0, 1, 1);

        gridLayoutWidget_14 = new QWidget(centralwidget);
        gridLayoutWidget_14->setObjectName("gridLayoutWidget_14");
        gridLayoutWidget_14->setGeometry(QRect(20, 390, 211, 121));
        gridLayout_14 = new QGridLayout(gridLayoutWidget_14);
        gridLayout_14->setObjectName("gridLayout_14");
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        btnCalcularPressaoHidroestatica = new QPushButton(gridLayoutWidget_14);
        btnCalcularPressaoHidroestatica->setObjectName("btnCalcularPressaoHidroestatica");

        gridLayout_14->addWidget(btnCalcularPressaoHidroestatica, 4, 0, 1, 2);

        lbnTituloProfundidadePressaoHidroestatica = new QLabel(gridLayoutWidget_14);
        lbnTituloProfundidadePressaoHidroestatica->setObjectName("lbnTituloProfundidadePressaoHidroestatica");
        lbnTituloProfundidadePressaoHidroestatica->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_14->addWidget(lbnTituloProfundidadePressaoHidroestatica, 1, 0, 1, 1);

        lbnTituloPressaoHidroestatica_2 = new QLabel(gridLayoutWidget_14);
        lbnTituloPressaoHidroestatica_2->setObjectName("lbnTituloPressaoHidroestatica_2");
        lbnTituloPressaoHidroestatica_2->setFont(font);
        lbnTituloPressaoHidroestatica_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_14->addWidget(lbnTituloPressaoHidroestatica_2, 0, 0, 1, 2);

        lbnPressaoHidroestatica = new QLabel(gridLayoutWidget_14);
        lbnPressaoHidroestatica->setObjectName("lbnPressaoHidroestatica");
        lbnPressaoHidroestatica->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_14->addWidget(lbnPressaoHidroestatica, 3, 1, 1, 1);

        editProfundidadePressaoHidroestatica = new QLineEdit(gridLayoutWidget_14);
        editProfundidadePressaoHidroestatica->setObjectName("editProfundidadePressaoHidroestatica");

        gridLayout_14->addWidget(editProfundidadePressaoHidroestatica, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_14->addItem(verticalSpacer_3, 2, 0, 1, 2);

        lbnTituloPressaoHidroestatica = new QLabel(gridLayoutWidget_14);
        lbnTituloPressaoHidroestatica->setObjectName("lbnTituloPressaoHidroestatica");
        lbnTituloPressaoHidroestatica->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_14->addWidget(lbnTituloPressaoHidroestatica, 3, 0, 1, 1);

        gridLayoutWidget_10 = new QWidget(centralwidget);
        gridLayoutWidget_10->setObjectName("gridLayoutWidget_10");
        gridLayoutWidget_10->setGeometry(QRect(520, 390, 261, 281));
        gridLayout_10 = new QGridLayout(gridLayoutWidget_10);
        gridLayout_10->setObjectName("gridLayout_10");
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        lbnTituloModeloBigham = new QLabel(gridLayoutWidget_10);
        lbnTituloModeloBigham->setObjectName("lbnTituloModeloBigham");
        lbnTituloModeloBigham->setFont(font);
        lbnTituloModeloBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_10->addWidget(lbnTituloModeloBigham, 0, 0, 1, 1);

        tabWidget_2 = new QTabWidget(gridLayoutWidget_10);
        tabWidget_2->setObjectName("tabWidget_2");
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        gridLayoutWidget_5 = new QWidget(tab_3);
        gridLayoutWidget_5->setObjectName("gridLayoutWidget_5");
        gridLayoutWidget_5->setGeometry(QRect(0, 0, 253, 221));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        lbnTituloVelocidadePocoBigham = new QLabel(gridLayoutWidget_5);
        lbnTituloVelocidadePocoBigham->setObjectName("lbnTituloVelocidadePocoBigham");
        lbnTituloVelocidadePocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnTituloVelocidadePocoBigham, 2, 0, 1, 1);

        lbnReynoldsPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnReynoldsPocoBigham->setObjectName("lbnReynoldsPocoBigham");
        lbnReynoldsPocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnReynoldsPocoBigham, 5, 1, 1, 1);

        lbnTituloPerdaFriccionalPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnTituloPerdaFriccionalPocoBigham->setObjectName("lbnTituloPerdaFriccionalPocoBigham");
        lbnTituloPerdaFriccionalPocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnTituloPerdaFriccionalPocoBigham, 7, 0, 1, 1);

        lbnVelocidadePocoBigham = new QLabel(gridLayoutWidget_5);
        lbnVelocidadePocoBigham->setObjectName("lbnVelocidadePocoBigham");
        lbnVelocidadePocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnVelocidadePocoBigham, 2, 1, 1, 1);

        btnCalcularModeloBighamPoco = new QPushButton(gridLayoutWidget_5);
        btnCalcularModeloBighamPoco->setObjectName("btnCalcularModeloBighamPoco");

        gridLayout_5->addWidget(btnCalcularModeloBighamPoco, 8, 0, 1, 2);

        editPontoEscoamentoPoco = new QLineEdit(gridLayoutWidget_5);
        editPontoEscoamentoPoco->setObjectName("editPontoEscoamentoPoco");

        gridLayout_5->addWidget(editPontoEscoamentoPoco, 0, 1, 1, 1);

        lbnTituloHedstromPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnTituloHedstromPocoBigham->setObjectName("lbnTituloHedstromPocoBigham");
        lbnTituloHedstromPocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnTituloHedstromPocoBigham, 3, 0, 1, 1);

        lbnTituloViscosidadePlasticaPoco = new QLabel(gridLayoutWidget_5);
        lbnTituloViscosidadePlasticaPoco->setObjectName("lbnTituloViscosidadePlasticaPoco");
        lbnTituloViscosidadePlasticaPoco->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnTituloViscosidadePlasticaPoco, 1, 0, 1, 1);

        lbnPerdaFriccionalPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnPerdaFriccionalPocoBigham->setObjectName("lbnPerdaFriccionalPocoBigham");
        lbnPerdaFriccionalPocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnPerdaFriccionalPocoBigham, 7, 1, 1, 1);

        editViscosidadePlasticaPoco = new QLineEdit(gridLayoutWidget_5);
        editViscosidadePlasticaPoco->setObjectName("editViscosidadePlasticaPoco");

        gridLayout_5->addWidget(editViscosidadePlasticaPoco, 1, 1, 1, 1);

        lbnTituloPontoEscoamentoPoco = new QLabel(gridLayoutWidget_5);
        lbnTituloPontoEscoamentoPoco->setObjectName("lbnTituloPontoEscoamentoPoco");
        lbnTituloPontoEscoamentoPoco->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnTituloPontoEscoamentoPoco, 0, 0, 1, 1);

        lbnTituloReynoldsPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnTituloReynoldsPocoBigham->setObjectName("lbnTituloReynoldsPocoBigham");
        lbnTituloReynoldsPocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnTituloReynoldsPocoBigham, 5, 0, 1, 1);

        lbnTituloTipoFluxoPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnTituloTipoFluxoPocoBigham->setObjectName("lbnTituloTipoFluxoPocoBigham");
        lbnTituloTipoFluxoPocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnTituloTipoFluxoPocoBigham, 6, 0, 1, 1);

        lbnTipoFluxoPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnTipoFluxoPocoBigham->setObjectName("lbnTipoFluxoPocoBigham");
        lbnTipoFluxoPocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnTipoFluxoPocoBigham, 6, 1, 1, 1);

        lbnTituloCriticoPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnTituloCriticoPocoBigham->setObjectName("lbnTituloCriticoPocoBigham");
        lbnTituloCriticoPocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnTituloCriticoPocoBigham, 4, 0, 1, 1);

        lbnReynoldsHedstromPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnReynoldsHedstromPocoBigham->setObjectName("lbnReynoldsHedstromPocoBigham");
        lbnReynoldsHedstromPocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnReynoldsHedstromPocoBigham, 3, 1, 1, 1);

        lbnReynoldsCriticoPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnReynoldsCriticoPocoBigham->setObjectName("lbnReynoldsCriticoPocoBigham");
        lbnReynoldsCriticoPocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnReynoldsCriticoPocoBigham, 4, 1, 1, 1);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        gridLayoutWidget_6 = new QWidget(tab_4);
        gridLayoutWidget_6->setObjectName("gridLayoutWidget_6");
        gridLayoutWidget_6->setGeometry(QRect(0, 0, 253, 221));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        editPontoEscoamentoAnular = new QLineEdit(gridLayoutWidget_6);
        editPontoEscoamentoAnular->setObjectName("editPontoEscoamentoAnular");

        gridLayout_6->addWidget(editPontoEscoamentoAnular, 0, 1, 1, 1);

        lbnTituloHedstromAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnTituloHedstromAnularBigham->setObjectName("lbnTituloHedstromAnularBigham");
        lbnTituloHedstromAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnTituloHedstromAnularBigham, 3, 0, 1, 1);

        btnCalcularModeloBighamAnular = new QPushButton(gridLayoutWidget_6);
        btnCalcularModeloBighamAnular->setObjectName("btnCalcularModeloBighamAnular");

        gridLayout_6->addWidget(btnCalcularModeloBighamAnular, 8, 0, 1, 2);

        lbnVelocidadeAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnVelocidadeAnularBigham->setObjectName("lbnVelocidadeAnularBigham");
        lbnVelocidadeAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnVelocidadeAnularBigham, 2, 1, 1, 1);

        lbnReynoldsAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnReynoldsAnularBigham->setObjectName("lbnReynoldsAnularBigham");
        lbnReynoldsAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnReynoldsAnularBigham, 5, 1, 1, 1);

        lbnTituloTipoFluxoAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnTituloTipoFluxoAnularBigham->setObjectName("lbnTituloTipoFluxoAnularBigham");
        lbnTituloTipoFluxoAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnTituloTipoFluxoAnularBigham, 6, 0, 1, 1);

        lbnPerdaFriccionalAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnPerdaFriccionalAnularBigham->setObjectName("lbnPerdaFriccionalAnularBigham");
        lbnPerdaFriccionalAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnPerdaFriccionalAnularBigham, 7, 1, 1, 1);

        lbnTituloPontoEscoamentoAnular = new QLabel(gridLayoutWidget_6);
        lbnTituloPontoEscoamentoAnular->setObjectName("lbnTituloPontoEscoamentoAnular");
        lbnTituloPontoEscoamentoAnular->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnTituloPontoEscoamentoAnular, 0, 0, 1, 1);

        lbnTituloReynoldsAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnTituloReynoldsAnularBigham->setObjectName("lbnTituloReynoldsAnularBigham");
        lbnTituloReynoldsAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnTituloReynoldsAnularBigham, 5, 0, 1, 1);

        editViscosidadePlasticaAnular = new QLineEdit(gridLayoutWidget_6);
        editViscosidadePlasticaAnular->setObjectName("editViscosidadePlasticaAnular");

        gridLayout_6->addWidget(editViscosidadePlasticaAnular, 1, 1, 1, 1);

        lbnTipoFluxoAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnTipoFluxoAnularBigham->setObjectName("lbnTipoFluxoAnularBigham");
        lbnTipoFluxoAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnTipoFluxoAnularBigham, 6, 1, 1, 1);

        lbnTituloViscosidadePlasticaAnular = new QLabel(gridLayoutWidget_6);
        lbnTituloViscosidadePlasticaAnular->setObjectName("lbnTituloViscosidadePlasticaAnular");
        lbnTituloViscosidadePlasticaAnular->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnTituloViscosidadePlasticaAnular, 1, 0, 1, 1);

        lbnTituloVelocidadeAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnTituloVelocidadeAnularBigham->setObjectName("lbnTituloVelocidadeAnularBigham");
        lbnTituloVelocidadeAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnTituloVelocidadeAnularBigham, 2, 0, 1, 1);

        lbnTituloPerdaFriccionalAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnTituloPerdaFriccionalAnularBigham->setObjectName("lbnTituloPerdaFriccionalAnularBigham");
        lbnTituloPerdaFriccionalAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnTituloPerdaFriccionalAnularBigham, 7, 0, 1, 1);

        lbnTituloCriticoAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnTituloCriticoAnularBigham->setObjectName("lbnTituloCriticoAnularBigham");
        lbnTituloCriticoAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnTituloCriticoAnularBigham, 4, 0, 1, 1);

        lbnReynoldsHedstromAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnReynoldsHedstromAnularBigham->setObjectName("lbnReynoldsHedstromAnularBigham");
        lbnReynoldsHedstromAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnReynoldsHedstromAnularBigham, 3, 1, 1, 1);

        lbnReynoldsCriticoAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnReynoldsCriticoAnularBigham->setObjectName("lbnReynoldsCriticoAnularBigham");
        lbnReynoldsCriticoAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnReynoldsCriticoAnularBigham, 4, 1, 1, 1);

        tabWidget_2->addTab(tab_4, QString());

        gridLayout_10->addWidget(tabWidget_2, 1, 0, 1, 1);

        gridLayoutWidget_11 = new QWidget(centralwidget);
        gridLayoutWidget_11->setObjectName("gridLayoutWidget_11");
        gridLayoutWidget_11->setGeometry(QRect(790, 390, 261, 281));
        gridLayout_11 = new QGridLayout(gridLayoutWidget_11);
        gridLayout_11->setObjectName("gridLayout_11");
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        lbnTituloModeloBigham_2 = new QLabel(gridLayoutWidget_11);
        lbnTituloModeloBigham_2->setObjectName("lbnTituloModeloBigham_2");
        lbnTituloModeloBigham_2->setFont(font);
        lbnTituloModeloBigham_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_11->addWidget(lbnTituloModeloBigham_2, 0, 0, 1, 1);

        tabWidget_3 = new QTabWidget(gridLayoutWidget_11);
        tabWidget_3->setObjectName("tabWidget_3");
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        gridLayoutWidget_7 = new QWidget(tab_5);
        gridLayoutWidget_7->setObjectName("gridLayoutWidget_7");
        gridLayoutWidget_7->setGeometry(QRect(0, 0, 251, 221));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_7);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        lbnPerdaFriccionalPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnPerdaFriccionalPocoPotencia->setObjectName("lbnPerdaFriccionalPocoPotencia");
        lbnPerdaFriccionalPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnPerdaFriccionalPocoPotencia, 5, 1, 1, 1);

        lbnTituloPerdaFriccionalPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnTituloPerdaFriccionalPocoPotencia->setObjectName("lbnTituloPerdaFriccionalPocoPotencia");
        lbnTituloPerdaFriccionalPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnTituloPerdaFriccionalPocoPotencia, 5, 0, 1, 1);

        lbnVelocidadePocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnVelocidadePocoPotencia->setObjectName("lbnVelocidadePocoPotencia");
        lbnVelocidadePocoPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnVelocidadePocoPotencia, 1, 1, 1, 1);

        lbnTipoFluxoPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnTipoFluxoPocoPotencia->setObjectName("lbnTipoFluxoPocoPotencia");
        lbnTipoFluxoPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnTipoFluxoPocoPotencia, 4, 1, 1, 1);

        lbnTituloCriticoPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnTituloCriticoPocoPotencia->setObjectName("lbnTituloCriticoPocoPotencia");
        lbnTituloCriticoPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnTituloCriticoPocoPotencia, 2, 0, 1, 1);

        lbnTituloReynoldsPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnTituloReynoldsPocoPotencia->setObjectName("lbnTituloReynoldsPocoPotencia");
        lbnTituloReynoldsPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnTituloReynoldsPocoPotencia, 3, 0, 1, 1);

        lbnTituloVelocidadePocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnTituloVelocidadePocoPotencia->setObjectName("lbnTituloVelocidadePocoPotencia");
        lbnTituloVelocidadePocoPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnTituloVelocidadePocoPotencia, 1, 0, 1, 1);

        lbnReynoldsPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnReynoldsPocoPotencia->setObjectName("lbnReynoldsPocoPotencia");
        lbnReynoldsPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnReynoldsPocoPotencia, 3, 1, 1, 1);

        lbnTituloTipoFluxoPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnTituloTipoFluxoPocoPotencia->setObjectName("lbnTituloTipoFluxoPocoPotencia");
        lbnTituloTipoFluxoPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnTituloTipoFluxoPocoPotencia, 4, 0, 1, 1);

        lbnReynoldsCriticoPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnReynoldsCriticoPocoPotencia->setObjectName("lbnReynoldsCriticoPocoPotencia");
        lbnReynoldsCriticoPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnReynoldsCriticoPocoPotencia, 2, 1, 1, 1);

        btnCalcularModeloPotenciaPoco = new QPushButton(gridLayoutWidget_7);
        btnCalcularModeloPotenciaPoco->setObjectName("btnCalcularModeloPotenciaPoco");

        gridLayout_7->addWidget(btnCalcularModeloPotenciaPoco, 6, 0, 1, 2);

        lbnTituloIndiceConsistenciaPoco = new QLabel(gridLayoutWidget_7);
        lbnTituloIndiceConsistenciaPoco->setObjectName("lbnTituloIndiceConsistenciaPoco");
        lbnTituloIndiceConsistenciaPoco->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnTituloIndiceConsistenciaPoco, 0, 0, 1, 1);

        editIndiceConsistenciaPotenciaPoco = new QLineEdit(gridLayoutWidget_7);
        editIndiceConsistenciaPotenciaPoco->setObjectName("editIndiceConsistenciaPotenciaPoco");

        gridLayout_7->addWidget(editIndiceConsistenciaPotenciaPoco, 0, 1, 1, 1);

        tabWidget_3->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        gridLayoutWidget_8 = new QWidget(tab_6);
        gridLayoutWidget_8->setObjectName("gridLayoutWidget_8");
        gridLayoutWidget_8->setGeometry(QRect(0, 0, 251, 211));
        gridLayout_8 = new QGridLayout(gridLayoutWidget_8);
        gridLayout_8->setObjectName("gridLayout_8");
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        lbnTipoFluxoAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnTipoFluxoAnularPotencia->setObjectName("lbnTipoFluxoAnularPotencia");
        lbnTipoFluxoAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnTipoFluxoAnularPotencia, 4, 1, 1, 1);

        lbnTituloCriticoAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnTituloCriticoAnularPotencia->setObjectName("lbnTituloCriticoAnularPotencia");
        lbnTituloCriticoAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnTituloCriticoAnularPotencia, 2, 0, 1, 1);

        lbnTituloTipoFluxoAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnTituloTipoFluxoAnularPotencia->setObjectName("lbnTituloTipoFluxoAnularPotencia");
        lbnTituloTipoFluxoAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnTituloTipoFluxoAnularPotencia, 4, 0, 1, 1);

        lbnTituloReynoldsAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnTituloReynoldsAnularPotencia->setObjectName("lbnTituloReynoldsAnularPotencia");
        lbnTituloReynoldsAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnTituloReynoldsAnularPotencia, 3, 0, 1, 1);

        lbnTituloVelocidadeAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnTituloVelocidadeAnularPotencia->setObjectName("lbnTituloVelocidadeAnularPotencia");
        lbnTituloVelocidadeAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnTituloVelocidadeAnularPotencia, 1, 0, 1, 1);

        lbnReynoldsAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnReynoldsAnularPotencia->setObjectName("lbnReynoldsAnularPotencia");
        lbnReynoldsAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnReynoldsAnularPotencia, 3, 1, 1, 1);

        lbnTituloPerdaFriccionalAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnTituloPerdaFriccionalAnularPotencia->setObjectName("lbnTituloPerdaFriccionalAnularPotencia");
        lbnTituloPerdaFriccionalAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnTituloPerdaFriccionalAnularPotencia, 5, 0, 1, 1);

        lbnVelocidadeAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnVelocidadeAnularPotencia->setObjectName("lbnVelocidadeAnularPotencia");
        lbnVelocidadeAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnVelocidadeAnularPotencia, 1, 1, 1, 1);

        lbnTituloIndiceConsistenciaAnular = new QLabel(gridLayoutWidget_8);
        lbnTituloIndiceConsistenciaAnular->setObjectName("lbnTituloIndiceConsistenciaAnular");
        lbnTituloIndiceConsistenciaAnular->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnTituloIndiceConsistenciaAnular, 0, 0, 1, 1);

        lbnPerdaFriccionalAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnPerdaFriccionalAnularPotencia->setObjectName("lbnPerdaFriccionalAnularPotencia");
        lbnPerdaFriccionalAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnPerdaFriccionalAnularPotencia, 5, 1, 1, 1);

        lbnReynoldsCriticoAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnReynoldsCriticoAnularPotencia->setObjectName("lbnReynoldsCriticoAnularPotencia");
        lbnReynoldsCriticoAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnReynoldsCriticoAnularPotencia, 2, 1, 1, 1);

        btnCalcularModeloPotenciaAnular = new QPushButton(gridLayoutWidget_8);
        btnCalcularModeloPotenciaAnular->setObjectName("btnCalcularModeloPotenciaAnular");

        gridLayout_8->addWidget(btnCalcularModeloPotenciaAnular, 6, 0, 1, 2);

        editIndiceConsistenciaPotenciaAnular = new QLineEdit(gridLayoutWidget_8);
        editIndiceConsistenciaPotenciaAnular->setObjectName("editIndiceConsistenciaPotenciaAnular");

        gridLayout_8->addWidget(editIndiceConsistenciaPotenciaAnular, 0, 1, 1, 1);

        tabWidget_3->addTab(tab_6, QString());

        gridLayout_11->addWidget(tabWidget_3, 1, 0, 1, 1);

        customPlotPoco = new QCustomPlot(centralwidget);
        customPlotPoco->setObjectName("customPlotPoco");
        customPlotPoco->setGeometry(QRect(1070, 30, 301, 631));
        CSimuladorPoco->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CSimuladorPoco);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1416, 22));
        menuArquivo = new QMenu(menubar);
        menuArquivo->setObjectName("menuArquivo");
        CSimuladorPoco->setMenuBar(menubar);
        statusbar = new QStatusBar(CSimuladorPoco);
        statusbar->setObjectName("statusbar");
        CSimuladorPoco->setStatusBar(statusbar);

        menubar->addAction(menuArquivo->menuAction());
        menuArquivo->addAction(actionImportar_Dados);

        retranslateUi(CSimuladorPoco);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CSimuladorPoco);
    } // setupUi

    void retranslateUi(QMainWindow *CSimuladorPoco)
    {
        CSimuladorPoco->setWindowTitle(QCoreApplication::translate("CSimuladorPoco", "CSimuladorPoco", nullptr));
        actionImportar_Dados->setText(QCoreApplication::translate("CSimuladorPoco", "Importar Dados", nullptr));
        lbnTituloDiametroOD->setText(QCoreApplication::translate("CSimuladorPoco", "Diamentro Revestimento OD (in)", nullptr));
        lbnTituloVazao->setText(QCoreApplication::translate("CSimuladorPoco", "Vaz\303\243o (gal/min)", nullptr));
        btnAtualizarDados->setText(QCoreApplication::translate("CSimuladorPoco", "Atualizar Dados", nullptr));
        lbnTituloNomePoco->setText(QCoreApplication::translate("CSimuladorPoco", "Nome Po\303\247o", nullptr));
        lbnTituloProfunidadeTotal->setText(QCoreApplication::translate("CSimuladorPoco", "Profundidade Total (ft)", nullptr));
        lbnTituloPressaoSuperficie->setText(QCoreApplication::translate("CSimuladorPoco", "Press\303\243o Superficie (psi)", nullptr));
        lbnTituloDiametroPoco->setText(QCoreApplication::translate("CSimuladorPoco", "Diametro Po\303\247o (in)", nullptr));
        btnAdicionarPropriedades->setText(QCoreApplication::translate("CSimuladorPoco", "Adicionar Propriedade", nullptr));
        lbnDensidadeMedia->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloProfundidadeOcupada->setText(QCoreApplication::translate("CSimuladorPoco", "Produndidade Ocupada (ft): ", nullptr));
        lbnViscosidadeMedia->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnProfundidadeOcupada->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloDiametroID->setText(QCoreApplication::translate("CSimuladorPoco", "Diamentro Revestimento ID  (in)", nullptr));
        lbnTituloViscosidadeMedia->setText(QCoreApplication::translate("CSimuladorPoco", "Viscosidade M\303\251dia (cP):", nullptr));
        lbnTituloDensidadeMedia->setText(QCoreApplication::translate("CSimuladorPoco", "Densidade M\303\251dia (lb/gal): ", nullptr));
        btnAdicionarFluido->setText(QCoreApplication::translate("CSimuladorPoco", "Adicionar Fluido", nullptr));
        btnRemoverFluido->setText(QCoreApplication::translate("CSimuladorPoco", "Remover Fluido", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblFluidos->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CSimuladorPoco", "Nome", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblFluidos->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CSimuladorPoco", "Densidade (lbm/gal)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblFluidos->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CSimuladorPoco", "Viscosidade (cP)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblFluidos->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CSimuladorPoco", "Prof. Inicial (ft)", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblFluidos->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CSimuladorPoco", "Prof. Final (ft)", nullptr));
        lbnTituloModeloNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "Modelo Newtoniano", nullptr));
        lbnTituloPerdaFriccionalPocoNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "Perda Friccional no Po\303\247o (psi/ft)", nullptr));
        lbnTipoFluxoPocoNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnPerdaFriccionalPocoNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloReynoldsPocoNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "Reynolds no Po\303\247o", nullptr));
        btnCalcularModeloNewtonianoPoco->setText(QCoreApplication::translate("CSimuladorPoco", "Calcular", nullptr));
        lbnReynoldsPocoNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloVelocidadePocoNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "Velocidade do Po\303\247o (ft/s)", nullptr));
        lbnTituloTipoFluxoPocoNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "Tipo de Fluxo no Po\303\247o", nullptr));
        lbnVelocidadePocoNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("CSimuladorPoco", "Po\303\247o", nullptr));
        lbnReynoldsAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloReynoldsAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "Reynolds no Anular", nullptr));
        lbnVelocidadeAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloPerdaFriccionalAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "Perda Friccional no Anular (psi/ft)", nullptr));
        lbnTipoFluxoAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloTipoFluxoAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "Tipo de Fluxo no Anular", nullptr));
        lbnTituloVelocidadeAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "Velocidade do Anular (ft/s)", nullptr));
        lbnPerdaFriccionalAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        btnCalcularModeloNewtonianoAnular->setText(QCoreApplication::translate("CSimuladorPoco", "Calcular", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("CSimuladorPoco", "Anular", nullptr));
        btnCalcularPressaoHidroestatica->setText(QCoreApplication::translate("CSimuladorPoco", "Calcular", nullptr));
        lbnTituloProfundidadePressaoHidroestatica->setText(QCoreApplication::translate("CSimuladorPoco", "Profundidade (ft)", nullptr));
        lbnTituloPressaoHidroestatica_2->setText(QCoreApplication::translate("CSimuladorPoco", "Press\303\243o Hidroest\303\241tica", nullptr));
        lbnPressaoHidroestatica->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        editProfundidadePressaoHidroestatica->setText(QString());
        lbnTituloPressaoHidroestatica->setText(QCoreApplication::translate("CSimuladorPoco", "Pressao Hidrost\303\241tica (psi)", nullptr));
        lbnTituloModeloBigham->setText(QCoreApplication::translate("CSimuladorPoco", "Modelo Bingham", nullptr));
        lbnTituloVelocidadePocoBigham->setText(QCoreApplication::translate("CSimuladorPoco", "Velocidade do Po\303\247o (ft/s)", nullptr));
        lbnReynoldsPocoBigham->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloPerdaFriccionalPocoBigham->setText(QCoreApplication::translate("CSimuladorPoco", "Perda Friccional no Po\303\247o (psi/ft)", nullptr));
        lbnVelocidadePocoBigham->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        btnCalcularModeloBighamPoco->setText(QCoreApplication::translate("CSimuladorPoco", "Calcular", nullptr));
        lbnTituloHedstromPocoBigham->setText(QCoreApplication::translate("CSimuladorPoco", "Reynolds Hedstrom", nullptr));
        lbnTituloViscosidadePlasticaPoco->setText(QCoreApplication::translate("CSimuladorPoco", "Viscosidade Pl\303\241stica (cP)", nullptr));
        lbnPerdaFriccionalPocoBigham->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloPontoEscoamentoPoco->setText(QCoreApplication::translate("CSimuladorPoco", "Ponto de Escoamento (lbf/100 sq.ft)", nullptr));
        lbnTituloReynoldsPocoBigham->setText(QCoreApplication::translate("CSimuladorPoco", "Reynolds no Po\303\247o", nullptr));
        lbnTituloTipoFluxoPocoBigham->setText(QCoreApplication::translate("CSimuladorPoco", "Tipo de Fluxo no Po\303\247o", nullptr));
        lbnTipoFluxoPocoBigham->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloCriticoPocoBigham->setText(QCoreApplication::translate("CSimuladorPoco", "Reynolds Cr\303\255tico", nullptr));
        lbnReynoldsHedstromPocoBigham->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnReynoldsCriticoPocoBigham->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("CSimuladorPoco", "Po\303\247o", nullptr));
        lbnTituloHedstromAnularBigham->setText(QCoreApplication::translate("CSimuladorPoco", "Reynolds Hedstrom", nullptr));
        btnCalcularModeloBighamAnular->setText(QCoreApplication::translate("CSimuladorPoco", "Calcular", nullptr));
        lbnVelocidadeAnularBigham->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnReynoldsAnularBigham->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloTipoFluxoAnularBigham->setText(QCoreApplication::translate("CSimuladorPoco", "Tipo de Fluxo no Anular", nullptr));
        lbnPerdaFriccionalAnularBigham->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloPontoEscoamentoAnular->setText(QCoreApplication::translate("CSimuladorPoco", "Ponto de Escoamento (lbf/100 sq.ft)", nullptr));
        lbnTituloReynoldsAnularBigham->setText(QCoreApplication::translate("CSimuladorPoco", "Reynolds no Anular", nullptr));
        lbnTipoFluxoAnularBigham->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloViscosidadePlasticaAnular->setText(QCoreApplication::translate("CSimuladorPoco", "Viscosidade Pl\303\241stica (cP)", nullptr));
        lbnTituloVelocidadeAnularBigham->setText(QCoreApplication::translate("CSimuladorPoco", "Velocidade do Anular (ft/s)", nullptr));
        lbnTituloPerdaFriccionalAnularBigham->setText(QCoreApplication::translate("CSimuladorPoco", "Perda Friccional no Anular (psi/ft)", nullptr));
        lbnTituloCriticoAnularBigham->setText(QCoreApplication::translate("CSimuladorPoco", "Reynolds Cr\303\255tico", nullptr));
        lbnReynoldsHedstromAnularBigham->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnReynoldsCriticoAnularBigham->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("CSimuladorPoco", "Anular", nullptr));
        lbnTituloModeloBigham_2->setText(QCoreApplication::translate("CSimuladorPoco", "Modelo Pot\303\252ncia", nullptr));
        lbnPerdaFriccionalPocoPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloPerdaFriccionalPocoPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "Perda Friccional no Po\303\247o (psi/ft)", nullptr));
        lbnVelocidadePocoPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTipoFluxoPocoPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloCriticoPocoPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "Reynolds Cr\303\255tico", nullptr));
        lbnTituloReynoldsPocoPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "Reynolds no Po\303\247o", nullptr));
        lbnTituloVelocidadePocoPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "Velocidade do Po\303\247o (ft/s)", nullptr));
        lbnReynoldsPocoPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloTipoFluxoPocoPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "Tipo de Fluxo no Po\303\247o", nullptr));
        lbnReynoldsCriticoPocoPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        btnCalcularModeloPotenciaPoco->setText(QCoreApplication::translate("CSimuladorPoco", "Calcular", nullptr));
        lbnTituloIndiceConsistenciaPoco->setText(QCoreApplication::translate("CSimuladorPoco", "Indice de Consistencia (cP eq)", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_5), QCoreApplication::translate("CSimuladorPoco", "Po\303\247o", nullptr));
        lbnTipoFluxoAnularPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloCriticoAnularPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "Reynolds Cr\303\255tico", nullptr));
        lbnTituloTipoFluxoAnularPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "Tipo de Fluxo no Anular", nullptr));
        lbnTituloReynoldsAnularPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "Reynolds no Anular", nullptr));
        lbnTituloVelocidadeAnularPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "Velocidade do Anular (ft/s)", nullptr));
        lbnReynoldsAnularPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloPerdaFriccionalAnularPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "Perda Friccional no Anular (psi/ft)", nullptr));
        lbnVelocidadeAnularPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnTituloIndiceConsistenciaAnular->setText(QCoreApplication::translate("CSimuladorPoco", "Indice de Consistencia (cP eq)", nullptr));
        lbnPerdaFriccionalAnularPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        lbnReynoldsCriticoAnularPotencia->setText(QCoreApplication::translate("CSimuladorPoco", "-", nullptr));
        btnCalcularModeloPotenciaAnular->setText(QCoreApplication::translate("CSimuladorPoco", "Calcular", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QCoreApplication::translate("CSimuladorPoco", "Anular", nullptr));
        menuArquivo->setTitle(QCoreApplication::translate("CSimuladorPoco", "Arquivo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSimuladorPoco: public Ui_CSimuladorPoco {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSIMULADORPOCO_H
