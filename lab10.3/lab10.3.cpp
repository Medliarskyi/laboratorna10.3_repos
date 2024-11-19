#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

struct Student {
    string surname;
    int grade_physics;
    int grade_math;
    int grade_info;
};

void Create(Student* students, const int N);
void Print(const Student* students, const int N);
void SortByAverage(Student* students, const int N);
void SortBySurname(Student* students, const int N);
void SortBySubject(Student* students, const int N, int subject);
double CalculateAverage(const Student& student);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Student* students = new Student[N];
    Create(students, N);

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1 - Вивести список студентів\n";
        cout << "2 - Сортувати за середнім балом\n";
        cout << "3 - Сортувати за прізвищем\n";
        cout << "4 - Сортувати за оцінками з фізики\n";
        cout << "5 - Сортувати за оцінками з математики\n";
        cout << "6 - Сортувати за оцінками з інформатики\n";
        cout << "0 - Завершити програму\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            Print(students, N);
            break;
        case 2:
            SortByAverage(students, N);
            Print(students, N);
            break;
        case 3:
            SortBySurname(students, N);
            Print(students, N);
            break;
        case 4:
            SortBySubject(students, N, 1);
            Print(students, N);
            break;
        case 5:
            SortBySubject(students, N, 2);
            Print(students, N);
            break;
        case 6:
            SortBySubject(students, N, 3);
            Print(students, N);
            break;
        }
    } while (choice != 0);

    delete[] students;
    return 0;
}

void Create(Student* students, const int N) {
    for (int i = 0; i < N; i++) {
        cout << "\nСтудент #" << i + 1 << ":\n";
        cin.ignore();
        cout << "Прізвище: ";
        getline(cin, students[i].surname);
        cout << "Оцінка з фізики: ";
        cin >> students[i].grade_physics;
        cout << "Оцінка з математики: ";
        cin >> students[i].grade_math;
        cout << "Оцінка з інформатики: ";
        cin >> students[i].grade_info;
    }
}

void Print(const Student* students, const int N) {
    cout << "============================================================================\n";
    cout << "| №  | Прізвище          | Фізика | Математика | Інформатика | Середній бал |\n";
    cout << "----------------------------------------------------------------------------\n";
    for (int i = 0; i < N; i++) {
        cout << "| " << setw(3) << i + 1 << " | "
            << setw(16) << left << students[i].surname
            << "| " << setw(6) << students[i].grade_physics
            << "| " << setw(10) << students[i].grade_math
            << "| " << setw(12) << students[i].grade_info
            << "| " << setw(12) << fixed << setprecision(2) << CalculateAverage(students[i]) << " |\n";
    }
    cout << "============================================================================\n";
}

double CalculateAverage(const Student& student) {
    return (student.grade_physics + student.grade_math + student.grade_info) / 3.0;
}

void SortByAverage(Student* students, const int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (CalculateAverage(students[j]) < CalculateAverage(students[j + 1])) {
                
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void SortBySurname(Student* students, const int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (students[j].surname > students[j + 1].surname) {
                
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void SortBySubject(Student* students, const int N, int subject) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            int grade_j = (subject == 1) ? students[j].grade_physics :
                (subject == 2) ? students[j].grade_math :
                students[j].grade_info;

            int grade_j1 = (subject == 1) ? students[j + 1].grade_physics :
                (subject == 2) ? students[j + 1].grade_math :
                students[j + 1].grade_info;

            if (grade_j < grade_j1) {
                
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
