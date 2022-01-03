#ifndef _FLOYD_HPP
#define _FLOYD_HPP

#include "/home/dd/Desktop/Design-and-Anaylsis-of-the-Algorithms/Graph_Basic/AdjMatrix_Graph/graph.hpp"

class Floyd_Graph : public Graph
{
    private :
 
        int** distance;
    
    public :
        Floyd_Graph(const int& _vertexNum, const bool& isDirected = true);
        ~Floyd_Graph();
        void floyd_algorithm();
        void print_shortest_distance() const;

    private :
        void relaxation(const int& src, const int& dest, const int& k);

};
#endif