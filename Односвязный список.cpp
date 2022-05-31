#include <iostream>
using namespace std;

class List
{
    class Node
    {
    public:
        int data;
        Node* pNext;
        Node(int data =0, Node* pNext = nullptr) {
            cout << "Node constructor: " << this << endl;
            this->data = data;
            this->pNext = pNext;
        }
        ~Node() {
            cout << "Node destructor." << endl;
        }
   };
    Node* head;
    Node* tail;
    int size;
public:
    List() {
        cout << "List constructor: " << this << endl;
        size = 0;
        tail = head = nullptr;
        
    }
    int getSize()const {
        return size;
    }
    void push_back(const int data) {
        if (head == nullptr){
            head = new Node(data, nullptr);
        }
        else {
            Node* current = head;
            while (current->pNext != nullptr) {
                current = current->pNext;
            }
            current->pNext = new Node(data, nullptr);
        }
        size++;
    }
    void pop_front() {
        Node* temp = head->pNext;
        delete head;
        head = temp;
        size--;
    }
    int& operator[](const int index) {
        int counter = 0;
        Node* current = head;
        while (current!= nullptr) {
            if (counter == index) {
                return current->data;
           }
            current = current->pNext;
            counter++;
        }
    }
    ~List() {
        cout << "List destruct:" << this << endl;
    }
};

int main()
{
    
    List list;
    cout << "size: " << list.getSize() << endl;
    list.push_back(5);
    list.push_back(10);
    list.push_back(15);
    list.push_back(20);
    cout <<list[0] << endl;;

}