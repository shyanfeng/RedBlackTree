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
  Node *node, *rightTemp, *leftTemp, *temp, *removeSuccessor;
  char tempColor;
  
  if((*rootPtr) == NULL){
    Throw(ERR_NODE_UNAVAILABLE);
  }else if((*rootPtr)->data == delNode->data){
    if((*rootPtr)->right != NULL){
      removeSuccessor = removeNextLargerSuccessor(&(*rootPtr)->right);
      leftTemp = (*rootPtr)->left;
      rightTemp = (*rootPtr)->right;
      tempColor = (*rootPtr)->color;
      (*rootPtr) = removeSuccessor;
      (*rootPtr)->left = leftTemp;
      (*rootPtr)->right = rightTemp;
      //printf("%c", (*rootPtr)->color);
      restructureRedBlackTree(rootPtr, removeSuccessor);
      (*rootPtr)->color = tempColor;
      //printf("%d\n", (*rootPtr)->data);
    }else if((*rootPtr)->left != NULL){
      rightRotate(rootPtr);
      removeSuccessor = removeNextLargerSuccessor(&(*rootPtr)->right);
      //(*rootPtr)->color = 'b';
      //printf("%d", (*rootPtr)->data);
    }else{
      (*rootPtr) = NULL;
    }
    return node;
  }else if((*rootPtr)->data > delNode->data){
    node = _delRedBlackTree(&(*rootPtr)->left, delNode);
  }else if((*rootPtr)->data < delNode->data){
    node = _delRedBlackTree(&(*rootPtr)->right, delNode);
  }

  //LeftCase
  if(isDoubleBlack((&(*rootPtr)->left), delNode)){
    if(isRed(&(*rootPtr)->right->left) || isRed(&(*rootPtr)->right->right)){
      isLeftCase1(rootPtr);
    }else if(isBlack(&(*rootPtr)->right) && isBlack(&(*rootPtr)->right->left) && 
    isBlack(&(*rootPtr)->right->right)){
      isLeftCase2(rootPtr, delNode);
    }else if(isRed(&(*rootPtr)->right)){
      isLeftCase3(rootPtr, delNode);
    }
  }
  
  //RightCase
  if(isDoubleBlack((&(*rootPtr)->right), delNode)){
    if(isRed(&(*rootPtr)->left->right) || isRed(&(*rootPtr)->left->left)){
      isRightCase1(rootPtr);
    }else if(isBlack(&(*rootPtr)->left) && isBlack(&(*rootPtr)->left->right) && 
      isBlack(&(*rootPtr)->left->left)){
      isRightCase2(rootPtr, delNode);
    }else if(isRed(&(*rootPtr)->left)){
      isRightCase3(rootPtr, delNode);
    }
  }
  
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
    (*rootPtr)->right->color = 'r';
	if(isDoubleBlack(&(*rootPtr)->left, removeNode) && (*rootPtr)->left != NULL){
		(*rootPtr)->left->color = 'b';
	}
  }else if(isRed(&(*rootPtr))){
    (*rootPtr)->color = 'b';
    (*rootPtr)->right->color = 'r';
	if(isDoubleBlack(&(*rootPtr)->left, removeNode) && (*rootPtr)->left != NULL){
		(*rootPtr)->left->color = 'd';
	}
  }
}

void isLeftCase1(Node **rootPtr){
  if(isRed(&(*rootPtr)->right->right)){
    (*rootPtr)->right->color = (*rootPtr)->color;
    leftRotate(rootPtr);
  }else if(isRed(&(*rootPtr)->right->left)){
    (*rootPtr)->right->color = (*rootPtr)->color;
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
    (*rootPtr)->left->color = 'r';
	if(isDoubleBlack(&(*rootPtr)->right, removeNode) && (*rootPtr)->right != NULL){
		(*rootPtr)->left->color = 'b';
	}
  }else if(isRed(&(*rootPtr))){
    (*rootPtr)->color = 'b';
    (*rootPtr)->left->color = 'r';
	if(isDoubleBlack(&(*rootPtr)->right, removeNode) && (*rootPtr)->right != NULL){
		(*rootPtr)->left->color = 'd';
	}
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


