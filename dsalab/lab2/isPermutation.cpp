#include <iostream>
#include <stack>
#include <string>
using namespace std;

/* Your helping functions go here */
string sortString(string a){
    int aLength = a.length();
    for (int i = 0; i < aLength; i++){
        for (int j = 0; j < aLength - 1; j++){
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
    return a;
}
bool isPermutation (string a, string b) {
    //TODO
    //cout << sortString(a) << endl << sortString(b) << endl;
    if (sortString(a) == sortString(b)){
        return true;
    }
    return false;
}


int main (){
    string a = "abba";
    string b="baba";
    cout << isPermutation(a, b);
    
    return 0;
}