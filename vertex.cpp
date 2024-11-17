#include "vertex.h"
#include "edge.h"
Vertex::Vertex(int id) {
    this->id = id;
    setFlags(ItemIsSelectable | ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(+1);
}

void Vertex::addEdge(Edge* edge) {
    this->edges.append(edge);
}

void Vertex::removeEdge(Edge* edgeToDelete) {
    this->edges.removeAll(edgeToDelete);
}

unsigned Vertex::getID(){
    return this->id;
}

void Vertex::setID(unsigned id) {
    this->id = id;
}

QList<Edge*> Vertex::getEdges() {
    return edges;
}

QRectF Vertex::boundingRect() const {
    // TODO: тестовые значения
    qreal adjust = 20;
    return QRectF( -15 - adjust, -15 - adjust, 33 + adjust, 33 + adjust);
}

void Vertex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Vertex::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

QVariant Vertex::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (Edge *edge, edges)
            edge->updateInScene();
        break;
    default:
        break;
    }

    return QGraphicsItem::itemChange(change, value);
}

void Vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) {
    if (option->state & QStyle::State_Selected)
    {
        painter->setBrush(QColor(254, 254, 34, 255));
    }
    else
    {
        painter->setBrush(QColor(191, 255, 148, 255));
    }
    painter->setPen(QPen(QColor(130, 180, 130, 255), 3));
    painter->drawEllipse(-15, -15, 30, 30);
    painter->setPen(QPen(Qt::black));
    QString text = QString::number(id);
    painter->drawText(-20, -20, text);
}
