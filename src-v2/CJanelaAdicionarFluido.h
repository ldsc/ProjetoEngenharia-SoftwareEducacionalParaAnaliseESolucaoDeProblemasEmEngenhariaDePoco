#ifndef CJANELAADICIONARFLUIDO_H
#define CJANELAADICIONARFLUIDO_H

#include <QDialog>

/*
Classe da interface grafica que permite ao usuario adicionar ou editar um fluido
Armazena os dados digitados: nome, densidade, viscosidade e faixa de profundidade
*/

namespace Ui {
class CJanelaAdicionarFluido;
}

class CJanelaAdicionarFluido : public QDialog
{
    Q_OBJECT

public:
    explicit CJanelaAdicionarFluido(QWidget *parent = nullptr);
    ~CJanelaAdicionarFluido();

    // metodos para alterar os dados
    void NomeFluido(const QString& nome) { nomeFluido = nome; }
    void Densidade(const QString& valor) { densidade = valor; }
    void Viscosidade(const QString& valor) { viscosidade = valor; }
    void ProfundidadeInicial(const QString& valor) { profundidadeInicial = valor; }
    void ProfundidadeFinal(const QString& valor) { profundidadeFinal = valor; }
    void ModoEdicao(bool opcao) { modoEdicao = opcao; }

    // metodos para acessar os dados
    QString NomeFluido() const { return nomeFluido; }
    QString Densidade() const { return densidade; }
    QString Viscosidade() const { return viscosidade; }
    QString ProfundidadeInicial() const { return profundidadeInicial; }
    QString ProfundidadeFinal() const { return profundidadeFinal; }
    bool ModoEdicao() const { return modoEdicao; }

private slots:
    void on_btnReturn_accepted();  // confirma os dados
    void on_btnReturn_rejected();  // cancela a edicao

private:
    bool modoEdicao = true;
    Ui::CJanelaAdicionarFluido *ui = nullptr;

    QString nomeFluido;
    QString densidade;
    QString viscosidade;
    QString profundidadeInicial;
    QString profundidadeFinal;
};

#endif // CJANELAADICIONARFLUIDO_H
