#ifndef RedBlackTree_H
#define RedBlackTree_H

#include "Node.h"

void addRedBlackTree(Node **rootPtr, Node *newNode);
void _addRedBlackTree(Node **rootPtr, Node *newNode);
Node *delRedBlackTree(Node **rootPtr, Node *delNode);
Node *_delRedBlackTree(Node **rootPtr, Node *delNode);

void isLeftCase1(Node **rootPtr);
void isLeftCase2(Node **rootPtr);
void isLeftCase3(Node **rootPtr);

void isRightCase1(Node **rootPtr);
void isRightCase2(Node **rootPtr);
void isRightCase3(Node **rootPtr);

int isRed(Node **rootPtr);
int isBlack(Node **rootPtr);
int isDoubleBlack(Node **rootPtr);
#endif // RedBlackTree_H
