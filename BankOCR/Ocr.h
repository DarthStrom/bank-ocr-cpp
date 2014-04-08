namespace BankOCR {
	using namespace std;

	class Ocr {
	protected:
		static map<string, string> Patterns;
		static vector<string> &Split(const string &s, char delim, vector<string> &elems);
		static vector<string> Split(const string &s, char delim);
		static string GetAccountNumber(string entry);
		static vector<string> GetDigits(string entry);
		static vector<string> GetEntries(string text);
	public:
		static string Convert(string text);
		static bool IsValid(string accountNumber);
	};
}