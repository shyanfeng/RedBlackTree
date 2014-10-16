#include <stdio.h>
#include "RedBlackTree.h"
#include "Rotations.h"
#include "ErrorCode.h"
#include "CException.h"


void _addRedBlackTree(Node **rootPtr, Node *newNode){
	Node *root = *rootPtr;
	
	if((*rootPtr) == NULL){
		*rootPtr = newNode;
		(*rootPtr)->color = 'r';
		return;
	}else if((*rootPtr) == newNode){
		Throw(ERR_EQUIVALENT_NODE);
	}
	
	if(newNode->data < (*rootPtr)->data){
		_addRedBlackTree(&(*rootPtr)->left, newNode);
	}else if(newNode->data > (*rootPtr)->data){
		_addRedBlackTree(&(*rootPtr)->right, newNode);
	} 
		
	if((*rootPtr)->left != NULL && (*rootPtr)->left->left != NULL){
		if((*rootPtr)->left->color == 'r' && (*rootPtr)->left->left->color == 'r'){
			rightRotate(rootPtr);
			(*rootPtr)->right->color = 'r';
		}
	}
	
	if((*rootPtr)->right != NULL && (*rootPtr)->right->right != NULL){
		if((*rootPtr)->right->color == 'r' && (*rootPtr)->right->right->color == 'r'){
			leftRotate(rootPtr);
			(*rootPtr)->left->color = 'r';
		}
	}
}

void addRedBlackTree(Node **rootPtr, Node *newNode){
	_addRedBlackTree(rootPtr, newNode);
	(*rootPtr)->color = 'b';
	
}

