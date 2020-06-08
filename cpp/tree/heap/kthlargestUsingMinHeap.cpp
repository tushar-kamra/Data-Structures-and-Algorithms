#include<iostream>
using namespace std ;

void minHeapify(int a[], int i, int n){
    int smallest = i ;
    int l = 2*i+1 ;
    int r = 2*i+2 ;
    if(l<n && a[l]<a[smallest]){
        smallest = l ;
    }
    if(r<n && a[r]<a[smallest]){
        smallest = r ;
    }
    if(i!=smallest){
        swap(a[i],a[smallest]) ;
        minHeapify(a,smallest,n) ;
    }
}

int extractMin(int a[], int n){
    if(n<=0){
        return -1 ;
    }
    int root = a[0] ;
    a[0] = a[n-1] ;
    minHeapify(a,0,n) ;
    return root ;
}

void buildheap(int a[], int n){
    int i = n/2 - 1 ;
    for(int j=i; j>=0; j--){
        minHeapify(a,j,n) ;
    }
}

int main(){
    int n,k ;
    cin >> n >> k ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    buildheap(a,k) ;
    for(int i=k; i<n; i++){
        if(a[i] > a[0]){
            a[0] = a[i] ;
            minHeapify(a,0,k) ;
        }
    }
    cout << a[0] ;
}