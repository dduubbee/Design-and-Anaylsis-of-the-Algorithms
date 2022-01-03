#include "binary_heap.hpp"

template <typename T>
BinaryHeap<T>::BinaryHeap(const int& _heapSize, const bool& _minheap)
:heapSize(_heapSize), isMinHeap(_minheap), heapSize(0)
{
    pHeap = new Edge<T>[heapSize];
    pHeap[0] = -1;
    
}

template <typename T>
BinaryHeap<T>::~BinaryHeap()
{
    delete[] pHeap;
}

template <typename T>
void BinaryHeap<T>::heapify(const int& index)
{
    int left = 2 * index;
    int right = 2 * index + 1;
    int smallest;

    if(left <= heapSize && compare(pHeap[left], pHeap[index]))
        smallest = left;
    else   
        smallest = index;
    
    if(right <= heapSize && compare(pHeap[right], pHeap[smallest]))
        smallest = right;

    if(smallest != index){
        swap(smallest, index);
        heapify(smallest);
    }
}

template <typename T>   
bool BinaryHeap<T>::compare(const Edge<T>& child, const Edge<T>& parent)
{
    if(isMinHeap)
    {
        return child.cost > parent.cost;
    }
    else{
        return child.cost < parent.cost;
    }
}
template <typename T>
void BinaryHeap<T>::swap(int e1, int e2)
{
    Edge<T> tmp = pHeap[e1];
    pHeap[e1] = pHeap[e2];
    pHeap[e2] = tmp;
}

template <typename T>
Edge<T> BinaryHeap<T>::top() const
{
    return pHeap[1];
}
template <typename T>
void BinaryHeap<T>::pop()
{
    pHeap[1] = pHeap[heapSize--];
    heapify(1);
}

template <typename T>
Edge<T> BinaryHeap<T>::extract()
{
    Edge<T> output = top();
    pop();
    return output;
}
