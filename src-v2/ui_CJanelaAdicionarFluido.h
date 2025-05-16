/********************************************************************************
** Form generated from reading UI file 'CJanelaAdicionarFluido.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CJANELAADICIONARFLUIDO_H
#define UI_CJANELAADICIONARFLUIDO_H

#include <QtCore/QVariant>
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
            CJanelaAdicionarFluido->setObjectName(QString::fromUtf8("CJanelaAdicionarFluido"));
        CJanelaAdicionarFluido->resize(227, 202);
        layoutWidget = new QWidget(CJanelaAdicionarFluido);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 211, 185));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbnTituloNome = new QLabel(layoutWidget);
        lbnTituloNome->setObjectName(QString::fromUtf8("lbnTituloNome"));

        verticalLayout->addWidget(lbnTituloNome);

        lbnTituloDensidade = new QLabel(layoutWidget);
        lbnTituloDensidade->setObjectName(QString::fromUtf8("lbnTituloDensidade"));

        verticalLayout->addWidget(lbnTituloDensidade);

        lbnTituloViscosidade = new QLabel(layoutWidget);
        lbnTituloViscosidade->setObjectName(QString::fromUtf8("lbnTituloViscosidade"));

        verticalLayout->addWidget(lbnTituloViscosidade);

        lbnTituloProfundidadeInicial = new QLabel(layoutWidget);
        lbnTituloProfundidadeInicial->setObjectName(QString::fromUtf8("lbnTituloProfundidadeInicial"));

        verticalLayout->addWidget(lbnTituloProfundidadeInicial);

        lbnTituloProfundidadeFinal = new QLabel(layoutWidget);
        lbnTituloProfundidadeFinal->setObjectName(QString::fromUtf8("lbnTituloProfundidadeFinal"));

        verticalLayout->addWidget(lbnTituloProfundidadeFinal);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        LnValorNome = new QLineEdit(layoutWidget);
        LnValorNome->setObjectName(QString::fromUtf8("LnValorNome"));
        LnValorNome->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(LnValorNome);

        LnValorDensidade = new QLineEdit(layoutWidget);
        LnValorDensidade->setObjectName(QString::fromUtf8("LnValorDensidade"));
        LnValorDensidade->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(LnValorDensidade);

        LnValorViscosidade = new QLineEdit(layoutWidget);
        LnValorViscosidade->setObjectName(QString::fromUtf8("LnValorViscosidade"));
        LnValorViscosidade->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(LnValorViscosidade);

        LnValorProfundidadeInicial = new QLineEdit(layoutWidget);
        LnValorProfundidadeInicial->setObjectName(QString::fromUtf8("LnValorProfundidadeInicial"));
        LnValorProfundidadeInicial->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(LnValorProfundidadeInicial);

        LnValorProfundidadeFinal = new QLineEdit(layoutWidget);
        LnValorProfundidadeFinal->setObjectName(QString::fromUtf8("LnValorProfundidadeFinal"));
        LnValorProfundidadeFinal->setStyleSheet(QString::fromUtf8("border: 1px solid #dddddd;  /* borda cinza bem leve */\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(LnValorProfundidadeFinal);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        btnReturn = new QDialogButtonBox(layoutWidget);
        btnReturn->setObjectName(QString::fromUtf8("btnReturn"));
        btnReturn->setOrientation(Qt::Orientation::Horizontal);
        btnReturn->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout_3->addWidget(btnReturn);


        retranslateUi(CJanelaAdicionarFluido);
        QObject::connect(btnReturn, SIGNAL(accepted()), CJanelaAdicionarFluido, SLOT(accept()));
        QObject::connect(btnReturn, SIGNAL(rejected()), CJanelaAdicionarFluido, SLOT(reject()));

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
