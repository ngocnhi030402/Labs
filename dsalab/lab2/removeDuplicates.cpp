#include <iostream>
#include <stack>
#include <string>
using namespace std;
string removeDuplicates(string S){
    stack <char> stack;
    for (int i = 0; i < S.length(); i++){
        if(stack.empty() || S[i] != stack.top()){
            stack.push(S[i]);
        }
        else{
            stack.pop();
        }

    }
    /*TODO*/
    string s = "";
    while (!stack.empty()){
        s += stack.top();
        stack.pop();
    }
    return s;
    
}
int main (){
    cout << removeDuplicates("abbaca"); //ca
    cout << removeDuplicates("aab"); //b
    return 0;
}