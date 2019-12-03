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
		
		TEST_METHOD(TestMethod1)
		{
			auto test = new ConversionAPostFija();
			Assert::AreEqual(true, test->HaveBadValues("2+5"));
		}
	};
}
