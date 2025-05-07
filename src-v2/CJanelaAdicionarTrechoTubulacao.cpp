#include "CJanelaAdicionarTrechoTubulacao.h"
#include "ui_CJanelaAdicionarTrechoTubulacao.h"
#include <QMessageBox>

CJanelaAdicionarTrechoTubulacao::CJanelaAdicionarTrechoTubulacao(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CJanelaAdicionarTrechoTubulacao)
{
    ui->setupUi(this);
}

CJanelaAdicionarTrechoTubulacao::~CJanelaAdicionarTrechoTubulacao()
{
    delete ui;
}

void CJanelaAdicionarTrechoTubulacao::on_btnReturn_accepted()
{
    if (edit == true){
        setTrecho(ui->editTrecho->text());
        setProfundidadeInicial(ui->editProfInicial->text());
        setProfundidadeFinal(ui->editProfFinal->text());
        setDiametroExterno(ui->editDiametroExterno->text());
        setDiametroInterno(ui->editDiametroInterno->text());
        setCoeficientePoisson(ui->editCoefPoisson->text());
        setCoeficienteExpansaoTermica(ui->editCoefExpansao->text());
        setModuloElasticidade(ui->editModuloElasticidade->text());
        setPesoUnidade(ui->editPesoUnid->text());
        setNomeFluido(ui->editNome->text());
        setDensidade(ui->editDensidade->text());
        setViscosidade(ui->editViscosidade->text());

        if (ui->editTrecho->text().isEmpty() ||
            ui->editProfInicial->text().isEmpty() ||
            ui->editProfFinal->text().isEmpty() ||
            ui->editDiametroExterno->text().isEmpty() ||
            ui->editDiametroInterno->text().isEmpty() ||
            ui->editCoefPoisson->text().isEmpty() ||
            ui->editCoefExpansao->text().isEmpty() ||
            ui->editModuloElasticidade->text().isEmpty() ||
            ui->editPesoUnid->text().isEmpty() ||
            ui->editNome->text().isEmpty() ||
            ui->editDensidade->text().isEmpty() ||
            ui->editViscosidade->text().isEmpty()){

            QMessageBox::warning(this, "Erro", "Por favor, preencha todos os campos!");
        }
    }
    else{
        setTrecho(ui->editTrecho->text());
        setProfundidadeInicial(ui->editProfInicial->text());
        setProfundidadeFinal(ui->editProfFinal->text());
        setDiametroExterno(ui->editDiametroExterno->text());
        setDiametroInterno(ui->editDiametroInterno->text());
        setCoeficientePoisson(ui->editCoefPoisson->text());
        setCoeficienteExpansaoTermica(ui->editCoefExpansao->text());
        setModuloElasticidade(ui->editModuloElasticidade->text());
        setPesoUnidade(ui->editPesoUnid->text());
        setNomeFluido(ui->editNome->text());
        setDensidade(ui->editDensidade->text());
        setViscosidade(ui->editViscosidade->text());
    }
}



void CJanelaAdicionarTrechoTubulacao::on_btnReturn_rejected()
{
    close();
}

