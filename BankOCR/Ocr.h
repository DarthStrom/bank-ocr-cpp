namespace BankOCR {
	using namespace std;

	class Ocr {
	public:
		static string Convert(string text);
	private:
		static map<string, string> Patterns;
	};
}