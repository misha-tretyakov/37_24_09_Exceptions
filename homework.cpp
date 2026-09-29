//
// Created by misha on 29.09.2026.
//
#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T value;  // значення елемента списку
    Node* next; // адреса на наступний елемент

    Node(const T& value) : value(value), next(nullptr) {}
    void Print() const
    {
        cout << value << endl;
    }
};

template<typename T>
class MyList {
public:
    Node<T>* head;
    MyList() {
        head = nullptr;
    }

    void Add(const T& value) {
        Node<T>* nodePtr = new Node<T>(value);
        nodePtr->next = head;
        head = nodePtr;
    }
    void Remove() {
        if (head == nullptr) {
            throw runtime_error("the list is empty");
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
};

int main() {
    MyList<int> list;

    try {
        list.Add(10);
        list.Remove();
        list.Remove();
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    cout << "Application running" << endl;
}
