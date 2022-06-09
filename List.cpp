#include <iostream>
using namespace std;

template <class T>
class List
{
private:
    template <class T>
    class Node {
    public:
        T data;
        Node* pNext;
        Node(T data = T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node<T>* head;
    int size;
public:
    int getSize() {
        return size;
    }
    void push_back(T data) {
        if (head == nullptr) {
            head = new Node<T>(data);
        }
        else {
            Node<T>* current = this->head;
            while (current->pNext != nullptr) {
                current = current->pNext;
            }
            current->pNext = new Node<T>(data);
        }
        size++;
    }
    void pop_front() {
        Node<T> *temp = head;
        head = head->pNext;
        delete temp;
        size--;
    }
    void clear() {
        while (size) {
            pop_front();
        }
    }
    T& operator[](int index) {
        int counter = 0;
        Node<T>* current = this->head;
        while (index < 0 || index > size) {
            cout << "Incorrect input index, please input correct index: ";
            cin>>index;
        }
        while (current != nullptr) {
            if (counter == index) {
                return current->data;
            }
            current = current->pNext;
            counter++;
        }
    }
    void push_front(T data) {
        head = new Node<T>(data,head);
        size++;
    }
    void printAll() {
        for (int i = 0; i < getSize(); i++)
            cout << this->operator[](i) << " ";
        cout << endl;
    }
    void insertAfter(T data, int index) {
        int counter = 0;
        Node<T>* current = this->head;
        while (index < 0 || index > size-1) {
            cout << "Incorrect input index, please input correct index: ";
            cin >> index;
        }
        while (counter != size) {
            if (counter == index) {
                current->pNext = new Node<T>(data, current->pNext);
                size++;
                break;
            }
            else
            {
                current = current->pNext;
                counter++;
            }
       } 
        
    }
    void insertBefore(T data, int index) {
        while (index < 0 || index > size - 1) {
            cout << "Incorrect input index, please input correct index: ";
            cin >> index;
        }
        if (index == 0) {
            push_front(data);
        }
        else {
            Node<T>* current = this->head;
            for (int i = 0; i < index - 1; i++) {
                current = current->pNext;
            }
            current->pNext = new Node<T>(data, current->pNext);
            size++;
        }
    }
    void removeAt(int index) {
        while (index < 0 || index > size - 1) {
            cout << "Incorrect input index, please input correct index: ";
            cin >> index;
        }
        if (index == 0) {
            pop_front();
        }
        else {
            Node<T>* current = this->head;
            for (int i = 0; i < index - 1; i++) {
                current = current->pNext;
            }
            Node<T>* toDelete = current->pNext;
            current->pNext = toDelete->pNext;
            delete toDelete;
            size--;
        }
    }
    void pop_back() {
        removeAt(size - 1);
    }
    List() {
        size = 0;
        head = nullptr;
    }
    ~List() { clear(); }
};
int main()
{
    List<int> lst;
    cout << "Size = " << lst.getSize() << endl;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    cout << "Size = " << lst.getSize() << endl;
    cout <<"Number for index = "<< lst[0] << endl;
    lst.printAll();
    lst.pop_front();
    cout <<"Size = "<< lst.getSize() << endl;
    lst.printAll();
    lst.push_front(5);
    cout << "Size = " << lst.getSize() << endl;
    lst.printAll();
    lst.insertAfter(225, 1);
    cout << "Size = " << lst.getSize() << endl;
    lst.printAll();
    lst.insertBefore(200, -1);
    cout << "Size = " << lst.getSize() << endl;
    lst.printAll();
    lst.removeAt(-1);
    cout << "Size = " << lst.getSize() << endl;
    lst.printAll();
    lst.pop_back();
    cout << "Size = " << lst.getSize() << endl;
    lst.printAll();
}