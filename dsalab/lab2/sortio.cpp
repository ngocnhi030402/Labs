#include<iostream>

using namespace std;

void quickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (a[i] < p){
			i++;
		}
		while (a[j] > p){
			j--;
		}
		if (i <= j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r){
		quickSort(a, i, r);
	}
	if (l < j){
		quickSort(a, l, j);
	}
}
void printArray(int a[], int n){
    for (int i = 0; i < n; i++){
    	cout << a[i] << " ";
	}
}
int a[100001], b[100001];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k = 0;
    for (int i = 0; i < n; i++){
    	if (a[i] != 0){
    		b[k] = a[i];  
			k = k + 1;  		
		}
	}
	quickSort(b, 0, k-1);
	k = 0;
	for (int i = n-1; i >= 0; i--){
		if (a[i] < 0){
			a[i] = b[k];
			k = k + 1;
		}
	}
	for (int i = 0; i < n; i++){
		if (a[i] > 0){
			a[i] = b[k];
			k = k + 1;
		}
	}
	printArray(a, n);
}