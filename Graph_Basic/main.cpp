#include "graph.hpp"

int main(){
    cout << "##### Undirected Graph Test #####" << endl; 
    Graph my_Undirected_Graph = Graph(5, false);
    my_Undirected_Graph.add_edge(0, 1);
    my_Undirected_Graph.add_edge(0, 4);
    my_Undirected_Graph.add_edge(1, 2);
    my_Undirected_Graph.add_edge(1, 3);
    my_Undirected_Graph.add_edge(1, 4);
    my_Undirected_Graph.add_edge(2, 3);
    my_Undirected_Graph.add_edge(3, 4);

    my_Undirected_Graph.print_graph();
    
    cout << "##### Directed Graph Test #####" << endl; 
    Graph my_directed_Graph = Graph(6);
    my_directed_Graph.add_edge(0, 1);
    my_directed_Graph.add_edge(0, 3);
    my_directed_Graph.add_edge(1, 4);
    my_directed_Graph.add_edge(2, 4);
    my_directed_Graph.add_edge(2, 5);
    my_directed_Graph.add_edge(3, 1);
    my_directed_Graph.add_edge(4, 3);
    my_directed_Graph.add_edge(5, 5);

    my_directed_Graph.print_graph();

}