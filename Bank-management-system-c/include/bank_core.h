#ifndef BANK_CORE_H
#define BANK_CORE_H

#include<stdint.h>

#define MAX_NME_LEN 50
#define MAX_PHN_LEN 15
#define MAX_HISY 5

typedef enum{
        DEPOSIT,
        WITHDRAWAL,
        TRANSFER_IN,
        TRANSFER_OUT
} TransactionType;

typedef struct{
        uint32_t transaction_ID;
       TransactionType type;
        double amount;
}Account_Transaction;

typedef struct AccountNode{
        uint32_t Account_num;
        char Account_nme[MAX_NME_LEN];
        char contact_num[MAX_PHN_LEN];
        double Account_balance;
        Account_Transaction transaction[MAX_HISY];
        int Account_Transaction_count;
        struct AccountNode*next;
}Account;
void Create_account(void);
void display_all(void);
void search_account(void);
void deposit(void);
void withdraw(void);
void transfer(void);
void mini_statement(void);
void balance_enquiry(void);
void save_accounts(void);
void load_accounts(void);
#endif