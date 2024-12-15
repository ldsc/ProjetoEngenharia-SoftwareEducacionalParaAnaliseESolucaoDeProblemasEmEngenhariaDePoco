#include "janelaadicionarfluido.h"
#include "ui_janelaadicionarfluido.h"
#include <QMessageBox>

janelaadicionarfluido::janelaadicionarfluido(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::janelaadicionarfluido)
{
    ui->setupUi(this);
}

janelaadicionarfluido::~janelaadicionarfluido()
{
    delete ui;
}

void janelaadicionarfluido::on_btnReturn_accepted()
{

    setNomeFluido(ui->LnValorNome->text());
    setDensidade(ui->LnValorDensidade->text());
    setViscosidade(ui->LnValorViscosidade->text());
    setProfunidadeInicial(ui->LnValorProfundidadeInicial->text());
    setProfunidadeFinal(ui->LnValorProfundidadeFinal->text());

    if (ui->LnValorNome->text().isEmpty() ||
        ui->LnValorDensidade->text().isEmpty() ||
        ui->LnValorViscosidade->text().isEmpty() ||
        ui->LnValorProfundidadeInicial->text().isEmpty() ||
        ui->lbnTituloProfundidadeFinal->text().isEmpty()) {
        QMessageBox::warning(this, "Erro", "Por favor, preencha todos os campos!");
    }
}


void janelaadicionarfluido::on_btnReturn_rejected()
{
    close();
}

