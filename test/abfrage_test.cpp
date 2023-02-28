//
// Created by rorba on 28.02.2023.
//
#include <gtest/gtest.h>
extern "C"{
#include "node.h"
#include "add_node.h"
#include "abfrage.h"
}


class AbfrageTest : public testing::Test {
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
TEST_F(AbfrageTest, SearchExisting) {
    int position = searchNode(1, head);
    EXPECT_EQ(position, 1);
}

// Test removing the last node
TEST_F(AbfrageTest, SearchNonExisting) {
    int position = searchNode(5, head);
    EXPECT_EQ(position, -1);
}
