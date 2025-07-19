#pragma once

#include <iostream>
#include "cls_Date.h"
#include "Global.h"

using namespace std;

class cls_screen
{


protected :

	static void _Draw_screen_header(string Title, string SubTitle = "") {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\t User :" << current_user.user_name << endl;
        cout << "\t\t\t\t\t Date :" << cls_Date::date_to_string(cls_Date::get_system_date()) << "\n\n";
           

	}

    static bool check_access_rights(cls_user::en_permissions Permission)
    {

        if (!current_user.check_access_permission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }



};

