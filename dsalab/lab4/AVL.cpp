#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }
    Node* rightRotate(Node* root)
    {
        //cout << "y->pLeft: " << y->pLeft->data << endl;
        Node* x = root->pLeft;
        //cout << "x->pRight: " << x->pRight->data << endl;
        root->pLeft = x->pRight;
        //cout << "y->pLeft: " << y->pLeft << endl;
        //cout << "y: " << y->data << endl;
        x->pRight = root;
        //cout << "x->pRight: " << x->pRight->data << endl;
        //cout << "x:" << x->data << endl;
        return x;
    }
    Node* leftRotate(Node* x)
    {
        Node* y = x->pRight;
        x->pRight = y->pLeft;
        y->pLeft = x;
        return y;
    }
    int getBalance(Node* N)
    {
        if (N == NULL)
            return 0;
        else{
            //cout << "getHeightRec(N->pLeft): " << getHeightRec(N->pLeft) << endl;
            //cout << "getHeightRec(N->pRight): " << getHeightRec(N->pRight) << endl;
            return getHeightRec(N->pLeft) - getHeightRec(N->pRight);
        }
    }
    Node* insertRecur(Node* node, const T &value)
    {
        if (node == NULL)
            return(new Node(value));

        if (value < node->data)
            node->pLeft = insertRecur(node->pLeft, value);
        else if (value >= node->data)
            node->pRight = insertRecur(node->pRight, value);
        
        int balance = getBalance(node); 

        // Left Left Case  
        if (balance > 1 && value < node->pLeft->data){
            return rightRotate(node);
        }

        // Right Right Case  
        if (balance < -1 && value >= node->pRight->data)
            return leftRotate(node);

        // Left Right Case  
        if (balance > 1 && value >= node->pLeft->data)
        {
            node->pLeft = leftRotate(node->pLeft);
            return rightRotate(node);
        }
        // Right Left Case  
        if (balance < -1 && value < node->pRight->data)
        {
            node->pRight = rightRotate(node->pRight);
            return leftRotate(node);
        }
        return node;
    }
    void insert(const T &value)
    {
        //TODO
        root = insertRecur(root, value);
        
    }
    Node* check(Node* node, const T &value)
    {
        // if (node == NULL)
        //     return(new Node(value));

        // if (value < node->data)
        //     node->pLeft = check(node->pLeft, value);
        // else if (value >= node->data)
        //     node->pRight = check(node->pRight, value);
        cout << "check func " << value << endl;
        int balance = getBalance(node); 
        //cout << "balance: " << balance << endl;
        // Left Left Case  
        if (balance > 1 && value < node->pLeft->data){
            return rightRotate(node);
        }

        // Right Right Case  
        if (balance < -1 && value >= node->pRight->data)
            return leftRotate(node);

        // Left Right Case  
        if (balance > 1 && value >= node->pLeft->data)
        {
            node->pLeft = leftRotate(node->pLeft);
            return rightRotate(node);
        }
        // Right Left Case  
        if (balance < -1 && value < node->pRight->data)
        {
            node->pRight = rightRotate(node->pRight);
            return leftRotate(node);
        }
        return node;
    }

int balanceFactor(Node *root){
    if (!root) return 0;
    return getHeightRec(root->pLeft) - getHeightRec(root->pRight);
}

Node *rotateR(Node *root){
    if(root->pLeft){
	Node *tempL = root->pLeft;
	root->pLeft = tempL->pRight;
	tempL->pRight = root;
	return tempL;
    }
    return root;
}

Node *rotateL(Node *root){
    if(root->pRight){
	Node *tempR = root->pRight;
	root->pRight = tempR->pLeft;
	tempR->pLeft = root;
	return tempR;
    }
    return root;
}

Node *getMax(Node *root){
    Node *pRoot= root;
    while(pRoot->pRight) pRoot=pRoot->pRight;
    return pRoot;
}

Node *removeRec(Node *root, const T &value){
    if(!root) return root;
    if(value < root->data) root->pLeft = removeRec(root->pLeft,value);
    else if(value > root->data) root->pRight = removeRec(root->pRight,value);
    else{
        if(!root->pLeft || !root->pRight){
			Node *temp = root->pLeft ? root->pLeft : root->pRight;
			if (temp == NULL){
				temp = root;
				root = NULL;
			}
			else *root = *temp;
			delete(temp);
		}else{
		Node *temp = getMax(root->pLeft);
		root->data = temp->data;
		root->pLeft=removeRec(root->pLeft,temp->data);
		}
    }
    int balance = balanceFactor(root);
	// Left Left
	if (balance > 1 && balanceFactor(root->pLeft) >= 0) return rotateR(root);
	// Left Right
	if (balance > 1 && balanceFactor(root->pLeft) < 0){
		root->pLeft = rotateL(root->pLeft);
		return rotateR(root);
	}
	// Right Right Case
	if (balance < -1 && balanceFactor(root->pRight) <= 0)   return rotateL(root);

	// Right Left Case
	if (balance < -1 && balanceFactor(root->pRight) > 0){
		root->pRight = rotateR(root->pRight);
		return rotateL(root);
	}
    
    return root;
}

void remove2(const T &value){
    //TODO
    root = removeRec(root,value);
}

Node* removeRecur(Node* node, T value){
    int count = 0;
    Node* curr = root; 
        Node* prev = NULL; 

        while (curr != NULL && curr->data != value) { 
            prev = curr; 
            if (value < curr->data){
                curr = curr->pLeft;
                count = 1;
            }
            else{
                curr = curr->pRight; 
                count = 2;
            }
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
    
    Node *temp = root;
    while(temp != NULL){
        node = check(root, temp->data);
        temp = temp->pLeft;
        
    }
    Node *tmp = root;
    while(temp != NULL){
        node = check(node, temp->data);
        temp = temp->pRight;
        
    }
    return node;
}
void remove(const T &value)
    {
        root = removeRecur(root, value);
        //TODO
    }
void printInorderRecur(Node *node){
        if(node == NULL) return;
        else{
            printInorderRecur(node->pLeft);
            cout << node->data << " ";
            printInorderRecur(node->pRight);
        }
    }
void printInorder(){
        printInorderRecur(root);
    }

bool searchRecur(Node* node, const T &value){
        if(node == NULL) return 0;
        else{
            if(node->data < value) return searchRecur(node->pRight);
            else if(node->data > value) return searchRecur(node->pLeft);
            else if(node->data == value) return 1;
        }
        return 0;
    }
bool search(const T &value){
        return searchRecur(root, value);
    }
int treeLevel(Node *t){
	if (t == NULL) return -1;
	return 1 + max(treeLevel(t->pLeft), treeLevel(t->pRight));
}
bool checkAvl(Node *t){
	if (t == NULL) 	return true;
	if (abs(treeLevel(t->pLeft) - treeLevel(t->pRight)) > 1) return false;
	return checkAvl(t->pLeft) && checkAvl(t->pRight);
}
bool checkAvl(){
    return checkAvl(root);
}
int count(Node *t, int x){
	if (t == NULL) return 0;
	if (t->data == x) return 1 + count(t->pLeft, x) + count(t->pRight, x);
	else if (t->data < x) return count(t->pRight, x);
	return count(t->left, x);
}
class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};


int main(){
    AVLTree<int> avl;
    avl.insert(1);
    avl.insert(2);
    avl.insert(3);
    avl.insert(4);
    avl.insert(5);
    avl.insert(6);
    avl.insert(7);
    if(avl.checkAvl() == 1){
        cout << "avl" << endl;
    }
    avl.printTreeStructure();
    //cout << avl.search(10);
    return 0;
}