#include<iostream>
using namespace std ;

int main(){
    int n ;
    cin >> n ;
    int nsp = n/2 ;
    int nst = 1 ;
    for(int r=1; r<=n; r++){
        for(int csp=1; csp<=nsp; csp++){
            cout<<" " ;
        }
        for(int cst=1; cst<=nst; cst++){
            cout<<"*" ;
        }
        if(r<(n+1)/2){
            nsp-- ;
            nst +=2 ;
        }
        else {
            nsp++ ;
            nst -= 2 ;
        }
        cout<<endl ;
    }
}