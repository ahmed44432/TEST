#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_user.h"
#include <iomanip>


using namespace std;

class cls_find_user_screen : protected cls_screen
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

public:

    static void show_find_user_screen()
    {

        _Draw_screen_header("\t  Find User Screen");

        if (!check_access_rights(cls_user::en_permissions::e_find_clint))
        {
            return;// this will exit the function and it will not continue
        }

        string User_Name;
      
        User_Name = cls_input_validate::read_string("\nPlease Enter UserName: ");
        while (!cls_user::is_user_exist(User_Name))
        {
            User_Name = cls_input_validate::read_string("\nUser is not found, choose another one: ");
        }

        cls_user User1 = cls_user::Find(User_Name);

        if (!User1.is_empty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _print_user(User1);

    }


};

