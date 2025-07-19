#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_input_validate.h"
#include "cls_bank_clint.h"
#include <iomanip>


using namespace std;

class cls_find_clint_screen : protected cls_screen
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
		cout << "\nBalance     : " << fixed << setprecision(2) << Client.Account_balance;
		cout << "\n___________________\n";

	}

public:

    static void show_find_client_screen() {

        _Draw_screen_header("\tFind Client Screen");

        string Account_number;
       
        Account_number = cls_input_validate::read_string("\nPlease Enter Account Number: ");
        while (!cls_bank_clint::is_client_exist(Account_number))
        {
            Account_number = cls_input_validate::read_string("\nAccount number is not found, choose another one: ");
        }

        cls_bank_clint Client1 = cls_bank_clint::Find(Account_number);

        if (!Client1.is_empty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _print_client(Client1);

    }



};

