#include<iostream>
using namespace std ;

void klargest(int a[], int n, int k){
    for(int i=0; i<k; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]) ;
            }
        }
    }
}

int main(){
    int n,k ;
    cin >> n >> k ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    klargest(a,n,k) ;
    for(int i=n-k; i<n; i++){
        cout << a[i] <<" " ;
    }
}