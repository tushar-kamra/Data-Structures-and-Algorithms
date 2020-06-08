#include<iostream>
using namespace std ;

int missingshoe(int a[], int l, int r){
    int mid = (l+r)/2 ;
    if(l<=r){
        if((a[mid-1] != a[mid]) && (a[mid] != a[mid+1])){
            return a[mid] ; 
        }
        else if(a[mid] == a[mid-1]){
            return missingshoe(a,mid+1,r);
        }
        else{
            return missingshoe(a,l,mid-1) ;
        }
    }
    return -1 ;
}

int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    cout << missingshoe(a,0,n-1) ;
}