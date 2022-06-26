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


    static void oddEvenSort(T *start, T *end)
    {
        /*TODO*/
        int num = end - start;
        bool sort = false;
        while (!sort){
            sort = true;

            //odd index
            for (int i = 1; i <= num - 2; i = i + 2){
                if (start[i] > start[i + 1]){
                    swap(start[i], start[i + 1]);
                    sort = false;
                }
            }
            printArray(start, end);
            //even index
            for (int i = 0; i <= num - 2; i = i + 2){
                if (start[i] > start[i + 1]){
                    swap(start[i], start[i + 1]);
                    sort = false;
                }
            }
            printArray(start, end);
        }
    }
};