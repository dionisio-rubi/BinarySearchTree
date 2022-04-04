#include "LinkedBinaryTreeNode.h"

template <class ItemType>
LinkedBinaryTreeNode<ItemType>::LinkedBinaryTreeNode() : leftChildPtr(nullptr), rightChildPtr(nullptr){ }

template <class ItemType>
LinkedBinaryTreeNode<ItemType>::LinkedBinaryTreeNode(const ItemType& newData, LinkedBinaryTreeNode<ItemType>* left, LinkedBinaryTreeNode<ItemType>* right) :
item(newData), leftChildPtr(left), rightChildPtr(right){ }
        
template <class ItemType>
void LinkedBinaryTreeNode<ItemType>::setItem(const ItemType& newData){
    item = newData;
}

template <class ItemType>
ItemType LinkedBinaryTreeNode<ItemType>::getItem() const{
    return item;
}

template <class ItemType>
bool LinkedBinaryTreeNode<ItemType>::isLeaf() const{
    return (leftChildPtr == nullptr && rightChildPtr == nullptr);
}

template <class ItemType>
LinkedBinaryTreeNode<ItemType>* LinkedBinaryTreeNode<ItemType>::getLeftChildPtr() const{
    return leftChildPtr;
}
        
template <class ItemType>
LinkedBinaryTreeNode<ItemType>* LinkedBinaryTreeNode<ItemType>::getRightChildPtr() const{
    return rightChildPtr;
}

template <class ItemType>
void LinkedBinaryTreeNode<ItemType>::setLeftChildPtr(LinkedBinaryTreeNode<ItemType>* newLeftChildPtr){
    leftChildPtr = newLeftChildPtr;
}

template <class ItemType>
void LinkedBinaryTreeNode<ItemType>::setRightChildPtr(LinkedBinaryTreeNode<ItemType>* newRightChildPtr){
    rightChildPtr = newRightChildPtr;
}