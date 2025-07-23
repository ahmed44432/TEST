#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_currency.h"
#include <iomanip>


using namespace std;

class cls_currency_calculator_screen : protected cls_screen
{

private:

    static void _print_currency_rate(cls_currency currency)
    {
        cout << "\nCurrency Info:";
        cout << "\n___________________";
        cout << "\nCurrency Code  : " << currency.currency_code();
        cout << "\nRate           : " << currency.rate();
        cout << "\n___________________\n";

    }


public:

    static void show_update_currency_rate_screen()
    {

        _Draw_screen_header("\t  Update Currency Screen");


        float amount;
        string currency;
       

        currency = cls_input_validate::read_string("\nplease enter currency code name : ");
        while (!cls_currency::is_currency_exist(currency))
        {
            currency = cls_input_validate::read_string("\nCurrency code is not found, choose another one: ");
        }
        cls_currency C1 = cls_currency::find_by_code(currency);
        _print_currency_rate(C1);

        currency = cls_input_validate::read_string("\nplease enter currency code name : ");
        while (!cls_currency::is_currency_exist(currency))
        {
            currency = cls_input_validate::read_string("\nCurrency code is not found, choose another one: ");
        }
        cls_currency C2 = cls_currency::find_by_code(currency);
        _print_currency_rate(C2);

        amount = cls_input_validate::read_positive_float_number("\nenter Amount to Exchange : ");

        float result = cls_currency::convert_currency_to_another(C1, C2, amount);

        cout << endl << amount << " " << C1.currency_code() << " = " << result << " " << C2.currency_code() << endl;

        if (cls_input_validate::read_logical_question("\ndo you want to perform another calcolation (Y/N) : "))
        {
            system("cls");
            show_update_currency_rate_screen();
        }
        else
        {
            cout << "\nsee you later.\n";
        }







    }


};

