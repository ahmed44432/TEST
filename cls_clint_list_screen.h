#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_bank_clint.h"
#include <iomanip>


using namespace std;


class cls_clint_list_screen : protected cls_screen
{
private : 

	static void _Print_client_record_line(cls_bank_clint Client)
	{

		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.get_account_number();
		cout << "| " << setw(20) << left << Client.full_name();
		cout << "| " << setw(12) << left << Client.phone;
		cout << "| " << setw(24) << left << Client.email;
		cout << "| " << setw(10) << left << Client.pin_code;
		cout << "| " << setw(12) << left << fixed << setprecision(2) << Client.Account_balance;

	}

public:

	static void Show_clients_list()
	{

		if (!check_access_rights(cls_user::en_permissions::e_show_clint))
		{
			return;// this will exit the function and it will not continue
		}

		vector <cls_bank_clint> vClients = cls_bank_clint::get_clints_list();
		string Title = "\t  Client List Screen";
		//string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

		_Draw_screen_header(Title);

		cout << setw(8) << "\n\t\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).\n";
		cout << setw(8) << left << "" << "______________________________________________________________";
		cout << "________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(24) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance\n";
		cout << setw(4) << left << "" << "______________________________________________________________";
		cout << "________________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!!!";
		else

			for (cls_bank_clint Client : vClients)
			{

				_Print_client_record_line(Client);
				cout << endl;
			}

		cout << setw(8) << left << "" << "______________________________________________________________";
		cout << "________________________________________________\n" << endl;

	}



};

