#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "janelaexibirdados.h"

#include <QApplication>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>

#include "CSimuladorPoco.h"

CSimuladorPoco simulador;

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

void MainWindow::on_BntImportarDados_clicked()
{
    QString caminhoDoArquivo = QFileDialog::getOpenFileName(
        this, // Passa a janela principal como pai
        "Selecione um arquivo",
        "",
        "Todos os arquivos (*.*)"
        );

    if (!caminhoDoArquivo.isEmpty()) {

        QMessageBox::information(
            nullptr, // Ponteiro para a janela pai (opcional)
            "Sucesso", // Título da caixa de diálogo
            "Dados importados com sucesso!" // Mensagem a ser exibida
            );
        // Faça algo com o caminho do arquivo, como exibir em um QLabel
        //ui->label->setText(caminhoDoArquivo);
    }

    simulador.ConfigurarPorArquivo(caminhoDoArquivo.toStdString());
}




void MainWindow::on_BntExibirDados_clicked()
{
    double profundTotal = 12;

    janelaExibirDados janelaDados;

    janelaDados.coletarPropriedade(profundTotal);

    janelaDados.exec();



}

