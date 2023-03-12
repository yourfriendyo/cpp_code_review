#pragma once
#include <iostream>
#include <cassert>
using namespace std;
namespace test
{
template<class T>
struct __list_node
{
    __list_node(T t = T())
        : _data(t)
        , _prev(nullptr)
        , _next(nullptr)
    {}

    T               _data;
    __list_node<T>* _prev;
    __list_node<T>* _next;
};

template<class T, class Ref, class Ptr>
struct __list_iterator
{
    typedef __list_node<T>               list_node;
    typedef __list_iterator<T, Ref, Ptr> self;

    __list_iterator(list_node* node)
        : _node(node)
    {}

    Ref operator*() { return _node->_data; }

    Ptr operator->() { return &_node->_data; }

    self& operator++()
    {
        _node = _node->_next;
        return *this;
    }

    self operator++(int)
    {
        self tmp(*this);
        ++(*this);
        return tmp;
    }

    self& operator--()
    {
        _node = _node->_prev;
        return *this;
    }

    self operator--(int)
    {
        self tmp(*this);
        --*this;
        return *this;
    }

    bool operator!=(const self& s) const { return _node != s._node; }
    bool operator==(const self& s) const { return _node == s._node; }

    list_node* _node;
};


template<class T>
class list
{
public:
    typedef __list_node<T>                         list_node;
    typedef __list_iterator<T, T&, T*>             iterator;
    typedef __list_iterator<T, const T&, const T*> const_iterator;

    iterator begin() { return iterator(_head->_next); }
    iterator end() { return iterator(_head); }

    const_iterator begin() const { return const_iterator(_head->_next); }
    const_iterator end() const { return const_iterator(_head); }

public:
    list()
    {
        _head        = new list_node;
        _head->_prev = _head;
        _head->_next = _head;
    }

    void push_back(T x)
    {
        // list_node* new_node = new list_node(x);
        // list_node* tail     = _head->_prev;

        // tail->_next     = new_node;
        // new_node->_prev = tail;

        // _head->_prev    = new_node;
        // new_node->_next = _head;

        insert(end(), x);
    }

    void push_front(T x) { insert(begin(), x); }

    void pop_front() { erase(begin()); }

    void pop_back() { erase(--end()); }

    iterator insert(iterator pos, T x)
    {
        list_node* new_node = new list_node(x);
        list_node* prev     = pos._node->_prev;
        list_node* next     = pos._node;

        prev->_next     = new_node;
        new_node->_prev = prev;

        new_node->_next = next;
        next->_prev     = new_node;

        return pos;
    }

    iterator erase(iterator pos)
    {
        assert(pos != end());

        list_node* prev = pos._node->_prev;
        list_node* next = pos._node->_next;

        prev->_next = next;
        next->_prev = prev;

        delete pos._node;
        return iterator(next);
    }

    void print()
    {
        for (auto e : *this)
        {
            cout << e << "->";
        }
        cout << "#" << endl;
    }

private:
    list_node* _head;
};

struct AA
{
    int _a1;
    int _a2;

    AA(int a1 = 0, int a2 = 0)
        : _a1(a1)
        , _a2(a2)
    {}
};

inline void test_list_1()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);

    lt.insert(lt.begin(), 0);
    //list<int>::iterator pos = find(lt.begin(), lt.end(), 2);
    // lt.insert(pos, 11);
    lt.insert(lt.end(), 5);

    lt.print();

    list<int>::iterator it = lt.begin();
    while (it != lt.end())
    {
        if (*it % 2 == 0)
        {
            it = lt.erase(it);
        }
        else
        {
            ++it;
        }
    }
    lt.print();
}

} // namespace test
