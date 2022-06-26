#include <iostream>
using namespace std;
template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList() : head(NULL), tail(NULL), count(0) {};
    ~DLinkedList() {};
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item); 
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();
public:
    class Node
    {
    private:
        T data;
        Node* next;
        Node* previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T& data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
        string toString()
        {
            stringstream ss;
            ss << "[";
            Node* ptr = head;
            while (ptr != tail)
            {
                ss << ptr->data << ",";
                ptr = ptr->next;
            }

            if (count > 0)
                ss << ptr->data << "]";
            else
                ss << "]";
            return ss.str();
        }
    };

};

template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    if (count == 0){
        Node *newNode = new Node(e);
        head = tail = newNode;
        count++;
    }
    else{
    
        Node *temp = new Node(e);
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
        
    }
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    if (index < 0 || index > count){
        return;
    }
    else if (index == 0 || count == 0){
        if (count == 0){
            Node *newNode = new Node(e);
            head = tail = newNode;
        }
        else{
            Node *pTmp = new Node(e);
            pTmp->next = head;
            head->previous = pTmp;
            head = pTmp;
        }
    }
    else{ 
        Node *newnode = new Node(e);
        Node *temp = head;
        for (int i = 0; i < index - 1; i++){
            temp = temp->next;
        }
        Node *pTmp = temp->next;
        newnode->next = temp->next;
        pTmp->previous = newnode;
        newnode->previous = temp;
        temp->next = newnode;
    }
    count++;
    
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}

template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index < 0 || index >= count){
        throw std::out_of_range("out of range");
    }
    Node *pTmp = head;
    for (int i = 0; i < index; i++){
        pTmp = pTmp->next;
    }
    return pTmp->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if (index < 0 || index >= count) {
        throw std::out_of_range("out of range");
    }
    Node *pTmp = head;
    for(int i = 0; i < index; i++){
        pTmp = pTmp->next;
    }
    pTmp->data = e;
    
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    if (count == 0){ return true;}
    else {return false;}
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    if (count == 0) return -1;
    Node *pTmp = head;
    int i = 0;
    while (pTmp != NULL){
        if(pTmp->data == item){
            return i;
        }
        i++;
        pTmp = pTmp->next;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    if (indexOf(item) != -1) {return true;}
    else {return false;}
}

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index < 0 || index >= this->count){
        return -1;
    }
    else{
        Node *newNode = this->head;
        int value;
        if (index == 0){
            this->head = newNode->next;
            value = newNode->data;
            delete newNode;
        }
        else if (index > 0 && index < this->count-1){
            for (int i = 0; i < index - 1; i++){
                newNode = newNode->next;
            }
            Node *pNew = newNode->next;
            value = pNew->data;
            newNode->next = pNew->next;
            delete pNew;
        }
        else if (index == this->count-1){
            for (int i = 0; i < index - 1; i++){
                newNode = newNode->next;
            }
            Node *temp = newNode->next;
            this->tail = newNode;
            newNode->next = NULL;
            value = temp->data;
            delete temp;
        }
    count--;
    return value;
    }
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    if (indexOf(item) == -1) {
        return false;
    }
    else{
	    removeAt(indexOf(item));
	    return true;
    }
}

template<class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
     while (head != NULL){
        Node *pTmp = this->head;
        head = head->next;
        delete pTmp;
        count--;
    }
}
