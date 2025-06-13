#ifndef CSIMULADORREOLOGICO_H
#define CSIMULADORREOLOGICO_H

#include <QMainWindow>
#include <QTableWidgetItem>

// inclui os arquivos com os modelos fisicos e estrutura do poco
#include "CObjetoPoco.h"
#include "CTrechoTubulacao.h"
#include "CModeloNewtoniano.h"
#include "CModeloBingham.h"
#include "CModeloPotencia.h"

namespace Ui {
class CSimuladorReologico;
}

// classe principal da interface grafica do simulador reologico
// herda de QMainWindow pois usa os recursos visuais do Qt
class CSimuladorReologico : public QMainWindow
{
    Q_OBJECT

public:
    // construtor e destrutor da interface
    CSimuladorReologico(QWidget *parent = nullptr);
    ~CSimuladorReologico();
    QString nomeArquivo = "";
    QString caminhoArquivo = "";

private slots:
    // atualiza os dados na interface quando ha alteracao
    void AtualizarDados();

    // botoes da interface para adicionar e remover fluido
    void on_btnAdicionarFluido_clicked();
    void on_btnRemoverFluido_clicked();

    // botao que calcula a pressao hidrostática com base nos dados do poco e do fluido
    void on_btnCalcularPressaoHidroestatica_clicked();

    // botoes que executam os calculos usando os diferentes modelos reologicos
    void on_btnCalcularModeloNewtonianoAnular_clicked();
    void on_btnCalcularModeloNewtonianoPoco_clicked();
    void on_btnCalcularModeloBighamPoco_clicked();
    void on_btnCalcularModeloBighamAnular_clicked();
    void on_btnCalcularModeloPotenciaPoco_clicked();
    void on_btnCalcularModeloPotenciaAnular_clicked();

    // funcao que gera o grafico do poco (perfil visual da configuracao)
    void makePlotPoco();

    // edita uma linha da tabela de fluidos ou trechos do poco
    void EditarLinhaTabela(int row);

    // edita os dados gerais do poco como nome, profundidade etc
    void EditarDadosPoco();

    // opcoes do menu superior da interface (arquivo, sobre, exportar etc)
    void on_actionExportar_como_Imagem_triggered();
    void on_actionSobre_o_Programa_triggered();
    void on_actionSalvar_Como_triggered();
    void SalvarArquivo(bool salvarComo);
    void on_actionArquivo_dat_triggered();
    void on_actionSalvar_triggered();
    void on_actionNova_Simula_o_triggered();

    // exibe o grafico da pressao hidrostática ao longo da profundidade
    void on_btnExibirGraficoPressaoHidroestatica_clicked();


    //getters
    QString NomeArquivo() { return nomeArquivo; }
    QString CaminhoArquivo() { return caminhoArquivo; }


    //setters
    void NomeArquivo(QString nome) { nomeArquivo = nome; }
    void CaminhoArquivo(QString caminho) { caminhoArquivo = caminho; }



    void on_actionAjuda_triggered();

    void on_actionSobre_os_Modelos_Reol_gicos_triggered();

private:
    Ui::CSimuladorReologico *ui; // interface grafica do Qt

    // ponteiros para os objetos principais usados nas simulacoes
    std::shared_ptr<CObjetoPoco> poco = nullptr;              // dados do poco inteiro
    std::shared_ptr<CTrechoPoco> trechoPoco = nullptr;        // trecho especifico do poco
    std::shared_ptr<CFluido> fluido = nullptr;                // fluido que circula no poco

    // ponteiros para os modelos reologicos que vao ser usados nos calculos
    std::shared_ptr<CModeloNewtoniano> modeloNewtoniano = nullptr;
    std::shared_ptr<CModeloBingham> modeloBingham = nullptr;
    std::shared_ptr<CModeloPotencia> modeloPotencia = nullptr;
};

#endif // CSIMULADORREOLOGICO_H
