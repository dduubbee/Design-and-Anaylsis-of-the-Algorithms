#include "graph_kruskal.hpp"
//
Graph::Graph(const int vertex_num, bool isDirected_Graph)
: _vertex_num(vertex_num), _isDirected_Graph(isDirected_Graph), totalCost(0)
{
    edge_number = 0;
    vertex = new list<Element>[_vertex_num];
    pParent = new int[_vertex_num];
    for(int i=0; i < _vertex_num; i++) pParent[i] = -1;
    pMST = nullptr;
}
Graph::~Graph()
{
    delete[] vertex;
    delete[] pParent;
    if(pMST)    delete[] pMST;
}
bool Graph::add_edge(const int start, const int end, const int cost)
{
    if(start < 0 || end < 0)    return false;
    if(start > _vertex_num-1 || end > _vertex_num)  return false;
    
    Element tmp = {cost, end};
    Edge edge(cost, start, end);
    pq.push(edge);

    if(_isDirected_Graph){
        vertex[start].push_back(tmp);
    }
    else{
        vertex[start].push_back(tmp);
        tmp.vertex = start;
        vertex[end].push_back(tmp);
    }
    edge_number++;
    return true;
}
int Graph::findSet(const int src){
    int currentVertex = src;
    while(pParent[currentVertex] != -1)
    {
        currentVertex = pParent[currentVertex];
    }
    return currentVertex;
}

void Graph::makeMST()
{   
    if(pMST) delete[] pMST;
    pMST = new list<Element>[_vertex_num];

    while(!pq.empty()){
        Edge temp_edge = pq.top();  pq.pop();
        if(findSet(temp_edge.src) != findSet(temp_edge.dest)){
            if(pParent[findSet(temp_edge.src)] == -1 && pParent[findSet(temp_edge.dest)] == -1)
                pParent[findSet(temp_edge.src)] = temp_edge.dest; 
            else 
                pParent[temp_edge.dest] = temp_edge.src;
            Element temp_element = {temp_edge.cost, temp_edge.dest};
            pMST[temp_edge.src].push_front(temp_element);
            temp_element.vertex = temp_edge.src;
            pMST[temp_edge.dest].push_front(temp_element);
            totalCost += temp_edge.cost;
        }
    }
}

void Graph::print_graph() const
{
    cout << "### Print All Element ###" << endl;
    list<Element>::iterator iter;
    for(int i=0; i<_vertex_num; i++){
        for(iter=vertex[i].begin(); iter!=vertex[i].end(); iter++){
            cout << '(' << (*iter).cost <<", " << (*iter).vertex << ") --";
        }
        cout << endl;
    }

    cout << "### Print MST ###" << endl;
    for(int i=0; i<_vertex_num; i++){
        for(iter = pMST[i].begin(); iter != pMST[i].end(); iter++){
            cout << '(' << (*iter).cost <<", " << (*iter).vertex << ") --";
        }
        cout << endl;
    }
}

