#pragma once

#include <iostream>
#include <vector>

using namespace std;

class cls_string
{
	string _value;

public :


	cls_string() {
		this->_value = "";
	}

	cls_string(string value) {
		this->_value = value;
	}

	void set_value(string value) {
		this->_value = value;
	}

	string get_value() {
		return _value;
	}

	__declspec(property(get = get_value, put = set_value)) string value;

	static short count_each_word_in_string(string st) {

		string vd = " ";
		short pos = 0;
		string word;
		short counter = 0;

		while ((pos = st.find(vd)) != string::npos) {

			word = st.substr(0, pos);

			if (word != "") {
				counter++;
			}

			st.erase(0, pos + vd.size());

		}

		if (st != "") {
			counter++;
		}
		return counter;

	}

	short count_each_word_in_string() {
		return count_each_word_in_string(_value);
	}

	static char lower_case_char(char upper_case) {

		for (int i = 65; i <= 90; i++) {

			if (char(i) == upper_case) {
				return char(i + 32);
			}

		}
		return upper_case;
	}

	static char upper_case_char(char lower_case) {

		for (int i = 97; i <= 122; i++) {

			if (char(i) == lower_case) {
				return char(i - 32);
			}

		}
		return lower_case;
	}

	static char invert_char_case(char letter) {

		if (letter >= 'A' && letter <= 'Z') {
			return letter + 32;
		}
		else if (letter >= 'a' && letter <= 'z') {
			return letter - 32;
		}
		return letter;

	}

	static string invert_word_case(string word) {

		string wr = "";

		for (short i = 0; i < word.size(); i++) {

			wr += cls_string::invert_char_case(word[i]);

		}

		return wr;
	}

	void invert_word_case() {
		_value = invert_word_case(_value);
	}

	static vector <string> split_each_word_from_string(string st, string delim) {

		size_t  pos = 0;
		vector <string> word;
		string temp;

		while ((pos = st.find(delim)) != string::npos) {

			temp = st.substr(0, pos);

			//if (temp != "") {

			word.push_back(temp);

			//}

			st.erase(0, pos + delim.size());

		}

		if (st != "") {
			word.push_back(st);
		}
		return word;

	}


	vector <string> split_each_word_from_string(string delim) {
		return split_each_word_from_string(_value, delim);
	}

	static string join_split_word_vector(vector <string> split_list, string delim) {

		string word;

		for (string& i : split_list) {

			//if (i == split_list[split_list.size() - 1]) {
			//	delim = "";
			//}

			word += i + delim;

		}
		return word.substr(0, word.length() - delim.length());
	}

	static string join_split_word_vector(string split_list[],int list_size, string delim) {

		string word;

		for (int i = 0; i < list_size;i++) {

			word += split_list[i] + delim;

		}
		return word.substr(0, word.length() - delim.length());
	}

	static string trim(string str) {
		size_t first = str.find_first_not_of(' ');
		size_t last = str.find_last_not_of(' ');
		return (first == string::npos) ? "" : str.substr(first, last - first + 1);
	}

	 void trim() {
		 _value = trim(_value);
	}

	 static string trim_left(string str) {
		 size_t first = str.find_first_not_of(' ');
		 return (first == string::npos) ? "" : str.substr(first);
	 }

	 void trim_left() {
		 _value = trim_left(_value);
	 }

	 static string trim_right(string str) {
		 size_t last = str.find_last_not_of(' ');
		 return (last == string::npos) ? "" : str.substr(0, last + 1);
	 }

	 void trim_right() {
		 _value = trim_right(_value);
	 }

	 static int count_capital_letters(string st) {
		 int counter = 0;

		 for (int i = 0; i < st.size(); i++) {
			 if (isupper(st[i])) {
				 counter++;
			 }
		 }

		 return counter;
	 }

	 int count_capital_letters() {
		 return count_capital_letters(_value);
	 }

	 static int count_small_letters(string st) {
		 int counter = 0;
		 for (int i = 0; i < st.size(); i++) {
			 if (islower(st[i])) {
				 counter++;
			 }
		 }
		 return counter;
	 }

	 int count_small_letters() {
		 return count_small_letters(_value);
	 }

	 static int count_specific_char_in_string(string st, char letter) {
		 int counter = 0;

		 for (int i = 0; i < st.size(); i++) {

			 if (st[i] == letter) {
				 counter++;
			 }

		 }

		 return counter;
	 }

	 int count_specific_char_in_string(char letter) {
		 return count_specific_char_in_string(_value, letter);
	 }

	 static int count_chars(string st) {
		 int counter = 0;

		 for (int i = 0; i < st.size(); i++) {
			 if (st[i] != ' ') {
				 counter++;
			 }
		 }

		 return counter;
	 }

	 int count_chars() {
		 return count_chars(_value);
	 }

	 static bool is_vowel_char(char letter) {

		 vector <char> vowel_letters{ 'a','e','i','u','o' };

		 for (char& i : vowel_letters) {

			 if (toupper(i) == toupper(letter)) {
				 return true;
			 }

		 }
		 return false;
	 }

	 static int count_vowel_letters(string st) {
		 int counter = 0;

		 for (int i = 0; i < st.size(); i++) {

			 if (is_vowel_char(st[i])) {
				 counter++;
			 }

		 }

		 return counter;
	 }

	 int count_vowel_letters() {
		return count_vowel_letters(_value);
	 }
	 
	 static string replace_word_in_string(string st, string word, string replaced_word) {

		 short pos = st.find(word);

		 while (pos != string::npos) {

			 st.erase(pos, word.length());

			 st.insert(pos, replaced_word);

			 pos = st.find(word);

		 }

		 return st;
	 }

	 void replace_word_in_string(string word, string replaced_word) {
		 _value = replace_word_in_string(_value, word, replaced_word);
	 }

	 static string remove_punctuation(string st) {

		 string fs = "";

		 for (int i = 0; i < st.size(); i++) {
			 if (!ispunct(st[i])) {
				 fs += st[i];
			 }
		 }

		 return fs;

	 }

	 void remove_punctuation() {
		 _value = remove_punctuation(_value);
	 }

	 static int length(string word) {
		 return word.length();
	 }

	 int length() {
		 return length(_value);
	 }

	 static void print_first_letter_from_each_word_in_string(string word) {

		 char letter = ' ';

		 for (int i = 0; i < word.size(); i++) {

			 if (word[i] != ' ') {

				 if (letter == ' ') {

					 letter = word[i];
					 cout << letter << endl;

				 }


			 }
			 else if (word[i] == ' ') {
				 letter = ' ';
			 }


		 }


	 }

	 void print_first_letter_from_each_word_in_string() {
		 print_first_letter_from_each_word_in_string(_value);
	 }

	 static string upper_case_first_letter_of_each_word(string word) {

		   
		 char letter = ' ';

		 for (int i = 0; i < word.size(); i++) {

			 if (word[i] != ' ') {

				 if (letter == ' ') {

					 letter = word[i];
					 word[i] = toupper(word[i]);

				 }


			 }
			 else if (word[i] == ' ') {
				 letter = ' ';
			 }


		 }
		 return word;

	 }

	 void upper_case_first_letter_of_each_word() {
		 _value = upper_case_first_letter_of_each_word(_value);
	 }

	 static string lower_case_first_letter_of_each_word(string word) {


		 char letter = ' ';

		 for (int i = 0; i < word.size(); i++) {

			 if (word[i] != ' ') {

				 if (letter == ' ') {

					 letter = word[i];
					 word[i] = tolower(word[i]);

				 }


			 }
			 else if (word[i] == ' ') {
				 letter = ' ';
			 }


		 }
		 return word;

	 }

	 void lower_case_first_letter_of_each_word() {
		 _value = lower_case_first_letter_of_each_word(_value);
	 }

	 static string reverse_string(string st,string delim, string seperator) {

		 vector<string> split_list = split_each_word_from_string(st, delim);
		 if (split_list.empty()) return "";

		 string word;

		 for (int i = split_list.size() - 1; i >= 0; --i) {
			 word += split_list[i];
			 if (i != 0) word += seperator; 
		 }

		 return word;

	 }

	 void reverse_string(string delim, string seperator) {
		 _value = reverse_string(_value, delim, seperator);
	 }

	 static string reverse_characters(string st) {

		 string fs = "";

		 for (int i = st.size() - 1; i >= 0; i--) {

			 fs += st[i];

		 }

		 return fs;

	 }

	 void reverse_characters() {
		 _value = reverse_characters(_value);
	 }

	 static string to_upper_case(string str) {
		 for (int i = 0; i < str.size(); i++) {
			 str[i] = toupper(str[i]);
		 }
		 return str;
	 }

	 void to_upper_case() {
		 _value = to_upper_case(_value);
	 }

	 static string to_lower_case(string str) {
		 for (int i = 0; i < str.size(); i++) {
			 str[i] = tolower(str[i]);
		 }
		 return str;
	 }

	 void to_lower_case() {
		_value = to_lower_case(_value);
	 }






	 
};

