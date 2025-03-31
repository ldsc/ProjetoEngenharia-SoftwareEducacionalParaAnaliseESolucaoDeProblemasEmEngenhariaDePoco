/********************************************************************************
** Form generated from reading UI file 'CSimuladorPocoTubos.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSIMULADORPOCOTUBOS_H
#define UI_CSIMULADORPOCOTUBOS_H

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

class Ui_CSimuladorPocoTubos
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
    QPushButton *btnAdicionarFluido_2;
    QPushButton *btnRemoverFluido_2;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tblFluidos_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *lbnTituloDiametroPoco;
    QLabel *lbnTituloPressaoSuperficie;
    QLabel *lbnTituloDiametroOD_2;
    QLabel *lbnTituloDiametroID;
    QPushButton *btnAdicionarPropriedades;
    QLabel *lbnTituloProfunidadeTotal;
    QLabel *lbnTituloVazao;
    QLineEdit *editProfundidadeTotal;
    QLineEdit *editDiametroOD;
    QCheckBox *checkBox;
    QLineEdit *editVazao;
    QLineEdit *editDiametroOD_2;
    QLineEdit *editNomePoco;
    QSpacerItem *verticalSpacer;
    QPushButton *btnAtualizarDados;
    QLabel *lbnTituloNomePoco;
    QLabel *lbnTituloDiametroOD;
    QLineEdit *editDiametroPoco;
    QLabel *lbnTituloDiametroOD_3;
    QLineEdit *editDiametroOD_3;

    void setupUi(QDialog *CSimuladorPocoTubos)
    {
        if (CSimuladorPocoTubos->objectName().isEmpty())
            CSimuladorPocoTubos->setObjectName("CSimuladorPocoTubos");
        CSimuladorPocoTubos->resize(1756, 1047);
        customPlotPoco = new QCustomPlot(CSimuladorPocoTubos);
        customPlotPoco->setObjectName("customPlotPoco");
        customPlotPoco->setGeometry(QRect(1440, 10, 301, 631));
        gridLayoutWidget_2 = new QWidget(CSimuladorPocoTubos);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(390, 10, 811, 321));
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
        tblFluidos->horizontalHeader()->setDefaultSectionSize(120);

        gridLayout_2->addWidget(tblFluidos, 0, 0, 1, 3);

        gridLayoutWidget_3 = new QWidget(CSimuladorPocoTubos);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(10, 350, 1191, 311));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        btnAdicionarFluido_2 = new QPushButton(gridLayoutWidget_3);
        btnAdicionarFluido_2->setObjectName("btnAdicionarFluido_2");

        gridLayout_3->addWidget(btnAdicionarFluido_2, 1, 0, 1, 1);

        btnRemoverFluido_2 = new QPushButton(gridLayoutWidget_3);
        btnRemoverFluido_2->setObjectName("btnRemoverFluido_2");

        gridLayout_3->addWidget(btnRemoverFluido_2, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        tblFluidos_2 = new QTableWidget(gridLayoutWidget_3);
        if (tblFluidos_2->columnCount() < 9)
            tblFluidos_2->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tblFluidos_2->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tblFluidos_2->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        tblFluidos_2->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        tblFluidos_2->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font);
        tblFluidos_2->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        tblFluidos_2->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font);
        tblFluidos_2->setHorizontalHeaderItem(6, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font);
        tblFluidos_2->setHorizontalHeaderItem(7, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font);
        tblFluidos_2->setHorizontalHeaderItem(8, __qtablewidgetitem13);
        tblFluidos_2->setObjectName("tblFluidos_2");
        tblFluidos_2->setAutoScrollMargin(19);
        tblFluidos_2->horizontalHeader()->setMinimumSectionSize(37);
        tblFluidos_2->horizontalHeader()->setDefaultSectionSize(131);
        tblFluidos_2->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));

        gridLayout_3->addWidget(tblFluidos_2, 0, 0, 1, 3);

        gridLayoutWidget = new QWidget(CSimuladorPocoTubos);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 371, 323));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 10, 0, 1, 2);

        lbnTituloDiametroPoco = new QLabel(gridLayoutWidget);
        lbnTituloDiametroPoco->setObjectName("lbnTituloDiametroPoco");
        lbnTituloDiametroPoco->setFont(font);
        lbnTituloDiametroPoco->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloDiametroPoco, 4, 0, 1, 1);

        lbnTituloPressaoSuperficie = new QLabel(gridLayoutWidget);
        lbnTituloPressaoSuperficie->setObjectName("lbnTituloPressaoSuperficie");
        lbnTituloPressaoSuperficie->setFont(font);
        lbnTituloPressaoSuperficie->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloPressaoSuperficie, 3, 0, 1, 3);

        lbnTituloDiametroOD_2 = new QLabel(gridLayoutWidget);
        lbnTituloDiametroOD_2->setObjectName("lbnTituloDiametroOD_2");
        lbnTituloDiametroOD_2->setFont(font);
        lbnTituloDiametroOD_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloDiametroOD_2, 9, 0, 1, 1);

        lbnTituloDiametroID = new QLabel(gridLayoutWidget);
        lbnTituloDiametroID->setObjectName("lbnTituloDiametroID");
        lbnTituloDiametroID->setFont(font);
        lbnTituloDiametroID->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloDiametroID, 7, 0, 1, 3);

        btnAdicionarPropriedades = new QPushButton(gridLayoutWidget);
        btnAdicionarPropriedades->setObjectName("btnAdicionarPropriedades");

        gridLayout->addWidget(btnAdicionarPropriedades, 13, 0, 1, 1);

        lbnTituloProfunidadeTotal = new QLabel(gridLayoutWidget);
        lbnTituloProfunidadeTotal->setObjectName("lbnTituloProfunidadeTotal");
        lbnTituloProfunidadeTotal->setFont(font);
        lbnTituloProfunidadeTotal->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloProfunidadeTotal, 1, 0, 1, 1);

        lbnTituloVazao = new QLabel(gridLayoutWidget);
        lbnTituloVazao->setObjectName("lbnTituloVazao");
        lbnTituloVazao->setFont(font);
        lbnTituloVazao->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloVazao, 8, 0, 1, 1);

        editProfundidadeTotal = new QLineEdit(gridLayoutWidget);
        editProfundidadeTotal->setObjectName("editProfundidadeTotal");

        gridLayout->addWidget(editProfundidadeTotal, 1, 1, 1, 2);

        editDiametroOD = new QLineEdit(gridLayoutWidget);
        editDiametroOD->setObjectName("editDiametroOD");

        gridLayout->addWidget(editDiametroOD, 5, 1, 1, 2);

        checkBox = new QCheckBox(gridLayoutWidget);
        checkBox->setObjectName("checkBox");
        checkBox->setFont(font);

        gridLayout->addWidget(checkBox, 11, 0, 1, 2);

        editVazao = new QLineEdit(gridLayoutWidget);
        editVazao->setObjectName("editVazao");

        gridLayout->addWidget(editVazao, 8, 1, 1, 2);

        editDiametroOD_2 = new QLineEdit(gridLayoutWidget);
        editDiametroOD_2->setObjectName("editDiametroOD_2");

        gridLayout->addWidget(editDiametroOD_2, 9, 1, 1, 1);

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

        lbnTituloDiametroOD = new QLabel(gridLayoutWidget);
        lbnTituloDiametroOD->setObjectName("lbnTituloDiametroOD");
        lbnTituloDiametroOD->setFont(font);
        lbnTituloDiametroOD->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloDiametroOD, 5, 0, 1, 1);

        editDiametroPoco = new QLineEdit(gridLayoutWidget);
        editDiametroPoco->setObjectName("editDiametroPoco");

        gridLayout->addWidget(editDiametroPoco, 4, 1, 1, 2);

        lbnTituloDiametroOD_3 = new QLabel(gridLayoutWidget);
        lbnTituloDiametroOD_3->setObjectName("lbnTituloDiametroOD_3");
        lbnTituloDiametroOD_3->setFont(font);
        lbnTituloDiametroOD_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lbnTituloDiametroOD_3, 12, 0, 1, 1);

        editDiametroOD_3 = new QLineEdit(gridLayoutWidget);
        editDiametroOD_3->setObjectName("editDiametroOD_3");

        gridLayout->addWidget(editDiametroOD_3, 12, 1, 1, 1);


        retranslateUi(CSimuladorPocoTubos);

        QMetaObject::connectSlotsByName(CSimuladorPocoTubos);
    } // setupUi

    void retranslateUi(QDialog *CSimuladorPocoTubos)
    {
        CSimuladorPocoTubos->setWindowTitle(QCoreApplication::translate("CSimuladorPocoTubos", "Dialog", nullptr));
        btnAdicionarFluido->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Adicionar Fluido", nullptr));
        btnRemoverFluido->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Remover Fluido", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblFluidos->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Nome", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblFluidos->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Densidade (lbm/gal)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblFluidos->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Viscosidade (cP)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblFluidos->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Prof. Inicial (ft)", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblFluidos->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Prof. Final (ft)", nullptr));
        btnAdicionarFluido_2->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Adicionar Trecho", nullptr));
        btnRemoverFluido_2->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Remover Trecho", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblFluidos_2->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Trecho", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblFluidos_2->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Prof. Inicial (ft)", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblFluidos_2->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Prof. Final (ft)", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblFluidos_2->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("CSimuladorPocoTubos", "ID - Di\303\242metro Externo (in)", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblFluidos_2->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("CSimuladorPocoTubos", "OD - Di\303\242metro Interno (in)", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblFluidos_2->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Coef. Poisson", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblFluidos_2->horizontalHeaderItem(6);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Coef. de Expan\303\247\303\243o t\303\251rmica (F^-1)", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblFluidos_2->horizontalHeaderItem(7);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("CSimuladorPocoTubos", "M\303\263d. Elasticidade (psi)", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblFluidos_2->horizontalHeaderItem(8);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Peso p/ Unidade (lb/ft)", nullptr));
        lbnTituloDiametroPoco->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Temperatura de Superfice (\302\272F)", nullptr));
        lbnTituloPressaoSuperficie->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Configura\303\247\303\243o Inicial", nullptr));
        lbnTituloDiametroOD_2->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Temperatura de Fundo (\302\272F)", nullptr));
        lbnTituloDiametroID->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Configura\303\247\303\243o Final", nullptr));
        btnAdicionarPropriedades->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Adicionar Propriedade", nullptr));
        lbnTituloProfunidadeTotal->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Profundidade Total (ft)", nullptr));
        lbnTituloVazao->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Temperatura de Superfice (\302\272F)", nullptr));
        checkBox->setText(QCoreApplication::translate("CSimuladorPocoTubos", "H\303\241 packer?", nullptr));
        btnAtualizarDados->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Atualizar Dados", nullptr));
        lbnTituloNomePoco->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Nome Po\303\247o", nullptr));
        lbnTituloDiametroOD->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Temperatura de Fundo (\302\272F)", nullptr));
        lbnTituloDiametroOD_3->setText(QCoreApplication::translate("CSimuladorPocoTubos", "Profundidade do Packer (ft)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSimuladorPocoTubos: public Ui_CSimuladorPocoTubos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSIMULADORPOCOTUBOS_H
