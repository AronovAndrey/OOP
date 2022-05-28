#include <iostream>

//Task1

//void _bSearch(int* array, const int size, int searchNumber) {
//    int low = 0;
//    int hight = size - 1;
//    while (low <= hight) {
//        int mid = (low + hight) / 2;
//        if (searchNumber == array[mid])
//        {
//            std::cout << "Number, which your loking for, is in " << mid << " index";
//            break;
//        }
//        else if (searchNumber > array[mid])
//            low = mid + 1;
//        else
//            hight = mid - 1;
//    }
//}
//int main()
//{
//    int a = 1000;
//    int* array = new int[a];
//    for (int i = 0; i < a; i++) {
//        array[i] = i + 1;
//    }
//    std::cout << "What number, you want find?" << std::endl;
//    int b;
//    std::cin >> b;
//    _bSearch(array, a, b);
//
//    delete[] array;
//}

//Task2

//void _swap(int* a, int* b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int main()
//{
//	int* a = new int;
//	int* b = new int;
//	*a = 10;
//	*b = 250;
//	std::cout << "a = " << *a << " b = " << *b << std::endl;
//	_swap(a, b);
//	std::cout << "a = " << *a << " b = " << *b << std::endl;
//	delete a, b;
//
//}

//Task3
void lokingFor(double* array, int size, double searchNumber)
{
	bool a = true;
	for (int i = 0; i < size; i++) {
		if (array[i] == searchNumber){
			std::cout << "Number, what you loking for is " << i << " index\n";
			a = false;
		}
	}
	if (a)
		std::cout << "Your number is missing";
}
int main()
{
	srand(time(NULL));
	int a = 50;
	double* array = new double[a];
	for (int i = 0; i < a; i++) {
		array[i] = (rand() % 999) * 2.3;
	}
	for (int i = 0; i < a; i++) {
		std::cout<<array[i]<<" ";
		if (i % 10 == 0 && i != 0)
			std::cout << "\n\n\n";
	}
	std::cout << "\n\n\n"<<"what number your want find?\n";
	double b;
	std::cin >> b;
	lokingFor(array, a, b);


}