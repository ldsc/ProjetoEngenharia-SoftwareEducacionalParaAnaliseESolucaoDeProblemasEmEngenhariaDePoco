#include "CSimuladorPerdaTubulacao.h"
#include "ui_CSimuladorPerdaTubulacao.h"
#include "CJanelaAdicionarFluido.h"

CSimuladorPerdaTubulacao::CSimuladorPerdaTubulacao(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CSimuladorPerdaTubulacao)
{
    ui->setupUi(this);

    // Inicialmente, desativa o lineEdit
    ui->editProfundidadePacker->setEnabled(false);

    // Conecta o sinal stateChanged do checkBox à função lambda
    connect(ui->checkBoxPacker, &QCheckBox::checkStateChanged, this, [=](int state){
        ui->editProfundidadePacker->setEnabled(state == Qt::Checked);
        });
}

CSimuladorPerdaTubulacao::~CSimuladorPerdaTubulacao()
{
    delete ui;
}

void CSimuladorPerdaTubulacao::on_btnAdicionarPropriedades_clicked()
{
    std::string nome;
    double profundidade, temperaturaSuperiorInicial, temperaturaFundoInicial, temperaturaSuperiorFinal, temperaturaFundoFinal, ProfundidadePacker;

    QString text;

    text = ui->editNomePoco->text();
    nome = text.toStdString();
    text = ui->editProfundidadeTotal->text();
    profundidade = text.toDouble();
    text = ui->editTemperaturaSuperiorInicial->text();
    temperaturaSuperiorInicial = text.toDouble();
    text = ui->editTemperaturaFundoInicial->text();
    temperaturaFundoInicial = text.toDouble();
    text = ui->editTemperaturaSuperiorFinal->text();
    temperaturaSuperiorFinal = text.toDouble();
    text = ui->lbnTituloTemperaturaFundoFinal->text();
    temperaturaFundoFinal = text.toDouble();
    text = ui->lbnTituloProfundidadePacker->text();
    ProfundidadePacker = text.toDouble();

    if (poco) {
        QMessageBox::StandardButton resposta = QMessageBox::question(
            this,
            "",
            "Ao confirmar, todos os fluidos serão deletados! Tem certeza?",
            QMessageBox::Yes | QMessageBox::No
            );

        if (resposta == QMessageBox::Yes) {
            poco = std::make_shared<CPoco>(nome, profundidade, temperaturaSuperiorInicial, temperaturaFundoInicial, temperaturaSuperiorFinal, temperaturaFundoFinal);
        }
        on_btnAtualizarDados_clicked();
    } else {
        poco = std::make_shared<CPoco>(nome, profundidade, temperaturaSuperiorInicial, temperaturaFundoInicial, temperaturaSuperiorFinal, temperaturaFundoFinal);
    }
}

void CSimuladorPerdaTubulacao::on_btnAdicionarFluido_clicked()
{
    ui->tblFluidos->setEditTriggers(QAbstractItemView::NoEditTriggers);

    if (!poco) {
        QMessageBox::warning(this, "Erro", "As propriedade do poço precisa está preenchida!");
    }

    else{
        janelaadicionarfluido JanelaFluido;
        JanelaFluido.exec();

        if (JanelaFluido.getNomeFluido() != "" &&
            JanelaFluido.getDensidade() != "" &&
            JanelaFluido.getViscosidade() != "" &&
            JanelaFluido.getProfunidadeInicial() != "" &&
            JanelaFluido.getProfunidadeFinal() != ""){

            int numLinhas = ui->tblFluidos->rowCount();
            ui->tblFluidos->insertRow(numLinhas);
            ui->tblFluidos->setItem(numLinhas, 0, new QTableWidgetItem(JanelaFluido.getNomeFluido()));
            ui->tblFluidos->setItem(numLinhas, 1, new QTableWidgetItem(JanelaFluido.getDensidade()));
            ui->tblFluidos->setItem(numLinhas, 2, new QTableWidgetItem(JanelaFluido.getViscosidade()));
            ui->tblFluidos->setItem(numLinhas, 3, new QTableWidgetItem(JanelaFluido.getProfunidadeInicial()));
            ui->tblFluidos->setItem(numLinhas, 4, new QTableWidgetItem(JanelaFluido.getProfunidadeFinal()));

            std::string nome = JanelaFluido.getNomeFluido().toStdString();
            double densidade = JanelaFluido.getDensidade().toDouble();
            double viscosidade = JanelaFluido.getViscosidade().toDouble();
            double profundInicial = JanelaFluido.getProfunidadeInicial().toDouble();
            double profundFinal = JanelaFluido.getProfunidadeFinal().toDouble();

            auto fluido = std::make_unique<CFluido>(nome, densidade, viscosidade);
            auto trechoPoco = std::make_unique<CTrechoPoco>(profundInicial, profundFinal, std::move(fluido));
            poco->AdicionarTrechoPoco(std::move(trechoPoco));

            on_btnAtualizarDados_clicked();
        }
    }
}


void CSimuladorPerdaTubulacao::on_btnAtualizarDados_clicked()
{

}

