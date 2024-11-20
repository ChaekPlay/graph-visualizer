#include "include/vertex.h"
#include "include/edge.h"
#include "include/styles.h"
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
    qreal adjust = 20;
    return QRectF( -Styles::CIRCLE_SIZE/2 - adjust, -Styles::CIRCLE_SIZE/2 - adjust, Styles::CIRCLE_SIZE+Styles::BORDER_SIZE + adjust, Styles::CIRCLE_SIZE+Styles::BORDER_SIZE + adjust);
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
    if (change == ItemPositionChange && scene()) {
        // Получаем новое положение элемента
        QPointF newPos = value.toPointF();
        QRectF rect = scene()->sceneRect();
        if (!rect.contains(newPos)) {
            // Сохраняем элемент внутри прямоугольника сцены.
            newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
            newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));
            foreach (Edge *edge, edges)
                edge->updateInScene();
            return newPos;
        }
        foreach (Edge *edge, edges)
            edge->updateInScene();
    }
    return QGraphicsItem::itemChange(change, value);
}

void Vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) {
    if (option->state & QStyle::State_Selected)
    {
        painter->setBrush(Styles::VERTEX_SELECTED_FILL_COLOR);
    }
    else
    {
        painter->setBrush(Styles::VERTEX_FILL_COLOR);
    }
    painter->setPen(QPen(Styles::VERTEX_BORDER_COLOR, Styles::BORDER_SIZE));
    painter->drawEllipse(-Styles::CIRCLE_SIZE/2, -Styles::CIRCLE_SIZE/2, Styles::CIRCLE_SIZE, Styles::CIRCLE_SIZE);
    painter->setPen(QPen(Styles::VERTEX_FONT_COLOR));
    QFont font;
    font.setPixelSize(Styles::FONT_SIZE);
    font.setBold(true);
    painter->setFont(font);
    QString text = QString::number(id);
    painter->drawText(-Styles::FONT_SIZE/4, Styles::FONT_SIZE/4, text);
}
