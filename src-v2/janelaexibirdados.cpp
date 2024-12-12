#include "janelaexibirdados.h"
#include "ui_janelaexibirdados.h"

janelaExibirDados::janelaExibirDados(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::janelaExibirDados)
{
    ui->setupUi(this);
}

janelaExibirDados::~janelaExibirDados()
{
    delete ui;
}

janelaExibirDados::coletarPropriedade(double valor){

    ui->LblValorProfundidade->setText(QString::number(valor));
}
