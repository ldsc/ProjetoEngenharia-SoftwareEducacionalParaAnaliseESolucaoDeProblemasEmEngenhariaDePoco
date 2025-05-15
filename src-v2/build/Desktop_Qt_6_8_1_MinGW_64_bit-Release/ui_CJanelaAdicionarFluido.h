/********************************************************************************
** Form generated from reading UI file 'CJanelaAdicionarFluido.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CJANELAADICIONARFLUIDO_H
#define UI_CJANELAADICIONARFLUIDO_H

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

class Ui_CJanelaAdicionarFluido
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lbnTituloNome;
    QLabel *lbnTituloDensidade;
    QLabel *lbnTituloViscosidade;
    QLabel *lbnTituloProfundidadeInicial;
    QLabel *lbnTituloProfundidadeFinal;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *LnValorNome;
    QLineEdit *LnValorDensidade;
    QLineEdit *LnValorViscosidade;
    QLineEdit *LnValorProfundidadeInicial;
    QLineEdit *LnValorProfundidadeFinal;
    QDialogButtonBox *btnReturn;

    void setupUi(QDialog *CJanelaAdicionarFluido)
    {
        if (CJanelaAdicionarFluido->objectName().isEmpty())
            CJanelaAdicionarFluido->setObjectName("CJanelaAdicionarFluido");
        CJanelaAdicionarFluido->resize(227, 202);
        layoutWidget = new QWidget(CJanelaAdicionarFluido);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 211, 185));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbnTituloNome = new QLabel(layoutWidget);
        lbnTituloNome->setObjectName("lbnTituloNome");

        verticalLayout->addWidget(lbnTituloNome);

        lbnTituloDensidade = new QLabel(layoutWidget);
        lbnTituloDensidade->setObjectName("lbnTituloDensidade");

        verticalLayout->addWidget(lbnTituloDensidade);

        lbnTituloViscosidade = new QLabel(layoutWidget);
        lbnTituloViscosidade->setObjectName("lbnTituloViscosidade");

        verticalLayout->addWidget(lbnTituloViscosidade);

        lbnTituloProfundidadeInicial = new QLabel(layoutWidget);
        lbnTituloProfundidadeInicial->setObjectName("lbnTituloProfundidadeInicial");

        verticalLayout->addWidget(lbnTituloProfundidadeInicial);

        lbnTituloProfundidadeFinal = new QLabel(layoutWidget);
        lbnTituloProfundidadeFinal->setObjectName("lbnTituloProfundidadeFinal");

        verticalLayout->addWidget(lbnTituloProfundidadeFinal);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        LnValorNome = new QLineEdit(layoutWidget);
        LnValorNome->setObjectName("LnValorNome");
        LnValorNome->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(LnValorNome);

        LnValorDensidade = new QLineEdit(layoutWidget);
        LnValorDensidade->setObjectName("LnValorDensidade");
        LnValorDensidade->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(LnValorDensidade);

        LnValorViscosidade = new QLineEdit(layoutWidget);
        LnValorViscosidade->setObjectName("LnValorViscosidade");
        LnValorViscosidade->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(LnValorViscosidade);

        LnValorProfundidadeInicial = new QLineEdit(layoutWidget);
        LnValorProfundidadeInicial->setObjectName("LnValorProfundidadeInicial");
        LnValorProfundidadeInicial->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(LnValorProfundidadeInicial);

        LnValorProfundidadeFinal = new QLineEdit(layoutWidget);
        LnValorProfundidadeFinal->setObjectName("LnValorProfundidadeFinal");
        LnValorProfundidadeFinal->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(LnValorProfundidadeFinal);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        btnReturn = new QDialogButtonBox(layoutWidget);
        btnReturn->setObjectName("btnReturn");
        btnReturn->setOrientation(Qt::Orientation::Horizontal);
        btnReturn->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout_3->addWidget(btnReturn);


        retranslateUi(CJanelaAdicionarFluido);
        QObject::connect(btnReturn, &QDialogButtonBox::accepted, CJanelaAdicionarFluido, qOverload<>(&QDialog::accept));
        QObject::connect(btnReturn, &QDialogButtonBox::rejected, CJanelaAdicionarFluido, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CJanelaAdicionarFluido);
    } // setupUi

    void retranslateUi(QDialog *CJanelaAdicionarFluido)
    {
        CJanelaAdicionarFluido->setWindowTitle(QCoreApplication::translate("CJanelaAdicionarFluido", "Dialog", nullptr));
        lbnTituloNome->setText(QCoreApplication::translate("CJanelaAdicionarFluido", "Nome:", nullptr));
        lbnTituloDensidade->setText(QCoreApplication::translate("CJanelaAdicionarFluido", "Densidade:", nullptr));
        lbnTituloViscosidade->setText(QCoreApplication::translate("CJanelaAdicionarFluido", "Viscosidade:", nullptr));
        lbnTituloProfundidadeInicial->setText(QCoreApplication::translate("CJanelaAdicionarFluido", "Profunidade Inicial:", nullptr));
        lbnTituloProfundidadeFinal->setText(QCoreApplication::translate("CJanelaAdicionarFluido", "Profundidade Final:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CJanelaAdicionarFluido: public Ui_CJanelaAdicionarFluido {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CJANELAADICIONARFLUIDO_H
