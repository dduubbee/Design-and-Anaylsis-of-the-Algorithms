#include <iostream>
#include <list>
#include <queue>
using namespace std;

struct Edge{
    int cost;
    int src;        // src vertex
    int dest;       // dest vertex

    Edge(const int _cost, const int _src, const int _dest)
    {this->cost = _cost; this->src = _src; this->dest = _dest;}
    bool operator < (const Edge& edge) const{
        return this->cost > edge.cost; 
    }
};

int main()
{
    priority_queue<Edge> pq;
    Edge e1(10, 20, 30);
    Edge e2(20, 30, 40);
    pq.push(e1);
    pq.push(e2);
}