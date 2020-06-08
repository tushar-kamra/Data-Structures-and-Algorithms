#include <iostream>
using namespace std ;

int main(){
    int n ;
    cin >> n ;
    int a[n][n] ;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j] ;
        }
    }
    for(int gap=0; gap<n; gap++){
        for(int i=0,j=gap; i<n && j<n; i++,j++){
            cout << a[i][j]<<" " ;
        }
    }
}