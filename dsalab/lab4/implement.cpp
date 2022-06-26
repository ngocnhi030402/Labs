#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class AVLTree{
public:
    class Node;
private:
    Node* root;
public:
    AVLTree(): root(nullptr);
    ~AVLTree(){}
    int getHeight(Node* node){
        if(node == NULL) return 0;
        else{
            int leftheight = getHeight(node->pLeft);
            int rightheight = getHeight(node->pRight);
            if(leftheight < rightheight) {
                return rightheight - leftheight + 1;
            }
            else return leftheight - rightheight + 1;
        }
    }
    void printTree(){

    }
    void printInorder(Node* node){
        printInorder(node->pLeft);
        cout << node->data << " ";
        printInorder(node->pRight);
    }

    int getBalance(Node* node){
        if(node == NULL) return 0;
        else{
            return getHeight(node->pLeft) - getHeight(node->pRight);
        }
    }

    Node* rightRotate(Node* root){
        Node* temp = root->pLeft;
        root->pLeft = temp->pRight;
        temp->pRight = root;
        return temp;
    }
    Node* leftRotate(Node *root){
        Node *temp = root->pRight;
        root->pRight = temp->pLeft;
        temp->pLeft = root;
    }
    
    Node* insert(Node* node, T value){
        if(node == NULL) root = new Node(value);
        else{
            if(value < node->data){
                insert(node->pLeft, value);
            }
            else insert(node->pRight, value);
        }

        //check balance
        int balance = getBalance(node);
        if(balance > 1 && value < node->pLeft->data){
            return leftRotate(node);
        }
    }


    class Node{
    private:
        T data;
        Node* pLeft, pRight;
        friend class AVLTree<T>;
    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL);
        ~Node(){

        }
    };
};