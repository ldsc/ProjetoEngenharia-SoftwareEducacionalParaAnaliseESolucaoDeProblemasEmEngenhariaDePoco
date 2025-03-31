#ifndef CSIMULADORPERDATUBULACAO_H
#define CSIMULADORPERDATUBULACAO_H

#include <QDialog>

namespace Ui {
class CSimuladorPerdaTubulacao;
}

class CSimuladorPerdaTubulacao : public QDialog
{
    Q_OBJECT

public:
    explicit CSimuladorPerdaTubulacao(QWidget *parent = nullptr);
    ~CSimuladorPerdaTubulacao();

private:
    Ui::CSimuladorPerdaTubulacao *ui;
};

#endif // CSIMULADORPERDATUBULACAO_H
