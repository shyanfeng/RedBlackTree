#include <stdio.h>
#include "unity.h"
#include "Rotations.h"
#include "Node.h"

Node node1, node3, node5, node6, node7, node8, node10, node12, node13, node15;

void setNode(Node *target, Node *left, Node *right, char color){
	target->left = left;
	target->right = right;
	target->color = color;
}

void resetNode(Node *target, int data){
	target->left = NULL;
	target->right = NULL;
	target->color = 'b';
	target->data = data;
}

void setUp(void){
	resetNode(&node1, 1);
	resetNode(&node3, 3);
	resetNode(&node5, 5);
	resetNode(&node6, 6);
	resetNode(&node7, 7);
	resetNode(&node8, 8);
	resetNode(&node10, 10);
	resetNode(&node12, 12);
	resetNode(&node13, 13);
	resetNode(&node15, 15);
}

void tearDown(void){}

/**
  *				  root
  *				   /			    root
  *				  v			      /
  *				10			     v
  *			  /			      5
  *			 5		--->   /  \
  *			/			      1   10
  *		 1
  *
  *
  */
void test_right_rotate_3_elements(void){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, &node1, NULL, 'b');
	setNode(&node10, &node5, NULL, 'b');
	Node *root = &node10;
	
	rightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
	
}

/**
  *				 root
  *				  /		    	      root
  *				 v		    	       /
  *				10		    	      v
  *			 /  \		    	     5
  *			5	  12    --->    /  \
  *		 /		    	       1   10
  *		1                        \
  *                            12
  *
  */
void test_right_rotate_4_elements(void){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, &node1, NULL, 'b');
	setNode(&node12, NULL, NULL, 'b');
	setNode(&node10, &node5, &node12, 'b');
	Node *root = &node10;
	
	rightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node12);
	TEST_ASSERT_EQUAL_PTR(node12.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node12.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
	
}

/**
  *				 root
  *				  /		    	      root
  *				 v		    	      /
  *				10		    	     v
  *			 /  \		    	    5
  *			5	  12    --->   /  \
  *		 / \	    	      1   10
  *	  1   7                 /  \
  *                        7   12
  *
  */
void test_right_rotate_5_elements(void){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node7, NULL, NULL, 'b');
	setNode(&node5, &node1, &node7, 'b');
	setNode(&node12, NULL, NULL, 'b');
	setNode(&node10, &node5, &node12, 'b');
	Node *root = &node10;
	
	rightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node7);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node12);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node12.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node12.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node7.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node7.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
	
}

/**
  *		 root
  *		  /			        root
  *		 v			        /
  *		5			         v
  *		  \		        7
  *		   7	--->   /  \
  *			  \		    5   10
  *			   10
  *
  *
  */
void test_left_rotate_3_elements(void){
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node7, NULL, &node10, 'b');
	setNode(&node5, NULL, &node7, 'b');
	Node *root = &node5;
	
	leftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node5.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node7.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node7.right, &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node7);
	
}

/**
  *		  root
  *		   /			        root
  *		  v			          /
  *		 5			         v
  *	  /  \		        7
  *	 1    7	  --->   /  \
  *			   \		    5   10
  *			    10     /
  *               1
  *
  */
void test_left_rotate_4_elements(void){
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node7, NULL, &node10, 'b');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, &node1, &node7, 'b');
	Node *root = &node5;
	
	leftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node7.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node7.right, &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node7);
	
}

/**
  *		    root
  *		     /			      root
  *		    v			        /
  *		   5			       v
  *	   /  \		        10
  *	  1    10	--->   /  \
  *		    /  \		  5   12
  *		   7	 12    / \
  *               1   7
  *
  */
void test_left_rotate_5_elements(void){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node7, NULL, NULL, 'b');
	setNode(&node12, NULL, NULL, 'b');
	setNode(&node5, &node1, &node10, 'b');
    setNode(&node10, &node7, &node12, 'b');
	Node *root = &node5;
	
	leftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node7.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node7.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node7);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node12);
	TEST_ASSERT_EQUAL_PTR(node12.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node12.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	
}

/**
  *				 root
  *				  /		    	root
  *				 v		    	  /                   root
  *				10		    	 v                      /
  *			   /  		    10                     v
  *			  5	   --->   /        --->          7
  *			   \	    	 7                      / \
  *			    7       /                      5   10
  *                5
  *
  *
  */
void test_leftRightRotate_rotate_3_elements(void){
	setNode(&node7, NULL, NULL, 'b');
	setNode(&node5, NULL, &node7, 'b');
	setNode(&node10, &node5, NULL, 'b');
	Node *root = &node10;
	
	leftRightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node5.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node7.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node7.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node7);
	
}

/**
  *				 root
  *				  /		    	root
  *				 v		    	  /                   root
  *				10		    	 v                      /
  *			  /  		    	10                     v
  *			 5	  --->   /        --->          7
  *			/  \	    	7                      / \
  *		1    7       /                      5   10
  *               5                      /
  *              /                      1
  *             1
  *
  *
  */
void test_leftRightRotate_rotate_4_elements(void){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node7, NULL, NULL, 'b');
	setNode(&node5, &node1, &node7, 'b');
	setNode(&node10, &node5, NULL, 'b');
	Node *root = &node10;
	
	leftRightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node7.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node7.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node7);
	
}

/**
  *				 root
  *				  /		    	    root
  *				 v		    	    /                   root
  *				10		    	   v                      /
  *			 /  \		    	  10                     v
  *		 5	   15  --->  /  \     --->          7
  *		/  \	    	    7    15                /  \
  *	 1    7          /  \                   5    10
  *        \        5    8                 /    /  \
  *         8      /                      1    8    15
  *               1
  *
  *
  *
  *
  *
  */
void test_leftRightRotate_rotate_6_elements_with_left_grand_right_child(void){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node8, NULL, NULL, 'b');
	setNode(&node7, NULL, &node8, 'b');
	setNode(&node5, &node1, &node7, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node10, &node5, &node15, 'b');
	Node *root = &node10;
	
	leftRightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node8.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node8.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node7.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node7.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node8);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node15);
	TEST_ASSERT_EQUAL_PTR(node15.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node7);
	
}

/**
  *				 root
  *				  /		    	    root
  *				 v		    	    /                   root
  *				10		    	   v                      /
  *			 /  \		    	  10                     v
  *			5	   15  --->  /  \     --->          7
  *		/  \	    	    7    15                /  \
  *	 1    7          /                      5    10
  *      /          5                      /  \    \
  *    6          /  \                   1    6    15
  *              1    6
  *
  *
  */
void test_leftRightRotate_rotate_6_elements_with_left_grand_left_child(void){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node6, NULL, NULL, 'b');
	setNode(&node7, &node6, NULL, 'b');
	setNode(&node5, &node1, &node7, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node10, &node5, &node15, 'b');
	Node *root = &node10;
	
	leftRightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node6.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node6.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node6);
	TEST_ASSERT_EQUAL_PTR(node7.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node7.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node15);
	TEST_ASSERT_EQUAL_PTR(node15.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node7);
	
}

/**
  *				 root
  *				  /		    	      root
  *				 v		    	      /                     root
  *				5		    	       v                        /
  *			   \  	    	    5                        v
  *			    10    --->     \       --->          7
  *			   /	              7                   / \
  *			  7                  \                 5   10
  *                           10
  *
  *
  */
void test_rightLeftRotate_rotate_3_elements(void){
	setNode(&node7, NULL, NULL, 'b');
	setNode(&node5, NULL, &node10, 'b');
	setNode(&node10, &node7, NULL, 'b');
	Node *root = &node5;
	
	rightLeftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node5.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node7.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node7.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node7);
	
}

/**
  *			   root
  *			   /		    	 root
  *			  v		    	      /                   root
  *			 5		        	 v                      /
  *			  \  		         5                      v
  *			   10	    --->    \     --->           8
  *			  /  \	    	     8                  / \
  *			 8    12            \                5   10
  *                         10                    \
  *                           \                    12
  *                            12
  *
  *
  */
void test_rightLeftRotate_rotate_4_elements(void){
	setNode(&node8, NULL, NULL, 'b');
	setNode(&node12, NULL, NULL, 'b');
	setNode(&node10, &node8, &node12, 'b');
	setNode(&node5, NULL, &node10, 'b');
	Node *root = &node5;
	
	rightLeftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node5.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node12);
	TEST_ASSERT_EQUAL_PTR(node8.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node8.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node12.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node12.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node8);
	
}

/**
  *				 root
  *				  /		    	    root
  *				 v		    	    /                     root
  *				5		    	     v                      /
  *			 /  \		    	  5                     v
  *			1	   10  --->  / \     --->          7
  *			    /  \  	  1   7                 /  \
  *			   7    15         \              5    10
  *         \               10           /    /  \
  *          8             /  \         1    8    15
  *                       8    15
  *
  *
  */
void test_rightLeftRotate_rotate_6_elements_with_left_grand_right_child(void){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node8, NULL, NULL, 'b');
	setNode(&node7, NULL, &node8, 'b');
	setNode(&node5, &node1, &node10, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node10, &node7, &node15, 'b');
	Node *root = &node5;
	
	rightLeftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node8.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node8.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node7.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node7.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node8);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node15);
	TEST_ASSERT_EQUAL_PTR(node15.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node7);
	
}

/**
  *				 root
  *				  /		    	    root
  *				 v		    	    /                   root
  *				5		    	     v                      /
  *			 /  \		    	  5                      v
  *		 1	   10  --->  /  \     --->          8
  *			    /	 \    	3    8                 /  \
  *			   8    15   /      \               5    10
  *       /         1       10             /  \    \
  *      3                    \           1    3    15
  *                           15
  *
  *
  *
  *
  *
  */
void test_rightLeftRotate_rotate_6_elements_with_left_grand_left_child(void){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node3, NULL, NULL, 'b');
	setNode(&node8, &node3, NULL, 'b');
	setNode(&node5, &node1, &node10, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node10, &node8, &node15, 'b');
	Node *root = &node5;
	
	rightLeftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node3.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node3.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node3);
	TEST_ASSERT_EQUAL_PTR(node8.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node8.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node15);
	TEST_ASSERT_EQUAL_PTR(node15.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node8);
	
}

void changeRootByVal(Node *node, Node *newNode){
	node = newNode;
	printf("changeRootByVal: node = %x\n", node);
}

void changeRootByRef(Node **nodePtr, Node *newNode){
	*nodePtr = newNode;
	printf("changeRootByRef: node = %x\n", nodePtr);
}

void test_changeRootByVal(){
	Node *root;
	root = &node10;
	
	printf("test_changeRootByVal()\n");
	printf("root is %d with address %x\n", root->data, root);
	changeRootByVal(root, &node5);
	printf("root is %d with address %x\n", root->data, root);
}

void test_changeRootByRef(){
	Node *root;
	root = &node10;
	
	printf("test_changeRootByRef()\n");
	printf("root is %d with address %x\n", root->data, root);
	changeRootByRef(&root, &node5);
	printf("root is %d with address %x\n", root->data, root);
}

