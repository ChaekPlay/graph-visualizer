#include "graphview.h"

QGraphicsScene *GraphView::getScene() const
{
    return scene;
}

QList<Vertex *> GraphView::getVertices() const
{
    return vertices;
}

GraphView::GraphView(QWidget *parent): QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    setScene(scene);
}

void GraphView::resizeEvent(QResizeEvent *event)
{
    scene->setSceneRect(0, 0, width()-2, height()-2);
    QGraphicsView::resizeEvent(event);
}

void GraphView::addVertex() {
    Vertex* vertex = new Vertex(currentVertexIndex++);
    scene->addItem(vertex);
    vertices.append(vertex);
    // TODO: поменять логику расположения вершин (мб ставить в (0,0), хз)
    vertex->setPos(QPointF(50+currentVertexIndex*10, 50+currentVertexIndex*10));
    update();
}

void GraphView::deleteVertex(Vertex* vertex) {
    for(Edge* edge: vertex->getEdges()) {
        deleteEdge(edge);
    }
    scene->removeItem(vertex);
    delete vertex;
    update();
}

void GraphView::addEdge(Vertex* v1, Vertex* v2, unsigned length) {

    scene->addItem(new Edge(v1,v2, length));
}

bool GraphView::edgeExists(Vertex* v1, Vertex* v2) {
    foreach(Edge* edgeToCompare, v1->getEdges()) {
        if(edgeToCompare->getVertex1() == v1 && edgeToCompare->getVertex2() == v2) {
            return true;
        }
    }
    return false;
}
Edge* GraphView::findEdge(Vertex* v1, Vertex* v2) {
    foreach(Edge* edgeToCompare, v1->getEdges()) {
        if(edgeToCompare->getVertex1() == v1 && edgeToCompare->getVertex2() == v2) {
            return edgeToCompare;
        }
    }
    return nullptr;
}

void GraphView::deleteEdge(Edge *edge)
{
    scene->removeItem(edge);
    edge->getVertex1()->removeEdge(edge);
    edge->getVertex2()->removeEdge(edge);
    delete edge;
};

void GraphView::clear() {
    if(vertices.length() == 0) return;
    for(Vertex* vertex: vertices) {
        deleteVertex(vertex);
    }
    vertices.clear();
    scene->clear();
}
