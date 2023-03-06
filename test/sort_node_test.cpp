//
// Created by rorba on 01.03.2023.
//
#include "gtest/gtest.h"
#include "node.h"
extern "C" {
#include "sort_node.h"
#include "add_node.h"
}

TEST(SortTest, SortsEmptyList) {
    Node *head = NULL;
    head = sort(head);

    EXPECT_EQ(head, nullptr);
}

TEST(SortTest, SortsSingleElementList) {
    Node *head = NULL;
    head = addNodeB(1,head);

    head = sort(head);

    EXPECT_EQ(head->times_correct, 1);
    EXPECT_EQ(head->next, nullptr);
    delete head;
}

TEST(SortTest, SortsTwoElementList) {
    Node *head = NULL;
    head = addNodeB(2,head);
    head = addNodeB(1,head);

    head = sort(head);

    EXPECT_EQ(head->times_correct, 1);
    EXPECT_EQ(head->next->times_correct, 2);
    EXPECT_EQ(head->next->next, nullptr);
    delete head->next;
    delete head;
}

TEST(SortTest, SortsThreeElementList) {
    Node *head = NULL;
    head = addNodeB(2,head);
    head = addNodeB(3,head);
    head = addNodeB(1,head);

    head = sort(head);

    EXPECT_EQ(head->times_correct, 1);
    EXPECT_EQ(head->next->times_correct, 2);
    EXPECT_EQ(head->next->next->times_correct, 3);
    EXPECT_EQ(head->next->next->next, nullptr);
    delete head->next->next;
    delete head->next;
    delete head;
}
