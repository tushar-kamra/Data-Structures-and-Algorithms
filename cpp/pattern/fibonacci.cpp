#include<iostream>
using namespace std ;

int main(){
    int n ;
    cin >> n ;
    int a=0, b=1, c ;
    for(int r=1; r<=n; r++){
        if(r==1){
            cout<<a<<endl ;
            continue ;
        }
        if(r==2){
            cout<<b<<" ";
            c = a+b ;
            a = b ;
            b = c ;
            cout<<c<<endl ;
            continue ;
        }
        for(int nst=1; nst<=r; nst++){
            c = a+b ;
            a = b ;
            b = c ;
            cout<<c<<" " ;
        }
        cout<<endl ;
    }
}