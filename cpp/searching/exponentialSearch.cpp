#include<iostream>
using namespace std ;

int binarySearch(int a[], int low, int high, int x){
    if(low<=high){
        int mid = low + (high-low)/2 ;
        if(a[mid] == x) return mid ;
        else if(a[mid] < x) return binarySearch(a,mid+1,high,x) ;
        else return binarySearch(a,low,mid-1,x) ;
    }
    return -1 ;
}

int exponentialSearch(int a[], int n, int x){
    if(a[0] == x) return 0 ;
    int i = 1 ;
    while( i<n && a[i]<x){
        i *= 2 ;
    }
    return binarySearch(0,i/2,min(i,n),x) ;
}

int main(){
    int n, x ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    cin >> x ;
    int ans = exponentialSearch(a,n,x); 
    if(ans != -1){
        cout << "Found at index = " << ans ;
    }
    else {
        cout << "Not found..." ;
    }
}