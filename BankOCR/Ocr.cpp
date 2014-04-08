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

	vector<string> Ocr::GetDigits(string entry) {
		vector<string> digits;
		vector<string> lines = Split(entry, '\n');
		for (unsigned int digitNumber = 0; digitNumber < lines[0].length(); digitNumber += 3) {
			string digit = "";
			for (unsigned int lineNumber = 0; lineNumber < lines.size(); lineNumber++) {
				digit += lines[lineNumber].substr(digitNumber, 3);
			}
			digits.push_back(digit);
		}
		return digits;
	}

	vector<string> Ocr::GetEntries(string text) {
		vector<string> entries;
		vector<string> lines = Split(text, '\n');
		for (unsigned int entryNumber = 0; entryNumber < lines.size(); entryNumber += 4) {
			string entry = "";
			for (unsigned int entryLine = 0; entryLine < 4; entryLine++) {
				entry += lines[entryNumber + entryLine] + '\n';
			}
			entries.push_back(entry);
		}
		return entries;
	}

	string Ocr::GetAccountNumber(string entry) {
		vector<string> digits = GetDigits(entry);
		string accountNumber = "";
		for (unsigned int i = 0; i < digits.size(); i++) {
			accountNumber += Patterns[digits[i]];
		}
		return accountNumber;
	}

	string Ocr::Convert(string text) {
		vector<string> entries = Ocr::GetEntries(text);
		string result = "";
		for (unsigned int i = 0; i < entries.size(); i++) {
			result += GetAccountNumber(entries[i]) + "\n";
		}
		return result.substr(0, result.length() - 1);
	}
}