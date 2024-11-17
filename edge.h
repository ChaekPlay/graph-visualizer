#ifndef EDGE_H
#define EDGE_H

#include <vertex.h>
class Edge: public QGraphicsItem
{
    Q_INTERFACES(QGraphicsItem)
    unsigned length = 0;
    Vertex* vertex1 = nullptr;
    Vertex* vertex2 = nullptr;
public:
    Edge(Vertex* v1, Vertex* v2, unsigned length);

    unsigned getLength();
    Vertex *getVertex1() const;
    Vertex *getVertex2() const;
    void updateInScene();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // EDGE_H
