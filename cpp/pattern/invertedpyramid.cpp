#include<iostream>
using namespace std ;

int main(){
    int n ;
    cin >> n ;
    int nsp = 0 ;
    int nst = 2*n-1 ;
    for(int r=1; r<=n; r++){
        for(int csp=1; csp<=nsp; csp++){
            cout<<" ";
        }
        for(int cst=1; cst<=nst; cst++){
            cout<<"*" ;
        }
        nst -= 2 ;
        nsp++ ;
        cout<<endl ;        
    }
}