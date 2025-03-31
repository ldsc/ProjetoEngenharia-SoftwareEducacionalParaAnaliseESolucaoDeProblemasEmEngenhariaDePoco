#include "CJanelaMenu.h"
#include "ui_CJanelaMenu.h"

#include "CSimuladorReologico.h"

JanelaMenu::JanelaMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JanelaMenu)
{
    ui->setupUi(this);

    ui->btnModulo02->setEnabled(false);

    ui->textEdit->setReadOnly(true);
    ui->textEdit->setMouseTracking(false);
    ui->textEdit->setFocusPolicy(Qt::NoFocus);

    ui->lbnModulo01->setAlignment(Qt::AlignCenter);
    QString buttonText_01 = "<b>Modulo 01 - Hidráulica de perfuração</b><br><ul><li>Transporte de cascalho.</li><li>Fluxo não newtoniano na coluna e espaço anular na coluna de perfuração</li></ul>";
    ui->lbnModulo01->setText(buttonText_01);
    ui->btnModulo01->setText("");
    ui->lbnModulo01->setAttribute(Qt::WA_TransparentForMouseEvents);

    //ui->lbnModulo02->setAlignment(Qt::AlignCenter);
    //QString buttonText_02 = "<b>Modulo 01 - Hidráulica de perfuração</b><br><ul><li>Transporte de cascalho.</li><li>Fluxo não newtoniano na coluna e espaço anular na coluna de perfuração</li></ul>";
    //ui->lbnModulo02->setText(buttonText_02);
    //ui->btnModulo02->setText("");
    //ui->lbnModulo02->setAttribute(Qt::WA_TransparentForMouseEvents);
}

JanelaMenu::~JanelaMenu()
{
    delete ui;
}

void JanelaMenu::on_btnModulo01_clicked()
{
    CSimuladorPoco *w = new CSimuladorPoco(this);
    w->setWindowTitle("SEAPEP - Software Educacional de Engenharia de Poço");
    w->show();
}

