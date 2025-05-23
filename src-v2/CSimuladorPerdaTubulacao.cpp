#include "CSimuladorPerdaTubulacao.h"
#include "ui_CSimuladorPerdaTubulacao.h"
#include "CJanelaAdicionarFluido.h"
#include "CJanelaAdicionarTrechoTubulacao.h"
#include "CJanelaSobreSoftware.h"

#include <iostream>   // para std::cerr e std::endl
#include <fstream>    // para std::ifstream
#include <sstream>

CSimuladorPerdaTubulacao::CSimuladorPerdaTubulacao(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CSimuladorPerdaTubulacao)
{
    ui->setupUi(this);

    // Inicialmente, desativa o lineEdit
    ui->editProfundidadePacker->setEnabled(false);

    // Conecta o sinal stateChanged do checkBox à função lambda
    connect(ui->checkBoxPacker, &QCheckBox::stateChanged, this, [=](int state){
        ui->editProfundidadePacker->setEnabled(state == Qt::Checked);
    });

    // Sinal para alterações das caixas
    connect(ui->editNomePoco, &QLineEdit::textChanged, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->editProfundidadeTotal, &QLineEdit::textChanged, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->editPressaoSup, &QLineEdit::textChanged, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->editTemperaturaSuperiorInicial, &QLineEdit::textChanged, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->editTemperaturaFundoInicial, &QLineEdit::textChanged, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->editTemperaturaSuperiorFinal, &QLineEdit::textChanged, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->editTemperaturaFundoFinal, &QLineEdit::textChanged, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->editProfundidadePacker, &QLineEdit::textChanged, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);

    // iniciar com botões desativado
    ui->btnAdicionarTrecho->setEnabled(false);
    ui->btnRemoverTrecho->setEnabled(false);
    ui->btnCalcularVariacoes->setEnabled(false);

    //abrir janela no meio do monitor
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;

    this->move(x, y);

    makePlotPoco();
}

CSimuladorPerdaTubulacao::~CSimuladorPerdaTubulacao()
{
    delete ui;
}

void CSimuladorPerdaTubulacao::EditarDadosPoco() {
    QString nome = ui->editNomePoco->text();
    bool ok1, ok2, ok3, ok4, ok5, ok6, ok7;
    double profund  = ui->editProfundidadeTotal->text().toDouble(&ok1);
    double pressao  = ui->editPressaoSup->text().toDouble(&ok2);
    double temperaturaSuperiorInicial = ui->editTemperaturaSuperiorInicial->text().toDouble(&ok3);
    double temperaturaFundoInicial = ui->editTemperaturaFundoInicial->text().toDouble(&ok4);
    double temperaturaSuperiorFinal = ui->editTemperaturaSuperiorFinal->text().toDouble(&ok5);
    double temperaturaFundoFinal = ui->editTemperaturaFundoFinal->text().toDouble(&ok6);
    double profundPacker = ui->editProfundidadePacker->text().toDouble(&ok7);

    if (!nome.isEmpty() && ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7) {
        if (!poco) {
            // Cria o poço
            poco = std::make_unique<CObjetoPoco>(
                CObjetoPoco::CriarParaModulo02(nome.toStdString(), profund, pressao, temperaturaSuperiorInicial, temperaturaFundoInicial, temperaturaSuperiorFinal, temperaturaFundoFinal, profundPacker)
                );

            ui->btnAdicionarTrecho->setEnabled(true);
            ui->btnRemoverTrecho->setEnabled(true);
            ui->btnCalcularVariacoes->setEnabled(true);

            ui->statusbar->showMessage("Poço criado com Sucesso!");
        } else {
            // Atualiza dados do poço já existente
            poco->NomePoco(nome.toStdString());
            poco->ProfundidadeTotal(profund);
            poco->PressaoSuperficie(pressao);
            poco->TemperaturaTopoInicial(temperaturaSuperiorInicial);
            poco->TemperaturaFundoInicial(temperaturaFundoInicial);
            poco->TemperaturaTopoFinal(temperaturaSuperiorFinal);
            poco->TemperaturaFundoFinal(temperaturaFundoFinal);
            poco->ProfundidadePacker(profundPacker);
            ui->statusbar->showMessage("Dados de Poço Atualizado com Sucesso!");
        }

        on_btnAtualizarDados_clicked();  // Atualiza os dados calculados e a interface
    }
}

void CSimuladorPerdaTubulacao::on_btnAdicionarPropriedades_clicked()
{
    std::string nome;
    double profundidade, pressaoSup, temperaturaSuperiorInicial, temperaturaFundoInicial, temperaturaSuperiorFinal, temperaturaFundoFinal, ProfundidadePacker;

    QString text;

    text = ui->editNomePoco->text();
    nome = text.toStdString();
    text = ui->editPressaoSup->text();
    pressaoSup = text.toDouble();
    text = ui->editProfundidadeTotal->text();
    profundidade = text.toDouble();
    text = ui->editTemperaturaSuperiorInicial->text();
    temperaturaSuperiorInicial = text.toDouble();
    text = ui->editTemperaturaFundoInicial->text();
    temperaturaFundoInicial = text.toDouble();
    text = ui->editTemperaturaSuperiorFinal->text();
    temperaturaSuperiorFinal = text.toDouble();
    text = ui->editTemperaturaFundoFinal->text();
    temperaturaFundoFinal = text.toDouble();
    text = ui->editProfundidadePacker->text();
    ProfundidadePacker = text.toDouble();

    if (poco) {
        QMessageBox::StandardButton resposta = QMessageBox::question(
            this,
            "",
            "Ao confirmar, todos os fluidos serão deletados! Tem certeza?",
            QMessageBox::Yes | QMessageBox::No
            );

        if (resposta == QMessageBox::Yes) {
            poco = std::make_unique<CObjetoPoco>(
                CObjetoPoco::CriarParaModulo02(nome, profundidade, pressaoSup, temperaturaSuperiorInicial, temperaturaFundoInicial, temperaturaSuperiorFinal, temperaturaFundoFinal, ProfundidadePacker)
                );
        }
        on_btnAtualizarDados_clicked();
    } else {

        poco = std::make_unique<CObjetoPoco>(
            CObjetoPoco::CriarParaModulo02(nome, profundidade, pressaoSup, temperaturaSuperiorInicial, temperaturaFundoInicial, temperaturaSuperiorFinal, temperaturaFundoFinal, ProfundidadePacker)
            );
    }

    makePlotTemperatura(temperaturaSuperiorInicial, temperaturaFundoInicial, profundidade, ui->customPlotTemperaturaInicial);
    makePlotTemperatura(temperaturaSuperiorFinal, temperaturaFundoFinal, profundidade, ui->customPlotTemperaturaFinal);
    makePlotPoco();
}

void CSimuladorPerdaTubulacao::on_btnAtualizarDados_clicked()
{

    if (poco){
        // Atualiza os valores dos QLineEdits com os dados do objeto poco
        ui->editNomePoco->setText(QString::fromStdString(poco->NomePoco()));       // Profundidade total do poço
        ui->editProfundidadeTotal->setText(QString::number(poco->ProfundidadeTotal()));       // Profundidade total do poço
        ui->editPressaoSup->setText(QString::number(poco->PressaoSuperficie())); // Profundidade ocupada
        ui->editTemperaturaSuperiorInicial->setText(QString::number(poco->TemperaturaTopoInicial()));              // Diâmetro do poço
        ui->editTemperaturaFundoInicial->setText(QString::number(poco->TemperaturaFundoInicial()));      // Diâmetro externo do revestimento (OD)
        ui->editTemperaturaSuperiorFinal->setText(QString::number(poco->TemperaturaTopoFinal()));      // Diâmetro interno do revestimento (ID)
        ui->editTemperaturaFundoFinal->setText(QString::number(poco->TemperaturaFundoFinal()));                            // Vazão do fluido no poço

        if (poco->ProfundidadePacker() != 0){
            ui->editProfundidadePacker->setEnabled(true);
            ui->editProfundidadePacker->setText(QString::number(poco->ProfundidadePacker()));
        }

        // Atualizar QTableWidget com os dados dos trechos
        ui->tblTrechos->setRowCount(static_cast<int>(poco->Trechos().size()));
        ui->tblFluidos->setRowCount(static_cast<int>(poco->Trechos().size()));
        qDebug() << "Número de trechos:" << poco->Trechos().size();
        int row = 0;
        for (const auto& trecho : poco->Trechos()) {

            ui->tblTrechos->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(trecho->Nome())));
            ui->tblTrechos->setItem(row, 1, new QTableWidgetItem(QString::number(trecho->ProfundidadeInicial(), 'f', 2)));
            ui->tblTrechos->setItem(row, 2, new QTableWidgetItem(QString::number(trecho->ProfundidadeFinal(), 'f', 2)));
            ui->tblTrechos->setItem(row, 3, new QTableWidgetItem(QString::number(trecho->DiametroExterno(), 'f', 2)));
            ui->tblTrechos->setItem(row, 4, new QTableWidgetItem(QString::number(trecho->DiametroInterno(), 'f', 2)));
            ui->tblTrechos->setItem(row, 5, new QTableWidgetItem(QString::number(trecho->CoeficientePoisson(), 'f', 3)));
            ui->tblTrechos->setItem(row, 6, new QTableWidgetItem(QString::number(trecho->CoeficienteExpancaoTermica(), 'f', 7)));
            ui->tblTrechos->setItem(row, 7, new QTableWidgetItem(QString::number(trecho->ModuloEslasticidade(), 'f', 7)));
            ui->tblTrechos->setItem(row, 8, new QTableWidgetItem(QString::number(trecho->PesoUnidade(), 'f', 2)));

            ui->tblFluidos->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(trecho->Fluido()->Nome())));
            ui->tblFluidos->setItem(row, 1, new QTableWidgetItem(QString::number(trecho->Fluido()->Densidade(), 'f', 2)));
            ui->tblFluidos->setItem(row, 2, new QTableWidgetItem(QString::number(trecho->Fluido()->Viscosidade(), 'f', 2)));

            ++row;
        }
    }
    makePlotTemperatura(poco->TemperaturaTopoInicial(), poco->TemperaturaFundoInicial(), poco->ProfundidadeTotal(), ui->customPlotTemperaturaInicial);
    makePlotTemperatura(poco->TemperaturaTopoFinal(), poco->TemperaturaFundoFinal(), poco->ProfundidadeTotal(), ui->customPlotTemperaturaFinal);
    makePlotPoco();
}

void CSimuladorPerdaTubulacao::on_btnAdicionarTrecho_clicked()
{
    ui->tblTrechos->setEditTriggers(QAbstractItemView::NoEditTriggers);

    if (!poco) {
        QMessageBox::warning(this, "Erro", "As propriedade do poço precisa está preenchida!");
    }

    else{
        CJanelaAdicionarTrechoTubulacao JanelaTrecho;
        JanelaTrecho.exec();

        if (JanelaTrecho.Trecho() != "" &&
            JanelaTrecho.ProfundidadeInicial() != "" &&
            JanelaTrecho.ProfundidadeFinal() != "" &&
            JanelaTrecho.DiametroExterno() != "" &&
            JanelaTrecho.DiametroInterno() != "" &&
            JanelaTrecho.CoeficientePoisson() != "" &&
            JanelaTrecho.CoeficienteExpansaoTermica() != "" &&
            JanelaTrecho.ModuloElasticidade() != "" &&
            JanelaTrecho.PesoUnidade() != "" &&
            JanelaTrecho.NomeFluido() != "" &&
            JanelaTrecho.Densidade() != "" &&
            JanelaTrecho.Viscosidade() != ""){


            int numLinhas = ui->tblTrechos->rowCount();

            ui->tblTrechos->insertRow(numLinhas);
            ui->tblTrechos->setItem(numLinhas, 0, new QTableWidgetItem(JanelaTrecho.Trecho()));
            ui->tblTrechos->setItem(numLinhas, 1, new QTableWidgetItem(JanelaTrecho.ProfundidadeInicial()));
            ui->tblTrechos->setItem(numLinhas, 2, new QTableWidgetItem(JanelaTrecho.ProfundidadeFinal()));
            ui->tblTrechos->setItem(numLinhas, 3, new QTableWidgetItem(JanelaTrecho.DiametroExterno()));
            ui->tblTrechos->setItem(numLinhas, 4, new QTableWidgetItem(JanelaTrecho.DiametroInterno()));
            ui->tblTrechos->setItem(numLinhas, 5, new QTableWidgetItem(JanelaTrecho.CoeficientePoisson()));
            ui->tblTrechos->setItem(numLinhas, 6, new QTableWidgetItem(JanelaTrecho.CoeficienteExpansaoTermica()));
            ui->tblTrechos->setItem(numLinhas, 7, new QTableWidgetItem(JanelaTrecho.ModuloElasticidade()));
            ui->tblTrechos->setItem(numLinhas, 8, new QTableWidgetItem(JanelaTrecho.PesoUnidade()));

            ui->tblFluidos->insertRow(numLinhas);
            ui->tblFluidos->setItem(numLinhas, 0, new QTableWidgetItem(JanelaTrecho.NomeFluido()));
            ui->tblFluidos->setItem(numLinhas, 1, new QTableWidgetItem(JanelaTrecho.Densidade()));
            ui->tblFluidos->setItem(numLinhas, 2, new QTableWidgetItem(JanelaTrecho.Viscosidade()));

            std::string NomeTrecho = JanelaTrecho.Trecho().toStdString();
            double profundInicial = JanelaTrecho.ProfundidadeInicial().toDouble();
            double profundFinal = JanelaTrecho.ProfundidadeFinal().toDouble();
            double diametroExterno = JanelaTrecho.DiametroExterno().toDouble();
            double diametroInterno = JanelaTrecho.DiametroInterno().toDouble();
            double coeficientePoisson = JanelaTrecho.CoeficientePoisson().toDouble();
            double coeficienteExpansaoTermica = JanelaTrecho.CoeficienteExpansaoTermica().toDouble();
            double moduloElasticidade = JanelaTrecho.ModuloElasticidade().toDouble();
            double pesoUnidade = JanelaTrecho.PesoUnidade().toDouble();

            std::string nome = JanelaTrecho.NomeFluido().toStdString();
            double densidade = JanelaTrecho.Densidade().toDouble();
            double viscosidade = JanelaTrecho.Viscosidade().toDouble();

            auto fluido = std::make_unique<CFluido>(nome, densidade, viscosidade);
            auto trechoPoco = std::make_unique<CTrechoPoco>(NomeTrecho, profundInicial, profundFinal, std::move(fluido), diametroExterno, diametroInterno, coeficientePoisson, coeficienteExpansaoTermica, moduloElasticidade, pesoUnidade);
            poco->AdicionarTrechoPoco(std::move(trechoPoco));

            on_btnAtualizarDados_clicked();
        }
    }
}

void CSimuladorPerdaTubulacao::makePlotTemperatura(double TempInicial, double TempFinal, double profundidade, QCustomPlot* plot)
{
    // Limpar o gráfico anterior
    plot->clearItems();
    plot->clearPlottables();

    // Configurar os eixos
    plot->xAxis->setLabel("Temperatura (°F)");
    plot->yAxis->setLabel("Profundidade (ft)");
    plot->yAxis->setRangeReversed(true); // profundidade cresce para baixo

    // Definir os pontos do perfil de temperatura
    QVector<double> temperaturas = {TempInicial, (TempInicial+TempFinal)/2, TempFinal};     // Temperaturas em °F
    QVector<double> profundidades = {0, (profundidade/2), profundidade};    // Profundidades em ft

    // Ajustar ranges com base nos dados
    double tempMin = *std::min_element(temperaturas.begin(), temperaturas.end());
    double tempMax = *std::max_element(temperaturas.begin(), temperaturas.end());
    double profMin = 0;
    double profMax = *std::max_element(profundidades.begin(), profundidades.end());

    plot->xAxis->setRange(tempMin - 20, tempMax + 20);
    plot->yAxis->setRange(profMin, profMax);

    // Criar linha do perfil de temperatura (vermelha)
    QCPGraph *perfilTemp = plot->addGraph();
    perfilTemp->setData(temperaturas, profundidades);
    perfilTemp->setPen(QPen(Qt::red, 2));
    perfilTemp->setName("Condição inicial");

    // Criar linha azul vertical (por exemplo, linha guia em 50°F)
    double linhaAzulX = 50; // ou alguma variável
    QCPItemLine *linhaAzul = new QCPItemLine(plot);
    linhaAzul->start->setCoords(linhaAzulX, profMin);
    linhaAzul->end->setCoords(linhaAzulX, profMax);
    linhaAzul->setPen(QPen(Qt::blue, 1, Qt::SolidLine));

    // Adicionar texto "condição inicial"
    QCPItemText *label = new QCPItemText(plot);
    label->position->setCoords(temperaturas[0] + 10, profundidades[1]); // próximo ao meio
    label->setText("condição inicial");
    label->setFont(QFont("Arial", 10));
    label->setColor(Qt::red);

    // Marcar os pontos principais
    for (int i = 0; i < temperaturas.size(); ++i) {
        QCPItemEllipse *ponto = new QCPItemEllipse(plot);
        ponto->topLeft->setCoords(temperaturas[i] - 5, profundidades[i] - 100);
        ponto->bottomRight->setCoords(temperaturas[i] + 5, profundidades[i] + 100);
        ponto->setPen(QPen(Qt::black));
        ponto->setBrush(Qt::gray);

        QCPItemText *rotulo = new QCPItemText(plot);
        rotulo->position->setCoords(temperaturas[i], profundidades[i]);
        rotulo->setText(QString::number(temperaturas[i]) + "°F");
        rotulo->setFont(QFont("Arial", 9));
        rotulo->setPositionAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    }

    // Atualizar o gráfico
    plot->replot();
}

void CSimuladorPerdaTubulacao::on_btnRemoverFluido_clicked()
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

void CSimuladorPerdaTubulacao::on_btnRemoverTrecho_clicked()
{
    int linhaSelecionada = ui->tblTrechos->currentRow();

    if (linhaSelecionada >= 0) {

        QTableWidgetItem* item = ui->tblTrechos->item(linhaSelecionada, 0);

        if (item) {
            QMessageBox::StandardButton resposta = QMessageBox::question(
                this,
                "",
                "Tem certeza que deseja remover o trecho?",
                QMessageBox::Yes | QMessageBox::No
                );

            if (resposta == QMessageBox::Yes) {
                QString nomeTrecho = item->text();
                ui->tblTrechos->removeRow(linhaSelecionada);
                poco->RemoverTrechoPoco(nomeTrecho.toStdString());
                on_btnAtualizarDados_clicked();
                ui->statusbar->showMessage("Fluido Removido com Sucesso!");
            }

        }

    } else {
        QMessageBox::warning(this, "Erro", "Selecione uma linha para deletar.");
    }
}

void CSimuladorPerdaTubulacao::makePlotPoco()
{
    ui->customPlotPoco->clearItems();
    ui->customPlotPoco->xAxis->setLabel("Diâmetro (pol)");
    ui->customPlotPoco->yAxis->setLabel("Profundidade (pol)");
    ui->customPlotPoco->yAxis->setRangeReversed(true);

    if (!poco || poco->Trechos().empty())
        return;

    // 1. Profundidade máxima e maior diâmetro externo
    double profundidadeMaxima = 0.0;
    double maiorDiametroExterno = 0.0;
    for (const auto& trecho : poco->Trechos()) {
        profundidadeMaxima = std::max(profundidadeMaxima, trecho->ProfundidadeFinal());
        maiorDiametroExterno = std::max(maiorDiametroExterno, trecho->DiametroExterno());
    }

    // 2. Buraco = maior diâmetro externo + 3 polegadas
    double diametroBuraco = maiorDiametroExterno + 3.0;

    // 3. Ajuste visual no eixo X: 1.5 vezes o furo
    double larguraGrafico = diametroBuraco * 1.5;
    ui->customPlotPoco->xAxis->setRange(-larguraGrafico / 2.0, larguraGrafico / 2.0);
    ui->customPlotPoco->yAxis->setRange(0, profundidadeMaxima);

    // 4. Cores dos fluidos
    QMap<QString, QColor> mapaCores;
    QVector<QColor> coresDisponiveis = {
        QColor(173, 216, 230, 150), QColor(255, 0, 0, 150),
        QColor(0, 255, 0, 150), QColor(0, 0, 255, 150),
        QColor(255, 165, 0, 150), QColor(128, 0, 128, 150)
    };
    int corIndex = 0;

    // 5. Desenho dos trechos
    for (const auto& trecho : poco->Trechos()) {
        double z1 = trecho->ProfundidadeInicial();
        double z2 = trecho->ProfundidadeFinal();
        double dExt = trecho->DiametroExterno();
        QString nomeFluido = QString::fromStdString(trecho->Fluido()->Nome());

        if (!mapaCores.contains(nomeFluido)) {
            mapaCores[nomeFluido] = coresDisponiveis[corIndex++ % coresDisponiveis.size()];
        }
        QColor corFluido = mapaCores[nomeFluido];

        // === Retângulo cinza (buraco do poço) ===
        QCPItemRect *rectBuraco = new QCPItemRect(ui->customPlotPoco);
        rectBuraco->topLeft->setCoords(-diametroBuraco / 2.0, z1);
        rectBuraco->bottomRight->setCoords(diametroBuraco / 2.0, z2);
        rectBuraco->setPen(QPen(Qt::black));
        rectBuraco->setBrush(QBrush(QColor(150, 150, 150, 100)));

        // === Retângulo da seção (fluido) ===
        QCPItemRect *rectSecao = new QCPItemRect(ui->customPlotPoco);
        rectSecao->topLeft->setCoords(-dExt / 2.0, z1);
        rectSecao->bottomRight->setCoords(dExt / 2.0, z2);
        rectSecao->setPen(QPen(Qt::black));
        rectSecao->setBrush(QBrush(corFluido));

        // === Rótulo ===
        QCPItemText *label = new QCPItemText(ui->customPlotPoco);
        label->position->setCoords(0, (z1 + z2) / 2.0);
        label->setText(nomeFluido);
        label->setFont(QFont("Arial", 10, QFont::Bold));
        label->setColor(Qt::black);
        label->setPositionAlignment(Qt::AlignCenter);
    }
    // 6. Desenhar packer se existir
    double profundidadePacker = poco->ProfundidadePacker();
    if (profundidadePacker > 0.0) {
        double alturaPacker = std::max(profundidadeMaxima * 0.01, 12.0);
        double zTop = profundidadePacker - alturaPacker / 2.0;
        double zBottom = profundidadePacker + alturaPacker / 2.0;

        // Encontrar o trecho correspondente à profundidade do packer
        double diametroNoPacker = 0.0;
        for (const auto& trecho : poco->Trechos()) {
            if (profundidadePacker >= trecho->ProfundidadeInicial() &&
                profundidadePacker <= trecho->ProfundidadeFinal()) {
                diametroNoPacker = trecho->DiametroExterno();
                break;
            }
        }

        // Se não achou trecho correspondente, usa o maior conhecido como fallback
        if (diametroNoPacker == 0.0)
            diametroNoPacker = maiorDiametroExterno;

        // Coordenadas horizontais para os quadrados laterais
        double xEsq1 = -diametroBuraco / 2.0;
        double xEsq2 = -diametroNoPacker / 2.0;
        double xDir1 = diametroNoPacker / 2.0;
        double xDir2 = diametroBuraco / 2.0;

        // === Quadrado esquerdo ===
        QCPItemRect* rectPackerEsq = new QCPItemRect(ui->customPlotPoco);
        rectPackerEsq->topLeft->setCoords(xEsq1, zTop);
        rectPackerEsq->bottomRight->setCoords(xEsq2, zBottom);
        rectPackerEsq->setPen(QPen(Qt::red, 1.5));
        rectPackerEsq->setBrush(Qt::NoBrush);

        // === Quadrado direito ===
        QCPItemRect* rectPackerDir = new QCPItemRect(ui->customPlotPoco);
        rectPackerDir->topLeft->setCoords(xDir1, zTop);
        rectPackerDir->bottomRight->setCoords(xDir2, zBottom);
        rectPackerDir->setPen(QPen(Qt::red, 1.5));
        rectPackerDir->setBrush(Qt::NoBrush);

        // === X vermelho esquerdo ===
        QCPItemLine* linha1Esq = new QCPItemLine(ui->customPlotPoco);
        linha1Esq->start->setCoords(xEsq1, zTop);
        linha1Esq->end->setCoords(xEsq2, zBottom);
        linha1Esq->setPen(QPen(Qt::red, 1.5));

        QCPItemLine* linha2Esq = new QCPItemLine(ui->customPlotPoco);
        linha2Esq->start->setCoords(xEsq2, zTop);
        linha2Esq->end->setCoords(xEsq1, zBottom);
        linha2Esq->setPen(QPen(Qt::red, 1.5));

        // === X vermelho direito ===
        QCPItemLine* linha1Dir = new QCPItemLine(ui->customPlotPoco);
        linha1Dir->start->setCoords(xDir1, zTop);
        linha1Dir->end->setCoords(xDir2, zBottom);
        linha1Dir->setPen(QPen(Qt::red, 1.5));

        QCPItemLine* linha2Dir = new QCPItemLine(ui->customPlotPoco);
        linha2Dir->start->setCoords(xDir2, zTop);
        linha2Dir->end->setCoords(xDir1, zBottom);
        linha2Dir->setPen(QPen(Qt::red, 1.5));
    }
    ui->customPlotPoco->replot();
}

void CSimuladorPerdaTubulacao::on_btnCalcularVariacoes_clicked()
{
    QString profundidadeStr = ui->editProfundidadeMedicao->text();
    double profundidade = profundidadeStr.toDouble();

    ui->lbnPressaoHidroestatica->setText(QString::number( (poco->PressaoHidroestaticaNoPonto(profundidade)) ));
    ui->lbnCargaInicial->setText(QString::number(poco->CargaInicial(profundidade)));
    ui->lbnTituloDeltaLTemperatura->setText(QString::number(poco->DeltaLTemperaturaTotal()));

}

void CSimuladorPerdaTubulacao::on_actionArquivo_Dat_triggered()
{
    QString caminhoDoArquivo = QFileDialog::getOpenFileName(
        this,
        "Selecione um arquivo",
        "",
        "Todos os arquivos (*.*)"
        );

    std::string caminhoDoArquivoStr = caminhoDoArquivo.toStdString();
    std::ifstream file(caminhoDoArquivoStr);

    if (!file.is_open()) {
        ui->statusbar->showMessage("Falha ao abrir o arquivo!");
        return;
    }

    std::string linha;
    bool lendoTrechos = false;

    while (std::getline(file, linha)) {
        if (linha.find("Configuração dos Trechos") != std::string::npos) {
            lendoTrechos = true;
            continue;
        }

        if (linha.empty() || linha[0] == '#') {
            continue;
        }

        if (!lendoTrechos) {
            // Leitura dos dados do poço
            std::istringstream iss(linha);
            std::string nome;
            double profundidade, pressaoSup;
            double temperaturaSuperiorInicial, temperaturaFundoInicial;
            double temperaturaSuperiorFinal, temperaturaFundoFinal;
            double profundidadePacker;

            if (iss >> nome >> profundidade >> pressaoSup
                >> temperaturaSuperiorInicial >> temperaturaFundoInicial
                >> temperaturaSuperiorFinal >> temperaturaFundoFinal >> profundidadePacker) {

                ui->btnAdicionarTrecho->setEnabled(true);
                ui->btnRemoverTrecho->setEnabled(true);
                ui->btnCalcularVariacoes->setEnabled(true);

                poco = std::make_unique<CObjetoPoco>(
                    CObjetoPoco::CriarParaModulo02(nome, profundidade, pressaoSup,
                                             temperaturaSuperiorInicial, temperaturaFundoInicial,
                                             temperaturaSuperiorFinal, temperaturaFundoFinal, profundidadePacker)
                    );
            } else {
                std::cerr << "Erro ao ler linha de poço: " << linha << std::endl;
            }
        } else {
            // Leitura dos dados dos trechos
            std::istringstream iss(linha);
            std::string nomeTrecho, nomeFluido;
            double profundInicial, profundFinal;
            double diametroExterno, diametroInterno;
            double coeficientePoisson, coeficienteExpansaoTermica;
            double moduloElasticidade, pesoUnidade;
            double densidade, viscosidade;

            if (iss >> nomeTrecho >> profundInicial >> profundFinal
                >> diametroExterno >> diametroInterno
                >> coeficientePoisson >> coeficienteExpansaoTermica
                >> moduloElasticidade >> pesoUnidade
                >> nomeFluido >> densidade >> viscosidade) {

                auto fluido = std::make_unique<CFluido>(nomeFluido, densidade, viscosidade);
                auto trechoPoco = std::make_unique<CTrechoPoco>(nomeTrecho,
                    profundInicial, profundFinal, std::move(fluido),
                    diametroExterno, diametroInterno,
                    coeficientePoisson, moduloElasticidade,
                    pesoUnidade, coeficienteExpansaoTermica
                    );

                if (!poco->AdicionarTrechoPoco(std::move(trechoPoco))) {
                    std::cerr << "Falha ao adicionar trecho ao poço.\n";
                }

            } else {
                std::cerr << "Erro ao ler trecho: " << linha << std::endl;
            }
        }
    }

    file.close();
    on_btnAtualizarDados_clicked();
    ui->statusbar->showMessage("Dados importados com sucesso!");

}


void CSimuladorPerdaTubulacao::on_actionNova_Simula_o_triggered()
{
    QMessageBox::StandardButton resposta = QMessageBox::question(
        this,
        "",
        "Tem certeza que deseja iniciar uma nova simulação?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (resposta == QMessageBox::Yes) {
        CSimuladorPerdaTubulacao *newWindow = new CSimuladorPerdaTubulacao();
        newWindow->show();
        this->close();
    }
}


void CSimuladorPerdaTubulacao::on_actionExportar_Como_Imagem_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Salvar imagem", "", "PNG (*.png);;JPEG (*.jpg)");

    if (!fileName.isEmpty()) {
        QPixmap pixmap = this->grab();
        pixmap.save(fileName);
    }
}


void CSimuladorPerdaTubulacao::on_actionSobre_o_SEEP_triggered()
{
    CJanelaSobreSofware janelaSobre;
    janelaSobre.setWindowTitle("Sobre o Software");
    janelaSobre.exec();
}

