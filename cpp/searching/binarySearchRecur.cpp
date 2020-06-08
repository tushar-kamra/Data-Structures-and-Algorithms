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

int main(){
    int n, x ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    cin >> x ;
    int ans = binarySearch(a,0,n-1,x); 
    if(ans != -1){
        cout << "Found at index = " << ans ;
    }
    else {
        cout << "Not found..." ;
    }
}