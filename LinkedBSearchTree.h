#ifndef LINKED_BSEARCHTREE
#define LINKED_BSEARCHTREE

#include "LinkedBinaryTreeNode.h"
#include "TreeInterface.h"

template<class ItemType>
class LinkedBSearchTree: public TreeInterface<ItemType> {
    private:
        LinkedBinaryTreeNode<ItemType>* rootPtr;
        int height;
        int numberOfNodes;
        
    protected:
        LinkedBinaryTreeNode<ItemType>* placeNode(LinkedBinaryTreeNode<ItemType>* subTreePtr, LinkedBinaryTreeNode<ItemType>* newNodePtr);
        LinkedBinaryTreeNode<ItemType>* removeValue(LinkedBinaryTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful);
        LinkedBinaryTreeNode<ItemType>* removeNode(LinkedBinaryTreeNode<ItemType>* nodePtr);
        LinkedBinaryTreeNode<ItemType>* removeLeftmostNode(LinkedBinaryTreeNode<ItemType>* nodePtr, LinkedBinaryTreeNode<ItemType>* inorderSuccessor);
        LinkedBinaryTreeNode<ItemType>* findNode(LinkedBinaryTreeNode<ItemType>* treePtr, const ItemType& target) const;

    public:
        LinkedBSearchTree();
        bool isEmpty() const;
        int getHeight() const;
        int getNumberOfNodes() const;
        ItemType getRootData() const;
        bool add(const ItemType& newData);
        bool remove(const ItemType& data);
        void clear();
        ItemType getEntry(const ItemType& anEntry) const;
        bool contains(const ItemType& anEntry) const;
        void preorderTraverse(LinkedBinaryTreeNode<ItemType>* treePtr, void visit(ItemType&)) const;
        void inorderTraverse(LinkedBinaryTreeNode<ItemType>* treePtr, void visit(ItemType&)) const;
        void postorderTraverse(LinkedBinaryTreeNode<ItemType>* treePtr, void visit(ItemType&)) const;
        ~LinkedBSearchTree() { }
};

#include "LinkedBSearchTree.cpp"
#endif