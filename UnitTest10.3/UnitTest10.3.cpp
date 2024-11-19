#include "pch.h"
#include "CppUnitTest.h"
#include "../lab10.3/lab10.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest103
{
	TEST_CLASS(UnitTest103)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int N = 3;
            Student students[N] = {
                {"Ivanov", 3, 4, 5},  // Середній бал = 4.0
                {"Petrov", 5, 5, 5},  // Середній бал = 5.0
                {"Sidorov", 2, 3, 4}  // Середній бал = 3.0
            };

            // Очікуваний порядок після сортування
            string expected_surnames[N] = { "Petrov", "Ivanov", "Sidorov" };

            // Виклик функції сортування
            SortByAverage(students, N);

            // Перевірка результату
            for (int i = 0; i < N; i++) {
                Assert::AreEqual(expected_surnames[i], students[i].surname, L"Прізвище не співпадає з очікуваним після сортування", LINE_INFO());
            }
		}
	};
}
