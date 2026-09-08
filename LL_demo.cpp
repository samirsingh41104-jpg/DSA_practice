#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* arrToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* ptr = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        ptr->next = temp;
        ptr = temp;
    }
    return head; // only gives the head
}

int main(){
    vector<int> arr = {1, 3, 5, 8};
    int n = arr.size();
    Node* head = arrToLL(arr);
    cout<<head->data<<endl; 

    Node* temp = head;
    while(temp){
        cout<<temp->data <<"->"<<temp->next<<" ";
        temp = temp->next;
    }
    return 0;
}