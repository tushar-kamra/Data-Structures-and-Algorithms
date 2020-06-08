#include<iostream>
using namespace std ;

int binarySearch(int a[], int low, int high, int x){
    while(low<=high){
        int mid = low + (high-low)/2 ;
        if(a[mid] == x) return mid ;
        else if(a[mid] < x) low = mid+1 ;
        else high = mid-1 ;
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