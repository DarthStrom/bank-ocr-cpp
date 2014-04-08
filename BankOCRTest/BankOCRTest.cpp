#include "stdafx.h"
#include "CppUnitTest.h"
#include "Ocr.h"

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
	};
}