#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_input_validate.h"
#include "cls_bank_clint.h"
#include "cls_deposit_screen.h"
#include "cls_withdraw_screen.h"
#include "cls_total_balances_screen.h"
#include "cls_transfer_screen.h"
#include "cls_transfer_log_screen.h"
#include <iomanip>


using namespace std;


class cls_transactions_screen : protected cls_screen
{

private:

    enum en_transactions_menue_options {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4, eTransferLogRegister = 5, eShowMainMenue = 6
    };

    static short read_transactions_menue_option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";

        short Choice = 
            cls_input_validate::
            read_short_with_error_message_number_in_range(1, 6, "Enter Number between 1 to 6? ");

        return Choice;
    }

    static void _show_deposit_screen()
    {
        //cout << "\n Deposit Screen will be here.\n";
        cls_deposit_screen::show_deposit_screen();
    }

    static void _show_withdraw_screen()
    {
        //cout << "\n Withdraw Screen will be here.\n";
        cls_withdraw_screen::show_withdraw_screen();
    }

    static void _show_total_balances_screen()
    {
        //cout << "\n Balances Screen will be here.\n";
        cls_total_balances_screen::show_total_balances();

    }

    static void _show_transfer_screen()
    {
        //cout << "\n Transfer Screen will be here.\n";
        cls_transfer_screen::show_transfer_screen();

    }

    static void _show_transfer_log_register_screen() {
        //cout << "\n Transfer log register Screen will be here.\n";
        cls_transfer_log_screen::show_transfer_log_register_list();
    }

    static void _Go_back_to_transactions_menue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        show_transactions_menue();

    }

    static void _perform_transactions_menue_option(en_transactions_menue_options TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
            case en_transactions_menue_options::eDeposit:
            {
                system("cls");
                _show_deposit_screen();
                _Go_back_to_transactions_menue();
                break;
            }

            case en_transactions_menue_options::eWithdraw:
            {
                system("cls");
                _show_withdraw_screen();
                _Go_back_to_transactions_menue();
                break;
            }

            case en_transactions_menue_options::eShowTotalBalance:
            {
                system("cls");
                _show_total_balances_screen();
                _Go_back_to_transactions_menue();
                break;
            }

            case en_transactions_menue_options::eTransfer :
            {
                system("cls");
                _show_transfer_screen();
                _Go_back_to_transactions_menue();
                break;
            }

            case en_transactions_menue_options::eTransferLogRegister :
            {
                system("cls");
                _show_transfer_log_register_screen();
                _Go_back_to_transactions_menue();
                break;
            }


            case en_transactions_menue_options::eShowMainMenue:
            {
                //do nothing here the main screen will handle it :-) ;
            }

        }


    }



public:


    static void show_transactions_menue()
    {


        system("cls");
        _Draw_screen_header("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _perform_transactions_menue_option((en_transactions_menue_options)read_transactions_menue_option());
    }




};

