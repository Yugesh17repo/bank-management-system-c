#include "header.h"

extern Account *head;

void balance_enquiry(void) {
        system("clear");
    uint32_t search_num;
    int found = 0;

    printf("\n========== BALANCE ENQUIRY ==========\n");

    if (head == NULL) {
        printf("No accounts exist in the system yet.\n");
        printf("=====================================\n");
        printf("Press enter to return to main menu...");
        __fpurge(stdin);
        getchar();
        return;
    }

    printf("Enter the Account Number: ");
    scanf("%u", &search_num);

    Account *temp = head;

    while (temp != NULL) {
        if (temp->Account_num == search_num) {
            found = 1;
            printf("\n--- Account Found ---\n");
            printf("Account Owner     : %s\n", temp->Account_nme);
            printf("Available Balance : $%.2f\n", temp->Account_balance);
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("\nError: Account Number %u not found in the system.\n", search_num);
    }

    printf("=====================================\n");
    printf("Press enter to return to main menu...");
    __fpurge(stdin);
    getchar();
}