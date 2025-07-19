#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_input_validate.h"
#include "cls_bank_clint.h"
#include "cls_list_users_screen.h"
#include "cls_add_new_user_screen.h"
#include "cls_delete_user_screen.h"
#include "cls_update_user_screen.h"
#include "cls_find_user_screen.h"
#include "cls_util.h"
#include <iomanip>


using namespace std;

class cls_manage_users_screen : cls_screen
{

private:


    enum en_manage_users_menue_options {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short _read_manage_users_menue_option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = cls_input_validate::read_short_with_error_message_number_in_range(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _go_back_to_manage_users_menue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        show_manage_users_menue();
    }

    static void _show_list_users_screen()
    {
        //cout << "\nList Users Screen Will Be Here.\n";
        cls_list_users_screen::show_users_list();
    }

    static void _show_add_new_user_screen()
    {
       // cout << "\nAdd New User Screen Will Be Here.\n";
        cls_add_new_user_screen::Show_add_new_user_screen();
    }

    static void _show_delete_user_screen()
    {
        //cout << "\nDelete User Screen Will Be Here.\n";
        cls_delete_user_screen::Delete_user();
    }

    static void _show_update_user_screen()
    {
        //cout << "\nUpdate User Screen Will Be Here.\n";
        cls_update_user_screen::update_user_info();
    }

    static void _show_find_user_screen()
    {
        //cout << "\nFind User Screen Will Be Here.\n";
        cls_find_user_screen::show_find_user_screen();
    }

    static void _perform_manage_users_menue_option(en_manage_users_menue_options ManageUsersMenueOption)
    {

        switch (ManageUsersMenueOption)
        {
        case en_manage_users_menue_options::eListUsers:
        {
            system("cls");
            _show_list_users_screen();
            _go_back_to_manage_users_menue();
            break;
        }

        case en_manage_users_menue_options::eAddNewUser:
        {
            system("cls");
            _show_add_new_user_screen();
            _go_back_to_manage_users_menue();
            break;
        }

        case en_manage_users_menue_options::eDeleteUser:
        {
            system("cls");
            _show_delete_user_screen();
            _go_back_to_manage_users_menue();
            break;
        }

        case en_manage_users_menue_options::eUpdateUser:
        {
            system("cls");
            _show_update_user_screen();
            _go_back_to_manage_users_menue();
            break;
        }

        case en_manage_users_menue_options::eFindUser:
        {
            system("cls");

            _show_find_user_screen();
            _go_back_to_manage_users_menue();
            break;
        }

        case en_manage_users_menue_options::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }



public:


    static void show_manage_users_menue()
    {

        if (!check_access_rights(cls_user::en_permissions::e_manager_users))
        {
            return;// this will exit the function and it will not continue
        }

        system("cls");
        _Draw_screen_header("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _perform_manage_users_menue_option((en_manage_users_menue_options)_read_manage_users_menue_option());
    }






};

