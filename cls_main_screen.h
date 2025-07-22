#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_input_validate.h"
#include "cls_clint_list_screen.h"
#include "cls_add_new_clint_screen.h"
#include "cls_find_clint_screen.h"
#include "cls_delete_clint_screen.h"
#include "cls_update_clint_screen.h"
#include "cls_transactions_screen.h"
#include "cls_manage_users_screen.h"
#include "cls_login_register_screen.h"
#include "cls_currency_exhange_main_screen.h"
#include "Global.h"
#include <iomanip>


using namespace std;

class cls_main_screen :  cls_screen
{

private:

    enum en_main_menue_options {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegisterScreen = 8, eCurrencyExhangeMenue = 9, eExit = 10
    };

    static short _read_main_menue_option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = cls_input_validate::read_short_with_error_message_number_in_range(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _Go_back_to_main_menue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        Show_Main_Menue();
    }

    static void _show_all_clients_screen()
    {
       // cout << "\nClient List Screen Will be here...\n";
        cls_clint_list_screen::Show_clients_list();

    }

    static void _show_add_new_clients_screen()
    {
       // cout << "\nAdd New Client Screen Will be here...\n";
        cls_add_new_clint_screen::Add_new_clint();
    }

    static void _show_delete_client_screen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
        cls_delete_clint_screen::Delete_clint();
    }

    static void _show_update_client_screen()
    {
        //cout << "\nUpdate Client Screen Will be here...\n";
        cls_update_clint_screen::update_client_info();
    }

    static void _show_find_client_screen()
    {
       //cout << "\nFind Client Screen Will be here...\n";
        cls_find_clint_screen::show_find_client_screen();
    }

    static void _show_transactions_menue()
    {
        //cout << "\nTransactions Menue Will be here...\n";
        cls_transactions_screen::show_transactions_menue();
    }

    static void _show_manage_users_menue()
    {
        //cout << "\nUsers Menue Will be here...\n";
        cls_manage_users_screen::show_manage_users_menue();
    }

    static void _show_login_register_screen()
    {
        //cout << "\nlogin_register_screen Will be here...\n";
        cls_login_register_screen::show_login_register_list();
    }

    static void _show_currency_exhange_main_screen()
    {
        //cout << "\ncurrency_exhange_main_screen Will be here...\n";
        cls_currency_exhange_main_screen::show_currency_exhange_menue();
    }

    static void _logout_screen()
    {
        //cout << "\nlogout Screen Will be here...\n";
        current_user = cls_user::Find("", "");
       
    }

    
    static void _perfrom_main_menue_option(en_main_menue_options MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case en_main_menue_options::eListClients:
        {
            system("cls");
            _show_all_clients_screen();
            _Go_back_to_main_menue();
            break;
        }
        case en_main_menue_options::eAddNewClient:
            system("cls");
            _show_add_new_clients_screen();
            _Go_back_to_main_menue();
            break;

        case en_main_menue_options::eDeleteClient:
            system("cls");
            _show_delete_client_screen();
            _Go_back_to_main_menue();
            break;

        case en_main_menue_options::eUpdateClient:
            system("cls");
            _show_update_client_screen();
            _Go_back_to_main_menue();
            break;

        case en_main_menue_options::eFindClient:
            system("cls");
            _show_find_client_screen();
            _Go_back_to_main_menue();
            break;

        case en_main_menue_options::eShowTransactionsMenue:
            system("cls");
            _show_transactions_menue();
            _Go_back_to_main_menue();
            break;

        case en_main_menue_options::eManageUsers:
            system("cls");
            _show_manage_users_menue();
            _Go_back_to_main_menue();
            break;

        case en_main_menue_options::eLoginRegisterScreen :
            system("cls");
            _show_login_register_screen();
            _Go_back_to_main_menue();
            break;

        case en_main_menue_options::eCurrencyExhangeMenue :
            system("cls");
            _show_currency_exhange_main_screen();
            _Go_back_to_main_menue();
            break;

        case en_main_menue_options::eExit:
            system("cls");
            _logout_screen();
            break;
        }

    }



public:


    static void Show_Main_Menue()
    {

        system("cls");
        _Draw_screen_header("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Show Login Register .\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exhange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _perfrom_main_menue_option((en_main_menue_options)_read_main_menue_option());
    }









};

