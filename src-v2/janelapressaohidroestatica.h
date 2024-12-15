#ifndef JANELAPRESSAOHIDROESTATICA_H
#define JANELAPRESSAOHIDROESTATICA_H

#include <QDialog>
#include <memory> // Para std::unique_ptr
#include "CPoco.h" // Inclua o cabeçalho da classe CPoco

namespace Ui {
class janelapressaohidroestatica;
}

class janelapressaohidroestatica : public QDialog
{
    Q_OBJECT

public:
    explicit janelapressaohidroestatica(std::shared_ptr<CPoco> poco, QWidget *parent = nullptr);
    ~janelapressaohidroestatica();

private slots:
    void on_bntCalcularPressaoHidroestatica_clicked();

private:
    Ui::janelapressaohidroestatica *ui;
    std::shared_ptr<CPoco> copiaPoco;
};

#endif // JANELAPRESSAOHIDROESTATICA_H
