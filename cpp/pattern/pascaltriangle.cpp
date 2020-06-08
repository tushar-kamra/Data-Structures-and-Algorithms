#include<iostream>
using namespace std ;

int main(){
    int row ;
    cin >> row ;
    for(int n=0; n<row; n++){
        int val = 1 ;
        for(int space=0; space<row-n; space++){
            cout<<" " ;
        }
        for(int r=0; r<=n; r++){
            cout<<val<<" " ;
            //cout<<"* ";
            val = val*(n-r)/(r+1) ;
        }
        cout<<endl ;
    }
}