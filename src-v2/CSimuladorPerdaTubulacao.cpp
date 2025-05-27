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


    // Sinal para alterações das caixas
    connect(ui->editNomePoco, &QLineEdit::editingFinished, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->editProfundidadeTotal, &QLineEdit::editingFinished, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->editPressaoSupInicial, &QLineEdit::editingFinished, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->editPressaoSupFinal, &QLineEdit::editingFinished, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->editTemperaturaSuperiorInicial, &QLineEdit::editingFinished, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->editTemperaturaFundoInicial, &QLineEdit::editingFinished, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->editTemperaturaSuperiorFinal, &QLineEdit::editingFinished, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->editTemperaturaFundoFinal, &QLineEdit::editingFinished, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->editProfundidadeMedicao, &QLineEdit::editingFinished, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);
    connect(ui->checkBoxPacker, &QCheckBox::stateChanged, this, &CSimuladorPerdaTubulacao::EditarDadosPoco);


    // iniciar com botões desativado
    ui->btnAdicionarTrecho->setEnabled(false);
    ui->btnRemoverTrecho->setEnabled(false);
    ui->btnCalcularVariacoes->setEnabled(false);

    connect(ui->tblFluidos, &QTableWidget::cellChanged, this, &CSimuladorPerdaTubulacao::EditarLinhaTabela);
    connect(ui->tblTrechos, &QTableWidget::cellChanged, this, &CSimuladorPerdaTubulacao::EditarLinhaTabela);

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
    bool ok1, ok2, ok3, ok4, ok5, ok6, ok7, ok8;
    double profund  = ui->editProfundidadeTotal->text().toDouble(&ok1);
    double diamPoco  = ui->editDiametroPoco->text().toDouble(&ok2);
    double pressao  = ui->editPressaoSupInicial->text().toDouble(&ok3);
    double pressaoFim  = ui->editPressaoSupFinal->text().toDouble(&ok4);
    double temperaturaSuperiorInicial = ui->editTemperaturaSuperiorInicial->text().toDouble(&ok5);
    double temperaturaFundoInicial = ui->editTemperaturaFundoInicial->text().toDouble(&ok6);
    double temperaturaSuperiorFinal = ui->editTemperaturaSuperiorFinal->text().toDouble(&ok7);
    double temperaturaFundoFinal = ui->editTemperaturaFundoFinal->text().toDouble(&ok8);
    bool haPacker = ui->checkBoxPacker->isChecked();

    if (!nome.isEmpty() && ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8) {
        if (!poco) {
            // Cria o poço

            poco = std::make_unique<CObjetoPoco>(
                CObjetoPoco::CriarParaModulo02(nome.toStdString(), profund, diamPoco, pressao, pressaoFim, temperaturaSuperiorInicial, temperaturaFundoInicial, temperaturaSuperiorFinal, temperaturaFundoFinal, haPacker)
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
            poco->PressaoSuperficieFim(pressaoFim);
            poco->TemperaturaTopoInicial(temperaturaSuperiorInicial);
            poco->TemperaturaFundoInicial(temperaturaFundoInicial);
            poco->TemperaturaTopoFinal(temperaturaSuperiorFinal);
            poco->TemperaturaFundoFinal(temperaturaFundoFinal);
            poco->Packer(haPacker);
            ui->statusbar->showMessage("Dados de Poço Atualizado com Sucesso!");
        }

        AtualizarDados();  // Atualiza os dados calculados e a interface
    }
}

void CSimuladorPerdaTubulacao::on_btnAdicionarPropriedades_clicked()
{
    std::string nome;
    double profundidade,diamPoco, pressaoSup, pressaoSupFim,  temperaturaSuperiorInicial, temperaturaFundoInicial, temperaturaSuperiorFinal, temperaturaFundoFinal;
    bool haPacker;

    QString text;

    text = ui->editNomePoco->text();
    nome = text.toStdString();
    text = ui->editPressaoSupInicial->text();
    pressaoSup = text.toDouble();
    text = ui->editPressaoSupFinal->text();
    pressaoSupFim = text.toDouble();
    text = ui->editProfundidadeTotal->text();
    profundidade = text.toDouble();
    text = ui->editDiametroPoco->text();
    diamPoco = text.toDouble();
    text = ui->editTemperaturaSuperiorInicial->text();
    temperaturaSuperiorInicial = text.toDouble();
    text = ui->editTemperaturaFundoInicial->text();
    temperaturaFundoInicial = text.toDouble();
    text = ui->editTemperaturaSuperiorFinal->text();
    temperaturaSuperiorFinal = text.toDouble();
    text = ui->editTemperaturaFundoFinal->text();
    temperaturaFundoFinal = text.toDouble();
    haPacker = ui->checkBoxPacker->isChecked();


    if (poco) {
        QMessageBox::StandardButton resposta = QMessageBox::question(
            this,
            "",
            "Ao confirmar, todos os fluidos serão deletados! Tem certeza?",
            QMessageBox::Yes | QMessageBox::No
            );

        if (resposta == QMessageBox::Yes) {
            poco = std::make_unique<CObjetoPoco>(
                CObjetoPoco::CriarParaModulo02(nome, profundidade, diamPoco, pressaoSup, pressaoSupFim, temperaturaSuperiorInicial, temperaturaFundoInicial, temperaturaSuperiorFinal, temperaturaFundoFinal, haPacker)
                );
        }
        AtualizarDados();
    } else {

        poco = std::make_unique<CObjetoPoco>(
            CObjetoPoco::CriarParaModulo02(nome, profundidade, diamPoco, pressaoSup, pressaoSupFim, temperaturaSuperiorInicial, temperaturaFundoInicial, temperaturaSuperiorFinal, temperaturaFundoFinal, haPacker)
            );
    }

    makePlotTemperatura(temperaturaSuperiorInicial, temperaturaFundoInicial, profundidade, ui->customPlotTemperaturaInicial);
    makePlotTemperatura(temperaturaSuperiorFinal, temperaturaFundoFinal, profundidade, ui->customPlotTemperaturaFinal);
    makePlotPoco();
}

void CSimuladorPerdaTubulacao::AtualizarDados()
{
    ui->tblFluidos->blockSignals(true);
    ui->tblTrechos->blockSignals(true);

    if (poco){
        // Atualiza os valores dos QLineEdits com os dados do objeto poco
        ui->editNomePoco->setText(QString::fromStdString(poco->NomePoco()));       // Profundidade total do poço
        ui->editProfundidadeTotal->setText(QString::number(poco->ProfundidadeTotal()));       // Profundidade total do poço
        ui->editDiametroPoco->setText(QString::number(poco->DiametroPoco()));
        ui->editPressaoSupInicial->setText(QString::number(poco->PressaoSuperficie())); // Profundidade ocupada
        ui->editPressaoSupFinal->setText(QString::number(poco->PressaoSuperficieFim()));
        ui->editTemperaturaSuperiorInicial->setText(QString::number(poco->TemperaturaTopoInicial()));              // Diâmetro do poço
        ui->editTemperaturaFundoInicial->setText(QString::number(poco->TemperaturaFundoInicial()));      // Diâmetro externo do revestimento (OD)
        ui->editTemperaturaSuperiorFinal->setText(QString::number(poco->TemperaturaTopoFinal()));      // Diâmetro interno do revestimento (ID)
        ui->editTemperaturaFundoFinal->setText(QString::number(poco->TemperaturaFundoFinal()));                            // Vazão do fluido no poço
        if (poco->Packer() == true) {
            ui->checkBoxPacker->setChecked(true);
        } else {
            ui->checkBoxPacker->setChecked(false);
        }



        // Atualizar QTableWidget com os dados dos trechos
        ui->tblTrechos->setRowCount(static_cast<int>(poco->Trechos().size()));
        ui->tblFluidos->setRowCount(static_cast<int>(poco->Trechos().size()));
        int row = 0;
        for (const auto& trecho : poco->Trechos()) {

            ui->tblTrechos->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(trecho->Nome())));
            ui->tblTrechos->setItem(row, 1, new QTableWidgetItem(QString::number(trecho->ProfundidadeInicial(), 'f', 2)));
            ui->tblTrechos->setItem(row, 2, new QTableWidgetItem(QString::number(trecho->ProfundidadeFinal(), 'f', 2)));
            ui->tblTrechos->setItem(row, 3, new QTableWidgetItem(QString::number(trecho->DiametroExterno(), 'f', 2)));
            ui->tblTrechos->setItem(row, 4, new QTableWidgetItem(QString::number(trecho->DiametroInterno(), 'f', 2)));
            ui->tblTrechos->setItem(row, 5, new QTableWidgetItem(QString::number(trecho->CoeficientePoisson(), 'f', 2)));
            ui->tblTrechos->setItem(row, 6, new QTableWidgetItem(QString::number(trecho->CoeficienteExpancaoTermica(), 'f', 8)));
            ui->tblTrechos->setItem(row, 7, new QTableWidgetItem(QString::number(trecho->ModuloEslasticidade(), 'f', 2)));
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

    ui->tblFluidos->blockSignals(false);
    ui->tblTrechos->blockSignals(false);
}

void CSimuladorPerdaTubulacao::on_btnAdicionarTrecho_clicked()
{
    ui->tblTrechos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblFluidos->setEditTriggers(QAbstractItemView::NoEditTriggers);

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

            AtualizarDados();
        }
    }
}

void CSimuladorPerdaTubulacao::makePlotTemperatura(double TempInicial, double TempFinal, double profundidade, QCustomPlot* plot)
{
    // Limpa graficos anteriores
    plot->clearItems();
    plot->clearPlottables();

    // Configura eixos
    plot->xAxis->setLabel("Temperatura (°F)");
    plot->yAxis->setLabel("Profundidade (ft)");
    plot->yAxis->setRangeReversed(true); // profundidade cresce pra baixo

    // Adiciona "respiro" nos extremos
    double margemProfundidade = profundidade * 0.05; // 5% de margem visual

    // Define pontos
    double tempMeio = (TempInicial + TempFinal) / 2.0;
    QVector<double> temperaturas = {TempInicial, tempMeio, TempFinal};
    QVector<double> profundidades = {0.0 + margemProfundidade, profundidade / 2.0, profundidade - margemProfundidade};

    // Ajuste de range
    double tempMin = *std::min_element(temperaturas.begin(), temperaturas.end());
    double tempMax = *std::max_element(temperaturas.begin(), temperaturas.end());

    plot->xAxis->setRange(tempMin - 5, tempMax + 5);
    plot->yAxis->setRange(0.0, profundidade); // Mantem 0 a profundidade total, o respiro e visual apenas

    // Grid leve
    plot->xAxis->grid()->setVisible(true);
    plot->yAxis->grid()->setVisible(true);
    plot->xAxis->grid()->setPen(QPen(QColor(220, 220, 220)));
    plot->yAxis->grid()->setPen(QPen(QColor(220, 220, 220)));

    // Linha do perfil
    QCPGraph *perfilTemp = plot->addGraph();
    perfilTemp->setData(temperaturas, profundidades);
    perfilTemp->setPen(QPen(QColor(200, 0, 0), 2));

    // Marcar e rotular os 3 pontos (topo, meio e fundo)
    for (int i = 0; i < temperaturas.size(); ++i) {
        QCPItemEllipse *ponto = new QCPItemEllipse(plot);
        ponto->topLeft->setCoords(temperaturas[i] - 2, profundidades[i] - 20);
        ponto->bottomRight->setCoords(temperaturas[i] + 2, profundidades[i] + 20);
        ponto->setPen(Qt::NoPen);
        ponto->setBrush(QBrush(Qt::darkGray));

        QCPItemText *rotulo = new QCPItemText(plot);
        rotulo->position->setCoords(temperaturas[i] + 4, profundidades[i]);
        rotulo->setText(QString::number(temperaturas[i], 'f', 1) + " °F");
        rotulo->setFont(QFont("Arial", 8));
        rotulo->setColor(Qt::darkGray);
        // Ajusta alinhamento do rotulo do ultimo ponto para dentro do grafico
        if (i == temperaturas.size() - 1)
            rotulo->setPositionAlignment(Qt::AlignRight | Qt::AlignVCenter); // alinha para a esquerda do ponto final
        else
            rotulo->setPositionAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    }

    // Limpeza estética
    plot->legend->setVisible(false);
    plot->setBackground(Qt::white);
    plot->xAxis->setBasePen(QPen(Qt::black));
    plot->yAxis->setBasePen(QPen(Qt::black));
    plot->xAxis->setTickPen(QPen(Qt::black));
    plot->yAxis->setTickPen(QPen(Qt::black));
    plot->xAxis->setTickLabelColor(Qt::black);
    plot->yAxis->setTickLabelColor(Qt::black);

    // Replotar
    plot->replot();
}




void CSimuladorPerdaTubulacao::on_btnRemoverTrecho_clicked()
{
    // pega qual linha ta selecionada em cada tabela
    int linhaSelecionadaTrecho = ui->tblTrechos->currentRow();
    int linhaSelecionadaFluido = ui->tblFluidos->currentRow();

    // se a selecao for feita na tabela de trecho, faz a remocao
    if (linhaSelecionadaTrecho >= 0) {
        QMessageBox::StandardButton resposta = QMessageBox::question(
            this,
            "Confirmação",
            "Deseja remover o trecho e o fluido associado?",
            QMessageBox::Yes | QMessageBox::No
            );

        if (resposta == QMessageBox::Yes) {
            // pega o nome do trecho pela tabela (pra remover do objeto poco)
            QString nomeTrecho = ui->tblTrechos->item(linhaSelecionadaTrecho, 0)->text();

            // remove a mesma linha das duas tabelas
            ui->tblTrechos->removeRow(linhaSelecionadaTrecho);
            ui->tblFluidos->removeRow(linhaSelecionadaTrecho);

            // remove o trecho (e junto o fluido) do objeto poco
            poco->RemoverTrechoPoco(nomeTrecho.toStdString());

            // atualiza visualmente os dados
            AtualizarDados();
            ui->statusbar->showMessage("Trecho removido com sucesso!");
        }

    } else if (linhaSelecionadaFluido >= 0) {
        // se clicou so na tabela de fluido, avisa que deve usar a outra
        QMessageBox::warning(this, "Aviso", "A remoção deve ser feita pela tabela de trechos.");
    } else {
        // nenhuma linha foi selecionada
        QMessageBox::warning(this, "Erro", "Nenhuma linha foi selecionada.");
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
        QColor(70, 130, 180, 180), QColor(255, 0, 0, 150),
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
bool haPacker = poco->Packer();
if (haPacker == true) {

    // Pega a profundidade do último trecho como profundidade do packer
    double profundidadePacker = 0.0;
    if (!poco->Trechos().empty()) {
        profundidadePacker = poco->Trechos().back()->ProfundidadeFinal();
    }

    double alturaPacker = std::max(profundidadeMaxima * 0.01, 12.0);
    double zTop, zBottom;

    // Se o packer estiver exatamente na profundidade máxima, desenha ele todo acima
    if (std::abs(profundidadePacker - profundidadeMaxima) < 1e-3) {
        zBottom = profundidadePacker;
        zTop = profundidadePacker - alturaPacker;
    } else {
        zTop = profundidadePacker - alturaPacker / 2.0;
        zBottom = profundidadePacker + alturaPacker / 2.0;
    }

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

    // 7. Linha tracejada indicando profundidade de medição, se válida
    bool ok = false;
    double profundidadeMedicao = ui->editProfundidadeMedicao->text().toDouble(&ok);

    // So desenha se a conversao foi bem-sucedida e o valor for maior que zero
    if (ok && profundidadeMedicao > 0.0) {
        QCPItemLine* linhaMedicao = new QCPItemLine(ui->customPlotPoco);
        linhaMedicao->start->setCoords(-larguraGrafico / 2.0, profundidadeMedicao);
        linhaMedicao->end->setCoords(larguraGrafico / 2.0, profundidadeMedicao);

        // Define o estilo como linha tracejada preta
        QPen pen(Qt::black);
        pen.setStyle(Qt::DashLine);
        pen.setWidthF(1.5);
        linhaMedicao->setPen(pen);
    }

    ui->customPlotPoco->replot();
}

void CSimuladorPerdaTubulacao::on_btnCalcularVariacoes_clicked()
{

    double pressaoCabeca = ui->editPressaoSupFinal->text().toDouble();

    QString profundidadeStr = ui->editProfundidadeMedicao->text();
    double profundidade = profundidadeStr.toDouble();

    ui->lbnPressaoHidroestatica->setText(QString::number( (poco->PressaoHidroestaticaNoPonto(profundidade)) ));
    ui->lbnCargaInicial->setText(QString::number(poco->Carga(profundidade, true)));

    ui->lbnTituloDeltaLTemperatura->setText(QString::number(poco->DeltaLTemperatura(profundidade)));
    ui->lbnCargaInjecaoColunaFixa->setText(QString::number(poco->CargaInjecao(profundidade)));
    ui->lbnCargaInjecaoColunaLivre->setText(QString::number(poco->Carga(profundidade, false)));
    ui->lbnDeltaLPistaoPacker->setText(QString::number(poco->DeltaLPistaoPacker(profundidade)));
    ui->lbnTituloDeltaLBalao->setText(QString::number(poco->DeltaLEfeitoBalao(profundidade)));
    ui->lbnDeltaLPistaoCrossover->setText(QString::number(poco->DeltaLPistaoCrossover(profundidade)));
    ui->lbnDeltaLForcaRestauradora->setText(QString::number(poco->DeltaLForcaRestauradora(profundidade)));
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
        if (linha.find("Configuracao dos Fluidos") != std::string::npos) {
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
            double profundidade, diamPoco, pressaoSup, pressaoSupFim;
            double temperaturaSuperiorInicial, temperaturaFundoInicial;
            double temperaturaSuperiorFinal, temperaturaFundoFinal;
            std::string strHaPacker;

            if (iss >> nome >> profundidade >>  diamPoco >> pressaoSup >> pressaoSupFim
                >> temperaturaSuperiorInicial >> temperaturaFundoInicial
                >> temperaturaSuperiorFinal >> temperaturaFundoFinal >> strHaPacker) {

                ui->btnAdicionarTrecho->setEnabled(true);
                ui->btnRemoverTrecho->setEnabled(true);
                ui->btnCalcularVariacoes->setEnabled(true);

                bool haPacker = (strHaPacker == "true" || strHaPacker == "1");

                if (haPacker == false){
                    ui->checkBoxPacker->setChecked(false);
                } else {
                    ui->checkBoxPacker->setChecked(true);
                }

                poco = std::make_unique<CObjetoPoco>(
                    CObjetoPoco::CriarParaModulo02(nome, profundidade, diamPoco, pressaoSup,pressaoSupFim,
                                             temperaturaSuperiorInicial, temperaturaFundoInicial,
                                             temperaturaSuperiorFinal, temperaturaFundoFinal, haPacker)
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
                    coeficientePoisson, coeficienteExpansaoTermica,
                    moduloElasticidade, pesoUnidade
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
    AtualizarDados();
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


void CSimuladorPerdaTubulacao::SalvarArquivo(bool salvarComo)
{
    QString caminho;

    // Se for salvarComo ou ainda não tiver caminho, abrir o diálogo
    if (salvarComo || CaminhoArquivo().isEmpty()) {
        caminho = QFileDialog::getSaveFileName(this, "Salvar Arquivo", "", "Arquivo DAT (*.dat)");
        if (caminho.isEmpty()) return; // usuário cancelou
        CaminhoArquivo(caminho);
        NomeArquivo(QFileInfo(caminho).fileName());
    } else {
        caminho = CaminhoArquivo(); // salva direto
    }

    QFile arquivo(caminho);
    if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Erro", "Nao foi possivel salvar o arquivo.");
        return;
    }

    QTextStream out(&arquivo);

    out << "# Configuracao do Poco ------------------------------------------------------------------------------------\n";
    out << "# "
        << QString("Nome").leftJustified(35, ' ')
        << QString("Profundidade (ft)").leftJustified(35, ' ')
        << QString("Diametro do Poçp (ft)").leftJustified(35, ' ')
        << QString("Pressao Sup. Inicial (psi)").leftJustified(35, ' ')
        << QString("Pressao Sup. Final (psi)").leftJustified(35, ' ')
        << QString("Temp Sup. Inicial (°F)").leftJustified(35, ' ')
        << QString("Temp Fund. Inicial (°F)").leftJustified(35, ' ')
        << QString("Temp Sup. Final (°F)").leftJustified(35, ' ')
        << QString("Temp Fund. Final (°F)").leftJustified(35, ' ')
        << QString("Prof Packer (ft)").leftJustified(35, ' ')
        << "\n";

    out << "  "
        << ui->editNomePoco->text().leftJustified(35, ' ')
        << ui->editProfundidadeTotal->text().leftJustified(35, ' ')
        << ui->editDiametroPoco->text().leftJustified(35, ' ')
        << ui->editPressaoSupInicial->text().leftJustified(35, ' ')
        << ui->editPressaoSupFinal->text().leftJustified(35, ' ')
        << ui->editTemperaturaSuperiorInicial->text().leftJustified(35, ' ')
        << ui->editTemperaturaFundoInicial->text().leftJustified(35, ' ')
        << ui->editTemperaturaSuperiorFinal->text().leftJustified(35, ' ')
        << ui->editTemperaturaFundoFinal->text().leftJustified(35, ' ');

    // Checkbox de saida
    if (ui->checkBoxPacker->isChecked()) {
        out << "true";
    } else {
        out << "false";
    }

    out << "\n";


    // Escreve os dados dos fluidos
    out << "\n\n\n# Configuracao dos Fluidos --------------------------------------------------------------------------------\n";
    out << "# "
        << QString("Nome Trecho").leftJustified(25, ' ')
        << QString("Prof. Inicial (ft)").leftJustified(25, ' ')
        << QString("Prof. Final (ft)").leftJustified(25, ' ')
        << QString("Diam. externo (in)").leftJustified(25, ' ')
        << QString("Diam. interno (in)").leftJustified(25, ' ')
        << QString("Coef. Poisson").leftJustified(25, ' ')
        << QString("Coef. Exp. Term. (1/F)").leftJustified(25, ' ')
        << QString("Mod. Elast. (psi)").leftJustified(25, ' ')
        << QString("Peso/unid (lb/ft)").leftJustified(25, ' ')
        << QString("Nome fluido").leftJustified(25, ' ')
        << QString("Densidade (lbm/gal)").leftJustified(25, ' ')
        << QString("Viscosidade (cP)").leftJustified(25, ' ')
        << "\n";

    int linhas = ui->tblFluidos->rowCount();
    for (int i = 0; i < linhas; ++i) {
        out << "  " // recuo
            << ui->tblTrechos->item(i, 0)->text().leftJustified(25, ' ')
            << ui->tblTrechos->item(i, 1)->text().leftJustified(25, ' ')
            << ui->tblTrechos->item(i, 2)->text().leftJustified(25, ' ')
            << ui->tblTrechos->item(i, 3)->text().leftJustified(25, ' ')
            << ui->tblTrechos->item(i, 4)->text().leftJustified(25, ' ')
            << ui->tblTrechos->item(i, 5)->text().leftJustified(25, ' ')
            << ui->tblTrechos->item(i, 6)->text().leftJustified(25, ' ')
            << ui->tblTrechos->item(i, 7)->text().leftJustified(25, ' ')
            << ui->tblTrechos->item(i, 8)->text().leftJustified(25, ' ')
            << ui->tblFluidos->item(i, 0)->text().leftJustified(25, ' ')
            << ui->tblFluidos->item(i, 1)->text().leftJustified(25, ' ')
            << ui->tblFluidos->item(i, 2)->text().leftJustified(25, ' ')
            << "\n";
    }

    arquivo.close();

    // Atualiza o caminho salvo apenas se for novo
    if (CaminhoArquivo().isEmpty())
    {
        CaminhoArquivo(caminho);
        NomeArquivo(QFileInfo(caminho).fileName());
    }

    QMessageBox::information(this, "Salvo", "Arquivo salvo com sucesso!");
}

void CSimuladorPerdaTubulacao::on_actionSalvar_triggered()
{
    SalvarArquivo(false);  // salvar direto
}

void CSimuladorPerdaTubulacao::on_actionSalvar_como_triggered()
{
    SalvarArquivo(true);  // forçar abrir QFileDialog
}

// essa funcao edita os dados do fluido e do trecho com base na linha da tabela de fluidos
void CSimuladorPerdaTubulacao::EditarLinhaTabela(int row)
{
    // garante que o índice da linha é válido
    if (row < 0 || row >= poco->Trechos().size()) {
        return;
    }

    // obtem o trecho e fluido da mesma linha
    CTrechoPoco* trecho = poco->Trechos().at(row);
    CFluido* fluido = trecho->Fluido();

    if (!fluido) return;

    trecho->Nome(ui->tblTrechos->item(row, 0)->text().toStdString());
    trecho->ProfundidadeInicial(ui->tblTrechos->item(row, 1)->text().toDouble());
    trecho->ProfundidadeFinal(ui->tblTrechos->item(row, 2)->text().toDouble());
    trecho->DiametroExterno(ui->tblTrechos->item(row, 3)->text().toDouble());
    trecho->DiametroInterno(ui->tblTrechos->item(row, 4)->text().toDouble());
    trecho->CoeficientePoisson(ui->tblTrechos->item(row, 5)->text().toDouble());
    trecho->CoeficienteExpancaoTermica(ui->tblTrechos->item(row, 6)->text().toDouble());
    trecho->ModuloEslasticidade(ui->tblTrechos->item(row, 7)->text().toDouble());
    trecho->PesoUnidade(ui->tblTrechos->item(row, 8)->text().toDouble());

    fluido->Nome(ui->tblFluidos->item(row, 0)->text().toStdString());
    fluido->Densidade(ui->tblFluidos->item(row, 1)->text().toDouble());
    fluido->Viscosidade(ui->tblFluidos->item(row, 2)->text().toDouble());

    // atualiza valores globais do simulador
    AtualizarDados();

    ui->statusbar->showMessage("Fluido e profundidades atualizados com sucesso!");
}
