/* This is your h file. DO NOT edit it!
 * To know more about what a specific function should do, refer to the list
 *  documentationi from en.cppreference

 * TODO 1: implement the get_identity function in MyList.hpp
 * TODO 2: implement the MyList-related functions in MyList.hpp
 * TODO 3: thoroughly test your MYList class to ensure proper functional
    behaviors
 */

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;

/*
* Same username function
*/
void get_identity(std::string &my_id);


template <typename T>
class Node
{
    public:
        T m_element;

        Node<T> *m_prev;
        Node<T> *m_next;

        // Helps you make a dummy/sentinel node
        Node(Node<T> *in_prev, Node<T> *in_next):
            m_prev(in_prev), m_next(in_next){}

        Node(const T &x, Node<T> *in_prev, Node<T> *in_next):
            m_element(x), m_prev(in_prev), m_next(in_next){}
};


template <typename T>
class MyList
{
    private:
        Node<T> *m_sentinel = nullptr;
        int m_size;

    public:
        // Here is where you will initialize your list (of size 0) with a
        //  sentinel node
        MyList();

        MyList(const MyList<T> &source);

        // Use the removeall function from the sample lecture code as your guide
        ~MyList();

        MyList<T> & operator=(const MyList<T> &source);

        T & front();

        T & back();

        // Assigns new contents (#count elements, each initialized to a copy of
        //  value) to the list and replace its current contents
        //  (size should be modified accordingly)
        void assign(int count, const T &value);

        // Default list size of 0, with one sentinel node as in the
        //  default constructor
        void clear();

        void push_front(const T &x);

        void push_back(const T &x);

        void pop_back();

        void pop_front();

        // Simplified version (not exactly like std::list.insert) that inserts x
        //  before element at position i.
        // Note: You should be able to insert in an empty list
        void insert(int i, const T &x);

        // Removes all elements in list that are equal to value
        void remove(T value);

        // Removes element at position i
        void erase(int i);

        // Reverses the order of the elements in the list
        void reverse();

        bool empty();

        int size();

        // Mimicking C++ iterator; you don't need to edit these two
        int begin()
        {
            return 0;
        }

        int end()
        {
            return size();
        }
};

#include "MyList.hpp"

#endif
