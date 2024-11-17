#ifndef VERTEX_H
#define VERTEX_H
#include <QGraphicsItem>
#include <QPen>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
class Edge;

class Vertex: public QGraphicsItem
{
    unsigned id;
    QList<Edge*> edges = {};
public:
    Vertex(int id);
    void addEdge(Edge* edge);
    void removeEdge(Edge* edgeToDelete);
    unsigned getID();
    void setID(unsigned id);
    QList<Edge*> getEdges();
    QBrush fillColor = QBrush(QColor(0,0,0,255));
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
};

#endif // VERTEX_H
