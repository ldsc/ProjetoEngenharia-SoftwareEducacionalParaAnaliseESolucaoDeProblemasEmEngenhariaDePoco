#include "CJanelaAdicionarTrechoTubulacao.h"
#include "ui_CJanelaAdicionarTrechoTubulacao.h"
#include <QMessageBox>

CJanelaAdicionarTrechoTubulacao::CJanelaAdicionarTrechoTubulacao(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CJanelaAdicionarTrechoTubulacao)
{
    ui->setupUi(this);

    if (edit){
        ui->editTrecho->setText(getTrecho());
        ui->editProfInicial->setDisabled(true);
        ui->editProfFinal->setDisabled(true);
        ui->editDiametroExterno->setDisabled(true);
        ui->editDiametroInterno->setDisabled(true);
        ui->editCoefPoisson->setText(getCoeficientePoisson());
        ui->editCoefExpansao->setText(getCoeficienteExpansaoTermica());
        ui->editModuloElasticidade->setText(getModuloElasticidade());
        ui->editPesoUnid->setText(getPesoUnidade());
    }
}

CJanelaAdicionarTrechoTubulacao::~CJanelaAdicionarTrechoTubulacao()
{
    delete ui;
}

void CJanelaAdicionarTrechoTubulacao::on_btnReturn_accepted()
{
    if (ui->editTrecho->text().isEmpty() ||
        ui->editProfInicial->text().isEmpty() ||
        ui->editProfFinal->text().isEmpty() ||
        ui->editDiametroExterno->text().isEmpty() ||
        ui->editDiametroInterno->text().isEmpty() ||
        ui->editCoefPoisson->text().isEmpty() ||
        ui->editCoefExpansao->text().isEmpty() ||
        ui->editModuloElasticidade->text().isEmpty() ||
        ui->editPesoUnid->text().isEmpty()) {

        QMessageBox::warning(this, "Erro", "Por favor, preencha todos os campos!");
    } else if (edit) {
        setTrecho(ui->editTrecho->text());
        setProfundidadeInicial(ui->editProfInicial->text());
        setProfundidadeFinal(ui->editProfFinal->text());
        setDiametroExterno(ui->editDiametroExterno->text());
        setDiametroInterno(ui->editDiametroInterno->text());
        setCoeficientePoisson(ui->editCoefPoisson->text());
        setCoeficienteExpansaoTermica(ui->editCoefExpansao->text());
        setModuloElasticidade(ui->editModuloElasticidade->text());
        setPesoUnidade(ui->editPesoUnid->text());
    }

    edit = true;
}


void CJanelaAdicionarTrechoTubulacao::on_btnReturn_rejected()
{
    close();
}

