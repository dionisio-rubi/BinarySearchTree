#ifndef LINKED_BINARYTREE_NODE
#define LINKED_BINARYTREE_NODE

template <class ItemType>
class LinkedBinaryTreeNode {
    private:
        ItemType item;
        LinkedBinaryTreeNode<ItemType>* leftChildPtr;
        LinkedBinaryTreeNode<ItemType>* rightChildPtr;
    public:
        LinkedBinaryTreeNode();
        LinkedBinaryTreeNode(const ItemType& newData, LinkedBinaryTreeNode<ItemType>* left, LinkedBinaryTreeNode<ItemType>* right);
        LinkedBinaryTreeNode(const ItemType& newData);
        void setItem(const ItemType& newData);
        ItemType getItem() const;
        bool isLeaf() const;
        LinkedBinaryTreeNode<ItemType>* getLeftChildPtr() const;
        LinkedBinaryTreeNode<ItemType>* getRightChildPtr() const;
        void setLeftChildPtr(LinkedBinaryTreeNode<ItemType>* newLeftChildPtr);
        void setRightChildPtr(LinkedBinaryTreeNode<ItemType>* newRightChildPtr);
};

#include "LinkedBinaryTreeNode.cpp"
#endif