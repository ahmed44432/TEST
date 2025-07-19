#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_bank_clint.h"
#include <iomanip>


using namespace std;

class cls_delete_clint_screen : protected cls_screen
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

	static void Delete_clint() {

		if (!check_access_rights(cls_user::en_permissions::e_delete_clint))
		{
			return;// this will exit the function and it will not continue
		}

		_Draw_screen_header("\tDelete Clint Screen");

		string accn = cls_input_validate::read_string("please enter Acc number : ");

		while (!cls_bank_clint::is_client_exist(accn)) {
			accn = cls_input_validate::read_string("this Acc number is not existed try another one : ");
		}

		cls_bank_clint old_clint = cls_bank_clint::Find(accn);
		_print_client(old_clint);

		bool choise = cls_input_validate::read_logical_question("\nare you sure you want to delete this clint y/n : ");

		if (choise) {

			if (old_clint.Delete())
			{
				cout << "\nClient Deleted Successfully :-)\n";

				_print_client(old_clint);
			}
			else
			{
				cout << "\nError Client Was not Deleted\n";
			}


		}


	}


};

