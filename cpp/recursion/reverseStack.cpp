#include<iostream>
#include<stack>

using namespace std ;

stack<int> s ;

void insertAtBottom(int x){
    if(s.empty()){
        s.push(x) ;
    }
    else {
        int temp = s.top() ;
        s.pop() ;
        insertAtBottom(x) ;
        s.push(temp) ;
    }
}

void reverseStack(){
    if(s.size()>0){
        int ele = s.top() ;
        s.pop() ;
        reverseStack() ;
        insertAtBottom(ele) ;
    }
}

int main(){
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    reverseStack() ;
    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop() ;
    }
}