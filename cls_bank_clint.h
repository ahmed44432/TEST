#pragma once

#include <iostream>
#include <vector>
#include "cls_string.h"
#include <string>
#include "cls_input_validate.h"
#include "cls_person.h"
#include <fstream>
#include "Global.h"

using namespace std;


class cls_bank_clint : public cls_person 
{

private :

	enum en_mode {empty_mode = 0, update_mode = 1 , add_new_mode = 2};
	en_mode _Mode;

	string _Account_number, _Pin_code;
	double _Account_balance;
	bool _Mark_for_delete = false;

	static cls_bank_clint _Convert_Line_to_Client_Object(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;

		/*if (vClientData.size() < 7)
		{
			cout << "!!! Skipped bad line: " << Line << endl;
			return _Get_Empty_Client_Object();
		}*/
		vClientData = cls_string::split_each_word_from_string(Line, Seperator);

		return cls_bank_clint(en_mode::update_mode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}

	static cls_bank_clint _Get_Empty_Client_Object()
	{
		return cls_bank_clint(en_mode::empty_mode, "", "", "", "", "", "", 0);
	}

	static string _Convert_Client_Object_To_Line(cls_bank_clint Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.first_name + Seperator;
		stClientRecord += Client.last_name + Seperator;
		stClientRecord += Client.email + Seperator;
		stClientRecord += Client.phone + Seperator;
		stClientRecord += Client.get_account_number() + Seperator;
		stClientRecord += Client.pin_code + Seperator;
		stClientRecord += to_string(Client.Account_balance);

		return stClientRecord;

	}

	static  vector <cls_bank_clint> _Load_Clients_Data_From_File()
	{

		vector <cls_bank_clint> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				cls_bank_clint Client = _Convert_Line_to_Client_Object(Line);

				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return vClients;

	}

	static void _Save_Clients_Data_To_File(vector <cls_bank_clint> vClients)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (cls_bank_clint C : vClients)
			{
				if (C.get_mark_for_delete() == false) {
					DataLine = _Convert_Client_Object_To_Line(C);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <cls_bank_clint> _vClients;
		_vClients = _Load_Clients_Data_From_File();

		for (cls_bank_clint& C : _vClients)
		{
			if (C.get_account_number() == get_account_number())
			{
				C = *this;
				break;
			}

		}

		_Save_Clients_Data_To_File(_vClients);

	}

	void _Add_Data_Line_To_File(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();

		}

	}

	void _Add_New() {
		_Add_Data_Line_To_File(_Convert_Client_Object_To_Line(*this));
	}

	struct st_transfer_log;
	static st_transfer_log _convert_line_to_struct(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = cls_string::split_each_word_from_string(Line, Seperator);

		st_transfer_log TL;
		TL.log_time = vClientData[0];
		TL.ACN1 = vClientData[1];
		TL.ACN2 = vClientData[2];
		TL.amount = stoi(vClientData[3]);
		TL.BL1 = stoi(vClientData[4]);
		TL.BL2 = stoi(vClientData[5]);
		TL.user_name = vClientData[6];
		return TL;

	}

	string _convert_client_struct_to_line( cls_bank_clint CL2, double amount , string Seperator = "#//#")
	{

		string UserRecord = "";
	
		UserRecord += cls_Date::get_string_system_date_and_time() + Seperator;
		UserRecord += get_account_number() + Seperator;
		UserRecord += CL2.get_account_number() + Seperator;
		UserRecord += to_string(amount) + Seperator;
		UserRecord += to_string(Account_balance) + Seperator;
		UserRecord += to_string(CL2.Account_balance) + Seperator;
		UserRecord += current_user.user_name;

		return UserRecord;

	}

	static  vector <st_transfer_log> _load_transfer_log_info_from_file(string file_name = "Transfer Log.txt")
	{

		vector <st_transfer_log> vClient;

		fstream MyFile;
		MyFile.open(file_name, ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				st_transfer_log client = _convert_line_to_struct(Line);

				vClient.push_back(client);
			}

			MyFile.close();

		}

		return vClient;

	}

	void _register_transfer_log_in_file(cls_bank_clint CL2, double Amount, string file_name = "Transfer Log.txt", string Seperator = "#//#") {

		fstream MyFile;
		MyFile.open(file_name, ios::out | ios::app);

		string line = _convert_client_struct_to_line(CL2, Amount);


		if (MyFile.is_open())
		{

			MyFile << line << endl;

			MyFile.close();
		}


	}



public :

	
	
	cls_bank_clint(en_mode mode, string first_name, string last_name, string email,
		string phone, string Account_number, string Pin_code, float Account_balance) :
		cls_person(first_name,  last_name,  email, phone) {

		_Mode = mode;
		_Account_number = Account_number;
		_Pin_code = Pin_code;
		_Account_balance = Account_balance;

	}
	
	struct st_transfer_log
	{
		string log_time, ACN1, ACN2,user_name;
		double amount, BL1, BL2;

	};

	string get_account_number() {return _Account_number;}

	string get_pin_code() {return _Pin_code;}

	bool get_mark_for_delete() { return _Mark_for_delete; }

	float get_account_balance() {return _Account_balance;}

	void set_pin_code(string pin_code) { _Pin_code = pin_code ;}

	__declspec(property(get = get_pin_code, put = set_pin_code))string pin_code;

	void set_account_balance(float account_balance) {_Account_balance = account_balance;}

	__declspec(property(get = get_account_balance, put = set_account_balance))float Account_balance;




	bool is_empty() {
		return (_Mode == en_mode::empty_mode);
	}


	static cls_bank_clint Find(string AccountNumber)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				cls_bank_clint Client = _Convert_Line_to_Client_Object(Line);
				if (Client.get_account_number() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _Get_Empty_Client_Object();
	}

	static cls_bank_clint Find(string AccountNumber, string PinCode)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				cls_bank_clint Client = _Convert_Line_to_Client_Object(Line);
				if (Client.get_account_number() == AccountNumber && Client.pin_code == PinCode)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}
		return _Get_Empty_Client_Object();
	}

	static bool is_client_exist(string AccountNumber)
	{
		cls_bank_clint Client1 = cls_bank_clint::Find(AccountNumber);
		return (!Client1.is_empty());
	}

	enum en_save_results { sv_faild_empty_object = 0, sv_succeeded = 1 , sv_faild_account_number_exists = 2};

	en_save_results Save()
	{

		switch (_Mode)
		{
			case en_mode::empty_mode :
				{
					if (cls_bank_clint::is_client_exist(_Account_number)) {
						return en_save_results::sv_faild_empty_object;
					}
					break;
				}

			case en_mode::update_mode :
				{

					_Update();

					return en_save_results::sv_succeeded;

					break;
				}
			case en_mode::add_new_mode : {

				if (cls_bank_clint::is_client_exist(_Account_number)){
					return en_save_results::sv_faild_account_number_exists;
				}
				else
				{
					_Add_New();

					//We need to set the mode to update after add new
					_Mode = en_mode::update_mode;
					return en_save_results::sv_succeeded;
				}

			}
		



		}



	}

	static cls_bank_clint Get_Add_New_Client_Object(string AccountNumber)
	{
		return cls_bank_clint(en_mode::add_new_mode, "", "", "", "", AccountNumber, "", 0);

	}

	bool Delete() {

		vector <cls_bank_clint> vClients = _Load_Clients_Data_From_File();
		for (cls_bank_clint& i : vClients) {

			if (i._Account_number == _Account_number) {
				i._Mark_for_delete = true;
				break;
			}

		}

		_Save_Clients_Data_To_File(vClients);
		*this = _Get_Empty_Client_Object();

		return true;

	}

	static vector <cls_bank_clint> get_clints_list() {
		return _Load_Clients_Data_From_File();
	}

	static double get_total_balances() {

		vector <cls_bank_clint> vClints = _Load_Clients_Data_From_File();
		double tl = 0.0;

		for (cls_bank_clint& i : vClints) {
			tl += i.Account_balance;
		}
		return tl;

	}

	void Deposit(double Amount)
	{
		_Account_balance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _Account_balance)
		{
			return false;
		}
		else
		{
			_Account_balance -= Amount;
			Save();
			return true;
		}

	}

	bool Transfer(double Amount,cls_bank_clint& transfer_to )
	{
		if (Amount > _Account_balance)
		{
			return false;
		}
		Withdraw(Amount);
		transfer_to.Deposit(Amount);
		_register_transfer_log_in_file(transfer_to, Amount);
		return true;
	

	}

	static vector <st_transfer_log> get_transfer_log_info() {
		return _load_transfer_log_info_from_file();
	}





	
	

};




