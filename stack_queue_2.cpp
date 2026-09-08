#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class stLL {
    Node* head;
    int size;

public:
    stLL() {
        head = nullptr;
        size = 0;
    }

    ~stLL() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        size++;
    }

    int pop() {
        if (head == nullptr) return -1;

        Node* temp = head;
        head = head->next;
        int x = temp->data;
        delete temp;
        size--;

        return x;
    }

    int top() {
        if (size == 0) return -1;
        return head->data;
    }

    int getSize() {
        return size;
    }
};

class quLL {
    Node* front;
    Node* rear;
    int size;

public:
    quLL() {
        front = rear = nullptr;
        size = 0;
    }

    ~quLL() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        if (front == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int pop() {
        if (front == nullptr) {
            return -1;
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        size--;
        return val;
    }

    int peek() {
        if (front == nullptr) {
            return -1;
        }
        return front->data;
    }

    int getSize() {
        return size;
    }
};

int main() {
    cout << "--- Stack Tests ---" << endl;
    stLL s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.getSize() << endl;
    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.top() << endl;
    cout << s.pop() << endl;

    cout << s.pop() << endl;
    cout << s.top() << endl;

    cout << "--- Queue Tests ---" << endl;
    quLL q;

    q.push(100);
    q.push(200);
    q.push(300);

    cout << "Size: " << q.getSize() << endl;
    cout << "Peek: " << q.peek() << endl;

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << "Peek: " << q.peek() << endl;
    cout << q.pop() << endl;

    cout << q.pop() << endl;
    cout << "Peek: " << q.peek() << endl;

    return 0;
}