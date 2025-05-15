#include "CJanelaAdicionarTrechoTubulacao.h"
#include "ui_CJanelaAdicionarTrechoTubulacao.h"
#include <QMessageBox>

// Construtor: inicializa a interface
CJanelaAdicionarTrechoTubulacao::CJanelaAdicionarTrechoTubulacao(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CJanelaAdicionarTrechoTubulacao)
{
    ui->setupUi(this);
}

// Destrutor: libera memoria da interface
CJanelaAdicionarTrechoTubulacao::~CJanelaAdicionarTrechoTubulacao()
{
    delete ui;
}

// Acao ao clicar em OK
void CJanelaAdicionarTrechoTubulacao::on_btnReturn_accepted()
{
    // verifica se campos obrigatorios estao vazios
    bool camposVazios =
        ui->editTrecho->text().isEmpty() ||
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
        ui->editViscosidade->text().isEmpty();

    if (edit && camposVazios) {
        QMessageBox::warning(this, "Erro", "Por favor, preencha todos os campos!");
        return; // nao continua se estiver faltando campo
    }

    // define todos os valores a partir dos campos
    Trecho(ui->editTrecho->text());
    ProfundidadeInicial(ui->editProfInicial->text());
    ProfundidadeFinal(ui->editProfFinal->text());
    DiametroExterno(ui->editDiametroExterno->text());
    DiametroInterno(ui->editDiametroInterno->text());
    CoeficientePoisson(ui->editCoefPoisson->text());
    CoeficienteExpansaoTermica(ui->editCoefExpansao->text());
    ModuloElasticidade(ui->editModuloElasticidade->text());
    PesoUnidade(ui->editPesoUnid->text());
    NomeFluido(ui->editNome->text());
    Densidade(ui->editDensidade->text());
    Viscosidade(ui->editViscosidade->text());
}

// Acao ao clicar em Cancelar
void CJanelaAdicionarTrechoTubulacao::on_btnReturn_rejected()
{
    close();
}
