/********************************************************************************
** Form generated from reading UI file 'CJanelaGraficoPressaoHidroestatica.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CJANELAGRAFICOPRESSAOHIDROESTATICA_H
#define UI_CJANELAGRAFICOPRESSAOHIDROESTATICA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_CJanelaGraficoPressaoHidroestatica
{
public:
    QGroupBox *groupBox_4;
    QCustomPlot *customPlotPressaoMediaProfundidade;
    QLabel *label_12;
    QPushButton *BntnExportarGrafico;

    void setupUi(QDialog *CJanelaGraficoPressaoHidroestatica)
    {
        if (CJanelaGraficoPressaoHidroestatica->objectName().isEmpty())
            CJanelaGraficoPressaoHidroestatica->setObjectName("CJanelaGraficoPressaoHidroestatica");
        CJanelaGraficoPressaoHidroestatica->resize(471, 419);
        groupBox_4 = new QGroupBox(CJanelaGraficoPressaoHidroestatica);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 10, 451, 371));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 4px;\n"
"}"));
        customPlotPressaoMediaProfundidade = new QCustomPlot(groupBox_4);
        customPlotPressaoMediaProfundidade->setObjectName("customPlotPressaoMediaProfundidade");
        customPlotPressaoMediaProfundidade->setGeometry(QRect(10, 40, 431, 321));
        customPlotPressaoMediaProfundidade->setStyleSheet(QString::fromUtf8(""));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 10, 271, 16));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label_12->setFont(font);
        BntnExportarGrafico = new QPushButton(CJanelaGraficoPressaoHidroestatica);
        BntnExportarGrafico->setObjectName("BntnExportarGrafico");
        BntnExportarGrafico->setGeometry(QRect(354, 390, 101, 24));

        retranslateUi(CJanelaGraficoPressaoHidroestatica);

        QMetaObject::connectSlotsByName(CJanelaGraficoPressaoHidroestatica);
    } // setupUi

    void retranslateUi(QDialog *CJanelaGraficoPressaoHidroestatica)
    {
        CJanelaGraficoPressaoHidroestatica->setWindowTitle(QCoreApplication::translate("CJanelaGraficoPressaoHidroestatica", "Dialog", nullptr));
        groupBox_4->setTitle(QString());
        label_12->setText(QCoreApplication::translate("CJanelaGraficoPressaoHidroestatica", "Profundidade x Press\303\243o Hidroestatica", nullptr));
        BntnExportarGrafico->setText(QCoreApplication::translate("CJanelaGraficoPressaoHidroestatica", "Exportar Gr\303\241fico", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CJanelaGraficoPressaoHidroestatica: public Ui_CJanelaGraficoPressaoHidroestatica {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CJANELAGRAFICOPRESSAOHIDROESTATICA_H
