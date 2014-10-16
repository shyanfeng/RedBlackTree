#include <stdio.h>
#include "RedBlackTree.h"
#include "ErrorCode.h"


void _addRedBlackTree(Node **rootPtr, Node *newNode){
	int e;
	
	if(*rootPtr == NULL){
		*rootPtr = newNode;
		(*rootPtr)->color = 'r';
	}else if(*rootPtr == newNode){
		Throw(e);
	}else if(*rootPtr > newNode){
		(*rootPtr)->left = newNode;
		(*rootPtr)->left->color = 'r';
	}else if(*rootPtr < newNode){
		(*rootPtr)->right = newNode;
		(*rootPtr)->right->color = 'r';
	}
}

void addRedBlackTree(Node **rootPtr, Node *newNode){
	_addRedBlackTree(rootPtr, newNode);
	(*rootPtr)->color = 'b';
	
}

