#include "CSimuladorPerdaTubulacao.h"
#include "ui_CSimuladorPerdaTubulacao.h"
#include "CJanelaAdicionarFluido.h"
#include "CJanelaAdicionarTrechoTubulacao.h"

CSimuladorPerdaTubulacao::CSimuladorPerdaTubulacao(QWidget *parent)
    : QMainWindow(parent)
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

    makePlotPoco();
}

CSimuladorPerdaTubulacao::~CSimuladorPerdaTubulacao()
{
    delete ui;
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
            poco = std::make_shared<CPoco>(nome, profundidade, pressaoSup, temperaturaSuperiorInicial, temperaturaFundoInicial, temperaturaSuperiorFinal, temperaturaFundoFinal);
        }
        on_btnAtualizarDados_clicked();
    } else {
        poco = std::make_shared<CPoco>(nome, profundidade, pressaoSup, temperaturaSuperiorInicial, temperaturaFundoInicial, temperaturaSuperiorFinal, temperaturaFundoFinal);
    }

    makePlotTemperatura(temperaturaSuperiorInicial, temperaturaFundoInicial, profundidade, ui->customPlotTemperaturaInicial);
    makePlotTemperatura(temperaturaSuperiorFinal, temperaturaFundoFinal, profundidade, ui->customPlotTemperaturaFinal);
    makePlotPoco();
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
    makePlotPoco();

}


void CSimuladorPerdaTubulacao::on_btnAdicionarTrecho_clicked()
{
    ui->tblTrechos->setEditTriggers(QAbstractItemView::NoEditTriggers);

    if (!poco) {
        QMessageBox::warning(this, "Erro", "As propriedade do poço precisa está preenchida!");
    }

    else{
        qDebug() << "1";
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

            qDebug() << JanelaTrecho.getProfundidadeInicial();

            int numLinhas = ui->tblTrechos->rowCount();
            ui->tblTrechos->insertRow(numLinhas);
            ui->tblTrechos->setItem(numLinhas, 0, new QTableWidgetItem(JanelaTrecho.getTrecho()));
            ui->tblTrechos->setItem(numLinhas, 1, new QTableWidgetItem(JanelaTrecho.getProfundidadeInicial()));
            ui->tblTrechos->setItem(numLinhas, 2, new QTableWidgetItem(JanelaTrecho.getProfundidadeFinal()));
            ui->tblTrechos->setItem(numLinhas, 3, new QTableWidgetItem(JanelaTrecho.getDiametroExterno()));
            ui->tblTrechos->setItem(numLinhas, 4, new QTableWidgetItem(JanelaTrecho.getDiametroInterno()));
            ui->tblTrechos->setItem(numLinhas, 5, new QTableWidgetItem(JanelaTrecho.getCoeficientePoisson()));
            ui->tblTrechos->setItem(numLinhas, 6, new QTableWidgetItem(JanelaTrecho.getCoeficienteExpansaoTermica()));
            ui->tblTrechos->setItem(numLinhas, 7, new QTableWidgetItem(JanelaTrecho.getModuloElasticidade()));
            ui->tblTrechos->setItem(numLinhas, 8, new QTableWidgetItem(JanelaTrecho.getPesoUnidade()));

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
            QString nomeFluido = item->text();
            ui->tblTrechos->removeRow(linhaSelecionada);
            poco->RemoverTrechoPoco(nomeFluido.toStdString());
            on_btnAtualizarDados_clicked();
        }

    } else {
        QMessageBox::warning(this, "Erro", "Selecione uma linha para deletar.");
    }
}

void CSimuladorPerdaTubulacao::makePlotPoco()
{
    ui->customPlotPoco->clearItems();

    ui->customPlotPoco->xAxis->setLabel("Diâmetro do Poço (in)");
    ui->customPlotPoco->yAxis->setLabel("Profundidade (ft)");
    ui->customPlotPoco->xAxis->setRange(-10, 10);
    ui->customPlotPoco->yAxis->setRange(0, 300);
    ui->customPlotPoco->yAxis->setRangeReversed(true);

    if (!poco || poco->Trechos().empty())
        return;

    double profundidadeMaxima = 0.0;
    double maiorDiametroExterno = 0.0;
    for (const auto& trecho : poco->Trechos()) {
        profundidadeMaxima = std::max(profundidadeMaxima, trecho->ProfundidadeFinal());
        maiorDiametroExterno = std::max(maiorDiametroExterno, trecho->DiametroExterno());
    }

    double diametroBuraco = maiorDiametroExterno + 5;
    ui->customPlotPoco->yAxis->setRange(0, profundidadeMaxima);

    // Desenhar trechos
    for (const auto& trecho : poco->Trechos()) {
        double z0 = trecho->ProfundidadeInicial();
        double z1 = trecho->ProfundidadeFinal();
        double d_ext = trecho->DiametroExterno();
        double d_int = trecho->DiametroInterno();
        QString nome = QString::fromStdString(trecho->Trecho());

        auto* fundo = new QCPItemRect(ui->customPlotPoco);
        fundo->topLeft->setCoords(-diametroBuraco / 2, z0);
        fundo->bottomRight->setCoords(diametroBuraco / 2, z1);
        fundo->setPen(Qt::NoPen);
        fundo->setBrush(QColor("#E6E6E6"));

        auto* parede = new QCPItemRect(ui->customPlotPoco);
        parede->topLeft->setCoords(-d_ext / 2, z0);
        parede->bottomRight->setCoords(d_ext / 2, z1);
        parede->setPen(QPen(Qt::black));
        parede->setBrush(QColor("#999999"));

        auto* fluido = new QCPItemRect(ui->customPlotPoco);
        fluido->topLeft->setCoords(-d_int / 2, z0);
        fluido->bottomRight->setCoords(d_int / 2, z1);
        fluido->setPen(Qt::NoPen);
        fluido->setBrush(QColor("#E6E6E6"));

        auto* texto = new QCPItemText(ui->customPlotPoco);
        texto->position->setCoords(0, (z0 + z1) / 2);
        texto->setText(nome);
        texto->setFont(QFont("Arial", 10, QFont::Bold));
        texto->setColor(Qt::black);
        texto->setPositionAlignment(Qt::AlignCenter);
    }

    // Determinar altura visual do crossover baseada na menor seção
    double menorAltura = std::numeric_limits<double>::max();
    for (const auto& trecho : poco->Trechos()) {
        double altura = trecho->ProfundidadeFinal() - trecho->ProfundidadeInicial();
        if (altura < menorAltura) menorAltura = altura;
    }
    double h = std::min(50.0, menorAltura * 0.2);  // até 50 ft ou 20% da menor seção

    // Desenhar crossovers com QCPItemLine (versão compatível com QCustomPlot 1.x)
    for (size_t i = 0; i + 1 < poco->Trechos().size(); ++i) {
        auto& t1 = poco->Trechos()[i];
        auto& t2 = poco->Trechos()[i + 1];

        double z = t1->ProfundidadeFinal();
        double d1 = t1->DiametroExterno();
        double d2 = t2->DiametroExterno();

        if (d1 == d2) continue;

        // Lado esquerdo
        auto* l1 = new QCPItemLine(ui->customPlotPoco);
        l1->start->setCoords(-d1 / 2, z);
        l1->end->setCoords(-d2 / 2, z + h);
        l1->setPen(QPen(Qt::black));

        auto* l2 = new QCPItemLine(ui->customPlotPoco);
        l2->start->setCoords(-d2 / 2, z + h);
        l2->end->setCoords(-d1 / 2, z);
        l2->setPen(QPen(Qt::black));

        // Lado direito
        auto* r1 = new QCPItemLine(ui->customPlotPoco);
        r1->start->setCoords(d1 / 2, z);
        r1->end->setCoords(d2 / 2, z + h);
        r1->setPen(QPen(Qt::black));

        auto* r2 = new QCPItemLine(ui->customPlotPoco);
        r2->start->setCoords(d2 / 2, z + h);
        r2->end->setCoords(d1 / 2, z);
        r2->setPen(QPen(Qt::black));
    }

    // Desenhar packer se habilitado
    if (ui->checkBoxPacker->isChecked()) {
        double prof = ui->editProfundidadePacker->text().toDouble();
        double altura = 0.5;
        double d_poco = maiorDiametroExterno;

        for (const auto& trecho : poco->Trechos()) {
            if (trecho->ProfundidadeInicial() <= prof && prof <= trecho->ProfundidadeFinal()) {
                d_poco = trecho->DiametroExterno();
                break;
            }
        }

        auto* retEsq = new QCPItemRect(ui->customPlotPoco);
        retEsq->topLeft->setCoords(-diametroBuraco / 2, prof - altura / 2);
        retEsq->bottomRight->setCoords(-d_poco / 2, prof + altura / 2);
        retEsq->setPen(QPen(Qt::black));
        retEsq->setBrush(Qt::white);

        auto* x1 = new QCPItemLine(ui->customPlotPoco);
        x1->start->setCoords(-diametroBuraco / 2, prof - altura / 2);
        x1->end->setCoords(-d_poco / 2, prof + altura / 2);
        x1->setPen(QPen(Qt::black));

        auto* x2 = new QCPItemLine(ui->customPlotPoco);
        x2->start->setCoords(-d_poco / 2, prof - altura / 2);
        x2->end->setCoords(-diametroBuraco / 2, prof + altura / 2);
        x2->setPen(QPen(Qt::black));

        auto* retDir = new QCPItemRect(ui->customPlotPoco);
        retDir->topLeft->setCoords(d_poco / 2, prof - altura / 2);
        retDir->bottomRight->setCoords(diametroBuraco / 2, prof + altura / 2);
        retDir->setPen(QPen(Qt::black));
        retDir->setBrush(Qt::white);

        auto* x3 = new QCPItemLine(ui->customPlotPoco);
        x3->start->setCoords(d_poco / 2, prof - altura / 2);
        x3->end->setCoords(diametroBuraco / 2, prof + altura / 2);
        x3->setPen(QPen(Qt::black));

        auto* x4 = new QCPItemLine(ui->customPlotPoco);
        x4->start->setCoords(diametroBuraco / 2, prof - altura / 2);
        x4->end->setCoords(d_poco / 2, prof + altura / 2);
        x4->setPen(QPen(Qt::black));
    }

    ui->customPlotPoco->replot();
}
