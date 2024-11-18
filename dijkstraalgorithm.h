#ifndef DIJKSTRAALGORITHM_H
#define DIJKSTRAALGORITHM_H

#include <vertex.h>

class DijkstraAlgorithm
{
public:
    DijkstraAlgorithm();
    QList<Vertex *> run(QList<Vertex*> vertices, Vertex* vertex1, Vertex* vertex2);
};

#endif // DIJKSTRAALGORITHM_H
