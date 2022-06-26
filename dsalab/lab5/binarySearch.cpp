#include <iostream>
using namespace std;
int binarySearch(int arr[], int left, int right, int x)
{
    int mid = (left + right)/2;
    if(arr[mid] == x){
        cout << "We traverse on index: " << mid << endl;
        return mid;
    }
    else if (arr[mid] > x){
        cout << "We traverse on index: " << mid << endl;
        return binarySearch(arr, left, mid-1, x);
    }
    else if (arr[mid] < x){
        cout << "We traverse on index: " << mid << endl;
        return binarySearch(arr, mid+1, right, x);
    }
    return -1;
}
int binarySearch2(int a[], int n, int x){
	int l = 0, r = n-1;
	while (l < r){
		int mid = (l+r)/2;
		if (a[mid] < x){
			l = mid+1;
		}
		else{
			r = mid;
		}
	}
	if (a[l] == x){
		return l;
	}
	return -1;
}
void printArray(int a[], int n, int l, int r){
	for (int i = l; i <= r; i++){
		cout << a[i] << " ";
	}
}
bool solve(int a[], int b[], int n, int s){
	b[0] = a[0];
	for (int i = 1; i < n; i++){
		b[i] = b[i-1] + a[i];
	}
	for (int i = 0; i < n; i++){
		if (b[i] == s){
			printArray(a, n, 0, i);
			return true;
		}
		if (b[i] > s){
			int l = binarySearch2(b, n, b[i] - s);
			if (l != -1){
				printArray(a, n, l+1, i);
				return true;
			}
		}
	}
}
int main (){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                : cout << "Element is present at index " << result;
}