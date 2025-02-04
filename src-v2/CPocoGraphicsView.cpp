#include "CPocoGraphicsView.h"
#include <QGraphicsRectItem>
#include <QBrush>

CPocoGraphicsView::CPocoGraphicsView(QWidget *parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
}

void CPocoGraphicsView::desenharPoco(const std::vector<SecaoPoco> &secoes) {
    scene->clear();  // Limpa a cena antes de desenhar

    float x_centro = 0; // Posição central do poço
    float escala = 10; // Ajuste de escala para largura

    for (const auto &secao : secoes) {
        float altura = secao.profundidade_final - secao.profundidade_inicial;
        float largura = secao.diametro * escala;

        QGraphicsRectItem *retangulo = new QGraphicsRectItem(
            x_centro - largura / 2, secao.profundidade_inicial, largura, altura
            );
        retangulo->setBrush(QBrush(Qt::gray));
        scene->addItem(retangulo);
    }

    setSceneRect(-100, 0, 200, 3000); // Define o tamanho da cena
}
