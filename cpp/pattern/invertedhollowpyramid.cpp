#include<iostream>
using namespace std ;

int main(){
    int n ; 
    cin >> n ;
    int nsp = 2*n-1 ;
    int nst = 1 ;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=2*n-1; j++){
            if(j<=i || j>=2*n-i){
                cout<<"*" ;
            }
            else {
                cout<<" " ;
            }
        }
        cout<<endl ;
    }

    for(int r=1; r<=n; r++){
        for(int cst=1; cst<=nst; cst++){
            cout<<"*" ;
        }
        for(int csp=1; csp<=nsp; csp++){
            cout<<" " ;
        }
        for(int cst=1; cst<=nst; cst++){
            cout<<"*" ;
        }
        nst++ ;
        nsp-=2;
        cout<<endl ;
    }

}