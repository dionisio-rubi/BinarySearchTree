//created by Rubi Dionisi0

#include <iostream>
#include <fstream>
#include "LinkedBSearchTree.h"


void print(int& item);

int main(){
    LinkedBSearchTree<int> tree;
    int nums[100];
    // tree.add(4);
    // tree.add(24);
    // tree.add(2);
    // tree.add(1);
    // tree.add(3);
    // tree.add(6);

    std::ofstream treeFile;
    treeFile.open("treeFile.txt", std::ios::app);
    if(treeFile){ 
        std::cout << "Data:" << std::endl;
        treeFile << "Data:" << std::endl;
        for(int i = 0; i < 100; i++){
            nums[i] = 1 + (rand() % 200);
            tree.add(nums[i]);
            std::cout << nums[i] << " ";
            treeFile << nums[i] << " ";
        }
        std::cout << "Height: " << tree.getHeight() << std::endl;
        std::cout << "Number of Nodes: " << tree.getNumberOfNodes() << std::endl;
        std::cout << "Root Data: " << tree.getRootData() << std::endl;

        treeFile << std::endl << "\nHeight: " << tree.getHeight() << std::endl;
        treeFile << "Number of Nodes: " << tree.getNumberOfNodes() << std::endl;
        treeFile << "Root Data: " << tree.getRootData() << std::endl;
        
        //preorder
        std::cout << "Preorder: " << std::endl;
        treeFile << "\nPreorder: " << std::endl;
        tree.preorderTraverse(tree.getRootPtr(), print);

        //inorder
        std::cout << std::endl << "Inorder: " << std::endl;
        treeFile << std::endl << "\nInorder: " << std::endl;
        tree.inorderTraverse(tree.getRootPtr(), print);

        //postorder
        std::cout << std::endl << "Postorder: " << std::endl;
        treeFile << std::endl << "\nPostorder: " << std::endl;
        tree.postorderTraverse(tree.getRootPtr(), print);
        std::cout << std::endl;
        treeFile << std::endl;
    }
    treeFile.close();
    tree.clear();
    return 0;
};

void print(int& item){
    std::ofstream treeFile;
    treeFile.open("treeFile.txt", std::ios::app);
    std::cout << item << " ";
    treeFile << item << " ";
    treeFile.close();
}