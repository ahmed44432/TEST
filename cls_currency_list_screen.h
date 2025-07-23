#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_input_validate.h"
#include "cls_currency.h"
#include "cls_util.h"
#include <iomanip>


using namespace std;

class cls_currency_list_screen : protected cls_screen
{

private :

    static void _print_currency_record_line(cls_currency currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << currency.country() ;
        cout << setw(3) << "| " << setw(5) << left << currency.currency_code();
        cout << "| " << setw(40) << left << currency.currency_name();
        cout << "| " << setw(20) << left << currency.rate();

    }


public :


    static void show_currency_list()
    {
        vector <cls_currency> vCurrency = cls_currency::get_currencies_list();

        string Title = "\t  Currency List Screen";
        string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Record(s).";

        _Draw_screen_header(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(6) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(10) << "Rate";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (cls_currency Currency : vCurrency)
            {

                _print_currency_record_line(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }



};

