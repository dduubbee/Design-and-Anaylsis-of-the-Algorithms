#include "BFS.hpp"
#include "../graph.cpp"

#define     WHITE   0
#define     BLACK   1
#define     GRAY    2

/*  WHITE : Unvisited vertex
    GRAY  : Current vertex
    BLAK  : Vistied vertex */

BFS_Graph::BFS_Graph(const int vertex_num, bool isDirected)
: Graph(vertex_num, isDirected)
{
    _vertex_num = vertex_num;
    pVertexState = new VertexState[vertex_num];
}
BFS_Graph::~BFS_Graph(){

}
bool BFS_Graph::BFS(const int source)
{
    for(int i=0; i<_vertex_num; i++){   // initialization
        if(i==source)   continue;   
        pVertexState[i].color = WHITE;
        pVertexState[i].distance = 10000;
        pVertexState[i].parentVertex = 10000;
        pVertexState[i].myVertex = i;
    }
    pVertexState[source].color  = GRAY;
    pVertexState[source].distance = 0;
    pVertexState[source].parentVertex = -1;
    pVertexState[source].myVertex = source;

    list<VertexState> queue;
    queue.push_back(pVertexState[source]);
    cout << source << ' ';
    while(!queue.empty()){
        VertexState u = queue.front();
        queue.pop_front();
        list<Element>* pGraph = get_Adjacency_List();
        for(auto iter = pGraph[u.myVertex].begin(); iter != pGraph[u.myVertex].end(); iter++)
        {
            if(pVertexState[(*iter).vertex].color == WHITE){
                pVertexState[(*iter).vertex].color = GRAY;
                pVertexState[(*iter).vertex].distance = pVertexState[u.myVertex].distance + 1;
                pVertexState[(*iter).vertex].parentVertex = u.myVertex;
                queue.push_back(pVertexState[(*iter).vertex]);
                cout << (*iter).vertex << ' ';
            }
        }
        u.color = BLACK;
    }
    cout << endl;
    return true;
}
void BFS_Graph::print_BFS_path() const{
    
}