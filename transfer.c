#include "header.h"

extern Account *head;

void transfer(void) {
        system("clear");
    uint32_t src_num, dest_num;
    double amount;
    Account *src_acc = NULL;
    Account *dest_acc = NULL;

    printf("\n========== MONEY TRANSFER ==========\n");

    if (head == NULL) {
        printf("No accounts exist in the system yet.\n");
        printf("====================================\n");
        printf("Press enter to return to main menu...");
        __fpurge(stdin);
        getchar();
        return;
    }

    printf("Enter your Account Number (Sender): ");
    scanf("%u", &src_num);

    printf("Enter destination Account Number (Receiver): ");
    scanf("%u", &dest_num);

    if (src_num == dest_num) {
        printf("\nError: Cannot transfer money to the same account.\n");
        printf("====================================\n");
        printf("Press enter to return to main menu...");
        __fpurge(stdin);
        getchar();
        return;
    }

    // Traverse the list once to find both accounts
    Account *temp = head;
    while (temp != NULL) {
        if (temp->Account_num == src_num) {
            src_acc = temp;
        }
        if (temp->Account_num == dest_num) {
            dest_acc = temp;
        }
        temp = temp->next;
    }

    if (src_acc == NULL) {
        printf("\nError: Sender Account %u not found.\n", src_num);
    }
    else if (dest_acc == NULL) {
        printf("\nError: Receiver Account %u not found.\n", dest_num);
    }
    else {
        printf("\nSender Balance: $%.2f\n", src_acc->Account_balance);
        printf("Enter amount to transfer: $");
        scanf("%lf", &amount);

        if (amount <= 0) {
            printf("\nError: Transfer amount must be greater than zero.\n");
        }
        else if (amount > src_acc->Account_balance) {
            printf("\nError: Insufficient funds. Your balance is only $%.2f.\n", src_acc->Account_balance);
        }
        else {
            // 1. Process Sender Math and Log TRANSFER_OUT
            src_acc->Account_balance -= amount;
            int src_index = src_acc->Account_Transaction_count % MAX_HISY;
            src_acc->transaction[src_index].transaction_ID = 10000 + src_acc->Account_Transaction_count;
            src_acc->transaction[src_index].type = TRANSFER_OUT;
            src_acc->transaction[src_index].amount = amount;
            src_acc->Account_Transaction_count += 1;

            // 2. Process Receiver Math and Log TRANSFER_IN
            dest_acc->Account_balance += amount;
            int dest_index = dest_acc->Account_Transaction_count % MAX_HISY;
            dest_acc->transaction[dest_index].transaction_ID = 10000 + dest_acc->Account_Transaction_count;
            dest_acc->transaction[dest_index].type = TRANSFER_IN;
            dest_acc->transaction[dest_index].amount = amount;
            dest_acc->Account_Transaction_count += 1;

            printf("\n--- Transfer Successful ---\n");
            printf("Transferred $%.2f to %s.\n", amount, dest_acc->Account_nme);
            printf("Your New Balance: $%.2f\n", src_acc->Account_balance);
        }
    }

    printf("====================================\n");
    printf("Press enter to return to main menu...");
    __fpurge(stdin);
    getchar();
}