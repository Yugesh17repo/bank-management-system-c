#include "header.h"

extern Account *head;

void load_accounts(void) {
                system("clear");
    // Open file in binary read mode ("rb")
    FILE *fp = fopen("bank_database.dat", "rb");

    if (fp == NULL) {
        // If file doesn't exist yet (first time running), just return silently
        return;
    }

    Account temp_node;
    Account *tail = NULL;
    int count = 0;

    // Read exactly one Account struct size of data at a time
    while (fread(&temp_node, sizeof(Account), 1, fp) == 1) {
        // Allocate fresh memory for the new node
        Account *new_node = (Account *)malloc(sizeof(Account));

        if (new_node == NULL) {
            printf("Memory allocation failed during loading.\n");
            break;
        }

        // Copy all the data (name, balance, transaction arrays) into the heap memory
        *new_node = temp_node;

        // CRITICAL: We must reset the 'next' pointer because the memory address
        // saved in the file is no longer valid in this new program session.
        new_node->next = NULL;

        // String the nodes together into the linked list
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        count++;
    }

    fclose(fp);

    // Print a nice confirmation message at startup if data was found
    if (count > 0) {
        printf(">>> Successfully loaded %d previous account(s) from disk. <<<\n", count);
        __fpurge(stdin);
        printf("Press enter to continue to menu...");
        __fpurge(stdin);
        getchar();
    }
}