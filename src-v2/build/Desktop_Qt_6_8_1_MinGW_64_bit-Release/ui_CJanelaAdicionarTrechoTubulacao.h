/********************************************************************************
** Form generated from reading UI file 'CJanelaAdicionarTrechoTubulacao.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CJANELAADICIONARTRECHOTUBULACAO_H
#define UI_CJANELAADICIONARTRECHOTUBULACAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CJanelaAdicionarTrechoTubulacao
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
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

    void setupUi(QDialog *CJanelaAdicionarTrechoTubulacao)
    {
        if (CJanelaAdicionarTrechoTubulacao->objectName().isEmpty())
            CJanelaAdicionarTrechoTubulacao->setObjectName("CJanelaAdicionarTrechoTubulacao");
        CJanelaAdicionarTrechoTubulacao->resize(255, 283);
        layoutWidget = new QWidget(CJanelaAdicionarTrechoTubulacao);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 231, 261));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbnTituloTrecho = new QLabel(layoutWidget);
        lbnTituloTrecho->setObjectName("lbnTituloTrecho");

        verticalLayout->addWidget(lbnTituloTrecho);

        lbnTituloProfInicial = new QLabel(layoutWidget);
        lbnTituloProfInicial->setObjectName("lbnTituloProfInicial");

        verticalLayout->addWidget(lbnTituloProfInicial);

        lbnTituloProfFinal = new QLabel(layoutWidget);
        lbnTituloProfFinal->setObjectName("lbnTituloProfFinal");

        verticalLayout->addWidget(lbnTituloProfFinal);

        lbnTituloDiametroExterno = new QLabel(layoutWidget);
        lbnTituloDiametroExterno->setObjectName("lbnTituloDiametroExterno");

        verticalLayout->addWidget(lbnTituloDiametroExterno);

        lbnTituloDiametroInterno = new QLabel(layoutWidget);
        lbnTituloDiametroInterno->setObjectName("lbnTituloDiametroInterno");

        verticalLayout->addWidget(lbnTituloDiametroInterno);

        lbnTituloCoefPoisson = new QLabel(layoutWidget);
        lbnTituloCoefPoisson->setObjectName("lbnTituloCoefPoisson");

        verticalLayout->addWidget(lbnTituloCoefPoisson);

        lbnTituloCoefExpancao = new QLabel(layoutWidget);
        lbnTituloCoefExpancao->setObjectName("lbnTituloCoefExpancao");

        verticalLayout->addWidget(lbnTituloCoefExpancao);

        lbnTituloModElasticidade = new QLabel(layoutWidget);
        lbnTituloModElasticidade->setObjectName("lbnTituloModElasticidade");

        verticalLayout->addWidget(lbnTituloModElasticidade);

        lbnTituloPesoUnidade = new QLabel(layoutWidget);
        lbnTituloPesoUnidade->setObjectName("lbnTituloPesoUnidade");

        verticalLayout->addWidget(lbnTituloPesoUnidade);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        editTrecho = new QLineEdit(layoutWidget);
        editTrecho->setObjectName("editTrecho");
        editTrecho->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editTrecho);

        editProfInicial = new QLineEdit(layoutWidget);
        editProfInicial->setObjectName("editProfInicial");
        editProfInicial->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editProfInicial);

        editProfFinal = new QLineEdit(layoutWidget);
        editProfFinal->setObjectName("editProfFinal");
        editProfFinal->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editProfFinal);

        editDiametroExterno = new QLineEdit(layoutWidget);
        editDiametroExterno->setObjectName("editDiametroExterno");
        editDiametroExterno->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editDiametroExterno);

        editDiametroInterno = new QLineEdit(layoutWidget);
        editDiametroInterno->setObjectName("editDiametroInterno");
        editDiametroInterno->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editDiametroInterno);

        editCoefPoisson = new QLineEdit(layoutWidget);
        editCoefPoisson->setObjectName("editCoefPoisson");
        editCoefPoisson->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editCoefPoisson);

        editCoefExpansao = new QLineEdit(layoutWidget);
        editCoefExpansao->setObjectName("editCoefExpansao");
        editCoefExpansao->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editCoefExpansao);

        editModuloElasticidade = new QLineEdit(layoutWidget);
        editModuloElasticidade->setObjectName("editModuloElasticidade");
        editModuloElasticidade->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editModuloElasticidade);

        editPesoUnid = new QLineEdit(layoutWidget);
        editPesoUnid->setObjectName("editPesoUnid");
        editPesoUnid->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(editPesoUnid);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        btnReturn = new QDialogButtonBox(layoutWidget);
        btnReturn->setObjectName("btnReturn");
        btnReturn->setOrientation(Qt::Orientation::Horizontal);
        btnReturn->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout_3->addWidget(btnReturn);


        retranslateUi(CJanelaAdicionarTrechoTubulacao);
        QObject::connect(btnReturn, &QDialogButtonBox::accepted, CJanelaAdicionarTrechoTubulacao, qOverload<>(&QDialog::accept));
        QObject::connect(btnReturn, &QDialogButtonBox::rejected, CJanelaAdicionarTrechoTubulacao, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CJanelaAdicionarTrechoTubulacao);
    } // setupUi

    void retranslateUi(QDialog *CJanelaAdicionarTrechoTubulacao)
    {
        CJanelaAdicionarTrechoTubulacao->setWindowTitle(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Dialog", nullptr));
        lbnTituloTrecho->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Trecho", nullptr));
        lbnTituloProfInicial->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Prof. Inicial (ft)", nullptr));
        lbnTituloProfFinal->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Prof. Final (ft)", nullptr));
        lbnTituloDiametroExterno->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Di\303\242metro Externo", nullptr));
        lbnTituloDiametroInterno->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Di\303\242metro Interno", nullptr));
        lbnTituloCoefPoisson->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Coef. Poisson", nullptr));
        lbnTituloCoefExpancao->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Coef. Expan\303\247\303\243o T\303\251rmica", nullptr));
        lbnTituloModElasticidade->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "M\303\263d. Elasticidade", nullptr));
        lbnTituloPesoUnidade->setText(QCoreApplication::translate("CJanelaAdicionarTrechoTubulacao", "Peso por Unid.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CJanelaAdicionarTrechoTubulacao: public Ui_CJanelaAdicionarTrechoTubulacao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CJANELAADICIONARTRECHOTUBULACAO_H
