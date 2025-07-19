#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_bank_clint.h"
#include <iomanip>


using namespace std;

class cls_update_clint_screen : protected cls_screen
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

	static void _read_info_to_update_client(cls_bank_clint& Client)
	{

		short
			user_choise =
			cls_input_validate::
			read_number
			("what do you want to edit 1/First_Name; 2/Last_Name;3/Email; 4/Phone; 5/PinCode; 6/Account_Balance ; any_n/all (default) ");

		switch (user_choise) {

		case 1:
			Client.first_name = cls_input_validate::read_string("\nEnter First_Name: ");
			break;
		case 2:
			Client.last_name = cls_input_validate::read_string("\nEnter Last_Name: ");
			break;

		case 3:
			Client.email = cls_input_validate::read_string("\nEnter Email: ");
			break;

		case 4:
			Client.phone = cls_input_validate::read_string("\nEnter Phone: ");
			break;
		case 5:
			Client.pin_code = cls_input_validate::read_string("\nEnter PinCode: ");
			break;
		case 6:
			Client.Account_balance = cls_input_validate::read_float_number("\nEnter Account_Balance: ");
			break;

		default:

			Client.first_name = cls_input_validate::read_string("\nEnter First_Name: ");
			Client.last_name = cls_input_validate::read_string("\nEnter Last_Name: ");
			Client.email = cls_input_validate::read_string("\nEnter Email: ");
			Client.phone = cls_input_validate::read_string("\nEnter Phone: ");
			Client.pin_code = cls_input_validate::read_string("\nEnter PinCode: ");
			Client.Account_balance = cls_input_validate::read_float_number("\nEnter Account_Balance: ");

			break;
		}


	}


public:


	static void update_client_info()
	{

		if (!check_access_rights(cls_user::en_permissions::e_add_clint))
		{
			return;// this will exit the function and it will not continue
		}
		_Draw_screen_header("\tUpdate Clint Screen");

		string client_account_number = "";

		client_account_number = cls_input_validate::read_string("\nPlease Enter client Account Number: ");

		while (!cls_bank_clint::is_client_exist(client_account_number))
		{
			client_account_number = cls_input_validate::read_string("\nAccount number is not found, choose another one: ");
		}

		cls_bank_clint Client1 = cls_bank_clint::Find(client_account_number);
		_print_client(Client1);

		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";


		_read_info_to_update_client(Client1);

		cls_bank_clint::en_save_results save_result;

		save_result = Client1.Save();

		switch (save_result)
		{
		case   cls_bank_clint::en_save_results::sv_succeeded:
		{
			cout << "\nAccount Updated Successfully :-)\n";
			_print_client(Client1);
			break;
		}
		case cls_bank_clint::en_save_results::sv_faild_empty_object:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}

		}



	}



};

