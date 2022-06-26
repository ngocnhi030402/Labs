#include<iostream>
#include<queue>
using namespace std;
template<class K, class T>
class Tree{
    class Node{
        Node getNode(Node *node){
            this->node = node;
            return node;
        }
    };
    Node* root;
    int count(int k);
    int getHeight(Node* node);
    void delNode(T value);
    void printInorder();
    void insert(T value);

public:
    Node* getNode(Node *node){
        return node;
    }
    void addNode_public(T value){
        int count(value);
    }
    Node* addNode(Node* node, T value){
        //recur add node
        if(node == NULL) node = new Node(value);
        else if(node->value >= value){
            node->pLeft = addNode(node->pLeft, value);
        }
        else node->pRight = addNode(node->pRight, value);
        return node;
    }
    void addNode(T value){
        root = addNode(root, value);
    }


public:
    class Node{
    private:
        int value;
        Node *pLeft, *pRight;
        friend class Tree<K, T>;
    public:
        Node(T value): value(value), pLeft(NULL), pRight(NULL){}
        ~Node(){}
    };



    
    // void print(Node *node){
    //     if(node != NULL){
    //         print(node->pLeft);
    //         cout << node->value << " ";
    //         print(node->pRight);
    //     }
    // }

    // void printInorder(){
    //     print(root);
    // }

    // queue<Node*> q;
    // void BFS(){
    //     q.push(root);
    //     Node *node = root;
    //     while(q.size() > 0){
    //         node = q.front();
    //         cout << node->value << " ";
    //         if(node->pLeft != NULL) q.push(node->pLeft);
    //         if(node->pRight != NULL) q.push(node->pRight);
    //         q.pop();
    //     }
    // }

};

// template <class K, class T>
// void Tree<K, T>::addNode_public(T value){
//     cout << "hi";
// }


int main(){
    Tree<int, int> tree;
    tree.addNode_public(3);
    tree.addNode_public(4);
    //tree.printInorder();
    
    

}