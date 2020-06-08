#include<iostream>
using namespace std ;

bool isSorted(int a[], int n){
    if(n == 0 || n == 1) return true ;
    if(a[n-1] > a[n-2]){
        return isSorted(a,n-1) ;
    }
    return false ;
}

int main(){
    int n ;
    cin>>n ;
    int a[n] ;
    for(int i=0; i<n ; i++){
        cin >> a[i] ;
    }
    if(isSorted(a,n)) cout << "true" ;
    else cout << "false " ;
}