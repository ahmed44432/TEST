#pragma once

#include <iostream>
#include <cmath>
#include "cls_Date.h"

using namespace std;



class cls_util
{

public :

	static void Srand() {
		//Seeds the random number generator in C++, called only once
		srand((unsigned)time(NULL));
	}

	static int random_number(int from, int to) {

		return ((rand() % (to - from + 1)) + from);

	}

	enum en_char_type { small_letter = 1, capital_letter = 2, digit = 3 , random_type = 4};

	static char random_char(en_char_type char_type) {

		if (char_type == 4) {
			char_type = (en_char_type) random_number(1, 3);
		}


		switch (char_type) {

		case en_char_type::capital_letter:

			return (char) random_number(65, 90);

		case en_char_type::small_letter:

			return random_number(97, 122);

		case en_char_type::digit:

			return  random_number(48, 57);



		default:
			cout << "FAILED !!!!\n";

			return 'F';

		}



	}

	static string generate_word(en_char_type char_type,short length) {

		string word = "";

		for (int i = 1; i <= length; i++) {
			
			word += random_char(char_type);

		}

		return word;

	}

	static string generate_key(en_char_type char_type) {

		string key = "";
		short limit = 4;

		for (int i = 1; i <= limit; i++) {

			key += generate_word(char_type,4);
			if (i < limit) {
				key += "-";
			}


		}

		return key;
	}

	static void random_keys(short keys_number, en_char_type char_type) {
		 
		string keys = "";

		for (int c = 1; c <= keys_number; c++) {

			keys = generate_key(char_type);

			cout << endl << "key[" << c << "] : " << keys << endl;

			keys = "";
		}


	}

	static void Swap(int &x, int &y) {
		int temp = x;
		x = y;
		y = temp;

	}

	static void Swap(double& x, double& y) {
		double temp = x;
		x = y;
		y = temp;

	}

	static void Swap(string& x, string& y) {
		string temp = x;
		x = y;
		y = temp;

	}

	static void Swap(char& x, char& y) {
		char temp = x;
		x = y;
		y = temp;

	}

	static void Swap(cls_Date & x, cls_Date& y) {
		cls_Date temp = x;
		x = y;
		y = temp;

	}

	static void fill_array_with_random_numbers(int arra_y[], int array_length,int from,int to) {

		for (int i = 0; i < array_length; i++) {

			arra_y[i] = random_number(from, to);

		}

	}

	static void fill_array_with_random_words(string arra_y[], int array_length,en_char_type char_type, int size_of_the_word) {

		for (int i = 0; i < array_length; i++) {

			arra_y[i] = generate_word(char_type, size_of_the_word);

		}

	}

	static void shuffell_array(int arra_y[], int array_length) {

		for (int i = 0; i < array_length; i++) {

			swap(arra_y[random_number(0, array_length - 1)], arra_y[random_number(0, array_length - 1)]);

		}


	}

	static void shuffell_array(string arra_y[], int array_length) {

		for (int i = 0; i < array_length; i++) {

			swap(arra_y[random_number(0, array_length - 1)], arra_y[random_number(0, array_length - 1)]);

		}


	}

	static void print_array(int arra_y[], int array_length) {

		for (int i = 0; i < array_length; i++) {

			cout << arra_y[i] << " ";

		}

		cout << endl;

	}

	static void print_array(string arra_y[], int array_length) {

		for (int i = 0; i < array_length; i++) {

			cout << arra_y[i] << " ";

		}

		cout << endl;

	}

	static string Tabs(int number) {
		string t = "";
		for (int i = 0; i < number; i++) {
			t = t + "\t";

		}
		return t;
	}

	static string encrypt_word(string word,short encrepte_number) {

		string encrypted_word = "";

		for (int i = 0; i < word.length(); i++) {
			encrypted_word += char((int)word[i] + encrepte_number);
		}
		
		return encrypted_word;
	}

	static string decrypt_word(string encrypted_word, short decrypted_number) {

		string decrypted_word = "";

		for (int i = 0; i < encrypted_word.length(); i++) {
			decrypted_word += char((int)encrypted_word[i] - decrypted_number);
		}

		return decrypted_word;
	}

	static string number_to_text(long long Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
			"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
			"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + "-" + number_to_text(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred and " + number_to_text(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   number_to_text(Number / 100) + "Hundreds and " + number_to_text(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + number_to_text(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   number_to_text(Number / 1000) + "Thousands " + number_to_text(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + number_to_text(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   number_to_text(Number / 1000000) + "Millions " + number_to_text(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + number_to_text(Number % 1000000000);
		}
		else
		{
			return   number_to_text(Number / 1000000000) + "Billions " + number_to_text(Number % 1000000000);
		}


	}

	static void clear_console() {
		system("cls");
		system("color 0F");
	}

	static void empty_line(int n) {

		string empty = "";
		for (int i = 0; i < n; i++) {
			cout << (empty = empty + "\n");
		}

	}

	static string space(int number) {
		string t = "";
		for (int i = 0; i < number; i++) {
			t = t + "\t";

		}
		return t;
	}







};

