#include "CJanelaAdicionarTrechoTubulacao.h"
#include "ui_CJanelaAdicionarTrechoTubulacao.h"

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
