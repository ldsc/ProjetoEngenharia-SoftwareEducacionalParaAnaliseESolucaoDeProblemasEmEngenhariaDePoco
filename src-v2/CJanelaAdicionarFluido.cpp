#include "CJanelaAdicionarFluido.h"
#include "ui_CJanelaAdicionarFluido.h"
#include <QMessageBox>

// Construtor da janela - inicializa a interface grafica
janelaadicionarfluido::janelaadicionarfluido(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::janelaadicionarfluido)
{
    ui->setupUi(this);
}

// Destrutor - limpa a interface da memoria
janelaadicionarfluido::~janelaadicionarfluido()
{
    delete ui;
}

// Acao quando o usuario clica em "OK"
void janelaadicionarfluido::on_btnReturn_accepted()
{
    // Se for modo de edicao, habilita todos os campos
    if (ModoEdicao()) {
        NomeFluido(ui->LnValorNome->text());
        Densidade(ui->LnValorDensidade->text());
        Viscosidade(ui->LnValorViscosidade->text());
        ProfundidadeInicial(ui->LnValorProfundidadeInicial->text());
        ProfundidadeFinal(ui->LnValorProfundidadeFinal->text());

        // Verifica se algum campo ficou vazio
        if (ui->LnValorNome->text().isEmpty() ||
            ui->LnValorDensidade->text().isEmpty() ||
            ui->LnValorViscosidade->text().isEmpty() ||
            ui->LnValorProfundidadeInicial->text().isEmpty() ||
            ui->LnValorProfundidadeFinal->text().isEmpty()) {
            QMessageBox::warning(this, "Erro", "Por favor, preencha todos os campos!");
        }

    } else {
        // Modo sem edicao da faixa de profundidade
        NomeFluido(ui->LnValorNome->text());
        Densidade(ui->LnValorDensidade->text());
        Viscosidade(ui->LnValorViscosidade->text());

        ui->LnValorProfundidadeInicial->setDisabled(true);
        ui->LnValorProfundidadeFinal->setDisabled(true);

        if (ui->LnValorNome->text().isEmpty() ||
            ui->LnValorDensidade->text().isEmpty() ||
            ui->LnValorViscosidade->text().isEmpty()) {
            QMessageBox::warning(this, "Erro", "Por favor, preencha todos os campos!");
        }
    }
}

// Acao quando o usuario clica em "Cancelar"
void janelaadicionarfluido::on_btnReturn_rejected()
{
    close();
}
