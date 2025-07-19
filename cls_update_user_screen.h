#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_user.h"
#include <iomanip>


using namespace std;

class cls_update_user_screen : protected cls_screen
{

	static void _print_user(cls_user user)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << user.first_name;
		cout << "\nLastName    : " << user.last_name;
		cout << "\nFull Name   : " << user.full_name();
		cout << "\nEmail       : " << user.email;
		cout << "\nPhone       : " << user.phone;
		cout << "\nUser Name   : " << user.user_name;
		cout << "\nPassword    : " << user.password;
		cout << "\nPermissions : " << user.permissions;
		cout << "\n___________________\n";

	}

	static void _read_info_to_update_client(cls_user & user)
	{

		short
			user_choise =
			cls_input_validate::
			read_number
			("what do you want to edit 1/First_Name; 2/Last_Name;3/Email; 4/Phone; 5/Password; 6/Permission ; any_n/all (default) ");

		switch (user_choise) {

		case 1:
			user.first_name = cls_input_validate::read_string("\nEnter First_Name: ");
			break;
		case 2:
			user.last_name = cls_input_validate::read_string("\nEnter Last_Name: ");
			break;

		case 3:
			user.email = cls_input_validate::read_string("\nEnter Email: ");
			break;

		case 4:
			user.phone = cls_input_validate::read_string("\nEnter Phone: ");
			break;
		case 5:
			user.password = cls_input_validate::read_string("\nEnter Password: ");
			break;
		case 6:
			user.permissions = _read_permissions("\nEnter Permission : ");
			break;

		default:

			user.first_name = cls_input_validate::read_string("\nEnter First_Name: ");
			user.last_name = cls_input_validate::read_string("\nEnter Last_Name: ");
			user.email = cls_input_validate::read_string("\nEnter Email: ");
			user.phone = cls_input_validate::read_string("\nEnter Phone: ");
			user.password = cls_input_validate::read_string("\nEnter Password: ");
			user.permissions = _read_permissions("\nEnter Permission : ");

			break;
		}


	}

	static int _read_permissions(string message) {

		int counter = 0;
		cout << message << endl;

		if (cls_input_validate::read_logical_question("do you want to give the ALL PERMISSIONS y/n : ")) {
			return counter += cls_user::e_full_permissions;
		}

		if (cls_input_validate::read_logical_question("do you want to give the authority to show a clint y/n : ")) {
			counter += cls_user::e_show_clint;
		}

		if (cls_input_validate::read_logical_question("do you want to give the authority to add a clint y/n : ")) {
			counter += cls_user::e_add_clint;
		}

		if (cls_input_validate::read_logical_question("do you want to give the authority to delete a clint y/n : ")) {
			counter += cls_user::e_delete_clint;
		}

		if (cls_input_validate::read_logical_question("do you want to give the authority to find a clint y/n : ")) {
			counter += cls_user::e_find_clint;
		}

		if (cls_input_validate::read_logical_question("do you want to give the authority to make transactions y/n : ")) {
			counter += cls_user::e_transactions;
		}

		if (cls_input_validate::read_logical_question("do you want to give the authority to show login register screen y/n : ")) {
			counter += cls_user::e_login_register_screen;
		}

		if (cls_input_validate::read_logical_question("do you want to give the authority to manage the users  y/n : ")) {
			counter += cls_user::e_manager_users;
		}

		return counter;
	}


public:


	static void update_user_info()
	{
		_Draw_screen_header("\tUpdate User Screen");

		string user_nm = "";

		user_nm = cls_input_validate::read_string("\nPlease Enter user name: ");

		while (!cls_user::is_user_exist(user_nm))
		{
			user_nm = cls_input_validate::read_string("\nuser name is not found, choose another one: ");
		}

		cls_user user = cls_user::Find(user_nm);
		_print_user(user);

		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";


		_read_info_to_update_client(user);

		cls_user::en_save_results save_result;

		save_result = user.Save();

		switch (save_result)
		{
			case   cls_user::en_save_results::sv_Succeeded:
			{
				cout << "\nAccount Updated Successfully :-)\n";
				_print_user(user);
				break;
			}
			case cls_user::en_save_results::sv_Faild_Empty_Object:
			{
				cout << "\nError account was not saved because it's Empty";
				break;

			}

		}



	}




};

