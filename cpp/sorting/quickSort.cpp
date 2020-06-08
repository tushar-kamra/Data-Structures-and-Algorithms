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

void quickSort(int a[], int start, int end){
    if(start < end){
        int p = partition(a,start,end) ;
        quickSort(a,start,p-1) ;
        quickSort(a,p+1,end) ;
    }
}

int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    quickSort(a,0,n-1) ;
    for(int i=0; i<n; i++){
        cout << a[i] <<" " ;
    }
}