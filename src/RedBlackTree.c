#include <stdio.h>
#include "RedBlackTree.h"
#include "Rotations.h"
#include "ErrorCode.h"
#include "CException.h"

void _addRedBlackTree(Node **rootPtr, Node *newNode);
Node *_delRedBlackTree(Node **rootPtr, Node *newNode);

void _addRedBlackTree(Node **rootPtr, Node *newNode){
		
		if(*rootPtr == NULL){
			*rootPtr = newNode;
			(*rootPtr)->color = 'r';
			return;
		}
        
  if((*rootPtr)->left != NULL && (*rootPtr)->right != NULL){
    if((*rootPtr)->left->color == 'r' && (*rootPtr)->right->color == 'r'){  
      (*rootPtr)->color = 'r';
      (*rootPtr)->left->color = 'b';
      (*rootPtr)->right->color = 'b';
     }
  }

  if((*rootPtr)->data > newNode->data){
		_addRedBlackTree(&(*rootPtr)->left, newNode);	
	}else if((*rootPtr)->data < newNode->data){
		_addRedBlackTree(&(*rootPtr)->right, newNode);	
	}else{
		Throw(ERR_EQUIVALENT_NODE);
	}

  if((*rootPtr)->left != NULL && (*rootPtr)->left->left != NULL){
    if((*rootPtr)->left->color == 'r' && (*rootPtr)->left->left->color == 'r'){
      rightRotate(rootPtr);
      (*rootPtr)->right->color = 'r'; 
    }
  }else if((*rootPtr)->left != NULL && (*rootPtr)->left->right != NULL){
    if((*rootPtr)->left->color == 'r' && (*rootPtr)->left->right->color == 'r'){
      leftRightRotate(rootPtr);
      (*rootPtr)->right->color = 'r';
    }
  }else if((*rootPtr)->right != NULL && (*rootPtr)->right->right != NULL){
    if((*rootPtr)->right->color == 'r' && (*rootPtr)->right->right->color == 'r'){
      leftRotate(rootPtr);
      (*rootPtr)->left->color = 'r';
    }
  }else if((*rootPtr)->right != NULL && (*rootPtr)->right->left != NULL){
    if((*rootPtr)->right->color == 'r' && (*rootPtr)->right->left->color == 'r'){
      rightLeftRotate(rootPtr);
      (*rootPtr)->left->color = 'r';
    }
  }
  
  if((*rootPtr)->right != NULL && (*rootPtr)->right->left != NULL){
    if((*rootPtr)->right->color == 'r' && (*rootPtr)->right->left->color == 'r'){
      (*rootPtr)->right->left->color = 'b';
      (*rootPtr)->right->right->color = 'b';
    }
  }
}

void addRedBlackTree(Node **rootPtr,Node *newNode){
		_addRedBlackTree(rootPtr,newNode);
      (*rootPtr)->color = 'b';	
}

Node *delRedBlackTree(Node **rootPtr, Node *delNode){
  Node *node;
  node = _delRedBlackTree(rootPtr, delNode);
  
  if(*rootPtr != NULL){
    (*rootPtr)->color = 'b';
  }
  return node;
}

Node *_delRedBlackTree(Node **rootPtr, Node *delNode){
  Node *node, *rightTemp, *leftTemp, *temp, *removeSuccessor, tempSuccessor;
  char tempColor;
  
  if((*rootPtr) == NULL){
    Throw(ERR_NODE_UNAVAILABLE);
  }else if((*rootPtr)->data == delNode->data){
    if((*rootPtr)->right != NULL){
      node = *rootPtr;
      removeSuccessor = removeNextLargerSuccessor(&(*rootPtr)->right);
      tempSuccessor = *removeSuccessor;
      leftTemp = (*rootPtr)->left;
      rightTemp = (*rootPtr)->right;
      tempColor = (*rootPtr)->color;
      (*rootPtr) = removeSuccessor;
      (*rootPtr)->left = leftTemp;
      (*rootPtr)->right = rightTemp;
      (*rootPtr)->color = tempColor;
      restructureRedBlackTree(rootPtr, &tempSuccessor);
    }else if((*rootPtr)->left != NULL){
      removeSuccessor = removeNextLargerSuccessor(&(*rootPtr)->left);
      tempSuccessor = *removeSuccessor;
      leftTemp = (*rootPtr)->left;
      rightTemp = (*rootPtr)->right;
      tempColor = (*rootPtr)->color;
      (*rootPtr) = removeSuccessor;
      (*rootPtr)->left = leftTemp;
      (*rootPtr)->right = rightTemp;
      (*rootPtr)->color = tempColor;
      restructureRedBlackTree(rootPtr, &tempSuccessor);
    }else{
      (*rootPtr) = NULL;
    }
    return node;
  }else if((*rootPtr)->data > delNode->data){
    node = _delRedBlackTree(&(*rootPtr)->left, delNode);
  }else if((*rootPtr)->data < delNode->data){
    node = _delRedBlackTree(&(*rootPtr)->right, delNode);
  }

  restructureRedBlackTree(rootPtr, delNode);
  
  return node;
}

Node *removeNextLargerSuccessor(Node **parentPtr){
  Node *removeNode;
 
  if((*parentPtr)->left != NULL){
    removeNode = removeNextLargerSuccessor(&(*parentPtr)->left);
  }else if((*parentPtr)->right == NULL){
    removeNode = (*parentPtr);
    (*parentPtr) = NULL;
    return removeNode;
  }else if((*parentPtr)->right != NULL){
    removeNode = (*parentPtr);
    (*parentPtr)->right->color = 'b';
    (*parentPtr) = (*parentPtr)->right;
    
    return removeNode;
  }
  
  restructureRedBlackTree(parentPtr, removeNode);
  
  return removeNode;
}

void restructureRedBlackTree(Node **parentPtr, Node *removeNode){
  //LeftCase
  if(isDoubleBlack((&(*parentPtr)->left), removeNode)){
    if(isRed(&(*parentPtr)->right->left) || isRed(&(*parentPtr)->right->right)){
      isLeftCase1(parentPtr);
    }else if(isBlack(&(*parentPtr)->right) && isBlack(&(*parentPtr)->right->left) && 
    isBlack(&(*parentPtr)->right->right)){
      isLeftCase2(parentPtr, removeNode);
    }else if(isRed(&(*parentPtr)->right)){
      isLeftCase3(parentPtr, removeNode);
      if((*parentPtr)->left->left != NULL && (*parentPtr)->left->left->color == 'd'){
      (*parentPtr)->left->left->color = 'b';
  }
    }
  }
  
  //RightCase
  if(isDoubleBlack((&(*parentPtr)->right), removeNode)){
    if(isRed(&(*parentPtr)->left->right) || isRed(&(*parentPtr)->left->left)){
      isRightCase1(parentPtr);
    }else if(isBlack(&(*parentPtr)->left) && isBlack(&(*parentPtr)->left->right) && 
      isBlack(&(*parentPtr)->left->left)){
      isRightCase2(parentPtr, removeNode);
    }else if(isRed(&(*parentPtr)->left)){
      isRightCase3(parentPtr, removeNode);
      if((*parentPtr)->right->right != NULL && (*parentPtr)->right->right->color == 'd'){
    (*parentPtr)->right->right->color = 'b';
  }
    }
  }
}

void isLeftCase3(Node **rootPtr, Node *removeNode){
  if(isRed(&(*rootPtr)->right)){
    (*rootPtr)->right->color = (*rootPtr)->color;
    (*rootPtr)->color = 'r';
    removeNode->color = 'b';
    leftRotate(rootPtr);
  }
  
  if(isDoubleBlack(&(*rootPtr)->left->left, removeNode) && isBlack(&(*rootPtr)->left->right)){
    if(isBlack(&(*rootPtr)->left->right->right) &&isBlack(&(*rootPtr)->left->right->left))
    isLeftCase2(&(*rootPtr)->left, removeNode);
    else if(isRed(&(*rootPtr)->left->right->right) || isRed(&(*rootPtr)->left->right->left))
    isLeftCase1(&(*rootPtr)->left);
  }
  

}

void isLeftCase2(Node **rootPtr, Node *removeNode){
  if(isBlack(&(*rootPtr)) && isBlack(&(*rootPtr)->right)){
    (*rootPtr)->color = 'd';
    if(isDoubleBlack(&(*rootPtr)->left, removeNode) && (*rootPtr)->left != NULL){
      (*rootPtr)->left->color = 'b';
    }
  }else if(isRed(&(*rootPtr))){
    (*rootPtr)->color = 'b';
  }
  if((*rootPtr)->right != NULL){
      (*rootPtr)->right->color = 'r';
  }
}

void isLeftCase1(Node **rootPtr){
  if(isRed(&(*rootPtr)->right->right)){
    (*rootPtr)->right->color = (*rootPtr)->color;
    leftRotate(rootPtr);
  }else if(isRed(&(*rootPtr)->right->left)){
    (*rootPtr)->right->left->color = (*rootPtr)->color;
    rightLeftRotate(rootPtr);
  }
  (*rootPtr)->left->color = 'b';
  (*rootPtr)->right->color = 'b';
}

void isRightCase3(Node **rootPtr, Node *removeNode){
  if(isRed(&(*rootPtr)->left)){
    (*rootPtr)->left->color = (*rootPtr)->color;
    (*rootPtr)->color = 'r';
    removeNode->color = 'b';
    rightRotate(rootPtr);
  }
  
  if(isDoubleBlack(&(*rootPtr)->right->right, removeNode) && isBlack(&(*rootPtr)->right->left)){
    if(isBlack(&(*rootPtr)->right->left->left) &&isBlack(&(*rootPtr)->right->left->right))
    isRightCase2(&(*rootPtr)->right, removeNode);
    else if(isRed(&(*rootPtr)->right->left->left) || isRed(&(*rootPtr)->right->left->right))
    isRightCase1(&(*rootPtr)->right);
  }
  

}

void isRightCase2(Node **rootPtr, Node *removeNode){
  if(isBlack(&(*rootPtr)) && isBlack(&(*rootPtr)->left)){
    (*rootPtr)->color = 'd';
    if(isDoubleBlack(&(*rootPtr)->right, removeNode) && (*rootPtr)->right != NULL){
      (*rootPtr)->right->color = 'b';
    }
  }else if(isRed(&(*rootPtr))){
    (*rootPtr)->color = 'b';
  }
  
  if((*rootPtr)->left != NULL){
      (*rootPtr)->left->color = 'r';
  }
}

void isRightCase1(Node **rootPtr){
  if(isRed(&(*rootPtr)->left->left)){
    (*rootPtr)->left->color = (*rootPtr)->color;
    rightRotate(rootPtr);
  }else if(isRed(&(*rootPtr)->left->right)){
    (*rootPtr)->left->color = (*rootPtr)->color;
    leftRightRotate(rootPtr);
  }
  (*rootPtr)->left->color = 'b';
  (*rootPtr)->right->color = 'b';
}

int isRed(Node **rootPtr){
  if((*rootPtr) != NULL && (*rootPtr)->color == 'r')
    return 1;
  else
    return 0;
}

int isBlack(Node **rootPtr){
  if((*rootPtr == NULL))
    return 1;
  else if((*rootPtr) != NULL && (*rootPtr)->color == 'b')
    return 1;
  else
    return 0;
}

int isDoubleBlack(Node **rootPtr, Node *removeNode){
  if((*rootPtr) != NULL && (*rootPtr)->color == 'd')
    return 1;
  else if((*rootPtr) == NULL && removeNode->color == 'b')
    return 1;
  else
    return 0;
}


// Node *_delRedBlackTree(Node **rootPtr, Node *delNode){
  // Node *node;
  
  
  
  // if((*rootPtr) == NULL){
    // Throw(ERR_NODE_UNAVAILABLE);
  // }else if((*rootPtr)->data == delNode->data){
    // (*rootPtr) = NULL;
    // return node;
  // }else if((*rootPtr)->data > delNode->data){
    // if((*rootPtr)->left != NULL && (*rootPtr)->right != NULL){
      // if((*rootPtr)->left->color == 'b' && (*rootPtr)->right->color == 'b'){  
        // (*rootPtr)->color = 'b';
        // (*rootPtr)->left->color = 'r';
        // (*rootPtr)->right->color = 'r';
      // }
    // }
    // node = _delRedBlackTree(&(*rootPtr)->left, delNode);
  // }else if((*rootPtr)->data < delNode->data){
    // if((*rootPtr)->left != NULL && (*rootPtr)->right != NULL){
      // if((*rootPtr)->left->color == 'b' && (*rootPtr)->right->color == 'b'){  
        // (*rootPtr)->color = 'b';
        // (*rootPtr)->left->color = 'r';
        // (*rootPtr)->right->color = 'r';
      // }
    // }
    // node = _delRedBlackTree(&(*rootPtr)->right, delNode);
  // }
  
  // if((*rootPtr)->right != NULL && (*rootPtr)->right->right != NULL && (*rootPtr)->left == NULL){
    // if((*rootPtr)->right->left->color == 'b' && (*rootPtr)->right->right->color == 'b'){
      // leftRotate(rootPtr);
      // (*rootPtr)->left->right->color = 'r';
    // }
  // }
  
  // return node;
// }


