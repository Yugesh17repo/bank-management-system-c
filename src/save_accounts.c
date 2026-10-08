#include "header.h"

extern Account *head;

void save_accounts(void) {
        system("clear");
    printf("\n========== SAVE DATABASE ==========\n");

    if (head == NULL) {
        printf("No accounts to save.\n");
        printf("===================================\n");
        printf("Press enter to return to main menu...");
        __fpurge(stdin);
        getchar();
        return;
    }

    // Open file in binary write mode ("wb")
    FILE *fp = fopen("bank_database.dat", "wb");
    if (fp == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    Account *temp = head;
    int count = 0;

    // Write each node to the file one by one
    while (temp != NULL) {
        fwrite(temp, sizeof(Account), 1, fp);
        temp = temp->next;
        count++;
    }

    fclose(fp);
    printf("Successfully saved %d account(s) to disk.\n", count);
    printf("===================================\n");
    printf("Press enter to return to main menu...");
    __fpurge(stdin);
    getchar();
}