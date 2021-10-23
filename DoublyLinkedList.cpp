/****************************************************************************************************************************
Title        : DoublyLinkedList.hpp
Auhors       : Kelly Camacho
Description  : partial implementation file of a linked list class
Dependencies : DoublyLinkedList.hpp
****************************************************************************************************************************/

#include "DoublyLinkedList.hpp"
#include <string>

/* Constructor */
template<typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList() : headPtr(nullptr), itemCount(0)
{

}   //end default constructor 

/* Copy Constructor */
template<typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType>& a_list) {
    itemCount = a_list.itemCount;

    DoubleNode<ItemType>* orig_chain_ptr = a_list.headPtr; //points to nodes in original chain
    if(orig_chain_ptr == nullptr) {
        headPtr = nullptr; //original bag is empty
    }
    else {
        //copy first node
        headPtr = new DoubleNode<ItemType>();
        headPtr->setItem(orig_chain_ptr->getItem()); //copy first node

        //copy remaining nodes
        DoubleNode<ItemType>* new_chain_ptr = headPtr; //points to last node in new chain
        orig_chain_ptr = orig_chain_ptr->getNext(); //advance original chain pointer

        while(orig_chain_ptr != nullptr) {
            ItemType next_item = orig_chain_ptr->getItem(); //get next item from original chain
            DoubleNode<ItemType>* new_node_ptr = new DoubleNode<ItemType>(next_item); //create a new node containing the next item

            new_chain_ptr->setNext(new_node_ptr); //link new node to end of new chain
            new_chain_ptr = new_chain_ptr->getNext(); //advance pointer to new last node
            orig_chain_ptr = orig_chain_ptr->getNext(); //advance original chain pointer
            
        }   //end while

        new_chain_ptr->setNext(nullptr); //flag end of chain

    }   //end if
}   //end copy constructor 

/* Destructor */
template<typename ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList() {
    clear();
}   //end destructor

template<typename ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType &item, const int &position) {
    bool ableToInsert = (position >= 1) && (position <= itemCount +1);

    if(ableToInsert) {
        //create a new node containing the new entry
        DoubleNode<ItemType>* newNodePtr = new DoubleNode<ItemType>(item);

        //attach new node to chain
        if(position == 1) {
            //insert new node at beginning of chain
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else {
            //find node that will be before new node
            DoubleNode<ItemType>* prePtr = getAtPos(position - 1);

            //insert new node after node to which prePtr points
            newNodePtr->setNext(prePtr->getNext());
            prePtr->setNext(newNodePtr);
        }   //end if

        itemCount++; //increase count of entries
    }   //end if

    return ableToInsert;
}   //end insert

template<typename ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &position) {
    bool ableToRemove = (position>= 1) && (position <= itemCount);

    if(ableToRemove) {
        DoubleNode<ItemType>* currPtr = nullptr;

        if(position == 1) {
            //remove first node in the chain
            currPtr = headPtr; //save to pointer
            headPtr = headPtr->getNext();
        }
        else {
            //find node that is before the one to remove
            DoubleNode<ItemType>* prePtr = getAtPos(position - 1);

            currPtr= prePtr->getNext(); //point to node to remove

            //disconnect indicated node from chain by connecting the prior node with the one after
            prePtr->setNext(currPtr->getNext());
        }   //end if

        //return node to system
        currPtr->setNext(nullptr);
        delete currPtr;
        currPtr = nullptr;
        itemCount--; //decrease count of entries
    }   //end if

    return ableToRemove;
}   //end remove

template<typename ItemType>
int DoublyLinkedList<ItemType>::getSize() const {
    return itemCount;
}   //end getSize

template<typename ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const {
    DoubleNode<ItemType>* copyPtr = headPtr; 
    return copyPtr; 
}   //end *getHeadPtr

template<typename ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int &pos) const {
    bool ableToGoPos = (pos >= 1) && (pos <= itemCount);

    if(ableToGoPos) { 
        //count from beginning of the chain
        DoubleNode<ItemType>* currPtr = headPtr;

        for(int i = 1; i < pos; i++) { //skip nodes in between
            currPtr = currPtr->getNext();
        }   //end for

        return currPtr;
    }   //end if

}   //end *getAtPos

template<typename ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const {
    if(headPtr == nullptr) {
        return true;
    }
    else {
        return false;
    }   //end if
}   //end isEmpty

template<typename ItemType>
void DoublyLinkedList<ItemType>::clear() {
    while(!isEmpty()) {
        remove(1);
    }   //end while
}   //end clear

template<typename ItemType>
int DoublyLinkedList<ItemType>::getIndexOf(const ItemType &item) const {
    int location = -1;
    
    for(int i = 0; i < itemCount; i++) {
        if(getEntry(i) == item) {
            location = i;
        }   //end if
    }   //end for

    return location;
}   //end getIndexOf

template<typename ItemType>
void DoublyLinkedList<ItemType>::display() const {
    if(isEmpty()) {
        std::cout << std::endl; 
    }   //end if

    for(int i = 1; i <= itemCount; i++) { 
        std::cout << getEntry(i);

        if(i == itemCount) { //only for last place
            std::cout << std::endl; 
        }
        else {
            std::cout << " "; 
        }   //end if
    }   //end for
}   //end getSize

template<typename ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const {
    if(isEmpty()) {
        std::cout << std::endl; 
    }   //end if

    DoubleNode<ItemType>* currPtr = getAtPos(itemCount - 1);
    for(int i = itemCount; i > 0; i--) { 
        std::cout << getEntry(i);

        if(i == 1) { //only for last place
            std::cout << std::endl; 
        }
        else {
            std::cout << " "; 
        }   //end if
    }   //end for  

}   //end getSize

template<typename ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType> &a_list) {
    DoublyLinkedList<ItemType> newList;
    int total_amount = itemCount + a_list.getSize();
    int a_num = 1; //entries of a list in called bag

    for(int i = 1; i <= itemCount; i++) { //copy all from call
        newList.insert(getEntry(i), newList.getSize() + 1);
    }   //end for

    for(int i = 1; i <= total_amount; i++) {
        if(i % 2 == 0 && a_num < newList.getSize() && a_num <= a_list.getSize()) { //if call has more items
            newList.insert(a_list.getEntry(a_num), i);
            a_num++;
        }   //end if

    }   //end for

    if(a_num >= newList.getSize()) {
        a_num--;
        for(int i = a_num; i < a_list.getSize() + 1; i++) { //gets remaining items
            newList.insert(a_list.getEntry(a_num), newList.getSize() + 1);
            a_num++;
        }   //end for
    }   //end if

    return newList;
}   //end interleave

template<typename ItemType>
ItemType DoublyLinkedList<ItemType>::getEntry(int position) const { 
    //Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);

    if(ableToGet) {
        DoubleNode<ItemType>* nodePtr = getAtPos(position);
        return nodePtr->getItem();
    }   //end if 
        
}   //end getEntry

