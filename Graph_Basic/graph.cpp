#include "graph.hpp"
//
Graph::Graph(const int vertex_num, bool isDirected_Graph)
: _vertex_num(vertex_num), _isDirected_Graph(isDirected_Graph)
{
    edge_number = 0;
    vertex = new list<Element>[_vertex_num];
}
Graph::~Graph()
{
    delete[] vertex;
}
bool Graph::add_edge(const int start, const int end, const int cost)
{
    if(start < 0 || end < 0)    return false;
    if(start > _vertex_num-1 || end > _vertex_num)  return false;
    
    if(_isDirected_Graph){
        Element tmp = {cost, end};
        vertex[start].push_back(tmp);
    }
    else{
        Element tmp = {cost, end};
        vertex[start].push_back(tmp);
        tmp.vertex = start;
        vertex[end].push_back(tmp);
    }
    edge_number++;
    return true;
}
void Graph::print_graph() const
{
    cout << "Print All Element" << endl;
    list<Element>::iterator iter;
    for(int i=0; i<_vertex_num; i++){
        for(iter=vertex[i].begin(); iter!=vertex[i].end(); iter++){
            cout << '(' << (*iter).cost <<", " << (*iter).vertex << ") --";
        }
        cout << endl;
    }
}

