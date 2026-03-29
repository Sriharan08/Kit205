#include <stdio.h>
#include <stdlib.h>
#include "list.h"


// Function to create and return a new empty list.
List new_list() {
	List temp;
	temp.head = NULL;
	return temp;
}

// Function to print the contents of a list.
void print_list(List* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		printf("%d", current->data);
		current = current->next;

		if (current != NULL)
			printf(", ");
	}
	printf("\n");
}

// Function to insert a new node with given data at the front of the list.
void insert_at_front(List* self, int data) {
	ListNodePtr new_node = malloc(sizeof * new_node);

	new_node->data = data;
	new_node->next = self->head;
	self->head = new_node;
}

// Function to insert a new node with given data in the list in ascending order.
void insert_in_order(List* self, int data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	ListNodePtr new_node = malloc(sizeof * new_node);
	new_node->data = data;
	new_node->next = NULL;

	while (current != NULL && current->data < data) {
		prev = current;
		current = current->next;
	}

	if (current == self->head) { // at front
		new_node->next = current;
		self->head = new_node;
	}
	else {                     // middle
		new_node->next = current;
		prev->next = new_node;
	}
}

// Function to delete the first occurrence of a node with given data from the list.
void delete_list(List* self, int data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	while (current != NULL) {
		if (current->data == data) {
			if (prev == NULL) {        // front of list
				self->head = current->next;
				free(current);
				current = self->head;
			}
			else {                    // middle of list
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}

// Function to free the memory allocated to a list and all its nodes.
void destroy_list(List* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		ListNodePtr to_free = current;
		current = current->next;
		free(to_free);
	}
	self->head = NULL;
}

// Helper functions for the ad-hoc menu (don't need to go in list.h)
void option_insert(List* self) {
    int data;
    printf("Enter integer to insert at front: ");
    scanf("%d", &data);
    insert_at_front(self, data);
    printf("Inserted %d at front.\n", data);
}

void option_delete(List* self) {
    int data;
    printf("Enter integer to delete: ");
    scanf("%d", &data);
    delete_list(self, data);
    printf("Deleted first occurrence of %d (if it existed).\n", data);
}

void option_print(List* self) {
    printf("Current list: ");
    print_list(self);
}

// Basic ad-hoc test (from step 1-2)
void list_adhoc_test_basic() {
    List myList = new_list();
    int input;
    
    printf("Enter integers to add to list (enter 0 to stop):\n");
    scanf("%d", &input);
    
    while (input != 0) {
        insert_at_front(&myList, input);
        scanf("%d", &input);
    }
    
    printf("Final list: ");
    print_list(&myList);
    destroy_list(&myList);
}

// Menu-based ad-hoc test (from step 3-5)
void list_adhoc_test() {
    List my_list = new_list();
    int quit = 0;  // 0 = false, continue running
    
    printf("\n=== Linked List Interactive Test Menu ===\n");
    
    while (!quit) {
        int option;
        
        // Display menu
        printf("\nMenu:\n");
        printf("  0 - Exit\n");
        printf("  1 - Insert integer at front\n");
        printf("  2 - Delete integer\n");
        printf("  3 - Print list\n");
        printf("Choose an option: ");
        
        scanf("%d", &option);
        
        if (option == 0) {
            quit = 1;
            printf("Exiting...\n");
        }
        else if (option == 1) {
            option_insert(&my_list);
        }
        else if (option == 2) {
            option_delete(&my_list);
        }
        else if (option == 3) {
            option_print(&my_list);
        }
        else {
            printf("Invalid option! Please enter 0, 1, 2, or 3.\n");
        }
    }
    
    destroy_list(&my_list);
    printf("List destroyed. Goodbye!\n");
}