#include "graphview.h"

GraphView::GraphView(QWidget *parent): QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    setScene(scene);
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
        scene->removeItem(edge);
        edge->getVertex1()->removeEdge(edge);
        edge->getVertex2()->removeEdge(edge);
        delete edge;
    }
    delete vertex;
}

void GraphView::addEdge(Vertex* v1, Vertex* v2, unsigned length) {

    scene->addItem(new Edge(v1,v2, length));
}

void GraphView::deleteEdge(Edge *edge)
{
    scene->removeItem(edge);
    edge->getVertex1()->removeEdge(edge);
    edge->getVertex2()->removeEdge(edge);
    delete edge;
};

void GraphView::clearGraph() {
    for(Vertex* vertex: vertices) {
        deleteVertex(vertex);
    }
    vertices.clear();
    scene->clear();
}
