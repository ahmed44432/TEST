#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_input_validate.h"
#include "cls_currency_list_screen.h"
#include "cls_find_currency_screen.h"
#include "cls_update_currency_rate_screen.h"
#include "cls_currency_calculator_screen.h"
#include "cls_util.h"
#include <iomanip>


using namespace std;

class cls_currency_exhange_main_screen : protected cls_screen
{
private:


    enum en_currency_exhange_menue_options {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalculator = 4, eMainMenue = 5
    };

    static short _read_currency_exhange_menue_option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = cls_input_validate::read_short_with_error_message_number_in_range(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _go_back_to_currency_exhange_menue()
    {
        cout << "\n\nPress any key to go back to Currency Exhange Menue...";
        system("pause>0");
        show_currency_exhange_menue();
    }

    static void _show_currency_list_screen()
    {
       //cout << "\nCurrency List Screen Will Be Here.\n";
        cls_currency_list_screen::show_currency_list();
    }

    static void _show_find_currency_screen()
    {
       // cout << "\nFind Currency Screen Will Be Here.\n";
        cls_find_currency_screen::show_find_currency_screen();
    }

    static void _show_update_rate_screen()
    {
        //cout << "\nUpdate Rate Screen Will Be Here.\n";
        cls_update_currency_rate_screen::show_update_currency_rate_screen();
    }

    static void _show_currency_calculator_screen()
    {
       // cout << "\nCurrency Calculator Screen Will Be Here.\n";
        cls_currency_calculator_screen::show_update_currency_rate_screen();
    }

    static void _Go_back_to_currency_exhange_menue()
    {
        cout << "\n\nPress any key to go back to Currency Exhange Menue...";
        system("pause>0");
        show_currency_exhange_menue();

    }

    static void _perform_currency_exhange_menue_option(en_currency_exhange_menue_options ManageCurrencyExhangeOption) {

        switch (ManageCurrencyExhangeOption) {

            case en_currency_exhange_menue_options::eListCurrencies :
            {
                system("cls");
                _show_currency_list_screen();
                _Go_back_to_currency_exhange_menue();
                break;
            }

            case en_currency_exhange_menue_options::eFindCurrency :
            {
                system("cls");
                _show_find_currency_screen();
                _Go_back_to_currency_exhange_menue();
                break;
            }

            case en_currency_exhange_menue_options::eUpdateRate :
            {
                system("cls");
                _show_update_rate_screen();
                _Go_back_to_currency_exhange_menue();
                break;
            }

            case en_currency_exhange_menue_options::eCurrencyCalculator :
            {
                system("cls");
                _show_currency_calculator_screen();
                _Go_back_to_currency_exhange_menue();
                break;
            }

            case en_currency_exhange_menue_options::eMainMenue :
            {
                //I LOVE FC BARCALONA
            }


        }

    }




public:


    static void show_currency_exhange_menue()
    {


        system("cls");
        _Draw_screen_header("\t Currency Exhange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _perform_currency_exhange_menue_option((en_currency_exhange_menue_options)_read_currency_exhange_menue_option());
    }



};

