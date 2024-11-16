#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QGraphicsView>
#include <vertex.h>
#include <edge.h>

class GraphView : public QGraphicsView
{
private:
    QGraphicsScene* scene = nullptr;
    QList<Vertex*> vertices = {};
    int currentVertexIndex = 0;
public:
    explicit GraphView(QWidget *parent = 0);
    void addVertex();
    void addEdge(Vertex* src, Vertex* dst, unsigned length);
    void deleteVertex(Vertex* vertex);
    void deleteEdge(Edge* edge);
    void clearGraph();
// public slots:
//     void deleteSelectedItems();
};

#endif // GRAPHVIEW_H
