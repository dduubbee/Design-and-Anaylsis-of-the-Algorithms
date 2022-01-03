#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_
#include "../master_include.hpp"
using namespace std;

class Graph{
    private :
        int vertexNum;
        int **adjMatrix;
        bool isDirected;
    public :
        Graph(const int& _vertexNum, const bool& isDirected=true);
        ~Graph();
        void add_edge(const int& src, const int& dest, const int& cost=1);
        void print_graph() const;
        int** get_adjMatrix() const {return adjMatrix;}
        int get_vertexNum() const {return vertexNum;}

};

#endif