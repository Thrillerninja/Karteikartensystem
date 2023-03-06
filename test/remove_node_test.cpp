//
// Created by rorba on 28.02.2023.
//
#include <gtest/gtest.h>
extern "C"{
#include "node.h"
#include "add_node.h"
#include "remove_node.h"
#include "print_list.h"
}


class RemoveNodeTest : public testing::Test {
protected:
    void SetUp() override {
        // create a list with some nodes
        head = nullptr;
        head = addNodeB(0,head);
        head = addNodeB(1,head);
        head = addNodeB(2,head);
    }

    void TearDown() override {
        // delete the list
        Node *current = head;
        while (current != nullptr) {        //hopefully no memleak (not completely sure about this code)
            Node *next = current->next;
            free(current);
            current = next;
        }
    }

    // the head of the list
    Node *head;
};

// Test removing the first node
TEST_F(RemoveNodeTest, RemoveFirstNode) {
    head = removeNode(0, head);
    EXPECT_EQ(head->times_correct, 1);
}

// Test removing the last node
TEST_F(RemoveNodeTest, RemoveLastNode) {
    head = removeNode(2, head);
    EXPECT_EQ(head->next->times_correct, 1);
}

// Test removing a node in the middle
TEST_F(RemoveNodeTest, RemoveMiddleNode) {
    head = removeNode(1, head);
    EXPECT_EQ(head->next->times_correct, 2);
}

// Test removing a node that does not exist
TEST_F(RemoveNodeTest, RemoveNonExistingNode) {
    head = removeNode(4, head);
    EXPECT_EQ(head->times_correct, 0);
    EXPECT_EQ(head->next->times_correct, 1);
    EXPECT_EQ(head->next->next->times_correct, 2);
}

// Test removing the only node in the list
TEST_F(RemoveNodeTest, RemoveOnlyNode) {
    Node *node = new Node;
    node->times_correct = 42;
    node->next = nullptr;
    head = removeNode(42, node);
    EXPECT_EQ(head, nullptr);
}