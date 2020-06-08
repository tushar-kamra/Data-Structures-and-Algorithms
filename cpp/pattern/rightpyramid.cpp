#include<iostream>
using namespace std ;

int main(){
    int n ;
    cin >> n ;
    int nst = 1 ;
    for(int r=1; r<=n; r++){
        for(int cst=1; cst<=nst; cst++){
            cout<<"*" ;
        }
        if(r<=n/2){
            nst++ ;
        }
        else {
            nst-- ;
        }
        cout<<endl ;
    }
}