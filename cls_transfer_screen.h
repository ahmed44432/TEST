#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_input_validate.h"
#include "cls_bank_clint.h"
#include <iomanip>


using namespace std;

class cls_transfer_screen : protected cls_screen
{

	static void _print_client(cls_bank_clint Client)
	{
		cout << "\nClient Card:";
		cout << "\n______________________________";
		cout << "\nFull Name   : " << Client.full_name();
		cout << "\nAcc. Number : " << Client.get_account_number();
        cout << "\nBalance     : " << fixed << setprecision(2) << Client.Account_balance;
		cout << "\n______________________________\n";

	}

public:

    static void show_transfer_screen()
    {
        _Draw_screen_header("\t   transfer Screen");

        string ACN1 = cls_input_validate::read_string("\nPlease enter Account Number to Transfer from : ");

        while (!cls_bank_clint::is_client_exist(ACN1))
        {
            cout << "\nClient with [" << ACN1 << "] does not exist.\n";
            ACN1 = cls_input_validate::read_string("\nPlease enter Account Number : ");
        }

        cls_bank_clint Client1 = cls_bank_clint::Find(ACN1);
        _print_client(Client1);

        string ACN2 = cls_input_validate::read_string("\nPlease enter Account Number to Transfer to : ");

        while ((!cls_bank_clint::is_client_exist(ACN2)) || ACN1 == ACN2)
        {
            cout << "\nClient with [" << ACN2 << "] does not exist or the Client is the transfer from.\n";
            ACN2 = cls_input_validate::read_string("\nPlease enter new Account Number : ");
        }

        cls_bank_clint Client2 = cls_bank_clint::Find(ACN2);
        _print_client(Client2);

        double Amount = 0;
        Amount = cls_input_validate::read_positive_double_number("\nPlease enter the Transfer amount : ");

        
        if (cls_input_validate::read_logical_question("\nAre you sure you want to perform this transaction (Y/N) : "))
        {
            while (!Client1.Transfer(Amount,Client2)) {
                printf("Amount Exceeds The Balance, you can withdraw up to %.2f", Client1.Account_balance);
                Amount = cls_input_validate::read_positive_double_number("\nenter withdraw amount : ");
            }
            
            cout << "Client card :" << endl;
            _print_client(Client1);
            cout << endl;
            cout << "Client card :" << endl;
            _print_client(Client2);
            cout << endl;
            

        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }



};

