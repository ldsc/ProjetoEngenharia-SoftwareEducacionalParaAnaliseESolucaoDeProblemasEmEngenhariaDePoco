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
    std::unique_ptr<CPoco> poco;
    std::unique_ptr<CTrechoPoco> trechoPoco;
    std::unique_ptr<CFluido> fluido;
    std::unique_ptr<CModeloNewtoniano> modeloNewtoniano;
    std::unique_ptr<CModeloBingham> modeloBingham;
    std::unique_ptr<CModeloPotencia> modeloPotencia;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BntImportarDados_clicked();

    void ExibirDadosPoco();

    void on_btnAdicionarPropriedades_clicked();

    void on_btnPressaoHidroesttica_clicked();

    void on_btnLimparPropriedadesPoco_clicked();

    void on_btnAdicionarFluido_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
