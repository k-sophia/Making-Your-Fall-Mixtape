/****************************************************************************************************************************
Title        : DoubleNode.hpp
Auhors       : Kelly Camacho
Description  : partial implementation file of a Node class
Dependencies : DoubleNode.hpp
****************************************************************************************************************************/

#include "DoubleNode.hpp"

/* Constructor */
template<typename ItemType>
DoubleNode<ItemType>::DoubleNode() : next_(nullptr)
{

}   // end of default constructor

template<typename ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType &anItem) : item_(anItem), next_(nullptr)
{

}   // end of constructor

template<typename ItemType>
void DoubleNode<ItemType>::setItem(const ItemType &anItem) {

    item_ = anItem;
} // end setItem

template<class ItemType>
void DoubleNode<ItemType>::setPrevious(DoubleNode<ItemType> *previousNodePtr) {
    prev_ = previousNodePtr;
}   // end setPrevious 

template<class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType> *nextNodePtr) {
    next_ = nextNodePtr;
}   // end setNext 

template<typename ItemType>
ItemType DoubleNode<ItemType>::getItem() const {
    return item_;
}   // end getItem

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const {
    return next_;
}   // end getNext

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrevious() const {
    return prev_;
}   // end getPrevious
 
