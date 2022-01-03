#ifndef _DFS_HPP_
#define _DFS_HPP_
#include "../graph.hpp"

#define WHITE 0 
#define GRAY 1
#define BLACK 2

struct VertexState{
    int startTime;
    int finishedTime;
    int parent;
    unsigned int color;
};

class DFS_Graph : public Graph {
    private :
        int time;
        int _vertexNum;
        VertexState* pState;

    public :
    DFS_Graph(const int vertex_num, bool isDirected = true);
    ~DFS_Graph();
    void DFS(const int source);
    void DFS_Visit(const int source);
};
#endif