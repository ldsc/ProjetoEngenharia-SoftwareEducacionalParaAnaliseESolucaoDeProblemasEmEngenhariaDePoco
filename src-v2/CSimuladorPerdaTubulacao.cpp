#include "CSimuladorPerdaTubulacao.h"
#include "ui_CSimuladorPerdaTubulacao.h"

CSimuladorPocoTubos::CSimuladorPocoTubos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CSimuladorPocoTubos)
{
    ui->setupUi(this);
}

CSimuladorPocoTubos::~CSimuladorPocoTubos()
{
    delete ui;
}
