#include "CSimuladorPocoTubos.h"
#include "ui_CSimuladorPocoTubos.h"

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
