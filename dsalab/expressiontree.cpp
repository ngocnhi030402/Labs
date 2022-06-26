#include <iostream>

using namespace std;

struct BinNode {
    int data;
    string info;
    BinNode *left, *right;
    
    BinNode () { left = NULL; right = NULL; }
    BinNode(int d) { data = d; left = NULL; right = NULL; }
    BinNode(int d, BinNode * l, BinNode * r) { data = d; left = l; right = r; }
    BinNode(string x){
        info = x;
    }
};

class BinTree {
public:
    BinNode * root;

public:    
    BinTree() { root = NULL; }
    
    void PreOrder(BinNode *n) {
        if (n != NULL) {
            cout << n->data << " ";
            PreOrder(n->left);
            PreOrder(n->right);
        }
    }
    void InOrder(BinNode *n) {
        if (n != NULL) {
            InOrder(n->left);
            cout << n->data << " ";
            InOrder(n->right);
        }
        
    }
    void PostOrder(BinNode *n) {
        if (n != NULL) {
            PostOrder(n->left);
            PostOrder(n->right);
            cout << n->data;
        }
    }
};

int main()
{

    BinTree * tree = new BinTree();
    tree->root = new BinNode("+");
    tree->root->left = new BinNode(2);
    tree->root->right = new BinNode(3);
    tree->root->right = new BinNode(4);
    
    cout << "PreOrder: ";
    tree->PreOrder(tree->root);
    cout << endl;

    cout << "InOrder: ";
    tree->InOrder(tree->root);
    cout << endl;

    cout << "PostOrder: ";
    tree->PostOrder(tree->root);
    cout << endl;
    return 0;
}