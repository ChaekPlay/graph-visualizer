#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H

#include <QGraphicsScene>
#include <QDebug>
#include <graph.h>
class GraphScene : public QGraphicsScene
{
public:
    Graph graph;
    const int VERTEX_SIZE = 50;
    int EDGE_LINE_THICKNESS = 2;
    QPen pen = QPen(QBrush(QColor(0,0,0,255)), this->EDGE_LINE_THICKNESS);
    explicit GraphScene(QObject *parent = nullptr);
    void setGraph(Graph);
    // void clearGraph();
    void drawGraph();
    // void addVertex();
    // void removeVertex();
    // void addEdge();
    // void removeEdge();
    // void runDijkstra();
    // void clearSelection();
};

#endif // GRAPHSCENE_H
