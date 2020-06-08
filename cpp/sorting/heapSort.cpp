#include<iostream>
using namespace std ;

void maxHeapify(int a[], int i, int size){
    int largest = i ;
    int l = 2*i+1 ;
    int r = 2*i+2 ;
    if(l<size && a[l] > a[largest]){
        largest = l ;
    }
    if(r<size && a[r] > a[largest]){
        largest = r ;
    }
    if(i!=largest){
        swap(a[i],a[largest]) ;
        maxHeapify(a,largest,size) ;
    }
}

void heapSort(int a[], int n){
    // Build Heap = O(n)
    for(int i=n/2-1; i>=0; i--){
        maxHeapify(a,i,n) ;
    }

    for(int i = n-1; i>=0; i--){
        swap(a[i],a[0]);
        maxHeapify(a,0,i) ;
    }
}

void print(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] <<" " ;
    }
}

int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    heapSort(a,n) ;
    print(a,n) ;
}