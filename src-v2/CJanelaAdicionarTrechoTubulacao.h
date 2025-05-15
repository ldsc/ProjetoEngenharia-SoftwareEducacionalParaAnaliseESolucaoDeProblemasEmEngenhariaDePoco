#ifndef CJANELAADICIONARTRECHOTUBULACAO_H
#define CJANELAADICIONARTRECHOTUBULACAO_H

#include <QDialog>

/*
Classe da interface grafica que permite adicionar um trecho de tubulacao ao sistema
O usuario insere informacoes da geometria da tubulacao, propriedades fisicas e dados do fluido
Esses dados sao usados para simulacoes de comportamento termico e mecanico da tubulacao
*/

namespace Ui {
class CJanelaAdicionarTrechoTubulacao;
}

class CJanelaAdicionarTrechoTubulacao : public QDialog
{
    Q_OBJECT

public:
    explicit CJanelaAdicionarTrechoTubulacao(QWidget *parent = nullptr);
    ~CJanelaAdicionarTrechoTubulacao();

    // metodos para acessar os dados inseridos
    QString Trecho() const { return trecho; }
    QString ProfundidadeInicial() const { return profundidadeInicial; }
    QString ProfundidadeFinal() const { return profundidadeFinal; }
    QString DiametroExterno() const { return diametroExterno; }
    QString DiametroInterno() const { return diametroInterno; }
    QString CoeficientePoisson() const { return coeficientePoisson; }
    QString CoeficienteExpansaoTermica() const { return coeficienteExpansaoTermica; }
    QString ModuloElasticidade() const { return moduloElasticidade; }
    QString PesoUnidade() const { return pesoUnidade; }
    QString NomeFluido() const { return nomeFluido; }
    QString Densidade() const { return densidade; }
    QString Viscosidade() const { return viscosidade; }

    // metodos para definir os dados
    void Trecho(const QString& valor) { trecho = valor; }
    void ProfundidadeInicial(const QString& valor) { profundidadeInicial = valor; }
    void ProfundidadeFinal(const QString& valor) { profundidadeFinal = valor; }
    void DiametroExterno(const QString& valor) { diametroExterno = valor; }
    void DiametroInterno(const QString& valor) { diametroInterno = valor; }
    void CoeficientePoisson(const QString& valor) { coeficientePoisson = valor; }
    void CoeficienteExpansaoTermica(const QString& valor) { coeficienteExpansaoTermica = valor; }
    void ModuloElasticidade(const QString& valor) { moduloElasticidade = valor; }
    void PesoUnidade(const QString& valor) { pesoUnidade = valor; }
    void NomeFluido(const QString& valor) { nomeFluido = valor; }
    void Densidade(const QString& valor) { densidade = valor; }
    void Viscosidade(const QString& valor) { viscosidade = valor; }
    void ModoEdicao(bool opcao) { edit = opcao; }

private slots:
    void on_btnReturn_accepted();  // acao ao confirmar
    void on_btnReturn_rejected();  // acao ao cancelar

private:
    bool edit = false;  // indica se esta no modo de edicao
    Ui::CJanelaAdicionarTrechoTubulacao *ui = nullptr;

    // dados da tubulacao
    QString trecho;
    QString profundidadeInicial;
    QString profundidadeFinal;
    QString diametroExterno;
    QString diametroInterno;
    QString coeficientePoisson;
    QString coeficienteExpansaoTermica;
    QString moduloElasticidade;
    QString pesoUnidade;

    // dados do fluido no trecho
    QString nomeFluido;
    QString densidade;
    QString viscosidade;
};

#endif // CJANELAADICIONARTRECHOTUBULACAO_H
