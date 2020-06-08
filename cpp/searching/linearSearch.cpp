#include<iostream>
using namespace std ;

int linearSearch(int a[], int n, int x){
    for(int i=0; i<n; i++){
        if(a[i] == x) return i ;
    }
    return -1 ;
}

int main(){
    int n, x ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    cin >> x ;
    int ans = linearSearch(a,n,x); 
    if(ans != -1){
        cout << "Found at index = " << ans ;
    }
    else {
        cout << "Not found..." ;
    }
}