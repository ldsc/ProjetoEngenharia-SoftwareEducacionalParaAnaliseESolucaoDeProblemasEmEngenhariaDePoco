#ifndef CSIMULADORPOCOTUBOS_H
#define CSIMULADORPOCOTUBOS_H

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

#endif // CSIMULADORPOCOTUBOS_H
