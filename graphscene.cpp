#include "graphscene.h"

GraphScene::GraphScene(QObject *parent)
    : QGraphicsScene{parent}
{

}

void GraphScene::setGraph(Graph newGraph) {
    this->graph = newGraph;
}

void GraphScene::drawGraph()
{
    // for vertex in vertices
    // int vertexCount = this->graph.vertices.count();
    for(auto& vertex: this->graph.vertices){
        this->addEllipse(vertex.xPos, vertex.yPos, VERTEX_SIZE, VERTEX_SIZE, this->pen);
        this->addText(QString::number(vertex.id));
    }
    // draw ellipse with radius of VERTEX_SIZE
    // draw id inside of vertex
    // for edge in edges
    // draw line from vertex1 to vertex2
    // draw cost on line
}
