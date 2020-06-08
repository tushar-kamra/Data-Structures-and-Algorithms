#include<iostream>
#include<cmath>
using namespace std ;

int jumpSearch(int a[], int n, int x){
    int left = 0 ;
    int right = sqrt(n) ;
    while(left <= right && x > a[right]){
        left = right ;
        right += sqrt(n) ;
    }
    for(int i=left; i<=min(right,n-1); i++){
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
    int ans = jumpSearch(a,n,x); 
    if(ans != -1){
        cout << "Found at index = " << ans ;
    }
    else {
        cout << "Not found..." ;
    }
}