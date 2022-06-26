#ifndef SORTING_H
#define SORTING_H
#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting {
private:
    static T* Partition(T* start, T* end){
        T* p = start;
	T* i = start;
	T* j = end;
	while (i < j) {
		do {
			i = i + 1;
		} while (*i < *p);
		do {
			j = j - 1;
		} while (*j > *p);
		
		swap(*i, *j);
	}
	
	if (i >= j) {
	    swap(*i, *j);
	}
	
	swap(*p, *j);
	return j;

    }
public:
    static void QuickSort(T* start, T* end){
        if (start < end){
            T* pi = Partition(start, end);
            QuickSort(start, pi - 1);
            QUickSort(pi + 1, end);
            
        }
    }
};
#endif /* SORTING_H */