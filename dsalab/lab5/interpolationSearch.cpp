#include <iostream>
#include <algorithm>
using namespace std;
int interpolationSearch(int arr[], int left, int right, int x){
    int pos = left + ((x - arr[left])*(right - left))/(arr[right] - arr[left]);
    if(x > arr[right] || x < arr[left] || left > right || pos < left || pos > right) return -1;
    if(arr[pos] == x){
        cout << "We traverse on index: " << pos << endl;
        return pos;
    }
    else if(arr[pos] < x){
        cout << "We traverse on index: " << pos << endl;
        left = pos + 1;
    }
    else{
        cout << "We traverse on index: " << pos << endl;
        right = pos - 1;
    }
    return interpolationSearch(arr, left, right, x);
}
int main (){
    int a[5] = {1, 2, 3, 4, 5};
    cout << interpolationSearch(a, 0, 4, 3) << endl;
}