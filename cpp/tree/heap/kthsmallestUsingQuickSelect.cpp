#include<iostream>
using namespace std ;

int partition(int a[], int start, int end){
    int pIndex = start ;
    int pivot = a[end] ;
    for(int i=start; i<end; i++){
        if(a[i] <= pivot){
            swap(a[pIndex],a[i]) ;
            pIndex++ ;
        }
    }
    swap(a[pIndex],a[end]) ;
    return pIndex ;
}

int kthsmallest(int a[], int start, int end, int k){
    if(k > 0 && k <= end-start+1){
        int p = partition(a,start,end) ;
        if(p-start == k-1){
            return a[p] ;
        }
        if(p-start > k){
            return kthsmallest(a,start,p-1,k) ;
        }
        return kthsmallest(a,p+1,end,k-p-1+start) ;
    }
    return -1 ;
}

int main(){
    int n, k ;
    cin >> n >> k ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    cout << kthsmallest(a,0,n-1,k) ;
}