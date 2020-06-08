#include<iostream>
using namespace std ;

void bubbleSort(int a[], int n){
    for(int i=0; i<n; i++){
        bool swapped = false ;
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]) ;
                swapped = true ;
            }
        }
        if(swapped == false) break ;
    }
}

int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    bubbleSort(a,n) ;
    for(int i=0; i<n; i++){
        cout << a[i] <<" " ;
    }
}