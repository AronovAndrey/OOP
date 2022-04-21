#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

class Lift
{
    int minFloat = 0;
    int maxFloat = 10;
public:
    int polojenie = 1;
    bool work = true;
    bool Float = true;
    void setLift(int value)
    {
        if (value <= 0 || value > 10)
            Float = false;
        else if (value >= 0 && value <= 10)
            Float = true;
    }
    string getLift()
    {
        if (Float)
            return "Лифт поехал";
        else
            return "Вы сделали неверный ввод этажа";
    }

};

int main() {
    setlocale(LC_ALL, "ru");
    Lift lift;
    cout << "Лифт находится на этаже: " << lift.polojenie << " он в состоянии: ";
    if (lift.work) cout << "Работает\n"; else cout << "Не работает\n";
    int choice;
    cout << "Выберите этаж на который хотите поехать: ";
    cin >> choice;
    lift.setLift(choice);
    cout << lift.getLift();
}