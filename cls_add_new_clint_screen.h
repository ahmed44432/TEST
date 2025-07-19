#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_bank_clint.h"
#include "cls_user.h"
#include <iomanip>


using namespace std;

class cls_add_new_clint_screen : protected cls_screen
{

	static void _read_clint_info(cls_bank_clint& Client)
	{
		Client.first_name = cls_input_validate::read_string("\nEnter First_Name: ");
		Client.last_name = cls_input_validate::read_string("\nEnter Last_Name: ");
		Client.email = cls_input_validate::read_string("\nEnter Email: ");
		Client.phone = cls_input_validate::read_string("\nEnter Phone: ");
		Client.pin_code = cls_input_validate::read_string("\nEnter PinCode: ");
		Client.Account_balance = cls_input_validate::read_float_number("\nEnter Account_Balance: ");
	}

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

	static void Add_new_clint() {

		if (!check_access_rights(cls_user::en_permissions::e_add_clint))
		{
			return;// this will exit the function and it will not continue
		}

		string accn = cls_input_validate::read_string("please enter Acc number : ");

		while (cls_bank_clint::is_client_exist(accn)) {
			accn = cls_input_validate::read_string("this Acc number is alredy exist try another one : ");
		}

		cls_bank_clint new_clint = cls_bank_clint::Get_Add_New_Client_Object(accn);

		_read_clint_info(new_clint);

		cls_bank_clint::en_save_results save_result;

		save_result = new_clint.Save();

		switch (save_result)
		{
		case  cls_bank_clint::en_save_results::sv_succeeded:
		{
			cout << "\nAccount Addeded Successfully :-)\n";
			_print_client(new_clint);
			break;
		}
		case cls_bank_clint::en_save_results::sv_faild_empty_object:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		case cls_bank_clint::en_save_results::sv_faild_account_number_exists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;

		}
		}


	}







};

