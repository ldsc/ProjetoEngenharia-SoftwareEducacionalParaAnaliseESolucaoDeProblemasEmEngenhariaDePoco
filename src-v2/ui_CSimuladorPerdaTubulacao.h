/********************************************************************************
** Form generated from reading UI file 'CSimuladorPerdaTubulacao.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSIMULADORPERDATUBULACAO_H
#define UI_CSIMULADORPERDATUBULACAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
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

class Ui_CSimuladorPerdaTubulacao
{
public:
    QAction *actionArquivo_Dat;
    QAction *actionNova_Simula_o;
    QAction *actionExportar_Como_Imagem;
    QAction *actionManual_do_Usu_rio;
    QAction *actionF_rmulas_Utilizadas;
    QAction *actionSobre_o_SEEP;
    QAction *actionSalvar;
    QAction *actionSalvar_como;
    QWidget *centralwidget;
    QCustomPlot *customPlotPoco;
    QGroupBox *groupBox;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *lbnTituloTemperaturaSuperiorInicial;
    QLineEdit *editTemperaturaFundoFinal;
    QLabel *lbnTituloConfiguraoFinal;
    QSpacerItem *verticalSpacer_2;
    QLabel *lbnTituloProfundidadePacker_5;
    QLabel *lbnTituloConfiguraoInicial;
    QLabel *lbnTituloNomePoco;
    QLabel *lbnTituloTemperaturaFundoFinal;
    QLineEdit *editDiametroPoco;
    QLabel *lbnTituloProfunidadeTotal;
    QLineEdit *editPressaoSupInicial;
    QLineEdit *editNomePoco;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *editTemperaturaSuperiorFinal;
    QLineEdit *editProfundidadeTotal;
    QLabel *lbnTituloProfundidadePacker_4;
    QCheckBox *checkBoxPacker;
    QLineEdit *editPressaoSupFinal;
    QLabel *lbnTituloPressaoSup;
    QSpacerItem *verticalSpacer;
    QLineEdit *editTemperaturaFundoInicial;
    QLineEdit *editTemperaturaSuperiorInicial;
    QLabel *lbnTituloTemperaturaFundoInicial;
    QLabel *lbnTituloTemperaturaSuperiorFinal;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnAdicionarTrecho;
    QPushButton *btnRemoverTrecho;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tblFluidos;
    QTableWidget *tblTrechos;
    QLabel *label_6;
    QGroupBox *groupBox_4;
    QLabel *label_4;
    QTabWidget *tabWidget_5;
    QWidget *tab_10;
    QGroupBox *groupBox_2;
    QCustomPlot *customPlotTemperaturaInicial;
    QLabel *label_3;
    QWidget *tab_8;
    QGroupBox *groupBox_5;
    QCustomPlot *customPlotTemperaturaFinal;
    QLabel *label_8;
    QGroupBox *groupBox_6;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QLabel *lbnTituloProfundidadePacker_3;
    QLineEdit *editProfundidadeMedicao;
    QSpacerItem *verticalSpacer_7;
    QLabel *lbnTituloNomePoco_2;
    QLabel *lbnPressaoHidroestatica;
    QLabel *lbnTituloNomePoco_3;
    QLabel *lbnCargaInicial;
    QLabel *lbnTituloNomePoco_11;
    QLabel *lbnCargaInjecaoColunaFixa;
    QLabel *lbnTituloNomePoco_8;
    QLabel *lbnCargaInjecaoColunaLivre;
    QSpacerItem *verticalSpacer_9;
    QLabel *lbnTituloDeltaTemperatura;
    QLabel *lbnTituloDeltaLTemperatura;
    QLabel *lbnTituloNomePoco_5;
    QLabel *lbnTituloDeltaLBalao;
    QLabel *lbnTituloNomePoco_6;
    QLabel *lbnDeltaLPistaoPacker;
    QLabel *lbnTituloNomePoco_7;
    QLabel *lbnDeltaLPistaoCrossover;
    QLabel *lbnTituloNomePoco_10;
    QLabel *lbnDeltaLForcaRestauradora;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCalcularVariacoes;
    QLabel *label_5;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_10;
    QLabel *label_11;
    QMenuBar *menubar;
    QMenu *menuArquivo;
    QMenu *menuImportar_Dados;
    QMenu *menuRefer_ncias;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CSimuladorPerdaTubulacao)
    {
        if (CSimuladorPerdaTubulacao->objectName().isEmpty())
            CSimuladorPerdaTubulacao->setObjectName(QString::fromUtf8("CSimuladorPerdaTubulacao"));
        CSimuladorPerdaTubulacao->setEnabled(true);
        CSimuladorPerdaTubulacao->resize(1449, 859);
        actionArquivo_Dat = new QAction(CSimuladorPerdaTubulacao);
        actionArquivo_Dat->setObjectName(QString::fromUtf8("actionArquivo_Dat"));
        actionNova_Simula_o = new QAction(CSimuladorPerdaTubulacao);
        actionNova_Simula_o->setObjectName(QString::fromUtf8("actionNova_Simula_o"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("document-page-setup")));
        actionNova_Simula_o->setIcon(icon);
        actionExportar_Como_Imagem = new QAction(CSimuladorPerdaTubulacao);
        actionExportar_Como_Imagem->setObjectName(QString::fromUtf8("actionExportar_Como_Imagem"));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("emblem-photos")));
        actionExportar_Como_Imagem->setIcon(icon1);
        actionManual_do_Usu_rio = new QAction(CSimuladorPerdaTubulacao);
        actionManual_do_Usu_rio->setObjectName(QString::fromUtf8("actionManual_do_Usu_rio"));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("dialog-question")));
        actionManual_do_Usu_rio->setIcon(icon2);
        actionF_rmulas_Utilizadas = new QAction(CSimuladorPerdaTubulacao);
        actionF_rmulas_Utilizadas->setObjectName(QString::fromUtf8("actionF_rmulas_Utilizadas"));
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("document-properties")));
        actionF_rmulas_Utilizadas->setIcon(icon3);
        actionSobre_o_SEEP = new QAction(CSimuladorPerdaTubulacao);
        actionSobre_o_SEEP->setObjectName(QString::fromUtf8("actionSobre_o_SEEP"));
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("dialog-information")));
        actionSobre_o_SEEP->setIcon(icon4);
        actionSalvar = new QAction(CSimuladorPerdaTubulacao);
        actionSalvar->setObjectName(QString::fromUtf8("actionSalvar"));
        QIcon icon5(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::DocumentSave")));
        actionSalvar->setIcon(icon5);
        actionSalvar_como = new QAction(CSimuladorPerdaTubulacao);
        actionSalvar_como->setObjectName(QString::fromUtf8("actionSalvar_como"));
        actionSalvar_como->setIcon(icon5);
        centralwidget = new QWidget(CSimuladorPerdaTubulacao);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        customPlotPoco = new QCustomPlot(centralwidget);
        customPlotPoco->setObjectName(QString::fromUtf8("customPlotPoco"));
        customPlotPoco->setGeometry(QRect(1110, 100, 321, 691));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 70, 301, 401));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        groupBox->setTitle(QString::fromUtf8(""));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 201, 16));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label->setFont(font);
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 281, 351));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lbnTituloTemperaturaSuperiorInicial = new QLabel(gridLayoutWidget);
        lbnTituloTemperaturaSuperiorInicial->setObjectName(QString::fromUtf8("lbnTituloTemperaturaSuperiorInicial"));
        QFont font1;
        font1.setBold(false);
        lbnTituloTemperaturaSuperiorInicial->setFont(font1);
        lbnTituloTemperaturaSuperiorInicial->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloTemperaturaSuperiorInicial, 6, 0, 1, 1);

        editTemperaturaFundoFinal = new QLineEdit(gridLayoutWidget);
        editTemperaturaFundoFinal->setObjectName(QString::fromUtf8("editTemperaturaFundoFinal"));
        editTemperaturaFundoFinal->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editTemperaturaFundoFinal, 12, 1, 1, 2);

        lbnTituloConfiguraoFinal = new QLabel(gridLayoutWidget);
        lbnTituloConfiguraoFinal->setObjectName(QString::fromUtf8("lbnTituloConfiguraoFinal"));
        lbnTituloConfiguraoFinal->setFont(font1);
        lbnTituloConfiguraoFinal->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloConfiguraoFinal, 10, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 3);

        lbnTituloProfundidadePacker_5 = new QLabel(gridLayoutWidget);
        lbnTituloProfundidadePacker_5->setObjectName(QString::fromUtf8("lbnTituloProfundidadePacker_5"));
        lbnTituloProfundidadePacker_5->setFont(font1);
        lbnTituloProfundidadePacker_5->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloProfundidadePacker_5, 2, 0, 1, 1);

        lbnTituloConfiguraoInicial = new QLabel(gridLayoutWidget);
        lbnTituloConfiguraoInicial->setObjectName(QString::fromUtf8("lbnTituloConfiguraoInicial"));
        lbnTituloConfiguraoInicial->setFont(font1);
        lbnTituloConfiguraoInicial->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloConfiguraoInicial, 5, 0, 1, 3);

        lbnTituloNomePoco = new QLabel(gridLayoutWidget);
        lbnTituloNomePoco->setObjectName(QString::fromUtf8("lbnTituloNomePoco"));
        lbnTituloNomePoco->setFont(font1);
        lbnTituloNomePoco->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloNomePoco, 0, 0, 1, 1);

        lbnTituloTemperaturaFundoFinal = new QLabel(gridLayoutWidget);
        lbnTituloTemperaturaFundoFinal->setObjectName(QString::fromUtf8("lbnTituloTemperaturaFundoFinal"));
        lbnTituloTemperaturaFundoFinal->setFont(font1);
        lbnTituloTemperaturaFundoFinal->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloTemperaturaFundoFinal, 12, 0, 1, 1);

        editDiametroPoco = new QLineEdit(gridLayoutWidget);
        editDiametroPoco->setObjectName(QString::fromUtf8("editDiametroPoco"));
        editDiametroPoco->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editDiametroPoco, 2, 1, 1, 2);

        lbnTituloProfunidadeTotal = new QLabel(gridLayoutWidget);
        lbnTituloProfunidadeTotal->setObjectName(QString::fromUtf8("lbnTituloProfunidadeTotal"));
        lbnTituloProfunidadeTotal->setFont(font1);
        lbnTituloProfunidadeTotal->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloProfunidadeTotal, 1, 0, 1, 1);

        editPressaoSupInicial = new QLineEdit(gridLayoutWidget);
        editPressaoSupInicial->setObjectName(QString::fromUtf8("editPressaoSupInicial"));
        editPressaoSupInicial->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editPressaoSupInicial, 8, 1, 1, 2);

        editNomePoco = new QLineEdit(gridLayoutWidget);
        editNomePoco->setObjectName(QString::fromUtf8("editNomePoco"));
        editNomePoco->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editNomePoco, 0, 1, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_3, 14, 0, 1, 3);

        editTemperaturaSuperiorFinal = new QLineEdit(gridLayoutWidget);
        editTemperaturaSuperiorFinal->setObjectName(QString::fromUtf8("editTemperaturaSuperiorFinal"));
        editTemperaturaSuperiorFinal->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editTemperaturaSuperiorFinal, 11, 1, 1, 2);

        editProfundidadeTotal = new QLineEdit(gridLayoutWidget);
        editProfundidadeTotal->setObjectName(QString::fromUtf8("editProfundidadeTotal"));
        editProfundidadeTotal->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editProfundidadeTotal, 1, 1, 1, 2);

        lbnTituloProfundidadePacker_4 = new QLabel(gridLayoutWidget);
        lbnTituloProfundidadePacker_4->setObjectName(QString::fromUtf8("lbnTituloProfundidadePacker_4"));
        lbnTituloProfundidadePacker_4->setFont(font1);
        lbnTituloProfundidadePacker_4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloProfundidadePacker_4, 13, 0, 1, 1);

        checkBoxPacker = new QCheckBox(gridLayoutWidget);
        checkBoxPacker->setObjectName(QString::fromUtf8("checkBoxPacker"));
        checkBoxPacker->setFont(font1);
        checkBoxPacker->setChecked(false);

        gridLayout->addWidget(checkBoxPacker, 15, 0, 1, 3);

        editPressaoSupFinal = new QLineEdit(gridLayoutWidget);
        editPressaoSupFinal->setObjectName(QString::fromUtf8("editPressaoSupFinal"));
        editPressaoSupFinal->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editPressaoSupFinal, 13, 1, 1, 2);

        lbnTituloPressaoSup = new QLabel(gridLayoutWidget);
        lbnTituloPressaoSup->setObjectName(QString::fromUtf8("lbnTituloPressaoSup"));
        lbnTituloPressaoSup->setFont(font1);
        lbnTituloPressaoSup->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloPressaoSup, 8, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 9, 0, 1, 3);

        editTemperaturaFundoInicial = new QLineEdit(gridLayoutWidget);
        editTemperaturaFundoInicial->setObjectName(QString::fromUtf8("editTemperaturaFundoInicial"));
        editTemperaturaFundoInicial->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editTemperaturaFundoInicial, 7, 1, 1, 2);

        editTemperaturaSuperiorInicial = new QLineEdit(gridLayoutWidget);
        editTemperaturaSuperiorInicial->setObjectName(QString::fromUtf8("editTemperaturaSuperiorInicial"));
        editTemperaturaSuperiorInicial->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        gridLayout->addWidget(editTemperaturaSuperiorInicial, 6, 1, 1, 2);

        lbnTituloTemperaturaFundoInicial = new QLabel(gridLayoutWidget);
        lbnTituloTemperaturaFundoInicial->setObjectName(QString::fromUtf8("lbnTituloTemperaturaFundoInicial"));
        lbnTituloTemperaturaFundoInicial->setFont(font1);
        lbnTituloTemperaturaFundoInicial->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloTemperaturaFundoInicial, 7, 0, 1, 1);

        lbnTituloTemperaturaSuperiorFinal = new QLabel(gridLayoutWidget);
        lbnTituloTemperaturaSuperiorFinal->setObjectName(QString::fromUtf8("lbnTituloTemperaturaSuperiorFinal"));
        lbnTituloTemperaturaSuperiorFinal->setFont(font1);
        lbnTituloTemperaturaSuperiorFinal->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(lbnTituloTemperaturaSuperiorFinal, 11, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 480, 1081, 321));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 270, 1041, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnAdicionarTrecho = new QPushButton(layoutWidget);
        btnAdicionarTrecho->setObjectName(QString::fromUtf8("btnAdicionarTrecho"));

        horizontalLayout_2->addWidget(btnAdicionarTrecho);

        btnRemoverTrecho = new QPushButton(layoutWidget);
        btnRemoverTrecho->setObjectName(QString::fromUtf8("btnRemoverTrecho"));

        horizontalLayout_2->addWidget(btnRemoverTrecho);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        tblFluidos = new QTableWidget(groupBox_3);
        if (tblFluidos->columnCount() < 3)
            tblFluidos->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tblFluidos->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        tblFluidos->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tblFluidos->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tblFluidos->setObjectName(QString::fromUtf8("tblFluidos"));
        tblFluidos->setGeometry(QRect(600, 50, 461, 211));
        tblFluidos->setStyleSheet(QString::fromUtf8(""));
        tblFluidos->horizontalHeader()->setDefaultSectionSize(153);
        tblTrechos = new QTableWidget(groupBox_3);
        if (tblTrechos->columnCount() < 9)
            tblTrechos->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(6, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(7, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font1);
        tblTrechos->setHorizontalHeaderItem(8, __qtablewidgetitem11);
        tblTrechos->setObjectName(QString::fromUtf8("tblTrechos"));
        tblTrechos->setGeometry(QRect(20, 50, 551, 211));
        tblTrechos->setStyleSheet(QString::fromUtf8(""));
        tblTrechos->setAutoScrollMargin(16);
        tblTrechos->horizontalHeader()->setMinimumSectionSize(37);
        tblTrechos->horizontalHeader()->setDefaultSectionSize(126);
        tblTrechos->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 10, 211, 16));
        label_6->setFont(font);
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(1100, 70, 341, 731));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        groupBox_4->setTitle(QString::fromUtf8(""));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 201, 16));
        label_4->setFont(font);
        tabWidget_5 = new QTabWidget(centralwidget);
        tabWidget_5->setObjectName(QString::fromUtf8("tabWidget_5"));
        tabWidget_5->setGeometry(QRect(690, 70, 401, 401));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        tabWidget_5->setFont(font2);
        tabWidget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #eaeaea;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"}"));
        tabWidget_5->setIconSize(QSize(16, 16));
        tabWidget_5->setElideMode(Qt::TextElideMode::ElideNone);
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        groupBox_2 = new QGroupBox(tab_10);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 10, 381, 351));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        groupBox_2->setTitle(QString::fromUtf8(""));
        customPlotTemperaturaInicial = new QCustomPlot(groupBox_2);
        customPlotTemperaturaInicial->setObjectName(QString::fromUtf8("customPlotTemperaturaInicial"));
        customPlotTemperaturaInicial->setGeometry(QRect(10, 20, 371, 331));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 211, 16));
        label_3->setFont(font);
        tabWidget_5->addTab(tab_10, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        groupBox_5 = new QGroupBox(tab_8);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(0, 0, 381, 361));
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        groupBox_5->setTitle(QString::fromUtf8(""));
        customPlotTemperaturaFinal = new QCustomPlot(groupBox_5);
        customPlotTemperaturaFinal->setObjectName(QString::fromUtf8("customPlotTemperaturaFinal"));
        customPlotTemperaturaFinal->setGeometry(QRect(10, 30, 371, 331));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 10, 211, 16));
        label_8->setFont(font);
        tabWidget_5->addTab(tab_8, QString());
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(320, 70, 361, 401));
        groupBox_6->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        groupBox_6->setTitle(QString::fromUtf8(""));
        layoutWidget1 = new QWidget(groupBox_6);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 40, 341, 342));
        formLayout = new QFormLayout(layoutWidget1);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        lbnTituloProfundidadePacker_3 = new QLabel(layoutWidget1);
        lbnTituloProfundidadePacker_3->setObjectName(QString::fromUtf8("lbnTituloProfundidadePacker_3"));
        lbnTituloProfundidadePacker_3->setFont(font1);
        lbnTituloProfundidadePacker_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, lbnTituloProfundidadePacker_3);

        editProfundidadeMedicao = new QLineEdit(layoutWidget1);
        editProfundidadeMedicao->setObjectName(QString::fromUtf8("editProfundidadeMedicao"));
        editProfundidadeMedicao->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd; \n"
"border-radius: 5px;"));

        formLayout->setWidget(0, QFormLayout::FieldRole, editProfundidadeMedicao);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(2, QFormLayout::SpanningRole, verticalSpacer_7);

        lbnTituloNomePoco_2 = new QLabel(layoutWidget1);
        lbnTituloNomePoco_2->setObjectName(QString::fromUtf8("lbnTituloNomePoco_2"));
        lbnTituloNomePoco_2->setFont(font1);
        lbnTituloNomePoco_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, lbnTituloNomePoco_2);

        lbnPressaoHidroestatica = new QLabel(layoutWidget1);
        lbnPressaoHidroestatica->setObjectName(QString::fromUtf8("lbnPressaoHidroestatica"));
        lbnPressaoHidroestatica->setFont(font1);
        lbnPressaoHidroestatica->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(3, QFormLayout::FieldRole, lbnPressaoHidroestatica);

        lbnTituloNomePoco_3 = new QLabel(layoutWidget1);
        lbnTituloNomePoco_3->setObjectName(QString::fromUtf8("lbnTituloNomePoco_3"));
        lbnTituloNomePoco_3->setFont(font1);
        lbnTituloNomePoco_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(4, QFormLayout::LabelRole, lbnTituloNomePoco_3);

        lbnCargaInicial = new QLabel(layoutWidget1);
        lbnCargaInicial->setObjectName(QString::fromUtf8("lbnCargaInicial"));
        lbnCargaInicial->setFont(font1);
        lbnCargaInicial->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(4, QFormLayout::FieldRole, lbnCargaInicial);

        lbnTituloNomePoco_11 = new QLabel(layoutWidget1);
        lbnTituloNomePoco_11->setObjectName(QString::fromUtf8("lbnTituloNomePoco_11"));
        lbnTituloNomePoco_11->setFont(font1);
        lbnTituloNomePoco_11->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(5, QFormLayout::LabelRole, lbnTituloNomePoco_11);

        lbnCargaInjecaoColunaFixa = new QLabel(layoutWidget1);
        lbnCargaInjecaoColunaFixa->setObjectName(QString::fromUtf8("lbnCargaInjecaoColunaFixa"));
        lbnCargaInjecaoColunaFixa->setFont(font1);
        lbnCargaInjecaoColunaFixa->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(5, QFormLayout::FieldRole, lbnCargaInjecaoColunaFixa);

        lbnTituloNomePoco_8 = new QLabel(layoutWidget1);
        lbnTituloNomePoco_8->setObjectName(QString::fromUtf8("lbnTituloNomePoco_8"));
        lbnTituloNomePoco_8->setFont(font1);
        lbnTituloNomePoco_8->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(6, QFormLayout::LabelRole, lbnTituloNomePoco_8);

        lbnCargaInjecaoColunaLivre = new QLabel(layoutWidget1);
        lbnCargaInjecaoColunaLivre->setObjectName(QString::fromUtf8("lbnCargaInjecaoColunaLivre"));
        lbnCargaInjecaoColunaLivre->setFont(font1);
        lbnCargaInjecaoColunaLivre->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(6, QFormLayout::FieldRole, lbnCargaInjecaoColunaLivre);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(8, QFormLayout::SpanningRole, verticalSpacer_9);

        lbnTituloDeltaTemperatura = new QLabel(layoutWidget1);
        lbnTituloDeltaTemperatura->setObjectName(QString::fromUtf8("lbnTituloDeltaTemperatura"));
        lbnTituloDeltaTemperatura->setFont(font1);
        lbnTituloDeltaTemperatura->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(9, QFormLayout::LabelRole, lbnTituloDeltaTemperatura);

        lbnTituloDeltaLTemperatura = new QLabel(layoutWidget1);
        lbnTituloDeltaLTemperatura->setObjectName(QString::fromUtf8("lbnTituloDeltaLTemperatura"));
        lbnTituloDeltaLTemperatura->setFont(font1);
        lbnTituloDeltaLTemperatura->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(9, QFormLayout::FieldRole, lbnTituloDeltaLTemperatura);

        lbnTituloNomePoco_5 = new QLabel(layoutWidget1);
        lbnTituloNomePoco_5->setObjectName(QString::fromUtf8("lbnTituloNomePoco_5"));
        lbnTituloNomePoco_5->setFont(font1);
        lbnTituloNomePoco_5->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(10, QFormLayout::LabelRole, lbnTituloNomePoco_5);

        lbnTituloDeltaLBalao = new QLabel(layoutWidget1);
        lbnTituloDeltaLBalao->setObjectName(QString::fromUtf8("lbnTituloDeltaLBalao"));
        lbnTituloDeltaLBalao->setFont(font1);
        lbnTituloDeltaLBalao->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(10, QFormLayout::FieldRole, lbnTituloDeltaLBalao);

        lbnTituloNomePoco_6 = new QLabel(layoutWidget1);
        lbnTituloNomePoco_6->setObjectName(QString::fromUtf8("lbnTituloNomePoco_6"));
        lbnTituloNomePoco_6->setFont(font1);
        lbnTituloNomePoco_6->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(11, QFormLayout::LabelRole, lbnTituloNomePoco_6);

        lbnDeltaLPistaoPacker = new QLabel(layoutWidget1);
        lbnDeltaLPistaoPacker->setObjectName(QString::fromUtf8("lbnDeltaLPistaoPacker"));
        lbnDeltaLPistaoPacker->setFont(font1);
        lbnDeltaLPistaoPacker->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(11, QFormLayout::FieldRole, lbnDeltaLPistaoPacker);

        lbnTituloNomePoco_7 = new QLabel(layoutWidget1);
        lbnTituloNomePoco_7->setObjectName(QString::fromUtf8("lbnTituloNomePoco_7"));
        lbnTituloNomePoco_7->setFont(font1);
        lbnTituloNomePoco_7->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(12, QFormLayout::LabelRole, lbnTituloNomePoco_7);

        lbnDeltaLPistaoCrossover = new QLabel(layoutWidget1);
        lbnDeltaLPistaoCrossover->setObjectName(QString::fromUtf8("lbnDeltaLPistaoCrossover"));
        lbnDeltaLPistaoCrossover->setFont(font1);
        lbnDeltaLPistaoCrossover->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(12, QFormLayout::FieldRole, lbnDeltaLPistaoCrossover);

        lbnTituloNomePoco_10 = new QLabel(layoutWidget1);
        lbnTituloNomePoco_10->setObjectName(QString::fromUtf8("lbnTituloNomePoco_10"));
        lbnTituloNomePoco_10->setFont(font1);
        lbnTituloNomePoco_10->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(13, QFormLayout::LabelRole, lbnTituloNomePoco_10);

        lbnDeltaLForcaRestauradora = new QLabel(layoutWidget1);
        lbnDeltaLForcaRestauradora->setObjectName(QString::fromUtf8("lbnDeltaLForcaRestauradora"));
        lbnDeltaLForcaRestauradora->setFont(font1);
        lbnDeltaLForcaRestauradora->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(13, QFormLayout::FieldRole, lbnDeltaLForcaRestauradora);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(14, QFormLayout::SpanningRole, verticalSpacer_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnCalcularVariacoes = new QPushButton(layoutWidget1);
        btnCalcularVariacoes->setObjectName(QString::fromUtf8("btnCalcularVariacoes"));

        horizontalLayout->addWidget(btnCalcularVariacoes);


        formLayout->setLayout(15, QFormLayout::SpanningRole, horizontalLayout);

        label_5 = new QLabel(groupBox_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 291, 16));
        label_5->setFont(font);
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(330, 0, 996, 64));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        label_10->setFont(font3);
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_10);

        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(false);
        label_11->setFont(font4);
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_11);

        label_11->raise();
        label_10->raise();
        CSimuladorPerdaTubulacao->setCentralWidget(centralwidget);
        groupBox_3->raise();
        groupBox_4->raise();
        customPlotPoco->raise();
        groupBox->raise();
        tabWidget_5->raise();
        groupBox_6->raise();
        layoutWidget_2->raise();
        menubar = new QMenuBar(CSimuladorPerdaTubulacao);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1449, 26));
        menuArquivo = new QMenu(menubar);
        menuArquivo->setObjectName(QString::fromUtf8("menuArquivo"));
        menuImportar_Dados = new QMenu(menuArquivo);
        menuImportar_Dados->setObjectName(QString::fromUtf8("menuImportar_Dados"));
        menuRefer_ncias = new QMenu(menubar);
        menuRefer_ncias->setObjectName(QString::fromUtf8("menuRefer_ncias"));
        CSimuladorPerdaTubulacao->setMenuBar(menubar);
        statusbar = new QStatusBar(CSimuladorPerdaTubulacao);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CSimuladorPerdaTubulacao->setStatusBar(statusbar);
        QWidget::setTabOrder(editNomePoco, editProfundidadeTotal);
        QWidget::setTabOrder(editProfundidadeTotal, editDiametroPoco);
        QWidget::setTabOrder(editDiametroPoco, editTemperaturaSuperiorInicial);
        QWidget::setTabOrder(editTemperaturaSuperiorInicial, editTemperaturaFundoInicial);
        QWidget::setTabOrder(editTemperaturaFundoInicial, editPressaoSupInicial);
        QWidget::setTabOrder(editPressaoSupInicial, editTemperaturaSuperiorFinal);
        QWidget::setTabOrder(editTemperaturaSuperiorFinal, editTemperaturaFundoFinal);
        QWidget::setTabOrder(editTemperaturaFundoFinal, editPressaoSupFinal);
        QWidget::setTabOrder(editPressaoSupFinal, checkBoxPacker);
        QWidget::setTabOrder(checkBoxPacker, editProfundidadeMedicao);
        QWidget::setTabOrder(editProfundidadeMedicao, btnCalcularVariacoes);
        QWidget::setTabOrder(btnCalcularVariacoes, tblTrechos);
        QWidget::setTabOrder(tblTrechos, btnAdicionarTrecho);
        QWidget::setTabOrder(btnAdicionarTrecho, btnRemoverTrecho);
        QWidget::setTabOrder(btnRemoverTrecho, tblFluidos);
        QWidget::setTabOrder(tblFluidos, tabWidget_5);

        menubar->addAction(menuArquivo->menuAction());
        menubar->addAction(menuRefer_ncias->menuAction());
        menuArquivo->addAction(actionNova_Simula_o);
        menuArquivo->addAction(actionSalvar);
        menuArquivo->addAction(actionSalvar_como);
        menuArquivo->addSeparator();
        menuArquivo->addAction(menuImportar_Dados->menuAction());
        menuArquivo->addAction(actionExportar_Como_Imagem);
        menuImportar_Dados->addAction(actionArquivo_Dat);
        menuRefer_ncias->addAction(actionManual_do_Usu_rio);
        menuRefer_ncias->addAction(actionF_rmulas_Utilizadas);
        menuRefer_ncias->addAction(actionSobre_o_SEEP);

        retranslateUi(CSimuladorPerdaTubulacao);

        tabWidget_5->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CSimuladorPerdaTubulacao);
    } // setupUi

    void retranslateUi(QMainWindow *CSimuladorPerdaTubulacao)
    {
        CSimuladorPerdaTubulacao->setWindowTitle(QCoreApplication::translate("CSimuladorPerdaTubulacao", "MainWindow", nullptr));
        actionArquivo_Dat->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Arquivo (.Dat)", nullptr));
        actionNova_Simula_o->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Nova Simula\303\247\303\243o", nullptr));
#if QT_CONFIG(shortcut)
        actionNova_Simula_o->setShortcut(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExportar_Como_Imagem->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Exportar Como Imagem", nullptr));
        actionManual_do_Usu_rio->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Manual do Usu\303\241rio", nullptr));
#if QT_CONFIG(shortcut)
        actionManual_do_Usu_rio->setShortcut(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionF_rmulas_Utilizadas->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "F\303\263rmulas Utilizadas", nullptr));
        actionSobre_o_SEEP->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Sobre o SEEP", nullptr));
        actionSalvar->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Salvar", nullptr));
#if QT_CONFIG(shortcut)
        actionSalvar->setShortcut(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSalvar_como->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Salvar como...", nullptr));
#if QT_CONFIG(shortcut)
        actionSalvar_como->setShortcut(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Dados do Po\303\247o", nullptr));
        lbnTituloTemperaturaSuperiorInicial->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Temperatura de Superfice (\302\272F)", nullptr));
        lbnTituloConfiguraoFinal->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Configura\303\247\303\243o Final", nullptr));
        lbnTituloProfundidadePacker_5->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Diametro Poco (in)", nullptr));
        lbnTituloConfiguraoInicial->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Configura\303\247\303\243o Inicial", nullptr));
        lbnTituloNomePoco->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Nome Po\303\247o", nullptr));
        lbnTituloTemperaturaFundoFinal->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Temperatura de Fundo (\302\272F)", nullptr));
        lbnTituloProfunidadeTotal->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Profundidade Total (ft)", nullptr));
        lbnTituloProfundidadePacker_4->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Press\303\243o na Cabe\303\247a Po\303\247o (psi)", nullptr));
        checkBoxPacker->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "H\303\241 packer?", nullptr));
        lbnTituloPressaoSup->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Press\303\243o na Cabe\303\247a Po\303\247o (psi)", nullptr));
        lbnTituloTemperaturaFundoInicial->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Temperatura de Fundo (\302\272F)", nullptr));
        lbnTituloTemperaturaSuperiorFinal->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Temperatura de Superfice (\302\272F)", nullptr));
        groupBox_3->setTitle(QString());
        btnAdicionarTrecho->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Adicionar Dados", nullptr));
        btnRemoverTrecho->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Remover Dados", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblFluidos->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Nome", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblFluidos->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Densidade (lbm/gal)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblFluidos->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Viscosidade (cP)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblTrechos->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Trecho", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblTrechos->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Prof. Inicial (ft)", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblTrechos->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Prof. Final (ft)", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblTrechos->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Diam. Externo (in)", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblTrechos->horizontalHeaderItem(4);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Diam Interno (in)", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblTrechos->horizontalHeaderItem(5);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Coef. Poisson", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblTrechos->horizontalHeaderItem(6);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Coef. Exp. T\303\251rm. (1/F)", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblTrechos->horizontalHeaderItem(7);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "M\303\263d. Elast. (psi)", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblTrechos->horizontalHeaderItem(8);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Peso/unid. (lb/ft)", nullptr));
        label_6->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Dados de Trecho e Fluido", nullptr));
        label_4->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Esquema do Po\303\247o", nullptr));
        label_3->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Profundidade x Temperatura", nullptr));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_10), QCoreApplication::translate("CSimuladorPerdaTubulacao", "           Condi\303\247\303\265es Iniciais           ", nullptr));
        label_8->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Profundidade x Temperatura", nullptr));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_8), QCoreApplication::translate("CSimuladorPerdaTubulacao", "           Condi\303\247\303\265es Finais           ", nullptr));
        lbnTituloProfundidadePacker_3->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Profundidade para medi\303\247\303\243o (ft):", nullptr));
        lbnTituloNomePoco_2->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Press\303\243o inicial, psi:", nullptr));
        lbnPressaoHidroestatica->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "-", nullptr));
        lbnTituloNomePoco_3->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Carga (condi\303\247\303\243o inicial), lb:", nullptr));
        lbnCargaInicial->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "-", nullptr));
        lbnTituloNomePoco_11->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Carga considerando inje\303\247\303\243o (coluna fixa), lb", nullptr));
        lbnCargaInjecaoColunaFixa->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "-", nullptr));
        lbnTituloNomePoco_8->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Carga considerando inje\303\247\303\243o (coluna livre), lb", nullptr));
        lbnCargaInjecaoColunaLivre->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "-", nullptr));
        lbnTituloDeltaTemperatura->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "\316\224L (temperatura), ft:", nullptr));
        lbnTituloDeltaLTemperatura->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "-", nullptr));
        lbnTituloNomePoco_5->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "\316\224L (efeito bal\303\243o), ft", nullptr));
        lbnTituloDeltaLBalao->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "-", nullptr));
        lbnTituloNomePoco_6->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "\316\224L (For\303\247a pist\303\243o devido ao packer), ft", nullptr));
        lbnDeltaLPistaoPacker->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "-", nullptr));
        lbnTituloNomePoco_7->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "\316\224L (For\303\247a pist\303\243o devido ao crossover), ft", nullptr));
        lbnDeltaLPistaoCrossover->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "-", nullptr));
        lbnTituloNomePoco_10->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "\316\224L (devido for\303\247a restauradora), ft", nullptr));
        lbnDeltaLForcaRestauradora->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "-", nullptr));
        btnCalcularVariacoes->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Calcular", nullptr));
        label_5->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Carga e Varia\303\247\303\265es de comprimentos", nullptr));
        label_10->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "SEAPEP - Software Educacional para An\303\241lise e Solu\303\247\303\265es de Problemas Em Engenharia de Po\303\247o", nullptr));
        label_11->setText(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Simula\303\247\303\243o de An\303\241lise de tens\303\265es na coluna", nullptr));
        menuArquivo->setTitle(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Arquivo", nullptr));
        menuImportar_Dados->setTitle(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Importar Dados", nullptr));
        menuRefer_ncias->setTitle(QCoreApplication::translate("CSimuladorPerdaTubulacao", "Refer\303\252ncias", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSimuladorPerdaTubulacao: public Ui_CSimuladorPerdaTubulacao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSIMULADORPERDATUBULACAO_H
