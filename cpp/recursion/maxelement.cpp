#include<iostream>
using namespace std ;

int maximum1(int a[], int idx, int n){
    if(idx == n-1) return a[idx] ;
    int res = maximum1(a,idx+1,n) ;
    return max(res,a[idx]);
}

int maximum2(int a[], int n){
    if(n == 0) return a[n] ;
    int res = maximum2(a,n-1);
    return max(res,a[n]) ;
}

int main(){
    int n;
    cin >> n; 
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << maximum1(a,0,n) << endl ;
    cout << maximum2(a,n-1) ;
}