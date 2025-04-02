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


private:
    bool edit = true;
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
