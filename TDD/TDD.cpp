#include "pch.h"
#include "CppUnitTest.h"
#include "../EvaluadorTest//ConversionAPostFija.h"
#include "../EvaluadorTest//ExpressionValidation.h"
#include "../EvaluadorTest//PostFijaOperacion.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TDD
{
	TEST_CLASS(TDD)
	{
	public:

		TEST_METHOD(ValidateString1)
		{
			auto test = new ExpressionValidation();
			Assert::AreEqual(true, test->Validation("2+5"));
		}

		TEST_METHOD(ValidateString2)
		{
			auto test = new ExpressionValidation();
			Assert::AreEqual(false, test->Validation("2+5a"));
		}

		TEST_METHOD(ValidateParentesis1)
		{
			auto test = new ExpressionValidation();
			Assert::AreEqual(true, test->Validation("(2+5)"));
		}

		TEST_METHOD(ValidateParentesis2)
		{
			auto test = new ExpressionValidation();
			Assert::AreEqual(false, test->Validation("2+5)"));
		}

		TEST_METHOD(ValidateCorchetes1)
		{
			auto test = new ExpressionValidation();
			Assert::AreEqual(false, test->Validation("[(2+5)"));
		}

		TEST_METHOD(ValidateCorchetes2)
		{
			auto test = new ExpressionValidation();
			Assert::AreEqual(true, test->Validation("[2+5]"));
		}

		TEST_METHOD(TotalValidation1)
		{
			auto convertir = new ConversionAPostFija();
			auto operar = new PostFijaOperacion();
			auto t = operar->Operate(convertir->Convert("2+5"));
			Assert::AreEqual(7.00, operar->Operate(convertir->Convert("2+5")));
		}

		TEST_METHOD(TotalValidation2)
		{
			auto convertir = new ConversionAPostFija();
			auto operar = new PostFijaOperacion();
			Assert::AreEqual(5.00, operar->Operate(convertir->Convert("2+9/3")));
		}
	};
}
