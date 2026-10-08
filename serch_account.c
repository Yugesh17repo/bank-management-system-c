#include "header.h"

// Access the global list head defined in main.c
extern Account *head;

void search_account(void) {
    system("clear");
    uint32_t search_num;
    int found = 0;

    printf("\n========== SEARCH ACCOUNT ==========\n");

    if (head == NULL) {
        printf("No accounts exist in the system yet.\n");
        printf("====================================\n");
        return;
    }

    printf("Enter the Account Number to search: ");
    scanf("%u", &search_num);

    Account *temp = head;

    // Traverse the list looking for a match
    while (temp != NULL) {
        if (temp->Account_num == search_num) {
            printf("\n--- Account Found ---\n");
            printf("Account Number : %u\n", temp->Account_num);
            printf("Account Name   : %s\n", temp->Account_nme);
            printf("Contact Number : %s\n", temp->contact_num);
            printf("Balance        : $%.2f\n", temp->Account_balance);
            found = 1;
            break; // Stop searching once we find it
        }
        temp = temp->next;
    }

    if (!found) {
        printf("\nError: Account Number %u not found in the system.\n", search_num);
    }

    printf("====================================\n");
    // pause the screen before returning to the main//
    printf("press enter to return to main menu...");
    __fpurge(stdin);
    getchar();
}