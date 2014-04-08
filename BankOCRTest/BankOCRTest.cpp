#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace BankOCR;

namespace BankOCRTest {
	TEST_CLASS(OcrTest) {
	public:

		TEST_METHOD(RecognizesZero) {
			Assert::AreEqual(string("0"), Ocr::Convert(
				" _ \n"
				"| |\n"
				"|_|\n"
				"   "));
		}

		TEST_METHOD(RecognizesOne) {
			Assert::AreEqual(string("1"), Ocr::Convert(
				"   \n"
				"  |\n"
				"  |\n"
				"   "));
		}

		TEST_METHOD(RecognizesTwo) {
			Assert::AreEqual(string("2"), Ocr::Convert(
				" _ \n"
				" _|\n"
				"|_ \n"
				"   "));
		}

		TEST_METHOD(RecognizesThree) {
			Assert::AreEqual(string("3"), Ocr::Convert(
				" _ \n"
				" _|\n"
				" _|\n"
				"   "));
		}

		TEST_METHOD(RecognizesFour) {
			Assert::AreEqual(string("4"), Ocr::Convert(
				"   \n"
				"|_|\n"
				"  |\n"
				"   "));
		}

		TEST_METHOD(RecognizesFive) {
			Assert::AreEqual(string("5"), Ocr::Convert(
				" _ \n"
				"|_ \n"
				" _|\n"
				"   "));
		}

		TEST_METHOD(RecognizesSix) {
			Assert::AreEqual(string("6"), Ocr::Convert(
				" _ \n"
				"|_ \n"
				"|_|\n"
				"   "));
		}

		TEST_METHOD(RecognizesSeven) {
			Assert::AreEqual(string("7"), Ocr::Convert(
				" _ \n"
				"  |\n"
				"  |\n"
				"   "));
		}

		TEST_METHOD(RecognizesEight) {
			Assert::AreEqual(string("8"), Ocr::Convert(
				" _ \n"
				"|_|\n"
				"|_|\n"
				"   "));
		}

		TEST_METHOD(RecognizesNine) {
			Assert::AreEqual(string("9"), Ocr::Convert(
				" _ \n"
				"|_|\n"
				" _|\n"
				"   "));
		}

		TEST_METHOD(ConvertsALineOfZeros) {
			Assert::AreEqual(string("000000000"), Ocr::Convert(
				" _  _  _  _  _  _  _  _  _ \n"
				"| || || || || || || || || |\n"
				"|_||_||_||_||_||_||_||_||_|\n"
				"                           "));
		}

		TEST_METHOD(CanParseMultipleEntries) {
			Assert::AreEqual(string(
				"111111111\n"
				"222222222\n"
				"333333333\n"
				"444444444\n"
				"555555555\n"
				"666666666\n"
				"777777777\n"
				"888888888\n"
				"999999999"), Ocr::Convert(
				"                           \n"
				"  |  |  |  |  |  |  |  |  |\n"
				"  |  |  |  |  |  |  |  |  |\n"
				"                           \n"
				" _  _  _  _  _  _  _  _  _ \n"
				" _| _| _| _| _| _| _| _| _|\n"
				"|_ |_ |_ |_ |_ |_ |_ |_ |_ \n"
				"                           \n"
				" _  _  _  _  _  _  _  _  _ \n"
				" _| _| _| _| _| _| _| _| _|\n"
				" _| _| _| _| _| _| _| _| _|\n"
				"                           \n"
				"                           \n"
				"|_||_||_||_||_||_||_||_||_|\n"
				"  |  |  |  |  |  |  |  |  |\n"
				"                           \n"
				" _  _  _  _  _  _  _  _  _ \n"
				"|_ |_ |_ |_ |_ |_ |_ |_ |_ \n"
				" _| _| _| _| _| _| _| _| _|\n"
				"                           \n"
				" _  _  _  _  _  _  _  _  _ \n"
				"|_ |_ |_ |_ |_ |_ |_ |_ |_ \n"
				"|_||_||_||_||_||_||_||_||_|\n"
				"                           \n"
				" _  _  _  _  _  _  _  _  _ \n"
				"  |  |  |  |  |  |  |  |  |\n"
				"  |  |  |  |  |  |  |  |  |\n"
				"                           \n"
				" _  _  _  _  _  _  _  _  _ \n"
				"|_||_||_||_||_||_||_||_||_|\n"
				"|_||_||_||_||_||_||_||_||_|\n"
				"                           \n"
				" _  _  _  _  _  _  _  _  _ \n"
				"|_||_||_||_||_||_||_||_||_|\n"
				" _| _| _| _| _| _| _| _| _|\n"
				"                           "));
		}

		TEST_METHOD(CanValidateAnAccountNumber) {
			Assert::IsTrue(Ocr::IsValid("345882865"));
		}


		TEST_METHOD(CanDetectAnInvalidAccountNumber) {
			Assert::IsFalse(Ocr::IsValid("987654321"));
		}
	};
}