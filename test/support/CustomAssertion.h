#ifndef __CustomAssertion_H__
#define __CustomAssertion_H__

#include "Node.h"

#define TEST_ASSERT_EQUAL_NODE(left, right, color, actualNode) assertNode(left, right, color, actualNode, __LINE__)

void assertNode(Node *left, Node *right, char color, Node *actualNode, int lineNumber);

#endif // __CustomAssertion_H__
