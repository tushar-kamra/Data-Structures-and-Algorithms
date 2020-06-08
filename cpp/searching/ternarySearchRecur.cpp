#include<iostream>
using namespace std ;

int ternarySearch(int a[], int low, int high, int x){
    if(low<=high){
        int mid1 = low+(high-low)/3 ;
        int mid2 = mid1 + (high-low)/3 ;
        if(a[mid1] == x) return mid1 ;
        else if(a[mid2] == x) return mid2 ;
        else if(a[mid1] > x) return ternarySearch(a,low,mid1-1,x) ;
        else if(a[mid2] < x) return ternarySearch(a,mid2+1,high,x) ;
        else return ternarySearch(a,mid1+1,mid2-1,x) ;
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
    int ans = ternarySearch(a,0,n-1,x); 
    if(ans != -1){
        cout << "Found at index = " << ans ;
    }
    else {
        cout << "Not found..." ;
    }
}