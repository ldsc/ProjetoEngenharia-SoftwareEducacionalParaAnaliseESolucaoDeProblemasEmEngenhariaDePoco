#ifndef CSIMULADORREOLOGICO_H
#define CSIMULADORREOLOGICO_H

#include <QMainWindow>
#include "CObjetoPoco.h"
#include "CTrechoTubulacao.h"
#include "CModeloNewtoniano.h"
#include "CModeloBingham.h"
#include "CModeloPotencia.h"

#include <QTableWidgetItem>


QT_BEGIN_NAMESPACE
namespace Ui {
class CSimuladorReologico;
}
QT_END_NAMESPACE

class CSimuladorReologico : public QMainWindow
{
    Q_OBJECT

public:
    CSimuladorReologico(QWidget *parent = nullptr);
    ~CSimuladorReologico();

private slots:
    void on_actionImportar_Dados_triggered();

    void AtualizarDados();

    void on_btnAdicionarFluido_clicked();

    void on_btnRemoverFluido_clicked();

    void on_btnCalcularPressaoHidroestatica_clicked();

    void on_btnCalcularModeloNewtonianoAnular_clicked();

    void on_btnCalcularModeloNewtonianoPoco_clicked();

    void on_btnCalcularModeloBighamPoco_clicked();

    void on_btnCalcularModeloBighamAnular_clicked();

    void on_btnCalcularModeloPotenciaPoco_clicked();

    void on_btnCalcularModeloPotenciaAnular_clicked();

    void makePlotPoco();

    void EditarLinhaTabela(int row, int column);

     void EditarDadosPoco();

    void on_actionNova_Simula_o_triggered();

     void on_actionExportar_como_Imagem_triggered();

    void on_actionSobre_o_Programa_triggered();

     void on_actionSalvar_Como_triggered();

    void on_actionExcel_triggered();

     void on_actionArquivo_dat_triggered();

 private:
    Ui::CSimuladorReologico *ui;
    std::shared_ptr<CPoco> poco = nullptr;
    std::shared_ptr<CTrechoPoco> trechoPoco = nullptr;
    std::shared_ptr<CFluido> fluido = nullptr;
    std::shared_ptr<CModeloNewtoniano> modeloNewtoniano = nullptr;
    std::shared_ptr<CModeloBingham> modeloBingham = nullptr;
    std::shared_ptr<CModeloPotencia> modeloPotencia = nullptr;
};
#endif // CSIMULADORREOLOGICO_H
