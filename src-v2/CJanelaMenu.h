#ifndef CJANELAMENU_H
#define CJANELAMENU_H

#include <QMainWindow>

/*
Janela principal do programa, que funciona como menu inicial
Aqui o usuario pode escolher entre os dois modulos principais do software:
- Modulo 1: simulacoes de pressao e escoamento
- Modulo 2: analise de deslocamentos axiais da tubulacao
*/

namespace Ui {
class JanelaMenu;
}

class JanelaMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit JanelaMenu(QWidget *parent = nullptr);  // construtor da janela principal
    ~JanelaMenu();                                   // destrutor

private slots:
    void on_btnModulo01_clicked();  // acao ao clicar no Modulo 1
    void on_btnModulo02_clicked();  // acao ao clicar no Modulo 2

private:
    Ui::JanelaMenu *ui;
};

#endif // CJANELAMENU_H
