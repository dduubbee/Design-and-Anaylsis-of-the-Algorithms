#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <list>
using namespace std;

struct Element{
    int cost;
    int vertex;
};
class Graph{
    private :
        int _vertex_num;
        int edge_number;
        list<Element>* vertex;
        bool _isDirected_Graph;
    public :
        Graph(const int vertex_num, bool isDirected_Graph = true);
        ~Graph();
        bool add_edge(const int start, const int end, const int cost=1);
        void print_graph() const;
        list<Element>* get_Adjacency_List() const{return vertex;}
        int getEdgeNumber() const{return edge_number;}
};
#endif