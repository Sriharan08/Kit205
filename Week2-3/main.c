#include <stdio.h>
#include "list.h"

// Function to test the linked list implementation
void list_test() {
    // Test insert_at_front
    printf("Testing insert_at_front...\n");
    List myList = new_list();
    
    insert_at_front(&myList, 5);
    insert_at_front(&myList, 3);
    insert_at_front(&myList, 7);
    insert_at_front(&myList, 2);
    insert_at_front(&myList, 0);
    
    printf("Expected: 0, 2, 7, 3, 5\n");
    printf("Result: ");
    print_list(&myList);
    
    // Clean up
    destroy_list(&myList);
    
    // TODO: Add tests for insert_in_order and delete_list
}

int main() {
    list_test();
    return 0;
}