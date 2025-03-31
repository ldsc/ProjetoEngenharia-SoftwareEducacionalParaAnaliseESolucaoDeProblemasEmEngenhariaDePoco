#ifndef CJANELAADICIONARFLUIDO_H
#define CJANELAADICIONARFLUIDO_H

#include <QDialog>

namespace Ui {
class janelaadicionarfluido;
}

class janelaadicionarfluido : public QDialog
{
    Q_OBJECT

public:
    explicit janelaadicionarfluido(QWidget *parent = nullptr);
    ~janelaadicionarfluido();

    void setNomeFluido(QString nome) {nomeFluido = nome; }
    void setDensidade(QString dens) {densidade = dens; }
    void setViscosidade(QString visc) {viscosidade = visc; }
    void setProfunidadeInicial(QString profI) {profunidadeInicial = profI; }
    void setProfunidadeFinal(QString profF) {profunidadeFinal = profF; }

    QString getNomeFluido() const { return nomeFluido; }
    QString getDensidade() const { return densidade; }
    QString getViscosidade() const { return viscosidade; }
    QString getProfunidadeInicial() const { return profunidadeInicial; }
    QString getProfunidadeFinal() const { return profunidadeFinal; }
    void Edit(bool opcao) {edit = opcao;}

private slots:
    void on_btnReturn_accepted();

    void on_btnReturn_rejected();




private:
    bool edit = true;
    Ui::janelaadicionarfluido *ui;
    QString nomeFluido;
    QString densidade;
    QString viscosidade;
    QString profunidadeInicial;
    QString profunidadeFinal;


};

#endif // CJANELAADICIONARFLUIDO_H
