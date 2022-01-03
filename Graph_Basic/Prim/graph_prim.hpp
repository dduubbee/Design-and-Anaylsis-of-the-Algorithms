#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;

struct Element{
    int cost;
    int vertex;
};

struct Edge{
    int cost;
    int src;
    int dest;

    Edge(const int _cost, const int _src, const int _dest)
    :cost(_cost), src(_src), dest(_dest){}

    bool operator < (const Edge& edge) const{
        return this->cost > edge.cost; 
    }
};


// Graph for Prim Algorithm
class Graph{
    private :
        int _vertex_num;
        int edge_number;
        list<Element>* vertex;
        list<Element>* pMST;
        priority_queue<Edge> pq;

        int *pParent;
        bool *isEnqueued;
        int totalCost;
        bool _isDirected_Graph;

    public :
        Graph(const int vertex_num, bool isDirected_Graph = false);
        ~Graph();
        bool add_edge(const int start, const int end, const int cost=1);
        void print_graph() const;
        list<Element>* get_Adjacency_List() const{return vertex;}
        int getEdgeNumber() const{return edge_number;}

        void Prim_MST(const int& src);
        int getTotalCost() const {return totalCost;}

    private :
        int findSet(const int& src) const;
};
#endif