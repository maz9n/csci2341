/**
*  @file LL.hpp
*  @author Almozaini:Mazen:A00323488:csc34118
*  @version 1.0
*  @date 2014-06-12
*
*  this program add and edit the nodes as wanted from any type and
*  print it out.
*/

/*
program is working as intended
*/

#ifndef LL_H
#define LL_H

// includes
#include <iostream>
#include <strstream> 
#include <sstream>
using std::ostream;

//struct
template<typename T>
struct LLNode
{
    T data;
    LLNode<T>*  next;
};

//class
template<typename T>
class LL
{
public:
    // constructors
    LL();                   // default constructor

    // Big 3.5
    LL(const LL<T>& src);      // copy constructor
    LL<T>& operator=(LL<T> src);  // assignment operator
    ~LL();                  // destructor
    void swap(LL<T>& other);   // swap method
    /**<
    It swaps nodes that chosen
    @return none
    @param  other  is the object of that wanted to be swped
    @pre    none
    @post   none
    */

    // observers
    int size() const;
    /**<
    to get the size of the nodes
    @return int the number of the size
    @param  none
    @pre    none
    @post   none
    */
    bool empty() const;
    /**< 
    To tell if the list is empty or not
    @return boolean <tt>true<tt/> if its not empty , and <tt>false<tt/>
    if not
    @param  none
    @pre    none
    @post   none
    */
    const T& at(int p) const;     
    /**< 
    to show the date in any node has been chosen and it not allowed to
    be changed
    @return anytype that has been used 
    @param  p the number of what node is wanted to show back
    @pre   
    -# the number of the node has been chosen should be exists
      otherwise it will retrun exaption
    @post   
    -# Invalid index when didnt find the index it looking for
    */


    // mutators
    void push_front(T e);
    /**< 
    to add a new node in the front 
    @return none
    @param  e The data to be include in the new node
    @pre none
    @post none
    */
    void push_back(T e);
    /**< 
    to add a new node in the back
    @return none
    @param  e The data to be include in the new node
    @pre none
    @post none
    */
    T& at(int p);                 // read-write access
    /**< 
    to show the date in any node has been chosen
    @return anytype that has been used 
    @param  p the number of what node is wanted to show back
    @pre   
    -# the number of the node has been chosen should be exists 
    otherwise it will retrun exaption
    @post   
    -# Invalid index when didnt find the index it looking for
    */
    // friends
    template<typename T>
    friend ostream& operator<<(ostream& out, const LL<T>& list);
    /**< 
    To print the data that in the object
    @return ostream object which the output of the list  
    @param  out an object from ostream
    @param  list an object from LL which the list of the nodes
    @pre   
    -# The list need to have data in it to be print out
    @post   
    -# print in bracts[ "data" , "data" .... ] until the end of the list.
    */

    // private data
private:
    LLNode<T>* head;
};


template<typename T>
LLNode<T>* CopyNodes(LLNode<T>* srcNode)
{
    if (srcNode == nullptr) return nullptr;
    LLNode<T>* copy = new LLNode<T>;
    copy->data = srcNode->data;
    copy->next = CopyNodes(srcNode->next);
    return copy;
}
template<typename T>
void DeleteNodes(LLNode<T>* cur) 
{
    if (cur != nullptr) 
    {
        LLNode<T>* temp = cur;
        cur = cur->next;
        delete temp;
    }
}

// constructors
template<typename T>
LL<T>::LL()
{
    head = nullptr;
}

// Big 3.5
template<typename T>
LL<T>::LL(const LL<T>& src)
{
    head = CopyNodes(src.head);
}
template<typename T>
LL<T>& LL<T>::operator=(LL<T> src)
{
    this->swap(src);
    return *this;
}
template<typename T>
LL<T>::~LL()
{
    DeleteNodes(head);
}
template<typename T>
void LL<T>::swap(LL<T>& other)
{
    std::swap(head, other.head);
}

// helper
std::string intToString(int n) 
{
    std::ostringstream out;
    out << n;
    return out.str();
}

// observers
template<typename T>
const T& LL<T>::at(int p) const
{
    LLNode<T>* cur = head;
    for (int i = 0; i < p; ++i)
    {
        if (cur == nullptr)
            throw std::range_error("Invalid index: " + intToString(p));
        cur = cur->next;
    }
    return cur->data;
}
// The size function
template<typename T>
int LL<T>::size() const
{
    int count = 0;
    for(LLNode<T>* cur = head; cur != nullptr; cur = cur->next)
        ++count;
    return count;
}
template<typename T>
bool LL<T>::empty() const
{
    return head == nullptr;
}


// mutators
template<typename T>
T& LL<T>::at(int p)
{
    LLNode<T>* cur = head;
    for (int i = 0; i < p; ++i)
    {
        if (cur == nullptr)
            throw std::range_error("Invalid index: " + intToString(p));
        cur = cur->next;
    }
    return cur->data;
}
//The push front node function
template<typename T>
void LL<T>::push_front(T e)
{
    LLNode<T>* cur = head;
    head = new LLNode<T>;
    head->data = e;
    head->next = cur;
}
// The push back node function
template<typename T>
void LL<T>::push_back(T e)
{
    if (head == nullptr)
    {
        push_front(e);
    }
    else
    {
        LLNode<T>* cur = head; 
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = new LLNode<T>;
        cur->next->data = e;
        cur->next->next = nullptr;
    }
}

// friends
template<typename T>
ostream& operator<<(ostream& out, const LL<T>& list)
{
    LLNode<T>* cur = list.head;    // friends can do this!
    out << "[";
    if (cur != nullptr)
    {
        while (cur->next != nullptr)
        {
            out << cur->data << ", ";
            cur = cur->next;
        }
        out << cur->data;
    }
    out << "]";
    return out;
}


#endif