#include<iostream>
using namespace std ;

class A {
    public:
        virtual ~A(){
            cout << "Base" << endl ;
        }
};

class B : public A {
    public:
        ~B(){
            cout << "Derived" << endl ;
        }
};

int main(){
    A *obj = new B ;
    delete obj ;
}