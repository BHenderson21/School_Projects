#include <iostream>
#include <cmath>
#include "main.h"

int main()
{
    return 0;
}

int height(node *root)
{
    if((root->leftPtr == nullptr && root->rightPtr == nullptr))
        return 0;
    if(height(root->leftPtr) >= height(root->rightPtr))
        return (height(root->leftPtr) + 1);
    return (height(root->rightPtr) + 1);
}

int getBalance(node *root)
{
    return fabs(height(root->leftPtr) - height(root->rightPtr));
}

node *rightRotate(node *x)
{
    node* small = x;
    node* temp = small->rightPtr;
    node* mid;
    node* large;
    if(height(temp->rightPtr) < height(temp->leftPtr))           // Right-Left
    {
        mid = temp->leftPtr;
        large = temp;

        temp = mid;
        mid->leftPtr = small;
        mid->rightPtr = large;
    }
    else                                    // Right-Right
    {
        mid = temp;
        large = mid->rightPtr;

        temp = small;
        small->rightPtr = mid->leftPtr;
        mid->leftPtr = temp;
    }
    return mid;
}

node *leftRotate(node *x)
{
    node* large = x;
    node* temp = large->leftPtr;
    node* mid;
    node* small;
    if(height(temp->leftPtr) < height(temp->rightPtr))           // Left-Right
    {
        mid = temp->rightPtr;
        small = temp;

        temp = mid;
        mid->leftPtr = small;
        mid->rightPtr = large;
    }
    else                                    // Left-Left
    {
        mid = temp;
        small = mid->leftPtr;

        temp = mid->rightPtr;
        mid->rightPtr = large;
        large->leftPtr = temp;
    }
    return mid;
}

node *insertNode(node *root, int data)
{
    if (root == nullptr)
    {
        node* newNode = new node;
        newNode->value = data;
        return newNode;
    }

    if (root->value >= data)
        root->leftPtr = insertNode(root->leftPtr, data);
    else
        root->rightPtr = insertNode(root->rightPtr, data);

    return root;
}

node *getMinimumKey(node* curr)
{

}


