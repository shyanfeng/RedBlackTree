#include <stdio.h>
#include "unity.h"
#include "Rotations.h"
#include "Node.h"
#include "RedBlackTree.h"
#include "InitNode.h"
#include "CustomAssertion.h"
#include "CException.h"

Node node1, node3, node5, node6, node7, node8, node10, node12, node13, node15;

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
  *				 root
  *				  /				 root
  *				 v	  add 10  	  /
  *				NULL  ------> 	 v
  *								10
  *
  */
void test_addRedBlackTree_add_10_to_empty_tree(void){
	setNode(&node10, NULL, NULL, 'r');
	Node *root = NULL;
	
	addRedBlackTree(&root, &node10);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
	//						left right color node
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', root);

}

/**
  *				 root
  *				  /		    		  root
  *				 v		    	  	  /
  *				10(b)	add 5    	 v
  *			     		------>	   	10(b)
  *			    	    	       /  
  *			 		    		  5(r)   
  *			                       
  *
  */
void test_addRedBlackTree_add_5_to_the_left_tree_with_root_10(void){
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node5, NULL, NULL, 'b');
	Node *root = &node10;
	
	addRedBlackTree(&root, &node5);
	
	TEST_ASSERT_EQUAL_PTR(root, &node10);
						// left right color node
	TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', root);
						// left right color node
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);

}

/**
  *				 root
  *				  /		    		  root
  *				 v		    	  	  /
  *				10(b)	add 5    	 v
  *			     		------>	   	10(b)
  *			    	    	      	  \  
  *			 		    		  	  15(r)   
  *			                       
  *
  */
void test_addRedBlackTree_add_15_to_the_right_tree_with_root_10(void){
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	Node *root = &node10;
	
	addRedBlackTree(&root, &node15);
	
	TEST_ASSERT_EQUAL_PTR(root, &node10);
						// left right color node
	TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', root);
						// left right color node
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);

}