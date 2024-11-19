#include "edge.h"
#include "styles.h"

Vertex* Edge::getVertex1() const
{
    return vertex1;
}

Vertex *Edge::getVertex2() const
{
    return vertex2;
}

QRectF Edge::boundingRect() const
{
    //TODO: поменять временные значения
    if (!vertex1 || !vertex2) return QRectF();

    qreal penWidth = 2;
    qreal extra = (penWidth)+60;

    return QRectF(vertex1->pos(), QSizeF(vertex2->pos().x() - vertex1->pos().x(),
                                      vertex2->pos().y() - vertex1->pos().y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

void Edge::updateInScene() {
    update();
}

Edge::Edge(Vertex* v1, Vertex* v2, unsigned length) {
    this->vertex1 = v1;
    this->vertex2 = v2;
    this->length = length;
    v1->addEdge(this);
    v2->addEdge(this);
    setAcceptedMouseButtons(Qt::NoButton);
    setCacheMode(DeviceCoordinateCache);
}

unsigned int Edge::getLength()
{
    return length;
}

void Edge::setLength(unsigned int length)
{
    this->length = length;
    updateInScene();
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget*) {
    if (!vertex1 || !vertex2) return;
    painter->setRenderHint(QPainter::Antialiasing);
    QPointF src = vertex1->pos();
    QPointF dst = vertex2->pos();
    QLineF line(src, dst);
    painter->setPen(QPen(Styles::EDGE_COLOR, Styles::LINE_THICKNESS, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);
    painter->setPen(QPen(Styles::EDGE_FONT_COLOR));
    QFont font;
    font.setPixelSize(Styles::FONT_SIZE);
    font.setBold(true);
    painter->setFont(font);
    QPointF bottom = {(src.rx()+dst.rx())/2, (src.ry()+dst.ry())/2-20};
    painter->drawText(bottom, QString::number(length));
}
