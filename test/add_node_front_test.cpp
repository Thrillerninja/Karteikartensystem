//
// Created by rorba on 09.02.2023.
//
#include <gtest/gtest.h>

extern "C" {
#include "node.h"
#include "add_node.h"
#include "remove_node.h"
#include "search_node.h"
#include "swap_node.h"
#include "sort_node.h"
#include "print_list.h"
#include "file_handling.h"
#include "abfrage.h"
}
/*
// Front
TEST(AddFrontTest, POSITIVE) {
    Node *head = NULL;
    head = addNodeF(700,head);
    ASSERT_TRUE(head!= NULL);
}

TEST(AddFrontTest, ZERO) {
    Node *head = NULL;
    head = addNodeF(0,head);
    ASSERT_TRUE(head!= NULL);
}

TEST(AddFrontTest, NEGATIVE) {
    Node *head = NULL;
    head = addNodeF(-500,head);
    ASSERT_TRUE(head!= NULL);
}

// Back
TEST(AddBackTest, POSITIVE) {
    Node *head = NULL;
    head = addNodeB(50,head);
    ASSERT_TRUE(head!= NULL);
}

TEST(AddBackTest, ZERO) {
    Node *head = NULL;
    head = addNodeB(0,head);
    ASSERT_TRUE(head!= NULL);
}

TEST(AddBackTest, NEGATIVE) {
    Node *head = NULL;
    head = addNodeB(-50,head);
    ASSERT_TRUE(head!= NULL);
}

// Insert
TEST(InsertTest, POSITIVE) {
    int compare[] = {50,45,40};
    Node *head = NULL;
    head = addNodeB(50,head);
    head = addNodeB(40,head);
    head = insertNode(45,1,head);

    for (int i = 0; i < 5;i++){
        ASSERT_EQ(compare[i],head->data);
        head = (Node*) head->next;
    }
}

TEST(InsertTest, ZERO) {
    int compare[] = {50,0,40};
    Node *head = NULL;
    head = addNodeB(50,head);
    head = addNodeB(40,head);
    head = insertNode(0,1,head);

    for (int i = 0; i < 5;i++){
        ASSERT_EQ(compare[i],head->data);
        head = (Node*) head->next;
    }
}

TEST(InsertTest, NEGATIVE) {
    int compare[] = {50,-10,40};
    Node *head = NULL;
    head = addNodeB(50,head);
    head = addNodeB(40,head);
    head = insertNode(-10,1,head);

    for (int i = 0; i < 5;i++){
        ASSERT_EQ(compare[i],head->data);
        head = (Node*) head->next;
    }

}
TEST(InsertTest, Fail) {
    int compare[] = {50,0,40};
    Node *head = NULL;
    head = addNodeB(50,head);
    head = addNodeB(40,head);
    head = insertNode(0,1,head);

    for (int i = 0; i < 5;i++){
        ASSERT_EQ(compare[i],head->data);
        head = (Node*) head->next;
    }
}

// Default
TEST(True, True) {
    ASSERT_TRUE(true);
}

// Push
TEST(Swap, Backwards) {

    Node *head = NULL;
    head = addNodeF(8,head);
    head = addNodeF(7,head);
    head = addNodeF(6,head);
    head = swap(0, head);

    ASSERT_EQ(7,head->data);
}

TEST(Swap, Fail) {

    Node *head = NULL;
    head = addNodeF(8,head);
    head = addNodeF(7,head);
    head = addNodeF(6,head);
    head = swap(-1, head);

    ASSERT_EQ(6,head->data);
}

TEST(Swap, Fail2) {

    Node *head = NULL;
    head = addNodeF(8,head);
    head = addNodeF(7,head);
    head = addNodeF(6,head);
    head = swap(3, head);

    ASSERT_EQ(6,head->data);
}

// Pull
TEST(Pull, Backwards) {

    Node *head = NULL;
    head = addNodeF(8,head);
    head = addNodeF(7,head);
    head = pull(1,head);

    ASSERT_EQ(7,head->data);
}

TEST(Pull, Fail) {

    Node *head = NULL;
    head = addNodeF(8,head);
    head = addNodeF(7,head);
    head = pull(-1,head);

    ASSERT_EQ(7,head->data);
}

TEST(Pull, Fail2) {

    Node *head = NULL;
    head = addNodeF(8,head);
    head = addNodeF(7,head);
    head = pull(3,head);

    ASSERT_EQ(7,head->data);
}

// Sort
TEST(Sort, AlreadySorted) {
    int compare[5] = {4,5,6,7,8};

    Node *head = NULL;
    head = addNodeB(4,head);
    head = addNodeB(5,head);
    head = addNodeB(6,head);
    head = addNodeB(7,head);
    head = addNodeB(8,head);
    printList(head);
    head = sort(head);
    printList(head);

    for (int i = 0; i < 5;i++){
        ASSERT_EQ(compare[i],head->data);
        head = (Node*) head->next;
    }
}

TEST(Sort, Sort) {
    int compare[5] = {4,5,6,7,8};

    Node *head = NULL;
    head = addNodeB(8,head);
    head = addNodeB(6,head);
    head = addNodeB(7,head);
    head = addNodeB(5,head);
    head = addNodeB(4,head);
    printList(head);
    head = sort(head);
    printList(head);

    for (int i = 0; i < 5;i++){
        ASSERT_EQ(compare[i],head->data);
        head = (Node*) head->next;
    }
}
*/