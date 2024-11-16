#include "graph.h"

Graph::Graph() {}

Graph::Graph(QList<Vertex> vertices, QList<Edge> edges) {
    this->vertices = vertices;
    this->edges = edges;
}

void Graph::addEdge(int v1ID, int v2ID, int value) {
    // TODO: check if edge is already exists
    edges.append(Edge(v1ID, v2ID, value));
}

void Graph::addVertex(int id) {
    vertices.append(Vertex(id));
}

void Graph::removeEdge(int v1ID, int v2ID) {
    // TODO: check if edge exists
    edges.removeIf([v1ID, v2ID] (Edge e) {return e.vertexID1 == v1ID && e.vertexID2 == v2ID;});
}

void Graph::removeVertex(int id) {
    // TODO: check if vertex exists
    vertices.removeIf([id] (Vertex v) {return v.id == id;});
}
