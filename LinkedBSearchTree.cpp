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
        return nullptr;
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
    if(nodePtr->isLeaf()){
        delete nodePtr;
        nodePtr = nullptr;
    } else if(nodePtr->getLeftChildPtr() == nullptr){
        LinkedBinaryTreeNode<ItemType>* nodeToConnectPtr = nodePtr->getRightChildPtr();
        delete nodePtr;
        nodePtr = nodeToConnectPtr;
    } else if(nodePtr->getRightChildPtr() == nullptr){
        LinkedBinaryTreeNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftChildPtr();
        delete nodePtr;
        nodePtr = nodeToConnectPtr;
    } else{
        LinkedBinaryTreeNode<ItemType>* inorderSuccessorPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), nodePtr);
        nodePtr->setRightChildPtr(inorderSuccessorPtr);
        nodePtr->setItem(inorderSuccessorPtr->getItem());
    }
    return nodePtr;
}

template <class ItemType>
LinkedBinaryTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeLeftmostNode(LinkedBinaryTreeNode<ItemType>* nodePtr, LinkedBinaryTreeNode<ItemType>* inorderSuccessor){
    if(nodePtr->getLeftChildPtr() == nullptr){
        inorderSuccessor = nodePtr->getItem();
        return removeNode(nodePtr);
    } else{
        nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
        return nodePtr;
    }
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
LinkedBSearchTree<ItemType>::LinkedBSearchTree() : rootPtr(nullptr), height(0) { }

template <class ItemType>
bool LinkedBSearchTree<ItemType>::isEmpty() const{
    return (rootPtr == nullptr);
}

template <class ItemType>
int LinkedBSearchTree<ItemType>::getHeight() const{
    return height;
}

template <class ItemType>
int LinkedBSearchTree<ItemType>::getNumberOfNodes() const{
    return numberOfNodes;
}

template <class ItemType>
ItemType LinkedBSearchTree<ItemType>::getRootData() const{
    return rootPtr->getItem();
}

template <class ItemType>
bool LinkedBSearchTree<ItemType>::add(const ItemType& newData){
    LinkedBinaryTreeNode<ItemType>* newNodePtr(newData);
    rootPtr = placeNode(rootPtr, newNodePtr);
    numberOfNodes++;
    return true;
}

template <class ItemType>
bool LinkedBSearchTree<ItemType>::remove(const ItemType& data){
    bool success = false;
    rootPtr = removeValue(rootPtr, data, success);
    if(success){
        numberOfNodes--;
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
    } else{
        throw "Item not found";
    }
}
        
template <class ItemType>
bool LinkedBSearchTree<ItemType>::contains(const ItemType& anEntry) const{
    LinkedBinaryTreeNode<ItemType>* found = findNode(rootPtr, anEntry);
    if(found != nullptr){
        return true;
    } else{
        return false;
    }
}

template <class ItemType>
void LinkedBSearchTree<ItemType>::preorderTraverse(LinkedBinaryTreeNode<ItemType>* treePtr, void visit(ItemType&)) const{
    visit(treePtr->getItem());
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
    visit(treePtr->getItem());
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
    visit(treePtr->getItem());
}