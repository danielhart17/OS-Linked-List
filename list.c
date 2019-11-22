// list/list.c
//
// Implementation for linked list.
//
// <Daniel Hart>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Function for allocating lists
list_t *list_alloc() {
    list_t *l;
    l = malloc(sizeof(list_t));
	l->head = NULL;
    return l;
}

//Function for freeing list
void list_free(list_t *l) {
    if (l == NULL)
    {
        return;
    }
    node_t *current_node = l->head;
    node_t *next_node = NULL;
    while (current_node != NULL)
    {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    l->head = NULL;
    free(l);
}

// Print list
void list_print(list_t *l) {
    node_t *current_node = l->head;
    node_t *next_node = NULL;
    while (current_node->next != NULL)
    {
        printf("%d -> ", current_node->value);
        next_node = current_node->next;
        current_node = next_node;
    }
	printf("%d", current_node->value);
	printf("\n");
}

// Returns the length of the list
int list_length(list_t *l) {
    node_t *current_node = l->head;
    int length = 0;
    while (current_node != NULL)
    {
        length ++;
        current_node = current_node->next;
    }
    return length;
}

// Methods for adding to the list.
void list_add_to_back(list_t *l, elem value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    node_t *current_node = l->head;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

//Add element to front of list
void list_add_to_front(list_t *l, elem value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = l->head;
	l->head = new_node;
}

// Add element to list at index
void list_add_at_index(list_t *l, elem value, int index) {
    int count = 1;
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    node_t * current_node = l->head;
    node_t* next_node = NULL;
    while (current_node != NULL && count < (index))
    {
        count++;
        next_node = current_node->next;
        current_node = next_node;
    }
    next_node = current_node->next;
    current_node->next = new_node;
    new_node->next = next_node;
}

// Remove element from end of list and returns the removed element.
elem list_remove_from_back(list_t *l) {
    node_t *prev_node = l->head;
	node_t *current_node = prev_node->next;
    while (current_node->next != NULL)
    {
		prev_node = current_node;
        current_node = current_node->next;
    }
	prev_node->next = NULL;
    elem num = current_node->value;
    free(current_node);
    return num;
}

// Remove element from front of list
elem list_remove_from_front(list_t *l) {
    node_t *current_node = l->head;
    l->head = current_node->next;
    elem num = current_node->value;
    free(current_node);
    return num;
}

// Remove element from list at index
elem list_remove_at_index(list_t *l, int index) {
    int count = 0;
    node_t *prev_node = l->head;
	node_t *current_node = prev_node->next;
    while (current_node->next != NULL && count < (index - 1))
    {
        count++;
		prev_node = current_node;
        current_node = current_node->next;
    }
    node_t *temp = current_node;
    prev_node->next = current_node->next;
    elem num = temp->value;
    free(temp);
    return num;
}

// Checks if element is in list
bool list_is_in(list_t *l, elem value) {
	bool valIsIn;
    node_t *current_node = l->head;
    while (current_node->next != NULL && !exist)
    {
		if (current_node->value == value){
			valIsIn = true;
		}
        current_node = current_node->next;
    }
    return valIsIn;
}

// Returns element at index
elem list_get_elem_at(list_t *l, int index) {
	int counter = 0;
	elem value = 0;
	node_t *current_node = l->head;
    while (current_node->next != NULL && counter < (index))
    {
		counter++;
        current_node = current_node->next;
    }
	if (current_node != NULL){
		value = current_node->value;
	}
	return value;
}

// Return index of certain element in list
int list_get_index_of(list_t *l, elem value) {
	int counter = 0;
	node_t *current_node = l->head;
    while (current_node->next != NULL)
    {
		if (current_node->value == value){
			return counter;
		} else {
			counter++;
			current_node = current_node->next;
		}
    }
	return counter;
}
