#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_user.h"
#include <iomanip>
#include "cls_main_screen.h"
#include "Global.h"

using namespace std;



class cls_login_screen : protected cls_screen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;

        short c = 3;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                --c;
                cout << "\nInvlaid Username/Password!\n";
                cout << "you have " << c << " trials to login\n\n";
                if (c == 0)
                {
                    cout << "\nYour are Locked after 3 faild trails \n\n";
                    return  false;
                }
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            current_user = cls_user::Find(Username, Password);

            LoginFaild = current_user.is_empty();


        } while (LoginFaild);

        current_user.login_time_in_file();
        cls_main_screen::Show_Main_Menue();
        return true;
    }

 

public:


    static bool show_login_screen()
    {
        system("cls");
        _Draw_screen_header("\t  Login Screen");
        return _Login();

    }



};

