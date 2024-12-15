#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CPoco.h"
#include "CTrechoPoco.h"
#include "CModeloNewtoniano.h"
#include "CModeloBingham.h"
#include "CModeloPotencia.h"
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    std::shared_ptr<CPoco> poco;
    std::shared_ptr<CTrechoPoco> trechoPoco = nullptr;
    std::shared_ptr<CFluido> fluido = nullptr;
    std::shared_ptr<CModeloNewtoniano> modeloNewtoniano = nullptr;
    std::shared_ptr<CModeloBingham> modeloBingham = nullptr;
    std::shared_ptr<CModeloPotencia> modeloPotencia = nullptr;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btnAdicionarPropriedades_clicked();

    void on_btnPressaoHidroesttica_clicked();

    void on_btnLimparPropriedadesPoco_clicked();

    void on_btnAdicionarFluido_clicked();

    void on_actionImportar_Dados_triggered();

    void on_bntRemoverFluido_clicked();

    void on_actionSobre_o_Simulador_triggered();

    void on_btnAtualizar_clicked();

    void on_btnCalcularPerdaCarga_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
