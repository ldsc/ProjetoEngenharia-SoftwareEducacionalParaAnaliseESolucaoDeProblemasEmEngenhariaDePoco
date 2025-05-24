#include "CSimuladorReologico.h"
#include "ui_CSimuladorReologico.h"
#include "CJanelaAdicionarFluido.h"
#include "CJanelaGraficoPressaoHidroestatica.h"
#include "CJanelaSobreSoftware.h"

#include <iostream>
#include <fstream>
#include <sstream>
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

     makePlotPoco(); // gera o grafico inicial do poco (mesmo vazio)

    // ativa edicao de celulas da tabela com clique duplo ou tecla Enter
    ui->tblFluidos->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);

    // conecta a edicao de celulas na tabela a uma funcao que atualiza os dados do fluido
    connect(ui->tblFluidos, &QTableWidget::cellChanged, this, &CSimuladorReologico::EditarLinhaTabela);

    // conecta a alteracao dos campos de entrada para atualizar o objeto do poco
    connect(ui->editNomePoco, &QLineEdit::textChanged, this, &CSimuladorReologico::EditarDadosPoco);
    connect(ui->editProfundidadeTotal, &QLineEdit::textChanged, this, &CSimuladorReologico::EditarDadosPoco);
    connect(ui->editPressaoSuperficie, &QLineEdit::textChanged, this, &CSimuladorReologico::EditarDadosPoco);
    connect(ui->editDiametroPoco, &QLineEdit::textChanged, this, &CSimuladorReologico::EditarDadosPoco);
    connect(ui->editDiametroOD, &QLineEdit::textChanged, this, &CSimuladorReologico::EditarDadosPoco);
    connect(ui->editDiametroID, &QLineEdit::textChanged, this, &CSimuladorReologico::EditarDadosPoco);
    connect(ui->editVazao, &QLineEdit::textChanged, this, &CSimuladorReologico::EditarDadosPoco);


    // desativa todos os botoes de calculo inicialmente (só ativa quando preencher dados do poco)
    ui->btnCalcularPressaoHidroestatica->setEnabled(false);
    ui->btnCalcularModeloNewtonianoPoco->setEnabled(false);
    ui->btnCalcularModeloNewtonianoAnular->setEnabled(false);
    ui->btnCalcularModeloBighamPoco->setEnabled(false);
    ui->btnCalcularModeloBighamAnular->setEnabled(false);
    ui->btnCalcularModeloPotenciaPoco->setEnabled(false);
    ui->btnCalcularModeloPotenciaAnular->setEnabled(false);
    ui->btnExibirGraficoPressaoHidroestatica->setEnabled(false);

    // centraliza a janela no meio da tela do computador
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


void CSimuladorReologico::EditarDadosPoco() {
    // pega os valores digitados nos campos da interface
    QString nome = ui->editNomePoco->text();

    // cria variaveis booleanas pra saber se a conversao pra double deu certo
    bool ok1, ok2, ok3, ok4, ok5, ok6;

    // converte os textos digitados em numeros reais (double)
    double profund  = ui->editProfundidadeTotal->text().toDouble(&ok1);
    double pressao  = ui->editPressaoSuperficie->text().toDouble(&ok2);
    double diametro = ui->editDiametroPoco->text().toDouble(&ok3);
    double OD       = ui->editDiametroOD->text().toDouble(&ok4);
    double ID       = ui->editDiametroID->text().toDouble(&ok5);
    double vazao    = ui->editVazao->text().toDouble(&ok6);

    // verifica se todos os valores sao validos e o nome nao ta vazio
    if (!nome.isEmpty() && ok1 && ok2 && ok3 && ok4 && ok5 && ok6) {

        // se ainda nao tiver criado o objeto do poco, entao cria agora
        if (!poco) {
            poco = std::make_unique<CObjetoPoco>(
                CObjetoPoco::CriarParaModulo01(nome.toStdString(), profund, pressao, diametro, OD, ID, vazao)
                );

            // ativa os botoes de calculo, ja que agora temos um poco valido
            ui->btnCalcularPressaoHidroestatica->setEnabled(true);
            ui->btnCalcularModeloNewtonianoPoco->setEnabled(true);
            ui->btnCalcularModeloNewtonianoAnular->setEnabled(true);
            ui->btnCalcularModeloBighamPoco->setEnabled(true);
            ui->btnCalcularModeloBighamAnular->setEnabled(true);
            ui->btnCalcularModeloPotenciaPoco->setEnabled(true);
            ui->btnCalcularModeloPotenciaAnular->setEnabled(true);
            ui->btnExibirGraficoPressaoHidroestatica->setEnabled(true);

            ui->statusbar->showMessage("Poco criado com sucesso!");
        } else {
            // se o poco ja existe, entao atualiza os valores com os novos que o usuario digitou
            poco->NomePoco(nome.toStdString());
            poco->ProfundidadeTotal(profund);
            poco->PressaoSuperficie(pressao);
            poco->DiametroPoco(diametro);
            poco->DiametroRevestimentoOD(OD);
            poco->DiametroRevestimentoID(ID);
            poco->Vazao(vazao);

            ui->statusbar->showMessage("Dados de poco atualizados com sucesso!");
        }

        // atualiza a interface e os calculos apos alterar os dados
        AtualizarDados();
    }
}

void CSimuladorReologico::EditarLinhaTabela(int row)
{
    // pega o nome do fluido da linha editada da tabela
    QString nomeAlvo = ui->tblFluidos->item(row, 0)->text();

    // pega a lista de trechos do poco pra procurar qual fluido foi alterado
    std::vector<CTrechoPoco*> trechos = poco->Trechos();

    // percorre os trechos do poco pra encontrar o fluido correspondente
    for (CTrechoPoco* trecho : trechos) {
        CFluido* fluido = trecho->Fluido();

        // compara se o nome do fluido do trecho bate com o nome da linha da tabela
        if (fluido && QString::fromStdString(fluido->Nome()) == nomeAlvo) {

            // atualiza os valores do fluido com os dados editados na linha da tabela
            fluido->Nome(ui->tblFluidos->item(row, 0)->text().toStdString());
            fluido->Densidade(ui->tblFluidos->item(row, 1)->text().toDouble());
            fluido->Viscosidade(ui->tblFluidos->item(row, 2)->text().toDouble());

            // atualiza as profundidades do trecho correspondente a esse fluido
            trecho->ProfundidadeInicial(ui->tblFluidos->item(row, 3)->text().toDouble());
            trecho->ProfundidadeFinal(ui->tblFluidos->item(row, 4)->text().toDouble());

            break; // sai do loop pois ja achou e atualizou o fluido certo
        }
    }

    // atualiza os dados gerais na interface (como densidade e viscosidade media)
    AtualizarDados();

    // mostra mensagem informando que o fluido foi atualizado
    ui->statusbar->showMessage("Dados de fluido atualizado com sucesso!");
}


void CSimuladorReologico::AtualizarDados()
{
    // desativa os sinais da tabela temporariamente pra evitar chamadas de funcoes durante a atualizacao
    ui->tblFluidos->blockSignals(true);

    // verifica se o objeto poco ja foi criado (ou seja, se ja tem dados carregados)
    if (poco) {
        // atualiza os campos de entrada com os valores do objeto poco
        ui->editNomePoco->setText(QString::fromStdString(poco->NomePoco()));
        ui->editProfundidadeTotal->setText(QString::number(poco->ProfundidadeTotal()));
        ui->lbnProfundidadeOcupada->setText(QString::number(poco->ProfundidadeOcupada()));
        ui->editPressaoSuperficie->setText(QString::number(poco->PressaoSuperficie()));
        ui->editDiametroPoco->setText(QString::number(poco->DiametroPoco()));
        ui->editDiametroOD->setText(QString::number(poco->DiametroRevestimentoOD()));
        ui->editDiametroID->setText(QString::number(poco->DiametroRevestimentoID()));
        ui->editVazao->setText(QString::number(poco->Vazao()));
        ui->lbnDensidadeMedia->setText(QString::number(poco->DensidadeEfetivaTotal()));
        ui->lbnViscosidadeMedia->setText(QString::number(poco->ViscosidadeEfetivaTotal()));

        // atualiza o numero de linhas da tabela de fluidos de acordo com os trechos cadastrados no poco
        ui->tblFluidos->setRowCount(static_cast<int>(poco->Trechos().size()));

        // percorre os trechos do poco e preenche cada linha da tabela com os dados do fluido
        int row = 0;
        for (const auto& trecho : poco->Trechos()) {
            ui->tblFluidos->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(trecho->Fluido()->Nome())));
            ui->tblFluidos->setItem(row, 1, new QTableWidgetItem(QString::number(trecho->Fluido()->Densidade(), 'f', 2)));
            ui->tblFluidos->setItem(row, 2, new QTableWidgetItem(QString::number(trecho->Fluido()->Viscosidade(), 'f', 2)));
            ui->tblFluidos->setItem(row, 3, new QTableWidgetItem(QString::number(trecho->ProfundidadeInicial(), 'f', 2)));
            ui->tblFluidos->setItem(row, 4, new QTableWidgetItem(QString::number(trecho->ProfundidadeFinal(), 'f', 2)));
            ++row;
        }

        // atualiza o grafico visual do poco com base nos trechos e profundidades
        makePlotPoco();
    }

    // reativa os sinais da tabela agora que a atualizacao terminou
    ui->tblFluidos->blockSignals(false);
}

void CSimuladorReologico::on_btnAdicionarFluido_clicked()
{
    // desativa edicao direta da tabela (evita conflito enquanto adiciona novo fluido)
    ui->tblFluidos->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // se o poco ainda nao foi criado, nao permite adicionar fluido
    if (!poco) {
        QMessageBox::warning(this, "Erro", "As propriedade do poco precisa estar preenchida!");
    }
    else {
        // abre a janela onde o usuario preenche os dados do novo fluido
        CJanelaAdicionarFluido JanelaFluido;
        JanelaFluido.exec(); // abre em modo bloqueante (espera fechar)

        // so continua se todos os campos foram preenchidos
        if (JanelaFluido.NomeFluido() != "" &&
            JanelaFluido.Densidade() != "" &&
            JanelaFluido.Viscosidade() != "" &&
            JanelaFluido.ProfundidadeInicial() != "" &&
            JanelaFluido.ProfundidadeFinal() != "") {

            // adiciona uma nova linha na tabela da interface
            int numLinhas = ui->tblFluidos->rowCount();
            ui->tblFluidos->insertRow(numLinhas);
            ui->tblFluidos->setItem(numLinhas, 0, new QTableWidgetItem(JanelaFluido.NomeFluido()));
            ui->tblFluidos->setItem(numLinhas, 1, new QTableWidgetItem(JanelaFluido.Densidade()));
            ui->tblFluidos->setItem(numLinhas, 2, new QTableWidgetItem(JanelaFluido.Viscosidade()));
            ui->tblFluidos->setItem(numLinhas, 3, new QTableWidgetItem(JanelaFluido.ProfundidadeInicial()));
            ui->tblFluidos->setItem(numLinhas, 4, new QTableWidgetItem(JanelaFluido.ProfundidadeFinal()));

            // converte os valores da janela pra tipos numericos
            std::string nome = JanelaFluido.NomeFluido().toStdString();
            double densidade = JanelaFluido.Densidade().toDouble();
            double viscosidade = JanelaFluido.Viscosidade().toDouble();
            double profundInicial = JanelaFluido.ProfundidadeInicial().toDouble();
            double profundFinal = JanelaFluido.ProfundidadeFinal().toDouble();

            // cria o novo fluido e trecho com base nas informacoes
            auto fluido = std::make_unique<CFluido>(nome, densidade, viscosidade);
            auto trechoPoco = std::make_unique<CTrechoPoco>(profundInicial, profundFinal, std::move(fluido));
            poco->AdicionarTrechoPoco(std::move(trechoPoco)); // adiciona ao poco

            AtualizarDados(); // atualiza a interface com o novo trecho
            ui->statusbar->showMessage("Fluido adicionado com sucesso!");
        }
    }
}

void CSimuladorReologico::on_btnRemoverFluido_clicked()
{
    int linhaSelecionada = ui->tblFluidos->currentRow();

    // verifica se alguma linha foi selecionada
    if (linhaSelecionada >= 0) {
        QTableWidgetItem* item = ui->tblFluidos->item(linhaSelecionada, 0); // nome do fluido

        if (item) {
            // confirma se o usuario quer mesmo remover o fluido
            QMessageBox::StandardButton resposta = QMessageBox::question(
                this,
                "",
                "Tem certeza que deseja remover o fluido?",
                QMessageBox::Yes | QMessageBox::No
                );

            // se o usuario confirmar, remove o trecho do objeto poco e da tabela
            if (resposta == QMessageBox::Yes) {
                QString nomeFluido = item->text();
                ui->tblFluidos->removeRow(linhaSelecionada);
                poco->RemoverTrechoPoco(nomeFluido.toStdString());
                AtualizarDados();
                ui->statusbar->showMessage("Fluido removido com sucesso!");
            }
        }
    } else {
        // caso nenhuma linha esteja selecionada
        QMessageBox::warning(this, "Erro", "Selecione uma linha para deletar.");
    }
}

void CSimuladorReologico::on_btnCalcularPressaoHidroestatica_clicked()
{
    // pega a profundidade digitada pelo usuario
    QString profundidadeStr = ui->editProfundidadePressaoHidroestatica->text();
    double profundidade = profundidadeStr.toDouble();

    // calcula a pressao usando o objeto poco e mostra o valor no label
    ui->lbnPressaoHidroestatica->setText(
        QString::number(poco->PressaoHidroestaticaNoPonto(profundidade))
        );
}

void CSimuladorReologico::on_btnCalcularModeloNewtonianoPoco_clicked()
{
    // cria o modelo passando o objeto poco como base
    modeloNewtoniano = std::make_shared<CModeloNewtoniano>(poco.get());

    // atualiza os campos da interface com os resultados do modelo
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
    // verifica se os campos estao vazios e avisa o usuario se faltar algum dado
    if (ui->editPontoEscoamentoPoco->text().isEmpty() && ui->editViscosidadePlasticaPoco->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha o Ponto de Escoamento e a Viscosidade Plástica.");
    } else if (ui->editPontoEscoamentoPoco->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha o Ponto de Escoamento.");
    } else if (ui->editViscosidadePlasticaPoco->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha a Viscosidade Plástica.");
    } else {
        // se os dois valores estiverem preenchidos, converte para double
        double pontoEscoamento = ui->editPontoEscoamentoPoco->text().toDouble();
        double viscosidadePlastica = ui->editViscosidadePlasticaPoco->text().toDouble();

        // cria o modelo reologico de Bingham com os dados do poco e os parametros fornecidos
        modeloBingham = std::make_shared<CModeloBingham>(poco.get(), viscosidadePlastica, pontoEscoamento);

        // atualiza a interface com os resultados dos calculos no espaco do tubo
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
    // checa se os campos de entrada estao vazios e avisa o usuario
    if (ui->editPontoEscoamentoAnular->text().isEmpty() && ui->editViscosidadePlasticaAnular->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha o Ponto de Escoamento e a Viscosidade Plástica.");
    } else if (ui->editPontoEscoamentoAnular->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha o Ponto de Escoamento.");
    } else if (ui->editViscosidadePlasticaAnular->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha a Viscosidade Plástica.");
    } else {
        // converte os valores digitados para numeros reais
        double pontoEscoamento = ui->editPontoEscoamentoAnular->text().toDouble();
        double viscosidadePlastica = ui->editViscosidadePlasticaAnular->text().toDouble();

        // cria o modelo de Bingham para calcular no anular (entre tubo e revestimento)
        modeloBingham = std::make_shared<CModeloBingham>(poco.get(), viscosidadePlastica, pontoEscoamento);

        // preenche os campos com os valores calculados para o anular
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
    // verifica se o campo do indice de consistencia esta vazio
    if (ui->editIndiceConsistenciaPotenciaPoco->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha o Indice de Consistencia.");
    } else {
        // se estiver preenchido, converte pra double
        double indiceConsistencia = ui->editIndiceConsistenciaPotenciaPoco->text().toDouble();

        // cria o modelo da lei da potencia com o indice fornecido
        modeloPotencia = std::make_shared<CModeloPotencia>(poco.get(), indiceConsistencia);

        // atualiza os campos da interface com os valores calculados no espaco do tubo
        ui->lbnVelocidadePocoPotencia->setText(QString::number(modeloPotencia->VMediaPoco()));
        ui->lbnReynoldsPocoPotencia->setText(QString::number(modeloPotencia->ReynoldsPoco()));
        ui->lbnReynoldsCriticoPocoPotencia->setText(QString::number(modeloPotencia->ReynoldsCriticoPoco()));
        ui->lbnTipoFluxoPocoPotencia->setText(QString::fromStdString(modeloPotencia->FluxoPoco()));
        ui->lbnPerdaFriccionalPocoPotencia->setText(QString::number(modeloPotencia->CalcularPerdaPorFriccaoPoco()));
    }
}

void CSimuladorReologico::on_btnCalcularModeloPotenciaAnular_clicked()
{
    // verifica se o campo do indice de consistencia do anular esta vazio
    if (ui->editIndiceConsistenciaPotenciaAnular->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Aviso", "Preencha o Indice de Consistencia.");
    } else {
        // se estiver preenchido, converte pra double
        double indiceConsistencia = ui->editIndiceConsistenciaPotenciaAnular->text().toDouble();

        // cria o modelo da lei da potencia com os dados do poco
        modeloPotencia = std::make_shared<CModeloPotencia>(poco.get(), indiceConsistencia);

        // atualiza os campos com os resultados dos calculos no anular
        ui->lbnVelocidadeAnularPotencia->setText(QString::number(modeloPotencia->VMediaAnular()));
        ui->lbnReynoldsAnularPotencia->setText(QString::number(modeloPotencia->ReynoldsAnular()));
        ui->lbnReynoldsCriticoAnularPotencia->setText(QString::number(modeloPotencia->ReynoldsCriticoAnular()));
        ui->lbnTipoFluxoAnularPotencia->setText(QString::fromStdString(modeloPotencia->FluxoAnular()));
        ui->lbnPerdaFriccionalAnularPotencia->setText(QString::number(modeloPotencia->CalcularPerdaPorFriccaoAnular()));
    }
}

void CSimuladorReologico::makePlotPoco()
{
    // limpa o grafico anterior (caso ja tenha algo desenhado)
    ui->customPlotPoco->clearItems();

    // configura os nomes dos eixos
    ui->customPlotPoco->xAxis->setLabel("Diametro do Poco (m)");
    ui->customPlotPoco->yAxis->setLabel("Profundidade (m)");

    // define uma faixa inicial de visualizacao nos eixos
    ui->customPlotPoco->xAxis->setRange(-10, 10);   // largura do poco no grafico
    ui->customPlotPoco->yAxis->setRange(0, 300);    // profundidade inicial do grafico
    ui->customPlotPoco->yAxis->setRangeReversed(true); // deixa o zero em cima e profundidade pra baixo

    // verifica se o objeto poco existe e se ja tem trechos adicionados
    if (!poco || poco->Trechos().empty()) {
        return; // nao desenha nada se o poco nao estiver pronto
    }

    // pega a maior profundidade entre todos os trechos pra ajustar o eixo Y
    double profundidadeMaxima = 0.0;
    for (const auto& trecho : poco->Trechos()) {
        if (trecho->ProfundidadeFinal() > profundidadeMaxima) {
            profundidadeMaxima = trecho->ProfundidadeFinal();
        }
    }
    ui->customPlotPoco->yAxis->setRange(0, profundidadeMaxima);

    // cria um mapa que associa um nome de fluido a uma cor
    QMap<QString, QColor> mapaCores;

    // define algumas cores diferentes pra usar nos fluidos
    QVector<QColor> coresDisponiveis = {
        QColor(255, 0, 0, 150),    // vermelho claro
        QColor(0, 255, 0, 150),    // verde claro
        QColor(0, 0, 255, 150),    // azul claro
        QColor(255, 165, 0, 150),  // laranja
        QColor(128, 0, 128, 150),  // roxo
        QColor(0, 255, 255, 150)   // ciano
    };
    int corIndex = 0;

    // para cada trecho do poco, desenha um retangulo com o fluido correspondente
    for (const auto& trecho : poco->Trechos()) {
        double profundInicial = trecho->ProfundidadeInicial();
        double profundFinal = trecho->ProfundidadeFinal();
        double diametroPoco = 8.0;  // valor fixo usado aqui como referencia visual
        double diametroSecao = 6.0; // o diametro da tubulacao eh menor que o do buraco
        QString nomeFluido = QString::fromStdString(trecho->Fluido()->Nome());

        // se for a primeira vez que esse fluido aparece, define uma cor nova pra ele
        if (!mapaCores.contains(nomeFluido)) {
            mapaCores[nomeFluido] = coresDisponiveis[corIndex % coresDisponiveis.size()];
            corIndex++;
        }
        QColor corFluido = mapaCores[nomeFluido];

        // desenha o buraco do poco (cinza claro)
        QCPItemRect *retanguloPoco = new QCPItemRect(ui->customPlotPoco);
        retanguloPoco->topLeft->setCoords(-diametroPoco / 2, profundInicial);
        retanguloPoco->bottomRight->setCoords(diametroPoco / 2, profundFinal);
        retanguloPoco->setPen(QPen(Qt::black));
        retanguloPoco->setBrush(QBrush(QColor(150, 150, 150, 100))); // cinza transparente

        // desenha a tubulacao com o fluido dentro (com a cor do fluido)
        QCPItemRect *retanguloSecao = new QCPItemRect(ui->customPlotPoco);
        retanguloSecao->topLeft->setCoords(-diametroSecao / 2, profundInicial);
        retanguloSecao->bottomRight->setCoords(diametroSecao / 2, profundFinal);
        retanguloSecao->setPen(QPen(Qt::black));
        retanguloSecao->setBrush(QBrush(corFluido));

        // coloca o nome do fluido centralizado na altura da secao
        QCPItemText *rotulo = new QCPItemText(ui->customPlotPoco);
        rotulo->position->setCoords(0, (profundInicial + profundFinal) / 2); // centro vertical
        rotulo->setText(nomeFluido);
        rotulo->setFont(QFont("Arial", 10, QFont::Bold));
        rotulo->setColor(Qt::black);
        rotulo->setPositionAlignment(Qt::AlignCenter);
    }

    // redesenha o grafico com os novos elementos
    ui->customPlotPoco->replot();
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
    CJanelaSobreSofware janelaSobre;
    janelaSobre.setWindowTitle("Sobre o Software");
    janelaSobre.exec();
}


void CSimuladorReologico::on_actionSalvar_Como_triggered()
{
    QString caminho = CaminhoArquivo();

    // Se o caminho ainda nao existe, pede para o usuario escolher
    if (caminho.isEmpty()) {
        caminho = QFileDialog::getSaveFileName(this, "Salvar Arquivo", "", "Arquivo DAT (*.dat)");
        if (caminho.isEmpty()) return; // Usuario cancelou
    }

    QFile arquivo(caminho);
    if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Erro", "Nao foi possivel salvar o arquivo.");
        return;
    }

    QTextStream out(&arquivo);

    // Escreve os dados do pouco
    out << "# Configuracao do Poco ------------------------------------------------------------------------------------\n";
    out << "# Nome                 Profundidade (ft)    Pressao Superficial (psi)    Diametro (in)    OD (in)    ID (in)    Vazao (bbl/d)\n";
    out << ui->editNomePoco->text() << "           ";
    out << ui->editProfundidadeTotal->text() << "                ";
    out << ui->editPressaoSuperficie->text() << "                         ";
    out << ui->editDiametroPoco->text() << "             ";
    out << ui->editDiametroOD->text() << "       ";
    out << ui->editDiametroID->text() << "       ";
    out << ui->editVazao->text() << "       ";

    // Escreve os dados dos fluidos
    out << "\n\n\n# Configuracao dos Fluidos --------------------------------------------------------------------------------\n";
    out << "# Nome       Densidade (lbm/gal)    Viscosidade (cP)    Prof. Inicial (ft)    Prof. Final (ft)\n";
    int linhas = ui->tblFluidos->rowCount();
    for (int i = 0; i < linhas; ++i) {
        out << ui->tblFluidos->item(i, 0)->text() << "        "
            << ui->tblFluidos->item(i, 1)->text() << "                    "
            << ui->tblFluidos->item(i, 2)->text() << "                 "
            << ui->tblFluidos->item(i, 3)->text() << "                  "
            << ui->tblFluidos->item(i, 4)->text() << "\n";
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

void CSimuladorReologico::on_actionArquivo_dat_triggered()
{
    // Abre uma janelinha pra o usuario escolher o arquivo que ele quer carregar
    QString caminhoDoArquivo = QFileDialog::getOpenFileName(
        this,
        "Selecione um arquivo",
        "",
        "Todos os arquivos (*.*)"
        );

    // Converte o caminho pra string padrao do C++ (std::string)
    std::string caminhoDoArquivoStr = caminhoDoArquivo.toStdString();

    // Abre o arquivo selecionado pra leitura
    std::ifstream file(caminhoDoArquivoStr);

    std::string linha;
    bool lendoFluidos = false; // começa assumindo que vamos ler os dados do poço

    // le linha por linha do arquivo
    while (std::getline(file, linha)) {
        // ignora linhas em branco ou que comecam com '#' (comentario)
        if (linha.empty() || linha[0] == '#') {
            // se encontrar a palavra "Fluidos", troca pro modo de leitura dos fluidos
            if (linha.find("Fluidos") != std::string::npos) {
                lendoFluidos = true;
            }
            continue;
        }

        // se ainda estamos lendo os dados do poço (linha unica)
        if (!lendoFluidos) {
            std::istringstream iss(linha); // transforma a linha em stream pra extrair os dados
            std::string nome;
            double profundidade, pressaoSuperficie, diametro, OD, ID, vazao;

            // extrai os valores na ordem correta
            if (iss >> nome >> profundidade >> pressaoSuperficie >> diametro >> OD >> ID >> vazao) {

                // ativa os botoes de calculo, ja que agora temos um poço valido
                ui->btnCalcularPressaoHidroestatica->setEnabled(true);
                ui->btnCalcularModeloNewtonianoPoco->setEnabled(true);
                ui->btnCalcularModeloNewtonianoAnular->setEnabled(true);
                ui->btnCalcularModeloBighamPoco->setEnabled(true);
                ui->btnCalcularModeloBighamAnular->setEnabled(true);
                ui->btnCalcularModeloPotenciaPoco->setEnabled(true);
                ui->btnCalcularModeloPotenciaAnular->setEnabled(true);
                ui->btnExibirGraficoPressaoHidroestatica->setEnabled(true);

                // cria o objeto do poço com os dados lidos
                poco = std::make_unique<CObjetoPoco>(
                    CObjetoPoco::CriarParaModulo01(nome, profundidade, pressaoSuperficie, diametro, OD, ID, vazao)
                    );
            }

        } else {
            // aqui ja estamos lendo os trechos dos fluidos
            std::istringstream iss(linha);
            std::string nome;
            double densidade, viscosidade, profInicial, profFinal;

            // le os valores do fluido e da faixa de profundidade
            if (iss >> nome >> densidade >> viscosidade >> profInicial >> profFinal) {
                auto fluido = std::make_unique<CFluido>(nome, densidade, viscosidade);
                auto trechoPoco = std::make_unique<CTrechoPoco>(profInicial, profFinal, std::move(fluido));

                // adiciona o trecho no objeto do poço
                poco->AdicionarTrechoPoco(std::move(trechoPoco));
            }
        }
    }

    file.close(); // fecha o arquivo depois de terminar a leitura

    // atualiza a interface com os dados lidos
    AtualizarDados();
    ui->statusbar->showMessage("Dados importados com sucesso!");

    NomeArquivo(QFileInfo(caminhoDoArquivo).fileName());
    CaminhoArquivo(caminhoDoArquivo);
}


void CSimuladorReologico::on_btnExibirGraficoPressaoHidroestatica_clicked()
{
    CJanelaGraficoPressaoHidroestatica grafico(poco->PlotarProfundidadePorPressaoMedia());
    grafico.exec();
    ui->statusbar->showMessage("Dados Plotador com Sucesso!");
}


void CSimuladorReologico::on_actionSalvar_triggered()
{
    // Se ja existe um caminho, salva diretamente
    if (!CaminhoArquivo().isEmpty()) {
        // Simula um "salvar como" com o caminho ja definido
        on_actionSalvar_Como_triggered();
    } else {
        // Se ainda nao foi salvo antes, forca o usuario a escolher um caminho
        on_actionSalvar_Como_triggered();
    }
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


