#ifndef RedBlackTree_H
#define RedBlackTree_H

#include "Node.h"

void addRedBlackTree(Node **rootPtr, Node *newNode);
void _addRedBlackTree(Node **rootPtr, Node *newNode);
Node *delRedBlackTree(Node **rootPtr, Node *delNode);
Node *_delRedBlackTree(Node **rootPtr, Node *delNode);

Node *removeNextLargerSuccessor(Node **parentPtr);

void isLeftCase1(Node **rootPtr);
void isLeftCase2(Node **rootPtr, Node *removeNode);
void isLeftCase3(Node **rootPtr, Node *removeNode);

void isRightCase1(Node **rootPtr);
void isRightCase2(Node **rootPtr, Node *removeNode);
void isRightCase3(Node **rootPtr, Node *removeNode);

int isRed(Node **rootPtr);
int isBlack(Node **rootPtr);
int isDoubleBlack(Node **rootPtr, Node *removeNode);
#endif // RedBlackTree_H
