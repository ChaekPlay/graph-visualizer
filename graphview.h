#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QGraphicsView>
#include <QMessageBox>
#include <vertex.h>
#include <edge.h>

class GraphView : public QGraphicsView
{
private:
    QGraphicsScene* scene = nullptr;
    int currentVertexIndex = 0;
    QList<Vertex*> vertices = {};
public:
    explicit GraphView(QWidget *parent = 0);
    void addVertex();
    void addEdge(Vertex* src, Vertex* dst, unsigned length);
    void deleteVertex(Vertex* vertex);
    void deleteEdge(Edge* edge);
    bool edgeExists(Vertex* v1, Vertex* v2);
    Edge* findEdge(Vertex* v1, Vertex* v2);
    void clear();
    QGraphicsScene *getScene() const;
// public slots:
//     void deleteSelectedItems();


    QList<Vertex *> getVertices() const;

protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // GRAPHVIEW_H
