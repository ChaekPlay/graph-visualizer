#include "include/dijkstraalgorithm.h"
#include "include/edge.h"

DijkstraAlgorithm::DijkstraAlgorithm() {}

QPair<QList<Vertex *>, int> DijkstraAlgorithm::run(QList<Vertex *> vertices, Vertex *vertex1, Vertex *vertex2)
{
    QMap<int, Vertex*> verticesMap;
    foreach(Vertex* vertex, vertices) {
        verticesMap[vertex->getID()] = vertex;
    }
    QMap<int, Vertex*> vertexParent;
    foreach(Vertex* vertex, vertices) {
        vertexParent[vertex->getID()] = nullptr;
    }
    QMap<int, unsigned> shortestDistance;
    foreach(Vertex* vertex, vertices) {
        shortestDistance[vertex->getID()] = UINT_MAX;
    }
    QMap<int, bool> visited;
    foreach(Vertex* vertex, vertices) {
        visited[vertex->getID()] = false;
    }
    unsigned srcID = vertex1->getID();
    shortestDistance[srcID] = 0;
    unsigned minDistance = UINT_MAX;
    unsigned minDistanceVertexID = 0, destNodeID = 0;
    foreach(Vertex* _, vertices) {
        minDistance = UINT_MAX;
        for (auto [id, distance] : shortestDistance.asKeyValueRange()) {
            if (distance < minDistance && visited[id] == false)
            {
                minDistance = distance;
                minDistanceVertexID = id;
            }
        }
        if (minDistance == UINT_MAX)
            continue;
        visited[minDistanceVertexID] = true;
        foreach (auto edge, verticesMap[minDistanceVertexID]->getEdges()) {
            destNodeID = edge->getVertex2()->getID();
            if(destNodeID == minDistanceVertexID)
                destNodeID = edge->getVertex1()->getID();
            if(shortestDistance[minDistanceVertexID] + edge->getLength() < shortestDistance[destNodeID]) {
                shortestDistance[destNodeID] = shortestDistance[minDistanceVertexID] + edge->getLength();
                vertexParent[destNodeID] = verticesMap[minDistanceVertexID];
            }
        }
    }
    Vertex* dst = vertex2;
    QList<Vertex*> shortestPath = {};
    shortestPath.append(dst);
    while(dst != vertex1) {
        if(!vertexParent[dst->getID()]) return {};
        dst = vertexParent[dst->getID()];
        shortestPath.append(dst);
    }
    std::reverse(shortestPath.begin(), shortestPath.end());
    return QPair<QList<Vertex *>, int>(shortestPath, shortestDistance[vertex2->getID()]);
}
