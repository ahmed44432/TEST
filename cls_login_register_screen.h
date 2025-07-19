#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_user.h"
#include <iomanip>
#include "cls_main_screen.h"
#include "Global.h"

using namespace std;




class cls_login_register_screen : protected cls_screen
{


private:

    static void _print_record_line(cls_user::st_login_regisrter_info User)
    {

        cout << setw(8) << left << "" << "| " << setw(40) << left << User.register_date_and_time;
        cout << "| " << setw(20) << left << User.user_name;
        cout << "| " << setw(17) << left << User.password;
        cout << "| " << setw(12) << left << User.permissions;

    }

public:

    static void show_login_register_list()
    {
        if (!check_access_rights(cls_user::en_permissions::e_login_register_screen))
        {
            return;// this will exit the function and it will not continue
        }
        
        vector <cls_user::st_login_regisrter_info> vUsers = cls_user::get_user_login_info_pls();
        string Title = "\t  Login Register Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") Record(s).";

        _Draw_screen_header(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(40) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(17) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Records Available In the System!";
        else

            for (cls_user::st_login_regisrter_info & User : vUsers)
            {
                _print_record_line(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }






};

