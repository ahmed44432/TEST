#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_currency.h"
#include <iomanip>


using namespace std;

class cls_update_currency_rate_screen : protected cls_screen
{

private:

    static void _print_currency(cls_currency currency)
    {
        cout << "\nCurrency Info:";
        cout << "\n___________________";
        cout << "\nCountry        : " << currency.country();
        cout << "\nCurrency Code  : " << currency.currency_code();
        cout << "\nCurrency Name  : " << currency.currency_name();
        cout << "\nRate           : " << currency.rate();
        cout << "\n___________________\n";

    }


public:

    static void show_update_currency_rate_screen()
    {

        _Draw_screen_header("\t  Update Currency Screen");


        float f;
        string currency;

         currency = cls_input_validate::read_string("\nplease enter currency code name : ");
         while (!cls_currency::is_currency_exist(currency))
         {
             currency = cls_input_validate::read_string("\nCurrency code is not found, choose another one: ");
         }
         cls_currency c_info = cls_currency::find_by_code(currency);
         _print_currency(c_info);

         if (cls_input_validate::read_logical_question("\nare tou sur you want to update the Rate (Y/N) : "))
         {
             f = cls_input_validate::read_positive_float_number("\nenter new Rate : ");
             c_info.update_rate(f);
             _print_currency(c_info);
             cout << "\nAccount Updated Successfully :-)\n";
         }
         else
         {
             cout << "\nOperation was cancelled.\n";
         }


      




    }


};

