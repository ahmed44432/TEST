#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_input_validate.h"
#include "cls_bank_clint.h"
#include "cls_util.h"
#include <iomanip>


using namespace std;

class cls_total_balances_screen : protected cls_screen
{

private:

    static void _print_client_record_balance_line(cls_bank_clint Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.get_account_number();
        cout << "| " << setw(30) << left << Client.full_name();
        cout << "| " << setw(12) << left << fixed << setprecision(2) << Client.Account_balance;
    }

public:

    static void show_total_balances()
    {

        vector <cls_bank_clint> vClients = cls_bank_clint::get_clints_list();

        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _Draw_screen_header(Title, SubTitle);

        cout  << setw(16) << left << "" << "_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(30) << "Client Name";
        cout << "| " << left << setw(12) << "Balance\n";
        cout << setw(12) << left << "" << "_______________________________________________________";
        cout << "__________________________\n" << endl;

        double TotalBalances = cls_bank_clint::get_total_balances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (cls_bank_clint Client : vClients)
            {
                _print_client_record_balance_line(Client);
                cout << endl;
            }

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(8) << left << "" << "\t\t     Total Balances = " << TotalBalances << endl;
        cout << setw(8) << left << "" << "\t  ( " << cls_util::number_to_text(TotalBalances) << ")";
    }


};

