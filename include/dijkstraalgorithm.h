#ifndef DIJKSTRAALGORITHM_H
#define DIJKSTRAALGORITHM_H

#include <include/vertex.h>

class DijkstraAlgorithm
{
public:
    DijkstraAlgorithm();
    QPair<QList<Vertex *>, int> run(QList<Vertex*> vertices, Vertex* vertex1, Vertex* vertex2);
};

#endif // DIJKSTRAALGORITHM_H
