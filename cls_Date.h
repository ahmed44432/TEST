#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include "cls_string.h"
#include <string>

using namespace std;

class cls_Date
{
	 
	int year = 2004;
	int month = 8;
	int day = 3;
	

	

public :

	int get_year() { return this->year; }
	int get_month() { return this->month; }
	int get_day() { return this->day; }

	void set_year(int year) { this->year = year ; }
	__declspec(property(get = get_year, put = set_year)) int yr;
	void set_month(int month) {  this->month = month  ; }
	__declspec(property(get = get_month, put = set_month)) int mn;
	void set_day(int day) { this->day = day ; }
	__declspec(property(get = get_day, put = set_day)) int dy;


	static bool is_leap_year(int x) {

		return  (x % 400 == 0) || ((x % 100 != 0) && (x % 4 == 0));

	}

	bool is_leap_year() {

		return  (this->year % 400 == 0) || ((this->year % 100 != 0) && (this->year % 4 == 0));

	}

	static short NumberOfDaysInAYear(short Year)
	{
		return  is_leap_year(Year) ? 365 : 364;
	}

	short NumberOfDaysInAYear()
	{
		return  NumberOfDaysInAYear(this->year);
	}

	static short NumberOfHoursInAYear(short Year)
	{
		return  NumberOfDaysInAYear(Year) * 24;
	}

	short NumberOfHoursInAYear()
	{
		return  NumberOfHoursInAYear(this->year);
	}

	static int NumberOfMinutesInAYear(short Year)
	{
		return  NumberOfHoursInAYear(Year) * 60;
	}

	int NumberOfMinutesInAYear()
	{
		return  NumberOfMinutesInAYear(this->year);
	}

	static int NumberOfSecondsInAYear(short Year)
	{
		return  NumberOfMinutesInAYear(Year) * 60;
	}

	int NumberOfSecondsInAYear()
	{
		return  NumberOfSecondsInAYear();
	}

	static int day_order(int year, int month, int day) {

		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + 12 * a - 2;

		int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;

	}

	static int day_order(cls_Date dt) {

		int a = (14 - dt.month) / 12;
		int y = dt.year - a;
		int m = dt.month + 12 * a - 2;

		int d = (dt.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;

	}

	int day_order() {

		int a = (14 - this->month) / 12;
		int y = this->year - a;
		int m = this->month + 12 * a - 2;

		int d = (this->day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;

	}

	static int get_month_days(int year, int month_number) {


		short month_days[12] = { 31, 28, 31, 30, 31, 30, 31,31,30,31,30,31 };

		if (month_number < 1 || month_number>12) {
			return 0;
		}
		return (month_number == 2) ? (is_leap_year(year) ? 29 : 28) : month_days[month_number - 1];


	}

	int get_month_days(int month_number) {


		short month_days[12] = { 31, 28, 31, 30, 31, 30, 31,31,30,31,30,31 };

		if (month_number < 1 || month_number>12) {
			return 0;
		}
		return (month_number == 2) ? (is_leap_year(this->year) ? 29 : 28) : month_days[month_number - 1];


	}

	static int days_since_year_start(int year, int month_to_stop, int day_to_stop) {
		int conter = 0;
		int rest = 0;

		if (day_to_stop > get_month_days(year, month_to_stop)) {
			cout << "Error: Invalid day for the selected month!" << endl;
			return 0;
		}

		int max_day = get_month_days(year, month_to_stop);

		if (day_to_stop < 1 || day_to_stop > max_day) {
			cout << "Error: Invalid day for the selected month!" << endl;
			return 0;
		}

		for (int i = 0; i < month_to_stop - 1; i++) {

			conter += get_month_days(year, i + 1);

		}
		conter += day_to_stop;

		return conter;

	}

	int days_since_year_start(int month_to_stop, int day_to_stop) {

		int conter = 0;
		int rest = 0;

		if (day_to_stop > get_month_days(year, month_to_stop)) {
			cout << "Error: Invalid day for the selected month!" << endl;
			return 0;
		}

		int max_day = get_month_days(year, month_to_stop);

		if (day_to_stop < 1 || day_to_stop > max_day) {
			cout << "Error: Invalid day for the selected month!" << endl;
			return 0;
		}

		for (int i = 0; i < month_to_stop - 1; i++) {

			conter += get_month_days(year, i + 1);

		}
		conter += day_to_stop;

		return conter;

	}

	static bool is_it_last_day_in_the_month(int year, int month, int the_day) {

		return get_month_days(year, month) == the_day;

	}

	static bool is_it_last_month_in_year(int month) {
		return month == 12;
	}

	static cls_Date adding_1_day_to_date(cls_Date d) {

		int year = d.year;
		int month = d.month;
		int day = d.day;
		


		if (is_it_last_day_in_the_month(year, month, day)) {

			d.day = 1;
			if (is_it_last_month_in_year(month)) {

				d.month = 1;
				d.year++;
			}
			else {

				d.month++;

			}

		}
		else {
			d.day++;
		}

		return d;


	}

	void adding_1_day_to_date() {


		if (is_it_last_day_in_the_month(year, month, day)) {

			day = 1;
			if (is_it_last_month_in_year(month)) {

				month = 1;
				year++;
			}
			else {

				month++;

			}

		}
		else {
			day++;
		}


	}

	static cls_Date adding_x_days_to_date(cls_Date d, int days) {

		for (int i = 0; i < days; i++) {

			d = adding_1_day_to_date(d);

		}

		return d;

	}

	void adding_x_days_to_date(int days) {

		for (int i = 0; i < days; i++) {

			*this = adding_1_day_to_date(*this);

		}

	}

	static cls_Date get_system_date() {


		time_t t = time(0);
		tm* now = localtime(&t);

		return cls_Date(now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);

	}

	void print_month_calender() {
		calander_top_head(this->month);
		calander_display_numbers(get_month_days(this->year, this->month), day_order(this->year, this->month, 1));
	}

	bool is_valid_date() {

		cls_Date d = *this;

		if (d.year <= 0 || d.month <= 0 || d.day <= 0) {
			return false;
		}

		if (d.month > 12 || d.day > get_month_days(d.year, d.month)) {
			return false;
		}
		return true;

	}

	protected :



	string return_first_delimiter(string st) {

			string fs = "";

			for (int i = 0; i < st.size(); i++) {
				if (ispunct(st[i])) {
					fs += st[i];
					return fs;
				}
			}
			return "";

		}

	cls_Date string_to_date(string d) {

		cls_Date date;

		string delim = return_first_delimiter(d);
		vector <string> vec_date = cls_string::split_each_word_from_string(d, delim);

		date.year = stoi(vec_date[0]);
		date.month = stoi(vec_date[1]);
		date.day = stoi(vec_date[2]);

		return date;
	}

	void calander_top_head(int month) {

		string month_names[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		string title = month_names[month-1];

		printf("\n    __________________%s__________________\n\n", title.c_str());
		printf("    Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");

	}

	void calander_display_numbers(int month_days, int day_order) {

		string sp = "      ";
		string kh = "   ";
		int curent_day = 1;

		for (int i = 0; i < day_order; i++) {

			cout << sp;

		}

		while (curent_day <= month_days) {

			/*cout << setw(3) << curent_day << kh;*/
			printf("%6d", curent_day);

			if ((curent_day + day_order) % 7 == 0) {
				cout << endl;
			}

			curent_day++;
		}

		cout << "\n    _______________________________________\n";

	}




	public : 


	static bool is_date_1_more_than_date_2(cls_Date date_1, cls_Date date_2) {

		return (date_1.get_year() > date_2.get_year()) ? true :
			(date_1.get_year() < date_2.get_year()) ? false :
			(date_1.get_month() > date_2.get_month()) ? true :
			(date_1.get_month() < date_2.get_month()) ? false :
			(date_1.get_day() > date_2.get_day()) ? true : false;

	}

	void print_year_calender() {

		printf("    _______________________________________\n");
		printf("\n                CALENDER - %d              \n", this->year);
		printf("    _______________________________________\n\n");

		for (int i = 0; i < 12; i++) {

			int dayo = day_order(this->year, i+1, 1);

			calander_top_head(i+1);
			calander_display_numbers(get_month_days(this->year, i + 1), dayo);

		}


	}

	static bool is_date_1_equal_date_2(cls_Date date_1, cls_Date date_2) {

		return ((date_1.year == date_2.year) && (date_1.month == date_2.month) && (date_1.day == date_2.day));

	}

	static bool is_date_1_after_date_2(cls_Date date_1, cls_Date date_2) {
		cls_Date tmp;
		return (tmp.is_date_1_more_than_date_2(date_1, date_2)) && !(tmp.is_date_1_equal_date_2(date_1, date_2));
	}

	bool is_date_1_after_date_2(cls_Date date_2) {

		return (is_date_1_more_than_date_2(*this, date_2)) && !(is_date_1_equal_date_2(*this, date_2));
	}

	bool is_date_1_equal_date_2(cls_Date date_2) {

		return ((year == date_2.year) && (month == date_2.month) && (day == date_2.day));

	}

	static bool is_it_weekend(int day_order) {

		return day_order == 5 || day_order == 6;

	}

	static bool is_it_business_day(int day_order) {

		return !(is_it_weekend(day_order));

	}

	static int count_vacation_days(cls_Date d1, cls_Date d2, bool includ_last_day = false) {

		int c = 0;

		if (is_date_1_equal_date_2(d1, d2)) {
			return (includ_last_day) ? c + 1 : c;
		}

		cls_Date big_date, small_date;

		bool date1_is_greater = d1.is_date_1_more_than_date_2(d1, d2);
		big_date = date1_is_greater ? d1 : d2;
		small_date = date1_is_greater ? d2 : d1;

		while (d1.is_date_1_more_than_date_2(big_date, small_date)) {

			if (is_it_business_day(day_order(small_date.year, small_date.month, small_date.day))) {
				c++;
			}
			small_date = adding_1_day_to_date(small_date);

		}


		return (includ_last_day) ? c + 1 : c;

	}

	int count_vacation_days(cls_Date d2, bool includ_last_day = false) {
		return count_vacation_days(*this, d2, includ_last_day);
	}

	static int time_diffrence_v2(cls_Date d1, cls_Date d2, bool includ_last_day = false) {

		int c = 0;

		if (is_date_1_equal_date_2(d1, d2)) {
			return (includ_last_day) ? c + 1 : c;
		}

		cls_Date big_date, small_date;

		bool date1_is_greater = is_date_1_more_than_date_2(d1, d2);
		big_date = date1_is_greater ? d1 : d2;
		small_date = date1_is_greater ? d2 : d1;

		while (is_date_1_more_than_date_2(big_date, small_date)) {

			c++;
			small_date = adding_1_day_to_date(small_date);

		}


		return (includ_last_day) ? c + 1 : c;
	}

	int time_diffrence_v2(cls_Date d2, bool includ_last_day = false) {
		return time_diffrence_v2(*this, d2);
	}

	static int your_age_in_days_in_the_moment(cls_Date birth_date) {

		return time_diffrence_v2(get_system_date(), birth_date);

	}

	static int your_age_in_days_in_the_sp_date(cls_Date date_to_stope,cls_Date birth_date) {

		return time_diffrence_v2(date_to_stope, birth_date);

	}

	enum en_date_compare { before = -1, equal = 0, after = 1 };

	static en_date_compare compare_date_order(cls_Date date_1, cls_Date date_2) {
		return is_date_1_equal_date_2(date_1, date_2) ? en_date_compare::equal : is_date_1_after_date_2(date_1, date_2) ? en_date_compare::after : en_date_compare::before;
	}

	cls_Date() {
		*this = get_system_date();
	}

	cls_Date(int year ,int month,int day) {
		
		this->year = year;
		this->month = month;
		this->day = day;

	}

	cls_Date(string date) {
		 *this =  string_to_date(date);
	}

	cls_Date(int number_of_dayes, int year) {
		this->day = 0;
		this->month = 1;
		this->year = year;
		*this = adding_x_days_to_date(*this, number_of_dayes);
	}

	void print() {
		cout << this->year << "/" << this->month << "/" << this->day << endl;
	}

	static string date_to_string(cls_Date d) {
		return to_string(d.year) + "/" + to_string(d.month) + "/" + to_string(d.day);
	}

	static string get_string_system_time() {


		time_t t = time(0);
		tm* now = localtime(&t);


		return  to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);

	}

	static string get_string_system_date_and_time() {
		return date_to_string(get_system_date()) + " - " + get_string_system_time();
	}







};

