#include <stdio.h>
#include "unity.h"
#include "Rotations.h"
#include "Node.h"
#include "RedBlackTree.h"
#include "InitNode.h"
#include "CustomAssertion.h"
#include "ErrorCode.h"
#include "CException.h"

Node node1, node2, node3, node4, node5, node6, node7;

void setUp(void){
	resetNode(&node1, 1);
	resetNode(&node2, 2);
	resetNode(&node3, 3);
	resetNode(&node4, 4);
	resetNode(&node5, 5);
	resetNode(&node6, 6);
	resetNode(&node7, 7);
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
 *//*
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

}*/

// /** 2-node case
 // *        root
 // *        /       remove 2    
 // *       v        -------->   Throw ERR_NODE_UNAVAILABLE
 // *      1(b)                   
 // *                            
 // *
 // *
 // */
// void test_delRedBlackTree_remove_2_from_tree_with_root_1_should_throw_ERR_NODE_UNAVAILABLE(void){
  // CEXCEPTION_T err;
  // setNode(&node1, NULL, NULL, 'b');
  // setNode(&node2, NULL, NULL, 'b');
  // Node *root = &node1;
  
  // Try {
    // delRedBlackTree(&root, &node2);
    // TEST_FAIL_MESSAGE("Expected ERR_NODE_UNAVAILABLE to be thrown. But receive none");
  // } Catch(err){
    // TEST_ASSERT_EQUAL_PTR(root, &node1);
    // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  // }
// }

// /** 2-node case
 // *        root
 // *        /       remove 1        root
 // *       v        -------->       /
 // *      1(b)                     v
 // *                              NULL
 // *
 // *
 // */
// void test_delRedBlackTree_remove_1_from_tree_with_root_1(void){
  // CEXCEPTION_T err;
  // setNode(&node1, NULL, NULL, 'b');
  // setNode(&node1, NULL, NULL, 'b');
  // Node *root = &node1;
  
  // delRedBlackTree(&root, &node1);
  // TEST_ASSERT_EQUAL_PTR(root, NULL);

// }

// /** 2-node case
 // *        root
 // *        /       remove 2        root
 // *       v        -------->       /
 // *      1(b)                     v
 // *        \                     1(b)
 // *        2(r)
 // *
 // */
// void test_delRedBlackTree_remove_2_from_tree_with_root_1(void){
  // CEXCEPTION_T err;
  // setNode(&node2, NULL, NULL, 'r');
  // setNode(&node1, NULL, &node2, 'b');
  // Node *root = &node1;
  
  // delRedBlackTree(&root, &node2);
  // TEST_ASSERT_EQUAL_PTR(root, &node1);

// }

// /** 2-node case
 // *        root
 // *        /       remove 1        root
 // *       v        -------->       /
 // *      2(b)                     v
 // *      /                        2(b)
 // *    1(r)
 // *
 // */
// void test_delRedBlackTree_remove_1_from_tree_with_root_2(void){
  // CEXCEPTION_T err;
  // setNode(&node1, NULL, NULL, 'r');
  // setNode(&node2, &node1, NULL, 'b');
  // Node *root = &node2;
  
  // delRedBlackTree(&root, &node1);
  // TEST_ASSERT_EQUAL_PTR(root, &node2);

// }

// /** 3-node case
 // *        root
 // *        /       remove 1        root
 // *       v        -------->       /
 // *      2(b)                     v
 // *     /  \                     2(b)
 // *   1(r)  3(r)                    \
 // *                                 3(r)
 // *
 // *
 // */
// void test_delRedBlackTree_remove_1_from_tree_with_root_2_and_3_with_red(void){
  // CEXCEPTION_T err;
  // setNode(&node1, NULL, NULL, 'r');
  // setNode(&node3, NULL, NULL, 'r');
  // setNode(&node2, &node1, &node3, 'b');
  // Node *root = &node2;
  
  // delRedBlackTree(&root, &node1);
  // TEST_ASSERT_EQUAL_PTR(root, &node2);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);

// }

// /** 3-node case
 // *        root
 // *        /       remove 1        root
 // *       v        -------->       /
 // *      2(b)                     v
 // *     /  \                     2(b)
 // *   1(b)  3(b)                    \
 // *                                 3(r)
 // *
 // *
 // */
// void test_delRedBlackTree_remove_1_from_tree_with_root_2_and_3_with_black(void){
  // CEXCEPTION_T err;
  // setNode(&node1, NULL, NULL, 'b');
  // setNode(&node3, NULL, NULL, 'b');
  // setNode(&node2, &node1, &node3, 'b');
  // Node *root = &node2;
  
  // delRedBlackTree(&root, &node1);
  // TEST_ASSERT_EQUAL_PTR(root, &node2);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);

// }

// /** 5-node case
 // *        root
 // *        /       remove 1        root
 // *       v        -------->       /
 // *      2(b)                     v
 // *     /  \                     5(b)
 // *   1(b)  5(r)                 /  \
 // *        /   \               2(b)  6(b)
 // *      3(b)  6(b)               \
 // *                               3(r)
 // */
// void test_delRedBlackTree_remove_1_from_tree_rotate_left_with_root_2_3_5_6(void){
  // CEXCEPTION_T err;
  // setNode(&node1, NULL, NULL, 'b');
  // setNode(&node3, NULL, NULL, 'b');
  // setNode(&node6, NULL, NULL, 'b');
  // setNode(&node5, &node3, &node6, 'r');
  // setNode(&node2, &node1, &node5, 'b');
  // Node *root = &node2;
  
  // delRedBlackTree(&root, &node1);
  // TEST_ASSERT_EQUAL_PTR(root, &node5);
  // TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node5);
  // TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);

// }

// /** 5-node case
 // *        root
 // *        /       remove 3        root
 // *       v        -------->       /
 // *      2(b)                     v
 // *     /  \                     2(b)
 // *   1(b)  5(r)                 /  \
 // *        /   \               1(b)  5(b)
 // *      3(b)  6(b)                    \
 // *                                     6(r)
 // */
// void test_delRedBlackTree_remove_3_from_tree_without_rotate_with_root_2_1_5_6(void){
  // CEXCEPTION_T err;
  // setNode(&node3, NULL, NULL, 'b');
  // setNode(&node1, NULL, NULL, 'b');
  // setNode(&node6, NULL, NULL, 'b');
  // setNode(&node5, &node3, &node6, 'r');
  // setNode(&node2, &node1, &node5, 'b');
  // Node *root = &node2;
  
  // delRedBlackTree(&root, &node3);
  // TEST_ASSERT_EQUAL_PTR(root, &node2);
  // TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'b', &node2);
  // TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node5);
  // TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'b', &node2);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node6);

// }

// /** 5-node case
 // *        root
 // *        /       remove 6        root
 // *       v        -------->       /
 // *      2(b)                     v
 // *     /  \                     2(b)
 // *   1(b)  5(r)                 /  \
 // *        /   \               1(b)  5(b)
 // *      3(b)  6(b)                  /
 // *                                3(r)
 // */
// void test_delRedBlackTree_remove_6_from_tree_without_rotate_with_root_2_1_5_3(void){
  // CEXCEPTION_T err;
  // setNode(&node6, NULL, NULL, 'b');
  // setNode(&node3, NULL, NULL, 'b');
  // setNode(&node1, NULL, NULL, 'b');
  // setNode(&node5, &node3, &node6, 'r');
  // setNode(&node2, &node1, &node5, 'b');
  // Node *root = &node2;
  
  // delRedBlackTree(&root, &node6);
  // TEST_ASSERT_EQUAL_PTR(root, &node2);
  // TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'b', &node2);
  // TEST_ASSERT_EQUAL_NODE(&node3, NULL, 'b', &node5);
  // TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'b', &node2);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);

// }

// /** 7-node case
 // *        root
 // *        /       remove 1        root
 // *       v        -------->       /
 // *      4(b)                     v
 // *     /    \                      4(b)
 // *   2(r)    6(r)                 /    \
 // *  /   \    /   \              2(b)   6(r)
 // *1(b) 3(b) 5(b)  7(b)             \    /   \
 // *                                3(r) 5(b) 7(b)
 // *
 // *
 // *
 // */
// void test_delRedBlackTree_remove_1_from_tree_without_rotate_with_root_2_5_3_6_7_4(void){
  // CEXCEPTION_T err;
  // setNode(&node1, NULL, NULL, 'b');
  // setNode(&node3, NULL, NULL, 'b');
  // setNode(&node5, NULL, NULL, 'b');
  // setNode(&node7, NULL, NULL, 'b');
  // setNode(&node6, &node5, &node7, 'r');
  // setNode(&node2, &node1, &node3, 'r');
  // setNode(&node4, &node2, &node6, 'b');
  // Node *root = &node4;
  
  // delRedBlackTree(&root, &node1);
  // TEST_ASSERT_EQUAL_PTR(root, &node4);
  // TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  // TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
  // TEST_ASSERT_EQUAL_NODE(&node5, &node7, 'r', &node6);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);

// }

// /** 7-node case
 // *        root
 // *        /       remove 3        root
 // *       v        -------->       /
 // *      4(b)                     v
 // *     /    \                      4(b)
 // *   2(r)    6(r)                 /    \
 // *  /   \    /   \              2(b)   6(r)
 // *1(b) 3(b) 5(b)  7(b)          /      /   \
 // *                            1(r)    5(b) 7(b)
 // *
 // *
 // *
 // */
// void test_delRedBlackTree_remove_3_from_tree_without_rotate_with_root_2_5_1_6_7_4(void){
  // CEXCEPTION_T err;
  // setNode(&node3, NULL, NULL, 'b');
  // setNode(&node1, NULL, NULL, 'b');
  // setNode(&node5, NULL, NULL, 'b');
  // setNode(&node7, NULL, NULL, 'b');
  // setNode(&node6, &node5, &node7, 'r');
  // setNode(&node2, &node1, &node3, 'r');
  // setNode(&node4, &node2, &node6, 'b');
  // Node *root = &node4;
  
  // delRedBlackTree(&root, &node3);
  // TEST_ASSERT_EQUAL_PTR(root, &node4);
  // TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  // TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  // TEST_ASSERT_EQUAL_NODE(&node5, &node7, 'r', &node6);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);

// }

// /** 7-node case
 // *        root
 // *        /       remove 5        root
 // *       v        -------->       /
 // *      4(b)                     v
 // *     /    \                      4(b)
 // *   2(r)    6(r)                 /    \
 // *  /   \    /   \              2(r)   6(b)
 // *1(b) 3(b) 5(b)  7(b)          /   \      \
 // *                            1(b)  3(b)   7(r)
 // *
 // *
 // *
 // */
// void test_delRedBlackTree_remove_5_from_tree_without_rotate_with_root_2_3_1_6_7_4(void){
  // CEXCEPTION_T err;
  // setNode(&node5, NULL, NULL, 'b');
  // setNode(&node3, NULL, NULL, 'b');
  // setNode(&node1, NULL, NULL, 'b');
  // setNode(&node7, NULL, NULL, 'b');
  // setNode(&node6, &node5, &node7, 'r');
  // setNode(&node2, &node1, &node3, 'r');
  // setNode(&node4, &node2, &node6, 'b');
  // Node *root = &node4;
  
  // delRedBlackTree(&root, &node5);
  // TEST_ASSERT_EQUAL_PTR(root, &node4);
  // TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  // TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'r', &node2);
  // TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node6);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);

// }

// /** 7-node case
 // *        root
 // *        /       remove 7        root
 // *       v        -------->       /
 // *      4(b)                     v
 // *     /    \                      4(b)
 // *   2(r)    6(r)                 /    \
 // *  /   \    /   \              2(r)    6(b)
 // *1(b) 3(b) 5(b)  7(b)          /  \    /
 // *                            1(b) 3(b)5(r)
 // *
 // *
 // *
 // */
// void test_delRedBlackTree_remove_7_from_tree_without_rotate_with_root_2_3_1_6_5_4(void){
  // CEXCEPTION_T err;
  // setNode(&node7, NULL, NULL, 'b');
  // setNode(&node5, NULL, NULL, 'b');
  // setNode(&node3, NULL, NULL, 'b');
  // setNode(&node1, NULL, NULL, 'b');
  // setNode(&node6, &node5, &node7, 'r');
  // setNode(&node2, &node1, &node3, 'r');
  // setNode(&node4, &node2, &node6, 'b');
  // Node *root = &node4;
  
  // delRedBlackTree(&root, &node7);
  // TEST_ASSERT_EQUAL_PTR(root, &node4);
  // TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node4);
  // TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'r', &node2);
  // TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', &node6);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  // TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);

// }

