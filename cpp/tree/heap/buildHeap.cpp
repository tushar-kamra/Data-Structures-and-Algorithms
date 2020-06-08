#include<iostream>
using namespace std ;

void maxHeapify(int a[], int i, int size){
    int largest = i ;
    int l = 2*i + 1 ;
    int r = 2*i + 2 ;
    if(l<size && a[l]>a[largest]){
        largest = l ;
    }
    if(r<size && a[r]>a[largest]){
        largest = r ;
    }
    if(largest != i){
        swap(a[i],a[largest]);
        maxHeapify(a,largest,size) ;
    }
}

void buildheap(int a[], int n){
    int i = n/2 - 1 ;
    for(int j=i; j>=0; j--){
        maxHeapify(a,j,n) ;
    }
}

void printHeap(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i]<<" " ;
    }
}
int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    buildheap(a,n) ;
    printHeap(a,n) ;
}