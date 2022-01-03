#include "graph_kruskal.hpp"

int main()
{
    Graph myGraph(9);

#if 1
    myGraph.add_edge(0, 1, 4);
    myGraph.add_edge(0, 7, 8);
    myGraph.add_edge(1, 7, 11);
    myGraph.add_edge(1, 2, 8);
    myGraph.add_edge(2, 8 ,2);
    myGraph.add_edge(2, 3, 7);
    myGraph.add_edge(2, 5, 4);
    myGraph.add_edge(3, 4, 9);
    myGraph.add_edge(3, 5, 14);
    myGraph.add_edge(4, 5, 10);
    myGraph.add_edge(5, 6, 2);
    myGraph.add_edge(6, 7, 1);
    myGraph.add_edge(6, 8, 6);
    myGraph.add_edge(7, 8, 7);
#endif
    myGraph.makeMST();
    myGraph.print_graph();

    cout << "minimum total cost : " << myGraph.get_minimum_total_cost() << endl;

}