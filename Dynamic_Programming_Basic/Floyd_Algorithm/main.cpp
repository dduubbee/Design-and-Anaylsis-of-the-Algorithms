#include "floyd.hpp"

int main()
{
    Floyd_Graph myGraph(5);

    myGraph.add_edge(0, 1, 1);
    myGraph.add_edge(0, 3, 1);
    myGraph.add_edge(0, 4, 5);

    myGraph.add_edge(1, 0, 9);
    myGraph.add_edge(1, 2, 3);
    myGraph.add_edge(1, 3, 2);

    myGraph.add_edge(2, 3, 4);
    
    myGraph.add_edge(3, 2, 2);
    myGraph.add_edge(3, 4, 3);

    myGraph.add_edge(4, 0, 3);

    myGraph.floyd_algorithm();
    myGraph.print_shortest_distance();
}