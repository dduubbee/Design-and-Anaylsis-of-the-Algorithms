#include "DFS.hpp"
#include "../graph.cpp"

DFS_Graph::DFS_Graph(const int vertex_num, bool isDirected)
: Graph(vertex_num, isDirected), _vertexNum(vertex_num)
{
    pState = new VertexState[_vertexNum];
    time = 0;
   
}
DFS_Graph::~DFS_Graph()
{
    delete[] pState;
}
void DFS_Graph::DFS(const int source)
{
     for(int i=0; i<_vertexNum; i++){
        pState[i].startTime = 0;
        pState[i].finishedTime = 0;
        pState[i].color = WHITE;
        pState[i].parent = -1;
    }
    cout << source << ' ';
    list<Element>* pVertex = get_Adjacency_List();
    for(auto iter = pVertex[source].begin(); iter != pVertex[source].end(); iter++){
        if(pState[(*iter).vertex].color == WHITE)
            DFS_Visit((*iter).vertex);
    }
    cout << endl;
} 
void DFS_Graph::DFS_Visit(const int source)
{
    pState[source].startTime = ++time;
    pState[source].color = GRAY;
    cout << source << ' ';
    list<Element>* pVertex = get_Adjacency_List();
    for(auto iter=pVertex[source].begin(); iter != pVertex[source].end(); iter++){
        if(pState[(*iter).vertex].color == WHITE){
            pState[(*iter).vertex].parent = source;
            DFS_Visit((*iter).vertex);
        }
    }
    pState[source].color = BLACK;
    pState[source].finishedTime = ++time;
}