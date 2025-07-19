#pragma once

#include <iostream>
#include "cls_string.h"
#include <string>

using namespace std;

class cls_person
{

	string _first_name, _last_name, _email, _phone;
	


public :
	

	cls_person(string first_name, string last_name, string email, string phone) {

		_first_name = first_name;
		_last_name = last_name;
		_email = email;
		_phone = phone;
		
	}
	

	string get_first_name() { return this->_first_name; }
	string get_last_name() { return this->_last_name; }
	string get_email() { return this->_email; }
	string get_phone() { return this->_phone; }


	void set_first_name(string first_name) { this->_first_name = first_name ;}
	__declspec(property(get = get_first_name, put = set_first_name)) string first_name;

	void set_last_name(string last_name) { this->_last_name = last_name; }
	__declspec(property(get = get_last_name, put = set_last_name)) string last_name;

	void set_email(string email) { this->_email = email ;}
	__declspec(property(get = get_email, put = set_email)) string email;

	void set_phone(string phone) { this->_phone = phone; }
	__declspec(property(get = get_phone, put = set_phone)) string phone;

	string full_name() {
		return _first_name + " " + _last_name;
	}




};

