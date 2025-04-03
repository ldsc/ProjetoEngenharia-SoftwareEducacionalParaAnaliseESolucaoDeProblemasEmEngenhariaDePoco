#include "CSimuladorPerdaTubulacao.h"
#include "ui_CSimuladorPerdaTubulacao.h"
#include "CJanelaAdicionarFluido.h"
#include "CJanelaAdicionarTrechoTubulacao.h"

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

    //abrir janela no meio do monitor
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;

    this->move(x, y);

    makePlotTemperatura();
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


void CSimuladorPerdaTubulacao::on_btnAdicionarTrecho_clicked()
{
    ui->tblFluidos->setEditTriggers(QAbstractItemView::NoEditTriggers);

    if (!poco) {
        QMessageBox::warning(this, "Erro", "As propriedade do poço precisa está preenchida!");
    }

    else{
        CJanelaAdicionarTrechoTubulacao JanelaTrecho;
        JanelaTrecho.exec();

        if (JanelaTrecho.getTrecho() != "" &&
            JanelaTrecho.getProfundidadeInicial() != "" &&
            JanelaTrecho.getProfundidadeFinal() != "" &&
            JanelaTrecho.getDiametroExterno() != "" &&
            JanelaTrecho.getDiametroInterno() != "" &&
            JanelaTrecho.getCoeficientePoisson() != "" &&
            JanelaTrecho.getCoeficienteExpansaoTermica() != "" &&
            JanelaTrecho.getModuloElasticidade() != "" &&
            JanelaTrecho.getPesoUnidade() != ""){


            int numLinhas = ui->tblTrechos->rowCount();
            ui->tblTrechos->insertRow(numLinhas);
            ui->tblTrechos->setItem(numLinhas, 0, new QTableWidgetItem(JanelaTrecho.getTrecho()));
            ui->tblTrechos->setItem(numLinhas, 1, new QTableWidgetItem(JanelaTrecho.getProfundidadeInicial()));
            ui->tblTrechos->setItem(numLinhas, 2, new QTableWidgetItem(JanelaTrecho.getProfundidadeFinal()));
            ui->tblTrechos->setItem(numLinhas, 3, new QTableWidgetItem(JanelaTrecho.getDiametroExterno()));
            ui->tblTrechos->setItem(numLinhas, 4, new QTableWidgetItem(JanelaTrecho.getDiametroInterno()));
            ui->tblTrechos->setItem(numLinhas, 4, new QTableWidgetItem(JanelaTrecho.getCoeficientePoisson()));
            ui->tblTrechos->setItem(numLinhas, 4, new QTableWidgetItem(JanelaTrecho.getCoeficienteExpansaoTermica()));
            ui->tblTrechos->setItem(numLinhas, 4, new QTableWidgetItem(JanelaTrecho.getModuloElasticidade()));
            ui->tblTrechos->setItem(numLinhas, 4, new QTableWidgetItem(JanelaTrecho.getPesoUnidade()));
            
            std::string trecho = JanelaTrecho.getTrecho().toStdString();
            double profundInicial = JanelaTrecho.getProfundidadeInicial().toDouble();
            double profundFinal = JanelaTrecho.getProfundidadeFinal().toDouble();
            double diametroExterno = JanelaTrecho.getDiametroExterno().toDouble();
            double diametroInterno = JanelaTrecho.getDiametroInterno().toDouble();
            double coeficientePoisson = JanelaTrecho.getCoeficientePoisson().toDouble();
            double coeficienteExpansaoTermica = JanelaTrecho.getCoeficienteExpansaoTermica().toDouble();
            double moduloElasticidade = JanelaTrecho.getModuloElasticidade().toDouble();
            double pesoUnidade = JanelaTrecho.getPesoUnidade().toDouble();

            auto trechoPoco = std::make_unique<CTrechoPoco>(trecho, profundInicial, profundFinal, diametroExterno, diametroInterno, coeficientePoisson, coeficienteExpansaoTermica, moduloElasticidade, pesoUnidade);
            poco->AdicionarTrechoPoco(std::move(trechoPoco));

            on_btnAtualizarDados_clicked();
        }
    }
}

void CSimuladorPerdaTubulacao::makePlotTemperatura()
{
    // Limpar o gráfico anterior
    ui->customPlotTemperatura->clearItems();
    ui->customPlotTemperatura->clearPlottables();

    // Configurar os eixos
    ui->customPlotTemperatura->xAxis->setLabel("Temperatura (°F)");
    ui->customPlotTemperatura->yAxis->setLabel("Profundidade (ft)");
    ui->customPlotTemperatura->yAxis->setRangeReversed(true); // profundidade cresce para baixo

    // Definir os pontos do perfil de temperatura
    QVector<double> temperaturas = {50, 175, 300};     // Temperaturas em °F
    QVector<double> profundidades = {0, 4000, 8000};    // Profundidades em ft

    // Ajustar ranges com base nos dados
    double tempMin = *std::min_element(temperaturas.begin(), temperaturas.end());
    double tempMax = *std::max_element(temperaturas.begin(), temperaturas.end());
    double profMin = 0;
    double profMax = *std::max_element(profundidades.begin(), profundidades.end());

    ui->customPlotTemperatura->xAxis->setRange(tempMin - 20, tempMax + 20);
    ui->customPlotTemperatura->yAxis->setRange(profMin, profMax);

    // Criar linha do perfil de temperatura (vermelha)
    QCPGraph *perfilTemp = ui->customPlotTemperatura->addGraph();
    perfilTemp->setData(temperaturas, profundidades);
    perfilTemp->setPen(QPen(Qt::red, 2));
    perfilTemp->setName("Condição inicial");

    // Criar linha azul vertical (por exemplo, linha guia em 50°F)
    double linhaAzulX = 50; // ou alguma variável
    QCPItemLine *linhaAzul = new QCPItemLine(ui->customPlotTemperatura);
    linhaAzul->start->setCoords(linhaAzulX, profMin);
    linhaAzul->end->setCoords(linhaAzulX, profMax);
    linhaAzul->setPen(QPen(Qt::blue, 1, Qt::SolidLine));

    // Adicionar texto "condição inicial"
    QCPItemText *label = new QCPItemText(ui->customPlotTemperatura);
    label->position->setCoords(temperaturas[0] + 10, profundidades[1]); // próximo ao meio
    label->setText("condição inicial");
    label->setFont(QFont("Arial", 10));
    label->setColor(Qt::red);

    // Marcar os pontos principais
    for (int i = 0; i < temperaturas.size(); ++i) {
        QCPItemEllipse *ponto = new QCPItemEllipse(ui->customPlotTemperatura);
        ponto->topLeft->setCoords(temperaturas[i] - 5, profundidades[i] - 100);
        ponto->bottomRight->setCoords(temperaturas[i] + 5, profundidades[i] + 100);
        ponto->setPen(QPen(Qt::black));
        ponto->setBrush(Qt::gray);

        QCPItemText *rotulo = new QCPItemText(ui->customPlotTemperatura);
        rotulo->position->setCoords(temperaturas[i], profundidades[i]);
        rotulo->setText(QString::number(temperaturas[i]) + "°F");
        rotulo->setFont(QFont("Arial", 9));
        rotulo->setPositionAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    }

    // Atualizar o gráfico
    ui->customPlotTemperatura->replot();
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
            QString nomeFluido = item->text();
            ui->tblTrechos->removeRow(linhaSelecionada);
            poco->RemoverTrechoPoco(nomeFluido.toStdString());
            on_btnAtualizarDados_clicked();
        }

    } else {
        QMessageBox::warning(this, "Erro", "Selecione uma linha para deletar.");
    }
}

