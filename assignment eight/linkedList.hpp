/*
Title: Chapter Sixteen Linked List Print Backwards Program -- linkedList Header File
Created by William Schaeffer
CPS 362
P. 1174, Challenge 4, Linked List Print Backwards Program, Week 9
03.24.2022
*/

#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <cassert>

using namespace std;

//Definition of the node

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type>* link;
};

//              ===============  class linkedListIterator  ===============


template <class Type>
class linkedListIterator
{
public:
    //Default constructor
        //Postcondition: current = nullptr;
    linkedListIterator();

    //Constructor with a parameter.
        //Postcondition: current = ptr;
    linkedListIterator(nodeType<Type>* ptr);
    
    //Function to overload the dereferencing operator *.
        //Postcondition: Returns the info contained in the node.
    Type operator*();
    
    //Overload the pre-increment operator.
        //Postcondition: The iterator is advanced to the next node.
    linkedListIterator<Type> operator++();
    
    //Overload the equality operator.
        //Postcondition: Returns true if this iterator is equal to the 
        //iterator specified by right, otherwise it returns the value false.
    bool operator==(const linkedListIterator<Type>& right) const;
    
    //Overload the not equal to operator.
        //Postcondition: Returns true if this iterator is not equal to the 
        //iterator specified by right; otherwise it returns the value false.
    bool operator!=(const linkedListIterator<Type>& right) const;
    
private:
    nodeType<Type>* current;                            //pointer to point to the current node in the linked list
};

//Constructors

    //Default Constructor
template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = nullptr;
}

    //Constructor with parameter
template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type>* ptr)
{
    current = ptr;
}

//Overload Operators

    //Overload dereferencing operator
template <class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info;
}

    //Overload pre-increment operator
template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
    current = current->link;

    return *this;
}

    //Overload equality operator
template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
    return (current == right.current);
}

    //Overload not equal operator
template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
{
    return (current != right.current);
}


//              ===============  class linkedListType   ===============

template <class Type>
class linkedListType
{
public:

//Overload Operators
    
    //Overload the assignment operator.
    const linkedListType<Type>& operator=(const linkedListType<Type>&);

//Member Functions

    //Initialize the list to an empty state.
        //Postcondition: first = nullptr, last = nullptr, count = 0;
    void initializeList();

    //Function to determine whether the list is empty. 
        //Postcondition: Returns true if the list is empty, otherwise it returns false.
    bool isEmptyList() const;
    
    //Function to output the data contained in each node.
        //Postcondition: none
    void print() const;

    //Function to output the data in each node, starting from the last element
        //Postcondition: none
    void reversePrint(nodeType<Type> *current) const;
    
    void printListReverse() const;

    //Function to return the number of nodes in the list.
        //Postcondition: The value of count is returned.
    int length() const;

    //Function to delete all the nodes from the list.
        //Postcondition: first = nullptr, last = nullptr, count = 0;
    void destroyList();

    //Function to return the first element of the list.
        //Precondition: The list must exist and must not be empty.
        //Postcondition: If the list is empty, the program terminates; 
        //otherwise, the first element of the list is returned.
    Type front() const;

    //Function to return the last element of the list.
        //Precondition: The list must exist and must not be empty.
        //Postcondition: If the list is empty, the program terminates; otherwise, 
        //the last element of the list is returned.
    Type back() const;

    //Function to determine whether searchItem is in the list.
        //Postcondition: Returns true if searchItem is in the list, otherwise the value 
        //false is returned.
    virtual bool search(const Type& searchItem) const = 0;
    
    //Function to insert newItem at the beginning of the list.
        //Postcondition: first points to the new list, newItem is inserted at the beginning 
        //of the list, last points to the last node in the list, and count is incremented by 1.
    virtual void insertFirst(const Type& newItem) = 0;

    //Function to insert newItem at the end of the list.
        //Postcondition: first points to the new list, newItem is inserted at the end of 
        //the list, last points to the last node in the list, and count is incremented by 1.
    virtual void insertLast(const Type& newItem) = 0;

    //Function to delete deleteItem from the list.
        //Postcondition: If found, the node containing deleteItem is deleted from the list.
        //first points to the first node, last points to the last node of the updated list, 
        //and count is decremented by 1.
    virtual void deleteNode(const Type& deleteItem) = 0;
    
    
    //Function to return an iterator at the begining of the linked list.
        //Postcondition: Returns an iterator such that current is set to first.
    linkedListIterator<Type> begin();
    
    
    //Function to return an iterator one element past the last element of the linked list. 
        //Postcondition: Returns an iterator such that current is set to nullptr.
    linkedListIterator<Type> end();
    
//Constructors
    //Default constructor
    //Initializes the list to an empty state.
        //Postcondition: first = nullptr, last = nullptr, count = 0; 
    linkedListType();

    //copy constructor
    linkedListType(const linkedListType<Type>& otherList);

//Destructor
    //Deletes all the nodes from the list.
    //Postcondition: The list object is destroyed. 
    ~linkedListType();
    

protected:
    int count;                                          //variable to store the number of elements in the list
    nodeType<Type>* first;                              //pointer to the first node of the list
    nodeType<Type>* last;                               //pointer to the last node of the list

private:
    //Function to make a copy of otherList.
        //Postcondition: A copy of otherList is created and assigned to this list.
    void copyList(const linkedListType<Type>& otherList);
};

    //Function to test if the List is empty
template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == nullptr);
}

    //Default Constructor
template <class Type>
linkedListType<Type>::linkedListType()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

    //Function to delete all nodes from the list
template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type>* temp;                               //pointer to deallocate the memory occupied by the node
    while (first != nullptr)                            //while there are nodes in the list
    {    
        temp = first;                                   //set temp to the current node
        first = first->link;                            //advance first to the next node
        delete temp;                                    //deallocate the memory occupied by temp
    }
    last = nullptr;                                     //initialize last to nullptr; first has already been set to nullptr by the while loop
    count = 0;
}

    //Function to initialize list
template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList();                                      //if the list has any nodes, delete them
}

    //Function to print list
template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type>* current;                            //pointer to traverse the list

    current = first;                                    //set current so that it points to the first node
    while (current != nullptr)                          //while more data to print
    {
        cout << current->info << " ";
        current = current->link;
    }
}//end print

    //Function to print list in reverse
        //calls itself recursively
template <class Type>
void linkedListType<Type>::reversePrint(nodeType<Type> *current) const
{
    if (current != nullptr)
    {
        reversePrint(current->link);                    //print tail
        cout << current->info << " ";                   //print node
    }
}

    //Function to print list in reverse
        //calls reversePrint, which then calls recursively
template <class Type>
void linkedListType<Type>::printListReverse() const
{
    reversePrint(first);
    cout << endl;
}

    //Function to return length of list
template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}

    //Function to return first node in list
template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != nullptr);

    return first->info;                                 //return the info of the first node	
}

    //Function to return last node in list
template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last != nullptr);

    return last->info;                                  //return the info of the last node	
}
    
    //Function to return an iterator at the begining of the linked list
template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);

    return temp;
}

    //Function to return an iterator one element past the last element of the linked list
template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(nullptr);

    return temp;
}


    //Function to copy list
template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
    nodeType<Type>* newNode;                            //pointer to create a node
    nodeType<Type>* current;                            //pointer to traverse the list

    if (first != nullptr)                               //if the list is nonempty, make it empty
        destroyList();

    if (otherList.first == nullptr)                     //otherList is empty
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else
    {
        current = otherList.first;                      //current points to the list to be copied
        count = otherList.count;

    //copy the first node
        first = new nodeType<Type>;                     //create the node

        first->info = current->info;                    //copy the info
        first->link = nullptr;                          //set the link field of the node to nullptr
        last = first;                                   //make last point to the first node
        current = current->link;                        //make current point to the next node

    //copy the remaining list
        while (current != nullptr)
        {
            newNode = new nodeType<Type>;               //create a node
            newNode->info = current->info;              //copy the info
            newNode->link = nullptr;                    //set the link of newNode to nullptr
            last->link = newNode;                       //attach newNode after last
            last = newNode;                             //make last point to the actual last node
            current = current->link;                    //make current point to the next node
        }
    }
}

    //destructor
template <class Type>
linkedListType<Type>::~linkedListType()
{
    destroyList();
}

    //copy constructor
template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
    first = nullptr;
    copyList(otherList);
}

    //function to overload the assignment operator
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
    if (this != &otherList)                             //avoid self-copy
    {
        copyList(otherList);
    }

    return *this;
}

#endif
