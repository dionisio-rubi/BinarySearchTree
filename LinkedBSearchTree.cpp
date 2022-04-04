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
    }
    if(subTreePtr->getItem() == target){
        isSuccessful = true;
        if(subTreePtr->isLeaf()){
            return nullptr;
        } else if(subTreePtr->getLeftChildPtr() == nullptr){
            return subTreePtr->getRightChildPtr();
        } else if(subTreePtr->getRightChildPtr() == nullptr){
            return subTreePtr->getLeftChildPtr();
        } else{
            ItemType newRootItem = inorderSuccessor(subTreePtr->getRightChildPtr());
            subTreePtr->setItem(newRootItem);
            subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), newRootItem, isSuccessful));
        }
    } else if(target < subTreePtr->getItem()){
        subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful));
    } else{
        subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful));
    }
    return subTreePtr;
}
    
template <class ItemType>
LinkedBinaryTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeNode(LinkedBinaryTreeNode<ItemType>* nodePtr){
    
}

template <class ItemType>
LinkedBinaryTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeLeftmostNode(LinkedBinaryTreeNode<ItemType>* nodePtr, LinkedBinaryTreeNode<ItemType>* inorderSuccessor){
    if(node->getLeftChildPtr() == nullptr){
        inorderSuccessor = nodePtr->getItem();
        return removeNode(nodePtr);
    } else{
        nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
        return nodePtr;
    }
}
        
template <class ItemType>
LinkedBinaryTreeNode<ItemType>* LinkedBSearchTree<ItemType>::findNode(LinkedBinaryTreeNode<ItemType>* treePtr, const ItemType& target) const{

}


template <class ItemType>
LinkedBSearchTree<ItemType>::LinkedBSearchTree() : rootPtr(nullptr) { }

template <class ItemType>
bool LinkedBSearchTree<ItemType>::isEmpty() const{
    return (rootPtr == nullptr);
}

template <class ItemType>
int LinkedBSearchTree<ItemType>::getHeight() const{

}

template <class ItemType>
int LinkedBSearchTree<ItemType>::getNumberOfNodes() const{

}

template <class ItemType>
ItemType LinkedBSearchTree<ItemType>::getRootData() const{
    return rootPtr->getItem();
}

template <class ItemType>
bool LinkedBSearchTree<ItemType>::add(const ItemType& newData){
    LinkedBinaryTreeNode<ItemType>* newNodePtr(newData);
    rootPtr = placeNode(rootPtr, newNodePtr);
    return true;
}

template <class ItemType>
bool LinkedBSearchTree<ItemType>::remove(const ItemType& data){
    LinkedBinaryTreeNode<ItemType>* newNodePtr(data);
    bool success = false;
    rootPtr = removeValue(rootPtr, data, success);
    return success;
}

template <class ItemType>
void LinkedBSearchTree<ItemType>::clear(){

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
void LinkedBSearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const{

}
        
template <class ItemType>
void LinkedBSearchTree<ItemType>::inorderTraverse(LinkedBinaryTreeNode<ItemType>* treePtr, void visit(ItemType&)) const{
    if(treePtr != nullptr){
        inorderTraverse(treePtr->getLeftChildPtr(), visit);
        visit(treePtr->getItem());
        inorderTraverse(treePtr->getRightChildPtr(), visit);
    }
}
        
template <class ItemType>
void LinkedBSearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const{

}