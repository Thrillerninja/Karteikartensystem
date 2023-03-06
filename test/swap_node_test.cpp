//
// Created by rorba on 28.02.2023.
//
#include <gtest/gtest.h>
extern "C"{
#include "node.h"
#include "add_node.h"
#include "swap_node.h"
}


class SwapNodeTest : public testing::Test {
protected:
    void SetUp() override {
        head = nullptr;
        for (int i = 0; i < 5; i++) {
            head = addNodeB(i, head);
        }
    }

    void TearDown() override {
        Node *current = head;
        while (current != nullptr) {
            Node *next = current->next;
            free(current);
            current = next;
        }
    }
    Node *head;
};

// SWAP
TEST_F(SwapNodeTest, SwapInvalid) {
    Node *test_head = nullptr;
    Node *test_head_2 = swap(0, test_head);
    EXPECT_EQ(test_head_2, test_head_2);
}

TEST_F(SwapNodeTest, SwapFirstSecond) {
    Node *test_head = swap(0, head);
    int compare[] = { 1, 0, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(test_head->times_correct, compare[i]);
        test_head = test_head->next;
    }
}

TEST_F(SwapNodeTest, SwapMiddleEnd) {
    Node *test_head = swap(3, head);
    int compare[] = { 0, 1, 2, 4, 3, 5};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(test_head->times_correct, compare[i]);
        test_head = test_head->next;
    }
}

// PUSHDATA
TEST_F(SwapNodeTest, PushdataInvalid) {
    Node *test_head = nullptr;
    Node *test_head_2 = pushdata(0, test_head);
    EXPECT_EQ(test_head_2, test_head_2);
}

TEST_F(SwapNodeTest, PushdataFirstSecond) {
    Node *test_head = pushdata(0, head);
    int compare[] = { 1, 0, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(test_head->times_correct, compare[i]);
        test_head = test_head->next;
    }
}

TEST_F(SwapNodeTest, PushdataMiddleEnd) {
    Node *test_head = pushdata(2, head);
    int compare[] = { 0, 1, 3, 2, 4, 5};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(test_head->times_correct, compare[i]);
        test_head = test_head->next;
    }
}

// PULL
TEST_F(SwapNodeTest, PullInvalid) {
    Node *test_head = nullptr;
    Node *test_head_2 = pull(0, test_head);
    EXPECT_EQ(test_head_2, test_head_2);
}

TEST_F(SwapNodeTest, PullFirstSecond) {
    Node *test_head = pull(0, head);
    int compare[] = { 0, 2, 1, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(test_head->times_correct, compare[i]);
        test_head = test_head->next;
    }
}

TEST_F(SwapNodeTest, PullMiddleEnd) {
    Node *test_head = pull(3, head);
    int compare[] = { 0, 2, 1, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(test_head->times_correct, compare[i]);
        test_head = test_head->next;
    }
}