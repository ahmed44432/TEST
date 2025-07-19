#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_input_validate.h"
#include "cls_bank_clint.h"
#include <iomanip>


using namespace std;

class cls_withdraw_screen : protected cls_screen
{

	static void _print_client(cls_bank_clint Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.first_name;
		cout << "\nLastName    : " << Client.last_name;
		cout << "\nFull Name   : " << Client.full_name();
		cout << "\nEmail       : " << Client.email;
		cout << "\nPhone       : " << Client.phone;
		cout << "\nAcc. Number : " << Client.get_account_number();
		cout << "\nPassword    : " << Client.pin_code;
		cout << "\nBalance     : " << Client.Account_balance;
		cout << "\n___________________\n";

	}


public :

    static void show_withdraw_screen()
    {
        _Draw_screen_header("\t   withdraw Screen");

        string AccountNumber = cls_input_validate::read_string("\nPlease enter Account Number : ");


        while (!cls_bank_clint::is_client_exist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = cls_input_validate::read_string("\nPlease enter Account Number : ");
        }

        cls_bank_clint Client1 = cls_bank_clint::Find(AccountNumber);
        _print_client(Client1);

        double Amount = 0;
        Amount = cls_input_validate::read_positive_double_number("\nPlease enter withdraw amount : ");

       /* while (Amount > Client1.Account_balance) {

            printf("Amount Exceeds The Balance, you can withdraw up to %.2f", Client1.Account_balance);
            Amount = cls_input_validate::read_positive_double_number("\nenter withdraw amount : ");

        }*/

        if (cls_input_validate::read_logical_question("\nAre you sure you want to perform this transaction : "))
        {
            if (Client1.Withdraw(Amount)) {
                cout << "\nAmount Withdrew  Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.Account_balance;

            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Client1.Account_balance;
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }


};

