#ifndef JANELAMENU_H
#define JANELAMENU_H

#include <QMainWindow>

namespace Ui {
class JanelaMenu;
}

class JanelaMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit JanelaMenu(QWidget *parent = nullptr);
    ~JanelaMenu();

private slots:
    void on_btnModulo01_clicked();

private:
    Ui::JanelaMenu *ui;
};

#endif // JANELAMENU_H
