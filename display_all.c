#include "header.h"

extern Account *head;

void display_all(void) {
        system("clear");
    printf("\n========== ALL ACCOUNT DETAILS ==========\n");

    if (head == NULL) {
        printf("No accounts exist in the system yet.\n");
        printf("=========================================\n");

        // ADD THESE 3 LINES SO IT PAUSES ON AN EMPTY SYSTEM
        printf("press enter to return to main menu...");
        __fpurge(stdin);
        getchar();

        return;
    }

    Account *temp = head;

    // Traverse the Single Linked List until the end (NULL)
    while (temp != NULL) {
        printf("Account Number : %u\n", temp->Account_num);
        printf("Account Name   : %s\n", temp->Account_nme);
        printf("Contact Number : %s\n", temp->contact_num);
        printf("Balance        : $%.2f\n", temp->Account_balance);
        printf("-----------------------------------------\n");

        temp = temp->next;
    }

    printf("=========================================\n");
    printf("press enter to return to main menu...");
    __fpurge(stdin);
    getchar();
}