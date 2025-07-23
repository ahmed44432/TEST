#pragma once

#include <iostream>
#include <vector>
#include "cls_string.h"
#include <string>
#include "cls_input_validate.h"
#include <fstream>


using namespace std;

class cls_currency
{

private :

	
	enum en_mode { Empty_mode = 0, Update_mode = 1 };
	en_mode _MODE;

	string _country, _currency_code, _currency_name;
	float _rate;


	static cls_currency _convert_line_to_currency_obj(std::string line,string delim = "#//#") {
		
		vector <string> vCurrency_info = cls_string::split_each_word_from_string(line, delim);
		return cls_currency(en_mode::Update_mode,vCurrency_info[0], vCurrency_info[1], vCurrency_info[2], stof(vCurrency_info[3]));

	}

	static cls_currency _get_empty_obj() {
		return cls_currency(en_mode::Empty_mode, "", "", "", 0);
	}

	static vector <cls_currency> _load_currency_info_from_file(string file_name = "Currencies.txt") {

		fstream my_file;
		my_file.open(file_name, ios::in);
		vector <cls_currency> vCurrency;

		if (my_file.is_open()) {

			
			string line;
			while (getline(my_file, line)) {

				cls_currency temp = _convert_line_to_currency_obj(line);
				vCurrency.push_back(temp);

			}


			my_file.close();
		}

		return vCurrency;
	}

	static string _convert_obj_to_line(cls_currency c_obj, string seperator = "#//#") {

		string st;
		st += c_obj._country + seperator;
		st += c_obj._currency_code + seperator;
		st += c_obj._currency_name + seperator;
		st += to_string(c_obj._rate);
		return st;
	}

	static void _save_currency_info_in_file(vector <cls_currency> VC,string file_name = "Currencies.txt") {

		fstream my_file;
		my_file.open(file_name, ios::out);
		string data_line;

		if (my_file.is_open()) {

			for (cls_currency& c : VC) {

				data_line = _convert_obj_to_line(c);
				my_file << data_line << endl;
			}

			my_file.close();
		}


	}

	void _update() {

		vector <cls_currency> vCurrencies;
		vCurrencies = _load_currency_info_from_file();

		for (cls_currency& c : vCurrencies) {
			if (c.currency_code() == currency_code()) {
				c = *this;
				break;
			}
		}

		_save_currency_info_in_file(vCurrencies);

	}


public :

	cls_currency(en_mode mode,string country, string currency_code, string currency_name,float rate) {
		_MODE = mode;
		_country = country;
		_currency_code = currency_code;
		_currency_name = currency_name;
		_rate = rate;
	}

	bool is_empty() {
		return(_MODE == en_mode::Empty_mode);
	}

	string country() {
		return _country;
	}

	string currency_code() {
		return _currency_code;
	}

	string currency_name() {
		return _currency_name;
	}

	float rate(){
		return _rate;
	}

	void update_rate(float new_rate) {
		_rate = new_rate;
		_update();
	}

	static cls_currency find_by_code(string currency_code,string file_name = "Currencies.txt") {
		
		string cc = cls_string::to_upper_case(currency_code);

		fstream my_file;
		my_file.open(file_name, ios::in);

		if (my_file.is_open()) {
			
			string line;
			while (getline(my_file, line)) {

				cls_currency currency_obj = _convert_line_to_currency_obj(line);
				if (currency_obj.currency_code() == cc) {
					my_file.close();
					return currency_obj;
				}

			}
			my_file.close();
			return _get_empty_obj();
		}


	}

	static cls_currency find_by_country(string country, string file_name = "Currencies.txt") {

		string c = cls_string::to_upper_case(country);

		fstream my_file;
		my_file.open(file_name, ios::in);

		if (my_file.is_open()) {

			string line;
			while (getline(my_file, line)) {

				cls_currency currency_obj = _convert_line_to_currency_obj(line);
				if (cls_string::to_upper_case(currency_obj.country()) == c) {
					my_file.close();
					return currency_obj;
				}

			}
			my_file.close();
			return _get_empty_obj();
		}


	}

	static bool is_currency_exist(string currency_code) {
		cls_currency c = find_by_code(currency_code);
		return (!c.is_empty());
	}

	static vector <cls_currency> get_currencies_list() {
		return _load_currency_info_from_file();
	}

	static float convert_currency_to_another(cls_currency C1, cls_currency C2, float amount) {

	return (float)(amount * C2.rate()) / C1.rate();

	}








};

