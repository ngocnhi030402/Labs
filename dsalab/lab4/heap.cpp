#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    void clear();
    
    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();
    
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};
//Your code goes here
template<class T>
void Heap<T>::push(T item){
    elements[count] = item;
    count++;
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    
    T* arr = new T [minCapacity];
    for(int i = 0; i < count; i++){
        arr[i] = elements[i];
    }
    capacity += minCapacity;
    for(int i = 0; i < count; i++){
        elements[i] = arr[i];
    }
    //elements = arr;
}

template<class T>
void Heap<T>::reheapUp(int position){
    //if(postion < 0 || postion >= count || count == 0) return;
    int parent = (position - 1)/2;
    if(elements[parent] < elements[position]){
        swap(elements[parent], elements[position]);
        reheapUp(parent);
    }
}

template<class T>
void Heap<T>::reheapDown(int position){
    //if(postion < 0 || postion >= count || count == 0) return;
    
}