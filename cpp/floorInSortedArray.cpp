#include<iostream>
using namespace std ;

int bs(int a[], int l, int r, int x){
    while(l<=r){
        int mid = (l+r)/2 ;
        if(a[mid] == x){
            return mid ;
        }
        else if(a[mid] > x){
            r = mid-1 ;
        }
        else {
            l = mid+1 ;
        }
    }
    return l ;
}

int main(){
    int n, x ;
    cin >> n >> x ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    int ans = bs(a,0,n-1,x) ;
    cout << a[ans] ;
}