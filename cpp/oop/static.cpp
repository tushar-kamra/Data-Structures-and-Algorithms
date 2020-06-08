#include<iostream>
using namespace std ;

class demo {
    int c ;
    static int data ;
    void display(){
            cout << c ;
        }
    public :
        int d  ;
        
        
        demo(int e){
            d = 2 ;
            data = e ;
        }
} ;



int main(){
    demo d(2) ;

}