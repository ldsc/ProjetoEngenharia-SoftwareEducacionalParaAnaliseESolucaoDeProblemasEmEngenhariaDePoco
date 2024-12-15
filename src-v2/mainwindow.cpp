#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "janelapressaohidroestatica.h"
#include "janelaadicionarfluido.h"

#include <iostream>
#include <fstream>
#include <QApplication>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btnAdicionarPropriedades_clicked()
{
    double profundidade, pressaoSuperficie, diametro, OD, ID, vazao;

    QString text;

    text = ui->lnValorProfundidadePoco->text();
    profundidade = text.toDouble();
    text = ui->lnValorPressaoSup->text();
    pressaoSuperficie = text.toDouble();
    text = ui->lnValorDiametroPoco->text();
    diametro = text.toDouble();
    text = ui->lnValorDiametroOD->text();
    OD = text.toDouble();
    text = ui->lnValorDiametroID->text();
    ID = text.toDouble();
    text = ui->lnValorVazao->text();
    vazao = text.toDouble();

    if (poco) {
        QMessageBox::StandardButton resposta = QMessageBox::question(
            this,
            "",
            "Ao confirmar, todos os fluidos serão deletados! Tem certeza?",
            QMessageBox::Yes | QMessageBox::No
            );

        if (resposta == QMessageBox::Yes) {
            poco = std::make_unique<CPoco>(profundidade, pressaoSuperficie, diametro, OD, ID, vazao);
        }
        on_btnAtualizar_clicked();
    } else {
        poco = std::make_unique<CPoco>(profundidade, pressaoSuperficie, diametro, OD, ID, vazao);
    }
}


void MainWindow::on_btnPressaoHidroesttica_clicked()
{
    //janelapressaohidroestatica janelaPressaoHidro(poco);
    //janelaPressaoHidro.exec();
}

void MainWindow::on_btnLimparPropriedadesPoco_clicked()
{
    ui->lnValorProfundidadePoco->clear();
    ui->lnValorPressaoSup->clear();
    ui->lnValorDiametroPoco->clear();
    ui->lnValorDiametroOD->clear();
    ui->lnValorDiametroID->clear();
    ui->lnValorVazao->clear();

    on_btnAdicionarPropriedades_clicked();
}


void MainWindow::on_btnAdicionarFluido_clicked()
{
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

        if (!poco){
            on_btnAdicionarPropriedades_clicked();
        }

        auto fluido = std::make_unique<CFluido>(nome, densidade, viscosidade);
        auto trechoPoco = std::make_unique<CTrechoPoco>(profundInicial, profundFinal, std::move(fluido));
        poco->AdicionarTrechoPoco(std::move(trechoPoco));
    }
}


void MainWindow::on_actionImportar_Dados_triggered()
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

        if (!lendoFluidos) {
            // Ler os dados do poço
            std::istringstream iss(linha);
            double profundidade, pressaoSuperficie, diametro, OD, ID, vazao;

            if (iss >> profundidade >> pressaoSuperficie >> diametro >> OD >> ID >> vazao) {
                poco = std::make_unique<CPoco>(profundidade, pressaoSuperficie, diametro, OD, ID, vazao);
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
                    std::cerr << "Erro ao adicionar trecho ao poço!" << std::endl;
                }
            } else {
                std::cerr << "Erro ao ler linha de fluido: " << linha << std::endl;
            }
        }
    }

    file.close();
    on_btnAtualizar_clicked();
}


void MainWindow::on_bntRemoverFluido_clicked()
{
    int linhaSelecionada = ui->tblFluidos->currentRow();

    if (linhaSelecionada >= 0) {
        ui->tblFluidos->removeRow(linhaSelecionada);
    } else {
        QMessageBox::warning(this, "Erro", "Selecione uma linha para deletar.");
    }
}


void MainWindow::on_actionSobre_o_Simulador_triggered()
{

}


void MainWindow::on_btnAtualizar_clicked()
{
    // Atualiza os valores dos QLineEdits com os dados do objeto poco
    ui->lnValorProfundidadePoco->setText(QString::number(poco->ProfundidadeTotal()));       // Profundidade total do poço
    ui->lbnValorProfundidadeOcupada->setText(QString::number(poco->ProfundidadeOcupada())); // Profundidade ocupada
    ui->lnValorPressaoSup->setText(QString::number(poco->PressaoSuperficie()));           // Pressão na superfície
    ui->lnValorDiametroPoco->setText(QString::number(poco->DiametroPoco()));              // Diâmetro do poço
    ui->lnValorDiametroOD->setText(QString::number(poco->DiametroRevestimentoOD()));      // Diâmetro externo do revestimento (OD)
    ui->lnValorDiametroID->setText(QString::number(poco->DiametroRevestimentoID()));      // Diâmetro interno do revestimento (ID)
    ui->lnValorVazao->setText(QString::number(poco->Vazao()));                            // Vazão do fluido no poço
    ui->lbnValorDensidadeMedia->setText(QString::number(poco->DensidadeEfetivaTotal()));   // Densidade efetiva média dos fluidos
    ui->lbnValorViscosidadeMedia->setText(QString::number(poco->ViscosidadeEfetivaTotal())); // Viscosidade efetiva média dos fluidos

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

