//
// Created by rorba on 28.02.2023.
//

#include <gtest/gtest.h>

extern "C" {
#include "node.h"
#include "add_node.h"
}

// Test addNodeF function
TEST(AddNodeFTest, EmptyList) {
    Node *head = NULL;
    head = addNodeF(42, head);

    EXPECT_EQ(head->data, 42);
    EXPECT_EQ(head->next, nullptr);
}

TEST(AddNodeFTest, NonEmptyList) {
    Node *head = new Node;
    head->data = 0;
    head->next = nullptr;
    head = addNodeF(42, head);

    EXPECT_EQ(head->data, 42);
    EXPECT_NE(head->next, nullptr);
}

// Test addNodeB function
TEST(AddNodeBTest, EmptyList) {
    Node *head = NULL;
    head = addNodeB(42, head);

    EXPECT_EQ(head->data, 42);
    EXPECT_EQ(head->next, nullptr);
}

TEST(AddNodeBTest, NonEmptyList) {
    Node *head = new Node;
    head->data = 0;
    head->next = nullptr;
    head = addNodeB(42, head);

    EXPECT_EQ(head->data, 0);
    EXPECT_NE(head->next, nullptr);
    EXPECT_EQ(head->next->data, 42);
}

// Test insertNode function
TEST(InsertNodeTest, EmptyList) {
    Node *head = NULL;
    head = insertNode(42, 0, head);

    EXPECT_NE(head, nullptr);
    EXPECT_EQ(head->data, 42);
    EXPECT_EQ(head->next, nullptr);
}

TEST(InsertNodeTest, NonEmptyList) {
    Node *head = new Node;
    head->data = 0;
    head->next = nullptr;
    head = insertNode(42, 1, head);

    EXPECT_EQ(head->data, 0);
    EXPECT_NE(head->next, nullptr);
    if (head->next != nullptr) {
        EXPECT_EQ(head->next->data, 42);
    }
}

TEST(InsertNodeTest, MultiElementList) {
    Node *head = new Node;
    head->data = 0;
    head->next = nullptr;
    head = addNodeB(69,head);
    head = insertNode(42, 2, head);

    EXPECT_EQ(head->data, 0);
    EXPECT_NE(head->next, nullptr);
    if (head->next != nullptr) {
        EXPECT_EQ(head->next->data, 69);
        EXPECT_EQ(head->next->next->data, 42);
    }
}

TEST(InsertNodeTest, PositivePosition) {
    Node *head = new Node;
    head->data = 0;
    head->next = nullptr;
    head = insertNode(42, 5, head);

    EXPECT_EQ(head->data, 0);
    EXPECT_EQ(head->next, nullptr);
}

TEST(InsertNodeTest, NegativePosition) {
    Node *head = new Node;
    head->data = 0;
    head->next = nullptr;
    head = insertNode(42, -1, head);

    EXPECT_EQ(head->data, 0);
    EXPECT_EQ(head->next, nullptr);
}

// Test setValue function
TEST(SetValueTest, NotFound) {
    Node *head = new Node;
    head->data = 0;
    head->next = nullptr;
    head = setValue(1, 42, head);

    EXPECT_EQ(head->data, 0);
}

TEST(SetValueTest, Found) {
    Node *head = new Node;
    head->data = 0;
    head->next = nullptr;
    head = setValue(0, 42, head);

    EXPECT_EQ(head->data, 42);
}