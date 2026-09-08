#include <bits/stdc++.h>
using namespace std;

class stack_array{
    static const int cap = 10;
    int st[cap];
    int top = -1;
    public:
    void push(int x){
        if(top == cap - 1){
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        st[top] = x;
    }
    int pop(){
        if(top == -1){
            cout<<"Stack Underflow" << endl;
            return -1;
        }
        int x = st[top];
        top--;
        return x;
    }
    int top_element(){
        if(top == -1){
            cout<<"Stack is empty" << endl;
            return -1;
        }
        return st[top];
    }
};

class queue_array{
    int capacity = 10;
    int qu[10];
    int front = -1;
    int rear = -1;
    int currSize = 0;

    public:
    void push(int x) {
        if (currSize == capacity) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (rear == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        
        qu[rear] = x;
        currSize++; 
    }
    int pop(){
        if(currSize == 0 ){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }           
        int x = qu[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1) % capacity;
        }
        currSize--;
        return x;
    }
    int front_element() {
        if (currSize == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return qu[front];
    }
};
int main() {
    // --- Test Stack ---
    cout << "=== STACK TEST ===" << endl;
    stack_array s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top_element() << endl; // 30
    cout << "Popped: " << s.pop() << endl;              // 30
    cout << "Popped: " << s.pop() << endl;              // 20
    cout << "Popped: " << s.pop() << endl;              // 10
    cout << "Popped: " << s.pop() << endl;              // Stack Underflow -> -1

    // --- Test Queue (Circular Behavior) ---
    cout << "\n=== QUEUE TEST ===" << endl;
    queue_array q;
    for (int i = 1; i <= 10; i++) {
        q.push(i * 5);
    }
    q.push(55); // Queue Overflow

    cout << "Front element: " << q.front_element() << endl; // 5
    cout << "Popped: " << q.pop() << endl;                  // 5
    cout << "Popped: " << q.pop() << endl;                  // 10

    // Push after pop tests the circular wrap-around
    q.push(100);
    q.push(200);

    cout << "Front element: " << q.front_element() << endl; // 15
    while (true) {
        int val = q.pop();
        if (val == -1) break; // Empties queue until underflow
        cout << val << " ";
    }
    cout << endl;

    return 0;
}