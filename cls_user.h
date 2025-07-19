#pragma once

#include <iostream>
#include "cls_person.h"
#include "cls_input_validate.h"
#include "cls_string.h"
#include "cls_util.h"
#include "cls_Date.h"
#include <fstream>
#include <iomanip>



using namespace std;

class cls_user : public cls_person
{
	enum en_mode { empty_mode = 0, update_mode = 1, add_new_mode = 2 };

	en_mode _MODE;
	string _user_name, _password ;
	int _permissions;
    static const short _encrypt_key = 5;
   

	bool _mark_for_delete = false;


    static cls_user _convert_line_to_user_object(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = cls_string::split_each_word_from_string(Line, Seperator);
        //0FN/1LN/2EM/3PH/4UN/5PS/6PR
        return cls_user(en_mode::update_mode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], cls_util::decrypt_word(vUserData[5],_encrypt_key), stoi(vUserData[6]));

    }


    struct st_login_regisrter_info;
    static st_login_regisrter_info _convert_line_to_struct(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = cls_string::split_each_word_from_string(Line, Seperator);

        st_login_regisrter_info lri;
        lri.register_date_and_time = vUserData[0];
        lri.user_name = vUserData[1];
        lri.password = cls_util::decrypt_word(vUserData[2],_encrypt_key) ;
        lri.permissions = stoi(vUserData[3]);
        return lri;

    }

    static string _convert_user_object_to_line(cls_user User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.first_name + Seperator;
        UserRecord += User.last_name + Seperator;
        UserRecord += User.email + Seperator;
        UserRecord += User.phone + Seperator;
        UserRecord += User.user_name + Seperator;
        UserRecord += cls_util::encrypt_word(User.password,_encrypt_key) + Seperator;
        UserRecord += to_string(User.permissions);

        return UserRecord;

    }

    string _convert_user_struct_to_line( string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += cls_Date::get_string_system_date_and_time() + Seperator;
        UserRecord += user_name + Seperator;
        UserRecord += cls_util::encrypt_word(password, _encrypt_key) + Seperator;
        UserRecord += to_string(permissions);

        return UserRecord;

    }

    static  vector <cls_user> _load_users_data_from_file()
    {

        vector <cls_user> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                cls_user User = _convert_line_to_user_object(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _save_users_data_to_file(vector <cls_user> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (cls_user U : vUsers)
            {
                if (U.marked_for_deleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _convert_user_object_to_line(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <cls_user> _vUsers;
        _vUsers = _load_users_data_from_file();

        for (cls_user& U : _vUsers)
        {
            if (U.user_name == user_name)
            {
                U = *this;
                break;
            }

        }

        _save_users_data_to_file(_vUsers);

    }

    void _Add_New()
    {

        _Add_Data_Line_To_File(_convert_user_object_to_line(*this));
    }

    void _Add_Data_Line_To_File(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static cls_user _Get_Empty_User_Object()
    {
        return cls_user(en_mode::empty_mode, "", "", "", "", "", "", 0);
    }

    static  vector <st_login_regisrter_info> _load_users_login_info_from_file(string file_name = "Login Time.txt")
    {

        vector <st_login_regisrter_info> vUsers;

        fstream MyFile;
        MyFile.open(file_name, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                st_login_regisrter_info User = _convert_line_to_struct(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

   


public:
    
    cls_user(en_mode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) :
        cls_person(FirstName, LastName, Email, Phone) {

        _MODE = Mode;
        _user_name = UserName;
        _password = Password;
        _permissions = Permissions;

    }

    struct st_login_regisrter_info {

        string register_date_and_time;
        string user_name , password;
        int permissions;
    };

    st_login_regisrter_info lri;

    enum en_permissions {
        e_full_permissions = -1,

        e_show_clint = 1,
        e_add_clint = 2,
        e_delete_clint = 4,
        e_update_clint_info = 8,
        e_find_clint = 16,
        e_transactions = 32,
        e_manager_users = 64,
        e_login_register_screen = 128
    };

    bool is_empty()
    {
        return (_MODE == en_mode::empty_mode);
    }



    bool marked_for_deleted() { return _mark_for_delete; }

    string get_user_name() { return _user_name; }

    string get_password() { return _password; }

    int get_permissions() { return _permissions; }

    


    void set_user_name(string un) {  _user_name = un; }
         
    void set_password(string psw) {  _password = psw; }
         
    void set_permissions(int pr) {  _permissions = pr; }



    __declspec(property(get = get_user_name, put = set_user_name))string user_name;

    __declspec(property(get = get_password, put = set_password))string password;

    __declspec(property(get = get_permissions, put = set_permissions))int permissions;



    static cls_user Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                cls_user User = _convert_line_to_user_object(Line);
                if (User.user_name == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _Get_Empty_User_Object();
    }

    static cls_user Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                cls_user User = _convert_line_to_user_object(Line);
                if (User.user_name == UserName && User.password == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _Get_Empty_User_Object();
    }

    enum en_save_results { sv_Faild_Empty_Object = 0, sv_Succeeded = 1, sv_Faild_User_Exists = 2 };

    en_save_results Save()
    {

        switch (_MODE)
        {
        case en_mode::empty_mode :
        {
            if (is_empty())
            {
                return en_save_results::sv_Faild_Empty_Object;
            }
        }

        case en_mode::update_mode :
        {
            _Update();
            return en_save_results::sv_Succeeded;

            break;
        }

        case en_mode::add_new_mode :
        {
            //This will add new record to file or database
            if (cls_user::is_user_exist(_user_name))
            {
                return en_save_results::sv_Faild_User_Exists;
            }
            else
            {
                _Add_New();
                //We need to set the mode to update after add new
                _MODE = en_mode::update_mode ;
                return en_save_results::sv_Succeeded;
            }

            break;
        }
        }

    }

    static bool is_user_exist(string UserName)
    {
        cls_user User = cls_user::Find(UserName);
        return (!User.is_empty());
    }

    bool Delete()
    {
        vector <cls_user> _vUsers;
        _vUsers = _load_users_data_from_file();

        for (cls_user& U : _vUsers)
        {
            if (U.user_name == _user_name)
            {
                U._mark_for_delete = true;
                break;
            }

        }

        _save_users_data_to_file(_vUsers);

        *this = _Get_Empty_User_Object();

        return true;

    }

    static cls_user get_add_new_user_object(string UserName)
    {
        return cls_user(en_mode::add_new_mode, "", "", "", "", UserName, "", 0);
    }

    static vector <cls_user> get_users_list()
    {
        return _load_users_data_from_file();
    }

    bool check_access_permission(en_permissions Permission)
    {
        if (this->permissions == en_permissions::e_full_permissions)
            return true;

        if ((Permission & this->permissions) == Permission)
            return true;
        else
            return false;

    }

    static vector <st_login_regisrter_info> get_user_login_info_pls() {
        return _load_users_login_info_from_file();
    }

    void login_time_in_file(string file_name = "Login Time.txt", string Seperator = "#//#") {

        fstream MyFile;
        MyFile.open(file_name, ios::out | ios::app);

        string line = _convert_user_struct_to_line();


        if (MyFile.is_open())
        {

            MyFile << line << endl;

            MyFile.close();
        }


    }


  



};

