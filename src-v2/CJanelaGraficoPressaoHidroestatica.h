#ifndef CJANELAGRAFICOPRESSAOHIDROESTATICA_H
#define CJANELAGRAFICOPRESSAOHIDROESTATICA_H

#include <QDialog>

namespace Ui {
class CJanelaGraficoPressaoHidroestatica;
}

class CJanelaGraficoPressaoHidroestatica : public QDialog
{
    Q_OBJECT

public:
    explicit CJanelaGraficoPressaoHidroestatica(
        const std::pair<std::vector<double>, std::vector<double>>& dados, QWidget *parent = nullptr);
    ~CJanelaGraficoPressaoHidroestatica();
    void PerfilHidrostatico(const std::pair<std::vector<double>, std::vector<double>>& novoPerfil);

private slots:
    void on_BntnExportarGrafico_clicked();

private:
    Ui::CJanelaGraficoPressaoHidroestatica *ui;
    std::vector<double> profundidades;
    std::vector<double> pressoes;
    void PlotarGraficoPressaoxProfundidade();
};

#endif // CJANELAGRAFICOPRESSAOHIDROESTATICA_H
