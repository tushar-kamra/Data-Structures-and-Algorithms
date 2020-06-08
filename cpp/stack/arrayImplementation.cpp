#include<iostream>
using namespace std ;

class Stack {
    int top ;
    int capacity ;
    int *stack ;
    public :
        Stack(){
            top = -1 ;
            capacity = 5 ;
            stack = new int[capacity] ;
        }
        void push(int x){
            if(top == capacity-1){
                cout << "Overflow...\n" ;
                return ;
            }
            stack[++top] = x ;
        }
        void pop(){
            if(capacity == -1){
                cout << "Underflow...\n" ;
                return ;
            }
            top-- ;
        }
        int tope(){
            return stack[top] ;
        }
};

int main(){
    Stack s ;
    s.push(5) ;
    s.push(1) ;
    s.push(7) ;
    cout << s.tope() << endl ;
    s.push(9) ;
    s.push(43) ;
    s.push(3) ;
    s.pop() ;
    cout << s.tope() ;
}