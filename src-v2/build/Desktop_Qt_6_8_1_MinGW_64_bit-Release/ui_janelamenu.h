/********************************************************************************
** Form generated from reading UI file 'janelamenu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELAMENU_H
#define UI_JANELAMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaMenu
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QPushButton *btnModulo01;
    QPushButton *btnModulo02;
    QLabel *lbnModulo01;
    QLabel *lbnModulo01_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *JanelaMenu)
    {
        if (JanelaMenu->objectName().isEmpty())
            JanelaMenu->setObjectName("JanelaMenu");
        JanelaMenu->resize(790, 306);
        centralwidget = new QWidget(JanelaMenu);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 30, 431, 211));
        btnModulo01 = new QPushButton(centralwidget);
        btnModulo01->setObjectName("btnModulo01");
        btnModulo01->setGeometry(QRect(460, 20, 311, 111));
        btnModulo02 = new QPushButton(centralwidget);
        btnModulo02->setObjectName("btnModulo02");
        btnModulo02->setGeometry(QRect(460, 140, 311, 111));
        lbnModulo01 = new QLabel(centralwidget);
        lbnModulo01->setObjectName("lbnModulo01");
        lbnModulo01->setGeometry(QRect(460, 30, 301, 101));
        lbnModulo01_2 = new QLabel(centralwidget);
        lbnModulo01_2->setObjectName("lbnModulo01_2");
        lbnModulo01_2->setGeometry(QRect(460, 140, 301, 101));
        JanelaMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(JanelaMenu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 790, 22));
        JanelaMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(JanelaMenu);
        statusbar->setObjectName("statusbar");
        JanelaMenu->setStatusBar(statusbar);

        retranslateUi(JanelaMenu);

        QMetaObject::connectSlotsByName(JanelaMenu);
    } // setupUi

    void retranslateUi(QMainWindow *JanelaMenu)
    {
        JanelaMenu->setWindowTitle(QCoreApplication::translate("JanelaMenu", "MainWindow", nullptr));
        textEdit->setHtml(QCoreApplication::translate("JanelaMenu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:700;\">Software Educacional para An\303\241lise e Solu\303\247\303\265es de Problemas Em Engenharia de Po\303\247o</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic;\">Bem-vindo ao software de simula\303\247\303\243o de pulsos!</span></p>\n"
""
                        "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Este simulador foi desenvolvido para auxiliar no estudo dos fen\303\264menos de po\303\247o na engenharia, permitindo simula\303\247\303\265es interativas e c\303\241lculos avan\303\247ados.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">Desenvolvedor:</span> Nathan Rangel Magalh\303\243es<br /><span style=\" font-weight:700;\">Coordenador:</span> Andr\303\251 Duarte Bueno<br /><span style=\" font-weight:700;\">Contato:</span> nathanmagalhaes@lenep.uenf.br / bueno@lenep.uenf.br</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Escolha um dos m\303\263dulos abaixo para iniciar sua simula\303\247\303\243o:</p></body></html>", nullptr));
        btnModulo01->setText(QString());
        btnModulo02->setText(QString());
        lbnModulo01->setText(QCoreApplication::translate("JanelaMenu", "<html><b>Modulo 01 - Hidr\303\241ulica de perfura\303\247\303\243o</b><br><ul><li>Transporte de cascalho.</li><li>Fluxo n\303\243o newtoniano na coluna e espa\303\247o anular na coluna de perfura\303\247\303\243o</li></ul></html>", nullptr));
        lbnModulo01_2->setText(QCoreApplication::translate("JanelaMenu", "<html><b>Modulo 02 - Hidr\303\241ulica de perfura\303\247\303\243o</b><br><ul><li>Transporte de cascalho.</li><li>Fluxo n\303\243o newtoniano na coluna e espa\303\247o anular na coluna de perfura\303\247\303\243o</li></ul></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JanelaMenu: public Ui_JanelaMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAMENU_H
