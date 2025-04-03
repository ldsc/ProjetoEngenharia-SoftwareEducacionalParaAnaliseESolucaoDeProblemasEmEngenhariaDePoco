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
    QWidget *widget;
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
        CJanelaAdicionarTrechoTubulacao->resize(304, 320);
        widget = new QWidget(CJanelaAdicionarTrechoTubulacao);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 271, 291));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbnTituloTrecho = new QLabel(widget);
        lbnTituloTrecho->setObjectName("lbnTituloTrecho");

        verticalLayout->addWidget(lbnTituloTrecho);

        lbnTituloProfInicial = new QLabel(widget);
        lbnTituloProfInicial->setObjectName("lbnTituloProfInicial");

        verticalLayout->addWidget(lbnTituloProfInicial);

        lbnTituloProfFinal = new QLabel(widget);
        lbnTituloProfFinal->setObjectName("lbnTituloProfFinal");

        verticalLayout->addWidget(lbnTituloProfFinal);

        lbnTituloDiametroExterno = new QLabel(widget);
        lbnTituloDiametroExterno->setObjectName("lbnTituloDiametroExterno");

        verticalLayout->addWidget(lbnTituloDiametroExterno);

        lbnTituloDiametroInterno = new QLabel(widget);
        lbnTituloDiametroInterno->setObjectName("lbnTituloDiametroInterno");

        verticalLayout->addWidget(lbnTituloDiametroInterno);

        lbnTituloCoefPoisson = new QLabel(widget);
        lbnTituloCoefPoisson->setObjectName("lbnTituloCoefPoisson");

        verticalLayout->addWidget(lbnTituloCoefPoisson);

        lbnTituloCoefExpancao = new QLabel(widget);
        lbnTituloCoefExpancao->setObjectName("lbnTituloCoefExpancao");

        verticalLayout->addWidget(lbnTituloCoefExpancao);

        lbnTituloModElasticidade = new QLabel(widget);
        lbnTituloModElasticidade->setObjectName("lbnTituloModElasticidade");

        verticalLayout->addWidget(lbnTituloModElasticidade);

        lbnTituloPesoUnidade = new QLabel(widget);
        lbnTituloPesoUnidade->setObjectName("lbnTituloPesoUnidade");

        verticalLayout->addWidget(lbnTituloPesoUnidade);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        editTrecho = new QLineEdit(widget);
        editTrecho->setObjectName("editTrecho");

        verticalLayout_2->addWidget(editTrecho);

        editProfInicial = new QLineEdit(widget);
        editProfInicial->setObjectName("editProfInicial");

        verticalLayout_2->addWidget(editProfInicial);

        editProfFinal = new QLineEdit(widget);
        editProfFinal->setObjectName("editProfFinal");

        verticalLayout_2->addWidget(editProfFinal);

        editDiametroExterno = new QLineEdit(widget);
        editDiametroExterno->setObjectName("editDiametroExterno");

        verticalLayout_2->addWidget(editDiametroExterno);

        editDiametroInterno = new QLineEdit(widget);
        editDiametroInterno->setObjectName("editDiametroInterno");

        verticalLayout_2->addWidget(editDiametroInterno);

        editCoefPoisson = new QLineEdit(widget);
        editCoefPoisson->setObjectName("editCoefPoisson");

        verticalLayout_2->addWidget(editCoefPoisson);

        editCoefExpansao = new QLineEdit(widget);
        editCoefExpansao->setObjectName("editCoefExpansao");

        verticalLayout_2->addWidget(editCoefExpansao);

        editModuloElasticidade = new QLineEdit(widget);
        editModuloElasticidade->setObjectName("editModuloElasticidade");

        verticalLayout_2->addWidget(editModuloElasticidade);

        editPesoUnid = new QLineEdit(widget);
        editPesoUnid->setObjectName("editPesoUnid");

        verticalLayout_2->addWidget(editPesoUnid);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        btnReturn = new QDialogButtonBox(widget);
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
