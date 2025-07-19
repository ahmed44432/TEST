#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_input_validate.h"
#include "cls_bank_clint.h"
#include <iomanip>


using namespace std;

class cls_deposit_screen : protected cls_screen
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

    static string _read_account_number()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:

    static void show_deposit_screen()
    {
        _Draw_screen_header("\t   Deposit Screen");

        string AccountNumber = _read_account_number();


        while (!cls_bank_clint::is_client_exist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _read_account_number();
        }

        cls_bank_clint Client1 = cls_bank_clint::Find(AccountNumber);
        _print_client(Client1);

        double Amount = 0;
        Amount = cls_input_validate::read_double_number("\nPlease enter deposit amount : ");

        

        if (cls_input_validate::read_logical_question("\nAre you sure you want to perform this transaction : "))
        {
            Client1.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.Account_balance;

        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }



};

