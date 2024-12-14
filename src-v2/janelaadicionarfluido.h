#ifndef JANELAADICIONARFLUIDO_H
#define JANELAADICIONARFLUIDO_H

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

private slots:
    QString on_btnReturn_accepted();

private:
    Ui::janelaadicionarfluido *ui;
};

#endif // JANELAADICIONARFLUIDO_H
