#ifndef JANELAEXIBIRDADOS_H
#define JANELAEXIBIRDADOS_H

#include <QDialog>

namespace Ui {
class janelaExibirDados;
}

class janelaExibirDados : public QDialog
{
    Q_OBJECT

public:
    explicit janelaExibirDados(QWidget *parent = nullptr);
    ~janelaExibirDados();
    coletarPropriedade(double valor);

private:
    Ui::janelaExibirDados *ui;
};

#endif // JANELAEXIBIRDADOS_H
