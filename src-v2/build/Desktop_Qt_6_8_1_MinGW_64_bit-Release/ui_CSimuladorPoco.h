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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

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
    QMenuBar *menubar;
    QMenu *menuArquivo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CSimuladorPoco)
    {
        if (CSimuladorPoco->objectName().isEmpty())
            CSimuladorPoco->setObjectName("CSimuladorPoco");
        CSimuladorPoco->resize(1052, 402);
        actionImportar_Dados = new QAction(CSimuladorPoco);
        actionImportar_Dados->setObjectName("actionImportar_Dados");
        centralwidget = new QWidget(CSimuladorPoco);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 30, 371, 311));
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
        gridLayoutWidget_2->setGeometry(QRect(420, 30, 601, 311));
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

        CSimuladorPoco->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CSimuladorPoco);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1052, 22));
        menuArquivo = new QMenu(menubar);
        menuArquivo->setObjectName("menuArquivo");
        CSimuladorPoco->setMenuBar(menubar);
        statusbar = new QStatusBar(CSimuladorPoco);
        statusbar->setObjectName("statusbar");
        CSimuladorPoco->setStatusBar(statusbar);

        menubar->addAction(menuArquivo->menuAction());
        menuArquivo->addAction(actionImportar_Dados);

        retranslateUi(CSimuladorPoco);

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
        menuArquivo->setTitle(QCoreApplication::translate("CSimuladorPoco", "Arquivo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSimuladorPoco: public Ui_CSimuladorPoco {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSIMULADORPOCO_H
