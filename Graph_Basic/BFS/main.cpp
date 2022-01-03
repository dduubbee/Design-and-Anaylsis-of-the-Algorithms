#include "BFS.hpp"

int main()
{
    BFS_Graph my_directed_Graph = BFS_Graph(6);
    my_directed_Graph.add_edge(0, 1);
    my_directed_Graph.add_edge(0, 3);
    my_directed_Graph.add_edge(1, 4);
    my_directed_Graph.add_edge(2, 4);
    my_directed_Graph.add_edge(2, 5);
    my_directed_Graph.add_edge(3, 1);
    my_directed_Graph.add_edge(4, 3);
    my_directed_Graph.add_edge(5, 5);

    my_directed_Graph.print_graph();
    my_directed_Graph.BFS(0);
    my_directed_Graph.BFS(2);
}