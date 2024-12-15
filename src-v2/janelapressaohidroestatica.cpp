#include "janelapressaohidroestatica.h"
#include "ui_janelapressaohidroestatica.h"
#include <QMessageBox>

janelapressaohidroestatica::janelapressaohidroestatica(std::shared_ptr<CPoco> poco, QWidget *parent)
    : QDialog(parent), // Inicializa a classe base QDialog
    ui(new Ui::janelapressaohidroestatica), copiaPoco(poco){

    ui->setupUi(this);
}

janelapressaohidroestatica::~janelapressaohidroestatica()
{
    delete ui;
}

void janelapressaohidroestatica::on_bntCalcularPressaoHidroestatica_clicked()
{
    if(ui->lnValorProfundidade->text() == ""){
        QMessageBox::warning(this, "Erro", "Por favor, informe um valor de profundidade!");
    }
    else{
        double profundidade = ui->lnValorProfundidade->text().toDouble();
        double PressaoHidro = copiaPoco->PressaoHidroestaticaNoPonto(profundidade);
        ui->lbnValorPressao->setText(QString::number(PressaoHidro));
    }
}

