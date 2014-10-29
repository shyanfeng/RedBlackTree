#include <stdio.h>
#include "unity.h"
#include "Rotations.h"
#include "Node.h"
#include "RedBlackTree.h"
#include "InitNode.h"
#include "CustomAssertion.h"
#include "ErrorCode.h"
#include "CException.h"

Node node1, node2, node3, node4, node5, node6, node7, node8, node10, node12, node13, node15, node18, node20, node22, node25, node30, node35, node40, node45, node60;

void setUp(void){
	resetNode(&node1, 1);
	resetNode(&node2, 2);
	resetNode(&node3, 3);
	resetNode(&node4, 4);
	resetNode(&node5, 5);
	resetNode(&node6, 6);
	resetNode(&node7, 7);
	resetNode(&node8, 8);
	resetNode(&node10, 10);
	resetNode(&node12, 12);
	resetNode(&node13, 13);
	resetNode(&node15, 15);
	resetNode(&node18, 18);
	resetNode(&node18, 20);
	resetNode(&node22, 22);
	resetNode(&node25, 25);
	resetNode(&node30, 30);
	resetNode(&node35, 35);
	resetNode(&node40, 40);
	resetNode(&node40, 45);
	resetNode(&node60, 60);
}

void tearDown(void){}
/** 2-node case
 *        root
 *        /       remove 2    
 *       v        -------->   Throw ERR_NODE_UNAVAILABLE
 *      1(b)                   
 *                            
 *
 *
 */
void test_delRedBlackTree_remove_2_from_tree_with_root_1_should_throw_ERR_NODE_UNAVAILABLE(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'b');
  Node *root = &node1;
  
  Try {
    delRedBlackTree(&root, &node1);
    TEST_FAIL_MESSAGE("Expected ERR_NODE_UNAVAILABLE to be thrown. But receive none");
  } Catch(err){
    TEST_ASSERT_EQUAL_PTR(root, &node1);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  }
}

/** 2-node case
 *        root
 *        /       remove 2        root
 *       v        -------->       /
 *      1(b)                     v
 *                              NULL
 *
 *
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_1(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'b');
  Node *root = &node1;
  
  delRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, NULL);

}

/** 2-node case
 *        root
 *        /       remove 2        root
 *       v        -------->       /
 *      1(b)                     v
 *        \                     1(b)
 *        2(r)
 *
 */
void test_delRedBlackTree_remove_2_from_tree_with_root_1(void){
  CEXCEPTION_T err;
  setNode(&node2, NULL, NULL, 'r');
  setNode(&node1, NULL, &node1, 'b');
  Node *root = &node1;
  
  delRedBlackTree(&root, &node2);
  TEST_ASSERT_EQUAL_PTR(root, &node1);

}
