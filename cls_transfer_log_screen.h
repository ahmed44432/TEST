#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_bank_clint.h"
#include <iomanip>
#include "cls_main_screen.h"
#include "Global.h"

using namespace std;



class cls_transfer_log_screen :protected cls_screen
{

private:

    static void _print_record_line(cls_bank_clint::st_transfer_log CR)
    {

        cout << setw(8) << left << "" << "| " << setw(25) << left << CR.log_time;
        cout << "| " << setw(8) << left << CR.ACN1;
        cout << "| " << setw(8) << left << CR.ACN2;
        cout << "| " << setw(8) << fixed << setprecision(2) << left << CR.amount;
        cout << "| " << setw(13) << fixed << setprecision(2) << left << CR.BL1;
        cout << "| " << setw(13) << fixed << setprecision(2) << left << CR.BL2;
        cout << "| " << setw(10) << left << CR.user_name;

    }

public:

    static void show_transfer_log_register_list()
    {
       
        vector <cls_bank_clint::st_transfer_log> vRecords = cls_bank_clint::get_transfer_log_info();
        string Title = "\t  Login Register Screen";
        string SubTitle = "\t    (" + to_string(vRecords.size()) + ") Record(s).";

        _Draw_screen_header(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(13) << "s.Balance";
        cout << "| " << left << setw(13) << "d.Balance";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vRecords.size() == 0)
            cout << "\t\t\t\tNo Records Available In the System!";
        else

            for (cls_bank_clint::st_transfer_log & Record : vRecords)
            {
                _print_record_line(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

