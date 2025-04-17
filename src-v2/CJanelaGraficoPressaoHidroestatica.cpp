#include "CJanelaGraficoPressaoHidroestatica.h"
#include "ui_CJanelaGraficoPressaoHidroestatica.h"

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

CJanelaGraficoPressaoHidroestatica::~CJanelaGraficoPressaoHidroestatica()
{
    delete ui;
}


void CJanelaGraficoPressaoHidroestatica::PlotarGraficoPressaoxProfundidade()
{
    QVector<double> x(profundidades.begin(), profundidades.end());
    QVector<double> y(pressoes.begin(), pressoes.end());

    auto *plot = ui->customPlotPressaoMediaProfundidade;
    plot->clearGraphs();

    QVector<double> trechoX, trechoY;

    auto isMesmaInclinacao = [](double dy1, double dy2, double tolerancia) {
        return std::abs(dy1 - dy2) < tolerancia;
    };

    double tolerancia = 1e-2;
    double inclinacaoAnterior = (y[1] - y[0]) / (x[1] - x[0]);

    trechoX.push_back(x[0]);
    trechoY.push_back(y[0]);

    for (int i = 1; i < x.size(); ++i) {
        double inclinacaoAtual = (y[i] - y[i - 1]) / (x[i] - x[i - 1]);

        if (!isMesmaInclinacao(inclinacaoAtual, inclinacaoAnterior, tolerancia)) {
            int index = plot->graphCount();
            plot->addGraph();
            plot->graph(index)->setData(trechoX, trechoY);

            QPen pen;
            pen.setWidth(1); // Linha mais fina
            pen.setColor(QColor::fromHsv((index * 70) % 360, 255, 200));
            plot->graph(index)->setPen(pen);

            QCPScatterStyle estiloPonto(QCPScatterStyle::ssCircle, 4); // marcadores menores
            plot->graph(index)->setScatterStyle(estiloPonto);
            plot->graph(index)->setLineStyle(QCPGraph::lsLine);

            plot->graph(index)->setName(QString("Fluido %1").arg(index + 1));

            trechoX.clear();
            trechoY.clear();
        }

        trechoX.push_back(x[i]);
        trechoY.push_back(y[i]);
        inclinacaoAnterior = inclinacaoAtual;
    }

    // Último trecho
    int index = plot->graphCount();
    plot->addGraph();
    plot->graph(index)->setData(trechoX, trechoY);

    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor::fromHsv((index * 70) % 360, 255, 200));
    plot->graph(index)->setPen(pen);

    QCPScatterStyle estiloPonto(QCPScatterStyle::ssCircle, 4);
    plot->graph(index)->setScatterStyle(estiloPonto);
    plot->graph(index)->setLineStyle(QCPGraph::lsLine);

    plot->graph(index)->setName(QString("Fluido %1").arg(index + 1));

    // Eixos
    plot->xAxis->setLabel("Profundidade (ft)");
    plot->yAxis->setLabel("Pressão Hidrostática (psi)");

    plot->xAxis->setRange(*std::min_element(x.begin(), x.end()),
                          *std::max_element(x.begin(), x.end()));
    plot->yAxis->setRange(*std::min_element(y.begin(), y.end()),
                          *std::max_element(y.begin(), y.end()));

    // Legenda: canto inferior direito
    plot->legend->setVisible(true);
    plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight | Qt::AlignBottom);
    plot->legend->setBrush(QBrush(Qt::white));
    plot->legend->setBorderPen(QPen(Qt::gray));
    plot->legend->setFont(QFont("Arial", 9));

    // Zoom e pan com mouse
    plot->setInteraction(QCP::iRangeDrag, true);
    plot->setInteraction(QCP::iRangeZoom, true);
    plot->setInteraction(QCP::iSelectPlottables, true);

    // Mostrar coordenadas com o mouse
    connect(plot, &QCustomPlot::mouseMove, this, [=](QMouseEvent *event) {
        double xVal = plot->xAxis->pixelToCoord(event->pos().x());
        double yVal = plot->yAxis->pixelToCoord(event->pos().y());

        plot->setToolTip(QString("Profundidade: %1 ft\nPressão: %2 psi")
                             .arg(xVal, 0, 'f', 2)
                             .arg(yVal, 0, 'f', 2));
    });

    plot->replot();
}


void CJanelaGraficoPressaoHidroestatica::on_BntnExportarGrafico_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Salvar gr", "", "PNG (*.png);;JPEG (*.jpg)");

    if (!fileName.isEmpty()) {
        QPixmap pixmap = ui->customPlotPressaoMediaProfundidade->toPixmap(800, 600);
        pixmap.save(fileName);
    }
}

