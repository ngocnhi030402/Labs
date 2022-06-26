#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
using namespace std;

template<class T>
class BinarySearchTree
{
public:
    class Node;

private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    { 
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;

    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    Node* addRec(Node* root, T value);
    
    void add (T value){
        if (root == NULL){
            root = new Node(value);
        }
        else{
            Node *temp = root;
            Node *parent = NULL;
            while (temp != NULL){
                parent = temp;
                if (parent->value >= value){
                    temp = temp->pLeft;
                }
                else temp = temp->pRight;
            }

            if(parent->value >= value){
                parent->pLeft = new Node(value);
            }
            else parent->pRight = new Node(value);
        }
    }
    Node* addRecur(Node* node, T value){
        if (node == NULL) node = new Node(value);
        
        else if(node->value >= value){
            node->pLeft = addRecur(node->pLeft, value);
        }
        else node->pRight = addRecur(node->pRight, value);
        return node;
    }
    void addNode(T value){
        root = addRecur(root, value);
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

    Node* del(Node* node, T value) {
        Node* curr = root; 
        Node* prev = NULL; 

        while (curr != NULL && curr->value != value) { 
            prev = curr; 
            if (value < curr->value) 
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
            curr->value = temp->value; 
            free(temp); 
        } 
        return node;
    }


    void deleteNode(T value){
        root = del(root, value);
        //root = del(root, value);
    }



// if (root == NULL)
//         return 0;
//     return (root->key + addBT(root->left) + addBT(root->right));

    // void add(T value){
    //      if (root == NULL){
    //         root = new Node(value);
    //         cout << "root NULL" << endl;
    //     }
    //     else{
    //         Node *temp = root;
    //         Node *parent = NULL;
    //         while (temp != NULL){
    //             parent = temp;
    //             cout << "temp->value: " << temp->value << endl;
    //             cout << "parent->value: " << parent->value << endl;
    //             if (parent->value >= value){
    //                 temp = temp->pLeft;
    //             }
    //             else{
    //                 temp = temp->pRight;
    //             }
    //         }
    //         cout << "##################################" << endl;
    //         if (parent == NULL){
    //             parent = new Node(value);
    //             cout << "parent NULL" << endl;
    //         }
    //         else if (parent->value >= value){
    //             parent->pLeft = new Node(value);
    //             cout << "parent->pLeft: " << parent->pLeft->value << endl;
    //         } 
    //         else{
    //             parent->pRight = new Node(value);
    //             cout << "parent->pRight: " << parent->pRight->value << endl;
    //         }
            
    //     }
    // }


    bool findRecur(Node* node, T i){
        node = root;
        int count = 0;
        while (node != NULL){
            if (node->value == i) return true;
            else if (node->value > i){
                node = node->pLeft;
            }
            else{
                node = node->pRight;
            }
        }
        return false;
    }
    bool find(T i) {
    // TODO: return true if value i is in the tree; otherwise, return false.
        return findRecur(root, i);
    }

    void sumRecur(Node* node, T l, T r, T& sum){

        if (node == NULL) return;
        
        if (node->value >= l && node->value <=r){
            sum = sum + node->value;
        }
        sumRecur(node->pLeft, l, r, sum);
        sumRecur(node->pRight, l, r, sum);

    
    }

    T sum(T l, T r) {
    // TODO: return the sum of all element in the tree has value in range [l,r].
        T sum = 0;
        sumRecur(root, l, r, sum);
        return sum;
    }

    T getMinn(Node *node){
        while (node->pLeft != NULL){
            node = node->pLeft;
        }
        return node->value;
    }
    T getMin() {
        //TODO: return the minimum values of nodes in the tree.
        return getMinn(root);
    }

    T getMaxx(Node *node){
        while (node->pRight != NULL){
            node = node->pRight;
        }
        return node->value;
    }
    T getMax() {
        //TODO: return the maximum values of nodes in the tree.
        return getMaxx(root);
    }

    void print(Node *node){
        if(node != NULL){
            cout << node->value << " ";
            print(node->pLeft);
            print(node->pRight);
        }
    }

    void print(){
        print(root);
    }

    queue<Node*> q;
    void BFS(){
        q.push(root);
        Node *node = root;
        //cout << q.size() << endl;
        while (q.size() > 0){

            node = q.front();
            
            cout << node->value << " ";
            if(node->pLeft != NULL) q.push(node->pLeft);
            if(node->pRight != NULL) q.push(node->pRight);
            q.pop();
            //cout << q.size() << endl;
        }
        //cout << q.size() << endl;
    }
    queue <Node*> newqueue;
    void BFS2(){
        Node *temp = root;
        newqueue.push(root);
        while(newqueue.size() > 0){
            temp = newqueue.front();
            cout << temp->value << " ";
            if(newqueue->pLeft != NULL) newqueue.push(newqueue->pLeft);
            if(newqueue->pRight != NULL) newqueue.push(newqueue->pRight);
            newqueue.pop();
        }
    }
    void walk(Node* root){
     /*YOUR CODE HERE*/
    //Guideline: Use recursive technique
    //Queue <Node*> q;
    if(root == NULL) return;
    else{
        //  if(root->pLeft == NULL && root->pRight == NULL){
        //        cout << root->value; 
        //  }
        //  else{
             
       q.push(root);
        Node *node = root;
        while (q.size() > 0){

            node = q.front();
           
            cout << node->value<< ", ";
            if(node->pLeft != NULL) q.push(node->pLeft);
            if(node->pRight != NULL) q.push(node->pRight);
            q.pop();
         }
        //}
    }
    }

    void walk(){
        walk(root);
    }
    // STUDENT ANSWER BEGIN
    
    // STUDENT ANSWER END


    //xoa 1 node thi cac node con cung bi xoa theo
    void delete_node(Node* node){
        if(node != NULL){
            if(node->pLeft != NULL) delete_node(node->pLeft);
            if(node->pRight != NULL) delete_node(node->pRight);
            delete(node);
        }
    }
    Node* delete_value(Node* node, int value){
        if(node != NULL){
            if(node->value == value){
                delete_node(node->pLeft);
                delete_node(node->pRight);
                node = NULL;
            }
            else if(node->value > value) node->pLeft = delete_value(node->pLeft, value);
            else node->pRight = delete_value(node->pRight, value);
        }
        return node;
    }
    bool is2ChildNode(Node *node){
        return(node->pLeft != NULL && node->pRight != NULL);
    }
    Node* delete_nodee(Node* node){
        if(node != NULL){
            if(is2ChildNode(node)){
                node = del(node, node->value);
                print();
                cout << endl;
            }
            delete_nodee(node->pLeft);
            delete_nodee(node->pRight);
        }
        return node;
    }
    void delete_child(){
        root = delete_nodee(root);
    }
    void delete_value(int value){
        root = del(root, value);
    }

};

int main (){
    BinarySearchTree<int> bst;
    // for (int i = 0; i < 10; ++i) {
    //     cout << "add " << i << endl;
    //     bst.add(i);
    // }
    bst.addNode(5);
    bst.addNode(2);
    bst.addNode(7);
    bst.addNode(1);
    bst.addNode(3);
    bst.addNode(2);
    bst.addNode(4);

    bst.print();
    cout << endl;
    cout << bst.getHeight() << endl;
    //bst.walk();

    // bst.deleteNode(30);
    // bst.print();
    // cout << endl;

    // bst.delete_child();
    // bst.print();
    // bst.deleteNode(50);
    // bst.print();
    
    return 0;
}