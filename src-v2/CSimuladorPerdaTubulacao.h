#ifndef CSIMULADORPERDATUBULACAO_H
#define CSIMULADORPERDATUBULACAO_H

#include <QMainWindow>
#include "CObjetoPoco.h"
#include "CTrechoTubulacao.h"
#include "CModeloNewtoniano.h"
#include "CModeloBingham.h"
#include "CModeloPotencia.h"
#include "qcustomplot.h" // usado pra gerar os graficos

namespace Ui {
class CSimuladorPerdaTubulacao;
}

// essa classe representa a interface principal do simulador do modulo 2 (perda e variacao)
// aqui que o usuario interage com os dados do poço, dos trechos e calcula ΔL, perda, efeito balao etc
class CSimuladorPerdaTubulacao : public QMainWindow
{
    Q_OBJECT

public:
    // construtor e destrutor
    explicit CSimuladorPerdaTubulacao(QWidget *parent = nullptr);
    ~CSimuladorPerdaTubulacao();
    QString nomeArquivo;
    QString caminhoArquivo;

private slots:
    // esses são os slots que reagem aos botoes da interface

    void on_btnAdicionarPropriedades_clicked();     // adiciona as propriedades termicas e mecanicas do fluido
    void on_btnAtualizarDados_clicked();            // atualiza os dados na tela com base no objeto do poço
    void on_btnAdicionarTrecho_clicked();           // adiciona um novo trecho de tubulacao ao poço
    void makePlotTemperatura(double TempInicial, double TempFinal, double profundidade, QCustomPlot* plot); // gera grafico de temperatura com profundidade
    void on_btnRemoverFluido_clicked();             // remove um fluido da tabela e do poço
    void on_btnRemoverTrecho_clicked();             // remove um trecho da tubulacao
    void makePlotPoco();                            // desenha o perfil visual do poço
    void on_btnCalcularVariacoes_clicked();         // calcula ΔL, efeito balao, forca etc

    void on_actionArquivo_Dat_triggered();          // importa dados do arquivo .dat
    void EditarDadosPoco();                         // edita os dados gerais do poço (nome, pressao etc)

    // opcoes do menu da interface
    void on_actionNova_Simula_o_triggered();
    void on_actionExportar_Como_Imagem_triggered();
    void on_actionSobre_o_SEEP_triggered();
    void SalvarArquivo(bool salvarComo);
    void on_actionSalvar_como_triggered();
    void on_actionSalvar_triggered();

    //getters
    QString NomeArquivo() { return nomeArquivo; }
    QString CaminhoArquivo() { return caminhoArquivo; }

    //setters
    void NomeArquivo(QString nome) { nomeArquivo = nome; }
    void CaminhoArquivo(QString caminho) { caminhoArquivo = caminho; }

private:
    Ui::CSimuladorPerdaTubulacao *ui; // ponteiro pra interface gerada pelo Qt Designer

    // ponteiros para os objetos principais que compoem o modelo do poço
    std::shared_ptr<CObjetoPoco> poco = nullptr;              // representa o poço como um todo
    std::shared_ptr<CTrechoPoco> trechoPoco = nullptr;        // trecho individual de tubulacao
    std::shared_ptr<CFluido> fluido = nullptr;                // fluido associado aos trechos

    // modelos reologicos usados pra calcular propriedades de escoamento
    std::shared_ptr<CModeloNewtoniano> modeloNewtoniano = nullptr;
    std::shared_ptr<CModeloBingham> modeloBingham = nullptr;
    std::shared_ptr<CModeloPotencia> modeloPotencia = nullptr;
};

#endif // CSIMULADORPERDATUBULACAO_H
