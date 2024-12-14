#include "janelaadicionarfluido.h"
#include "ui_janelaadicionarfluido.h"

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

QString janelaadicionarfluido::on_btnReturn_accepted()
{
    QString nome, densidade, viscosidade, profunInicial, profunFinal;

    nome = ui->LnValorNome->text();
    densidade = ui->LnValorDensidade->text();
    viscosidade = ui->LnValorDensidade->text();
    profunInicial = ui->LnValorProfundidadeInicial->text();
    profunFinal = ui->lbnTituloProfundidadeFinal->text();
}

