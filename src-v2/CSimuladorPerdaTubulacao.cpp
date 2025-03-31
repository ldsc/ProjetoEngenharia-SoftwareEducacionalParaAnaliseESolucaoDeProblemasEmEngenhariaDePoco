#include "CSimuladorPerdaTubulacao.h"
#include "ui_CSimuladorPerdaTubulacao.h"

CSimuladorPerdaTubulacao::CSimuladorPerdaTubulacao(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CSimuladorPerdaTubulacao)
{
    ui->setupUi(this);
}

CSimuladorPerdaTubulacao::~CSimuladorPerdaTubulacao()
{
    delete ui;
}
