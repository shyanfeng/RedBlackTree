#include <stdio.h>
#include "unity.h"
#include "Rotations.h"
#include "Node.h"
#include "RedBlackTree.h"
#include "InitNode.h"
#include "CustomAssertion.h"
#include "ErrorCode.h"
#include "CException.h"

Node node1, node2, node3, node4, node5, node6, node7, 
node8, node10, node12, node13,node18, node19, node20, node24, node25;

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
	resetNode(&node18, 18);
	resetNode(&node19, 19);
	resetNode(&node20, 20);
	resetNode(&node24, 24);
	resetNode(&node25, 25);
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
 *  /   \    /    \              12(b)  	25(b)
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
  TEST_ASSERT_EQUAL_NODE(&node10, &node13, 'b', &node12);
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
 *10(b)13(b)20(b)  25(b)         /  \   	 /
 *                            10(b) 13(b)20(r)
 *
 */
void test_delRedBlackTree_case2b_removeNextLargerSuccessor_24_from_tree_18b_12r_24r_10b_13b_20b_25b(void){
  CEXCEPTION_T err;
  setNode(&node24, &node20, &node25, 'b');
  setNode(&node10, NULL, NULL, 'b');
  setNode(&node13, NULL, NULL, 'b');
  setNode(&node20, NULL, NULL, 'b');
  setNode(&node25, NULL, NULL, 'b');
  setNode(&node12, &node10, &node13, 'b');
  setNode(&node18, &node12, &node24, 'r');
  Node *root = &node18;
  
  delRedBlackTree(&root, &node24);
  TEST_ASSERT_EQUAL_PTR(root, &node18);
  TEST_ASSERT_EQUAL_NODE(&node12, &node25, 'b', &node18);
  TEST_ASSERT_EQUAL_NODE(&node10, &node13, 'b', &node12);
  TEST_ASSERT_EQUAL_NODE(&node20, NULL, 'b', &node25);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);

}
