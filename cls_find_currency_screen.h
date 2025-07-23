#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_currency.h"
#include <iomanip>


using namespace std;

class cls_find_currency_screen : protected cls_screen
{

private :

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


public :

    static void show_find_currency_screen()
    {

        _Draw_screen_header("\t  Find Currency Screen");


        short n;
        string currency;
        

        n = cls_input_validate::read_number_in_range(1,2,"\nFind by : [1] Code or [2] Country : ");
        if (n == 2) {
            currency = cls_input_validate::read_string("please enter country name : ");
            while (!cls_currency::is_currency_exist_by_cn(currency))
            {
                currency = cls_input_validate::read_string("\nCountry is not found, choose another one: ");
            }
            cls_currency c_info = cls_currency::find_by_country(currency);

            if (!(c_info.is_empty()))
            {
                cout << "\nUser Found :-)\n";
                _print_currency(c_info);
            }
            else
            {
                cout << "\nUser Was not Found :-(\n";
            }

           

        }
        else {

            currency = cls_input_validate::read_string("please enter currency code name : ");
            while (!cls_currency::is_currency_exist(currency))
            {
                currency = cls_input_validate::read_string("\nCurrency code is not found, choose another one: ");
            }
            cls_currency c_info = cls_currency::find_by_code(currency);

            if (!(c_info.is_empty()))
            {
                cout << "\nUser Found :-)\n";
                _print_currency(c_info);
            }
            else
            {
                cout << "\nUser Was not Found :-(\n";
            }

            
        }

       

  

    }


};

