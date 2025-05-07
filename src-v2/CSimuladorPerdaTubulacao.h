#ifndef CSIMULADORPERDATUBULACAO_H
#define CSIMULADORPERDATUBULACAO_H

#include <QMainWindow>
#include "CObjetoPoco.h"
#include "CTrechoTubulacao.h"
#include "CModeloNewtoniano.h"
#include "CModeloBingham.h"
#include "CModeloPotencia.h"
#include "qcustomplot.h"

namespace Ui {
class CSimuladorPerdaTubulacao;
}

class CSimuladorPerdaTubulacao : public QMainWindow
{
    Q_OBJECT

public:
    explicit CSimuladorPerdaTubulacao(QWidget *parent = nullptr);
    ~CSimuladorPerdaTubulacao();

private slots:
    void on_btnAdicionarFluido_clicked();

    void on_btnAdicionarPropriedades_clicked();

    void on_btnAtualizarDados_clicked();

    void on_btnAdicionarTrecho_clicked();

    void makePlotTemperatura(double TempInicial, double TempFinal, double profundidade, QCustomPlot* plot);

    void on_btnRemoverFluido_clicked();

    void on_btnRemoverTrecho_clicked();

    void makePlotPoco();

    void on_btnCalcularVariacoes_clicked();

private:
    Ui::CSimuladorPerdaTubulacao *ui;
    std::shared_ptr<CPoco> poco = nullptr;
    std::shared_ptr<CTrechoPoco> trechoPoco = nullptr;
    std::shared_ptr<CFluido> fluido = nullptr;
    std::shared_ptr<CModeloNewtoniano> modeloNewtoniano = nullptr;
    std::shared_ptr<CModeloBingham> modeloBingham = nullptr;
    std::shared_ptr<CModeloPotencia> modeloPotencia = nullptr;
};

#endif // CSIMULADORPERDATUBULACAO_H
