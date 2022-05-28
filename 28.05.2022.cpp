#include <iostream>
#include <initializer_list>
using namespace std;

template <class T>
class Array
{
    T* array;
    unsigned long size;
   
public:
    Array() : array{ nullptr }, size{ 0 }{}
    Array(Array& other) {
        this->size = other.size;
        this->array = new T[size];
        for (int i = 0; i < size; i++) {
            this->array[i] = other.array[i];
        }
    }
    Array(int value){
        array = new T[value]{0};
        size = value;
    }
    Array(const initializer_list<T>& list, int value) {
        array = new T[value]{0};
        int i = 0;
        for (auto& element : list) {
            array[i] = element;
            i++;
        }
        size = value;
    };
    Array(const initializer_list<T>& list){
        array = new T[list.size()];
        int i = 0;
        for (auto& element : list){
            array[i] = element;
            i++;
        }
        size = list.size();
    }
    unsigned long GetSize()const{
        
        return size;
           
    }
    void SetSize(int size,int grow = 1){//я не совсем понял суть, но решил реализовать вот в таком виде.
        if (this->size == size) {
            cout << "Size equal, nothing needs to be changed" << endl;
        }
        else if (grow < size) {
            int num = size - grow;
            size -= num;
            num *= grow;
            size += num;
            T* temp = new T[size]{ 0 };
            if (this->size > size) {
                for (int i = 0; i < size; i++) {
                    temp[i] = array[i];
                }
            }
            else if (this->size <= size) {
                for (int i = 0; i < this->size; i++) {
                    temp[i] = array[i];
                }
            }
            delete[] array;
            array = temp;
            this->size = size;
        }
        else if ((grow >= size) && (this->size != size)) {
            T* temp = new T[size]{ 0 };
            if (this->size > size) {
                for (int i = 0; i < size; i++) {
                    temp[i] = array[i];
                }
            }
            else if (this->size <= size) {
                for (int i = 0; i < this->size; i++) {
                    temp[i] = array[i];
                }
            }  
            delete[] array;
            array = temp;
            this->size = size;
        }              
    }
    void GetUpperBound(int* index, int* number) {
        for (int i = 0; i < size; i++) {
            if (array[i] != 0) {
                *index = i;
                *number = array[i];
            }
        }
    }
    void print() {
        if (array != nullptr) {
            for (auto i = 0; i < size; i++) {
                cout << array[i] << " ";
            }
        }
        else {
            cout << "Array was delete, because it was empty" << endl;
        }
        cout << endl;
        
    }
    void printSize() {
        cout << "Size " << this << " objective = " << GetSize() << endl;
    }
    void printGetUpperBound(int* index, int* number) {
        cout << "The maximum index containing a number = " << *index << ". The number in it = " << *number << endl;
    }
    void FreeExtra() {
        int i = 0;
        for (int j = 0; j < size; j++) {
            if (array[j] != 0) {
                i++;
            }
        }
        if (i != 0) {
            T* temp = new T[i]{ 0 };
            for (int j = 0; j < i; j++) {
                temp[j] = array[j];
            }
            delete[] array;
            array = temp;
            this->size = i;
        }
        else {
            delete[] array;
            array = nullptr;
        }
    }
    bool isEmpty() {
        for (int i = 0; i < size; i++) {
            if (array[i] != 0) {
                cout << "Array is not empty" << endl;
                return false;
                break;
            }
        }
        return true;
    }
    void operator=(Array& other) {
        if (this->array != nullptr) {
            delete[] this->array;
        }
        this->size = other.size;
        this->array = new T[size];
        for (int i = 0; i < size; i++) {
            this->array[i] = other.array[i];
        }
    }
    void Append(Array& other, Array& other2){
       size = other.size + other2.size;
        int sizeC = 0;
        array = new T[size]{0};
        for (int i = 0; i < other.size; i++) {
            this->array[sizeC] = other.array[i];
                sizeC++;
        }
        for (int i = 0; i < other2.size; i++) {
            array[sizeC] = other2.array[i];
            sizeC++;
        }
    }
    T& operator[](int index) {
        T a{ 0 };
        if (index <= size - 1)
            return array[index];
        else
            return a;
       
    }
    void RemoveAll() {
        if (array != nullptr) {
            delete[] array;
            array = nullptr;
        }
    }
    ~Array(){
        delete[] array;
    }
};
int main()
{
    Array<int> a{1,2,3,4,5,6,7,8,9,10,11};
    //Array<int> b(a);
    //Array<int> b = a;
    a.printSize();
    a.print();
    a.SetSize(10, 2);
    a.printSize();
    a.print();
    int* index1 = new int{0};
    int* number1 = new int{0};
    a.GetUpperBound(index1, number1);
    a.printGetUpperBound(index1, number1);
    if (a.isEmpty()) 
        cout << "Array is empty" << endl;
    a.FreeExtra();
    a.print();
    cout << a[5] << endl;
    a[5] = 564654;
    cout << a[5] << endl;
   /* a.RemoveAll();*/
    a.print();
    cout << "\n\n\n\n\n";
    


    
    Array<int> b({ 5464,354354,35435,3543 },5);
    Array<int> c;
    /*Array<int> b(5);*/
    b.printSize();
    b.print();
    b.SetSize(2, 2);
    b.printSize();
    b.print();
    c.Append(a, b);
    c.print();
    int* index2 = new int{ 0 };
    int* number2 = new int{ 0 };
    b.GetUpperBound(index2, number2);
    b.printGetUpperBound(index2, number2);
    if (b.isEmpty())
        cout << "Array is empty" << endl;
    b.FreeExtra();
    b.print();
    b.RemoveAll();
    b.print();
    delete index1, number1;
    delete number2, index2;
    
}