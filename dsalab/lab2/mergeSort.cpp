#ifndef SORTING_H
#define SORTING_H
#include <iostream>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    static void merge(T* left, T* middle, T* right){
        /*TODO*/
        int i, j, k;
        int n1 = middle - left + 1;
        int n2 = right - middle;

        int *leftArray = new int[n1];
        int *rightArray = new int[n2]; 

        for (int i = 0; i < n1; i++){
            leftArray[i] = left[i];
        }

        for (int i = 0; i < n2; i++){
            rightArray[i] = middle[i + 1]; //left[mid + i + 1]
        }

        //merge
        i = 0, j = 0, k = 0;
        while (i < n1 && j < n2){
            if (leftArray[i] <= rightArray[j]) {
                left[k] = leftArray[i];
                i++;
            }

            else {
                left[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < n1) 
        {
            left[k] = leftArray[i];
            i++;
            k++;
        }
        while (k < n2) {
            left[k] = rightArray[j];
            j++;
            k++;
        }
        
        Sorting::printArray(left, right);
    }
    static void mergeSort(T* start, T* end) {
       /*TODO*/
       if (start < end){
           T* m = start + (end - start)/2;
           mergeSort(start, m);
           mergeSort(m + 1, end);
           merge(start, m, end);
       }
    }
};
#endif /* SORTING_H */
