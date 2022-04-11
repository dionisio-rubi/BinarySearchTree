//created by Rubi Dionisi0

#include <iostream>
#include "LinkedBSearchTree.h"

int main(){
    LinkedBSearchTree<int> tree;
    int postOrder[100];
    int preOrder[100];
    int inOrder[100];
    int nums[100];
    tree.add(4);
    tree.add(24);
    tree.add(2);

    // std::cout << "Data:" << std::endl;
    // for(int i = 0; i < 100; i++){
    //     nums[i] = 1 + (rand() % 200);
    //     tree->add(nums[i]);
    //     if(i == 99){
    //         std::cout << nums[i] << std::endl;
    //     }else
    //     std::cout << nums[i] << ", ";
    // }

    std::cout << "Height: " << tree.getHeight() << std::endl;
    // std::cout << "Number of Nodes: " << tree->getNumberOfNodes() << std::endl;

    //preorder
    std::cout << "Preorder: " << std::endl;
    // tree->preorderTraverse(tree->getRootPtr(), preOrder);

    //inorder

    //postorder

    // tree->clear();
    return 0;
};