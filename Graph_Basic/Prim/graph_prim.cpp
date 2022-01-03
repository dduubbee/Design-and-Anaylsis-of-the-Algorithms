#include "graph_prim.hpp"
//
Graph::Graph(const int vertex_num, bool isDirected_Graph)
: _vertex_num(vertex_num), _isDirected_Graph(isDirected_Graph)
{
    edge_number = 0;
    totalCost = 0;
    vertex = new list<Element>[_vertex_num];
    pMST = new list<Element>[_vertex_num];
    pParent = new int[_vertex_num];
    isEnqueued = new bool[_vertex_num];
    for(int i=0; i<_vertex_num; i++) isEnqueued[i] = false;
   
}
Graph::~Graph()
{
    delete[] vertex;
    delete[] pMST;
    delete[] pParent;
    delete[] isEnqueued;
}
bool Graph::add_edge(const int start, const int end, const int cost)
{
    if(start < 0 || end < 0)    return false;
    if(start > _vertex_num-1 || end > _vertex_num)  return false;
    
    Element tmp = {cost, end};

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
    cout << "### PRIM MST ###" << endl;
    for(int i=0; i<_vertex_num; i++){
        for(iter=pMST[i].begin(); iter!=pMST[i].end(); iter++){
            cout << '(' << (*iter).cost <<", " << (*iter).vertex << ") --";
        }
        cout << endl;
    }
}
void Graph::Prim_MST(const int& src)
{
    for(int i=0; i<_vertex_num; i++)    pParent[i] = -1;
    int currentVertex = src;
    isEnqueued[currentVertex] = true;
    //initialization
    for(auto iter = vertex[currentVertex].begin();
        iter != vertex[currentVertex].end(); iter++){
        Edge temp_edge((*iter).cost, currentVertex, (*iter).vertex);
        isEnqueued[(*iter).vertex] = true;
      //  pParent[(*iter).vertex] = currentVertex;
        pq.push(temp_edge);
    }
    int count = 0;
    while(!pq.empty() && count <= _vertex_num - 1)
    {
        cout << count << endl;
        Edge temp_edge = pq.top();  pq.pop();
        if(findSet(temp_edge.dest) == src)   continue;
        Element temp_element = {temp_edge.cost, temp_edge.dest};
        pParent[temp_edge.dest] = temp_edge.src;        // Parent Array
        pMST[temp_edge.src].push_front(temp_element);   // Union
        temp_element.vertex = temp_edge.src;
        pMST[temp_edge.dest].push_front(temp_element);
        totalCost += temp_edge.cost;
        
        for(auto iter = vertex[temp_edge.dest].begin(); 
        iter != vertex[temp_edge.dest].end(); iter++){
            if(isEnqueued[(*iter).vertex] == false && pParent[(*iter).vertex] == -1){
                Edge e((*iter).cost, temp_edge.dest, (*iter).vertex);
                pq.push(e);
            }
        }
        count++;
    }
}

int Graph::findSet(const int& src) const
{
    int idx = src;
    while(pParent[idx] != -1){
        idx = pParent[idx];
    }
    return idx;
}