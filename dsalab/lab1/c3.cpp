#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>

using namespace std;
template <class T>
class SLinkedList
{
public:
	 class Iterator; //forward declaration
	class Node;     //forward declaration

protected:
	Node* head;
	Node* tail;
	int count;

public:
	SLinkedList() : head(NULL), tail(NULL), count(0) {};
	~SLinkedList();
	void add(const T& e);
	void add(int index, const T& e);
	int size();

	T removeAt(int index);
	bool removeItem(const T& removeItem);
	bool empty();
	
	void clear();
	T get(int index);
	void set(int index, const T& e);
	int indexOf(const T& item);
	bool contains(const T& item);
	string toString();

	SLinkedList(const SLinkedList& list)
	{
		this->count = 0;
		this->head = NULL;
		this->tail = NULL;
	}

	Iterator begin()
	{
		return Iterator(this, true);
	}
	Iterator end()
	{
		return Iterator(this, false);
	}

public:
	class Node
	{
	private:
		T data;
		Node* next;
		friend class SLinkedList<T>;

	public:
		Node()
		{
			next = 0;
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

	class Iterator
	{
	private:
		SLinkedList<T>* pList;
		Node* current;
		int index;

	public:
		Iterator(SLinkedList<T>* pList = NULL, bool begin = true);
		Iterator& operator=(const Iterator& iterator);
		void remove();
		void set(const T& e);
		T& operator*();
		bool operator!=(const Iterator& iterator);
		Iterator& operator++();
		Iterator operator++(int);
	};
};

template <class T>
void SLinkedList<T>::add(const T& e) {
	/* Insert an element into the end of the list. */
	if (this->count == 0) {
	    this->tail = this->head = new Node(e, NULL);
	}
	else this->tail = this->tail->next = new Node(e, NULL);
	this->count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
	/* Insert an element into the list at given index. */
	if (this->count == 0 || index >= this->count) {
		add(e);
		return;
	}
	else if (index <= 0)	{
	    this->head = new Node(e, this->head);
	}
	else {
		Node* pnode = this->head;
		for (int i = 0; i < index - 1; i++) {
		    pnode = pnode->next;
		}
		pnode->next = new Node(e, pnode->next);
	}
	this->count++;
}

template<class T>
int SLinkedList<T>::size() {
	/* Return the length (size) of list */
	return this->count;
}

template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index < 0 || index >= this->count) {
        throw std::out_of_range("out of range");
    }
    Node *pTmp = this->head;
    for (int i = 0; i < index; i++){
        pTmp = pTmp->next;
    }
    return pTmp->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if (index < 0 || index >= this->count) {
        throw std::out_of_range("out of range");
    }
    Node *pTmp = this->head;
    for (int i = 0; i < index; i++){
        pTmp = pTmp->next;
    }
    pTmp->data = e;
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    if (this->count == 0){
        return true;
    }
    return false;
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node *pTmp = this->head;
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
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
     Node *pTmp = this->head;
    int i = 0;
    while (pTmp != NULL){
        
        if(pTmp->data == item){
            return true;
        }
        i++;
        pTmp = pTmp->next;
        
    }
    return false;
}

int main (){
    SLinkedList<int> list;
    list.add(5);
    list.add(5);
    list.add(5);
    list.add(5);
    list.add(5);
    list.add(5);
    list.add(5);
    list.add(5);
        
    return 0;
}