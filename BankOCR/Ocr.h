namespace BankOCR {
	using namespace std;

	class Ocr {
	public:
		static string Convert(string text);
	private:
		static map<string, string> Patterns;
		static vector<string> &Split(const string &s, char delim, vector<string> &elems);
		static vector<string> Split(const string &s, char delim);
		static vector<string> GetDigits(string text);
	};
}