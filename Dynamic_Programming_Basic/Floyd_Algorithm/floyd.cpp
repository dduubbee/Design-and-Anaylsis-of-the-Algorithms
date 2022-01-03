#include "/home/dd/Desktop/Design-and-Anaylsis-of-the-Algorithms/Graph_Basic/AdjMatrix_Graph/graph.cpp"
#include "floyd.hpp"

Floyd_Graph::Floyd_Graph(const int& _vertexNum, const bool& isDirected)
: Graph(_vertexNum, isDirected)
{
    distance = new int*[_vertexNum];
    for(int i=0; i<_vertexNum; i++) distance[i] = new int[_vertexNum];

}
Floyd_Graph::~Floyd_Graph()
{
    for(int i=0; i < get_vertexNum(); i++)
        delete[] distance[i];
    delete[] distance;
}

void Floyd_Graph::floyd_algorithm()
{
    int** adjMatrx = get_adjMatrix();
    int vertexNum = get_vertexNum();
    for(int i=0; i<get_vertexNum(); i++)
        for(int j=0; j<get_vertexNum(); j++)
            distance[i][j] = adjMatrx[i][j];

    for(int k=0; k<vertexNum; k++)
        for(int i=0; i<vertexNum; i++)
            for(int j=0; j<vertexNum; j++)
                relaxation(i, j, k);

}
void Floyd_Graph::relaxation(const int& src, const int& dest, const int& k)
{
    if(distance[src][dest] > (distance[src][k] + distance[k][dest]))
        distance[src][dest] = distance[src][k] + distance[k][dest];        
}
void Floyd_Graph::print_shortest_distance() const
{   
    int vertexNum = get_vertexNum();
    cout << "### Print Shortest Distance" << endl;
    for(int i=0; i<vertexNum; i++){
        for(int j=0; j<vertexNum; j++)
            cout << distance[i][j] << ' ';
        cout << endl;
    }
}