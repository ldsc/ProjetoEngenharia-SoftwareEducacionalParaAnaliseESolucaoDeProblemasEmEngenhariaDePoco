#include "CJanelaMenu.h"
#include "ui_CJanelaMenu.h"

#include "CSimuladorReologico.h"
#include "CSimuladorPerdaTubulacao.h"

// Construtor da janela principal do menu
JanelaMenu::JanelaMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JanelaMenu)
{
    ui->setupUi(this);

    // Caixa de texto apenas para visualizacao, sem interacao
    ui->textEdit->setReadOnly(true);
    ui->textEdit->setMouseTracking(false);
    ui->textEdit->setFocusPolicy(Qt::NoFocus);

    // Configuracao da descricao do Modulo 1
    ui->lbnModulo01->setAlignment(Qt::AlignCenter);

    // Texto com HTML para deixar a explicacao mais visual
    QString buttonText_01 =
        "<b>Modulo 01 - Hidráulica de Perfuração</b><br>"
        "<ul>"
        "<li>Transporte de Cascalho.</li>"
        "<li>Fluxo nao Newtoniano na Coluna e Anular.</li>"
        "</ul>";

    ui->lbnModulo01->setText(buttonText_01);
    ui->btnModulo01->setText("");  // Botao fica invisivel para dar lugar ao label formatado
    ui->lbnModulo01->setAttribute(Qt::WA_TransparentForMouseEvents); // Label nao atrapalha clique

    // Configuracao da descricao do Modulo 2
    ui->lbnModulo02->setAlignment(Qt::AlignCenter);

    QString buttonText_02 =
        "<b>Modulo 02 - Analise de Tensoes na Coluna</b><br>"
        "<ul>"
        "<li>Carga Axial.</li>"
        "<li>Colapso e Explosao da Coluna.</li>"
        "</ul>";

    ui->lbnModulo02->setText(buttonText_02);
    ui->btnModulo02->setText("");
    ui->lbnModulo02->setAttribute(Qt::WA_TransparentForMouseEvents);
}

// Destrutor da janela principal
JanelaMenu::~JanelaMenu()
{
    delete ui;
}

// Quando o usuario clica no Modulo 1, abre a janela de simulacao reologica
void JanelaMenu::on_btnModulo01_clicked()
{
    CSimuladorReologico *w = new CSimuladorReologico(this);
    w->setWindowTitle("SEAPEP - Software Educacional de Engenharia de Poço");
    w->show();
}

// Quando o usuario clica no Modulo 2, abre a janela de simulacao de perda na tubulacao
void JanelaMenu::on_btnModulo02_clicked()
{
    CSimuladorPerdaTubulacao *w = new CSimuladorPerdaTubulacao(this);
    w->setWindowTitle("SEAPEP - Software Educacional de Engenharia de Poço");
    w->show();
}
