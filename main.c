#include <stdio.h>

#include "list.h"

int main() {
	printf("Tests for implementation of Linked List.\n\n");
    printf("Populating List...\n");

    //Define list
	list_t *list = list_alloc();

    //Test for adding elements to front of list
	list_add_to_front(list,5);
    printf("Add %d to the front: ", 5);
    list_print(list);
	list_add_to_front(list,1);
    printf("Add %d to the front: ", 1);
    list_print(list);
    list_add_to_front(list,6);
    printf("Add %d to the front: ", 6);
    list_print(list);

    //Test for adding elements to end of list
	list_add_to_back(list,2);
    printf("Add %d to the back: ", 2);
    list_print(list);
	list_add_to_back(list,8);
    printf("Add %d to the back: ", 8);
    list_print(list);
    list_add_to_back(list,1);
    printf("Add %d to the back: ", 1);
    list_print(list);

    //Test for adding elements at index
	list_add_at_index(list,3,4);
    printf("Add %d at index %d: ", 3,4);
    list_print(list);
    list_add_at_index(list,9,5);
    printf("Add %d at index %d: ", 9,5);
    list_print(list);
    list_add_at_index(list,7,2);
    printf("Add %d at index %d: ", 7,2);
    list_print(list);

    //Test for removing elements from list front of list
	elem e1 = list_remove_from_front(list);
    printf("\nRemoved %d from the front: ", e1);
    list_print(list);
    e1 = list_remove_from_front(list);
    printf("Removed %d from the front: ", e1);
    list_print(list);

    //Test for removing elements from list at index
	elem e2 = list_remove_at_index(list, 3);
    printf("Removed %d from the index %d: ", e2, 3);
    list_print(list);
    e2 = list_remove_at_index(list, 1);
    printf("Removed %d from the index %d: ", e2, 1);
    list_print(list);

    //Test for removing elements from end of list
	elem e3 = list_remove_from_back(list);
    printf("Removed %d from the back: ", e3);
	list_print(list);
    e3 = list_remove_from_back(list);
    printf("Removed %d from the back: ", e3);
	list_print(list);

    //Test length of list
	int length = list_length(list);
	printf("\nLength of the list is: %d.\n", length);

    //Test to check if item is in list
	elem item = 10;
	bool isInList = list_is_in(list, item);
	if (isInList){
		printf("%d is in the list.\n", item);
	} else {
		printf("%d is not in the list.\n", item);
	}

    //Test to get element at index
	int index = 2;
	elem e4 = list_get_elem_at(list, index);
	printf("Element at index %d is: %d. \n", index, e4);
	elem e5 = 2;
	index = list_get_index_of(list,e5);
	printf("Element at index %d is: %d. \n", index, e5);

	list_free(list);
	return 0;
}

/*
 * OUTPUT!!

    Tests for implementation of Linked List.

    Populating List...
    Add 5 to the front: 5
    Add 1 to the front: 1 -> 5
    Add 6 to the front: 6 -> 1 -> 5
    Add 2 to the back: 6 -> 1 -> 5 -> 2
    Add 8 to the back: 6 -> 1 -> 5 -> 2 -> 8
    Add 1 to the back: 6 -> 1 -> 5 -> 2 -> 8 -> 1
    Add 3 at index 4: 6 -> 1 -> 5 -> 2 -> 3 -> 8 -> 1
    Add 9 at index 5: 6 -> 1 -> 5 -> 2 -> 3 -> 9 -> 8 -> 1
    Add 7 at index 2: 6 -> 1 -> 7 -> 5 -> 2 -> 3 -> 9 -> 8 -> 1

    Removed 6 from the front: 1 -> 7 -> 5 -> 2 -> 3 -> 9 -> 8 -> 1
    Removed 1 from the front: 7 -> 5 -> 2 -> 3 -> 9 -> 8 -> 1
    Removed 3 from the index 3: 7 -> 5 -> 2 -> 9 -> 8 -> 1
    Removed 5 from the index 1: 7 -> 2 -> 9 -> 8 -> 1
    Removed 1 from the back: 7 -> 2 -> 9 -> 8
    Removed 8 from the back: 7 -> 2 -> 9

    Length of the list is: 3.
    10 is not in the list.
    Element at index 2 is: 9.
    Element at index 1 is: 2.

*/
