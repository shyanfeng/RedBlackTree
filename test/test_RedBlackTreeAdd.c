#include <stdio.h>
#include "unity.h"
#include "Rotations.h"
#include "Node.h"
#include "RedBlackTree.h"
#include "InitNode.h"
#include "CustomAssertion.h"
#include "ErrorCode.h"
#include "CException.h"

Node node1, node2, node4, node5, node7, node10, node12, node13, node15, node18, 
node19, node20, node22, node25, node30, node31, node40, node60;

void setUp(void){
	resetNode(&node1, 1);
	resetNode(&node2, 2);
	resetNode(&node4, 4);
	resetNode(&node5, 5);
	resetNode(&node7, 7);
	resetNode(&node10, 10);
	resetNode(&node12, 12);
	resetNode(&node13, 13);
	resetNode(&node15, 15);
	resetNode(&node18, 18);
	resetNode(&node19, 19);
	resetNode(&node20, 20);
	resetNode(&node22, 22);
	resetNode(&node25, 25);
	resetNode(&node30, 30);
	resetNode(&node31, 31);
	resetNode(&node40, 40);
	resetNode(&node60, 60);
	
}

void tearDown(void){}

/** Empty Case
  *       root
  *       /                 root
  *       v       add 10     /
  *      NULL    ------>    v
  *                        10
  *
  */
void test_addRedBlackTree_add_10_to_empty_tree(void){
	setNode(&node10, NULL, NULL, 'r');
	Node *root = NULL;
	
	addRedBlackTree(&root, &node10);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', root);

}

/** 2-node case
  *         root
  *         /                 root
  *         v                   /
  *       10(b) add5           v
  *             ------>       10(b)
  *                           /  
  *                         5(r)   
  *			                       
  *
  */
void test_addRedBlackTree_add_5_to_the_left_tree_with_root_10(void){
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node5, NULL, NULL, 'b');
	Node *root = &node10;
	
	addRedBlackTree(&root, &node5);
	
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);

}

/** 2-node case
  *         root
  *         /                    root
  *        v                    /
  *     10(b)   add5           v
  *             ------>      10(b)
  *                             \  
  *                           15(r)   
  *			                       
  *
  */
void test_addRedBlackTree_add_15_to_the_right_tree_with_root_10(void){
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	Node *root = &node10;
	
	addRedBlackTree(&root, &node15);
	
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);

}

/** 3-node case
  *           root
  *            /                 root
  *           v                 /
  *         10(b)   add1       v
  *         /       ------>   5(b)
  *       5(r)                /  \
  *                         1(r)  10(r)   
  *			                       
  *
  */
void test_addRedBlackTree_add_1_to_the_tree_rotate_right_with_5_10_nodes(void){
  setNode(&node1, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node10, &node5, NULL, 'b');
	Node *root = &node10;
	
	addRedBlackTree(&root, &node1);
	
	TEST_ASSERT_EQUAL_PTR(root, &node5);
	TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);

}

/** 3-node case
  *         root
  *         /                 root
  *        v                    /
  *       5(b)  add15          v
  *         \   ------>       10(b)
  *         10(r)             /   \  
  *                         5(r)  15(r)   
  *			                       
  *
  */
void test_addRedBlackTree_add_15_to_the_tree_rotate_left_with_5_10_nodes(void){
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node5, NULL, &node10, 'b');
	setNode(&node10, NULL, NULL, 'r');
	Node *root = &node5;
	
	addRedBlackTree(&root, &node15);
	
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);

}

/** Error case
  *         root
  *         /		    		  
  *        v		    	  	  
  *       10(b) add10    	 
  *             ------>   Error
  *			    	    	      	            
  *
  */
void test_addRedBlackTree_add_same_value_should_throw(void){
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node10, NULL, NULL, 'b');
	Node *root = &node10;
	int e;
	
	Try{
		addRedBlackTree(&root, &node10);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_EQUIVALENT_NODE, e);
	}	
}

/** 3-node case
  *         root
  *         /                   root
  *        v                    /                     root
  *       10(b) add7           v                      /
  *       /      ------>      10(b)                  v
  *     5(r)                  /           --->      7(b)
  *                         5(r)                   /   \
  *                           \                 5(r)    10(r)
  *                           7(r)                  
  *                             
  *
  *
  */
void test_addRedBlackTree_add_7_to_the_tree_rotate_left_right_with_5_10_nodes(void){
	setNode(&node7, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node10, &node5, NULL, 'b');
	Node *root = &node10;
	
	addRedBlackTree(&root, &node7);
	
	TEST_ASSERT_EQUAL_PTR(root, &node7);
	TEST_ASSERT_EQUAL_NODE(&node5, &node10, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
	
}

/** 3-node case
  *         root
  *         /                   root
  *        v                    /            
  *       10(b) add12          v               
  *       /     ------>       10(b)               
  *     5(r)                  /   \        
  *                         5(r)  12(r)           
  *
  */
void test_addRedBlackTree_add_12_to_the_tree_with_5_10_nodes(void){
	setNode(&node12, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node10, &node5, NULL, 'b');
	Node *root = &node10;
	
	addRedBlackTree(&root, &node12);
	
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	TEST_ASSERT_EQUAL_NODE(&node5, &node12, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node12);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
	
}

/** 3-node case
  *         root
  *         /                  root
  *        v                   /
  *       10(b)   add12(r)    v
  *           \   ------>    12(b)
  *         15(r)           /   \  
  *                       10(r) 15(r)   
  *			                       
  *
  */
void test_addRedBlackTree_add_12_to_the_tree_rotate_right_left_with_10_15_nodes(void){
	setNode(&node12, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node10, NULL, &node15, 'b');
	Node *root = &node10;
	
	addRedBlackTree(&root, &node12);
	
	TEST_ASSERT_EQUAL_PTR(root, &node12);
	TEST_ASSERT_EQUAL_NODE(&node10, &node15, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);

}

/** 3-node case
  *         root
  *         /                 root
  *        v                  /
  *       10(b)   add5       v
  *           \   ------>   10(b)
  *           5(r)          /   \  
  *                       5(r)  15(r)   
  *
  */
void test_addRedBlackTree_add_5_to_the_tree_with_10_15_nodes(void){
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node10, NULL, &node15, 'b');
	Node *root = &node10;
	
	addRedBlackTree(&root, &node5);
	
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);

}

/** 4-node case
  *         root
  *         /                       root
  *        v                        /                     root
  *       10(b)       add1           v                      /
  *       /   \       ------>      10(b)                  v
  *     5(r)   15(r)               /  \         --->      10(r)
  *                             5(r)  15(r)              /   \
  *                             /                      5(b)   15(b)
  *                            1(r)                    /
  *                                                  1(r)
  *
  *
  */
void test_addRedBlackTree_add_1_to_the_tree_with_5_10_15_nodes(void){
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node10, &node5, &node15, 'b');
	Node *root = &node10;
	
	_addRedBlackTree(&root, &node1);
	
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
	
}

/** 4-node case
  *         root
  *         /                       root
  *        v                        /                     root
  *       10(b)       add7           v                      /
  *       /   \       ------>      10(b)                  v
  *     5(r)   15(r)               /  \         --->      10(r)
  *                             5(r)  15(r)              /   \
  *                               \                    5(b)   15(b)
  *                               7(r)                   \
  *                                                      7(r)
  *
  *
  */
void test_addRedBlackTree_add_7_to_the_tree_with_5_10_15_nodes(void){
	setNode(&node7, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node10, &node5, &node15, 'b');
	Node *root = &node10;
	
	_addRedBlackTree(&root, &node7);
	
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
	
}

/** 4-node case
  *         root
  *         /                       root
  *        v                        /                     root
  *       10(b)       add12        v                      /
  *       /   \       ------>      10(b)                  v
  *     5(r)   15(r)               /  \         --->      10(r)
  *                             5(r)  15(r)              /   \
  *                                   /                5(b)   15(b)
  *                                 12(r)                     /
  *                                                         12(r)
  *
  *
  */
void test_addRedBlackTree_add_12_to_the_tree_with_5_10_15_nodes(void){
	setNode(&node12, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node10, &node5, &node15, 'b');
	Node *root = &node10;
	
	_addRedBlackTree(&root, &node12);
	
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', root);
	TEST_ASSERT_EQUAL_NODE(&node12, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node12);
	
}

/** 4-node case
  *         root
  *         /                       root
  *        v                        /                     root
  *       10(b)       add18          v                      /
  *       /   \       ------>      10(b)                  v
  *     5(r)   15(r)               /  \         --->      10(r)
  *                             5(r)  15(r)              /   \
  *                                     \              5(b)   15(b)
  *                                     18(r)                   \
  *                                                             18(r)
  *
  *
  */
void test_addRedBlackTree_add_18_to_the_tree_with_5_10_15_nodes(void){
	setNode(&node18, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node10, &node5, &node15, 'b');
	Node *root = &node10;
	
	_addRedBlackTree(&root, &node18);
	
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', root);
	TEST_ASSERT_EQUAL_NODE(NULL, &node18, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node18);
	
}

/** 6-node case
  *         root
  *         /                       root
  *        v                        /                         root
  *       20(b)       add7           v                        /
  *       /   \       ------>      20(b)                     v
  *    10(b)   22(b)               /    \         --->      20(b)
  *    /  \                      10(b)  22(b)               /   \
  * 5(r)  15(r)                  /  \                    10(r)   22(b)
  *                            5(r)  15(r)               /  \
  *                               \                    5(b)  15(b)     
  *                               7(r)                    \
  *                                                        7(r)
  *
  *
  */
void test_addRedBlackTree_add_7_to_the_tree_with_5_10_15_20_22_nodes(void){
	setNode(&node7, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node22, NULL, NULL, 'b');
	setNode(&node10, &node5, &node15, 'b');
	setNode(&node20, &node10, &node22, 'b');
	Node *root = &node20;
	
	addRedBlackTree(&root, &node7);
	
	TEST_ASSERT_EQUAL_PTR(root, &node20);
	TEST_ASSERT_EQUAL_NODE(&node10, &node22, 'b', root);
	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node22);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
	
}

/**
 *        root           root
 *         |    add 10r   |
 *         V   ------->   V
 *        25b            25b    =>     25b
 *       /   \          /   \         /   \
 *     15b   30b      15b   30b     15r   30b
 *    /  \           /  \          /  \
 *   5r  20r       5r   20r      5b   20b
 *                   \             \
 *                   10r           10r
 */
void test_addRedBlackTree_add_10_should_not_rotate_and_promote_then_flip_colour(void){
  setNode(&node10,NULL,NULL,'r');
  setNode(&node5,NULL,NULL,'r');
  setNode(&node20,NULL,NULL,'r');
  setNode(&node15,&node5,&node20,'b');
  setNode(&node30,NULL,NULL,'b');
  setNode(&node25,&node15,&node30,'b');
	Node *root = &node25;

  addRedBlackTree(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(root, &node25);

  TEST_ASSERT_EQUAL_NODE(&node15, &node30, 'b', &node25);
  TEST_ASSERT_EQUAL_NODE(&node5, &node20, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, &node10, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
}

/** 10-node case
 *            root         add7  
 *            V           ------->      root
 *          20(b)                       V             ----->        root
 *        /      \                     20(b)                        V
 *       4(r)     40(r)               /     \                       20(b)
 *      /  \      /   \             4(r)     40(r)                 /     \
 *  1(b) 10(b) 30(b) 60(b)         /  \      /   \               4(b)     40(b)
 *       /  \                   1(b) 10(b) 30(b) 60(b)          /   \     /   \
 *     5(r) 15(r)                    /  \                     1(b) 10(r) 30(b) 60(b)
 *                                 5(r) 15(r)                      /   \
 *                                   \                           5(b)  15(b)
 *                                   7(r)                         \
 *                                                                 7(r)
 */
void test_addRedBlackTree_add_7_should_not_rotate_and_promote_then_flip_colour(void){
  setNode(&node7,NULL,NULL,'r');
  setNode(&node5,NULL,NULL,'r');
  setNode(&node15,NULL,NULL,'r');
  setNode(&node1,NULL,NULL,'b');
  setNode(&node10,&node5,&node15,'b');
  setNode(&node30,NULL,NULL,'b');
  setNode(&node60,NULL,NULL,'b');
  setNode(&node4,&node1,&node10,'r');
  setNode(&node40,&node30,&node60,'r');
  setNode(&node20,&node4,&node40,'b');
	Node *root = &node20;

  addRedBlackTree(&root, &node7);
  TEST_ASSERT_EQUAL_PTR(root, &node20);
  TEST_ASSERT_EQUAL_NODE(&node4, &node40, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node30, &node60, 'b', &node40);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node60);
  TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
}

/* Failed Function Test adding 13 with sequence to be completed
 *            root
 *            /     add 13(b)            root
 *          NULL      --->               /
 *                                    13(b)
 *
 *
 */
 
void test_addRedBlackTree_13_with_adding_sequence(void){
  setNode(&node13,NULL,NULL,'b');
  Node *root = NULL;
  
  addRedBlackTree(&root, &node13);
  TEST_ASSERT_EQUAL_PTR(root, &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
 
}

/* Failed Function Test adding 10 with sequence to be completed
 *            root
 *            /     add 10(b)            root
 *          13(b)    --->               /
 *                                    13(b)
 *                                    /
 *                                  10(r)
 */
 
void test_addRedBlackTree_10_with_adding_sequence(void){
  setNode(&node13,NULL,NULL,'b');
  setNode(&node10,NULL,NULL,'b');
  Node *root = &node13;
  
  addRedBlackTree(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(root, &node13);
  TEST_ASSERT_EQUAL_NODE(&node10, NULL, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
 
}

/* Failed Function Test adding 2 with sequence to be completed
 *            root
 *            /     add 2(b)            root
 *          13(b)    --->               /
 *         /                           10(b)
 *       10(r)                        /    \
 *                                  2(r)  13(r)
 */
 
void test_addRedBlackTree_2_with_adding_sequence(void){
  setNode(&node13,&node10,NULL,'b');
  setNode(&node10,NULL,NULL,'r');
  setNode(&node2,NULL,NULL,'b');
  Node *root = &node13;
  
  addRedBlackTree(&root, &node2);
  TEST_ASSERT_EQUAL_PTR(root, &node10);
  TEST_ASSERT_EQUAL_NODE(&node2, &node13, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node2);
 
}

/* Failed Function Test adding 1 with sequence to be completed
 *            root
 *            /     add 1(b)            root
 *          10(b)    --->               /
 *         /    \                      10(b)
 *       2(r)  13(r)                  /    \
 *                                  2(b)   13(b)
 *                                  /
 *                                1(r)
 *
 */
 
void test_addRedBlackTree_1_with_adding_sequence(void){
  setNode(&node10,&node2,&node13,'b');
  setNode(&node13,NULL,NULL,'r');
  setNode(&node2,NULL,NULL,'r');
  setNode(&node1,NULL,NULL,'b');
  Node *root = &node10;
  
  addRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, &node10);
  TEST_ASSERT_EQUAL_NODE(&node2, &node13, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
 
}

/* Failed Function Test adding 5 with sequence to be completed
 *            root
 *            /     add 5(b)            root
 *          10(b)    --->               /
 *         /    \                      10(b)
 *       2(b)  13(b)                  /    \
 *       /                           2(b)   13(b)
 *     1(r)                         /   \
 *                                1(r)  5(r)
 *
 */
 
void test_addRedBlackTree_5_with_adding_sequence(void){
  setNode(&node10,&node2,&node13,'b');
  setNode(&node13,NULL,NULL,'b');
  setNode(&node2,&node1,NULL,'b');
  setNode(&node1,NULL,NULL,'r');
  setNode(&node5,NULL,NULL,'b');
  Node *root = &node10;
  
  addRedBlackTree(&root, &node5);
  TEST_ASSERT_EQUAL_PTR(root, &node10);
  TEST_ASSERT_EQUAL_NODE(&node2, &node13, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
 
}

/* Failed Function Test adding 31 with sequence to be completed
 *            root
 *            /     add 31(b)            root
 *          10(b)    --->               /
 *         /    \                      10(b)
 *       2(b)  13(b)                  /    \
 *       /   \                      2(b)   13(b)
 *     1(r)  5(r)                  /   \      \
 *                               1(r)  5(r)   31(r)
 *
 */
 
void test_addRedBlackTree_31_with_adding_sequence(void){
  setNode(&node10,&node2,&node13,'b');
  setNode(&node13,NULL,NULL,'b');
  setNode(&node2,&node1,&node5,'b');
  setNode(&node1,NULL,NULL,'r');
  setNode(&node5,NULL,NULL,'r');
  setNode(&node31,NULL,NULL,'b');
  Node *root = &node10;
  
  addRedBlackTree(&root, &node31);
  TEST_ASSERT_EQUAL_PTR(root, &node10);
  TEST_ASSERT_EQUAL_NODE(&node2, &node13, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node31, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node31);
 
}

/* Failed Function Test adding 7 with sequence to be completed
 *            root
 *            /     add 7(b)            root
 *          10(b)    --->               /
 *         /    \                      10(b)
 *       2(b)  13(b)                  /    \
 *       /   \     \                2(r)   13(b)
 *     1(r)  5(r)  31(r)           /   \      \
 *                               1(b)  5(b)   31(r)
 *                                        \
 *                                        7(r)
 *
 *
 */
 
void test_addRedBlackTree_7_with_adding_sequence(void){
  setNode(&node10,&node2,&node13,'b');
  setNode(&node13,NULL,&node31,'b');
  setNode(&node2,&node1,&node5,'b');
  setNode(&node1,NULL,NULL,'r');
  setNode(&node5,NULL,NULL,'r');
  setNode(&node31,NULL,NULL,'r');
  setNode(&node7,NULL,NULL,'b');
  Node *root = &node10;
  
  addRedBlackTree(&root, &node7);
  TEST_ASSERT_EQUAL_PTR(root, &node10);
  TEST_ASSERT_EQUAL_NODE(&node2, &node13, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'r', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node31, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node31);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
 
}

/* Failed Function Test adding 19 with sequence to be completed
 *            root
 *            /     add 19(b)            root
 *          10(b)    --->               /
 *         /    \                       10(b)
 *       2(r)  13(b)                 /         \
 *       /   \     \               2(r)       19(r)
 *     1(b)  5(b)  31(r)          /   \      /    \
 *              \               1(b)  5(b) 13(b)   31(b)
 *              7(r)                     \
 *                                       7(r)
 *
 *
 */
 
void test_addRedBlackTree_19_with_adding_sequence(void){
  setNode(&node10,&node2,&node13,'b');
  setNode(&node13,NULL,&node31,'b');
  setNode(&node2,&node1,&node5,'r');
  setNode(&node1,NULL,NULL,'b');
  setNode(&node5,NULL,&node7,'b');
  setNode(&node31,NULL,NULL,'r');
  setNode(&node7,NULL,NULL,'r');
  setNode(&node19,NULL,NULL,'b');
  Node *root = &node10;
  
  addRedBlackTree(&root, &node19);
  TEST_ASSERT_EQUAL_PTR(root, &node10);
  TEST_ASSERT_EQUAL_NODE(&node2, &node19, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'r', &node2);
  TEST_ASSERT_EQUAL_NODE(&node13, &node31, 'r', &node19);
  TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node31);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
 
}
