#include "CSimuladorPoco.h"
#include "ui_CSimuladorPoco.h"
#include "janelaadicionarfluido.h"

#include <iostream>
#include <fstream>
#include <QApplication>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>

CSimuladorPoco::CSimuladorPoco(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CSimuladorPoco)
{
    ui->setupUi(this);
    std::vector<SecaoPoco> secoes = {
        {0.0f, 500.0f, 17.5f},
        {500.0f, 1500.0f, 12.25f},
        {1500.0f, 3000.0f, 8.5f}
    };

    // Chama a função desenharPoco no widget promovido
    CPocoGraphicsView *pocoView = qobject_cast<CPocoGraphicsView*>(ui->graphicsView);
    if (pocoView) {
        pocoView->desenharPoco(secoes);
    }
}

CSimuladorPoco::~CSimuladorPoco()
{
    delete ui;
}

void CSimuladorPoco::on_actionImportar_Dados_triggered()
{
    QString caminhoDoArquivo = QFileDialog::getOpenFileName(
        this, // Passa a janela principal como pai
        "Selecione um arquivo",
        "",
        "Todos os arquivos (*.*)"
        );

    // Converte o QString para std::string corretamente
    std::string caminhoDoArquivoStr = caminhoDoArquivo.toStdString();

    std::ifstream file(caminhoDoArquivoStr);

    std::string linha;
    bool lendoFluidos = false; // Começa lendo dados do poço

    while (std::getline(file, linha)) {
        // Ignorar linhas vazias ou comentários
        if (linha.empty() || linha[0] == '#') {
            if (linha.find("Fluidos") != std::string::npos) {
                lendoFluidos = true; // Mudar para leitura de fluidos
            }
            continue;
        }

        ui->tblFluidos->setEditTriggers(QAbstractItemView::NoEditTriggers);

        if (!lendoFluidos) {
            // Ler os dados do poço
            std::istringstream iss(linha);
            std::string nome;
            double profundidade, pressaoSuperficie, diametro, OD, ID, vazao;

            if (iss >> nome >> profundidade >> pressaoSuperficie >> diametro >> OD >> ID >> vazao) {
                poco = std::make_unique<CPoco>(nome, profundidade, pressaoSuperficie, diametro, OD, ID, vazao);
            }
        } else {
            // Ler os dados dos fluidos
            std::istringstream iss(linha);
            std::string nome;
            double densidade, viscosidade, profInicial, profFinal;

            if (iss >> nome >> densidade >> viscosidade >> profInicial >> profFinal) {
                auto fluido = std::make_unique<CFluido>(nome, densidade, viscosidade);
                auto trechoPoco = std::make_unique<CTrechoPoco>(profInicial, profFinal, std::move(fluido));
                if (!poco->AdicionarTrechoPoco(std::move(trechoPoco))) {
                }
            }
        }
    }

    file.close();
    on_btnAtualizarDados_clicked();
}



void CSimuladorPoco::on_btnAtualizarDados_clicked()
{
    if (poco){
        // Atualiza os valores dos QLineEdits com os dados do objeto poco
        ui->editNomePoco->setText(QString::fromStdString(poco->NomePoco()));       // Profundidade total do poço
        ui->editProfundidadeTotal->setText(QString::number(poco->ProfundidadeTotal()));       // Profundidade total do poço
        ui->lbnProfundidadeOcupada->setText(QString::number(poco->ProfundidadeOcupada())); // Profundidade ocupada
        ui->editPressaoSuperficie->setText(QString::number(poco->PressaoSuperficie()));           // Pressão na superfície
        ui->editDiametroPoco->setText(QString::number(poco->DiametroPoco()));              // Diâmetro do poço
        ui->editDiametroOD->setText(QString::number(poco->DiametroRevestimentoOD()));      // Diâmetro externo do revestimento (OD)
        ui->editDiametroID->setText(QString::number(poco->DiametroRevestimentoID()));      // Diâmetro interno do revestimento (ID)
        ui->editVazao->setText(QString::number(poco->Vazao()));                            // Vazão do fluido no poço
        ui->lbnDensidadeMedia->setText(QString::number(poco->DensidadeEfetivaTotal()));   // Densidade efetiva média dos fluidos
        ui->lbnViscosidadeMedia->setText(QString::number(poco->ViscosidadeEfetivaTotal())); // Viscosidade efetiva média dos fluidos

        // Atualizar QTableWidget com os dados dos trechos
        ui->tblFluidos->setRowCount(static_cast<int>(poco->Trechos().size()));

        int row = 0;
        for (const auto& trecho : poco->Trechos()) {
            ui->tblFluidos->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(trecho->Fluido()->Nome())));
            ui->tblFluidos->setItem(row, 1, new QTableWidgetItem(QString::number(trecho->Fluido()->Densidade(), 'f', 2)));
            ui->tblFluidos->setItem(row, 2, new QTableWidgetItem(QString::number(trecho->Fluido()->Viscosidade(), 'f', 2)));
            ui->tblFluidos->setItem(row, 3, new QTableWidgetItem(QString::number(trecho->ProfundidadeInicial(), 'f', 2)));
            ui->tblFluidos->setItem(row, 4, new QTableWidgetItem(QString::number(trecho->ProfundidadeFinal(), 'f', 2)));
           ++row;
        }
    }
}


void CSimuladorPoco::on_btnAdicionarPropriedades_clicked()
{
    std::string nome;
    double profundidade, pressaoSuperficie, diametro, OD, ID, vazao;

    QString text;

    text = ui->editNomePoco->text();
    nome = text.toStdString();
    text = ui->editProfundidadeTotal->text();
    profundidade = text.toDouble();
    text = ui->editPressaoSuperficie->text();
    pressaoSuperficie = text.toDouble();
    text = ui->editDiametroPoco->text();
    diametro = text.toDouble();
    text = ui->editDiametroOD->text();
    OD = text.toDouble();
    text = ui->editDiametroID->text();
    ID = text.toDouble();
    text = ui->editVazao->text();
    vazao = text.toDouble();

    if (poco) {
        QMessageBox::StandardButton resposta = QMessageBox::question(
            this,
            "",
            "Ao confirmar, todos os fluidos serão deletados! Tem certeza?",
            QMessageBox::Yes | QMessageBox::No
            );

        if (resposta == QMessageBox::Yes) {
            poco = std::make_shared<CPoco>(nome, profundidade, pressaoSuperficie, diametro, OD, ID, vazao);
        }
        on_btnAtualizarDados_clicked();
    } else {
        poco = std::make_shared<CPoco>(nome, profundidade, pressaoSuperficie, diametro, OD, ID, vazao);
    }
}


void CSimuladorPoco::on_btnAdicionarFluido_clicked()
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


void CSimuladorPoco::on_btnRemoverFluido_clicked()
{
    int linhaSelecionada = ui->tblFluidos->currentRow();

    if (linhaSelecionada >= 0) {

        QTableWidgetItem* item = ui->tblFluidos->item(linhaSelecionada, 0);

        if (item) {
            QString nomeFluido = item->text();
            ui->tblFluidos->removeRow(linhaSelecionada);
            poco->RemoverTrechoPoco(nomeFluido.toStdString());
            on_btnAtualizarDados_clicked();
        }

    } else {
        QMessageBox::warning(this, "Erro", "Selecione uma linha para deletar.");
    }
}



void CSimuladorPoco::on_btnCalcularPressaoHidroestatica_clicked()
{
    QString profundidadeStr = ui->editProfundidadePressaoHidroestatica->text();
    double profundidade = profundidadeStr.toDouble();

    ui->lbnPressaoHidroestatica->setText(QString::number(poco->PressaoHidroestaticaNoPonto(profundidade)));

}

void CSimuladorPoco::on_btnCalcularModeloNewtonianoPoco_clicked()
{
    modeloNewtoniano = std::make_shared<CModeloNewtoniano>(poco.get());

    ui->lbnVelocidadePocoNewtoniano->setText(QString::number(modeloNewtoniano->VMediaPoco()));
    ui->lbnReynoldsPocoNewtoniano->setText(QString::number(modeloNewtoniano->ReynoldsPoco()));
    ui->lbnTipoFluxoPocoNewtoniano->setText(QString::fromStdString(modeloNewtoniano->FluxoPoco()));
    ui->lbnPerdaFriccionalPocoNewtoniano->setText(QString::number(modeloNewtoniano->CalcularPerdaPorFriccaoPoco()));
}

void CSimuladorPoco::on_btnCalcularModeloNewtonianoAnular_clicked()
{
    modeloNewtoniano = std::make_shared<CModeloNewtoniano>(poco.get());

    ui->lbnVelocidadeAnularNewtoniano->setText(QString::number(modeloNewtoniano->VMediaAnular()));
    ui->lbnReynoldsAnularNewtoniano->setText(QString::number(modeloNewtoniano->ReynoldsAnular()));
    ui->lbnTipoFluxoAnularNewtoniano->setText(QString::fromStdString(modeloNewtoniano->FluxoAnular()));
    ui->lbnPerdaFriccionalAnularNewtoniano->setText(QString::number(modeloNewtoniano->CalcularPerdaPorFriccaoAnular()));
}





void CSimuladorPoco::on_btnCalcularModeloBighamPoco_clicked()
{
    if (ui->editPontoEscoamentoPoco->text().isEmpty() && ui->editViscosidadePlasticaPoco->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha o Ponto de Escoamento e a Viscosidade Plástica.");
    } else if (ui->editPontoEscoamentoPoco->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha o Ponto de Escoamento.");
    } else if (ui->editViscosidadePlasticaPoco->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha a Viscosidade Plástica.");
    } else {

        double pontoEscoamento = ui->editPontoEscoamentoPoco->text().toDouble();
        double viscosidadePlastica = ui->editViscosidadePlasticaPoco->text().toDouble();

        modeloBingham = std::make_shared<CModeloBingham>(poco.get(), viscosidadePlastica, pontoEscoamento);

        ui->lbnVelocidadePocoBigham->setText(QString::number(modeloBingham->VMediaPoco()));
        ui->lbnReynoldsPocoBigham->setText(QString::number(modeloBingham->ReynoldsPoco()));
        ui->lbnReynoldsHedstromPocoBigham->setText(QString::number(modeloBingham->ReynoldsHedstronPoco()));
        ui->lbnReynoldsCriticoPocoBigham->setText(QString::number(modeloBingham->ReynoldsCriticoPoco()));
        ui->lbnTipoFluxoPocoBigham->setText(QString::fromStdString(modeloBingham->FluxoPoco()));
        ui->lbnPerdaFriccionalPocoBigham->setText(QString::number(modeloBingham->CalcularPerdaPorFriccaoPoco()));
    }
}

//Informe o valor do pontoDeEscoamento [lbf/100 sq.ft]: 10
    //Informe o valor da viscosidade Plastica [cP]: 500

    //Velocidade no Poco: 1.28397 ft/s
        //Reynolds no Poco: 145.714
    //Reynolds Hedstrom no Poco: 643.355
    //Reynolds Critico no Poco: 2225.82
    //Tipo de Fluxo no Poco: Laminar
    //Perda Friccional no Poco: 0.00271893 psi/ft

void CSimuladorPoco::on_btnCalcularModeloBighamAnular_clicked()
{
    if (ui->editPontoEscoamentoAnular->text().isEmpty() && ui->editViscosidadePlasticaAnular->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha o Ponto de Escoamento e a Viscosidade Plástica.");
    } else if (ui->editPontoEscoamentoAnular->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha o Ponto de Escoamento.");
    } else if (ui->editViscosidadePlasticaAnular->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha a Viscosidade Plástica.");
    } else {

        double pontoEscoamento = ui->editPontoEscoamentoAnular->text().toDouble();
        double viscosidadePlastica = ui->editViscosidadePlasticaAnular->text().toDouble();

        modeloBingham = std::make_shared<CModeloBingham>(poco.get(), viscosidadePlastica, pontoEscoamento);

        ui->lbnVelocidadeAnularBigham->setText(QString::number(modeloBingham->VMediaAnular()));
        ui->lbnReynoldsAnularBigham->setText(QString::number(modeloBingham->ReynoldsAnular()));
        ui->lbnReynoldsHedstromAnularBigham->setText(QString::number(modeloBingham->ReynoldsHedstronAnular()));
        ui->lbnReynoldsCriticoAnularBigham->setText(QString::number(modeloBingham->ReynoldsCriticoAnular()));
        ui->lbnTipoFluxoAnularBigham->setText(QString::fromStdString(modeloBingham->FluxoAnular()));
        ui->lbnPerdaFriccionalAnularBigham->setText(QString::number(modeloBingham->CalcularPerdaPorFriccaoAnular()));
    }
}


void CSimuladorPoco::on_btnCalcularModeloPotenciaPoco_clicked()
{
    if (ui->editIndiceConsistenciaPotenciaPoco->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha o Indice de Consistência.");
    } else {

        double indiceConsistencia = ui->editIndiceConsistenciaPotenciaPoco->text().toDouble();

        modeloPotencia = std::make_shared<CModeloPotencia>(poco.get(), indiceConsistencia);

        ui->lbnVelocidadePocoPotencia->setText(QString::number(modeloPotencia->VMediaPoco()));
        ui->lbnReynoldsPocoPotencia->setText(QString::number(modeloPotencia->ReynoldsPoco()));
        ui->lbnReynoldsCriticoPocoPotencia->setText(QString::number(modeloPotencia->ReynoldsCriticoPoco()));
        ui->lbnTipoFluxoPocoPotencia->setText(QString::fromStdString(modeloPotencia->FluxoPoco()));
        ui->lbnPerdaFriccionalPocoPotencia->setText(QString::number(modeloPotencia->CalcularPerdaPorFriccaoPoco()));
    }
}


void CSimuladorPoco::on_btnCalcularModeloPotenciaAnular_clicked()
{
    if (ui->editIndiceConsistenciaPotenciaAnular->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha o Indice de Consistência.");
    } else {

        double indiceConsistencia = ui->editIndiceConsistenciaPotenciaAnular->text().toDouble();

        modeloPotencia = std::make_shared<CModeloPotencia>(poco.get(), indiceConsistencia);

        ui->lbnVelocidadeAnularPotencia->setText(QString::number(modeloPotencia->VMediaAnular()));
        ui->lbnReynoldsAnularPotencia->setText(QString::number(modeloPotencia->ReynoldsAnular()));
        ui->lbnReynoldsCriticoAnularPotencia->setText(QString::number(modeloPotencia->ReynoldsCriticoAnular()));
        ui->lbnTipoFluxoAnularPotencia->setText(QString::fromStdString(modeloPotencia->FluxoAnular()));
        ui->lbnPerdaFriccionalAnularPotencia->setText(QString::number(modeloPotencia->CalcularPerdaPorFriccaoAnular()));
    }
}

