#ifndef CSIMULADORPERDATUBULACAO_H
#define CSIMULADORPERDATUBULACAO_H

#include <QDialog>

namespace Ui {
class CSimuladorPocoTubos;
}

class CSimuladorPocoTubos : public QDialog
{
    Q_OBJECT

public:
    explicit CSimuladorPocoTubos(QWidget *parent = nullptr);
    ~CSimuladorPocoTubos();

private:
    Ui::CSimuladorPocoTubos *ui;
};

#endif // CSIMULADORPERDATUBULACAO_H
