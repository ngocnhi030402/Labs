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
	void add2(const T& e);
	void add(int index, const T& e);
	int size();
	void print();
	void listDiff(Node* list1, Node* list2);
	Node* getUnion(Node* head1, Node* head2){
		Node* ans = new Node(-1);
    struct Node* head = ans;
    SLinkedList<int> st;
    while (head1 != NULL) {
        st.add2(head1->data);
        head1 = head1->next;
    }
    while (head2 != NULL) {
        st.add2(head2->data);
        head2 = head2->next;
    }
    for (auto it : st) {
        struct Node* t = new Node(it);
        ans->next = t;
        ans = ans->next;
    }
    head = head->next;
	while(head != NULL){
		cout << head->data << " ";
	}
    return head;
	}
	Node* getHead(){
		return this->head;
	}

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


template<class T>
SLinkedList<T>::~SLinkedList()
{
}

template <class T>
void SLinkedList<T>::add(const T& e) {
	/* Insert an element into the end of the list. */
	if (this->count == 0){
		this->tail = this->head = new Node(e, NULL);
	}		else {
		this->tail = this->tail->next = new Node(e, NULL);
	}
	this->count++;
}

template <class T>
void SLinkedList<T>::print(){
	if(!head){
		cout << "Empty list";
		return;
	}
	while(head){
		cout << head->data << " ";
		head = head->next;
	}
}

template <class T>
void SLinkedList<T>::add2(const T& e){
	if(head == NULL){
		Node* temp = new Node(e);
		head = temp;
	}
	else{
		Node* temp = new Node(e);
		Node* p = head;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = temp;
	}
}


template<class T>
void SLinkedList<T>::listDiff(typename SLinkedList<T>::Node* list1, typename SLinkedList<T>::Node* list2){
	SLinkedList<int> nhi;
	cout << "list" << endl;
	cout << "list1->data: " <<  head->data << endl << list2->data << endl;
		
	while(list1->next != NULL){
		cout << "list1->data: " <<  list1->data << endl << list2->data << endl;
		if(list1->data != list2->data){
			cout << "in" << endl;
			if(list1->data < list2->data){
				nhi.add2(list1->data);
				nhi.add2(list2->data);
			}
		
			else{
				nhi.add2(list2->data);
				nhi.add2(list1->data);
			}
		}
		cout << "what" << endl;
		list1 = list1->next;
		list2 = list2->next;
	}


	cout << "print" << endl;
	nhi.print();
	
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
	/* Insert an element into the list at given index. */
	if (this->count == 0 || index >= this->count) {
		add(e);
		return;
	}
	else if (index <= 0)	this->head = new Node(e, this->head);
	else {
		Node* pnode = this->head;
		for (int i = 0; i < index - 1; i++)   pnode = pnode->next;
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
	//if (empty() || index < 0 || index >= this->count) throw std::out_of_range("Index is out of range");
	Node* tmp = this->head;
	for (int i = 0; i < index; i++) tmp = tmp->next;
	return tmp->data;

}
template <class T>
void SLinkedList<T>::set(int index, const T& e) {
	if (index < 0 || index >= this->count) 	throw std::out_of_range("Index is out of range");
	Node* pNode = this->head;
	for (int i = 0; i < index; i++) pNode = pNode->next;
	pNode->data = e;
}
template<class T>
bool SLinkedList<T>::empty() {
	/* Check if the list is empty or not. */
	return (this->count == 0);
}
template<class T>
int SLinkedList<T>::indexOf(const T& item) {
	/* Return the first index wheter item appears in list, otherwise return -1 */
	Node* pNode = this->head;
	int i = 0;
	while (pNode != NULL) {
		if (pNode->data == item) {
			return i;
		}
		i++;
		pNode = pNode->next;
	}
	return -1;
}
template<class T>
bool SLinkedList<T>::contains(const T& item) {
	/* Check if item appears in the list */
	return (this->indexOf(item) != -1);
}
template<class T>
string SLinkedList<T>::toString()
{
	stringstream ss;
	ss << "[";
	Node* ptr = head;
	while (ptr != tail) {
		ss << ptr->data << ",";
		ptr = ptr->next;
	}

	if (count > 0)
		ss << ptr->data << "]";
	else
		ss << "]";
	return ss.str();
}
//template <class T>
// T SLinkedList<T>::removeAt(int index)
// {
// 	if (index >= this->count || index < 0) throw out_of_range("");
// 	T value = this->get(index);
// 	if (index == 0) {
// 		Node* pNode = this->head;
// 		this->head = pNode->next;
// 		delete pNode;
// 		this->count--;
// 		return value;
// 	}
// 	Node* pNode = this->head;
// 	for (int i = 0; i < index - 1; i++) {
// 		pNode = pNode->next;
// 	}
// 	Node* tmp = pNode->next;
// 	pNode->next = pNode->next->next;
// 	delete tmp;
// 	if (index == this->count - 1) this->tail = pNode;
// 	this->count--;
// 	return value;

// }

// template <class T>
// bool SLinkedList<T>::removeItem(const T& item)
// {
// 	if (this->indexOf(item) == -1) return false;
// 	this->removeAt(this->indexOf(item));
// 	return true;
// }

// template<class T>
// void SLinkedList<T>::clear() {
// 	while (this->head != NULL) {
// 		Node* currentNode = this->head;
// 		this->head = this->head->next;
// 		delete currentNode;
// 	}
// 	this->count = 0;
// }


template <class T>
T SLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index < 0 || index >= this->count){
        throw std::out_of_range("out of range");
    }
    int value = get(index);
    if (index == 0){
        Node *temp = this->head;
        delete temp;
        count--;
        return value;
    }
    Node *pTmp = this->head;
    for (int i = 0; i < index - 1; i++){
        pTmp = pTmp->next;
    }
    Node *temp = pTmp;
    pTmp->next = pTmp->next->next;  
    count--;
    return value;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    int idx = indexOf(item);
    if (idx != -1){
        removeAt(idx);
        return true;
    }
    return false;

}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    
    while (head != NULL){
        Node *pTmp = this->head;
        head = head->next;
        delete pTmp;
    }
}

template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
	this->pList = pList;
	if (begin) {
		if (pList != NULL) {
			this->current = this->pList->head;
			this->index = 0;
		}
		else {
			this->current = NULL;
			this->index = -1;
		}
	}
	else {
		this->current = NULL;
		if (pList != NULL) this->index = this->pList->size();
		else this->index = 0;
	}
}

template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
	/*
		Assignment operator
		* Set this current, index, pList to iterator corresponding elements.
	*/
	this->current = iterator.current;
	this->pList = iterator.pList;
	this->index = iterator.index;
	//*this = iterator;
	return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
	/*
		Remove a node which is pointed by current
		* After remove current points to the previous node of this position (or node with index - 1)
		* If remove at front, current points to previous "node" of head (current = NULL, index = -1)
		* Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
	*/
	if (this->current == NULL) throw std::out_of_range("Segmentation fault!");
	else if (this->index == 0) {
		this->pList->removeAt(this->index);
		this->current = NULL;
		this->index = -1;
	}
	else {
		this->current = this->pList->head;
		for (int i = 0; i < this->index - 1; i++) {
			this->current = this->current->next;
		}
		this->pList->removeAt(this->index);
		this->index -= 1;
	}
}

template <class T>
void SLinkedList<T>::Iterator::set(const T& e)
{
	/*
		Set the new value for current node
		* Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
	*/
	if (this->current == NULL) throw std::out_of_range("Segmentation fault!");
	this->current->data = e;
}

template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
	/*
		Get data stored in current node
		* Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
	*/
	//if ((this->current)==NULL) throw std::out_of_range("Segmentation fault!");
	return this->current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
	/*
		Operator not equals
		* Returns true if two iterators points the same node and index
	*/

	return !(this->current == iterator.current);
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
	/*
		Prefix ++ overload
		* Set current to the next node
		* If iterator corresponds to the previous "node" of head, set it to head
		* Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
	*/
	if (this->index == -1) this->current = this->pList->head;
	//else if (this->current == this->pList->tail) throw std::out_of_range("Segmentation fault!");
	else this->current = this->current->next;
	this->index++;
	return *this;
}
// Postfix ++ overload

int main() {
	SLinkedList<int> list, list2, list1;

	int size = 10;
	for (int idx = 0; idx < size; idx++) {
		list.add2(idx);
	}
    //cout << list.removeAt(1) << endl;
	list1.add2(1);
	list1.add2(2);
	list1.add2(3);
	list1.add2(4);
	list1.add2(5);
	list1.add2(6);
	list1.add2(7);
	// SLinkedList<int>::Iterator it;
	// int expvalue = 0;
	// for (it = list.begin(); it != list.end(); it++) {
	// 	assert(*it == expvalue);
	// 	expvalue += 1;
	// }
    list.print();
	cout << endl;
	list1.print();
	cout << endl;
	list.getUnion(list.getHead(), list1.getHead());
	list2.getUnion(list.getHead(), list1.getHead());

	//list.add(3, 34);
    
	//list2.listDiff(list1.getHead(), list.getHead());
	list1.print();
	list2.print();
    //cout << list.toString();
	//list.clear();
    //cout << "clear" << endl;
	//cout << list.toString();


}