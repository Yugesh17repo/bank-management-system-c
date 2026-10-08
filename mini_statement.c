#include "header.h"

extern Account *head;

void mini_statement(void) {
        system("clear");
    uint32_t search_num;
    int found = 0;

    printf("\n========== MINI STATEMENT ==========\n");

    if (head == NULL) {
        printf("No accounts exist in the system yet.\n");
        printf("====================================\n");
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
            printf("\n--- Statement for %s ---\n", temp->Account_nme);
            printf("Current Balance: $%.2f\n", temp->Account_balance);
            printf("--------------------------------------------------\n");

            if (temp->Account_Transaction_count == 0) {
                printf("No transactions found for this account.\n");
            } else {
                // Determine how many transactions to show (max 5)
                int total = temp->Account_Transaction_count;
                int max_to_show = (total > MAX_HISY) ? MAX_HISY : total;

                // Find the oldest transaction in the circular buffer
                int start_idx = (total > MAX_HISY) ? (total % MAX_HISY) : 0;

                // Print the table header
                printf("%-12s | %-15s | %-15s\n", "Receipt ID", "Type", "Amount");
                printf("--------------------------------------------------\n");

                for (int i = 0; i < max_to_show; i++) {
                    int idx = (start_idx + i) % MAX_HISY;
                    char type_str[15];

                    // Convert the enum to a readable string
                    switch(temp->transaction[idx].type) {
                        case DEPOSIT:      strcpy(type_str, "DEPOSIT"); break;
                        case WITHDRAWAL:   strcpy(type_str, "WITHDRAWAL"); break;
                        case TRANSFER_IN:  strcpy(type_str, "TRANSFER IN"); break;
                        case TRANSFER_OUT: strcpy(type_str, "TRANSFER OUT"); break;
                        default:           strcpy(type_str, "UNKNOWN"); break;
                    }

                    // Print the formatted row
                    printf("%-12u | %-15s | $%.2f\n",
                           temp->transaction[idx].transaction_ID,
                           type_str,
                           temp->transaction[idx].amount);
                }
            }
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("\nError: Account Number %u not found.\n", search_num);
    }

    printf("==================================================\n");
    printf("Press enter to return to main menu...");
    __fpurge(stdin);
    getchar();
}