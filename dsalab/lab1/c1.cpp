#include <iostream>
#include <ostream>
using namespace std;
class Node {
    friend class Iterator;
    template<class T> friend class List;

protected:
    Node *next_, *prev_;

    void push_back(Node* n) {
        n->next_ = this;
        n->prev_ = prev_;
        prev_->next_ = n;
        prev_ = n;
    }

    void unlink() {
        Node *next = next_, *prev = prev_;
        next->prev_ = prev;
        prev->next_ = next;
        next_ = this;
        prev_ = this;
    }

public:
    Node()
        : next_(this), prev_(this)
    {}

    ~Node() { unlink(); }
};
class Iterator {
protected:
    Node* node_;

    Iterator(Node* node)
        : node_(node)
    {}

public:
    Iterator& operator++() {
        node_ = node_->next_;
        return *this;
    }

    bool operator==(Iterator b) const { return node_ == b.node_; }
    bool operator!=(Iterator b) const { return node_ != b.node_; }

    // Implement the rest of iterator interface.
};
template<class T>
class SLinkedList {
    class NodeT : public Node {
        friend class SLinkedList<T>;
        T value_;
        NodeT(T t) : value_(t) {}
    };

    template<class U>
    class IteratorT : public Iterator {
        friend class SLinkedList<T>;
        NodeT* node() const { return static_cast<NodeT*>(node_); }
    public:
        U& operator*() const { return node()->value_; }
        U* operator->() const { return &node()->value_; }
        operator IteratorT<U const>() const { return node_; } // iterator to const_iterator conversion
        IteratorT(Node* node) : Iterator{node} {}
    };

    Node list_;

public:
    using iterator = IteratorT<T>;
    using const_iterator = IteratorT<T const>;

    ~List() { clear(); }
    bool empty() const { return list_.next_ == &list_; }

    iterator begin() { return list_.next_; }
    iterator end() { return &list_; }

    void push_back(T t) { list_.push_back(new NodeT(t)); }
    void erase(const_iterator i) { delete i.node(); }

    void clear() {
        while(!empty())
            erase(begin());
    }

    // Implement the rest of the functionality.
};
class Polynomial;
class Term {
private:
    double coeff;   
    int exp;
    friend class Polynomial;
public:
    Term(double coeff = 0.0, int exp = 0) {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term& rhs) const {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream & operator<<(ostream &os, const Term& term) {
        cout << endl;
        cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};

class Polynomial {
private:
    SLinkedList<Term>* terms;
public:
    Polynomial() {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial() {
        this->terms->clear();
    }
    void insertTerm(const Term& term);
    void insertTerm(double coeff, int exp);
    void print() {
        SLinkedList<Term>::IteratorT it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << endl << "]";
    }
};
void Polynomial::insertTerm(const Term& term) {
    //STUDENT ANSWer
    if (term.coeff != 0){
    if(!this->terms){
        this->terms->add(term);
    }
    else {
        int index = 0;
        bool flag = false;
        SLinkedList<Term>::Iterator it = this->terms->begin();
        while(it != this->terms->end() && !flag){

            if((*it).exp ==term.exp){
                (*it).coeff +=term.coeff;
                if((*it).coeff == 0){
                    SLinkedList<Term>::Iterator temp = it;
                    if (it != this->terms->end()) it++;
                    flag = this->terms->removeItem(*temp);
                }
                flag = true;
            }
            else if((*it).exp < term.exp){
                this->terms->add(index, term);
                flag = true;
            }
            if(!flag) it++;
            index++;
        }
        if(!flag and (term.coeff != 0)){this->terms->add(index,term);}
    }
    }
    
}

void Polynomial::insertTerm(double coeff, int exp) {
    Term term = Term(coeff, exp);
    insertTerm(term);
    
}

// #include "Header.h"
// #include <iostream>
// #include <string>
// #include <sstream>
// #include <assert.h>
// using namespace std;
// class Polynomial;

// class Term {
// private:
//     double coeff;
//     int exp;
//     friend class Polynomial;

// public:
//     Term(double coeff = 0.0, int exp = 0) {
//         this->coeff = coeff;
//         this->exp = exp;
//     }

//     bool operator==(const Term& rhs) const {
//         return this->coeff == rhs.coeff && this->exp == rhs.exp;
//     }

//     friend ostream& operator<<(ostream& os, const Term& term) {
//         cout << endl;
//         cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
//         return os;
//     }
// };

// class Polynomial {
// private:
//     SLinkedList<Term>* terms;

// public:
//     Polynomial() {
//         this->terms = new SLinkedList<Term>();
//     }

//     ~Polynomial() {
//         this->terms->clear();
//     }

//     void insertTerm(const Term& term) {
//         this->terms->add(term);
//     }
//     void insertTerm(double coeff, int exp) {
//         Term term(coeff, exp);
//         insertTerm(term);
//     }
//     // Polynomial operator+(const Polynomial& rhs);

//     void print() {
//         SLinkedList<Term>::Iterator it;
//         cout << "[";
//         for (it = this->terms->begin(); it != this->terms->end(); it++) {
//             cout << (*it);
//         }
//         cout << endl << "]";
//     }
// };
// int main() {
//     Polynomial* poly = new Polynomial();
//     poly->insertTerm(6.0, 2);
//     poly->insertTerm(4.0, 5);
//     poly->insertTerm(4.0, 3);
//     poly->insertTerm(6.0, 5);
//     poly->insertTerm(-1.0, 0);
//     poly->insertTerm(-6.0, 6);
//     poly->insertTerm(6.0, 6);
//     poly->print();
// }