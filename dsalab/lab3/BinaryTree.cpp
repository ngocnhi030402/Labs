#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
template<class K, class V>
class BinaryTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    class Node
    {
    private:
        K key;
        V value;
        Node* pLeft, * pRight;
        friend class BinaryTree<K, V>;
    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node* walker = this->root;
        int l = (int)posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }

    //Helping functions
    
    int countNodes(Node *node){
        if (node == NULL) return 0;
        else{
            if (countNodes(node->pLeft) >= countNodes(node->pRight)) return countNodes(node->pLeft) + 1;
            else return countNodes(node->pRight) + 1;
        }
        return -1;
    }

    int getDiameterRecur(Node *root){
        if (root == NULL) return 0;
        else {
            cout << "countNode: " << countNodes(root) << endl;
            int left_Height = countNodes(root->pLeft);
            int right_Height = countNodes(root->pRight);
            int left_Dia = getDiameterRecur(root->pLeft);
            int right_Dia = getDiameterRecur(root->pRight);
            // cout << "left_Height: " << left_Height << endl;
            // cout << "right_Height: " << right_Height << endl;
            // cout << "left_Dia: " << left_Dia << endl;
            // cout << "right_Dia: " << right_Dia << endl;
            return max(left_Height + right_Height + 1, max(left_Dia, right_Dia));
        }

    }
    int leftheight(Node* root){
        int lh = 0;
        while(root != NULL){
            root = root->pLeft;
            lh++;
        }
        return lh;
    }
    int rightheight(Node* root){
        int rh = 0;
        while(root != NULL){
            root = root->pLeft;
            rh++;
        }
        return rh;
    }
    int countFullNodes(Node *root){
        if(root == NULL) return 0;
        int lh = leftheight(root);
        int rh = rightheight(root);
        if(lh == rh) return lh*2 + 1;
        else return 1 + countFullNodes(root->pLeft) + countFullNodes(root->pRight);
    }
    int countFull(){
        return countFullNodes(root);
    }
    int getDiameter(){
        //TODO
        return getDiameterRecur(root);
    }

    int countTwoChildrenNodeRecur(Node *node, int &count){
        if (node == NULL){
            return 0;
        }
        else if (node->pLeft != NULL && node->pRight != NULL){
            count++;
        }
        countTwoChildrenNodeRecur(node->pLeft, count);
        countTwoChildrenNodeRecur(node->pRight, count);
        
        return count;
    }
    int countTwoChildrenNode(){
        int count = 0;
        return countTwoChildrenNodeRecur(root, count);
    }

    bool isBSTRecur(Node *node){
        bool flag = true;
        if (node == NULL) flag = true;
        else if (node->pLeft == NULL && node->pRight == NULL) flag = true;
        else if (node->pLeft != NULL && node->pLeft->value > node->value){
            flag = false;
        }
        else if (node->pRight != NULL && node->pRight->value < node->value){
            flag = false;
        }
        else{
            if (isBSTRecur(node->pLeft) == false || isBSTRecur(node->pRight) == false){
                flag = false;
            }
        }    
        return flag;

    }
    bool isBST() {
    // TODO: return true if a tree is a BST; otherwise, return false.
       return isBSTRecur(root);
    }

    int getHeightt(Node *node){
        if (node == NULL) return 0;
        else{
            if (getHeightt(node->pLeft) >= getHeightt(node->pRight)) return getHeightt(node->pLeft) + 1;
            else return getHeightt(node->pRight) + 1;
        }
        return -1;
    }

    int getHeight() {
    // TODO: return height of the binary tree.
        return getHeightt(root);
    }

    void preOrderRecur(Node *node){
        if (node == NULL) return;
        else{
            cout << node->value << " ";
            preOrderRecur(node->pLeft);
            preOrderRecur(node->pRight);
        }
    }

    string preOrder() {
    // TODO: return the sequence of values of nodes in pre-order.
        //string s = "";
        preOrderRecur(root);
        //return "";
    }

    void inOrderRecur(Node *node){
        if (node == NULL) return;
        else{
            inOrderRecur(node->pLeft);
            cout << node->value << " ";
            inOrderRecur(node->pRight);
        }
    }

    string inOrder() {
    // TODO: return the sequence of values of nodes in in-order.
        inOrderRecur(root);
    }

    void postOrderRecur(Node *node){
        if (node == NULL) return;
        else{
            postOrderRecur(node->pLeft);
            postOrderRecur(node->pRight);
            cout << node->value << " ";
        }
    }
    // string printlevel(Node *node){
    //     Queue <int> q;
    //     q.push(node);
    //     while (!q.empty()){
    //         Node *
    //     }
    // }

    string postOrder() {
    // TODO: return the sequence of values of nodes in post-order.
        postOrderRecur(root);
    }

    int sumOfLeafsRecur(Node *node, int &sum){
        
        if (node == NULL) return sum;
        else{
            if (node->pLeft == NULL && node->pRight == NULL){
                sum += node->value;
            }
                sumOfLeafsRecur(node->pLeft, sum);
                sumOfLeafsRecur(node->pRight, sum);
        }
        return sum;
    }

    int sumOfLeafs(){
    //TODO
        int sum = 0;
        return sumOfLeafsRecur(root, sum);
    }

    void printLeafNodes(Node *node){
        if (node == NULL) return;

        if (node->pLeft == NULL && node->pRight == NULL){
            cout << node->value << " ";
        }

        if (root->pLeft != NULL){
            printLeafNodes(root->pLeft);
        }

        if (root->pRight != NULL){
            printLeafNodes(root->pRight);
        }
    }
    void printLeafNodes(){
        printLeafNodes(root);
    }

    int countLeafNodes(Node *node){
        if (node == NULL) return 0;
        else if (node->pLeft == NULL && node->pRight == NULL) return 1;
        else{
            return countLeafNodes(node->pLeft) + countLeafNodes(node->pRight);
        }
    }
    
    int countLeafNodes(){
        return countLeafNodes(root);
    }

    void print(Node *node){
        if(node != NULL){
            print(node->pLeft);
            cout << node->value << " ";
            print(node->pRight);
        }
    }

    void print(){
        print(root);
    }
};

int main (){
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 6);
    binaryTree.addNode("L", 3, 4);
    binaryTree.addNode("R", 5, 8);
    binaryTree.addNode("LL", 4, 2);
    binaryTree.addNode("LR", 6, 5);
    //binaryTree.addNode("LLL", 7, 0);
    //binaryTree.addNode("LLLR", 8, 1);
    binaryTree.addNode("RR", 9, 9);
    binaryTree.addNode("RL", 10, 7);
    // cout << "countFull: " << binaryTree.countFull() << endl;
    // cout << "getDiameter(): " << binaryTree.getDiameter() << endl;
    cout << "countLeafNodes: " << binaryTree.sumOfLeafs() << endl;
    cout << "countLeafNodes: " << binaryTree.countLeafNodes() << endl;
    binaryTree.printLeafNodes();
    // binaryTree.addNode("", 2, 4); // Add to root
    // binaryTree.addNode("L", 3, 6); // Add to root's left node
    // binaryTree.addNode("R", 5, 9); // Add to root's right node
    //cout << "isBST(): " << binaryTree.isBST() << endl; 
    //cout << "getHeight(): " << binaryTree.getHeight() << endl;
    //cout << "preOrder(): " << binaryTree.preOrder() << endl;
    //cout << "inOrder(): " << binaryTree.inOrder() << endl;
    //cout << "sumOfLeafs(): " << binaryTree.sumOfLeafs() << endl;
    

    // BinaryTree<int, int> binaryTree2;
    // binaryTree2.addNode("",2, 4);
    // binaryTree2.addNode("L",3, 6);
    // binaryTree2.addNode("R",5, 9);
    // binaryTree2.addNode("LL",4, 10);
    // binaryTree2.addNode("LR",6, 2);
    //cout << "countTwoChildrenNode(): " << binaryTree2.countTwoChildrenNode() << endl;
    //cout << "isBST2(): " << binaryTree2.isBST() << endl;


}