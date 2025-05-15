#ifndef CJANELAGRAFICOPRESSAOHIDROESTATICA_H
#define CJANELAGRAFICOPRESSAOHIDROESTATICA_H

#include <QDialog>
#include <vector>

/*
Classe da interface grafica que exibe o grafico de pressao hidrostatica x profundidade
Recebe os dados (profundidade e pressao) e plota o grafico usando QCustomPlot
Permite exportar o grafico em imagem
*/

namespace Ui {
class CJanelaGraficoPressaoHidroestatica;
}

class CJanelaGraficoPressaoHidroestatica : public QDialog
{
    Q_OBJECT

public:
    explicit CJanelaGraficoPressaoHidroestatica(
        const std::pair<std::vector<double>, std::vector<double>>& dados,
        QWidget *parent = nullptr);
    ~CJanelaGraficoPressaoHidroestatica();

    // metodo para atualizar os dados do grafico
    void PerfilHidrostatico(const std::pair<std::vector<double>, std::vector<double>>& novoPerfil);

private slots:
    // acao ao clicar no botao de exportar imagem
    void on_BntnExportarGrafico_clicked();

private:
    Ui::CJanelaGraficoPressaoHidroestatica *ui;

    // vetores com dados de profundidade e pressao
    std::vector<double> profundidades;
    std::vector<double> pressoes;

    // funcao que monta o grafico
    void PlotarGraficoPressaoxProfundidade();
};

#endif // CJANELAGRAFICOPRESSAOHIDROESTATICA_H
