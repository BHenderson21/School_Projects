//
// Created by Brandon on 3/26/2023.
//

#ifndef CSC315PROGRAMMINGASSIGNMENT2_MAIN_H
#define CSC315PROGRAMMINGASSIGNMENT2_MAIN_H
using namespace std;

struct node{
    int value;
    node* leftPtr;
    node* rightPtr;
    node* parent;
};

class AVL{
public:
    int height(node *root);
    int getBalance(node *root);
    node *rightRotate(node *x);
    node *leftRotate(node *x);
    node *insertNode(node *root, int data);
    node *getMinimumKey(node* curr);
    node *deleteNode(node *root, int key);
    void deleteTree(node *root);
    void dotPrint(node *root, char *filename);

private:
    node* headptr;
};

#endif //CSC315PROGRAMMINGASSIGNMENT2_MAIN_H
