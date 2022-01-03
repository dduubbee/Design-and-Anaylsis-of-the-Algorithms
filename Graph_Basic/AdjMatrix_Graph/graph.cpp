#include "graph.hpp"

Graph::Graph(const int&  _vertexNum, const bool& _isDirected)
:vertexNum(_vertexNum), isDirected(_isDirected)
{
    adjMatrix = new int*[vertexNum];
    for(int i=0; i<vertexNum; i++)
        adjMatrix[i] = new int[vertexNum];

    for(int i=0; i<vertexNum; i++)
        for(int j=0; j<vertexNum; j++)
            adjMatrix[i][j] = 65536;

    for(int i=0; i<vertexNum; i++)
        adjMatrix[i][i] = 0;
}
Graph::~Graph()
{
    for(int i=0; i<vertexNum; i++)  delete[] adjMatrix[i];
    delete[] adjMatrix;
}
void Graph::add_edge(const int& src, const int& dest, const int& cost){
    if(isDirected){
        adjMatrix[src][dest] = cost;
    }
    else{
        adjMatrix[src][dest] = cost;
        adjMatrix[dest][src] = cost;
    }
}
void Graph::print_graph() const
{
    cout << "### Print Graph ###" << endl;
    for(int i=0; i<vertexNum; i++){
        cout << i << "--"; 
        for(int j=0; j<vertexNum; j++)
            if(adjMatrix[i][j] != 65536)
                cout << '(' << j << ", " << adjMatrix[i][j] << ")--";
        cout << endl;
    } 
}
