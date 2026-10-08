#include "header.h"

extern Account *head;

void deposit(void) {
    system("clear");
    uint32_t search_num;
    double amount;
    int found = 0;

    printf("\n========== DEPOSIT FUNDS ==========\n");

    if (head == NULL) {
        printf("No accounts exist in the system yet.\n");
        printf("===================================\n");
        printf("Press enter to return to main menu...");
        __fpurge(stdin);
        getchar();
        return;
    }

    printf("Enter the Account Number for deposit: ");
    scanf("%u", &search_num);

    Account *temp = head;

    while (temp != NULL) {
        if (temp->Account_num == search_num) {
            found = 1;
            printf("\n--- Account Found ---\n");
            printf("Account Owner   : %s\n", temp->Account_nme);
            printf("Current Balance : $%.2f\n", temp->Account_balance);

            printf("\nEnter amount to deposit: $");
            scanf("%lf", &amount);

            if (amount <= 0) {
                printf("\nError: Deposit amount must be greater than zero.\n");
            } else {
                temp->Account_balance += amount;

                // --- NEW TRANSACTION LOGGING LOGIC ---
                // Find the correct index (0-4) to store the transaction
                int t_index = temp->Account_Transaction_count % MAX_HISY;

                // Record the details
                temp->transaction[t_index].transaction_ID = 10000 + temp->Account_Transaction_count; // Generate a simple ID
                temp->transaction[t_index].type = DEPOSIT;
                temp->transaction[t_index].amount = amount;

                // Increment total transaction count AFTER logging
                temp->Account_Transaction_count += 1;

                printf("\n--- Transaction Successful ---\n");
                printf("New Balance     : $%.2f\n", temp->Account_balance);
            }
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("\nError: Account Number %u not found in the system.\n", search_num);
    }

    printf("===================================\n");
    printf("Press enter to return to main menu...");
    __fpurge(stdin);
    getchar();
}