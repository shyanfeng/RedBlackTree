#include <stdio.h>
#include "Rotations.h"
#include "Node.h"

void rightRotate(Node **nodePtr){
  Node *newNode = (*nodePtr)->left;
  Node *storeNode = newNode->right;
    
  newNode->right = *nodePtr;
  newNode->right->left = storeNode;
  *nodePtr = newNode;
}

void leftRotate(Node **nodePtr){
  Node *newNode = (*nodePtr)->right;
  Node *storeNode = newNode->left;
    
  newNode->left = NULL;
  newNode->left = *nodePtr;
  newNode->left->right = storeNode;
  *nodePtr = newNode;
}

void leftRightRotate(Node **nodePtr){
  leftRotate(&(*nodePtr)->left);
  rightRotate(*(&nodePtr));
}

void rightLeftRotate(Node **nodePtr){
  rightRotate(&(*nodePtr)->right);
  leftRotate(*(&nodePtr));
}