#include<iostream>
using namespace std ;

int main(){
    int n, nsp, nst ;
    cin >> n ;
    nsp = n-1 ;
    nst = 1 ;
    for(int r=1; r<=n; r++){
        for(int csp=1; csp<=nsp; csp++){
            cout<<" " ;
        }
        for(int cst=1; cst<=nst; cst++){
            cout<<"*" ;
        }
        nsp-- ;
        nst += 2 ;
        cout<<endl ;
    }
}