#include "janelapressaohidroestatica.h"
#include "ui_janelapressaohidroestatica.h"

janelapressaohidroestatica::janelapressaohidroestatica(std::unique_ptr<CPoco> poco, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::janelapressaohidroestatica),
    m_poco(std::move(poco)) // Move o unique_ptr para m_poco
{
    ui->setupUi(this);
}

janelapressaohidroestatica::~janelapressaohidroestatica()
{
    delete ui;
}

void janelapressaohidroestatica::on_bntCalcularPressaoHidroestatica_clicked()
{
    double profundidade = ui->lnValorProfundidade->text().toDouble();
    double PressaoHidro = m_poco->PressaoHidroestaticaNoPonto(profundidade);
     ui->lbnValorPressao->setText(QString::number(PressaoHidro));
}

