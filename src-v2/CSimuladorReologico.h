#ifndef CSIMULADORREOLOGICO_H
#define CSIMULADORREOLOGICO_H

#include <QMainWindow>
#include "CObjetoPoco.h"
#include "CTrechoTubulacao.h"
#include "CModeloNewtoniano.h"
#include "CModeloBingham.h"
#include "CModeloPotencia.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class CSimuladorPoco;
}
QT_END_NAMESPACE

class CSimuladorPoco : public QMainWindow
{
    Q_OBJECT

public:
    CSimuladorPoco(QWidget *parent = nullptr);
    ~CSimuladorPoco();

private slots:
    void on_actionImportar_Dados_triggered();

    void on_btnAtualizarDados_clicked();

    void on_btnAdicionarPropriedades_clicked();

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

private:
    Ui::CSimuladorPoco *ui;
    std::shared_ptr<CPoco> poco = nullptr;
    std::shared_ptr<CTrechoPoco> trechoPoco = nullptr;
    std::shared_ptr<CFluido> fluido = nullptr;
    std::shared_ptr<CModeloNewtoniano> modeloNewtoniano = nullptr;
    std::shared_ptr<CModeloBingham> modeloBingham = nullptr;
    std::shared_ptr<CModeloPotencia> modeloPotencia = nullptr;
};
#endif // CSIMULADORREOLOGICO_H
