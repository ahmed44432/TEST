#pragma once


#include <iostream>
#include "cls_Date.h"
#include "cls_periode.h"
#include <string>

using namespace std;

class cls_input_validate
{


public :

	static bool is_number_between(int number, int from, int to) {
		return (number >= from && number <= to);
	}

	static bool is_number_between(double number, double from, double to) {
		return (number >= from && number <= to);
	}

	static bool is_number_between(float number, float from, float to) {
		return (number >= from && number <= to);
	}

	static bool is_number_between(cls_Date date, cls_Date from, cls_Date to) {
		cls_periode p(from, to);
		return cls_periode::is_date_within_this_period(p, date);
	}

	static int read_number(string message) {

		int user_choise = 0;

		cout << message;
		cin >> user_choise;
		cout << endl;

		while (cin.fail()) {

			//input not a number
			cin.clear();
			cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

			cout << "invalid number!! enter another one : \n";
			cin >> user_choise;


		}

		return user_choise;
	}

	static long long read_long_number(string message) {

		long long user_choise = 0;

		cout << message;
		cin >> user_choise;
		cout << endl;

		while (cin.fail()) {

			//input not a number
			cin.clear();
			cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

			cout << "invalid number!! enter another one : \n";
			cin >> user_choise;


		}

		return user_choise;
	}

	static float read_float_number(string message) {

		float user_choise = 0;

		cout << message;
		cin >> user_choise;
		cout << endl;

		while (cin.fail()) {

			//input not a number
			cin.clear();
			cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

			cout << "invalid number!! enter another one : \n";
			cin >> user_choise;


		}

		return (float)user_choise;
	}

	static double read_double_number(string message) {

		double user_choise = 0;

		cout << message;
		cin >> user_choise;
		cout << endl;

		while (cin.fail()) {

			//input not a number
			cin.clear();
			cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

			cout << "invalid number!! enter another one : \n";
			cin >> user_choise;


		}

		return (double)user_choise;
	}

	static int read_positive_number(string message) {

		int user_choise = 0;
		do {

			cout << message;
			cin >> user_choise;

			while (cin.fail()) {

				//input not a number
				cin.clear();
				cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

				cout << "invalid number!! enter another one : \n";
				cin >> user_choise;


			}



		} while (user_choise < 0);

		return user_choise;

	}

	static double read_positive_double_number(string message) {

		double user_choise = 0;
		do {

			cout << message;
			cin >> user_choise;

			while (cin.fail()) {

				//input not a number
				cin.clear();
				cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

				cout << "invalid number!! enter another one : \n";
				cin >> user_choise;


			}



		} while (user_choise < 0.0);

		return user_choise;

	}

	static int read_number_in_range(int from, int to) {

		int user_choise = 0;
		do {


			cin >> user_choise;

			while (cin.fail()) {

				//input not a number
				cin.clear();
				cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

				cout << "invalid number!! enter another one : \n";
				cin >> user_choise;


			}

			if (user_choise < from || user_choise > to) {
				cout << "\ninvalid number !! enter another one : ";
			}

		} while (user_choise < from || user_choise > to);

		return user_choise;

	}

	static int read_number_in_range(int from, int to,string message) {

		int user_choise = 0;
		do {

			cout << message;
			cin >> user_choise;

			while (cin.fail()) {

				//input not a number
				cin.clear();
				cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

				cout << "invalid number!! enter another one : \n";
				cin >> user_choise;


			}

			if (user_choise < from || user_choise > to) {
				cout << "\ninvalid number !! enter another one : ";
			}

		} while (user_choise < from || user_choise > to);

		return user_choise;

	}

	static double read_double_number_in_range(double from, double to, string message) {

		double user_choise = 0;
		do {

			cout << message;
			cin >> user_choise;

			while (cin.fail()) {

				//input not a number
				cin.clear();
				cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

				cout << "invalid number!! enter another one : \n";
				cin >> user_choise;


			}

			if (user_choise < from || user_choise > to) {
				cout << "\ninvalid number !! enter another one : ";
			}

		} while (user_choise < from || user_choise > to);

		return user_choise;

	}

	static short read_short_number_with_message_in_range(short from, short to, string message) {

		short user_choise = 0;
		do {

			cout << message;
			cin >> user_choise;

			while (cin.fail()) {

				//input not a number
				cin.clear();
				cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

				cout << "invalid number!! enter another one : \n";
				cin >> user_choise;


			}

			if (user_choise < from || user_choise > to) {
				cout << "\ninvalid number !! enter another one : ";
			}

		} while (user_choise < from || user_choise > to);

		return user_choise;

	}

	static short read_short_with_error_message_number_in_range(short from, short to, string error_message) {

		short user_choise = 0;
		do {

			;
			cin >> user_choise;

			while (cin.fail()) {

				//input not a number
				cin.clear();
				cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

				cout << endl << error_message;
				cin >> user_choise;


			}

			if (user_choise < from || user_choise > to) {
				cout << endl << error_message;
			}

		} while (user_choise < from || user_choise > to);

		return user_choise;

	}

	static short read_short_number_in_range(short from, short to, string message,string error_message) {

		short user_choise = 0;
		do {

			cout << message;
			cin >> user_choise;

			while (cin.fail()) {

				//input not a number
				cin.clear();
				cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');

				cout << endl << error_message;
				cin >> user_choise;


			}

			if (user_choise < from || user_choise > to) {
				cout << endl << error_message;
			}

		} while (user_choise < from || user_choise > to);

		return user_choise;

	}

	static string read_string(string message) {
		string user_input;
		if (cin.rdbuf()->in_avail() > 0) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		while (true) {

			cout << message;
			getline(cin, user_input);

			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Input error. Please try again." << endl;
			}
			else if (user_input.empty()) {
				cout << "Invalid input. Please enter a non-empty string." << endl;
			}
			else {
				break;
			}
		}

		return user_input;
	}

	static char read_char(string message) {
		char input;

		while (true) {
			cout << message;
			cin >> input;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please try again." << endl;
			}
			else {
				break;
			}
		}

		return input;
	}

	static bool read_logical_question(string message) {
		char s = ' ';

		cout << message;
		cin >> s;
		cout << endl;

		if (toupper(s) == 'Y') {

			return true;

		}

		return false;

	}

	static bool is_valid_date(cls_Date d) {
		
		if (d.yr <= 0 || d.mn <= 0 || d.dy <= 0) {
			return false;
		}

		if (d.mn > 12 || d.dy > cls_Date::get_month_days(d.yr, d.mn)) {
			return false;
		}
		return true;

	}








};

