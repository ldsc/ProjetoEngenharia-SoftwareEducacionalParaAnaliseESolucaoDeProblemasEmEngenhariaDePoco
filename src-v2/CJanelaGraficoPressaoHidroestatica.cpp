#include "CJanelaGraficoPressaoHidroestatica.h"
#include "ui_CJanelaGraficoPressaoHidroestatica.h"
#include <QFileDialog>
#include <QMessageBox>
#include <algorithm>

// Construtor: recebe os dados de profundidade e pressao e plota o grafico
CJanelaGraficoPressaoHidroestatica::CJanelaGraficoPressaoHidroestatica(
    const std::pair<std::vector<double>, std::vector<double>>& dados,
    QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CJanelaGraficoPressaoHidroestatica)
    , profundidades(dados.first)
    , pressoes(dados.second)
{
    ui->setupUi(this);
    PlotarGraficoPressaoxProfundidade();
}

// Destrutor: libera memoria
CJanelaGraficoPressaoHidroestatica::~CJanelaGraficoPressaoHidroestatica()
{
    delete ui;
}

// Permite atualizar os dados apos a criacao da janela
void CJanelaGraficoPressaoHidroestatica::PerfilHidrostatico(
    const std::pair<std::vector<double>, std::vector<double>>& novoPerfil)
{
    profundidades = novoPerfil.first;
    pressoes = novoPerfil.second;
    PlotarGraficoPressaoxProfundidade();
}

// Funcao que plota o grafico com base na relacao profundidade x pressao
// Parte da logica para segmentacao por inclinacao foi adaptada com auxilio de IA (ChatGPT)
void CJanelaGraficoPressaoHidroestatica::PlotarGraficoPressaoxProfundidade()
{
    //QVector<double> x(profundidades.begin(), profundidades.end());
    QVector<double> x = QVector<double>::fromStdVector(profundidades);
    //QVector<double> y(pressoes.begin(), pressoes.end());
    QVector<double> y = QVector<double>::fromStdVector(pressoes);

    auto *plot = ui->customPlotPressaoMediaProfundidade;
    plot->clearGraphs();

    QVector<double> trechoX, trechoY;

    // Funcao lambda para comparar inclinacao entre segmentos
    auto isMesmaInclinacao = [](double dy1, double dy2, double tolerancia) {
        return std::abs(dy1 - dy2) < tolerancia;
    };

    double tolerancia = 1e-2;
    double inclinacaoAnterior = (y[1] - y[0]) / (x[1] - x[0]);

    trechoX.push_back(x[0]);
    trechoY.push_back(y[0]);

    for (int i = 1; i < x.size(); ++i) {
        double inclinacaoAtual = (y[i] - y[i - 1]) / (x[i] - x[i - 1]);

        // Se mudou muito a inclinacao, cria um novo trecho no grafico
        if (!isMesmaInclinacao(inclinacaoAtual, inclinacaoAnterior, tolerancia)) {
            int index = plot->graphCount();
            plot->addGraph();
            plot->graph(index)->setData(trechoX, trechoY);

            // Uso de cor e estilo dinamico inspirado em sugestao de IA para melhorar visualizacao
            QPen pen;
            pen.setWidth(1);
            pen.setColor(QColor::fromHsv((index * 70) % 360, 255, 200));
            plot->graph(index)->setPen(pen);

            QCPScatterStyle estilo(QCPScatterStyle::ssCircle, 4);
            plot->graph(index)->setScatterStyle(estilo);
            plot->graph(index)->setLineStyle(QCPGraph::lsLine);

            plot->graph(index)->setName(QString("Fluido %1").arg(index + 1));

            trechoX.clear();
            trechoY.clear();
        }

        trechoX.push_back(x[i]);
        trechoY.push_back(y[i]);
        inclinacaoAnterior = inclinacaoAtual;
    }

    // adiciona ultimo trecho
    int index = plot->graphCount();
    plot->addGraph();
    plot->graph(index)->setData(trechoX, trechoY);

    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor::fromHsv((index * 70) % 360, 255, 200));
    plot->graph(index)->setPen(pen);

    QCPScatterStyle estilo(QCPScatterStyle::ssCircle, 4);
    plot->graph(index)->setScatterStyle(estilo);
    plot->graph(index)->setLineStyle(QCPGraph::lsLine);
    plot->graph(index)->setName(QString("Fluido %1").arg(index + 1));

    // Configura rotulos dos eixos
    plot->xAxis->setLabel("Profundidade (ft)");
    plot->yAxis->setLabel("Pressão Hidrostática (psi)");

    // Define o intervalo dos eixos com base nos dados
    plot->xAxis->setRange(*std::min_element(x.begin(), x.end()),
                          *std::max_element(x.begin(), x.end()));
    plot->yAxis->setRange(*std::min_element(y.begin(), y.end()),
                          *std::max_element(y.begin(), y.end()));

    // Legenda posicionada no canto inferior direito
    plot->legend->setVisible(true);
    plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight | Qt::AlignBottom);
    plot->legend->setBrush(QBrush(Qt::white));
    plot->legend->setBorderPen(QPen(Qt::gray));
    plot->legend->setFont(QFont("Arial", 9));

    // Ativacao do zoom, arrastar e selecao com mouse (configuracao sugerida com base em IA)
    plot->setInteraction(QCP::iRangeDrag, true);
    plot->setInteraction(QCP::iRangeZoom, true);
    plot->setInteraction(QCP::iSelectPlottables, true);

    // Mostra tooltip com coordenadas ao passar o mouse (recurso inserido com apoio de IA)
    //ERRO: linha abaixo não compila
    // connect(plot, &QCustomPlot::mouseMove, this, [=](QMouseEvent *event) {
    QObject::connect(plot, &QCustomPlot::mouseMove, this, [=](QMouseEvent *event) { // <--- AQUI ESTÁ A CORREÇÃO PRINCIPAL
        double xVal = plot->xAxis->pixelToCoord(event->pos().x());
        double yVal = plot->yAxis->pixelToCoord(event->pos().y());

        // NOTA: Conforme discutido anteriormente, setToolTip pode não ser ideal para
        // tooltip dinâmico no gráfico QCustomPlot. Avalie se você realmente quer
        // um tooltip no *widget* QCustomPlot ou uma QLabel na barra de status.
        plot->setToolTip(QString("Profundidade: %1 ft\nPressão: %2 psi")
                             .arg(xVal, 0, 'f', 2)
                             .arg(yVal, 0, 'f', 2));
    });

    plot->replot();
}

// Botao de exportar imagem do grafico (logica de exportacao por QPixmap)
void CJanelaGraficoPressaoHidroestatica::on_BntnExportarGrafico_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Salvar grafico", "", "PNG (*.png);;JPEG (*.jpg)");

    if (!fileName.isEmpty()) {
        QPixmap imagem = ui->customPlotPressaoMediaProfundidade->toPixmap(800, 600);
        imagem.save(fileName);
    }
}
