#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int jumpSearch(int arr[], int x, int n) {
    // TODO: print the traversed indexes and return the index of value x in array if x is found, otherwise, return -1.
    int step = sqrt(n);
    int prev = 0;
    int i;
    for (i = 0; i < n; i += step) {
        if (arr[i] <= x) {
            prev = i;
        }
        if (arr[i] == x) {
            cout << "i: " << i << endl;
            return i;
        }
        cout << i << " ";
        if (arr[i] > x) break;
    }
    if (prev > n - 1) return -1;
    else {
        for (int j = prev; j < i; j++) {
            if (arr[j] == x) {
                cout << j;
                return j;
            }
            if (j != prev) cout << j << " ";
            if (arr[j] > x) break;
        }
    }
    return -1;
    
}

int jumpSearch2(int arr[], int x, int n){
    int step = sqrt(n);
    int pos = 0;
    int i;
    for(i = 0; i < n; i = i + step){
        cout << i << " ";
        if(arr[i] == x){
            return i;
        }
        if(arr[i] <= x){
            pos = i;
        }
        if(arr[i] > x) break;
    }

    //linear search from pos to i
    for(int j = pos; j < i; j++){
        //cout << j << " ";
        if(arr[j] == x){
            cout << j;
            return j;
        }
        if(pos != j){
            cout << j << " ";
        }
    }
    return -1;
}
int main (){
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
int x = 55;
int n = sizeof(arr) / sizeof(arr[0]);
int index = jumpSearch2(arr, x, n);

if (index != -1) {
    cout << "\nNumber " << x << " is at index " << index;
}
else {
    cout << "\n" << x << " is not in array!";
}
    return 0;
}