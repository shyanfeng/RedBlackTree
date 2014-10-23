#include <stdio.h>
#include "RedBlackTree.h"
#include "Rotations.h"
#include "ErrorCode.h"
#include "CException.h"

void _addRedBlackTree(Node **rootPtr, Node *newNode);
Node *_delRedBlackTree(Node **rootPtr, Node *newNode);

void addRedBlackTree(Node **rootPtr, Node *newNode){
	_addRedBlackTree(rootPtr, newNode);
	(*rootPtr)->color = 'b';
}	

void _addRedBlackTree(Node **rootPtr, Node *newNode){

	if((*rootPtr) == NULL){
		*rootPtr = newNode;
		(*rootPtr)->color = 'r';
		return;
	}else if((*rootPtr) == newNode){
		Throw(ERR_EQUIVALENT_NODE);
	}

  if((*rootPtr)->left != NULL && (*rootPtr)->right != NULL){
    if((*rootPtr)->left->color == 'r' && (*rootPtr)->right->color == 'r'){
      printf("aaa");
      (*rootPtr)->color = 'r';
      (*rootPtr)->left->color = 'b';
      (*rootPtr)->right->color = 'b';
    }
  }
  
	if(newNode->data < (*rootPtr)->data){
		_addRedBlackTree(&(*rootPtr)->left, newNode);
	}else if(newNode->data > (*rootPtr)->data){
		_addRedBlackTree(&(*rootPtr)->right, newNode);
	}
  
  if(((*rootPtr)->left != NULL && (*rootPtr)->left->left != NULL)){
		if((*rootPtr)->left->color == 'r' && (*rootPtr)->left->left->color == 'r'){
      rightRotate(rootPtr);
			(*rootPtr)->right->color = 'r';
		}
	}else if((*rootPtr)->right != NULL && (*rootPtr)->right->right != NULL){
		if((*rootPtr)->right->color == 'r' && (*rootPtr)->right->right->color == 'r'){
      leftRotate(rootPtr);
			(*rootPtr)->left->color = 'r';
		}
	}else if((*rootPtr)->left != NULL && (*rootPtr)->left->right != NULL){
		if((*rootPtr)->left->color == 'r' && (*rootPtr)->left->right->color == 'r'){
      leftRightRotate(rootPtr);
			(*rootPtr)->right->color = 'r';
		}
	}else if((*rootPtr)->right != NULL && (*rootPtr)->right->left != NULL){
		if((*rootPtr)->right->color == 'r' && (*rootPtr)->right->left->color == 'r'){
      rightLeftRotate(rootPtr);
			(*rootPtr)->left->color = 'r';
		}
	}
}

Node *delRedBlackTree(Node **rootPtr, Node *newNode){
  _delRedBlackTree(rootPtr, newNode);
  (*rootPtr)->color = 'b';
}

Node *_delRedBlackTree(Node **rootPtr, Node *newNode){
  Node *node;
  
  node = _delRedBlackTree(rootPtr, newNode);
  
  return node;
}


