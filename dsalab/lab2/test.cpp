#include <iostream>
using namespace std;
template <typename T>
class BSTree{
public:
    class Node; // forward declaration
private:
    Node* root = nullptr;
public:
    BSTree() : root(nullptr) {}
    ~BSTree(){}
    // helper function here

    Node* addRecur(Node* node, T value, int count, int a[]){
        if (node == NULL) {
            node = new Node(value);
            a[count] = node->data;
            count++;
        }
        
        else if(node->data >= value){
            if(count == 10){
                cout << "10";
            }
            a[count] = node->data;
            count++;
            node->pLeft = addRecur(node->pLeft, value, count, a);
            
        }
        else {
            if(count == 10){
                cout << "102";
            }
            a[count] = node->data;
            count++;
            node->pRight = addRecur(node->pRight, value, count, a);
            
        }
        return node;
    }
    
    int count = 0;
    int a[100] = {0};
    void addNode(T value){
        
        cout << "count: " << count << endl;
    }

    Node* del(Node* node, T value) {
        Node* curr = root; 
        Node* prev = NULL; 

        while (curr != NULL && curr->data != value) { 
            prev = curr; 
            if (value < curr->data) 
                curr = curr->pLeft;
            else
                curr = curr->pRight; 
        } 

        

        if (curr->pLeft == NULL || curr->pRight == NULL) { 
            Node* newCurr; 
            if (curr->pLeft == NULL) newCurr = curr->pRight; 
            else newCurr = curr->pLeft; 

            if (prev == NULL) return node; 
            if (curr == prev->pLeft) prev->pLeft = newCurr; 
            else prev->pRight = newCurr; 
            free(curr); 
        } 
        else { 
            Node* p = NULL; 
            Node* temp; 

            temp = curr->pRight; 
            while (temp->pLeft != NULL) { 
                p = temp; 
                temp = temp->pLeft; 
            } 
            if (p != NULL){ 
                p->pLeft = temp->pRight;
            } 
            else{
                curr->pRight = temp->pRight; 
            }
            curr->data = temp->data; 
            free(temp); 
        } 
        return node;
    }


    void deleteNode(T value){
        root = del(root, value);
        //root = del(root, value);
    }

    Node* addRecur(Node* node, T value){
        if (node == NULL) node = new Node(value);
        
        else if(node->value >= value){
            node->pLeft = addRecur(node->pLeft, value);
        }
        else node->pRight = addRecur(node->pRight, value);
        return node;
    }

    void insertFIFO(T data) {
        //TODO
         if(count == 10){
                deleteNode(a[count -1]);
            }
        if (root == NULL){
            root = new Node(data);
            a[count] = data;
            count++;
            
        }
        else{
            Node *temp = root;
            Node *parent = NULL;
            while (temp != NULL){
                parent = temp;
                if (parent->data >= data){
                    temp = temp->pLeft;
                }
                else temp = temp->pRight;
            }
            
            if(parent->data >= data){
                parent->pLeft = new Node(data);
                a[count] = data;
                count++;
            }
            else {
                parent->pRight = new Node(data);
                a[count] = data;
                count++;    
            }
            
        }
       
    }

    T sumLeft(Node *node, int sum){
        while (node->pLeft != NULL){
            node = node->pLeft;
            sum = sum + node->data;
        }
        return sum;
    }
    T sumLeft(){
        //TODO
        int sum = 0;
        sumLeft(root, sum);
    };

    void inorder( Node* root)
    {
        if (root != NULL) {
            inorder(root->pLeft);
            cout << root->data << " ";
            inorder(root->pRight);
        }
    }
    void printIn()
    {
        inorder(root);
    }
public:
    class Node
    {
    private:
        T data;
        Node *pLeft;
        Node *pRight;
        friend class BSTree<T>;
    public:
        Node(): pLeft(0), pRight(0) {};
        Node(T data): data(data), pLeft(0), pRight(0) {};
    };
};

int main (){
    BSTree<int> bst;
    // for (int i = 0; i < 10; ++i) {
    //     cout << "add " << i << endl;
    //     bst.add(i);
    // }
    bst.addNode(1);
    bst.addNode(2);
    bst.addNode(3);
    bst.addNode(4);
    bst.addNode(5);
    bst.addNode(6);
    bst.addNode(7);
    bst.addNode(8);
    bst.addNode(9);
    bst.addNode(11);
    bst.addNode(12);
    
    


    bst.printIn();
    cout << endl;
    //bst.walk();

    // bst.deleteNode(30);
    // bst.print();
    // cout << endl;

    // bst.deleteNode(50);
    // bst.print();
    //bst.BFS();
    return 0;
}