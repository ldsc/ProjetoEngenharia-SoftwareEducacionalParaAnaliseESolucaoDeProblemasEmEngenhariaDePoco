/********************************************************************************
** Form generated from reading UI file 'CSimuladorReologico.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSIMULADORREOLOGICO_H
#define UI_CSIMULADORREOLOGICO_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_CSimuladorReologico
{
public:
    QAction *actionNova_Simula_o;
    QAction *actionSalvar_Como;
    QAction *actionExportar_como_Imagem;
    QAction *actionAjuda;
    QAction *actionSobre_os_Modelos_Reol_gicos;
    QAction *actionSobre_o_Programa;
    QAction *actionArquivo_dat;
    QAction *actionSalvar;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *lbnTituloNomePoco;
    QLabel *lbnTituloDiametroID;
    QLineEdit *editDiametroOD;
    QLabel *lbnProfundidadeOcupada;
    QSpacerItem *verticalSpacer_2;
    QLabel *lbnTituloPressaoSuperficie;
    QLineEdit *editProfundidadeTotal;
    QLabel *lbnTituloVazao;
    QLineEdit *editNomePoco;
    QLabel *lbnDensidadeMedia;
    QLineEdit *editPressaoSuperficie;
    QLineEdit *editVazao;
    QLabel *lbnViscosidadeMedia;
    QLineEdit *editDiametroPoco;
    QSpacerItem *verticalSpacer;
    QLabel *lbnTituloDensidadeMedia;
    QLabel *lbnTituloProfundidadeOcupada;
    QLabel *lbnTituloDiametroOD;
    QLabel *lbnTituloProfunidadeTotal;
    QLineEdit *editDiametroID;
    QLabel *lbnTituloDiametroPoco;
    QLabel *lbnTituloViscosidadeMedia;
    QLabel *label;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QTableWidget *tblFluidos;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnRemoverFluido;
    QPushButton *btnAdicionarFluido;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QWidget *gridLayoutWidget_14;
    QGridLayout *gridLayout_14;
    QLineEdit *editProfundidadePressaoHidroestatica;
    QLabel *lbnTituloPressaoHidroestatica;
    QLabel *lbnPressaoHidroestatica;
    QSpacerItem *verticalSpacer_3;
    QLabel *lbnTituloProfundidadePressaoHidroestatica;
    QSpacerItem *verticalSpacer_4;
    QPushButton *btnCalcularPressaoHidroestatica;
    QPushButton *btnExibirGraficoPressaoHidroestatica;
    QTabWidget *tabWidget_4;
    QWidget *tab_7;
    QLabel *label_6;
    QLabel *label_7;
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
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *lbnVelocidadePocoNewtoniano;
    QLabel *lbnTituloReynoldsPocoNewtoniano;
    QLabel *lbnTipoFluxoPocoNewtoniano;
    QLabel *lbnTituloVelocidadePocoNewtoniano;
    QLabel *lbnPerdaFriccionalPocoNewtoniano;
    QLabel *lbnReynoldsPocoNewtoniano;
    QPushButton *btnCalcularModeloNewtonianoPoco;
    QLabel *lbnTituloPerdaFriccionalPocoNewtoniano;
    QLabel *lbnTituloTipoFluxoPocoNewtoniano;
    QWidget *tab_9;
    QLabel *label_8;
    QLabel *label_9;
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
    QWidget *tab_8;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *gridLayoutWidget_7;
    QGridLayout *gridLayout_7;
    QLabel *lbnTituloCriticoPocoPotencia;
    QLabel *lbnTituloVelocidadePocoPotencia;
    QLabel *lbnTipoFluxoPocoPotencia;
    QLabel *lbnReynoldsPocoPotencia;
    QLabel *lbnTituloPerdaFriccionalPocoPotencia;
    QLineEdit *editIndiceConsistenciaPotenciaPoco;
    QLabel *lbnReynoldsCriticoPocoPotencia;
    QLabel *lbnPerdaFriccionalPocoPotencia;
    QLabel *lbnTituloTipoFluxoPocoPotencia;
    QLabel *lbnTituloIndiceConsistenciaPoco;
    QPushButton *btnCalcularModeloPotenciaPoco;
    QLabel *lbnVelocidadePocoPotencia;
    QLabel *lbnTituloReynoldsPocoPotencia;
    QLabel *lbnTituloIndiceComportamentoPoco;
    QLineEdit *editIndiceComportamentoPoco;
    QWidget *gridLayoutWidget_8;
    QGridLayout *gridLayout_8;
    QLabel *lbnPerdaFriccionalAnularPotencia;
    QLabel *lbnTituloVelocidadeAnularPotencia;
    QLabel *lbnReynoldsAnularPotencia;
    QLabel *lbnTituloTipoFluxoAnularPotencia;
    QLabel *lbnTituloReynoldsAnularPotencia;
    QLabel *lbnVelocidadeAnularPotencia;
    QLabel *lbnTituloIndiceConsistenciaAnular;
    QLabel *lbnTituloPerdaFriccionalAnularPotencia;
    QPushButton *btnCalcularModeloPotenciaAnular;
    QLabel *lbnTituloCriticoAnularPotencia;
    QLineEdit *editIndiceConsistenciaPotenciaAnular;
    QLabel *lbnTipoFluxoAnularPotencia;
    QLabel *lbnReynoldsCriticoAnularPotencia;
    QLabel *lbnTituloIndiceComportamentoAnular;
    QLineEdit *editIndiceComportamentoAnular;
    QGroupBox *groupBox_4;
    QCustomPlot *customPlotPoco;
    QLabel *label_12;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_10;
    QLabel *label_11;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuArquivo;
    QMenu *menuImportar_Dados;
    QMenu *menuAjuda;

    void setupUi(QMainWindow *CSimuladorReologico)
    {
        if (CSimuladorReologico->objectName().isEmpty())
            CSimuladorReologico->setObjectName(QString::fromUtf8("CSimuladorReologico"));
        CSimuladorReologico->resize(1264, 711);
        actionNova_Simula_o = new QAction(CSimuladorReologico);
        actionNova_Simula_o->setObjectName(QString::fromUtf8("actionNova_Simula_o"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::DocumentNew")));
        actionNova_Simula_o->setIcon(icon);
        actionSalvar_Como = new QAction(CSimuladorReologico);
        actionSalvar_Como->setObjectName(QString::fromUtf8("actionSalvar_Como"));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::DocumentSave")));
        actionSalvar_Como->setIcon(icon1);
        actionExportar_como_Imagem = new QAction(CSimuladorReologico);
        actionExportar_como_Imagem->setObjectName(QString::fromUtf8("actionExportar_como_Imagem"));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("emblem-photos")));
        actionExportar_como_Imagem->setIcon(icon2);
        actionAjuda = new QAction(CSimuladorReologico);
        actionAjuda->setObjectName(QString::fromUtf8("actionAjuda"));
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::HelpFaq")));
        actionAjuda->setIcon(icon3);
        actionSobre_os_Modelos_Reol_gicos = new QAction(CSimuladorReologico);
        actionSobre_os_Modelos_Reol_gicos->setObjectName(QString::fromUtf8("actionSobre_os_Modelos_Reol_gicos"));
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("document-properties")));
        actionSobre_os_Modelos_Reol_gicos->setIcon(icon4);
        actionSobre_o_Programa = new QAction(CSimuladorReologico);
        actionSobre_o_Programa->setObjectName(QString::fromUtf8("actionSobre_o_Programa"));
        QIcon icon5(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::HelpAbout")));
        actionSobre_o_Programa->setIcon(icon5);
        actionArquivo_dat = new QAction(CSimuladorReologico);
        actionArquivo_dat->setObjectName(QString::fromUtf8("actionArquivo_dat"));
        actionSalvar = new QAction(CSimuladorReologico);
        actionSalvar->setObjectName(QString::fromUtf8("actionSalvar"));
        actionSalvar->setIcon(icon1);
        centralwidget = new QWidget(CSimuladorReologico);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 60, 281, 341));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        groupBox->setTitle(QString::fromUtf8(""));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 261, 307));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lbnTituloNomePoco = new QLabel(gridLayoutWidget);
        lbnTituloNomePoco->setObjectName(QString::fromUtf8("lbnTituloNomePoco"));
        QFont font;
        font.setBold(false);
        lbnTituloNomePoco->setFont(font);
        lbnTituloNomePoco->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloNomePoco, 0, 0, 1, 1);

        lbnTituloDiametroID = new QLabel(gridLayoutWidget);
        lbnTituloDiametroID->setObjectName(QString::fromUtf8("lbnTituloDiametroID"));
        lbnTituloDiametroID->setFont(font);
        lbnTituloDiametroID->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloDiametroID, 5, 0, 1, 1);

        editDiametroOD = new QLineEdit(gridLayoutWidget);
        editDiametroOD->setObjectName(QString::fromUtf8("editDiametroOD"));
        editDiametroOD->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editDiametroOD, 4, 1, 1, 2);

        lbnProfundidadeOcupada = new QLabel(gridLayoutWidget);
        lbnProfundidadeOcupada->setObjectName(QString::fromUtf8("lbnProfundidadeOcupada"));
        lbnProfundidadeOcupada->setStyleSheet(QString::fromUtf8(""));
        lbnProfundidadeOcupada->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnProfundidadeOcupada, 9, 1, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_2, 8, 0, 1, 3);

        lbnTituloPressaoSuperficie = new QLabel(gridLayoutWidget);
        lbnTituloPressaoSuperficie->setObjectName(QString::fromUtf8("lbnTituloPressaoSuperficie"));
        lbnTituloPressaoSuperficie->setFont(font);
        lbnTituloPressaoSuperficie->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloPressaoSuperficie, 2, 0, 1, 1);

        editProfundidadeTotal = new QLineEdit(gridLayoutWidget);
        editProfundidadeTotal->setObjectName(QString::fromUtf8("editProfundidadeTotal"));
        editProfundidadeTotal->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editProfundidadeTotal, 1, 1, 1, 2);

        lbnTituloVazao = new QLabel(gridLayoutWidget);
        lbnTituloVazao->setObjectName(QString::fromUtf8("lbnTituloVazao"));
        lbnTituloVazao->setFont(font);
        lbnTituloVazao->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloVazao, 6, 0, 1, 1);

        editNomePoco = new QLineEdit(gridLayoutWidget);
        editNomePoco->setObjectName(QString::fromUtf8("editNomePoco"));
        editNomePoco->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editNomePoco, 0, 1, 1, 2);

        lbnDensidadeMedia = new QLabel(gridLayoutWidget);
        lbnDensidadeMedia->setObjectName(QString::fromUtf8("lbnDensidadeMedia"));
        lbnDensidadeMedia->setStyleSheet(QString::fromUtf8(""));
        lbnDensidadeMedia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnDensidadeMedia, 10, 1, 1, 2);

        editPressaoSuperficie = new QLineEdit(gridLayoutWidget);
        editPressaoSuperficie->setObjectName(QString::fromUtf8("editPressaoSuperficie"));
        editPressaoSuperficie->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editPressaoSuperficie, 2, 1, 1, 2);

        editVazao = new QLineEdit(gridLayoutWidget);
        editVazao->setObjectName(QString::fromUtf8("editVazao"));
        editVazao->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editVazao, 6, 1, 1, 2);

        lbnViscosidadeMedia = new QLabel(gridLayoutWidget);
        lbnViscosidadeMedia->setObjectName(QString::fromUtf8("lbnViscosidadeMedia"));
        lbnViscosidadeMedia->setStyleSheet(QString::fromUtf8(""));
        lbnViscosidadeMedia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnViscosidadeMedia, 11, 1, 1, 2);

        editDiametroPoco = new QLineEdit(gridLayoutWidget);
        editDiametroPoco->setObjectName(QString::fromUtf8("editDiametroPoco"));
        editDiametroPoco->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editDiametroPoco, 3, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 12, 0, 1, 3);

        lbnTituloDensidadeMedia = new QLabel(gridLayoutWidget);
        lbnTituloDensidadeMedia->setObjectName(QString::fromUtf8("lbnTituloDensidadeMedia"));
        lbnTituloDensidadeMedia->setFont(font);
        lbnTituloDensidadeMedia->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloDensidadeMedia, 10, 0, 1, 1);

        lbnTituloProfundidadeOcupada = new QLabel(gridLayoutWidget);
        lbnTituloProfundidadeOcupada->setObjectName(QString::fromUtf8("lbnTituloProfundidadeOcupada"));
        lbnTituloProfundidadeOcupada->setFont(font);
        lbnTituloProfundidadeOcupada->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloProfundidadeOcupada, 9, 0, 1, 1);

        lbnTituloDiametroOD = new QLabel(gridLayoutWidget);
        lbnTituloDiametroOD->setObjectName(QString::fromUtf8("lbnTituloDiametroOD"));
        lbnTituloDiametroOD->setFont(font);
        lbnTituloDiametroOD->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloDiametroOD, 4, 0, 1, 1);

        lbnTituloProfunidadeTotal = new QLabel(gridLayoutWidget);
        lbnTituloProfunidadeTotal->setObjectName(QString::fromUtf8("lbnTituloProfunidadeTotal"));
        lbnTituloProfunidadeTotal->setFont(font);
        lbnTituloProfunidadeTotal->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloProfunidadeTotal, 1, 0, 1, 1);

        editDiametroID = new QLineEdit(gridLayoutWidget);
        editDiametroID->setObjectName(QString::fromUtf8("editDiametroID"));
        editDiametroID->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editDiametroID, 5, 1, 1, 2);

        lbnTituloDiametroPoco = new QLabel(gridLayoutWidget);
        lbnTituloDiametroPoco->setObjectName(QString::fromUtf8("lbnTituloDiametroPoco"));
        lbnTituloDiametroPoco->setFont(font);
        lbnTituloDiametroPoco->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloDiametroPoco, 3, 0, 1, 1);

        lbnTituloViscosidadeMedia = new QLabel(gridLayoutWidget);
        lbnTituloViscosidadeMedia->setObjectName(QString::fromUtf8("lbnTituloViscosidadeMedia"));
        lbnTituloViscosidadeMedia->setFont(font);
        lbnTituloViscosidadeMedia->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloViscosidadeMedia, 11, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 201, 16));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        label->setFont(font1);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(310, 60, 641, 271));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        gridLayoutWidget_2 = new QWidget(groupBox_3);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 40, 611, 221));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
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
        tblFluidos->setObjectName(QString::fromUtf8("tblFluidos"));
        tblFluidos->horizontalHeader()->setDefaultSectionSize(120);

        gridLayout_2->addWidget(tblFluidos, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

        btnRemoverFluido = new QPushButton(gridLayoutWidget_2);
        btnRemoverFluido->setObjectName(QString::fromUtf8("btnRemoverFluido"));
        btnRemoverFluido->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(btnRemoverFluido, 1, 1, 1, 1);

        btnAdicionarFluido = new QPushButton(gridLayoutWidget_2);
        btnAdicionarFluido->setObjectName(QString::fromUtf8("btnAdicionarFluido"));
        btnAdicionarFluido->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(btnAdicionarFluido, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 201, 16));
        label_2->setFont(font1);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 410, 281, 241));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 201, 16));
        label_3->setFont(font1);
        gridLayoutWidget_14 = new QWidget(groupBox_2);
        gridLayoutWidget_14->setObjectName(QString::fromUtf8("gridLayoutWidget_14"));
        gridLayoutWidget_14->setGeometry(QRect(10, 40, 275, 191));
        gridLayout_14 = new QGridLayout(gridLayoutWidget_14);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        editProfundidadePressaoHidroestatica = new QLineEdit(gridLayoutWidget_14);
        editProfundidadePressaoHidroestatica->setObjectName(QString::fromUtf8("editProfundidadePressaoHidroestatica"));
        editProfundidadePressaoHidroestatica->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout_14->addWidget(editProfundidadePressaoHidroestatica, 0, 1, 1, 1);

        lbnTituloPressaoHidroestatica = new QLabel(gridLayoutWidget_14);
        lbnTituloPressaoHidroestatica->setObjectName(QString::fromUtf8("lbnTituloPressaoHidroestatica"));
        lbnTituloPressaoHidroestatica->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_14->addWidget(lbnTituloPressaoHidroestatica, 2, 0, 1, 1);

        lbnPressaoHidroestatica = new QLabel(gridLayoutWidget_14);
        lbnPressaoHidroestatica->setObjectName(QString::fromUtf8("lbnPressaoHidroestatica"));
        lbnPressaoHidroestatica->setStyleSheet(QString::fromUtf8(""));
        lbnPressaoHidroestatica->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_14->addWidget(lbnPressaoHidroestatica, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(verticalSpacer_3, 1, 0, 1, 2);

        lbnTituloProfundidadePressaoHidroestatica = new QLabel(gridLayoutWidget_14);
        lbnTituloProfundidadePressaoHidroestatica->setObjectName(QString::fromUtf8("lbnTituloProfundidadePressaoHidroestatica"));
        lbnTituloProfundidadePressaoHidroestatica->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_14->addWidget(lbnTituloProfundidadePressaoHidroestatica, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(verticalSpacer_4, 3, 0, 1, 3);

        btnCalcularPressaoHidroestatica = new QPushButton(gridLayoutWidget_14);
        btnCalcularPressaoHidroestatica->setObjectName(QString::fromUtf8("btnCalcularPressaoHidroestatica"));
        btnCalcularPressaoHidroestatica->setStyleSheet(QString::fromUtf8(""));

        gridLayout_14->addWidget(btnCalcularPressaoHidroestatica, 4, 0, 1, 1);

        btnExibirGraficoPressaoHidroestatica = new QPushButton(gridLayoutWidget_14);
        btnExibirGraficoPressaoHidroestatica->setObjectName(QString::fromUtf8("btnExibirGraficoPressaoHidroestatica"));
        btnExibirGraficoPressaoHidroestatica->setStyleSheet(QString::fromUtf8(""));

        gridLayout_14->addWidget(btnExibirGraficoPressaoHidroestatica, 4, 1, 1, 2);

        tabWidget_4 = new QTabWidget(centralwidget);
        tabWidget_4->setObjectName(QString::fromUtf8("tabWidget_4"));
        tabWidget_4->setGeometry(QRect(310, 340, 641, 311));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        tabWidget_4->setFont(font2);
        tabWidget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #eaeaea;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"}"));
        tabWidget_4->setIconSize(QSize(16, 16));
        tabWidget_4->setElideMode(Qt::TextElideMode::ElideNone);
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        label_6 = new QLabel(tab_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(330, 20, 201, 16));
        label_6->setFont(font1);
        label_7 = new QLabel(tab_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 20, 201, 16));
        label_7->setFont(font1);
        gridLayoutWidget_4 = new QWidget(tab_7);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(330, 50, 291, 191));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        lbnReynoldsAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnReynoldsAnularNewtoniano->setObjectName(QString::fromUtf8("lbnReynoldsAnularNewtoniano"));
        lbnReynoldsAnularNewtoniano->setStyleSheet(QString::fromUtf8(""));
        lbnReynoldsAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lbnReynoldsAnularNewtoniano, 1, 1, 1, 1);

        lbnTituloReynoldsAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnTituloReynoldsAnularNewtoniano->setObjectName(QString::fromUtf8("lbnTituloReynoldsAnularNewtoniano"));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(false);
        lbnTituloReynoldsAnularNewtoniano->setFont(font3);
        lbnTituloReynoldsAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_4->addWidget(lbnTituloReynoldsAnularNewtoniano, 1, 0, 1, 1);

        lbnVelocidadeAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnVelocidadeAnularNewtoniano->setObjectName(QString::fromUtf8("lbnVelocidadeAnularNewtoniano"));
        lbnVelocidadeAnularNewtoniano->setStyleSheet(QString::fromUtf8(""));
        lbnVelocidadeAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lbnVelocidadeAnularNewtoniano, 0, 1, 1, 1);

        lbnTituloPerdaFriccionalAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnTituloPerdaFriccionalAnularNewtoniano->setObjectName(QString::fromUtf8("lbnTituloPerdaFriccionalAnularNewtoniano"));
        lbnTituloPerdaFriccionalAnularNewtoniano->setFont(font3);
        lbnTituloPerdaFriccionalAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_4->addWidget(lbnTituloPerdaFriccionalAnularNewtoniano, 3, 0, 1, 1);

        lbnTipoFluxoAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnTipoFluxoAnularNewtoniano->setObjectName(QString::fromUtf8("lbnTipoFluxoAnularNewtoniano"));
        lbnTipoFluxoAnularNewtoniano->setStyleSheet(QString::fromUtf8(""));
        lbnTipoFluxoAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lbnTipoFluxoAnularNewtoniano, 2, 1, 1, 1);

        lbnTituloTipoFluxoAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnTituloTipoFluxoAnularNewtoniano->setObjectName(QString::fromUtf8("lbnTituloTipoFluxoAnularNewtoniano"));
        lbnTituloTipoFluxoAnularNewtoniano->setFont(font3);
        lbnTituloTipoFluxoAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_4->addWidget(lbnTituloTipoFluxoAnularNewtoniano, 2, 0, 1, 1);

        lbnTituloVelocidadeAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnTituloVelocidadeAnularNewtoniano->setObjectName(QString::fromUtf8("lbnTituloVelocidadeAnularNewtoniano"));
        lbnTituloVelocidadeAnularNewtoniano->setFont(font3);
        lbnTituloVelocidadeAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_4->addWidget(lbnTituloVelocidadeAnularNewtoniano, 0, 0, 1, 1);

        lbnPerdaFriccionalAnularNewtoniano = new QLabel(gridLayoutWidget_4);
        lbnPerdaFriccionalAnularNewtoniano->setObjectName(QString::fromUtf8("lbnPerdaFriccionalAnularNewtoniano"));
        lbnPerdaFriccionalAnularNewtoniano->setStyleSheet(QString::fromUtf8(""));
        lbnPerdaFriccionalAnularNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lbnPerdaFriccionalAnularNewtoniano, 3, 1, 1, 1);

        btnCalcularModeloNewtonianoAnular = new QPushButton(gridLayoutWidget_4);
        btnCalcularModeloNewtonianoAnular->setObjectName(QString::fromUtf8("btnCalcularModeloNewtonianoAnular"));
        btnCalcularModeloNewtonianoAnular->setFont(font3);

        gridLayout_4->addWidget(btnCalcularModeloNewtonianoAnular, 4, 0, 1, 2);

        gridLayoutWidget_3 = new QWidget(tab_7);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(20, 50, 291, 191));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lbnVelocidadePocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnVelocidadePocoNewtoniano->setObjectName(QString::fromUtf8("lbnVelocidadePocoNewtoniano"));
        lbnVelocidadePocoNewtoniano->setStyleSheet(QString::fromUtf8(""));
        lbnVelocidadePocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lbnVelocidadePocoNewtoniano, 0, 1, 1, 1);

        lbnTituloReynoldsPocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnTituloReynoldsPocoNewtoniano->setObjectName(QString::fromUtf8("lbnTituloReynoldsPocoNewtoniano"));
        lbnTituloReynoldsPocoNewtoniano->setFont(font3);
        lbnTituloReynoldsPocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(lbnTituloReynoldsPocoNewtoniano, 1, 0, 1, 1);

        lbnTipoFluxoPocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnTipoFluxoPocoNewtoniano->setObjectName(QString::fromUtf8("lbnTipoFluxoPocoNewtoniano"));
        lbnTipoFluxoPocoNewtoniano->setStyleSheet(QString::fromUtf8(""));
        lbnTipoFluxoPocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lbnTipoFluxoPocoNewtoniano, 2, 1, 1, 1);

        lbnTituloVelocidadePocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnTituloVelocidadePocoNewtoniano->setObjectName(QString::fromUtf8("lbnTituloVelocidadePocoNewtoniano"));
        lbnTituloVelocidadePocoNewtoniano->setFont(font3);
        lbnTituloVelocidadePocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(lbnTituloVelocidadePocoNewtoniano, 0, 0, 1, 1);

        lbnPerdaFriccionalPocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnPerdaFriccionalPocoNewtoniano->setObjectName(QString::fromUtf8("lbnPerdaFriccionalPocoNewtoniano"));
        lbnPerdaFriccionalPocoNewtoniano->setStyleSheet(QString::fromUtf8(""));
        lbnPerdaFriccionalPocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lbnPerdaFriccionalPocoNewtoniano, 3, 1, 1, 1);

        lbnReynoldsPocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnReynoldsPocoNewtoniano->setObjectName(QString::fromUtf8("lbnReynoldsPocoNewtoniano"));
        lbnReynoldsPocoNewtoniano->setStyleSheet(QString::fromUtf8(""));
        lbnReynoldsPocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lbnReynoldsPocoNewtoniano, 1, 1, 1, 1);

        btnCalcularModeloNewtonianoPoco = new QPushButton(gridLayoutWidget_3);
        btnCalcularModeloNewtonianoPoco->setObjectName(QString::fromUtf8("btnCalcularModeloNewtonianoPoco"));
        btnCalcularModeloNewtonianoPoco->setFont(font3);

        gridLayout_3->addWidget(btnCalcularModeloNewtonianoPoco, 4, 0, 1, 2);

        lbnTituloPerdaFriccionalPocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnTituloPerdaFriccionalPocoNewtoniano->setObjectName(QString::fromUtf8("lbnTituloPerdaFriccionalPocoNewtoniano"));
        lbnTituloPerdaFriccionalPocoNewtoniano->setFont(font3);
        lbnTituloPerdaFriccionalPocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(lbnTituloPerdaFriccionalPocoNewtoniano, 3, 0, 1, 1);

        lbnTituloTipoFluxoPocoNewtoniano = new QLabel(gridLayoutWidget_3);
        lbnTituloTipoFluxoPocoNewtoniano->setObjectName(QString::fromUtf8("lbnTituloTipoFluxoPocoNewtoniano"));
        lbnTituloTipoFluxoPocoNewtoniano->setFont(font3);
        lbnTituloTipoFluxoPocoNewtoniano->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(lbnTituloTipoFluxoPocoNewtoniano, 2, 0, 1, 1);

        tabWidget_4->addTab(tab_7, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        label_8 = new QLabel(tab_9);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(320, 10, 201, 16));
        label_8->setFont(font1);
        label_9 = new QLabel(tab_9);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 10, 201, 16));
        label_9->setFont(font1);
        gridLayoutWidget_5 = new QWidget(tab_9);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(10, 31, 283, 255));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        lbnTituloVelocidadePocoBigham = new QLabel(gridLayoutWidget_5);
        lbnTituloVelocidadePocoBigham->setObjectName(QString::fromUtf8("lbnTituloVelocidadePocoBigham"));
        lbnTituloVelocidadePocoBigham->setFont(font3);
        lbnTituloVelocidadePocoBigham->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_5->addWidget(lbnTituloVelocidadePocoBigham, 2, 0, 1, 1);

        lbnReynoldsPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnReynoldsPocoBigham->setObjectName(QString::fromUtf8("lbnReynoldsPocoBigham"));
        lbnReynoldsPocoBigham->setStyleSheet(QString::fromUtf8(""));
        lbnReynoldsPocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnReynoldsPocoBigham, 5, 1, 1, 1);

        lbnTituloPerdaFriccionalPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnTituloPerdaFriccionalPocoBigham->setObjectName(QString::fromUtf8("lbnTituloPerdaFriccionalPocoBigham"));
        lbnTituloPerdaFriccionalPocoBigham->setFont(font3);
        lbnTituloPerdaFriccionalPocoBigham->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_5->addWidget(lbnTituloPerdaFriccionalPocoBigham, 7, 0, 1, 1);

        lbnVelocidadePocoBigham = new QLabel(gridLayoutWidget_5);
        lbnVelocidadePocoBigham->setObjectName(QString::fromUtf8("lbnVelocidadePocoBigham"));
        lbnVelocidadePocoBigham->setStyleSheet(QString::fromUtf8(""));
        lbnVelocidadePocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnVelocidadePocoBigham, 2, 1, 1, 1);

        btnCalcularModeloBighamPoco = new QPushButton(gridLayoutWidget_5);
        btnCalcularModeloBighamPoco->setObjectName(QString::fromUtf8("btnCalcularModeloBighamPoco"));
        btnCalcularModeloBighamPoco->setFont(font3);

        gridLayout_5->addWidget(btnCalcularModeloBighamPoco, 8, 0, 1, 2);

        editPontoEscoamentoPoco = new QLineEdit(gridLayoutWidget_5);
        editPontoEscoamentoPoco->setObjectName(QString::fromUtf8("editPontoEscoamentoPoco"));
        editPontoEscoamentoPoco->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"border-radius: 5px;"));

        gridLayout_5->addWidget(editPontoEscoamentoPoco, 0, 1, 1, 1);

        lbnTituloHedstromPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnTituloHedstromPocoBigham->setObjectName(QString::fromUtf8("lbnTituloHedstromPocoBigham"));
        lbnTituloHedstromPocoBigham->setFont(font3);
        lbnTituloHedstromPocoBigham->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_5->addWidget(lbnTituloHedstromPocoBigham, 3, 0, 1, 1);

        lbnTituloViscosidadePlasticaPoco = new QLabel(gridLayoutWidget_5);
        lbnTituloViscosidadePlasticaPoco->setObjectName(QString::fromUtf8("lbnTituloViscosidadePlasticaPoco"));
        lbnTituloViscosidadePlasticaPoco->setFont(font3);
        lbnTituloViscosidadePlasticaPoco->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_5->addWidget(lbnTituloViscosidadePlasticaPoco, 1, 0, 1, 1);

        lbnPerdaFriccionalPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnPerdaFriccionalPocoBigham->setObjectName(QString::fromUtf8("lbnPerdaFriccionalPocoBigham"));
        lbnPerdaFriccionalPocoBigham->setStyleSheet(QString::fromUtf8(""));
        lbnPerdaFriccionalPocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnPerdaFriccionalPocoBigham, 7, 1, 1, 1);

        editViscosidadePlasticaPoco = new QLineEdit(gridLayoutWidget_5);
        editViscosidadePlasticaPoco->setObjectName(QString::fromUtf8("editViscosidadePlasticaPoco"));
        editViscosidadePlasticaPoco->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"border-radius: 5px;"));

        gridLayout_5->addWidget(editViscosidadePlasticaPoco, 1, 1, 1, 1);

        lbnTituloPontoEscoamentoPoco = new QLabel(gridLayoutWidget_5);
        lbnTituloPontoEscoamentoPoco->setObjectName(QString::fromUtf8("lbnTituloPontoEscoamentoPoco"));
        lbnTituloPontoEscoamentoPoco->setFont(font3);
        lbnTituloPontoEscoamentoPoco->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_5->addWidget(lbnTituloPontoEscoamentoPoco, 0, 0, 1, 1);

        lbnTituloReynoldsPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnTituloReynoldsPocoBigham->setObjectName(QString::fromUtf8("lbnTituloReynoldsPocoBigham"));
        lbnTituloReynoldsPocoBigham->setFont(font3);
        lbnTituloReynoldsPocoBigham->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_5->addWidget(lbnTituloReynoldsPocoBigham, 5, 0, 1, 1);

        lbnTituloTipoFluxoPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnTituloTipoFluxoPocoBigham->setObjectName(QString::fromUtf8("lbnTituloTipoFluxoPocoBigham"));
        lbnTituloTipoFluxoPocoBigham->setFont(font3);
        lbnTituloTipoFluxoPocoBigham->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_5->addWidget(lbnTituloTipoFluxoPocoBigham, 6, 0, 1, 1);

        lbnTipoFluxoPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnTipoFluxoPocoBigham->setObjectName(QString::fromUtf8("lbnTipoFluxoPocoBigham"));
        lbnTipoFluxoPocoBigham->setStyleSheet(QString::fromUtf8(""));
        lbnTipoFluxoPocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnTipoFluxoPocoBigham, 6, 1, 1, 1);

        lbnTituloCriticoPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnTituloCriticoPocoBigham->setObjectName(QString::fromUtf8("lbnTituloCriticoPocoBigham"));
        lbnTituloCriticoPocoBigham->setFont(font3);
        lbnTituloCriticoPocoBigham->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_5->addWidget(lbnTituloCriticoPocoBigham, 4, 0, 1, 1);

        lbnReynoldsHedstromPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnReynoldsHedstromPocoBigham->setObjectName(QString::fromUtf8("lbnReynoldsHedstromPocoBigham"));
        lbnReynoldsHedstromPocoBigham->setStyleSheet(QString::fromUtf8(""));
        lbnReynoldsHedstromPocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnReynoldsHedstromPocoBigham, 3, 1, 1, 1);

        lbnReynoldsCriticoPocoBigham = new QLabel(gridLayoutWidget_5);
        lbnReynoldsCriticoPocoBigham->setObjectName(QString::fromUtf8("lbnReynoldsCriticoPocoBigham"));
        lbnReynoldsCriticoPocoBigham->setStyleSheet(QString::fromUtf8(""));
        lbnReynoldsCriticoPocoBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(lbnReynoldsCriticoPocoBigham, 4, 1, 1, 1);

        gridLayoutWidget_6 = new QWidget(tab_9);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(320, 30, 283, 255));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        editPontoEscoamentoAnular = new QLineEdit(gridLayoutWidget_6);
        editPontoEscoamentoAnular->setObjectName(QString::fromUtf8("editPontoEscoamentoAnular"));
        editPontoEscoamentoAnular->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"border-radius: 5px;"));

        gridLayout_6->addWidget(editPontoEscoamentoAnular, 0, 1, 1, 1);

        lbnTituloHedstromAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnTituloHedstromAnularBigham->setObjectName(QString::fromUtf8("lbnTituloHedstromAnularBigham"));
        lbnTituloHedstromAnularBigham->setFont(font3);
        lbnTituloHedstromAnularBigham->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_6->addWidget(lbnTituloHedstromAnularBigham, 3, 0, 1, 1);

        btnCalcularModeloBighamAnular = new QPushButton(gridLayoutWidget_6);
        btnCalcularModeloBighamAnular->setObjectName(QString::fromUtf8("btnCalcularModeloBighamAnular"));
        btnCalcularModeloBighamAnular->setFont(font3);

        gridLayout_6->addWidget(btnCalcularModeloBighamAnular, 8, 0, 1, 2);

        lbnVelocidadeAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnVelocidadeAnularBigham->setObjectName(QString::fromUtf8("lbnVelocidadeAnularBigham"));
        lbnVelocidadeAnularBigham->setStyleSheet(QString::fromUtf8(""));
        lbnVelocidadeAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnVelocidadeAnularBigham, 2, 1, 1, 1);

        lbnReynoldsAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnReynoldsAnularBigham->setObjectName(QString::fromUtf8("lbnReynoldsAnularBigham"));
        lbnReynoldsAnularBigham->setStyleSheet(QString::fromUtf8(""));
        lbnReynoldsAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnReynoldsAnularBigham, 5, 1, 1, 1);

        lbnTituloTipoFluxoAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnTituloTipoFluxoAnularBigham->setObjectName(QString::fromUtf8("lbnTituloTipoFluxoAnularBigham"));
        lbnTituloTipoFluxoAnularBigham->setFont(font3);
        lbnTituloTipoFluxoAnularBigham->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_6->addWidget(lbnTituloTipoFluxoAnularBigham, 6, 0, 1, 1);

        lbnPerdaFriccionalAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnPerdaFriccionalAnularBigham->setObjectName(QString::fromUtf8("lbnPerdaFriccionalAnularBigham"));
        lbnPerdaFriccionalAnularBigham->setStyleSheet(QString::fromUtf8(""));
        lbnPerdaFriccionalAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnPerdaFriccionalAnularBigham, 7, 1, 1, 1);

        lbnTituloPontoEscoamentoAnular = new QLabel(gridLayoutWidget_6);
        lbnTituloPontoEscoamentoAnular->setObjectName(QString::fromUtf8("lbnTituloPontoEscoamentoAnular"));
        lbnTituloPontoEscoamentoAnular->setFont(font3);
        lbnTituloPontoEscoamentoAnular->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_6->addWidget(lbnTituloPontoEscoamentoAnular, 0, 0, 1, 1);

        lbnTituloReynoldsAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnTituloReynoldsAnularBigham->setObjectName(QString::fromUtf8("lbnTituloReynoldsAnularBigham"));
        lbnTituloReynoldsAnularBigham->setFont(font3);
        lbnTituloReynoldsAnularBigham->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_6->addWidget(lbnTituloReynoldsAnularBigham, 5, 0, 1, 1);

        editViscosidadePlasticaAnular = new QLineEdit(gridLayoutWidget_6);
        editViscosidadePlasticaAnular->setObjectName(QString::fromUtf8("editViscosidadePlasticaAnular"));
        editViscosidadePlasticaAnular->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"border-radius: 5px;"));

        gridLayout_6->addWidget(editViscosidadePlasticaAnular, 1, 1, 1, 1);

        lbnTipoFluxoAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnTipoFluxoAnularBigham->setObjectName(QString::fromUtf8("lbnTipoFluxoAnularBigham"));
        lbnTipoFluxoAnularBigham->setStyleSheet(QString::fromUtf8(""));
        lbnTipoFluxoAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnTipoFluxoAnularBigham, 6, 1, 1, 1);

        lbnTituloViscosidadePlasticaAnular = new QLabel(gridLayoutWidget_6);
        lbnTituloViscosidadePlasticaAnular->setObjectName(QString::fromUtf8("lbnTituloViscosidadePlasticaAnular"));
        lbnTituloViscosidadePlasticaAnular->setFont(font3);
        lbnTituloViscosidadePlasticaAnular->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_6->addWidget(lbnTituloViscosidadePlasticaAnular, 1, 0, 1, 1);

        lbnTituloVelocidadeAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnTituloVelocidadeAnularBigham->setObjectName(QString::fromUtf8("lbnTituloVelocidadeAnularBigham"));
        lbnTituloVelocidadeAnularBigham->setFont(font3);
        lbnTituloVelocidadeAnularBigham->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_6->addWidget(lbnTituloVelocidadeAnularBigham, 2, 0, 1, 1);

        lbnTituloPerdaFriccionalAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnTituloPerdaFriccionalAnularBigham->setObjectName(QString::fromUtf8("lbnTituloPerdaFriccionalAnularBigham"));
        lbnTituloPerdaFriccionalAnularBigham->setFont(font3);
        lbnTituloPerdaFriccionalAnularBigham->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_6->addWidget(lbnTituloPerdaFriccionalAnularBigham, 7, 0, 1, 1);

        lbnTituloCriticoAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnTituloCriticoAnularBigham->setObjectName(QString::fromUtf8("lbnTituloCriticoAnularBigham"));
        lbnTituloCriticoAnularBigham->setFont(font3);
        lbnTituloCriticoAnularBigham->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_6->addWidget(lbnTituloCriticoAnularBigham, 4, 0, 1, 1);

        lbnReynoldsHedstromAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnReynoldsHedstromAnularBigham->setObjectName(QString::fromUtf8("lbnReynoldsHedstromAnularBigham"));
        lbnReynoldsHedstromAnularBigham->setStyleSheet(QString::fromUtf8(""));
        lbnReynoldsHedstromAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnReynoldsHedstromAnularBigham, 3, 1, 1, 1);

        lbnReynoldsCriticoAnularBigham = new QLabel(gridLayoutWidget_6);
        lbnReynoldsCriticoAnularBigham->setObjectName(QString::fromUtf8("lbnReynoldsCriticoAnularBigham"));
        lbnReynoldsCriticoAnularBigham->setStyleSheet(QString::fromUtf8(""));
        lbnReynoldsCriticoAnularBigham->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_6->addWidget(lbnReynoldsCriticoAnularBigham, 4, 1, 1, 1);

        tabWidget_4->addTab(tab_9, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        label_4 = new QLabel(tab_8);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 201, 16));
        label_4->setFont(font1);
        label_5 = new QLabel(tab_8);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(330, 10, 201, 16));
        label_5->setFont(font1);
        gridLayoutWidget_7 = new QWidget(tab_8);
        gridLayoutWidget_7->setObjectName(QString::fromUtf8("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(10, 40, 291, 228));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_7);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        lbnTituloCriticoPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnTituloCriticoPocoPotencia->setObjectName(QString::fromUtf8("lbnTituloCriticoPocoPotencia"));
        lbnTituloCriticoPocoPotencia->setFont(font3);
        lbnTituloCriticoPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_7->addWidget(lbnTituloCriticoPocoPotencia, 3, 0, 1, 1);

        lbnTituloVelocidadePocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnTituloVelocidadePocoPotencia->setObjectName(QString::fromUtf8("lbnTituloVelocidadePocoPotencia"));
        lbnTituloVelocidadePocoPotencia->setFont(font3);
        lbnTituloVelocidadePocoPotencia->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_7->addWidget(lbnTituloVelocidadePocoPotencia, 2, 0, 1, 1);

        lbnTipoFluxoPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnTipoFluxoPocoPotencia->setObjectName(QString::fromUtf8("lbnTipoFluxoPocoPotencia"));
        lbnTipoFluxoPocoPotencia->setStyleSheet(QString::fromUtf8(""));
        lbnTipoFluxoPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnTipoFluxoPocoPotencia, 5, 1, 1, 1);

        lbnReynoldsPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnReynoldsPocoPotencia->setObjectName(QString::fromUtf8("lbnReynoldsPocoPotencia"));
        lbnReynoldsPocoPotencia->setStyleSheet(QString::fromUtf8(""));
        lbnReynoldsPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnReynoldsPocoPotencia, 4, 1, 1, 1);

        lbnTituloPerdaFriccionalPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnTituloPerdaFriccionalPocoPotencia->setObjectName(QString::fromUtf8("lbnTituloPerdaFriccionalPocoPotencia"));
        lbnTituloPerdaFriccionalPocoPotencia->setFont(font3);
        lbnTituloPerdaFriccionalPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_7->addWidget(lbnTituloPerdaFriccionalPocoPotencia, 6, 0, 1, 1);

        editIndiceConsistenciaPotenciaPoco = new QLineEdit(gridLayoutWidget_7);
        editIndiceConsistenciaPotenciaPoco->setObjectName(QString::fromUtf8("editIndiceConsistenciaPotenciaPoco"));
        editIndiceConsistenciaPotenciaPoco->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        gridLayout_7->addWidget(editIndiceConsistenciaPotenciaPoco, 0, 1, 1, 1);

        lbnReynoldsCriticoPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnReynoldsCriticoPocoPotencia->setObjectName(QString::fromUtf8("lbnReynoldsCriticoPocoPotencia"));
        lbnReynoldsCriticoPocoPotencia->setStyleSheet(QString::fromUtf8(""));
        lbnReynoldsCriticoPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnReynoldsCriticoPocoPotencia, 3, 1, 1, 1);

        lbnPerdaFriccionalPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnPerdaFriccionalPocoPotencia->setObjectName(QString::fromUtf8("lbnPerdaFriccionalPocoPotencia"));
        lbnPerdaFriccionalPocoPotencia->setStyleSheet(QString::fromUtf8(""));
        lbnPerdaFriccionalPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnPerdaFriccionalPocoPotencia, 6, 1, 1, 1);

        lbnTituloTipoFluxoPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnTituloTipoFluxoPocoPotencia->setObjectName(QString::fromUtf8("lbnTituloTipoFluxoPocoPotencia"));
        lbnTituloTipoFluxoPocoPotencia->setFont(font3);
        lbnTituloTipoFluxoPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_7->addWidget(lbnTituloTipoFluxoPocoPotencia, 5, 0, 1, 1);

        lbnTituloIndiceConsistenciaPoco = new QLabel(gridLayoutWidget_7);
        lbnTituloIndiceConsistenciaPoco->setObjectName(QString::fromUtf8("lbnTituloIndiceConsistenciaPoco"));
        lbnTituloIndiceConsistenciaPoco->setFont(font3);
        lbnTituloIndiceConsistenciaPoco->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_7->addWidget(lbnTituloIndiceConsistenciaPoco, 0, 0, 1, 1);

        btnCalcularModeloPotenciaPoco = new QPushButton(gridLayoutWidget_7);
        btnCalcularModeloPotenciaPoco->setObjectName(QString::fromUtf8("btnCalcularModeloPotenciaPoco"));
        btnCalcularModeloPotenciaPoco->setFont(font3);

        gridLayout_7->addWidget(btnCalcularModeloPotenciaPoco, 7, 0, 1, 2);

        lbnVelocidadePocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnVelocidadePocoPotencia->setObjectName(QString::fromUtf8("lbnVelocidadePocoPotencia"));
        lbnVelocidadePocoPotencia->setStyleSheet(QString::fromUtf8(""));
        lbnVelocidadePocoPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(lbnVelocidadePocoPotencia, 2, 1, 1, 1);

        lbnTituloReynoldsPocoPotencia = new QLabel(gridLayoutWidget_7);
        lbnTituloReynoldsPocoPotencia->setObjectName(QString::fromUtf8("lbnTituloReynoldsPocoPotencia"));
        lbnTituloReynoldsPocoPotencia->setFont(font3);
        lbnTituloReynoldsPocoPotencia->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_7->addWidget(lbnTituloReynoldsPocoPotencia, 4, 0, 1, 1);

        lbnTituloIndiceComportamentoPoco = new QLabel(gridLayoutWidget_7);
        lbnTituloIndiceComportamentoPoco->setObjectName(QString::fromUtf8("lbnTituloIndiceComportamentoPoco"));
        lbnTituloIndiceComportamentoPoco->setFont(font3);
        lbnTituloIndiceComportamentoPoco->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_7->addWidget(lbnTituloIndiceComportamentoPoco, 1, 0, 1, 1);

        editIndiceComportamentoPoco = new QLineEdit(gridLayoutWidget_7);
        editIndiceComportamentoPoco->setObjectName(QString::fromUtf8("editIndiceComportamentoPoco"));
        editIndiceComportamentoPoco->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        gridLayout_7->addWidget(editIndiceComportamentoPoco, 1, 1, 1, 1);

        gridLayoutWidget_8 = new QWidget(tab_8);
        gridLayoutWidget_8->setObjectName(QString::fromUtf8("gridLayoutWidget_8"));
        gridLayoutWidget_8->setGeometry(QRect(330, 40, 281, 228));
        gridLayout_8 = new QGridLayout(gridLayoutWidget_8);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        lbnPerdaFriccionalAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnPerdaFriccionalAnularPotencia->setObjectName(QString::fromUtf8("lbnPerdaFriccionalAnularPotencia"));
        lbnPerdaFriccionalAnularPotencia->setStyleSheet(QString::fromUtf8(""));
        lbnPerdaFriccionalAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnPerdaFriccionalAnularPotencia, 6, 1, 1, 1);

        lbnTituloVelocidadeAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnTituloVelocidadeAnularPotencia->setObjectName(QString::fromUtf8("lbnTituloVelocidadeAnularPotencia"));
        lbnTituloVelocidadeAnularPotencia->setFont(font3);
        lbnTituloVelocidadeAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_8->addWidget(lbnTituloVelocidadeAnularPotencia, 2, 0, 1, 1);

        lbnReynoldsAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnReynoldsAnularPotencia->setObjectName(QString::fromUtf8("lbnReynoldsAnularPotencia"));
        lbnReynoldsAnularPotencia->setStyleSheet(QString::fromUtf8(""));
        lbnReynoldsAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnReynoldsAnularPotencia, 4, 1, 1, 1);

        lbnTituloTipoFluxoAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnTituloTipoFluxoAnularPotencia->setObjectName(QString::fromUtf8("lbnTituloTipoFluxoAnularPotencia"));
        lbnTituloTipoFluxoAnularPotencia->setFont(font3);
        lbnTituloTipoFluxoAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_8->addWidget(lbnTituloTipoFluxoAnularPotencia, 5, 0, 1, 1);

        lbnTituloReynoldsAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnTituloReynoldsAnularPotencia->setObjectName(QString::fromUtf8("lbnTituloReynoldsAnularPotencia"));
        lbnTituloReynoldsAnularPotencia->setFont(font3);
        lbnTituloReynoldsAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_8->addWidget(lbnTituloReynoldsAnularPotencia, 4, 0, 1, 1);

        lbnVelocidadeAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnVelocidadeAnularPotencia->setObjectName(QString::fromUtf8("lbnVelocidadeAnularPotencia"));
        lbnVelocidadeAnularPotencia->setStyleSheet(QString::fromUtf8(""));
        lbnVelocidadeAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnVelocidadeAnularPotencia, 2, 1, 1, 1);

        lbnTituloIndiceConsistenciaAnular = new QLabel(gridLayoutWidget_8);
        lbnTituloIndiceConsistenciaAnular->setObjectName(QString::fromUtf8("lbnTituloIndiceConsistenciaAnular"));
        lbnTituloIndiceConsistenciaAnular->setFont(font3);
        lbnTituloIndiceConsistenciaAnular->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_8->addWidget(lbnTituloIndiceConsistenciaAnular, 0, 0, 1, 1);

        lbnTituloPerdaFriccionalAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnTituloPerdaFriccionalAnularPotencia->setObjectName(QString::fromUtf8("lbnTituloPerdaFriccionalAnularPotencia"));
        lbnTituloPerdaFriccionalAnularPotencia->setFont(font3);
        lbnTituloPerdaFriccionalAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_8->addWidget(lbnTituloPerdaFriccionalAnularPotencia, 6, 0, 1, 1);

        btnCalcularModeloPotenciaAnular = new QPushButton(gridLayoutWidget_8);
        btnCalcularModeloPotenciaAnular->setObjectName(QString::fromUtf8("btnCalcularModeloPotenciaAnular"));
        btnCalcularModeloPotenciaAnular->setFont(font3);

        gridLayout_8->addWidget(btnCalcularModeloPotenciaAnular, 7, 0, 1, 2);

        lbnTituloCriticoAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnTituloCriticoAnularPotencia->setObjectName(QString::fromUtf8("lbnTituloCriticoAnularPotencia"));
        lbnTituloCriticoAnularPotencia->setFont(font3);
        lbnTituloCriticoAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_8->addWidget(lbnTituloCriticoAnularPotencia, 3, 0, 1, 1);

        editIndiceConsistenciaPotenciaAnular = new QLineEdit(gridLayoutWidget_8);
        editIndiceConsistenciaPotenciaAnular->setObjectName(QString::fromUtf8("editIndiceConsistenciaPotenciaAnular"));
        editIndiceConsistenciaPotenciaAnular->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        gridLayout_8->addWidget(editIndiceConsistenciaPotenciaAnular, 0, 1, 1, 1);

        lbnTipoFluxoAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnTipoFluxoAnularPotencia->setObjectName(QString::fromUtf8("lbnTipoFluxoAnularPotencia"));
        lbnTipoFluxoAnularPotencia->setStyleSheet(QString::fromUtf8(""));
        lbnTipoFluxoAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnTipoFluxoAnularPotencia, 5, 1, 1, 1);

        lbnReynoldsCriticoAnularPotencia = new QLabel(gridLayoutWidget_8);
        lbnReynoldsCriticoAnularPotencia->setObjectName(QString::fromUtf8("lbnReynoldsCriticoAnularPotencia"));
        lbnReynoldsCriticoAnularPotencia->setStyleSheet(QString::fromUtf8(""));
        lbnReynoldsCriticoAnularPotencia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lbnReynoldsCriticoAnularPotencia, 3, 1, 1, 1);

        lbnTituloIndiceComportamentoAnular = new QLabel(gridLayoutWidget_8);
        lbnTituloIndiceComportamentoAnular->setObjectName(QString::fromUtf8("lbnTituloIndiceComportamentoAnular"));
        lbnTituloIndiceComportamentoAnular->setFont(font3);
        lbnTituloIndiceComportamentoAnular->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_8->addWidget(lbnTituloIndiceComportamentoAnular, 1, 0, 1, 1);

        editIndiceComportamentoAnular = new QLineEdit(gridLayoutWidget_8);
        editIndiceComportamentoAnular->setObjectName(QString::fromUtf8("editIndiceComportamentoAnular"));
        editIndiceComportamentoAnular->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        gridLayout_8->addWidget(editIndiceComportamentoAnular, 1, 1, 1, 1);

        tabWidget_4->addTab(tab_8, QString());
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(970, 60, 281, 591));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        customPlotPoco = new QCustomPlot(groupBox_4);
        customPlotPoco->setObjectName(QString::fromUtf8("customPlotPoco"));
        customPlotPoco->setGeometry(QRect(10, 40, 261, 541));
        customPlotPoco->setStyleSheet(QString::fromUtf8(""));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 10, 201, 16));
        label_12->setFont(font1);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(230, 0, 996, 64));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        label_10->setFont(font4);
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_10);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font5;
        font5.setPointSize(11);
        font5.setBold(false);
        label_11->setFont(font5);
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_11);

        label_11->raise();
        label_10->raise();
        CSimuladorReologico->setCentralWidget(centralwidget);
        layoutWidget->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        groupBox->raise();
        tabWidget_4->raise();
        groupBox_4->raise();
        statusbar = new QStatusBar(CSimuladorReologico);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CSimuladorReologico->setStatusBar(statusbar);
        menubar = new QMenuBar(CSimuladorReologico);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1264, 26));
        menuArquivo = new QMenu(menubar);
        menuArquivo->setObjectName(QString::fromUtf8("menuArquivo"));
        menuImportar_Dados = new QMenu(menuArquivo);
        menuImportar_Dados->setObjectName(QString::fromUtf8("menuImportar_Dados"));
        menuAjuda = new QMenu(menubar);
        menuAjuda->setObjectName(QString::fromUtf8("menuAjuda"));
        CSimuladorReologico->setMenuBar(menubar);
        QWidget::setTabOrder(editNomePoco, editProfundidadeTotal);
        QWidget::setTabOrder(editProfundidadeTotal, editPressaoSuperficie);
        QWidget::setTabOrder(editPressaoSuperficie, editDiametroPoco);
        QWidget::setTabOrder(editDiametroPoco, editDiametroOD);
        QWidget::setTabOrder(editDiametroOD, editDiametroID);
        QWidget::setTabOrder(editDiametroID, editVazao);
        QWidget::setTabOrder(editVazao, editProfundidadePressaoHidroestatica);
        QWidget::setTabOrder(editProfundidadePressaoHidroestatica, btnCalcularPressaoHidroestatica);
        QWidget::setTabOrder(btnCalcularPressaoHidroestatica, btnExibirGraficoPressaoHidroestatica);
        QWidget::setTabOrder(btnExibirGraficoPressaoHidroestatica, tblFluidos);
        QWidget::setTabOrder(tblFluidos, btnAdicionarFluido);
        QWidget::setTabOrder(btnAdicionarFluido, btnRemoverFluido);
        QWidget::setTabOrder(btnRemoverFluido, tabWidget_4);
        QWidget::setTabOrder(tabWidget_4, btnCalcularModeloNewtonianoPoco);
        QWidget::setTabOrder(btnCalcularModeloNewtonianoPoco, btnCalcularModeloNewtonianoAnular);
        QWidget::setTabOrder(btnCalcularModeloNewtonianoAnular, editPontoEscoamentoPoco);
        QWidget::setTabOrder(editPontoEscoamentoPoco, editViscosidadePlasticaPoco);
        QWidget::setTabOrder(editViscosidadePlasticaPoco, btnCalcularModeloBighamPoco);
        QWidget::setTabOrder(btnCalcularModeloBighamPoco, editPontoEscoamentoAnular);
        QWidget::setTabOrder(editPontoEscoamentoAnular, editViscosidadePlasticaAnular);
        QWidget::setTabOrder(editViscosidadePlasticaAnular, btnCalcularModeloBighamAnular);
        QWidget::setTabOrder(btnCalcularModeloBighamAnular, editIndiceConsistenciaPotenciaPoco);
        QWidget::setTabOrder(editIndiceConsistenciaPotenciaPoco, editIndiceComportamentoPoco);
        QWidget::setTabOrder(editIndiceComportamentoPoco, btnCalcularModeloPotenciaPoco);
        QWidget::setTabOrder(btnCalcularModeloPotenciaPoco, editIndiceConsistenciaPotenciaAnular);
        QWidget::setTabOrder(editIndiceConsistenciaPotenciaAnular, editIndiceComportamentoAnular);
        QWidget::setTabOrder(editIndiceComportamentoAnular, btnCalcularModeloPotenciaAnular);

        menubar->addAction(menuArquivo->menuAction());
        menubar->addAction(menuAjuda->menuAction());
        menuArquivo->addAction(actionNova_Simula_o);
        menuArquivo->addAction(actionSalvar);
        menuArquivo->addAction(actionSalvar_Como);
        menuArquivo->addSeparator();
        menuArquivo->addAction(menuImportar_Dados->menuAction());
        menuArquivo->addAction(actionExportar_como_Imagem);
        menuImportar_Dados->addAction(actionArquivo_dat);
        menuAjuda->addAction(actionAjuda);
        menuAjuda->addAction(actionSobre_os_Modelos_Reol_gicos);
        menuAjuda->addAction(actionSobre_o_Programa);

        retranslateUi(CSimuladorReologico);

        tabWidget_4->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CSimuladorReologico);
    } // setupUi

    void retranslateUi(QMainWindow *CSimuladorReologico)
    {
        CSimuladorReologico->setWindowTitle(QCoreApplication::translate("CSimuladorReologico", "CSimuladorPoco", nullptr));
        actionNova_Simula_o->setText(QCoreApplication::translate("CSimuladorReologico", "Nova Simula\303\247\303\243o", nullptr));
#if QT_CONFIG(shortcut)
        actionNova_Simula_o->setShortcut(QCoreApplication::translate("CSimuladorReologico", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSalvar_Como->setText(QCoreApplication::translate("CSimuladorReologico", "Salvar Como...", nullptr));
#if QT_CONFIG(shortcut)
        actionSalvar_Como->setShortcut(QCoreApplication::translate("CSimuladorReologico", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExportar_como_Imagem->setText(QCoreApplication::translate("CSimuladorReologico", "Exportar como Imagem", nullptr));
        actionAjuda->setText(QCoreApplication::translate("CSimuladorReologico", "Manual do Usu\303\241rio", nullptr));
#if QT_CONFIG(shortcut)
        actionAjuda->setShortcut(QCoreApplication::translate("CSimuladorReologico", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSobre_os_Modelos_Reol_gicos->setText(QCoreApplication::translate("CSimuladorReologico", "Modelos Reol\303\263gicos Utilizados", nullptr));
        actionSobre_o_Programa->setText(QCoreApplication::translate("CSimuladorReologico", "Sobre o SEEP", nullptr));
        actionArquivo_dat->setText(QCoreApplication::translate("CSimuladorReologico", "Arquivo .(dat)", nullptr));
        actionSalvar->setText(QCoreApplication::translate("CSimuladorReologico", "Salvar", nullptr));
#if QT_CONFIG(shortcut)
        actionSalvar->setShortcut(QCoreApplication::translate("CSimuladorReologico", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        lbnTituloNomePoco->setText(QCoreApplication::translate("CSimuladorReologico", "Nome Po\303\247o", nullptr));
        lbnTituloDiametroID->setText(QCoreApplication::translate("CSimuladorReologico", "Diam. Interno ID  (in)", nullptr));
        lbnProfundidadeOcupada->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloPressaoSuperficie->setText(QCoreApplication::translate("CSimuladorReologico", "Press\303\243o Superficie (psi)", nullptr));
        lbnTituloVazao->setText(QCoreApplication::translate("CSimuladorReologico", "Vaz\303\243o (gal/min)", nullptr));
        lbnDensidadeMedia->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnViscosidadeMedia->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloDensidadeMedia->setText(QCoreApplication::translate("CSimuladorReologico", "Densidade M\303\251dia (lb/gal): ", nullptr));
        lbnTituloProfundidadeOcupada->setText(QCoreApplication::translate("CSimuladorReologico", "Produndidade Ocupada (ft): ", nullptr));
        lbnTituloDiametroOD->setText(QCoreApplication::translate("CSimuladorReologico", "Diam. Externo OD (in)", nullptr));
        lbnTituloProfunidadeTotal->setText(QCoreApplication::translate("CSimuladorReologico", "Profundidade Total (ft)", nullptr));
        lbnTituloDiametroPoco->setText(QCoreApplication::translate("CSimuladorReologico", "Diametro Po\303\247o (in)", nullptr));
        lbnTituloViscosidadeMedia->setText(QCoreApplication::translate("CSimuladorReologico", "Viscosidade M\303\251dia (cP):", nullptr));
        label->setText(QCoreApplication::translate("CSimuladorReologico", "Dados do Po\303\247o", nullptr));
        groupBox_3->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem = tblFluidos->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CSimuladorReologico", "Nome", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblFluidos->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CSimuladorReologico", "Densidade (lbm/gal)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblFluidos->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CSimuladorReologico", "Viscosidade (cP)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblFluidos->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CSimuladorReologico", "Prof. Inicial (ft)", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblFluidos->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CSimuladorReologico", "Prof. Final (ft)", nullptr));
        btnRemoverFluido->setText(QCoreApplication::translate("CSimuladorReologico", "Remover", nullptr));
        btnAdicionarFluido->setText(QCoreApplication::translate("CSimuladorReologico", "Adicionar", nullptr));
        label_2->setText(QCoreApplication::translate("CSimuladorReologico", "Dados do Fluido", nullptr));
        groupBox_2->setTitle(QString());
        label_3->setText(QCoreApplication::translate("CSimuladorReologico", "Press\303\243o Hidroest\303\241tica", nullptr));
        editProfundidadePressaoHidroestatica->setText(QString());
        lbnTituloPressaoHidroestatica->setText(QCoreApplication::translate("CSimuladorReologico", "Pressao Hidrost\303\241tica (psi)", nullptr));
        lbnPressaoHidroestatica->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloProfundidadePressaoHidroestatica->setText(QCoreApplication::translate("CSimuladorReologico", "Profundidade (ft)", nullptr));
        btnCalcularPressaoHidroestatica->setText(QCoreApplication::translate("CSimuladorReologico", "Calcular", nullptr));
        btnExibirGraficoPressaoHidroestatica->setText(QCoreApplication::translate("CSimuladorReologico", "Exibir Gr\303\241fico", nullptr));
        label_6->setText(QCoreApplication::translate("CSimuladorReologico", "Anular", nullptr));
        label_7->setText(QCoreApplication::translate("CSimuladorReologico", "Po\303\247o", nullptr));
        lbnReynoldsAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloReynoldsAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "Reynolds no Anular", nullptr));
        lbnVelocidadeAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloPerdaFriccionalAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "Perda Friccional no Anular (psi/ft)", nullptr));
        lbnTipoFluxoAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloTipoFluxoAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "Tipo de Fluxo no Anular", nullptr));
        lbnTituloVelocidadeAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "Velocidade do Anular (ft/s)", nullptr));
        lbnPerdaFriccionalAnularNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        btnCalcularModeloNewtonianoAnular->setText(QCoreApplication::translate("CSimuladorReologico", "Calcular", nullptr));
        lbnVelocidadePocoNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloReynoldsPocoNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "Reynolds no Po\303\247o", nullptr));
        lbnTipoFluxoPocoNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloVelocidadePocoNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "Velocidade do Po\303\247o (ft/s)", nullptr));
        lbnPerdaFriccionalPocoNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnReynoldsPocoNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        btnCalcularModeloNewtonianoPoco->setText(QCoreApplication::translate("CSimuladorReologico", "Calcular", nullptr));
        lbnTituloPerdaFriccionalPocoNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "Perda Friccional no Po\303\247o (psi/ft)", nullptr));
        lbnTituloTipoFluxoPocoNewtoniano->setText(QCoreApplication::translate("CSimuladorReologico", "Tipo de Fluxo no Po\303\247o", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_7), QCoreApplication::translate("CSimuladorReologico", "           Modelo Newtoniano           ", nullptr));
        label_8->setText(QCoreApplication::translate("CSimuladorReologico", "Anular", nullptr));
        label_9->setText(QCoreApplication::translate("CSimuladorReologico", "Po\303\247o", nullptr));
        lbnTituloVelocidadePocoBigham->setText(QCoreApplication::translate("CSimuladorReologico", "Velocidade do Po\303\247o (ft/s)", nullptr));
        lbnReynoldsPocoBigham->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloPerdaFriccionalPocoBigham->setText(QCoreApplication::translate("CSimuladorReologico", "Perda Friccional no Po\303\247o (psi/ft)", nullptr));
        lbnVelocidadePocoBigham->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        btnCalcularModeloBighamPoco->setText(QCoreApplication::translate("CSimuladorReologico", "Calcular", nullptr));
        lbnTituloHedstromPocoBigham->setText(QCoreApplication::translate("CSimuladorReologico", "Reynolds Hedstrom", nullptr));
        lbnTituloViscosidadePlasticaPoco->setText(QCoreApplication::translate("CSimuladorReologico", "Viscosidade Pl\303\241stica (cP)", nullptr));
        lbnPerdaFriccionalPocoBigham->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloPontoEscoamentoPoco->setText(QCoreApplication::translate("CSimuladorReologico", "Ponto de Escoamento (lbf/100 sq.ft)", nullptr));
        lbnTituloReynoldsPocoBigham->setText(QCoreApplication::translate("CSimuladorReologico", "Reynolds no Po\303\247o", nullptr));
        lbnTituloTipoFluxoPocoBigham->setText(QCoreApplication::translate("CSimuladorReologico", "Tipo de Fluxo no Po\303\247o", nullptr));
        lbnTipoFluxoPocoBigham->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloCriticoPocoBigham->setText(QCoreApplication::translate("CSimuladorReologico", "Reynolds Cr\303\255tico", nullptr));
        lbnReynoldsHedstromPocoBigham->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnReynoldsCriticoPocoBigham->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloHedstromAnularBigham->setText(QCoreApplication::translate("CSimuladorReologico", "Reynolds Hedstrom", nullptr));
        btnCalcularModeloBighamAnular->setText(QCoreApplication::translate("CSimuladorReologico", "Calcular", nullptr));
        lbnVelocidadeAnularBigham->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnReynoldsAnularBigham->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloTipoFluxoAnularBigham->setText(QCoreApplication::translate("CSimuladorReologico", "Tipo de Fluxo no Anular", nullptr));
        lbnPerdaFriccionalAnularBigham->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloPontoEscoamentoAnular->setText(QCoreApplication::translate("CSimuladorReologico", "Ponto de Escoamento (lbf/100 sq.ft)", nullptr));
        lbnTituloReynoldsAnularBigham->setText(QCoreApplication::translate("CSimuladorReologico", "Reynolds no Anular", nullptr));
        lbnTipoFluxoAnularBigham->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloViscosidadePlasticaAnular->setText(QCoreApplication::translate("CSimuladorReologico", "Viscosidade Pl\303\241stica (cP)", nullptr));
        lbnTituloVelocidadeAnularBigham->setText(QCoreApplication::translate("CSimuladorReologico", "Velocidade do Anular (ft/s)", nullptr));
        lbnTituloPerdaFriccionalAnularBigham->setText(QCoreApplication::translate("CSimuladorReologico", "Perda Friccional no Anular (psi/ft)", nullptr));
        lbnTituloCriticoAnularBigham->setText(QCoreApplication::translate("CSimuladorReologico", "Reynolds Cr\303\255tico", nullptr));
        lbnReynoldsHedstromAnularBigham->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnReynoldsCriticoAnularBigham->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_9), QCoreApplication::translate("CSimuladorReologico", "           Modelo de Bingham            ", nullptr));
        label_4->setText(QCoreApplication::translate("CSimuladorReologico", "Po\303\247o", nullptr));
        label_5->setText(QCoreApplication::translate("CSimuladorReologico", "Anular", nullptr));
        lbnTituloCriticoPocoPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "Reynolds Cr\303\255tico", nullptr));
        lbnTituloVelocidadePocoPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "Velocidade do Po\303\247o (ft/s)", nullptr));
        lbnTipoFluxoPocoPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnReynoldsPocoPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloPerdaFriccionalPocoPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "Perda Friccional no Po\303\247o (psi/ft)", nullptr));
        lbnReynoldsCriticoPocoPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnPerdaFriccionalPocoPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloTipoFluxoPocoPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "Tipo de Fluxo no Po\303\247o", nullptr));
        lbnTituloIndiceConsistenciaPoco->setText(QCoreApplication::translate("CSimuladorReologico", "Indice de Consistencia (cP eq)", nullptr));
        btnCalcularModeloPotenciaPoco->setText(QCoreApplication::translate("CSimuladorReologico", "Calcular", nullptr));
        lbnVelocidadePocoPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloReynoldsPocoPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "Reynolds no Po\303\247o", nullptr));
        lbnTituloIndiceComportamentoPoco->setText(QCoreApplication::translate("CSimuladorReologico", "Indice de comportamento", nullptr));
        lbnPerdaFriccionalAnularPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloVelocidadeAnularPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "Velocidade do Anular (ft/s)", nullptr));
        lbnReynoldsAnularPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloTipoFluxoAnularPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "Tipo de Fluxo no Anular", nullptr));
        lbnTituloReynoldsAnularPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "Reynolds no Anular", nullptr));
        lbnVelocidadeAnularPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloIndiceConsistenciaAnular->setText(QCoreApplication::translate("CSimuladorReologico", "Indice de Consistencia (cP eq)", nullptr));
        lbnTituloPerdaFriccionalAnularPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "Perda Friccional no Anular (psi/ft)", nullptr));
        btnCalcularModeloPotenciaAnular->setText(QCoreApplication::translate("CSimuladorReologico", "Calcular", nullptr));
        lbnTituloCriticoAnularPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "Reynolds Cr\303\255tico", nullptr));
        lbnTipoFluxoAnularPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnReynoldsCriticoAnularPotencia->setText(QCoreApplication::translate("CSimuladorReologico", "-", nullptr));
        lbnTituloIndiceComportamentoAnular->setText(QCoreApplication::translate("CSimuladorReologico", "Indice de comportamento", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_8), QCoreApplication::translate("CSimuladorReologico", "            Modelo de Pot\303\252ncia           ", nullptr));
        groupBox_4->setTitle(QString());
        label_12->setText(QCoreApplication::translate("CSimuladorReologico", "Fluidos x Profundidade", nullptr));
        label_10->setText(QCoreApplication::translate("CSimuladorReologico", "SEAPEP - Software Educacional para An\303\241lise e Solu\303\247\303\265es de Problemas Em Engenharia de Po\303\247o", nullptr));
        label_11->setText(QCoreApplication::translate("CSimuladorReologico", "Simula\303\247\303\243o de Press\303\243o Hidrost\303\241tica e Perda por Fric\303\247\303\243o", nullptr));
        menuArquivo->setTitle(QCoreApplication::translate("CSimuladorReologico", "Arquivo", nullptr));
        menuImportar_Dados->setTitle(QCoreApplication::translate("CSimuladorReologico", "Importar Dados", nullptr));
        menuAjuda->setTitle(QCoreApplication::translate("CSimuladorReologico", "Refer\303\252ncias", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSimuladorReologico: public Ui_CSimuladorReologico {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSIMULADORREOLOGICO_H
