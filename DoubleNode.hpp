/****************************************************************************************************************************
Title       : DoubleNode.hpp
Auhors      : Kelly Camacho
Description : header/interface file of a Node class
****************************************************************************************************************************/

#ifndef DOUBLE_NODE_H_
#define DOUBLE_NODE_H_ 

template<typename ItemType>
class DoubleNode{
    public:
        //Default Cosntructor
        DoubleNode();
        //Parameterized Constructor
        DoubleNode(const ItemType &anItem);

        // Setter Functions
        void setItem(const ItemType &anItem);
        void setPrevious(DoubleNode<ItemType> *previousNodePtr);
        void setNext(DoubleNode<ItemType> *nextNodePtr);

        // Getter Functions
        ItemType getItem() const;
        DoubleNode<ItemType> *getNext() const;
        DoubleNode<ItemType> *getPrevious() const;

    private:
        ItemType item_;
        DoubleNode<ItemType> *next_;    //pointer to next node
        DoubleNode<ItemType> *prev_;    //pointer to previous node
};

#include "DoubleNode.cpp"
#endif //DOUBLE_NODE_H_
