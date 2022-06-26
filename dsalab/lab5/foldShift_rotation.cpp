#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int foldShift(long long key, int addressSize) { 
	long long tmp = key; 
	int A[100] = {}; 
	int n = 0;
	while (tmp != 0) { 
        A[n] = tmp % 10; 
        tmp = tmp / 10; 
        n++; 
	} 
	long long sum = 0; 
	while (n>0) { 
		long long s = 0; 
		for (int i = 0; i<addressSize; i++) { 
			if (n - i - 1 >= 0) { 
				s = s * 10 + A[n - i - 1]; 
			} 
		} 
		n -= addressSize; 
		sum += s; 
		
	cout << "s: " << s << endl;
	} 
	long long t = 1; 
	for (int i = 0; i<addressSize; i++) t *= 10; 
	return sum % t; 
}

int rotation(long long key, int addressSize){ 
	long long tmp = key; 
	int A[100] = {};
	int n = 0; 
	while (tmp != 0){
		A[n] = tmp % 10; 
		tmp = tmp / 10; n++; 
	} 
	tmp = A[0]; 
	
	for (int i = 0; i<n - 1; i++) A[i] = A[i + 1]; 
	
	A[n - 1] = tmp; 
	for(int i = 0; i < n; i++){
		cout << A[i] << " ";
	}
	cout << endl;
	long long sum = 0; 
	while (n>0){ 
		long long s = 0; 
    	for (int i = 0; i<addressSize; i++) { 
    		if (n - i - 1 >= 0) {
    		    s = s * 10 + A[n - i - 1];
				cout << "s: " << s << endl; 
    		} 
    	} 
		cout << "n: " << n << endl;
    	n -= addressSize; sum += s;
	} 
	long long t = 1; 
	for (int i = 0; i<addressSize; i++) t *= 10; 
	return sum % t;
};

int foldShift2(long long key, int addressSize){
	string s = "";
	int result = 0;
	int *arr = new int[100];
	int count = 0;
	int temp_key = key;
	int size = 0;
	while(temp_key>0){
        temp_key/=10;
        size++;
    }
	while(key != 0){
		arr[size - 1] = key % 10;
		key /= 10;
		size--;
		count++;
	}

	int temp = arr[0];
	for(int i = 0; i < count - 1; i++){
		arr[i] = arr[i + 1];
	}
	arr[count - 1] = temp;
	for(int i = 0; i < count; i++){
		s += to_string(arr[i]);
	}
	result = stoi(s);
	return result;

}
int foldShift_notString(long long key, int addressSize){
	int result = 0;
	int *arr = new int[100];
	int count = 0;
	int temp_key = key;
	int size = 0;
	while(temp_key>0){
        temp_key/=10;
        size++;
    }
	while(key != 0){
		arr[size - 1] = key % 10;
		key /= 10;
		size--;
		count++;
	}

	int temp = arr[0];
	for(int i = 0; i < count - 1; i++){
		arr[i] = arr[i + 1];
	}
	arr[count - 1] = temp;

	//not use string to convert
	int temp_count = count - 1;
	for(int i = 0; i < count; i++){
		result += arr[i]*pow(10, temp_count);
		temp_count--;
	}
	return result;

}
int rotation2(long long key, int addressSize){
	string s = "";
	int sum = 0;
	int *arr = new int[100];
	int count = 0;
	int temp_key = key;
	int size = 0;
	while(temp_key>0){
        temp_key/=10;
        size++;
    }
	while(key != 0){
		arr[size - 1] = key % 10;
		key /= 10;
		size--;
		count++;
	}
	int last = arr[count - 1];
	for(int i = count - 1; i > 0; i--){
		arr[i] = arr[i - 1];
	}
	arr[0] = last;
	
	int countloop = 0;
	for(int i = 0; i < count; i = i + addressSize){
		s = "";
		countloop = 0;
		for(int j = i; j < i + addressSize; j++){
			if(j == count - 1 && countloop == 0) {
				s = to_string(arr[j]);
				break;
			}
			else{
				s += to_string(arr[j]);
				countloop++;
			}
			
		}
		sum += stoi(s);
	}

	return sum;
}
int main(){
	//cout << foldShift(12345, 2) << endl;
	
	//cout << foldShift_notString(12345, 2) << endl;

    //cout << rotation(12345, 2) << endl;
    cout << rotation2(600101, 3) << endl;
}