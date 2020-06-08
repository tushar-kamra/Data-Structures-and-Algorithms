#include <iostream>
using namespace std;

int findIndex(int a[], int idx, int n, int m){
    if(idx == n) return -1 ;
    if(a[idx]==m) return idx ;
    return findIndex(a,idx+1,n,m) ;
}

int main() {
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    int m ;
    cin >> m ;
    cout << findIndex(a,0,n,m) ;
    return 0;
}
