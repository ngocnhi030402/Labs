// #include <iostream>
// using namespace std;
// template<class K, class T>
// class BST{
//     class Node; //public
//     Node* root; //private
//     int count(int k);
//     void insert(T value, K key){
//         cout << "insert func in" << endl;
//          if (root == 0){
//              cout << "root NULL" << endl;
//             root = new Node(value);
//         }
//         else{
//             cout << "root not null" << endl;
//             Node *temp = root;
//             Node *parent = NULL;
//             while (temp != NULL){
//                 parent = temp;
//                 if (parent->data >= value){
//                     temp = temp->pLeft;
//                 }
//                 else temp = temp->pRight;
//             }

//             if(parent->data >= value){
//                 parent->pLeft = new Node(value);
//             }
//             else parent->pRight = new Node(value);
//         }
//     }
//     void print(Node* node){
//         if(node != NULL){
//             cout << node->data << " ";
//             print(node->pLeft);
//             print(node->pRight);
//         }
//     }
//     class Node{
//         T data;
//         K key;
//         Node* pLeft, *pRight, *pMid;
//         friend class BST<K, T>;
//         Node(T data): data(data), pLeft(0), pRight(0) {}
//     // public:
//     //      Node(T data) : data(data), pLeft(NULL), pRight(NULL), pMid(NULL) {}
//     //      ~Node() {}
//     };

// public:

//     void add(T data, K key){
//         cout << "add func in" << endl;
//         insert(data, key);
//     }
    
//     void print(){
//         cout << "print: " << endl;
//         print(root);
//     }
// };

// int main (){
//     BST<int, int> bst;
//     //bst.insert(30, 1);
//     bst.print();
//     bst.add(30, 1);
//     cout << "after add" << endl;
//     bst.print();
// }


#include <iostream>
using namespace std;

template<typename T>
class BST{
public:
    class Node;

private:
    Node* root;
public:
    BST();
    ~BST();

    void insert(T data);
    void erase(T data);
    int height();
    bool find(T data);
    T findMin();
    T findMax();
    bool isEmpty();
    void printInOrder();

private:
    void insert(Node* node, T data);
    Node* find(Node* node, T data);
    int height(Node* node, int count);
    void printInOrder(Node* node);
    

public:
    class Node{
    private:
        int data;
        Node *pLeft, *pRight;
        friend class BST;
    public:
        Node ();
        Node(T data): data(data), pLeft(NULL), pRight(NULL);
        Node(int data, Node *node);
        ~Node();
    };

};

template<typename T>
void BST<T>::insert(Node *node, T data){
    if(node == NULL){
        node = new Node(data);
        node->pLeft = NULL;
        node->pRight = NULL;
    }
    else{
        if(data > node->data){
            insert(node->pRight, data);
        }
        else insert(node->pLeft, data);
    }
}

template<typename T>
void BST<T>::printInOrder(Node *node){
    if(node != NULL){
        cout << node->data << " ";
        printInOrder(node->pLeft);
        printInOrder(node->pRight);
    } //O(n)
}

template<typename T>
int BST<T>::height(Node *node, int count){
    while(node != NULL){
        count++;
        node = node->next;
    }

    return count;
    
}

int main (){
    BST<int> bst;
    bst.insert(1);  

}