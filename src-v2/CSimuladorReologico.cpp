#include "CSimuladorReologico.h"
#include "ui_CSimuladorReologico.h"
#include "CJanelaAdicionarFluido.h"
#include "CJanelaGraficoPressaoHidroestatica.h"

#include <iostream>
#include <fstream>
#include <QApplication>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QMap>
#include <QColor>
#include <QDesktopServices>
#include <QUrl>

CSimuladorReologico::CSimuladorReologico(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CSimuladorReologico)
{
    ui->setupUi(this);

    CSimuladorReologico::makePlotPoco();

    ui->tblFluidos->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);

    // Conectar o sinal de alteração para chamar sua função AtualizarTabela
    connect(ui->tblFluidos, &QTableWidget::cellChanged,
            this, &CSimuladorReologico::EditarLinhaTabela);

    // Sinal para alterações das caixas
    connect(ui->editNomePoco, &QLineEdit::textChanged, this, &CSimuladorReologico::EditarDadosPoco);
    connect(ui->editProfundidadeTotal, &QLineEdit::textChanged, this, &CSimuladorReologico::EditarDadosPoco);
    connect(ui->editPressaoSuperficie, &QLineEdit::textChanged, this, &CSimuladorReologico::EditarDadosPoco);
    connect(ui->editDiametroPoco, &QLineEdit::textChanged, this, &CSimuladorReologico::EditarDadosPoco);
    connect(ui->editDiametroOD, &QLineEdit::textChanged, this, &CSimuladorReologico::EditarDadosPoco);
    connect(ui->editDiametroID, &QLineEdit::textChanged, this, &CSimuladorReologico::EditarDadosPoco);
    connect(ui->editVazao, &QLineEdit::textChanged, this, &CSimuladorReologico::EditarDadosPoco);

    // iniciar com botões desativado
    ui->btnCalcularPressaoHidroestatica->setEnabled(false);
    ui->btnCalcularModeloNewtonianoPoco->setEnabled(false);
    ui->btnCalcularModeloNewtonianoAnular->setEnabled(false);
    ui->btnCalcularModeloBighamPoco->setEnabled(false);
    ui->btnCalcularModeloBighamAnular->setEnabled(false);
    ui->btnCalcularModeloPotenciaPoco->setEnabled(false);
    ui->btnCalcularModeloPotenciaAnular->setEnabled(false);
    ui->btnExibirGraficoPressaoHidroestatica->setEnabled(false);


    //abrir janela no meio do monitor
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;

    this->move(x, y);
}

CSimuladorReologico::~CSimuladorReologico()
{
    delete ui;
}

void CSimuladorReologico::on_actionImportar_Dados_triggered()
{

}

void CSimuladorReologico::EditarDadosPoco() {
    QString nome = ui->editNomePoco->text();
    bool ok1, ok2, ok3, ok4, ok5, ok6;
    double profund  = ui->editProfundidadeTotal->text().toDouble(&ok1);
    double pressao  = ui->editPressaoSuperficie->text().toDouble(&ok2);
    double diametro = ui->editDiametroPoco->text().toDouble(&ok3);
    double OD       = ui->editDiametroOD->text().toDouble(&ok4);
    double ID       = ui->editDiametroID->text().toDouble(&ok5);
    double vazao    = ui->editVazao->text().toDouble(&ok6);

    if (!nome.isEmpty() && ok1 && ok2 && ok3 && ok4 && ok5 && ok6) {
        if (!poco) {
            // Cria o poço
            poco = std::make_unique<CPoco>(
                CPoco::CriarParaModulo01(nome.toStdString(), profund, pressao, diametro, OD, ID, vazao)
                );

            ui->btnCalcularPressaoHidroestatica->setEnabled(true);
            ui->btnCalcularModeloNewtonianoPoco->setEnabled(true);
            ui->btnCalcularModeloNewtonianoAnular->setEnabled(true);
            ui->btnCalcularModeloBighamPoco->setEnabled(true);
            ui->btnCalcularModeloBighamAnular->setEnabled(true);
            ui->btnCalcularModeloPotenciaPoco->setEnabled(true);
            ui->btnCalcularModeloPotenciaAnular->setEnabled(true);
            ui->btnExibirGraficoPressaoHidroestatica->setEnabled(true);

            ui->statusbar->showMessage("Poço criado com Sucesso!");
        } else {
            // Atualiza dados do poço já existente
            poco->NomePoco(nome.toStdString());
            poco->ProfundidadeTotal(profund);
            poco->PressaoSuperficie(pressao);
            poco->DiametroPoco(diametro);
            poco->DiametroRevestimentoOD(OD);
            poco->DiametroRevestimentoID(ID);
            poco->Vazao(vazao);
            ui->statusbar->showMessage("Dados de Poço Atualizado com Sucesso!");
        }

        AtualizarDados();  // Atualiza os dados calculados e a interface
    }
}


void CSimuladorReologico::EditarLinhaTabela(int row, int column)
{
    QString nomeAlvo = ui->tblFluidos->item(row, 0)->text();
    std::vector<CTrechoPoco*> trechos = poco->Trechos();

    for (CTrechoPoco* trecho : trechos) {
        CFluido* fluido = trecho->Fluido();
        if (fluido && QString::fromStdString(fluido->Nome()) == nomeAlvo) {
            // Atualiza os dados do fluido
            fluido->Nome(ui->tblFluidos->item(row, 0)->text().toStdString());
            fluido->Densidade(ui->tblFluidos->item(row, 1)->text().toDouble());
            fluido->Viscosidade(ui->tblFluidos->item(row, 2)->text().toDouble());

            // Atualiza profundidades
            trecho->ProfundidadeInicial(ui->tblFluidos->item(row, 3)->text().toDouble());
            trecho->ProfundidadeFinal(ui->tblFluidos->item(row, 4)->text().toDouble());

            break; // encontrou e atualizou
        }
    }
    AtualizarDados();
    ui->statusbar->showMessage("Dados de Fluido Atualizado com Sucesso!");
}

void CSimuladorReologico::AtualizarDados()
{

    ui->tblFluidos->blockSignals(true);

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

           makePlotPoco();
        }
    }

    ui->tblFluidos->blockSignals(false);
}


void CSimuladorReologico::on_btnAdicionarFluido_clicked()
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

            AtualizarDados();
            ui->statusbar->showMessage("Fluido Adicionado com Sucesso!");
        }
    }
}


void CSimuladorReologico::on_btnRemoverFluido_clicked()
{
    int linhaSelecionada = ui->tblFluidos->currentRow();

    if (linhaSelecionada >= 0) {

        QTableWidgetItem* item = ui->tblFluidos->item(linhaSelecionada, 0);

        if (item) {
            QMessageBox::StandardButton resposta = QMessageBox::question(
                this,
                "",
                "Tem certeza que deseja remover o fluido?",
                QMessageBox::Yes | QMessageBox::No
                );

            if (resposta == QMessageBox::Yes) {
                QString nomeFluido = item->text();
                ui->tblFluidos->removeRow(linhaSelecionada);
                poco->RemoverTrechoPoco(nomeFluido.toStdString());
                AtualizarDados();
                ui->statusbar->showMessage("Fluido Removido com Sucesso!");
            }

        }

    } else {
        QMessageBox::warning(this, "Erro", "Selecione uma linha para deletar.");
    }
}



void CSimuladorReologico::on_btnCalcularPressaoHidroestatica_clicked()
{
    QString profundidadeStr = ui->editProfundidadePressaoHidroestatica->text();
    double profundidade = profundidadeStr.toDouble();

    ui->lbnPressaoHidroestatica->setText(QString::number(poco->PressaoHidroestaticaNoPonto(profundidade)));

}

void CSimuladorReologico::on_btnCalcularModeloNewtonianoPoco_clicked()
{
    modeloNewtoniano = std::make_shared<CModeloNewtoniano>(poco.get());

    ui->lbnVelocidadePocoNewtoniano->setText(QString::number(modeloNewtoniano->VMediaPoco()));
    ui->lbnReynoldsPocoNewtoniano->setText(QString::number(modeloNewtoniano->ReynoldsPoco()));
    ui->lbnTipoFluxoPocoNewtoniano->setText(QString::fromStdString(modeloNewtoniano->FluxoPoco()));
    ui->lbnPerdaFriccionalPocoNewtoniano->setText(QString::number(modeloNewtoniano->CalcularPerdaPorFriccaoPoco()));
}

void CSimuladorReologico::on_btnCalcularModeloNewtonianoAnular_clicked()
{
    modeloNewtoniano = std::make_shared<CModeloNewtoniano>(poco.get());

    ui->lbnVelocidadeAnularNewtoniano->setText(QString::number(modeloNewtoniano->VMediaAnular()));
    ui->lbnReynoldsAnularNewtoniano->setText(QString::number(modeloNewtoniano->ReynoldsAnular()));
    ui->lbnTipoFluxoAnularNewtoniano->setText(QString::fromStdString(modeloNewtoniano->FluxoAnular()));
    ui->lbnPerdaFriccionalAnularNewtoniano->setText(QString::number(modeloNewtoniano->CalcularPerdaPorFriccaoAnular()));
}


void CSimuladorReologico::on_btnCalcularModeloBighamPoco_clicked()
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

void CSimuladorReologico::on_btnCalcularModeloBighamAnular_clicked()
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


void CSimuladorReologico::on_btnCalcularModeloPotenciaPoco_clicked()
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


void CSimuladorReologico::on_btnCalcularModeloPotenciaAnular_clicked()
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

void CSimuladorReologico::makePlotPoco()
{
    // Limpar o gráfico anterior
    ui->customPlotPoco->clearItems();

    // Configurar os eixos
    ui->customPlotPoco->xAxis->setLabel("Diâmetro do Poço (m)");
    ui->customPlotPoco->yAxis->setLabel("Profundidade (m)");

    ui->customPlotPoco->xAxis->setRange(-10, 10);  // Simulação da largura do poço
    ui->customPlotPoco->yAxis->setRange(0, 300);   // Profundidade máxima do poço (ajustável)
    ui->customPlotPoco->yAxis->setRangeReversed(true); // Profundidade cresce para baixo

    // Verifica se o poço está configurado
    if (!poco || poco->Trechos().empty()) {
        return;
    }

    // Determinar profundidade máxima real
    double profundidadeMaxima = 0.0;
    for (const auto& trecho : poco->Trechos()) {
        if (trecho->ProfundidadeFinal() > profundidadeMaxima) {
            profundidadeMaxima = trecho->ProfundidadeFinal();
        }
    }
    ui->customPlotPoco->yAxis->setRange(0, profundidadeMaxima);

    // Mapa para armazenar cores únicas por fluido
    QMap<QString, QColor> mapaCores;
    QVector<QColor> coresDisponiveis = {
        QColor(255, 0, 0, 150),    // Vermelho translúcido
        QColor(0, 255, 0, 150),    // Verde translúcido
        QColor(0, 0, 255, 150),    // Azul translúcido
        QColor(255, 165, 0, 150),  // Laranja translúcido
        QColor(128, 0, 128, 150),  // Roxo translúcido
        QColor(0, 255, 255, 150)   // Ciano translúcido
    };
    int corIndex = 0;

    // Criar os retângulos para cada seção do poço
    for (const auto& trecho : poco->Trechos()) {
        double profundidadeInicial = trecho->ProfundidadeInicial();
        double profundidadeFinal = trecho->ProfundidadeFinal();
        double diametroPoco = 8.0;   // Supondo um diâmetro fixo do poço
        double diametroSecao = 6.0;  // Supondo um diâmetro da seção menor que o do poço
        QString nomeFluido = QString::fromStdString(trecho->Fluido()->Nome());

        // Definir cor única para cada fluido
        if (!mapaCores.contains(nomeFluido)) {
            mapaCores[nomeFluido] = coresDisponiveis[corIndex % coresDisponiveis.size()];
            corIndex++;
        }
        QColor corFluido = mapaCores[nomeFluido];

        // Criar retângulo do poço (cinza translúcido)
        QCPItemRect *rectPoco = new QCPItemRect(ui->customPlotPoco);
        rectPoco->topLeft->setCoords(-diametroPoco / 2, profundidadeInicial);
        rectPoco->bottomRight->setCoords(diametroPoco / 2, profundidadeFinal);
        rectPoco->setPen(QPen(Qt::black));
        rectPoco->setBrush(QBrush(QColor(150, 150, 150, 100))); // Cinza translúcido

        // Criar retângulo da seção (fluido)
        QCPItemRect *rectSecao = new QCPItemRect(ui->customPlotPoco);
        rectSecao->topLeft->setCoords(-diametroSecao / 2, profundidadeInicial);
        rectSecao->bottomRight->setCoords(diametroSecao / 2, profundidadeFinal);
        rectSecao->setPen(QPen(Qt::black));
        rectSecao->setBrush(QBrush(corFluido)); // Cor do fluido

        // Criar rótulo do fluido dentro do retângulo
        QCPItemText *textLabel = new QCPItemText(ui->customPlotPoco);
        textLabel->position->setCoords(0, (profundidadeInicial + profundidadeFinal) / 2); // Centralizado
        textLabel->setText(nomeFluido);
        textLabel->setFont(QFont("Arial", 10, QFont::Bold));
        textLabel->setColor(Qt::black);
        textLabel->setPositionAlignment(Qt::AlignCenter);
    }

    // Atualizar o gráfico
    ui->customPlotPoco->replot();
}

void CSimuladorReologico::on_actionNova_Simula_o_triggered()
{
    QMessageBox::StandardButton resposta = QMessageBox::question(
        this,
        "",
        "Tem certeza que deseja iniciar uma nova simulação?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (resposta == QMessageBox::Yes) {
        CSimuladorReologico *newWindow = new CSimuladorReologico();
        newWindow->show();
        this->close();
    }
}


void CSimuladorReologico::on_actionExportar_como_Imagem_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Salvar imagem", "", "PNG (*.png);;JPEG (*.jpg)");

    if (!fileName.isEmpty()) {
        QPixmap pixmap = this->grab();
        pixmap.save(fileName);
    }
}


void CSimuladorReologico::on_actionSobre_o_Programa_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/ldsc/ProjetoEngenharia-SoftwareEducacionalParaAnaliseESolucaoDeProblemasEmEngenhariaDePoco"));
}


void CSimuladorReologico::on_actionSalvar_Como_triggered()
{
    QString caminho = QFileDialog::getSaveFileName(this, "Salvar Arquivo", "", "Arquivo DAT (*.dat)");
    if (caminho.isEmpty()) return;

    QFile arquivo(caminho);
    if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Erro", "Não foi possível salvar o arquivo.");
        return;
    }

    QTextStream out(&arquivo);

    // Dados do Poço
    out << "# Configuração do Poço------------------------------------------------------------------------------------\n";
    out << "# Nome                 Profundidade (ft)    Pressão Superficial (psi)    Diâmetro (in)    OD (in)    ID (in)    Vazão (bbl/d)\n";
    out << ui->editNomePoco->text() << "           ";
    out << ui->editProfundidadeTotal->text() << "                ";
    out << ui->editPressaoSuperficie->text() << "                         ";
    out << ui->editDiametroPoco->text() << "             ";
    out << ui->editDiametroOD->text() << "       ";
    out << ui->editDiametroID->text() << "       ";
    out << ui->editVazao->text() << "       ";

    // Dados dos Fluidos (pega da tabela)
    out << "\n\n\n# Configuração dos Fluidos--------------------------------------------------------------------------------\n";
    out << "# Nome       Densidade (lbm/gal)    Viscosidade (cP)    Prof. Inicial (ft)    Prof. Final (ft)\n";
    int linhas = ui->tblFluidos->rowCount();
    for (int i = 0; i < linhas; ++i) {
        QString nome = ui->tblFluidos->item(i, 0)->text();
        QString densidade = ui->tblFluidos->item(i, 1)->text();
        QString viscosidade = ui->tblFluidos->item(i, 2)->text();
        QString profIni = ui->tblFluidos->item(i, 3)->text();
        QString profFim = ui->tblFluidos->item(i, 4)->text();

        out << nome << "        " << densidade << "                    " << viscosidade << "                 " << profIni << "                  " << profFim << "\n";
    }

    arquivo.close();
    QMessageBox::information(this, "Salvo", "Arquivo salvo com sucesso!");
}


void CSimuladorReologico::on_actionExcel_triggered()
{

}


void CSimuladorReologico::on_actionArquivo_dat_triggered()
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
            std::string nome;
            double profundidade, pressaoSuperficie, diametro, OD, ID, vazao;

            if (iss >> nome >> profundidade >> pressaoSuperficie >> diametro >> OD >> ID >> vazao) {

                ui->btnCalcularPressaoHidroestatica->setEnabled(true);
                ui->btnCalcularModeloNewtonianoPoco->setEnabled(true);
                ui->btnCalcularModeloNewtonianoAnular->setEnabled(true);
                ui->btnCalcularModeloBighamPoco->setEnabled(true);
                ui->btnCalcularModeloBighamAnular->setEnabled(true);
                ui->btnCalcularModeloPotenciaPoco->setEnabled(true);
                ui->btnCalcularModeloPotenciaAnular->setEnabled(true);
                ui->btnExibirGraficoPressaoHidroestatica->setEnabled(true);

                poco = std::make_unique<CPoco>(
                    CPoco::CriarParaModulo01(nome, profundidade, pressaoSuperficie, diametro, OD, ID, vazao)
                    );
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
    AtualizarDados();
    ui->statusbar->showMessage("Dados Importado com Sucesso!");
}


void CSimuladorReologico::on_btnExibirGraficoPressaoHidroestatica_clicked()
{
    CJanelaGraficoPressaoHidroestatica grafico(poco->PlotarProfundidadePorPressaoMedia());
    grafico.exec();
    ui->statusbar->showMessage("Dados Plotador com Sucesso!");
}

