#ifndef _BFS_HPP_
#define _BFS_HPP_
#include "../graph.hpp"
#include <vector>

struct VertexState{
    unsigned int color;
    unsigned int distance;
    unsigned int parentVertex;
    int myVertex;
};

class BFS_Graph : public Graph {
    private :
        int _vertex_num;
        VertexState* pVertexState;

    public :
        BFS_Graph(const int vertex_num, bool isDirected=true);
        ~BFS_Graph();
        bool BFS(const int source);
        void print_BFS_path() const;
};

#endif