#include<iostream>
using namespace std ;

class Node {
    public :
        int data ;
        Node* next ;
        Node(int x){
            data = x ;
            next = NULL ;
        }
};

class Stack {
    Node* top ;
    public :
        Stack(){
            top = NULL ;
        }
        void push(int x){
            Node* temp = new Node(x) ;
            if(top == NULL){
                top = temp ;
                return ;
            }
            temp->next = top ;
            top = temp ;
        }
        void pop(){
            Node* temp = top ;
            top = top->next ;
            delete temp ;
        }
        void print(){
            Node* temp = top ;
            while(temp!=NULL){
                cout << temp->data <<" " ;
                temp = temp->next ;
            }
            cout << endl ;
        }
};

int main(){
    Stack s ;
    s.push(4) ;
    s.push(1) ;
    s.print() ;
    s.push(2) ;
    s.push(11) ;
    s.push(46) ;
    s.push(9) ;
    s.print();
    s.pop();
    s.pop();
    s.print() ;
}