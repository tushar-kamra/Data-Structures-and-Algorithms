#include<iostream>
using namespace std ;

void maxHeapify(int a[], int i, int n){
    int largest = i ;
    int l = 2*i+1 ;
    int r = 2*i+2 ;
    if(l<n && a[l]>a[largest]){
        largest = l ;
    }
    if(r<n && a[r]>a[largest]){
        largest = r ;
    }
    if(i!=largest){
        swap(a[i],a[largest]) ;
        maxHeapify(a,largest,n) ;
    }
}

int extractMax(int a[], int n){
    if(n<=0){
        return -1 ;
    }
    int root = a[0] ;
    a[0] = a[n-1] ;
    maxHeapify(a,0,n) ;
    return root ;
}

void buildheap(int a[], int n){
    int i = n/2 - 1 ;
    for(int j=i; j>=0; j--){
        maxHeapify(a,j,n) ;
    }
}

int main(){
    int n,k ;
    cin >> n >> k ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    buildheap(a,n) ;
    for(int i=0; i<k-1; i++){
        extractMax(a,n-i) ;
    }
    cout << a[0] ;
}