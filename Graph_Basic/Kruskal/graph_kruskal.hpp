#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <list>
#include <queue>
using namespace std;

struct Element{
    int cost;
    int vertex;
};
struct Edge{
    int cost;
    int src;        // src vertex
    int dest;       // dest vertex

    Edge(const int _cost, const int _src, const int _dest)
    :cost(_cost), src(_src), dest(_dest){}
    bool operator < (const Edge& edge) const{
        return this->cost > edge.cost; 
    }
};
//Graph for Kruskal Algorithm
class Graph{
    private :
        int _vertex_num;
        int edge_number;
        list<Element>* vertex;
        list<Element>* pMST;
        int *pParent;
        priority_queue<Edge> pq;
        bool _isDirected_Graph;
        int totalCost;

    public :
        Graph(const int vertex_num, bool isDirected_Graph = false);
        ~Graph();
        bool add_edge(const int start, const int end, const int cost=1);
        int findSet(const int src);
       // void Union(const int src, const int dest, const int cost);
        void makeMST();
      
        void print_graph() const;
        list<Element>* get_Adjacency_List() const{return vertex;}
        int getEdgeNumber() const{return edge_number;}
        int get_minimum_total_cost() const {return totalCost;}
};
#endif