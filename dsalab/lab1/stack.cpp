#include <iostream>
#include <string>
using namespace std;
// template <class U>
// class Node
// {
// public:
// 	int data;
// 	int key;
// 	Node* next;
	
// 	Node *top = NULL;
// 	Node()
// 	{
// 		data = 0;
// 		key = 0;
// 		next = NULL;
// 	}
// 	Node(int d, int k)
// 	{
// 		data = d;
// 		key = k;
// 		next = NULL;
// 	}
// };
template <class T>
class stack{
public:
    class Node;
protected:
    Node *head;
public:
	stack(): head(NULL) {};
    void push(T item);
    void pop();
    int top();
    bool isEmpty();
	void display();
	// stack (int stack sttack){
	// 	this->head = NULL;
	// }
public:
    class Node{
        
    private:
        T data;
        Node *next;
		friend class stack <T>;
	public:
		Node()
		{
		}
		Node(Node* next)
		{
			this->next = next;
		}
		Node(T data, Node* next = NULL)
		{
			this->data = data;
			this->next = next;
		}

    };
};
template <class T>
void stack<T>::push(T item) {
	Node *newnode = head;
	if (head == NULL){
		Node *pNew = new Node(item, NULL);
		head = pNew;
	}
	else{
		while (newnode->next != NULL){
			newnode = newnode->next;
		}
		Node *temp = new Node(item, NULL);
		newnode->next = temp;
	}
}

template <class T>
void stack<T>::pop() {
	// Node *newnode = head;
	// while (newnode->next->next != NULL){
	// 		newnode = newnode->next;
	// }
	// newnode->next = NULL;

	//queue
	Node *newnode = head;
	head = head->next;
	delete newnode;
}
template <class T>
int stack<T>::top() {
	Node *newnode = head;
	while (newnode->next->next != NULL){
			newnode = newnode->next;
	}
	return newnode->next->data;
}
template <class T>
void stack<T>::display(){
   cout << "[";
   Node *pNode = head;
   
   while (pNode != NULL){
	   if (pNode->next == NULL){
			cout << pNode->data;   
	   }
	   else{
	   	cout << pNode->data << ", ";
	   }
	   pNode = pNode->next;
   }
   cout <<"]";
   cout<<endl;
}

// bool isValidparentheses(string s){
//     stack<char> a;
// 	if (s.length() == 0) return true;

// 	for (int i = 0; i < s.length(); i++){
// 		if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
// 			a.push(s[i]);
// 		}
// 		if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
// 			char b = a.top();
// 			if ((b == '(' && s[i] == ')') || (b == '[' && s[i] == ']') || (b == '{' && s[i] == '}')){
// 				a.pop();
// 			}
// 			else{
// 				return false;
// 			}
// 		}
// 	}
// 	if (a.isEmpty()){
// 		return true;
// 	}
// 	return false;
// }
int main (){
	// string s;
	// cin >> s;
	// cout << isValidparentheses(s) << endl;
	stack<int> stack;
	
	stack.display();
	for (int i = 0; i < 5; i++){
		stack.push(i);
	}
	stack.display();
	stack.pop();
	stack.display();
	cout << stack.top() << endl;
	
	return 0;
}