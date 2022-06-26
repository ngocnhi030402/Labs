#include <iostream>
#include <stack>
using namespace std;
int baseballScore(string ops){
/*TODO*/
    int sum = 0;
    stack<int> list;
    for (int i = 0; i < ops.length(); i++){
        if(ops[i] >= 48 && ops[i] <= 57){
            int num = ops[i] - 48;
            list.push(num);
        }
        

        if (ops[i] == 'C'){
            list.pop();
        }

        if (ops[i] == 'D'){
            int num = (int)list.top() * 2;
            list.push(num);
        }
        
        if (ops[i] == '+'){
            int newNum = 0;
            int listTop = list.top();
            newNum +=  list.top();
            list.pop();
            newNum += list.top();
            list.push(listTop);
            list.push(newNum);
        }
    }
    while (!list.empty()){
        sum += list.top();
        list.pop();
    }
    return sum;
}

int main (){
    cout << baseballScore("52CD+") << endl;
    cout << "sum: " << baseballScore("524CD9++") << endl;
    return 0;
}