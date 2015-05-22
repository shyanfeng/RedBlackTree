#include <stdio.h>
#include "unity.h"
#include "Rotations.h"
#include "Node.h"
#include "RedBlackTree.h"
#include "InitNode.h"
#include "CustomAssertion.h"
#include "ErrorCode.h"
#include "CException.h"

Node node1, node2, node3, node4, node5, node6, node7, node8, node10, node11, node12, 
node13, node15, node18, node19, node20, node21, node22, node23, node24, node25, 
node26, node28, node29, node30, node31, node32;

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
	resetNode(&node11, 11);
	resetNode(&node12, 12);
	resetNode(&node13, 13);
	resetNode(&node15, 15);
	resetNode(&node18, 18);
	resetNode(&node19, 19);
	resetNode(&node20, 20);
	resetNode(&node21, 21);
	resetNode(&node22, 22);
	resetNode(&node23, 23);
	resetNode(&node24, 24);
	resetNode(&node25, 25);
	resetNode(&node26, 26);
	resetNode(&node28, 28);
	resetNode(&node29, 29);
	resetNode(&node30, 30);
	resetNode(&node31, 31);
	resetNode(&node32, 32);
}

void tearDown(void){}

/** 5-node case
 *        root
 *        /       remove 1        root
 *       v        -------->       /                     root
 *      2(b)                     v        ----->        /
 *     /  \                     2(b)                  4(b)
 *   1(b)  4(b)                     \                /    \
 *             \                    4(b)           2(b)   5(b)
 *            5(b)                    \
 *                                    5(r)
 */
void test_delRedBlackTree_remove_1_from_tree_rotate_left_with_root_2_4_5(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node2, &node1, &node4, 'b');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node4, NULL, &node5, 'b');
  Node *root = &node2;
  
  delRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, &node4);
  TEST_ASSERT_EQUAL_NODE(&node2, &node5, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);

}

/** 5-node case
 *        root
 *        /       remove 1        root
 *       v        -------->       /                     root
 *      2(b)                     v        ----->        /
 *     /  \                     2(r)                  4(r)
 *   1(b)  5(b)                     \                /    \
 *         /                        5(b)           2(b)   5(b)
 *       4(r)                       /
 *                                4(r)
 */
void test_delRedBlackTree_remove_1_from_tree_rotate_right_left_with_root_2_4_5(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node2, &node1, &node5, 'b');
  setNode(&node4, NULL, NULL, 'r');
  setNode(&node5, &node4, NULL, 'b');
  Node *root = &node2;
  
  delRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, &node4);
  TEST_ASSERT_EQUAL_NODE(&node2, &node5, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);

}

/** 3-node case
 *        root
 *        /       remove 1        root
 *       v        -------->       /
 *      2(b)                     v
 *     /  \                     2(d)
 *   1(b)  3(b)                    \
 *                                 3(r)
 *
 *
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2_and_3_with_red(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node2, &node1, &node3, 'b');
  Node *root = &node2;
  
  _delRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'd', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);

}

/** 3-node case
 *        root
 *        /       remove 1        root
 *       v        -------->       /
 *      2(r)                     v
 *     /  \                     2(b)
 *   1(b)  3(b)                    \
 *                                 3(r)
 *
 *
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2_red_and_3_(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node2, &node1, &node3, 'r');
  Node *root = &node2;
  
  _delRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);

}

/** 5-node case
 *        root
 *        /       remove 1        root
 *       v        -------->       /                         root
 *      2(b)                     v      ---->               /
 *     /  \                     2(b)                       4(b)
 *   1(b)  4(r)                    \                      /    \
 *        /    \                   4(r)                 2(b)    5(b)
 *      3(b)   5(b)               /   \                   \
 *                              3(b)  5(b)                3(r)
 *
 *
 *
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2_4_red_3_5(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node4, &node3, &node5, 'r');
  setNode(&node2, &node1, &node4, 'b');
  Node *root = &node2;
  
  delRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, &node4);
  TEST_ASSERT_EQUAL_NODE(&node2, &node5, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);

}

/** 6-node case
 *        root
 *        /     remove 1       root              root
 *       v      -------->      /                 /
 *      2(b)                  v      ---->      v                 root
 *     /  \                  2(b)              5(b)       --->    /
 *   1(b)  5(r)                 \             /    \             v
 *        /    \                5(r)        2(r)    6(b)        5(b)
 *      3(b)   6(b)             /   \         \                /   \
 *        \                   3(b)  6(b)      3(b)           3(r)  6(b)
 *        4(r)                   \              \           /   \
 *                              4(r)            4(r)      2(b)  4(b)
 *
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2_4_5_red_3_6(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node4, NULL, NULL, 'r');
  setNode(&node6, NULL, NULL, 'b');
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node5, &node3, &node6, 'r');
  setNode(&node2, &node1, &node5, 'b');
  Node *root = &node2;
  
  delRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, &node5);
  TEST_ASSERT_EQUAL_NODE(&node3, &node6, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(&node2, &node4, 'r', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node4);

}

/** 4-node case
 *        root
 *        /       remove 5        root
 *       v        -------->       /                     root
 *      4(b)                     v        ----->        /
 *     /  \                     4(b)                  2(b)
 *   2(b)  5(b)                 /                    /    \
 *   /                         2(b)                1(b)   4(b)
 *  1(r)                      /        
 *                           1(r)         
 */
void test_delRedBlackTree_remove_5_from_tree_rotate_right_case_1_with_root_2_4_1(void){
  CEXCEPTION_T err;
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node4, &node2, &node5, 'b');
  Node *root = &node4;
  
  delRedBlackTree(&root, &node5);
  TEST_ASSERT_EQUAL_PTR(root, &node2);
  TEST_ASSERT_EQUAL_NODE(&node1, &node4, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node4);

}

/** 4-node case
 *        root
 *        /       remove 5        root
 *       v        -------->       /                     root
 *      4(b)                     v        ----->        /
 *     /  \                     4(b)                  3(b)
 *   2(b)  5(b)                 /                    /    \
 *      \                      2(b)                2(b)   4(b)
 *       3(r)                     \        
 *                                3(r)         
 */
void test_delRedBlackTree_remove_5_from_tree_rotate_right_case_1_with_root_2_4_red_1(void){
  CEXCEPTION_T err;
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'r');
  setNode(&node2, NULL, &node3, 'b');
  setNode(&node4, &node2, &node5, 'b');
  Node *root = &node4;
  
  delRedBlackTree(&root, &node5);
  TEST_ASSERT_EQUAL_PTR(root, &node3);
  TEST_ASSERT_EQUAL_NODE(&node2, &node4, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node4);

}

/** 3-node case
 *        root
 *        /       remove 3        root
 *       v        -------->       /
 *      2(b)                     v
 *     /  \                     2(d)
 *   1(b)  3(b)                 /  
 *                             1(r)
 *
 *
 */
void test_delRedBlackTree_remove_3_from_tree_with_right_case_root_2_and_3_with_red(void){
  CEXCEPTION_T err;
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node2, &node1, &node3, 'b');
  Node *root = &node2;
  
  _delRedBlackTree(&root, &node3);
  TEST_ASSERT_EQUAL_PTR(root, &node2);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'd', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);

}

/** 3-node case
 *        root
 *        /       remove 3        root
 *       v        -------->       /
 *      2(r)                     v
 *     /  \                     2(d)
 *   1(b)  3(b)                 /  
 *                             1(r)
 *
 *
 */
void test_delRedBlackTree_remove_3_from_tree_with_right_case_root_2_red_and_3(void){
  CEXCEPTION_T err;
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node2, &node1, &node3, 'r');
  Node *root = &node2;
  
  _delRedBlackTree(&root, &node3);
  TEST_ASSERT_EQUAL_PTR(root, &node2);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);

}

/** 5-node case
 *        root
 *        /       remove 5        root
 *       v        -------->       /                      root
 *      4(b)                     v      ---->            /
 *     /  \                     4(b)                   2(b)
 *   2(r)  5(b)                /                      /    \
 *  /    \                   2(r)                  1(b)    4(b)
 * 1(b)   3(b)               /   \                         /
 *                        1(b)  3(b)                    3(r)
 *
 *
 *
 */
void test_delRedBlackTree_remove_1_from_tree_with_right_case_root_2_4_red_3_5(void){
  CEXCEPTION_T err;
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node2, &node1, &node3, 'r');
  setNode(&node4, &node2, &node5, 'b');
  Node *root = &node4;
  
  delRedBlackTree(&root, &node5);
  TEST_ASSERT_EQUAL_PTR(root, &node2);
  TEST_ASSERT_EQUAL_NODE(&node1, &node4, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node3, NULL, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);

}

/** 1-node case
 *          root
 *          /     successor 3      root             
 *        v      -------->      /             
 *       3(b)                  v 
 *                            NULL
 *           
 *
 */
void test_removeNextLargerSuccessor_with_black_should_return_NULL(void){
  CEXCEPTION_T err;
  setNode(&node3, NULL, NULL, 'b');
  Node *removedNode, *parent = &node3;
  
  removedNode = removeNextLargerSuccessor(&parent);
  TEST_ASSERT_EQUAL_PTR(&node3, removedNode);
  TEST_ASSERT_NULL(parent);
  TEST_ASSERT_EQUAL(1, isDoubleBlack(&parent, removedNode));

}

/** 1-node case
 *          root
 *          /     successor 3      root             
 *        v      -------->      /             
 *       3(r)                  v 
 *                            NULL
 *           
 *
 */
void test_removeNextLargerSuccessor_with_red_should_return_NULL(void){
  CEXCEPTION_T err;
  setNode(&node3, NULL, NULL, 'r');
  Node *removedNode, *parent = &node3;
  
  removedNode = removeNextLargerSuccessor(&parent);
  TEST_ASSERT_EQUAL_PTR(&node3, removedNode);
  TEST_ASSERT_NULL(parent);
  TEST_ASSERT_EQUAL(0, isDoubleBlack(&parent, removedNode));

}

/** 2-node case
 *          root
 *          /     successor 3      root             
 *        v      -------->      /     ---->   root        
 *       3(b)                  4(r)           /
 *      /   \                               4(b)
 *         4(r) 
 *
 */
void test_removeNextLargerSuccessor_with_3b_4r_should_return_4b(void){
  CEXCEPTION_T err;
  setNode(&node3, NULL, &node4, 'b');
  setNode(&node4, NULL, NULL, 'r');
  Node *removedNode, *parent = &node3;
  
  removedNode = removeNextLargerSuccessor(&parent);
  TEST_ASSERT_EQUAL_PTR(&node3, removedNode);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node4);


}

/** 3-node case
 *          root
 *          /     successor 5      root             
 *        v      -------->      /            
 *       12(b)                12(b)           
 *      /   \                    \
 *    5(r)  18(r)                18(r)
 *
 */
void test_removeNextLargerSuccessor_with_12b_5r_18r_should_return_12b_18r(void){
  CEXCEPTION_T err;
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node18, NULL, NULL, 'r');
  setNode(&node12, &node5, &node18, 'b');
  Node *removedNode, *parent = &node12;
  
  removedNode = removeNextLargerSuccessor(&parent);
  TEST_ASSERT_EQUAL_PTR(&node5, removedNode);
  TEST_ASSERT_EQUAL_NODE(NULL, &node18, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node18);


}

/** 5-node case
 *          root
 *          /     successor 1      root             
 *        v      -------->      /            
 *       12(b)                12(b)           
 *      /   \                /   \
 *    5(b)  18(b)         5(b)   18(b)
 *    /     /                    /
 *  1(r)   13(r)               13(r)
 *
 *
 */
void test_removeNextLargerSuccessor_with_12b_5b_18b_1r_13rshould_return_12b_18b_5b_13r(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node13, NULL, NULL, 'r');
  setNode(&node18, &node13, NULL, 'b');
  setNode(&node5, &node1, NULL, 'b');
  setNode(&node12, &node5, &node18, 'b');
  Node *removedNode, *parent = &node12;
  
  removedNode = removeNextLargerSuccessor(&parent);
  TEST_ASSERT_EQUAL_PTR(&node1, removedNode);
  TEST_ASSERT_EQUAL_NODE(&node5, &node18, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(&node13, NULL, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node13);

}

/** 5-node case
 *          root
 *          /     successor 1     root             
 *        v      -------->       /            
 *       12(b)                  12(b)           
 *      /   \                  /      \
 *    5(b)   18(b)           5(b)     18(b)
 *    /  \    /   \        /  \      /    \
 * 1(b) 7(b)13(b) 19(b)   2(b) 7(b) 13(b) 19(b)
 *   \
 *   2(r)
 */
void test_removeNextLargerSuccessor_with_1b_12b_5b_18b_1b_7b_13b_19b_2r_should_return_12b_5b_18b_7b_2r_13b_19b_2b(void){
  CEXCEPTION_T err;
  setNode(&node2, NULL, NULL, 'r');
  setNode(&node1, NULL, &node2, 'b');
  setNode(&node7, NULL, NULL, 'b');
  setNode(&node13, NULL, NULL, 'b');
  setNode(&node19, NULL, NULL, 'b');
  setNode(&node18, &node13, &node19, 'b');
  setNode(&node5, &node1, &node7, 'b');
  setNode(&node12, &node5, &node18, 'b');
  Node *removedNode, *parent = &node12;
  
  removedNode = removeNextLargerSuccessor(&parent);
  TEST_ASSERT_EQUAL_PTR(&node1, removedNode);
  TEST_ASSERT_EQUAL_NODE(&node5, &node18, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(&node13, &node19, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node19);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);

}

/** 6-node case
 *          root
 *          /     successor 1     root             
 *        v      -------->       /            
 *       12(b)                  12(d)           
 *      /   \                  /      \
 *    5(b)   18(b)           5(b)     18(r)
 *    /  \    /   \           \      /    \
 * 1(b) 7(b)13(b) 19(b)       7(r) 13(b) 19(b)
 *   
 */
void test_removeNextLargerSuccessor_with_1b_12b_5b_18b_1b_7b_13b_19b_should_return_12b_5b_18b_7b_13b_19b(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node7, NULL, NULL, 'b');
  setNode(&node13, NULL, NULL, 'b');
  setNode(&node19, NULL, NULL, 'b');
  setNode(&node18, &node13, &node19, 'b');
  setNode(&node5, &node1, &node7, 'b');
  setNode(&node12, &node5, &node18, 'b');
  Node *removedNode, *parent = &node12;
  
  removedNode = removeNextLargerSuccessor(&parent);
  TEST_ASSERT_EQUAL_PTR(&node1, removedNode);
  TEST_ASSERT_EQUAL_NODE(&node5, &node18, 'd', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(&node13, &node19, 'r', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node19);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);

}

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
  setNode(&node2, NULL, NULL, 'b');
  Node *root = &node1;
  
  Try {
    delRedBlackTree(&root, &node2);
    TEST_FAIL_MESSAGE("Expected ERR_NODE_UNAVAILABLE to be thrown. But receive none");
  } Catch(err){
    TEST_ASSERT_EQUAL_PTR(root, &node1);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  }
}

/** 2-node case
 *        root
 *        /       remove 1        root
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
  Node *newRoot;
  
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
  setNode(&node1, NULL, &node2, 'b');
  Node *root = &node1;
  
  delRedBlackTree(&root, &node2);
  TEST_ASSERT_EQUAL_PTR(root, &node1);

}

/** 2-node case
 *        root
 *        /       remove 1        root
 *       v        -------->       /
 *      2(b)                     v
 *      /                        2(b)
 *    1(r)
 *
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node2, &node1, NULL, 'b');
  Node *root = &node2;
  
  delRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, &node2);

}

/** 3-node case
 *        root
 *        /       remove 1        root
 *       v        -------->       /
 *      2(b)                     v
 *     /  \                     2(b)
 *   1(r)  3(r)                    \
 *                                 3(r)
 *
 *
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2b_and_3r(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node3, NULL, NULL, 'r');
  setNode(&node2, &node1, &node3, 'b');
  Node *root = &node2;
  
  delRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);

}

/** 3-node case
 *        root
 *        /       remove 1        root
 *       v        -------->       /
 *      2(b)                     v
 *     /  \                     2(b)
 *   1(b)  3(b)                    \
 *                                 3(r)
 *
 *
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2_and_3_with_black(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node2, &node1, &node3, 'b');
  Node *root = &node2;
  
  delRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);

}

/** 5-node case
 *        root
 *        /       remove 1        root
 *       v        -------->       /
 *      2(b)                     v
 *     /  \                     5(b)
 *   1(b)  5(r)                 /  \
 *        /   \               2(b)  6(b)
 *      3(b)  6(b)               \
 *                               3(r)
 */
void test_delRedBlackTree_remove_1_from_tree_rotate_left_with_root_2_3_5_6(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node6, NULL, NULL, 'b');
  setNode(&node5, &node3, &node6, 'r');
  setNode(&node2, &node1, &node5, 'b');
  Node *root = &node2;
  
  delRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, &node5);
  TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);

}

/** 5-node case
 *        root
 *        /       remove 3        root
 *       v        -------->       /
 *      2(b)                     v
 *     /  \                     2(b)
 *   1(b)  5(r)                 /  \
 *        /   \               1(b)  5(b)
 *      3(b)  6(b)                    \
 *                                     6(r)
 */
void test_delRedBlackTree_remove_3_from_tree_without_rotate_with_root_2_1_5_6(void){
  CEXCEPTION_T err;
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node6, NULL, NULL, 'b');
  setNode(&node5, &node3, &node6, 'r');
  setNode(&node2, &node1, &node5, 'b');
  Node *root = &node2;
  
  delRedBlackTree(&root, &node3);
  TEST_ASSERT_EQUAL_PTR(root, &node2);
  TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node6);

}

/** 5-node case
 *        root
 *        /       remove 6        root
 *       v        -------->       /
 *      2(b)                     v
 *     /  \                     2(b)
 *   1(b)  5(r)                 /  \
 *        /   \               1(b)  5(b)
 *      3(b)  6(b)                  /
 *                                3(r)
 */
void test_delRedBlackTree_remove_6_from_tree_without_rotate_with_root_2_1_5_3(void){
  CEXCEPTION_T err;
  setNode(&node6, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node5, &node3, &node6, 'r');
  setNode(&node2, &node1, &node5, 'b');
  Node *root = &node2;
  
  delRedBlackTree(&root, &node6);
  TEST_ASSERT_EQUAL_PTR(root, &node2);
  TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node3, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);

}

/** 7-node case
 *        root
 *        /       remove 1        root
 *       v        -------->       /
 *      4(b)                     v
 *     /    \                      4(b)
 *   2(r)    6(r)                 /    \
 *  /   \    /   \              2(b)   6(r)
 *1(b) 3(b) 5(b)  7(b)             \    /   \
 *                                3(r) 5(b) 7(b)
 *
 *
 *
 */
void test_delRedBlackTree_remove_1_from_tree_without_rotate_with_root_2_5_3_6_7_4(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node7, NULL, NULL, 'b');
  setNode(&node6, &node5, &node7, 'r');
  setNode(&node2, &node1, &node3, 'r');
  setNode(&node4, &node2, &node6, 'b');
  Node *root = &node4;
  
  delRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, &node4);
  TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, &node7, 'r', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);

}

/** 7-node case
 *        root
 *        /       remove 3        root
 *       v        -------->       /
 *      4(b)                     v
 *     /    \                      4(b)
 *   2(r)    6(r)                 /    \
 *  /   \    /   \              2(b)   6(r)
 *1(b) 3(b) 5(b)  7(b)          /      /   \
 *                            1(r)    5(b) 7(b)
 *
 *
 *
 */
void test_delRedBlackTree_remove_3_from_tree_without_rotate_with_root_2_5_1_6_7_4(void){
  CEXCEPTION_T err;
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node7, NULL, NULL, 'b');
  setNode(&node6, &node5, &node7, 'r');
  setNode(&node2, &node1, &node3, 'r');
  setNode(&node4, &node2, &node6, 'b');
  Node *root = &node4;
  
  delRedBlackTree(&root, &node3);
  TEST_ASSERT_EQUAL_PTR(root, &node4);
  TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, &node7, 'r', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);

}

/** 7-node case
 *        root
 *        /       remove 5        root
 *       v        -------->       /
 *      4(b)                     v
 *     /    \                      4(b)
 *   2(r)    6(r)                 /    \
 *  /   \    /   \              2(r)   6(b)
 *1(b) 3(b) 5(b)  7(b)          /   \      \
 *                            1(b)  3(b)   7(r)
 *
 *
 *
 */
void test_delRedBlackTree_remove_5_from_tree_without_rotate_with_root_2_3_1_6_7_4(void){
  CEXCEPTION_T err;
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node7, NULL, NULL, 'b');
  setNode(&node6, &node5, &node7, 'r');
  setNode(&node2, &node1, &node3, 'r');
  setNode(&node4, &node2, &node6, 'b');
  Node *root = &node4;
  
  delRedBlackTree(&root, &node5);
  TEST_ASSERT_EQUAL_PTR(root, &node4);
  TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'r', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);

}

/** 7-node case
 *        root
 *        /       remove 7        root
 *       v        -------->       /
 *      4(b)                     v
 *     /    \                      4(b)
 *   2(r)    6(r)                 /    \
 *  /   \    /   \              2(r)    6(b)
 *1(b) 3(b) 5(b)  7(b)          /  \    /
 *                            1(b) 3(b)5(r)
 *
 *
 *
 */
void test_delRedBlackTree_remove_7_from_tree_without_rotate_with_root_2_3_1_6_5_4(void){
  CEXCEPTION_T err;
  setNode(&node7, NULL, NULL, 'b');
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node6, &node5, &node7, 'r');
  setNode(&node2, &node1, &node3, 'r');
  setNode(&node4, &node2, &node6, 'b');
  Node *root = &node4;
  
  delRedBlackTree(&root, &node7);
  TEST_ASSERT_EQUAL_PTR(root, &node4);
  TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'r', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', &node6);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);

}

/** 2-node case
 *        root
 *        /       remove 3        	root
 *       v        -------->       	/
 *      3(b)                   	   v
 *     /                          1(b)
 *   1(r)                  
 *
 *
 *
 */
void test_delRedBlackTree_removeNextLargerSuccessor_3_from_tree_3b_1r(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node3, &node1, NULL, 'b');
  Node *root = &node3;
  
  delRedBlackTree(&root, &node3);
  TEST_ASSERT_EQUAL_PTR(root, &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);

}

/** 2-node case
 *        root
 *        /       remove 3        	root
 *       v        -------->       	/
 *      3(b)                   	   v
 *         \                      5(b)
 *          5(r)                  
 *
 *
 *
 */
void test_delRedBlackTree_removeNextLargerSuccessor_3_from_tree_3b_5r(void){
  CEXCEPTION_T err;
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node3, NULL, &node5, 'b');
  Node *root = &node3;
  
  delRedBlackTree(&root, &node3);
  TEST_ASSERT_EQUAL_PTR(root, &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);

}

/** 7-node case
 *        root
 *        /       remove 24        	root
 *       v        -------->       	/
 *      18(b)                   	   v
 *     /    \                      18(b)
 *   12(b)  	24(b)                 /    \
 *  /   \    /    \              12(r)  	25(b)
 *10(b)13(b)20(b)  25(b)         /  \   	 /
 *                            10(b) 13(b)20(r)
 *
 *
 *
 */
void test_delRedBlackTree_case2a_removeNextLargerSuccessor_24_from_tree_18b_12r_24b_10b_13b_20b_25b(void){
  CEXCEPTION_T err;
  setNode(&node24, &node20, &node25, 'b');
  setNode(&node10, NULL, NULL, 'b');
  setNode(&node13, NULL, NULL, 'b');
  setNode(&node20, NULL, NULL, 'b');
  setNode(&node25, NULL, NULL, 'b');
  setNode(&node12, &node10, &node13, 'b');
  setNode(&node18, &node12, &node24, 'b');
  Node *root = &node18;
  
  delRedBlackTree(&root, &node24);
  TEST_ASSERT_EQUAL_PTR(root, &node18);
  TEST_ASSERT_EQUAL_NODE(&node12, &node25, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(&node10, &node13, 'r', &node12);
  TEST_ASSERT_EQUAL_NODE(&node20, NULL, 'b', &node25);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);

}

/** 7-node case
 *        root
 *        /       remove 24        	root
 *       v        -------->       	/
 *      18(b)                   	   v
 *     /    \                      18(b)
 *   12(b)  	24(r)                 /    \
 *  /   \    /    \              12(b)  	25(b)
 *10(r)13(r)20(b)  25(b)         /  \   	 /
 *                            10(r) 13(r)20(r)
 *
 */
void test_delRedBlackTree_case2b_removeNextLargerSuccessor_24_from_tree_18b_12r_24r_10b_13b_20b_25b(void){
  CEXCEPTION_T err;
  setNode(&node24, &node20, &node25, 'r');
  setNode(&node10, NULL, NULL, 'r');
  setNode(&node13, NULL, NULL, 'r');
  setNode(&node20, NULL, NULL, 'b');
  setNode(&node25, NULL, NULL, 'b');
  setNode(&node12, &node10, &node13, 'b');
  setNode(&node18, &node12, &node24, 'b');
  Node *root = &node18;
  
  delRedBlackTree(&root, &node24);
  TEST_ASSERT_EQUAL_PTR(root, &node18);
  TEST_ASSERT_EQUAL_NODE(&node12, &node25, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(&node10, &node13, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(&node20, NULL, 'b', &node25);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);

}

/** 9-node case
 *        root
 *        /       remove 24        	root
 *       v        -------->       	/
 *      18(b)                   	   v
 *     /    \                        18(b)
 *   12(b)  	24(b)                 /     \
 *  /   \    /    \              12(b)  	 26(b)
 *10(b)13(b)20(b)  30(b)         /  \   	 /    \
 *                 /          10(b) 13(b)20(b)  30(b)
 *               28(b)                          /
 *               /                            28(b)
 *             26(r)                          
 *                      
 *
 */
void test_delRedBlackTree_case1a_removeNextLargerSuccessor_24_from_tree_18b_12r_24b_10b_13b_20b_26r_28b_30b(void){
  CEXCEPTION_T err;
  setNode(&node24, &node20, &node30, 'b');
  setNode(&node10, NULL, NULL, 'b');
  setNode(&node13, NULL, NULL, 'b');
  setNode(&node20, NULL, NULL, 'b');
  setNode(&node26, NULL, NULL, 'r');
  setNode(&node28, &node26, NULL, 'b');
  setNode(&node30, &node28, NULL, 'b');
  setNode(&node12, &node10, &node13, 'b');
  setNode(&node18, &node12, &node24, 'b');
  Node *root = &node18;
  
  delRedBlackTree(&root, &node24);
  TEST_ASSERT_EQUAL_PTR(root, &node18);
  TEST_ASSERT_EQUAL_NODE(&node12, &node26, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(&node10, &node13, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(&node20, &node30, 'b', &node26);
  TEST_ASSERT_EQUAL_NODE(&node28, NULL, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node28);

}

/** 8-node case
 *        root
 *        /       remove 10        	root
 *       v        -------->       	/
 *      18(b)                   	   v
 *     /    \                        18(b)
 *   12(b)  	24(b)                 /     \
 *  /   \    /    \              12(b)  	 24(b)
 *10(b)13(b)20(b)  30(b)         /  \   	 /    \
 *  \                         11(b) 13(b)20(b)  30(b)
 *   11(r)                           
 *                      
 *
 */
void test_delRedBlackTree_case1b_removeNextLargerSuccessor_10_from_tree_18b_12r_24b_10b_13b_20b_11b_30b(void){
  CEXCEPTION_T err;
  setNode(&node10, NULL, &node11, 'b');
  setNode(&node24, &node20, &node30, 'b');
  setNode(&node13, NULL, NULL, 'b');
  setNode(&node20, NULL, NULL, 'b');
  setNode(&node11, NULL, NULL, 'r');
  setNode(&node30, NULL, NULL, 'b');
  setNode(&node12, &node10, &node13, 'b');
  setNode(&node18, &node12, &node24, 'b');
  Node *root = &node18;
  
  delRedBlackTree(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(root, &node18);
  TEST_ASSERT_EQUAL_NODE(&node12, &node24, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(&node11, &node13, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(&node20, &node30, 'b', &node24);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node11);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);


}

/** 4-node case
 *       root              root
 *       /    remove 20    /
 *       v   ------->      v
 *      10(b)             10(b)
 *     /   \              /   \             10(b)
 *   5(b)  20(b)        5(b) 30(r)     =>   /   \
 *           \                            5(b)  30(b)
 *           30(r)                 
 */
void test_delRedBlackTree_case1a_removeNextLargerSuccessor_20_from_tree_10b_5b_20b_30r(void){
  setNode(&node20, NULL, &node30, 'b');
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node30, NULL, NULL, 'r');
  setNode(&node10, &node5, &node20, 'b');
  Node *root = &node10;
  
  delRedBlackTree(&root, &node20);
  TEST_ASSERT_EQUAL_PTR(root, &node10);
  TEST_ASSERT_EQUAL_NODE(&node5, &node30, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);

}

/** Failed Function Test delete node 2 to be complete
 *                                    20(b)
 *                                      |
 *                 10(b)----------------+-----------------26(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                22(b)------+------30(b)
 *        |                    |                    |                |
 *  2(b)-+--7(b)       12(b)--+---18(b)     21(b)--+--23(b)  28(b)--+--32(b)
 *    /      /  \        /          /  \                 \      \        /
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)            25(r)  29(r)   31(r)
 *
 *
 */
void test_delRedBlackTree_del_node_2(void){
  CEXCEPTION_T err;
  setNode(&node20, &node10, &node26, 'b');
  setNode(&node10, &node3, &node13, 'b');
  setNode(&node26, &node22, &node30, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node13, &node12, &node18, 'b');
  setNode(&node22, &node21, &node23, 'b');
  setNode(&node30, &node28, &node32, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node12, &node11, NULL, 'b');
  setNode(&node18, &node15, &node19, 'b');
  setNode(&node21, NULL, NULL, 'b');
  setNode(&node23, NULL, &node25, 'b');
  setNode(&node28, NULL, &node29, 'b');
  setNode(&node32, &node31, NULL, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node11, NULL, NULL, 'r');
  setNode(&node15, NULL, NULL, 'r');
  setNode(&node19, NULL, NULL, 'r');
  setNode(&node25, NULL, NULL, 'r');
  setNode(&node29, NULL, NULL, 'r');
  setNode(&node31, NULL, NULL, 'r');
  Node *root = &node20;
  
  delRedBlackTree(&root, &node2);
  TEST_ASSERT_EQUAL_PTR(root, &node20);
  TEST_ASSERT_EQUAL_NODE(&node3, &node13, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(&node22, &node30, 'b', &node26);
  TEST_ASSERT_EQUAL_NODE(&node1, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  
  TEST_ASSERT_EQUAL_NODE(&node12, &node18, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(&node11, NULL, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node11);
  TEST_ASSERT_EQUAL_NODE(&node15, &node19, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node19);
  
  TEST_ASSERT_EQUAL_NODE(&node21, &node23, 'b', &node22);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node21);
  TEST_ASSERT_EQUAL_NODE(NULL, &node25, 'b', &node23);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node25);
  
  TEST_ASSERT_EQUAL_NODE(&node28, &node32, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, &node29, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(&node31, NULL, 'b', &node32);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node29);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node31);

}

/** Failed Function Test delete node 12 to be complete
 *                                    20(b)
 *                                      |
 *                 10(b)----------------+-----------------26(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                22(b)------+------30(b)
 *        |                    |                    |                |
 *  2(b)-+--7(b)       12(b)--+---18(b)     21(b)--+--23(b)  28(b)--+--32(b)
 *    /      /  \        /          /  \                 \      \        /
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)            25(r)  29(r)   31(r)
 *
 *
 */
void test_delRedBlackTree_del_node_12(void){
  CEXCEPTION_T err;
  setNode(&node20, &node10, &node26, 'b');
  setNode(&node10, &node3, &node13, 'b');
  setNode(&node26, &node22, &node30, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node13, &node12, &node18, 'b');
  setNode(&node22, &node21, &node23, 'b');
  setNode(&node30, &node28, &node32, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node12, &node11, NULL, 'b');
  setNode(&node18, &node15, &node19, 'b');
  setNode(&node21, NULL, NULL, 'b');
  setNode(&node23, NULL, &node25, 'b');
  setNode(&node28, NULL, &node29, 'b');
  setNode(&node32, &node31, NULL, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node11, NULL, NULL, 'r');
  setNode(&node15, NULL, NULL, 'r');
  setNode(&node19, NULL, NULL, 'r');
  setNode(&node25, NULL, NULL, 'r');
  setNode(&node29, NULL, NULL, 'r');
  setNode(&node31, NULL, NULL, 'r');
  Node *root = &node20;
  
  delRedBlackTree(&root, &node12);
  TEST_ASSERT_EQUAL_PTR(root, &node20);
  TEST_ASSERT_EQUAL_NODE(&node3, &node13, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(&node22, &node30, 'b', &node26);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  
  TEST_ASSERT_EQUAL_NODE(&node11, &node18, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node11);
  TEST_ASSERT_EQUAL_NODE(&node15, &node19, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node19);
  
  TEST_ASSERT_EQUAL_NODE(&node21, &node23, 'b', &node22);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node21);
  TEST_ASSERT_EQUAL_NODE(NULL, &node25, 'b', &node23);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node25);
  
  TEST_ASSERT_EQUAL_NODE(&node28, &node32, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, &node29, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(&node31, NULL, 'b', &node32);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node29);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node31);

}

/** Failed Function Test delete node 32 to be complete
 *                                    20(b)
 *                                      |
 *                 10(b)----------------+-----------------26(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                22(b)------+------30(b)
 *        |                    |                    |                |
 *  2(b)-+--7(b)       12(b)--+---18(b)     21(b)--+--23(b)  28(b)--+--32(b)
 *    /      /  \        /          /  \                 \      \        /
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)            25(r)  29(r)   31(r)
 *
 *
 */
void test_delRedBlackTree_del_node_32(void){
  CEXCEPTION_T err;
  setNode(&node20, &node10, &node26, 'b');
  setNode(&node10, &node3, &node13, 'b');
  setNode(&node26, &node22, &node30, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node13, &node12, &node18, 'b');
  setNode(&node22, &node21, &node23, 'b');
  setNode(&node30, &node28, &node32, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node12, &node11, NULL, 'b');
  setNode(&node18, &node15, &node19, 'b');
  setNode(&node21, NULL, NULL, 'b');
  setNode(&node23, NULL, &node25, 'b');
  setNode(&node28, NULL, &node29, 'b');
  setNode(&node32, &node31, NULL, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node11, NULL, NULL, 'r');
  setNode(&node15, NULL, NULL, 'r');
  setNode(&node19, NULL, NULL, 'r');
  setNode(&node25, NULL, NULL, 'r');
  setNode(&node29, NULL, NULL, 'r');
  setNode(&node31, NULL, NULL, 'r');
  Node *root = &node20;
  
  delRedBlackTree(&root, &node32);
  TEST_ASSERT_EQUAL_PTR(root, &node20);
  TEST_ASSERT_EQUAL_NODE(&node3, &node13, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(&node22, &node30, 'b', &node26);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  
  TEST_ASSERT_EQUAL_NODE(&node12, &node18, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(&node11, NULL, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node11);
  TEST_ASSERT_EQUAL_NODE(&node15, &node19, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node19);
  
  TEST_ASSERT_EQUAL_NODE(&node21, &node23, 'b', &node22);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node21);
  TEST_ASSERT_EQUAL_NODE(NULL, &node25, 'b', &node23);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node25);
  
  TEST_ASSERT_EQUAL_NODE(&node28, &node31, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, &node29, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node31);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node29);

}

/** Failed Function Test delete node 1 by 1 20 to be complete
 *                                    20(b)
 *                                      |
 *                 10(b)----------------+-----------------26(b)
 *
 *
 */
void test_delRedBlackTree_del_node_1_by_1_20(void){
  CEXCEPTION_T err;
  setNode(&node20, &node10, &node26, 'b');
  setNode(&node10, NULL, NULL, 'b');
  setNode(&node26, NULL, NULL, 'b');
  Node *root = &node20;
  
  delRedBlackTree(&root, &node20);
  TEST_ASSERT_EQUAL_PTR(root, &node26);
  TEST_ASSERT_EQUAL_NODE(&node10, NULL, 'b', &node26);
  
}

/** Failed Function Test delete node 1 by 1 (20)to be complete
 *                                    20(b)
 *                                      |
 *                 10(b)----------------+-----------------26(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                22(b)------+------30(b)
 *        |                    |                    |                |
 *  2(b)-+--7(b)       12(b)--+---18(b)     21(b)--+--23(b)  28(b)--+--32(b)
 *    /      /  \        /          /  \                 \      \        /
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)            25(r)  29(r)   31(r)
 *
 *
 */
void test_delRedBlackTree_del_node_first_node(void){
  CEXCEPTION_T err;
  setNode(&node20, &node10, &node26, 'b');
  setNode(&node10, &node3, &node13, 'b');
  setNode(&node26, &node22, &node30, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node13, &node12, &node18, 'b');
  setNode(&node22, &node21, &node23, 'b');
  setNode(&node30, &node28, &node32, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node12, &node11, NULL, 'b');
  setNode(&node18, &node15, &node19, 'b');
  setNode(&node21, NULL, NULL, 'b');
  setNode(&node23, NULL, &node25, 'b');
  setNode(&node28, NULL, &node29, 'b');
  setNode(&node32, &node31, NULL, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node11, NULL, NULL, 'r');
  setNode(&node15, NULL, NULL, 'r');
  setNode(&node19, NULL, NULL, 'r');
  setNode(&node25, NULL, NULL, 'r');
  setNode(&node29, NULL, NULL, 'r');
  setNode(&node31, NULL, NULL, 'r');
  Node *root = &node20;
  
  delRedBlackTree(&root, &node20);
  TEST_ASSERT_EQUAL_PTR(root, &node21);
  TEST_ASSERT_EQUAL_NODE(&node10, &node26, 'b', &node21);
  TEST_ASSERT_EQUAL_NODE(&node3, &node13, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(&node23, &node30, 'b', &node26);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  
  TEST_ASSERT_EQUAL_NODE(&node12, &node18, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(&node11, NULL, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node11);
  TEST_ASSERT_EQUAL_NODE(&node15, &node19, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node19);
  
  TEST_ASSERT_EQUAL_NODE(&node22, &node25, 'b', &node23);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node22);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
  
  TEST_ASSERT_EQUAL_NODE(&node28, &node32, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, &node29, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(&node31, NULL, 'b', &node32);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node29);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node31);

}

/** Failed Function Test delete node 1 by 1 (21) full to be complete
 *                                    21(b)
 *                                      |
 *                 10(b)----------------+-----------------26(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                23(b)------+------30(b)
 *        |                    |                    |                |
 *  2(b)-+--7(b)       12(b)--+---18(b)     22(b)--+--25(b)  28(b)--+--32(b)
 *    /      /  \        /          /  \                        \        /
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)                   29(r)   31(r)
 *
 *
 *
 *
 *
 *                                    22(b)
 *                                      |
 *                 10(r)----------------+-----------------26(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                23(b)------+------30(r)
 *        |                    |                    |                |
 *  2(b)-+--7(b)       12(b)--+---18(b)            +--25(r)  28(b)--+--32(b)
 *    /      /  \        /          /  \                        \        /
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)                   29(r)   31(r)
 *
 *
 */
void test_delRedBlackTree_del_node_second_node(void){
  CEXCEPTION_T err;
  setNode(&node21, &node10, &node26, 'b');
  setNode(&node10, &node3, &node13, 'b');
  setNode(&node26, &node23, &node30, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node13, &node12, &node18, 'b');
  setNode(&node23, &node22, &node25, 'b');
  setNode(&node30, &node28, &node32, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node12, &node11, NULL, 'b');
  setNode(&node18, &node15, &node19, 'b');
  setNode(&node22, NULL, NULL, 'b');
  setNode(&node25, NULL, NULL, 'b');
  setNode(&node28, NULL, &node29, 'b');
  setNode(&node32, &node31, NULL, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node11, NULL, NULL, 'r');
  setNode(&node15, NULL, NULL, 'r');
  setNode(&node19, NULL, NULL, 'r');
  setNode(&node29, NULL, NULL, 'r');
  setNode(&node31, NULL, NULL, 'r');
  Node *root = &node21;
  
  delRedBlackTree(&root, &node21);
  TEST_ASSERT_EQUAL_PTR(root, &node22);
  TEST_ASSERT_EQUAL_NODE(&node10, &node26, 'b', &node22);
  TEST_ASSERT_EQUAL_NODE(&node3, &node13, 'r', &node10);
  TEST_ASSERT_EQUAL_NODE(&node23, &node30, 'b', &node26);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  
  TEST_ASSERT_EQUAL_NODE(&node12, &node18, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(&node11, NULL, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node11);
  TEST_ASSERT_EQUAL_NODE(&node15, &node19, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node19);
  
  TEST_ASSERT_EQUAL_NODE(NULL, &node25, 'b', &node23);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node25);
  
  TEST_ASSERT_EQUAL_NODE(&node28, &node32, 'r', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, &node29, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(&node31, NULL, 'b', &node32);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node29);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node31);

}

/** Failed Function Test delete node 1 by 1 (22) full to be complete
 *
 *
 *                                    22(b)
 *                                      |
 *                 10(r)----------------+-----------------26(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                23(b)------+------30(r)
 *        |                    |                    |                |
 *  2(b)-+--7(b)       12(b)--+---18(b)            +--25(r)  28(b)--+--32(b)
 *    /      /  \        /          /  \                        \        /
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)                   29(r)   31(r)
 *
 *
 *
 *                                    23(b)
 *                                      |
 *                 10(r)----------------+-----------------26(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                25(b)------+------30(r)
 *        |                    |                                     |
 *  2(b)-+--7(b)       12(b)--+---18(b)                      28(b)--+--32(b)
 *    /      /  \        /          /  \                        \        /
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)                   29(r)   31(r)
 *
 *
 *
 */
void test_delRedBlackTree_del_node_third_node(void){
  CEXCEPTION_T err;
  setNode(&node22, &node10, &node26, 'b');
  setNode(&node10, &node3, &node13, 'r');
  setNode(&node26, &node23, &node30, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node13, &node12, &node18, 'b');
  setNode(&node23, NULL, &node25, 'b');
  setNode(&node30, &node28, &node32, 'r');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node12, &node11, NULL, 'b');
  setNode(&node18, &node15, &node19, 'b');
  setNode(&node25, NULL, NULL, 'r');
  setNode(&node28, NULL, &node29, 'b');
  setNode(&node32, &node31, NULL, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node11, NULL, NULL, 'r');
  setNode(&node15, NULL, NULL, 'r');
  setNode(&node19, NULL, NULL, 'r');
  setNode(&node29, NULL, NULL, 'r');
  setNode(&node31, NULL, NULL, 'r');
  Node *root = &node22;
  
  delRedBlackTree(&root, &node22);
  TEST_ASSERT_EQUAL_PTR(root, &node23);
  TEST_ASSERT_EQUAL_NODE(&node10, &node26, 'b', &node23);
  TEST_ASSERT_EQUAL_NODE(&node3, &node13, 'r', &node10);
  TEST_ASSERT_EQUAL_NODE(&node25, &node30, 'b', &node26);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  
  TEST_ASSERT_EQUAL_NODE(&node12, &node18, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(&node11, NULL, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node11);
  TEST_ASSERT_EQUAL_NODE(&node15, &node19, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node19);
  
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
  
  TEST_ASSERT_EQUAL_NODE(&node28, &node32, 'r', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, &node29, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(&node31, NULL, 'b', &node32);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node29);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node31);

}

/** Failed Function Test delete node 1 by 1 (23) full to be complete
 *
 *                                    23(b)
 *                                      |
 *                 10(r)----------------+-----------------26(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                25(b)------+------30(r)
 *        |                    |                                     |
 *  2(b)-+--7(b)       12(b)--+---18(b)                      28(b)--+--32(b)
 *    /      /  \        /          /  \                        \        /
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)                   29(r)   31(r)
 *
 *
 *
 *                                    25(b)
 *                                      |
 *                 10(r)----------------+-----------------30(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                28(r)------+------32(b)
 *        |                    |                   |                 |
 *  2(b)--+--7(b)      12(b)--+---18(b)    26(b)--+--29(b)   31(r)--+
 *    /      /  \        /          /  \                     
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)         
 *
 *
 *
 */
void test_delRedBlackTree_del_node_forth_node(void){
  CEXCEPTION_T err;
  setNode(&node23, &node10, &node26, 'b');
  setNode(&node10, &node3, &node13, 'r');
  setNode(&node26, &node25, &node30, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node13, &node12, &node18, 'b');
  setNode(&node25, NULL, NULL, 'b');
  setNode(&node30, &node28, &node32, 'r');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node12, &node11, NULL, 'b');
  setNode(&node18, &node15, &node19, 'b');
  setNode(&node28, NULL, &node29, 'b');
  setNode(&node32, &node31, NULL, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node11, NULL, NULL, 'r');
  setNode(&node15, NULL, NULL, 'r');
  setNode(&node19, NULL, NULL, 'r');
  setNode(&node29, NULL, NULL, 'r');
  setNode(&node31, NULL, NULL, 'r');
  Node *root = &node23;
  
  delRedBlackTree(&root, &node23);
  TEST_ASSERT_EQUAL_PTR(root, &node25);
  TEST_ASSERT_EQUAL_NODE(&node10, &node30, 'b', &node25);
  TEST_ASSERT_EQUAL_NODE(&node3, &node13, 'r', &node10);
  TEST_ASSERT_EQUAL_NODE(&node28, &node32, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  
  TEST_ASSERT_EQUAL_NODE(&node12, &node18, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(&node11, NULL, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node11);
  TEST_ASSERT_EQUAL_NODE(&node15, &node19, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node19);
  
  TEST_ASSERT_EQUAL_NODE(&node26, &node29, 'r', &node28);
  
  TEST_ASSERT_EQUAL_NODE(&node31, NULL, 'b', &node32);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node26);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node29);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node31);

}

/** Failed Function Test delete node 1 by 1 (25) full to be complete
 *
 *                                    25(b)
 *                                      |
 *                 10(r)----------------+-----------------30(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                28(r)------+------32(b)
 *        |                    |                   |                 |
 *  2(b)--+--7(b)      12(b)--+---18(b)    26(b)--+--29(b)   31(r)--+
 *    /      /  \        /          /  \                     
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)         
 *
 *
 *                                    26(b)
 *                                      |
 *                 10(r)----------------+-----------------30(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                28(b)------+------32(b)
 *        |                    |                   |                 |
 *  2(b)--+--7(b)      12(b)--+---18(b)           +--29(r)   31(r)--+
 *    /      /  \        /          /  \                     
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)         
 *
 *
 *
 */
void test_delRedBlackTree_del_node_fifth_node(void){
  CEXCEPTION_T err;
  setNode(&node25, &node10, &node30, 'b');
  setNode(&node10, &node3, &node13, 'r');
  setNode(&node30, &node28, &node32, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node13, &node12, &node18, 'b');
  setNode(&node28, &node26, &node29, 'r');
  setNode(&node32, &node31, NULL, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node12, &node11, NULL, 'b');
  setNode(&node18, &node15, &node19, 'b');
  setNode(&node26, NULL, NULL, 'b');
  setNode(&node29, NULL, NULL, 'b');
  setNode(&node31, NULL, NULL, 'r');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node11, NULL, NULL, 'r');
  setNode(&node15, NULL, NULL, 'r');
  setNode(&node19, NULL, NULL, 'r');

  Node *root = &node25;
  
  delRedBlackTree(&root, &node25);
  TEST_ASSERT_EQUAL_PTR(root, &node26);
  TEST_ASSERT_EQUAL_NODE(&node10, &node30, 'b', &node26);
  TEST_ASSERT_EQUAL_NODE(&node3, &node13, 'r', &node10);
  TEST_ASSERT_EQUAL_NODE(&node28, &node32, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  
  TEST_ASSERT_EQUAL_NODE(&node12, &node18, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(&node11, NULL, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node11);
  TEST_ASSERT_EQUAL_NODE(&node15, &node19, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node19);
  
  TEST_ASSERT_EQUAL_NODE(NULL, &node29, 'b', &node28);
  
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node29);
  TEST_ASSERT_EQUAL_NODE(&node31, NULL, 'b', &node32);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node31);

}

/** Failed Function Test delete node 1 by 1 (26) full to be complete
 *
 *                                    26(b)
 *                                      |
 *                 10(r)----------------+-----------------30(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                28(b)------+------32(b)
 *        |                    |                   |                 |
 *  2(b)--+--7(b)      12(b)--+---18(b)           +--29(r)   31(r)--+
 *    /      /  \        /          /  \                     
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)         
 *
 *
 *                                    28(b)
 *                                      |
 *                 10(r)----------------+-----------------30(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                29(b)------+------32(b)
 *        |                    |                                     |
 *  2(b)--+--7(b)      12(b)--+---18(b)                      31(r)--+
 *    /      /  \        /          /  \                     
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)         
 *
 *
 *
 */
void test_delRedBlackTree_del_node_sixth_node(void){
  CEXCEPTION_T err;
  setNode(&node26, &node10, &node30, 'b');
  setNode(&node10, &node3, &node13, 'r');
  setNode(&node30, &node28, &node32, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node13, &node12, &node18, 'b');
  setNode(&node28, NULL, &node29, 'b');
  setNode(&node32, &node31, NULL, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node12, &node11, NULL, 'b');
  setNode(&node18, &node15, &node19, 'b');
  setNode(&node29, NULL, NULL, 'r');
  setNode(&node31, NULL, NULL, 'r');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node11, NULL, NULL, 'r');
  setNode(&node15, NULL, NULL, 'r');
  setNode(&node19, NULL, NULL, 'r');

  Node *root = &node26;
  
  delRedBlackTree(&root, &node26);
  TEST_ASSERT_EQUAL_PTR(root, &node28);
  TEST_ASSERT_EQUAL_NODE(&node10, &node30, 'b', &node28);
  TEST_ASSERT_EQUAL_NODE(&node3, &node13, 'r', &node10);
  TEST_ASSERT_EQUAL_NODE(&node29, &node32, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  
  TEST_ASSERT_EQUAL_NODE(&node12, &node18, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(&node11, NULL, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node11);
  TEST_ASSERT_EQUAL_NODE(&node15, &node19, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node19);
  
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node29);
  
  TEST_ASSERT_EQUAL_NODE(&node31, NULL, 'b', &node32);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node31);

}

/** Failed Function Test delete node 1 by 1 (28) full to be complete
 *
 *                                    28(b)
 *                                      |
 *                 10(r)----------------+-----------------30(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                29(b)------+------32(b)
 *        |                    |                                     |
 *  2(b)--+--7(b)      12(b)--+---18(b)                      31(r)--+
 *    /      /  \        /          /  \                     
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)         
 *
 *
 *                                    29(b)
 *                                      |
 *                 10(r)----------------+-----------------31(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                30(b)------+------32(b)
 *        |                    |                                    
 *  2(b)--+--7(b)      12(b)--+---18(b)                     
 *    /      /  \        /          /  \                     
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)  
 *
 */
void test_delRedBlackTree_del_node_seventh_node(void){
  CEXCEPTION_T err;
  setNode(&node28, &node10, &node30, 'b');
  setNode(&node10, &node3, &node13, 'r');
  setNode(&node30, &node29, &node32, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node13, &node12, &node18, 'b');
  setNode(&node29, NULL, NULL, 'b');
  setNode(&node32, &node31, NULL, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node12, &node11, NULL, 'b');
  setNode(&node18, &node15, &node19, 'b');
  setNode(&node31, NULL, NULL, 'r');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node11, NULL, NULL, 'r');
  setNode(&node15, NULL, NULL, 'r');
  setNode(&node19, NULL, NULL, 'r');

  Node *root = &node28;
  
  delRedBlackTree(&root, &node28);
  TEST_ASSERT_EQUAL_PTR(root, &node29);
  TEST_ASSERT_EQUAL_NODE(&node10, &node31, 'b', &node29);
  TEST_ASSERT_EQUAL_NODE(&node3, &node13, 'r', &node10);
  TEST_ASSERT_EQUAL_NODE(&node30, &node32, 'b', &node31);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  
  TEST_ASSERT_EQUAL_NODE(&node12, &node18, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(&node11, NULL, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node11);
  TEST_ASSERT_EQUAL_NODE(&node15, &node19, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node19);
  
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node32);

}

/** Failed Function Test delete node 1 by 1 (29) full to be complete
 *
 *                                    29(b)
 *                                      |
 *                 10(r)----------------+-----------------31(b)
 *                  |                                       |
 *      3(b)--------+-------13(b)                30(b)------+------32(b)
 *        |                    |                                    
 *  2(b)--+--7(b)      12(b)--+---18(b)                     
 *    /      /  \        /          /  \                     
 * 1(r)   5(r) 8(r)   11(r)     15(r) 19(r)  
 *
 *
 *                                    10(b)
 *                                      |
 *                 3(b)-----------------+-----------------30(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                 13(r)------+------31(b)
 *        /                /  \                       |                | 
 *      1(r)              5(r) 8(r)           12(b)---+---18(b)        +--32(r)
 *                                               /          /  \
 *                                            11(r)      15(r) 19(r)
 *                                  
 *
 */
void test_delRedBlackTree_del_node_eighth_node(void){
  CEXCEPTION_T err;
  setNode(&node29, &node10, &node31, 'b');
  setNode(&node10, &node3, &node13, 'r');
  setNode(&node31, &node30, &node32, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node13, &node12, &node18, 'b');
  setNode(&node30, NULL, NULL, 'b');
  setNode(&node32, NULL, NULL, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node12, &node11, NULL, 'b');
  setNode(&node18, &node15, &node19, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node11, NULL, NULL, 'r');
  setNode(&node15, NULL, NULL, 'r');
  setNode(&node19, NULL, NULL, 'r');

  Node *root = &node29;
  
  delRedBlackTree(&root, &node29);
  TEST_ASSERT_EQUAL_PTR(root, &node10);
  TEST_ASSERT_EQUAL_NODE(&node3, &node30, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node13, &node31, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node12, &node18, 'r', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, &node32, 'b', &node31);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  
  TEST_ASSERT_EQUAL_NODE(&node11, NULL, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node11);
  TEST_ASSERT_EQUAL_NODE(&node15, &node19, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node19);

  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node32);

}

/** Failed Function Test delete node 1 by 1 (10) full to be complete
 *
 *                                    10(b)
 *                                      |
 *                 3(b)-----------------+-----------------30(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                 13(r)------+------31(b)
 *        /                /  \                       |                | 
 *      1(r)              5(r) 8(r)           12(b)---+---18(b)        +--32(r)
 *                                               /          /  \
 *                                            11(r)      15(r) 19(r)
 *                                  
 *
 *                                    11(b)
 *                                      |
 *                 3(b)-----------------+-----------------30(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                 13(r)------+------31(b)
 *        /                /  \                       |                | 
 *      1(r)              5(r) 8(r)           12(b)---+---18(b)        +--32(r)
 *                                                          /  \
 *                                                       15(r) 19(r)
 *
 */
void test_delRedBlackTree_del_node_ninth_node(void){
  CEXCEPTION_T err;
  setNode(&node10, &node3, &node30, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node30, &node13, &node31, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node13, &node12, &node18, 'r');
  setNode(&node31, NULL, &node32, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node12, &node11, NULL, 'b');
  setNode(&node18, &node15, &node19, 'b');
  setNode(&node32, NULL, NULL, 'r');
  setNode(&node11, NULL, NULL, 'r');
  setNode(&node15, NULL, NULL, 'r');
  setNode(&node19, NULL, NULL, 'r');

  Node *root = &node10;
  
  delRedBlackTree(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(root, &node11);
  TEST_ASSERT_EQUAL_NODE(&node3, &node30, 'b', &node11);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node13, &node31, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node12, &node18, 'r', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, &node32, 'b', &node31);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(&node15, &node19, 'b', &node18);
  
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node19);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node32);

}

/** Failed Function Test delete node 1 by 1 (11) full to be complete
 *                            
 *
 *                                    11(b)
 *                                      |
 *                 3(b)-----------------+-----------------30(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                 13(r)------+------31(b)
 *        /                /  \                       |                | 
 *      1(r)              5(r) 8(r)           12(b)---+---18(b)        +--32(r)
 *                                                          /  \
 *                                                       15(r) 19(r)
 *
 *
 *                                    12(b)
 *                                      |
 *                 3(b)-----------------+-----------------30(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                 18(r)------+------31(b)
 *        /                /  \                       |                | 
 *      1(r)              5(r) 8(r)           13(b)---+---19(b)        +--32(r)
 *                                                \            
 *                                              15(r)     
 *
 */
void test_delRedBlackTree_del_node_tenth_node(void){
  CEXCEPTION_T err;
  setNode(&node11, &node3, &node30, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node30, &node13, &node31, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node13, &node12, &node18, 'r');
  setNode(&node31, NULL, &node32, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node12, NULL, NULL, 'b');
  setNode(&node18, &node15, &node19, 'b');
  setNode(&node32, NULL, NULL, 'r');
  setNode(&node15, NULL, NULL, 'r');
  setNode(&node19, NULL, NULL, 'r');

  Node *root = &node11;
  
  delRedBlackTree(&root, &node11);
  TEST_ASSERT_EQUAL_PTR(root, &node12);
  TEST_ASSERT_EQUAL_NODE(&node3, &node30, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node18, &node31, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node13, &node19, 'r', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, &node32, 'b', &node31);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node19);
  
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node32);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);

}

/** Failed Function Test delete node 1 by 1 (12) full to be complete
 *                            
 *
 *                                    12(b)
 *                                      |
 *                 3(b)-----------------+-----------------30(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                 18(r)------+------31(b)
 *        /                /  \                       |                | 
 *      1(r)              5(r) 8(r)           13(b)---+---19(b)        +--32(r)
 *                                                \            
 *                                              15(r)     
 *
 *
 *
 *                                    13(b)
 *                                      |
 *                 3(b)-----------------+-----------------30(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                 18(r)------+------31(b)
 *        /                /  \                       |                | 
 *      1(r)              5(r) 8(r)           15(b)---+---19(b)        +--32(r)
 *                                                            
 *                                                  
 *
 *
 *
 */
void test_delRedBlackTree_del_node_eleventh_node(void){
  CEXCEPTION_T err;
  setNode(&node12, &node3, &node30, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node30, &node18, &node31, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node18, &node13, &node19, 'r');
  setNode(&node31, NULL, &node32, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node13, NULL, &node15, 'b');
  setNode(&node19, NULL, NULL, 'b');
  setNode(&node32, NULL, NULL, 'r');
  setNode(&node15, NULL, NULL, 'r');

  Node *root = &node12;
  
  delRedBlackTree(&root, &node12);
  TEST_ASSERT_EQUAL_PTR(root, &node13);
  TEST_ASSERT_EQUAL_NODE(&node3, &node30, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node18, &node31, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node15, &node19, 'r', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, &node32, 'b', &node31);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node19);
  
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node32);

}

/** Failed Function Test delete node 1 by 1 (15) full to be complete
 *
 *
 *                                    13(b)
 *                                      |
 *                 3(b)-----------------+-----------------30(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                 18(r)------+------31(b)
 *        /                /  \                       |                | 
 *      1(r)              5(r) 8(r)           15(b)---+---19(b)        +--32(r)
 *                                                            
 *                                                  
 *
 *
 *                                    15(b)
 *                                      |
 *                 3(b)-----------------+-----------------30(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                 18(b)------+------31(b)
 *        /                /  \                       |                | 
 *      1(r)              5(r) 8(r)                   +---19(r)        +--32(r)
 *                                                            
 *  
 *
 *
 */
void test_delRedBlackTree_del_node_twelveth_node(void){
  CEXCEPTION_T err;
  setNode(&node13, &node3, &node30, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node30, &node18, &node31, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node18, &node15, &node19, 'r');
  setNode(&node31, NULL, &node32, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node15, NULL, NULL, 'b');
  setNode(&node19, NULL, NULL, 'b');
  setNode(&node32, NULL, NULL, 'r');

  Node *root = &node13;
  
  delRedBlackTree(&root, &node13);
  TEST_ASSERT_EQUAL_PTR(root, &node15);
  TEST_ASSERT_EQUAL_NODE(&node3, &node30, 'b', &node15);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node18, &node31, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, &node19, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(NULL, &node32, 'b', &node31);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node19);
  
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node32);

}

/** Failed Function Test delete node 1 by 1 (15) full to be complete
 *
 *                                    15(b)
 *                                      |
 *                 3(b)-----------------+-----------------30(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                 18(b)------+------31(b)
 *        /                /  \                       |                | 
 *      1(r)              5(r) 8(r)                   +---19(r)        +--32(r)
 *                                                            
 *  
 *
 *                                    18(b)
 *                                      |
 *                 3(b)-----------------+-----------------30(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                 19(b)------+------31(b)
 *        /                /  \                                        | 
 *      1(r)              5(r) 8(r)                                    +--32(r)
 *                                                            
 * 
 *
 */
void test_delRedBlackTree_del_node_thirdteen_node(void){
  CEXCEPTION_T err;
  setNode(&node15, &node3, &node30, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node30, &node18, &node31, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node18, NULL, &node19, 'b');
  setNode(&node31, NULL, &node32, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node19, NULL, NULL, 'r');
  setNode(&node32, NULL, NULL, 'r');

  Node *root = &node15;
  
  delRedBlackTree(&root, &node15);
  TEST_ASSERT_EQUAL_PTR(root, &node18);
  TEST_ASSERT_EQUAL_NODE(&node3, &node30, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node19, &node31, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node19);
  TEST_ASSERT_EQUAL_NODE(NULL, &node32, 'b', &node31);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node32);

}

/** Failed Function Test delete node 1 by 1 (18) full to be complete
 *
 *                                    18(b)
 *                                      |
 *                 3(b)-----------------+-----------------30(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                 19(b)------+------31(b)
 *        /                /  \                                        | 
 *      1(r)              5(r) 8(r)                                    +--32(r)
 *                                                            
 * 
 *                                    19(b)
 *                                      |
 *                 3(b)-----------------+-----------------31(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                 30(b)------+------32(b)
 *        /                /  \                                        
 *      1(r)              5(r) 8(r)                                  
 *
 */
void test_delRedBlackTree_del_node_fifthteen_node(void){
  CEXCEPTION_T err;
  setNode(&node18, &node3, &node30, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node30, &node19, &node31, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node19, NULL, NULL, 'b');
  setNode(&node31, NULL, &node32, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');
  setNode(&node32, NULL, NULL, 'r');

  Node *root = &node18;
  
  delRedBlackTree(&root, &node18);
  TEST_ASSERT_EQUAL_PTR(root, &node19);
  TEST_ASSERT_EQUAL_NODE(&node3, &node31, 'b', &node19);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node30, &node32, 'b', &node31);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node32);

}

/** Failed Function Test delete node 1 by 1 (19) full to be complete
 *                                                       
 * 
 *                                    19(b)
 *                                      |
 *                 3(b)-----------------+-----------------31(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                 30(b)------+------32(b)
 *        /                /  \                                        
 *      1(r)              5(r) 8(r)                                  
 *
 *
 *                                    30(b)
 *                                      |
 *                 3(r)-----------------+-----------------31(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                            +------32(r)
 *        /                /  \                                        
 *      1(r)              5(r) 8(r)                                  
 *
 *
 */
void test_delRedBlackTree_del_node_sixthteen_node(void){
  CEXCEPTION_T err;
  setNode(&node19, &node3, &node31, 'b');
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node31, &node30, &node32, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node30, NULL, NULL, 'b');
  setNode(&node32, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');

  Node *root = &node19;
  
  delRedBlackTree(&root, &node19);
  TEST_ASSERT_EQUAL_PTR(root, &node30);
  TEST_ASSERT_EQUAL_NODE(&node3, &node31, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'r', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, &node32, 'b', &node31);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node32);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);

}

/** Failed Function Test delete node 1 by 1 (30) full to be complete
 *
 *                                    30(b)
 *                                      |
 *                 3(r)-----------------+-----------------31(b)
 *                  |                                       |
 *      2(b)--------+-------7(b)                            +------32(r)
 *        /                /  \                                        
 *      1(r)              5(r) 8(r)                                  
 *
 *
 *                                    31(b)
 *                                      |
 *                 3(r)-----------------+-----------------32(b)
 *                  |                                     
 *      2(b)--------+-------7(b)                           
 *        /                /  \                                        
 *      1(r)              5(r) 8(r)                                  
 *
 *
 */
void test_delRedBlackTree_del_node_seventhteen_node(void){
  CEXCEPTION_T err;
  setNode(&node30, &node3, &node31, 'b');
  setNode(&node3, &node2, &node7, 'r');
  setNode(&node31, NULL, &node32, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node32, NULL, NULL, 'r');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');

  Node *root = &node30;
  
  delRedBlackTree(&root, &node30);
  TEST_ASSERT_EQUAL_PTR(root, &node31);
  TEST_ASSERT_EQUAL_NODE(&node3, &node32, 'b', &node31);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'r', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node32);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);

}

/** Failed Function Test delete node 1 by 1 (31) full to be complete
 *
 *                                    31(b)
 *                                      |
 *                 3(r)-----------------+-----------------32(b)
 *                  |                                     
 *      2(b)--------+-------7(b)                           
 *        /                /  \                                        
 *      1(r)              5(r) 8(r)                                  
 *
 *
 *                                     3(b)
 *                                      |
 *                 2(b)-----------------+-----------------7(r)
 *                  |                                     |
 *      1(r)--------+                         5(b)--------+-------32(b)
 *                                                                 /                   
 *                                                              8(r)       
 *
 *
 */
void test_delRedBlackTree_del_node_eighthteen_node(void){
  CEXCEPTION_T err;
  setNode(&node31, &node3, &node32, 'b');
  setNode(&node3, &node2, &node7, 'r');
  setNode(&node32, NULL, NULL, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node8, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node8, NULL, NULL, 'r');

  Node *root = &node31;
  
  delRedBlackTree(&root, &node31);
  TEST_ASSERT_EQUAL_PTR(root, &node3);
  TEST_ASSERT_EQUAL_NODE(&node2, &node7, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node5, &node32, 'r', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(&node8, NULL, 'b', &node32);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);

}

/** Failed Function Test delete node 1 by 1 (3) full to be complete
 *
 *                                     3(b)
 *                                      |
 *                 2(b)-----------------+-----------------7(r)
 *                  |                                     |
 *      1(r)--------+                         5(b)--------+-------32(b)
 *                                                                 /                   
 *                                                              8(r)       
 *
 *                                     5(b)
 *                                      |
 *                 2(b)-----------------+-----------------8(r)
 *                  |                                     |
 *      1(r)--------+                          7(b)-------+-------32(b)
 *                                                                                    
 *                                                                 
 *
 *
 */
void test_delRedBlackTree_del_node_ninthteen_node(void){
  CEXCEPTION_T err;
  setNode(&node3, &node2, &node7, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node7, &node5, &node32, 'r');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node32, &node8, NULL, 'b');
  setNode(&node8, NULL, NULL, 'r');

  Node *root = &node3;
  
  delRedBlackTree(&root, &node3);
  TEST_ASSERT_EQUAL_PTR(root, &node5);
  TEST_ASSERT_EQUAL_NODE(&node2, &node8, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node7, &node32, 'r', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node32);

}

/** Failed Function Test delete node 1 by 1 (5) full to be complete
 *
 *                                     5(b)
 *                                      |
 *                 2(b)-----------------+-----------------8(r)
 *                  |                                     |
 *      1(r)--------+                          7(b)-------+-------32(b)
 *                                                                                    
 *                                                                 
 *
 *                                     7(b)
 *                                      |
 *                 2(b)-----------------+-----------------8(b)
 *                  |                                     |
 *      1(r)--------+                                     +-------32(r)
 *                                                                                    
 *  
 *
 */
void test_delRedBlackTree_del_node_twenty_node(void){
  CEXCEPTION_T err;
  setNode(&node5, &node2, &node8, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node8, &node7, &node32, 'r');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node7, NULL, NULL, 'b');
  setNode(&node32, NULL, NULL, 'b');

  Node *root = &node5;
  
  delRedBlackTree(&root, &node5);
  TEST_ASSERT_EQUAL_PTR(root, &node7);
  TEST_ASSERT_EQUAL_NODE(&node2, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node32, 'b', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node32);

}

/** Failed Function Test delete node 1 by 1 (7) full to be complete
 *                                                                
 *
 *                                     7(b)
 *                                      |
 *                 2(b)-----------------+-----------------8(b)
 *                  |                                     |
 *      1(r)--------+                                     +-------32(r)
 *                                                                                    
 *  
 *                                     8(b)
 *                                      |
 *                 2(b)-----------------+-----------------32(b)
 *                  |                                     
 *      1(r)--------+                                     
 *                                                                                    
 *  
 *
 */
void test_delRedBlackTree_del_node_twenty_one_node(void){
  CEXCEPTION_T err;
  setNode(&node7, &node2, &node8, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node8, NULL, &node32, 'b');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node32, NULL, NULL, 'r');

  Node *root = &node7;
  
  delRedBlackTree(&root, &node7);
  TEST_ASSERT_EQUAL_PTR(root, &node8);
  TEST_ASSERT_EQUAL_NODE(&node2, &node32, 'b', &node8);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node32);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);

}

/** Failed Function Test delete node 1 by 1 (8) full to be complete
 *                                                                
 * 
 *                                     8(b)
 *                                      |
 *                 2(b)-----------------+-----------------32(b)
 *                  |                                     
 *      1(r)--------+                                     
 *              
 *                                     2(b)
 *                                      |
 *                 1(b)-----------------+-----------------32(b)
 *                                                       
 *                                          
 *    
 *  
 *
 */
void test_delRedBlackTree_del_node_twenty_two_node(void){
  CEXCEPTION_T err;
  setNode(&node8, &node2, &node32, 'b');
  setNode(&node2, &node1, NULL, 'b');
  setNode(&node32, NULL, NULL, 'b');
  setNode(&node1, NULL, NULL, 'r');

  Node *root = &node8;
  
  delRedBlackTree(&root, &node8);
  TEST_ASSERT_EQUAL_PTR(root, &node2);
  TEST_ASSERT_EQUAL_NODE(&node1, &node32, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node32);

}

/** Failed Function Test delete node 1 by 1 (2) full to be complete
 *                                                                
 *           
 *                                     2(b)
 *                                      |
 *                 1(b)-----------------+-----------------32(b)
 *                                                       
 *                                          
 *    
 *                                    32(b)
 *                                      |
 *                 1(r)-----------------+
 *   
 *  
 *
 */
void test_delRedBlackTree_del_node_twenty_three_node(void){
  CEXCEPTION_T err;
  setNode(&node2, &node1, &node32, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node32, NULL, NULL, 'b');

  Node *root = &node2;
  
  delRedBlackTree(&root, &node2);
  TEST_ASSERT_EQUAL_PTR(root, &node32);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node32);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);

}

/** Failed Function Test delete node 1 by 1 (32) full to be complete
 *                                                                
 *                                                  
 *    
 *                                    32(b)
 *                                      |
 *                 1(r)-----------------+
 *   
 *  
 *                                    1(b)
 *                                      
 *              
 *   
 *
 */
void test_delRedBlackTree_del_node_twenty_four_node(void){
  CEXCEPTION_T err;
  setNode(&node32, &node1, NULL, 'b');
  setNode(&node1, NULL, NULL, 'r');

  Node *root = &node32;
  
  delRedBlackTree(&root, &node32);
  TEST_ASSERT_EQUAL_PTR(root, &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);

}

/** Failed Function Test delete node 1 by 1 (1) full to be complete
 *                                                                
 *                                                  
 *    
 *                                    1(b)
 *   
 *  
 *                                     NULL
 *
 */
void test_delRedBlackTree_del_node_twenty_five_node(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'b');

  Node *root = &node1;
  
  delRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, NULL);

}