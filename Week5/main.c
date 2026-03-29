#include <stdio.h>
#include "bst.h"

int main() {
    // Run automated tests
    bst_test();

    // Run interactive test
    printf("\nStarting interactive test...\n");
    bst_adhoc_test();

    return 0;
}