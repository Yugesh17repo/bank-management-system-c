#include "header.h"

// Access the global list head defined in main.c
extern Account *head;

void Create_account(void) {
    Account *new_acc = (Account *)malloc(sizeof(Account));
    if (new_acc == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("\n--- Create New Account ---\n");
    printf("Enter Account Name: ");
    scanf(" %49[^\n]", new_acc->Account_nme);

    printf("Enter Contact Number: ");
    scanf(" %14s", new_acc->contact_num);

    new_acc->Account_balance = 0.0;
    new_acc->Account_Transaction_count = 0;
    new_acc->next = NULL;

    // 1. FIND THE HIGHEST ACCOUNT NUMBER
    // Since the list is no longer sorted by ID, we must find the highest existing ID first
    uint32_t max_id = 100000;
    Account *id_temp = head;
    while (id_temp != NULL) {
        if (id_temp->Account_num > max_id) {
            max_id = id_temp->Account_num;
        }
        id_temp = id_temp->next;
    }
    new_acc->Account_num = max_id + 1;

    // 2. ALPHABETICAL INSERTION LOGIC
    if (head == NULL) {
        // Case 1: Empty list (First account ever)
        head = new_acc;
    }
    else if (strcmp(new_acc->Account_nme, head->Account_nme) < 0) {
        // Case 2: Insert at Beginning (like your add_node_begin function)
        // If the new name comes alphabetically BEFORE the current head
        new_acc->next = head;
        head = new_acc;
    }
    else {
        // Case 3: Insert at Middle (add_pos) or End (add_node_last)
        Account *temp = head;

        // Traverse until we find a node whose NEXT name is alphabetically greater than our new name
        while (temp->next != NULL && strcmp(new_acc->Account_nme, temp->next->Account_nme) > 0) {
            temp = temp->next;
        }

        // Link the new account exactly where the traversal stopped
        new_acc->next = temp->next;
        temp->next = new_acc;
    }

    printf("\nSuccess! Account created.\n");
    printf("Your unique Account Number is: %u\n", new_acc->Account_num);

    // Pause the screen before returning to the main menu
    printf("\npress enter to return to main menu...");
    __fpurge(stdin);
    getchar();
}