#include "stdafx.h"
#include "CppUnitTest.h"
#include "Ocr.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace BankOCR;

namespace BankOCRTest
{		
	TEST_CLASS(OcrTest)
	{
	public:
		
		TEST_METHOD(RecognizesZero)
		{
			Assert::AreEqual(string("0"), Ocr::Convert(
				" _ \n"
				"| |\n"
				"|_|\n"
				"   "));
		}

	};
}