#include<iostream>
using namespace std ;

void merge(int a[], int low, int mid, int high){
    int k1 = mid-low+1 ;
    int k2 = high-mid ;
    int b[k1], c[k2] ;
    for(int i=0; i<k1; i++){
        b[i] = a[low+i] ;
    }
    for(int j=0; j<k2; j++){
        c[j] = a[mid+j+1] ;
    }
    int i=0, j=0, k=low ;
    while(i<k1 && j<k2){
        if(b[i] < c[j]){
            a[k++] = b[i++] ;
        }
        else {
            a[k++] = c[j++] ;
        }
    }
    while(i<k1){
        a[k++] = b[i++] ;
    }
    while(j<k2){
        a[k++] = c[j++] ;
    }
}

void mergeSort(int a[], int low, int high){
    if(low < high){
        int mid = low + (high-low)/2;
        mergeSort(a,low,mid) ;
        mergeSort(a,mid+1,high) ;
        merge(a,low,mid,high) ;
    }
}

int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    mergeSort(a,0,n-1) ;
    for(int i=0; i<n; i++){
        cout << a[i] << " " ;
    }
}