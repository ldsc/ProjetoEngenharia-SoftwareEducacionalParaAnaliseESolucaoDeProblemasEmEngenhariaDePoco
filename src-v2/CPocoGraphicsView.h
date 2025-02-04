#ifndef POCOGRAPHICSVIEW_H
#define POCOGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>

struct SecaoPoco {
    float profundidade_inicial;
    float profundidade_final;
    float diametro;
};

class CPocoGraphicsView : public QGraphicsView {
    Q_OBJECT

public:
    explicit CPocoGraphicsView(QWidget *parent = nullptr);
    void desenharPoco(const std::vector<SecaoPoco> &secoes);

private:
    QGraphicsScene *scene;
};

#endif // POCOGRAPHICSVIEW_H
