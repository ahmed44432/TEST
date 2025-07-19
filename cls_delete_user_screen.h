#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_user.h"
#include <iomanip>


using namespace std;

class cls_delete_user_screen : protected cls_screen
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

public :

	static void Delete_user() {

		_Draw_screen_header("\tDelete User Screen");

		string user_nm = cls_input_validate::read_string("please enter user name : ");

		while (!cls_user::is_user_exist(user_nm)) {
			user_nm = cls_input_validate::read_string("this Acc number is not existed try another one : ");
		}

		cls_user old_user = cls_user::Find(user_nm);
		_print_user(old_user);

		bool choise = cls_input_validate::read_logical_question("\nare you sure you want to delete this clint y/n : ");

		if (choise) {

			if (old_user.Delete())
			{
				cout << "\nClient Deleted Successfully :-)\n";

				_print_user(old_user);
			}
			else
			{
				cout << "\nError Client Was not Deleted\n";
			}


		}


	}


};

