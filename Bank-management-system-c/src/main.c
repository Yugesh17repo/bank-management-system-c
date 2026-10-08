#include"header.h"

// Global head pointer for the Single Linked List
Account *head = NULL;
// Function prototype
int main() {
    char choice;
    load_accounts();
    while (1) {
        printf("\n========== MENU ==========\n");
        printf("c/C: Create account\n");
        printf("d/D: Deposit amount\n");
        printf("w/W: Withdrawl amount\n");
        printf("t/T: Transfer amount\n");
        printf("b/B: Balance enquiry\n");
        printf("e/E: Display acocunt\n");
        printf("h/H: Transaction Mini statement(History)\n");
        printf("f/F: Search account\n");
        printf("s/S: save the accounts info\n");
        printf("q/Q: Quit from app\n");
        // We will add the other menu prints later as we build them
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Enter your choice:");
        __fpurge(stdin);
        choice = getchar();

        switch (choice) {
            case 'c': case 'C':
                Create_account();
                break;

            case 'd': case 'D':
                deposit();
                break;

            case 'w': case 'W':
                withdraw();
                break;

            case 'b': case 'B':
                balance_enquiry();
                break;

            case 't': case 'T':
                transfer();
                break;

            case 'e':case 'E':
                display_all();
                break;

            case 'h': case 'H':
                mini_statement();
                break;

            case 'f':case'F':
                search_account();
                break;

            case 's':case'S':
                save_accounts();
                break;

            case 'q': case 'Q':
                printf("Exiting application.\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}