#include "stdafx.h"
#include "Ocr.h"

namespace BankOCR {
	using namespace std;

	map<string, string> Ocr::Patterns = {
		{
			" _ "
			"| |"
			"|_|"
			"   ", "0" },
		{
			"   "
			"  |"
			"  |"
			"   ", "1" },
		{
			" _ "
			" _|"
			"|_ "
			"   ", "2" },
		{
			" _ "
			" _|"
			" _|"
			"   ", "3" },
		{
			"   "
			"|_|"
			"  |"
			"   ", "4" },
		{
			" _ "
			"|_ "
			" _|"
			"   ", "5" },
		{
			" _ "
			"|_ "
			"|_|"
			"   ", "6" },
		{
			" _ "
			"  |"
			"  |"
			"   ", "7" },
		{
			" _ "
			"|_|"
			"|_|"
			"   ", "8" },
		{
			" _ "
			"|_|"
			" _|"
			"   ", "9" }
	};

	vector<string> &Ocr::Split(const string &s, char delim, vector<string> &elems) {
		stringstream ss(s);
		string item;
		while (getline(ss, item, delim)) {
			elems.push_back(item);
		}
		return elems;
	}

	vector<string> Ocr::Split(const string &s, char delim) {
		vector<string> elems;
		Split(s, delim, elems);
		return elems;
	}

	vector<string> Ocr::GetDigits(string text) {
		vector<string> digits;
		vector<string> lines = Split(text, '\n');
		for (unsigned int digitNumber = 0; digitNumber < lines[0].length(); digitNumber += 3) {
			string digit = "";
			for (unsigned int lineNumber = 0; lineNumber < lines.size(); lineNumber++) {
				digit += lines[lineNumber].substr(digitNumber, 3);
			}
			digits.push_back(digit);
		}
		return digits;
	}

	string Ocr::Convert(string text) {
		vector<string> digits = Ocr::GetDigits(text);
		string result = "";
		for (unsigned int i = 0; i < digits.size(); i++) {
			result += Patterns[digits[i]];
		}
		return result;
	}
}