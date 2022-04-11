#include "LinkedBSearchTree.h"

template <class ItemType>
LinkedBinaryTreeNode<ItemType>* LinkedBSearchTree<ItemType>::placeNode(LinkedBinaryTreeNode<ItemType>* subTreePtr, LinkedBinaryTreeNode<ItemType>* newNodePtr){
    if(subTreePtr == nullptr){
        return newNodePtr;
    } else if(newNodePtr->getItem() < subTreePtr->getItem()){
        subTreePtr->setLeftChildPtr(placeNode(subTreePtr->getLeftChildPtr(), newNodePtr));
    } else{
        subTreePtr->setRightChildPtr(placeNode(subTreePtr->getRightChildPtr(), newNodePtr));
    }
    return subTreePtr;
}

template <class ItemType>
LinkedBinaryTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeValue(LinkedBinaryTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful){
    if(subTreePtr == nullptr){
        isSuccessful = false;
    } else if(subTreePtr->getItem() == target){
        subTreePtr = removeNode(subTreePtr);
        isSuccessful = true;
    } else if(target < subTreePtr->getItem()){
        subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful));
    }else{
        subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful));
    }
    return subTreePtr;
}
    
template <class ItemType>
LinkedBinaryTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeNode(LinkedBinaryTreeNode<ItemType>* nodePtr){
    LinkedBinaryTreeNode<ItemType>* nodeToConnectPtr;
    if(nodePtr->isLeaf()){
        delete nodePtr;
        nodeToConnectPtr = nullptr;
    } else if(nodePtr->getLeftChildPtr() == nullptr){ // can assume that there is only a right child
        nodeToConnectPtr = nodePtr->getRightChildPtr();
        delete nodePtr;
    } else if(nodePtr->getRightChildPtr() == nullptr){ // can assume that there is only a left child
        nodeToConnectPtr = nodePtr->getLeftChildPtr();
        delete nodePtr;
    } else{ // there are two children
        ItemType iOS;
        nodeToConnectPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), iOS);
        nodePtr->setItem(iOS);
    }
    return nodeToConnectPtr;
}

template <class ItemType>
LinkedBinaryTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeLeftmostNode(LinkedBinaryTreeNode<ItemType>* nodePtr, ItemType& inorderSuccessor){
    if(nodePtr->getLeftChildPtr() == nullptr){
        inorderSuccessor = nodePtr->getItem();
        return removeNode(nodePtr);
    } else{
        nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));   
    }
    return nodePtr;
}
        
template <class ItemType>
LinkedBinaryTreeNode<ItemType>* LinkedBSearchTree<ItemType>::findNode(LinkedBinaryTreeNode<ItemType>* treePtr, const ItemType& target) const{
    if(treePtr == nullptr){
        return nullptr;
    }else if(treePtr->getItem() == target){
        return treePtr;
    }else if(treePtr->getItem() > target){
        return findNode(treePtr->getLeftChildPtr(), target);
    }else{
        return findNode(treePtr->getRightChildPtr(), target);
    }
}


template <class ItemType>
LinkedBSearchTree<ItemType>::LinkedBSearchTree() : rootPtr(nullptr), numberOfNodes(0) { }

template <class ItemType>
bool LinkedBSearchTree<ItemType>::isEmpty() const{
    return (rootPtr == nullptr);
}

template <class ItemType>
int LinkedBSearchTree<ItemType>::getHeight(LinkedBinaryTreeNode<ItemType>* ptr) const{
    if(ptr != nullptr){
        int rNodes = 1 + getHeight(ptr->getRightChildPtr());
        int lNodes = 1 + getHeight(ptr->getLeftChildPtr());
        if(rNodes > lNodes){
            return rNodes;
        } else{
            return lNodes;
        }
    }
    return 0;
}

template <class ItemType>
int LinkedBSearchTree<ItemType>::getHeight() const{
    if(rootPtr != nullptr){
        return getHeight(rootPtr);
    }else if(isEmpty()){
        return -1;
    }
    return 0;
}

template <class ItemType>
int LinkedBSearchTree<ItemType>::getNumberOfNodes() const{
    if(rootPtr == nullptr){
        return 0;
    }
    return numberOfNodes;
}

template <class ItemType>
ItemType LinkedBSearchTree<ItemType>::getRootData() const{
    return rootPtr->getItem();
}

template <class ItemType>
LinkedBinaryTreeNode<ItemType>* LinkedBSearchTree<ItemType>::getRootPtr() const{
    return rootPtr;
}

template <class ItemType>
bool LinkedBSearchTree<ItemType>::add(const ItemType& newData){
    if(!contains(newData)){
        LinkedBinaryTreeNode<ItemType>* newNodePtr = new LinkedBinaryTreeNode<ItemType>(newData);
        rootPtr = placeNode(rootPtr, newNodePtr);
        numberOfNodes++; // increases cout of number of nodes
        return true;
    }
    return false;
}

template <class ItemType>
bool LinkedBSearchTree<ItemType>::remove(const ItemType& data){
    bool success = false;
    if(contains(data)){
        rootPtr = removeValue(rootPtr, data, success);
        numberOfNodes--; // decreases count of number of nodes
    }
    return success;
}

template <class ItemType>
void LinkedBSearchTree<ItemType>::clear(){
    while(!isEmpty()){
        remove(getRootData());
    }
}
        
template <class ItemType>
ItemType LinkedBSearchTree<ItemType>::getEntry(const ItemType& anEntry) const{
    LinkedBinaryTreeNode<ItemType>* found = findNode(rootPtr, anEntry);
    if(found != nullptr){
        return found->getItem();
    }
    return ItemType(); // using this instead of throw exception, only runs when item is not a nullptr
}
        
template <class ItemType>
bool LinkedBSearchTree<ItemType>::contains(const ItemType& anEntry) const{
    LinkedBinaryTreeNode<ItemType>* found = findNode(rootPtr, anEntry);
    if(found == nullptr){
        return false;
    }
    return true;
}

template <class ItemType>
void LinkedBSearchTree<ItemType>::preorderTraverse(LinkedBinaryTreeNode<ItemType>* treePtr, void visit(ItemType&)) const{
    ItemType i = treePtr->getItem();
    visit(i);
    if(treePtr->getLeftChildPtr() != nullptr){
        preorderTraverse(treePtr->getLeftChildPtr(), visit);
    }
    if(treePtr->getRightChildPtr() != nullptr){
        preorderTraverse(treePtr->getRightChildPtr(), visit);
    }
}
        
template <class ItemType>
void LinkedBSearchTree<ItemType>::inorderTraverse(LinkedBinaryTreeNode<ItemType>* treePtr, void visit(ItemType&)) const{
    if(treePtr->getLeftChildPtr() != nullptr){
        inorderTraverse(treePtr->getLeftChildPtr(), visit);
    }
    ItemType i = treePtr->getItem();
    visit(i);
    if(treePtr->getRightChildPtr() != nullptr){
        inorderTraverse(treePtr->getRightChildPtr(), visit);
    }
}

template <class ItemType>
void LinkedBSearchTree<ItemType>::postorderTraverse(LinkedBinaryTreeNode<ItemType>* treePtr, void visit(ItemType&)) const{
    if(treePtr->getLeftChildPtr() != nullptr){
        postorderTraverse(treePtr->getLeftChildPtr(), visit);
    }
    if(treePtr->getRightChildPtr() != nullptr){
        postorderTraverse(treePtr->getRightChildPtr(), visit);
    }
    ItemType i = treePtr->getItem();
    visit(i);
}

template <class ItemType>
LinkedBSearchTree<ItemType>::~LinkedBSearchTree(){
    clear();
}