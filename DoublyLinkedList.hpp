/****************************************************************************************************************************
Title       : DoublyLinkedList.hpp
Auhors      : Kelly Camacho
Description : header/interface file of a linked list class
****************************************************************************************************************************/

#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

#include "DoubleNode.hpp"

template<typename ItemType>
class DoublyLinkedList : public DoubleNode<ItemType*> {
    public:
        //Default Constructor
        DoublyLinkedList();

        //Copy Constructor 
        DoublyLinkedList(const DoublyLinkedList<ItemType>& a_list);

        //Destructor
        ~DoublyLinkedList();

        bool insert(const ItemType &item, const int &position) ;
        //inserts item at position in caller list
            
        bool remove(const int &position);           
        //removes the node at position

        int getSize() const;                        
        // returns the number of the nodes in the calling list
                        
        DoubleNode<ItemType> *getHeadPtr() const;   
        // returns a copy of the headPtr

        DoubleNode<ItemType> *getAtPos(const int &pos) const; 
        // returns a pointer to the node located at pos

        bool isEmpty() const;                       
        // returns whether the calling list is empty

        void clear();                               
        // clears the list

        int getIndexOf(const ItemType &item) const; 
        // returns the position of the given item in the list, -1 otherwise

        void display() const;                       
        // prints the contents of the calling list in order

        void displayBackwards() const;              
        // prints the contents of the calling list in reverse order

        DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType> &a_list); 
        // returns the interleaved list of the calling and parameter lists

        ItemType getEntry(int position) const;
        //returns item of given position in the list

    private:
        DoubleNode<ItemType> *headPtr;    
        //pointer to first node in chain
        //(contains the first entry in the list) 
        
        int itemCount;  //current count of list items

};

#include "DoublyLinkedList.cpp"
#endif //DOUBLY_LINKED_LIST_H_ 