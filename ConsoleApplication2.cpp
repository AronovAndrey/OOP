#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

struct Student
{
    string FIO;
    vector <int> Count;
};
void input(Student student)
{

    cout << "Введите имя ученика:\n";
    SetConsoleCP(1251);
    getline(cin, student.FIO);
    int a; float sum = 0;
    
    for (int i = 0; i < 5; i++)
    {
        cout << "Введите оценку студента: ";
        cin >> a;
        student.Count.push_back(a);
        sum += a;
    }
    cout << "Средняя оценка студента "<<student.FIO<<" " << sum/5 << " баллов.";
}
int main() {
    setlocale(LC_ALL, "ru");
    Student student;
    input(student);
   
    return 0;
}
