/********************************************************************************
** Form generated from reading UI file 'CJanelaAdicionarTrechoTubulacao.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CJANELAADICIONARTRECHOTUBULACAO_H
#define UI_CJANELAADICIONARTRECHOTUBULACAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CJanelaAdicionarTrechoTubulacao
{
public:
    QGroupBox *groupBox_6;
    QLabel *label_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lbnTituloTrecho;
    QLabel *lbnTituloProfInicial;
    QLabel *lbnTituloProfFinal;
    QLabel *lbnTituloDiametroExterno;
    QLabel *lbnTituloDiametroInterno;
    QLabel *lbnTituloCoefPoisson;
    QLabel *lbnTituloCoefExpancao;
    QLabel *lbnTituloModElasticidade;
    QLabel *lbnTituloPesoUnidade;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *editTrecho;
    QLineEdit *editProfInicial;
    QLineEdit *editProfFinal;
    QLineEdit *editDiametroExterno;
    QLineEdit *editDiametroInterno;
    QLineEdit *editCoefPoisson;
    QLineEdit *editCoefExpansao;
    QLineEdit *editModuloElasticidade;
    QLineEdit *editPesoUnid;
    QDialogButtonBox *btnReturn;
    QGroupBox *groupBox_7;
    QLabel *label_9;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_9;
    QLabel *lbnTituloNome;
    QLabel *lbnTituloDensidade;
    QLabel *lbnTituloViscosidade;
    QVBoxLayout *verticalLayout_10;
    QLineEdit *editNome;
    QLineEdit *editDensidade;
    QLineEdit *editViscosidade;

    void setupUi(QDialog *CJanelaAdicionarTrechoTubulacao)
    {
        if (CJanelaAdicionarTrechoTubulacao->objectName().isEmpty())
            CJanelaAdicionarTrechoTubulacao->setObjectName(QString::fromUtf8("CJanelaAdicionarTrechoTubulacao"));
        CJanelaAdicionarTrechoTubulacao->resize(476, 333);
        groupBox_6 = new QGroupBox(CJanelaAdicionarTrechoTubulacao);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 10, 251, 311));
        groupBox_6->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        groupBox_6->setTitle(QString::fromUtf8(""));
        label_5 = new QLabel(groupBox_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 231, 16));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label_5->setFont(font);
        widget = new QWidget(groupBox_6);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 30, 229, 262));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbnTituloTrecho = new QLabel(widget);
        lbnTituloTrecho->setObjectName(QString::fromUtf8("lbnTituloTrecho"));

        verticalLayout->addWidget(lbnTituloTrecho);

        lbnTituloProfInicial = new QLabel(widget);
        lbnTituloProfInicial->setObjectName(QString::fromUtf8("lbnTituloProfInicial"));

        verticalLayout->addWidget(lbnTituloProfInicial);

        lbnTituloProfFinal = new QLabel(widget);
        lbnTituloProfFinal->setObjectName(QString::fromUtf8("lbnTituloProfFinal"));

        verticalLayout->addWidget(lbnTituloProfFinal);

        lbnTituloDiametroExterno = new QLabel(widget);
        lbnTituloDiametroExterno->setObjectName(QString::fromUtf8("lbnTituloDiametroExterno"));

        verticalLayout->addWidget(lbnTituloDiametroExterno);

        lbnTituloDiametroInterno = new QLabel(widget);
        lbnTituloDiametroInterno->setObjectName(QString::fromUtf8("lbnTituloDiametroInterno"));

        verticalLayout->addWidget(lbnTituloDiametroInterno);

        lbnTituloCoefPoisson = new QLabel(widget);
        lbnTituloCoefPoisson->setObjectName(QString::fromUtf8("lbnTituloCoefPoisson"));

        verticalLayout->addWidget(lbnTituloCoefPoisson);

        lbnTituloCoefExpancao = new QLabel(widget);
        lbnTituloCoefExpancao->setObjectName(QString::fromUtf8("lbnTituloCoefExpancao"));

        verticalLayout->addWidget(lbnTituloCoefExpancao);

        lbnTituloModElasticidade = new QLabel(widget);
        lbnTituloModElasticidade->setObjectName(QString::fromUtf8("lbnTituloModElasticidade"));

        verticalLayout->addWidget(lbnTituloModElasticidade);

        lbnTituloPesoUnidade = new QLabel(widget);
        lbnTituloPesoUnidade->setObjectName(QString::fromUtf8("lbnTituloPesoUnidade"));

        verticalLayout->addWidget(lbnTituloPesoUnidade);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        editTrecho = new QLineEdit(widget);
        editTrecho->setObjectName(QString::fromUtf8("editTrecho"));
        editTrecho->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editTrecho);

        editProfInicial = new QLineEdit(widget);
        editProfInicial->setObjectName(QString::fromUtf8("editProfInicial"));
        editProfInicial->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editProfInicial);

        editProfFinal = new QLineEdit(widget);
        editProfFinal->setObjectName(QString::fromUtf8("editProfFinal"));
        editProfFinal->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editProfFinal);

        editDiametroExterno = new QLineEdit(widget);
        editDiametroExterno->setObjectName(QString::fromUtf8("editDiametroExterno"));
        editDiametroExterno->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editDiametroExterno);

        editDiametroInterno = new QLineEdit(widget);
        editDiametroInterno->setObjectName(QString::fromUtf8("editDiametroInterno"));
        editDiametroInterno->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editDiametroInterno);

        editCoefPoisson = new QLineEdit(widget);
        editCoefPoisson->setObjectName(QString::fromUtf8("editCoefPoisson"));
        editCoefPoisson->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editCoefPoisson);

        editCoefExpansao = new QLineEdit(widget);
        editCoefExpansao->setObjectName(QString::fromUtf8("editCoefExpansao"));
        editCoefExpansao->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editCoefExpansao);

        editModuloElasticidade = new QLineEdit(widget);
        editModuloElasticidade->setObjectName(QString::fromUtf8("editModuloElasticidade"));
        editModuloElasticidade->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editModuloElasticidade);

        editPesoUnid = new QLineEdit(widget);
        editPesoUnid->setObjectName(QString::fromUtf8("editPesoUnid"));
        editPesoUnid->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editPesoUnid);


        horizontalLayout->addLayout(verticalLayout_2);

        btnReturn = new QDialogButtonBox(CJanelaAdicionarTrechoTubulacao);
        btnReturn->setObjectName(QString::fromUtf8("btnReturn"));
        btnReturn->setGeometry(QRect(300, 180, 161, 24));
        btnReturn->setOrientation(Qt::Orientation::Horizontal);
        btnReturn->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        groupBox_7 = new QGroupBox(CJanelaAdicionarTrechoTubulacao);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(270, 10, 191, 161));
        groupBox_7->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        groupBox_7->setTitle(QString::fromUtf8(""));
        label_9 = new QLabel(groupBox_7);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 10, 231, 16));
        label_9->setFont(font);
        layoutWidget_4 = new QWidget(groupBox_7);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 30, 171, 111));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        lbnTituloNome = new QLabel(layoutWidget_4);
        lbnTituloNome->setObjectName(QString::fromUtf8("lbnTituloNome"));

        verticalLayout_9->addWidget(lbnTituloNome);

        lbnTituloDensidade = new QLabel(layoutWidget_4);
        lbnTituloDensidade->setObjectName(QString::fromUtf8("lbnTituloDensidade"));

        verticalLayout_9->addWidget(lbnTituloDensidade);

        lbnTituloViscosidade = new QLabel(layoutWidget_4);
        lbnTituloViscosidade->setObjectName(QString::fromUtf8("lbnTituloViscosidade"));

        verticalLayout_9->addWidget(lbnTituloViscosidade);


        horizontalLayout_5->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        editNome = new QLineEdit(layoutWidget_4);
        editNome->setObjectName(QString::fromUtf8("editNome"));
        editNome->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_10->addWidget(editNome);

        editDensidade = new QLineEdit(layoutWidget_4);
        editDensidade->setObjectName(QString::fromUtf8("editDensidade"));
        editDensidade->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_10->addWidget(editDensidade);

        editViscosidade = new QLineEdit(layoutWidget_4);
        editViscosidade->setObjectName(QString::fromUtf8("editViscosidade"));
        editViscosidade->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_10->addWidget(editViscosidade);


        horizontalLayout_5->addLayout(verticalLayout_10);


        retranslateUi(CJanelaAdicionarTrechoTubulacao);
        QObject::connect(btnReturn, SIGNAL(accepted()), CJanelaAdicionarTrechoTubulacao, SLOT(accept()));
        QObject::connect(btnReturn, SIGNAL(rejected()), CJanelaAdicionarTrechoTubulacao, SLOT(reject()));

        QMetaObject::connectSlotsByName(CJanelaAdicionarTrechoTubulacao);
    } // setupUi

    void retranslateUi(QDialog *CJanelaAdicionarTrechoTubulacao)
    {
        CJanelaAdicionarTrechoTubulacao->setWindowTitle(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Dados do Trecho", nullptr));
        lbnTituloTrecho->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Trecho", nullptr));
        lbnTituloProfInicial->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Prof. Inicial (ft)", nullptr));
        lbnTituloProfFinal->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Prof. Final (ft)", nullptr));
        lbnTituloDiametroExterno->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Di\303\242metro Externo", nullptr));
        lbnTituloDiametroInterno->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Di\303\242metro Interno", nullptr));
        lbnTituloCoefPoisson->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Coef. Poisson", nullptr));
        lbnTituloCoefExpancao->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Coef. Expan\303\247\303\243o T\303\251rmica", nullptr));
        lbnTituloModElasticidade->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "M\303\263d. Elasticidade", nullptr));
        lbnTituloPesoUnidade->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Peso por Unid.", nullptr));
        label_9->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Dados do Fluido", nullptr));
        lbnTituloNome->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Nome", nullptr));
        lbnTituloDensidade->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Densidade", nullptr));
        lbnTituloViscosidade->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Viscosidade", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CJanelaAdicionarTrechoTubulacao: public Ui_CJanelaAdicionarTrechoTubulacao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CJANELAADICIONARTRECHOTUBULACAO_H
