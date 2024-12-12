#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::ExibirDadosPoco()
{
    // Atualiza os valores dos QLineEdits com os dados do objeto poco
    ui->lnValorProfundidadePoco->setText(QString::number(poco->ProfundidadeTotal()));       // Profundidade total do poço
    ui->lnValorProfundidadeOcupada->setText(QString::number(poco->ProfundidadeOcupada())); // Profundidade ocupada
    ui->lnValorPressaoSup->setText(QString::number(poco->PressaoSuperficie()));           // Pressão na superfície
    ui->lnValorDiametroPoco->setText(QString::number(poco->DiametroPoco()));              // Diâmetro do poço
    ui->lnValorDiametroOD->setText(QString::number(poco->DiametroRevestimentoOD()));      // Diâmetro externo do revestimento (OD)
    ui->lnValorDiametroID->setText(QString::number(poco->DiametroRevestimentoID()));      // Diâmetro interno do revestimento (ID)
    ui->lnValorVazao->setText(QString::number(poco->Vazao()));                            // Vazão do fluido no poço
    ui->lnValorDensidadeMedia->setText(QString::number(poco->DensidadeEfetivaTotal()));   // Densidade efetiva média dos fluidos
    ui->lnValorViscosidadeMedia->setText(QString::number(poco->ViscosidadeEfetivaTotal())); // Viscosidade efetiva média dos fluidos

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

void MainWindow::on_BntImportarDados_clicked()
{
    QString caminhoDoArquivo = QFileDialog::getOpenFileName(
        this, // Passa a janela principal como pai
        "Selecione um arquivo",
        "",
        "Todos os arquivos (*.*)"
        );

    // Converte o QString para std::string corretamente
    std::string caminhoDoArquivoStr = caminhoDoArquivo.toStdString();

    // Abre o arquivo com std::ifstream
    std::ifstream inputFile(caminhoDoArquivoStr);

    if (!inputFile.is_open()) {
        QMessageBox::information(
            nullptr, "Erro", "Não Foi Possível Abrir o Arquivo!");
    }
    return;

    std::string linha;
    bool lendoFluidos = false; // Começa lendo dados do poço

    while (std::getline(inputFile, linha)) {
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
            }
        }
    }
    inputFile.close();
    ExibirDadosPoco();
}






