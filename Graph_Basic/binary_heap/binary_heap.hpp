#ifndef _BINARY_HEAP_HPP_
#define _BINARY_HEAP_HPP_
#include <iostream>
using namespace std;

template <typename T>
struct Edge{
    int cost;
    T item;
};

template <typename T>
class BinaryHeap{   // true : minheap, false : maxheap
    private :
        int totalArraySize;
        int heapSize;
        bool isMinHeap;
        Edge<T>* pHeap;
    public :
        BinaryHeap(const int& heapSize = 100, const bool& minheap=true);
        ~BinaryHeap();

        void push(Edge<T> item);

        Edge<T> top() const;
        void pop();

        Edge<T> extract();

    private :
        void heapify(const int& index);
        bool compare(const Edge<T>& child, const Edge<T>& parent);
        void swap(int e1, int e2);

};

#endif