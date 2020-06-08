#include<iostream>
using namespace std ;

int minindex(int a[], int l, int r){
    if(l == r) return l ;
    int res = minindex(a,l+1,r);
    if(a[l]<a[res]){
        return l ;
    }
    else {
        return res ;
    }
}

void selSort(int a[], int idx, int n){
    if(idx == n-1) return ;
    int k = minindex(a,idx,n-1);
    if(k != idx){
        swap(a[idx],a[k]);
    }
    selSort(a,idx+1,n);
}

int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    selSort(a,0,n) ;
    for(int i=0; i<n; i++){
        cout << a[i] <<" " ;
    }
}