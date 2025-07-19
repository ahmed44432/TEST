#pragma once

#include <iostream>
#include "cls_Date.h"

using namespace std;




class cls_periode
{

	cls_Date _start_date;
	cls_Date _end_date;


public :

	static bool is_periode_overlap(cls_periode p1, cls_periode p2) {

		if (
			(cls_Date::compare_date_order(p1._end_date, p2._start_date) == cls_Date::en_date_compare::before) ||
			(cls_Date::compare_date_order(p1._start_date, p2._end_date) == cls_Date::en_date_compare::after)
			) {
			return false;
		}
		else {
			return true;
		}

	}

	bool is_periode_overlap(cls_periode p2) {
		return is_periode_overlap(*this, p2);
	}

	cls_periode(cls_Date start_date, cls_Date end_date) {

		this->_start_date = start_date;
		this->_end_date = end_date;

	}

	cls_periode() {

		cls_Date d(1900, 1, 1);

		this->_start_date = d;
		this->_end_date = d.get_system_date();

	}

	static int period_length(cls_periode p, bool includ_end_day = false) {

		return cls_Date::time_diffrence_v2(p._start_date, p._end_date, includ_end_day);

	}

	static bool is_date_within_this_period(cls_periode periode, cls_Date date) {

		return !(cls_Date::compare_date_order(date, periode._start_date) == cls_Date::en_date_compare::before ||
			cls_Date::compare_date_order(date, periode._end_date) == cls_Date::en_date_compare::after);

	}

	static int count_period_overlap_days(cls_periode p1, cls_periode p2) {

		int c = 0;
		int pl1 = period_length(p1);
		int pl2 = period_length(p2);


		if (!is_periode_overlap(p1, p2)) {
			return 0;
		}

		if (pl1 < pl2) {

			while (cls_Date::compare_date_order(p1._start_date, p1._end_date) != cls_Date::en_date_compare::equal) {


				if (is_date_within_this_period(p2, p1._start_date)) {

					c++;

				}
				else if (cls_Date::is_date_1_after_date_2(p1._start_date, p2._end_date)) {
					return c;
				}

				p1._start_date = cls_Date::adding_1_day_to_date(p1._start_date);

			}
		}
		else {


			while (cls_Date::compare_date_order(p2._start_date, p2._end_date) != cls_Date::en_date_compare::equal) {


				if (is_date_within_this_period(p1, p2._start_date)) {

					c++;

				}
				else if (cls_Date::is_date_1_after_date_2(p2._start_date, p1._end_date)) {
					return c;
				}

				p2._start_date = cls_Date::adding_1_day_to_date(p2._start_date);

			}

		}


		return c;

	}

	int count_period_overlap_days( cls_periode p2) {
		return count_period_overlap_days(*this, p2);
	}

	void print() {

		cout << "start date :" << endl;
		cls_periode::_start_date.print();
		cout << "end date :" << endl;
		cls_periode::_end_date.print();


	}


};

