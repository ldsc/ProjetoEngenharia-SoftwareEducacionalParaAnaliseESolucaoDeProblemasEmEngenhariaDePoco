#ifndef CJANELAADICIONARTRECHOTUBULACAO_H
#define CJANELAADICIONARTRECHOTUBULACAO_H

#include <QDialog>

namespace Ui {
class CJanelaAdicionarTrechoTubulacao;
}

class CJanelaAdicionarTrechoTubulacao : public QDialog
{
    Q_OBJECT

public:
    explicit CJanelaAdicionarTrechoTubulacao(QWidget *parent = nullptr);
    ~CJanelaAdicionarTrechoTubulacao();

    QString getTrecho() const { return trecho; }
    QString getProfundidadeInicial() const { return profundidadeInicial; }
    QString getProfundidadeFinal() const { return profundidadeFinal; }
    QString getDiametroExterno() const { return diametroExterno; }
    QString getDiametroInterno() const { return diametroInterno; }
    QString getCoeficientePoisson() const { return coeficientePoisson; }
    QString getCoeficienteExpansaoTermica() const { return coeficienteExpansaoTermica; }
    QString getModuloElasticidade() const { return moduloElasticidade; }
    QString getPesoUnidade() const { return pesoUnidade; }

    void setTrecho(const QString value) { trecho = value; }
    void setProfundidadeInicial(const QString value) { profundidadeInicial = value; }
    void setProfundidadeFinal(const QString value) { profundidadeFinal = value; }
    void setDiametroExterno(const QString value) { diametroExterno = value; }
    void setDiametroInterno(const QString value) { diametroInterno = value; }
    void setCoeficientePoisson(const QString value) { coeficientePoisson = value; }
    void setCoeficienteExpansaoTermica(const QString value) { coeficienteExpansaoTermica = value; }
    void setModuloElasticidade(const QString value) { moduloElasticidade = value; }
    void setPesoUnidade(const QString value) { pesoUnidade = value; }
    void Edit(bool opcao) {edit = opcao;}


private slots:
    void on_btnReturn_accepted();

    void on_btnReturn_rejected();

private:
    bool edit = false;
    Ui::CJanelaAdicionarTrechoTubulacao *ui;
    QString trecho;
    QString profundidadeInicial;
    QString profundidadeFinal;
    QString diametroExterno;
    QString diametroInterno;
    QString coeficientePoisson;
    QString coeficienteExpansaoTermica;
    QString moduloElasticidade;
    QString pesoUnidade;
};

#endif // CJANELAADICIONARTRECHOTUBULACAO_H
