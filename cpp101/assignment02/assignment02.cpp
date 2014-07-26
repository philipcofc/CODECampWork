/*
 * assignment02.cpp
 *
 * Requirements: Use struct and malloc to build a basic stack data structure.
 *
 *  Created on: Jul 16, 2014
 *      Author: philipmeyerjr
 */
#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
	int x;
	struct node *next;
	struct node *prev;
};

struct node* newNode(struct node *node, int x) {
        struct node *n = (struct node*)malloc(sizeof(struct node));
        n->x = x;
        n->next = NULL;
        n->prev = node;

        return n;
}

struct node *push(struct node *node, int x) {

	if(node == NULL) {
		return newNode(node, x);
	} else{
		if(node->next == NULL) {
			node->next = newNode(node, x);
			return node->next;
		} else {
			return push(node->next, x);
		}
	}
}

struct node *pop(struct node *node) {
	struct node *temp_node = NULL;

	if(node->next != NULL) {
		return pop(node->next);
	} else {
		if(node->prev != NULL) {
			temp_node = node->prev;
			free(node);
			temp_node->next = NULL;
			return temp_node;
		} else {
			free(node);
			return temp_node;
		}
	}
}

int main(void) {
	struct node *root = NULL;
	struct node *head = NULL;

	cout << "PUSH:" << endl;
	head = push(head, 4);
	root = head;
	cout << "HEAD VALUES " << head->prev << ", " << head << ", " << head->next << endl;
	cout << endl;
	head = push(head, 3);
	cout << "PHEAD VALUES " << head->prev->prev << ", " << head->prev << ", " << head->prev->next << endl;
	cout << "HEAD VALUES " << head->prev << ", " << head << ", " << head->next << endl;
	cout << endl;
	head = push(head, 8);
	cout << "PHEAD VALUES " << head->prev->prev << ", " << head->prev << ", " << head->prev->next << endl;
	cout << "HEAD VALUES " << head->prev << ", " << head << ", " << head->next << endl;
	cout << endl;
	head = push(head, 2);
	cout << "PHEAD VALUES " << head->prev->prev << ", " << head->prev << ", " << head->prev->next << endl;
	cout << "HEAD VALUES " << head->prev << ", " << head << ", " << head->next << endl;
	cout << endl;
	cout << "POP:" << endl;
	head = pop(head);
	cout << "HEAD VALUES " << head->prev << ", " << head << ", " << head->next << endl;
	cout << endl;
	head = pop(head);
	cout << "HEAD VALUES " << head->prev << ", " << head << ", " << head->next << endl;
	cout << endl;
	head = pop(head);
	cout << "HEAD VALUES " << head->prev << ", " << head << ", " << head->next << endl;
	cout << endl;
	head = pop(head);
	cout << "HEAD VALUES " << head << endl;
	cout << endl;

	return 0;
}

