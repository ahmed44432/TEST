#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_user.h"
#include <iomanip>


using namespace std;

class cls_add_new_user_screen : protected cls_screen
{

	static void _read_user_info(cls_user& user)
	{
		user.first_name = cls_input_validate::read_string("\nEnter First_Name: ");
		user.last_name = cls_input_validate::read_string("\nEnter Last_Name: ");
		user.email = cls_input_validate::read_string("\nEnter Email: ");
		user.phone = cls_input_validate::read_string("\nEnter Phone: ");
		user.password = cls_input_validate::read_string("\nEnter Password: ");
		user.permissions = _read_permissions("\nEnter Permission : ");
	}

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

	static void Show_add_new_user_screen()
	{

		_Draw_screen_header("\t  Add New User Screen");

		string User_Name = "";

	
		User_Name = cls_input_validate::read_string("\nPlease Enter UserName: ");
		while (cls_user::is_user_exist(User_Name))
		{
			User_Name = cls_input_validate::read_string("\nUserName Is Already Used, Choose another one: ");
		}

		cls_user NewUser = cls_user::get_add_new_user_object(User_Name);

		_read_user_info(NewUser);

		cls_user::en_save_results SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case  cls_user::en_save_results::sv_Succeeded:
		{
			cout << "\nUser Addeded Successfully :-)\n";
			_print_user(NewUser);
			break;
		}
		case cls_user::en_save_results::sv_Faild_Empty_Object:
		{
			cout << "\nError User was not saved because it's Empty";
			break;

		}
		case cls_user::en_save_results::sv_Faild_User_Exists:
		{
			cout << "\nError User was not saved because UserName is used!\n";
			break;

		}
		}
	}



};

