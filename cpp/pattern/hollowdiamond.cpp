#include<iostream>
using namespace std ;

int main(){
    int n ;
    cin >> n ;
    int nsp = 1 ;
    int nst = n/2 ;
    for(int r=1; r<=n; r++){
        for(int cst = 1; cst<=nst; cst++){
            cout<<"*" ;
        }
        for(int csp = 1; csp<=nsp; csp++){
            cout<<"." ;
        }
        for(int cst = 1; cst<=nst; cst++){
            cout<<"*" ;
        }
        if(r<=n/2){
            nst-- ;
            nsp += 2 ;
        }
        else {
            nst++ ;
            nsp -= 2 ;
        }
        cout<<endl ;
    }
}