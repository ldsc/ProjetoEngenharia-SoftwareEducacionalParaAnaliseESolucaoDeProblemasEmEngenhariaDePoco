#include "CJanelaMenu.h"
#include "ui_CJanelaMenu.h"

#include "CSimuladorReologico.h"
#include "CSimuladorPerdaTubulacao.h"

JanelaMenu::JanelaMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JanelaMenu)
{
    ui->setupUi(this);

    ui->textEdit->setReadOnly(true);
    ui->textEdit->setMouseTracking(false);
    ui->textEdit->setFocusPolicy(Qt::NoFocus);

    ui->lbnModulo01->setAlignment(Qt::AlignCenter);
    QString buttonText_01 = "<b>Modulo 01 - Hidráulica de Perfuração</b><br><ul><li>Transporte de Cascalho.</li><li>Fluxo não Newtoniano na Coluna e Anular.</li></ul>";
    ui->lbnModulo01->setText(buttonText_01);
    ui->btnModulo01->setText("");
    ui->lbnModulo01->setAttribute(Qt::WA_TransparentForMouseEvents);

    ui->lbnModulo02->setAlignment(Qt::AlignCenter);
    QString buttonText_02 = "<b>Modulo 02 - Análise de Tensões na Coluna</b><br><ul><li>Carga Axial.</li><li>Colapso e Explosão da Coluna</li></ul>";
    ui->lbnModulo02->setText(buttonText_02);
    ui->btnModulo02->setText("");
    ui->lbnModulo02->setAttribute(Qt::WA_TransparentForMouseEvents);
}

JanelaMenu::~JanelaMenu()
{
    delete ui;
}

void JanelaMenu::on_btnModulo01_clicked()
{
    CSimuladorReologico *w = new CSimuladorReologico(this);
    w->setWindowTitle("SEAPEP - Software Educacional de Engenharia de Poço");
    w->show();
}


void JanelaMenu::on_btnModulo02_clicked()
{
    CSimuladorPerdaTubulacao *w = new CSimuladorPerdaTubulacao(this);
    w->setWindowTitle("SEAPEP - Software Educacional de Engenharia de Poço");
    w->show();
}

