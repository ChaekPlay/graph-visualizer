#ifndef GRAPH_H
#define GRAPH_H

#include <QList>
#include <edge.h>
#include <vertex.h>

class Graph
{
public:
    QList<Vertex> vertices = {};
    QList<Edge> edges = {};
    Graph();
    Graph(QList<Vertex>, QList<Edge>);
    void addVertex(int);
    void addEdge(int,int,int);
    void removeVertex(int);
    void removeEdge(int,int);
};

#endif // GRAPH_H
