#include<iostream>
#include<math.h>
#include<string>
using namespace std;
long int midSquare(long int seed)
{
    int a = seed * seed;
    a = (a/100)%10000;
    return a;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed%mod;
}

long int digitExtraction2(long int seed,int* extractDigits,int size){
    int result = 0;
    int num = 0;
    int *a = new int[100];
    string res = "";
    int sizeSeed=0;
    int seed2 = seed;
    while(seed2>0){
        seed2/=10;
        sizeSeed++;
    }
    while(seed != 0){
        num = seed % 10;
        seed /= 10;
        a[sizeSeed - 1] = num;
        sizeSeed--;
    }
    for(int i = 0; i < size; i++){
        res += to_string(a[extractDigits[i]]);    
    }
    result = stoi(res);
    return result;
}

int main(){
    int a[]={1,2,5};
    cout << digitExtraction2(122443,a,3);
    cout << endl;
    cout <<midSquare(9452);
    return 0;
}