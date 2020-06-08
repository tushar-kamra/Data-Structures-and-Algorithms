#include<iostream>
#include<vector>
using namespace std ;

vector<int> findAllIndex(int a[], int idx, int n, int m,vector<int> v){
    if(idx == n) return v;
    if(a[idx] == m) v.push_back(idx) ;
    return findAllIndex(a,idx+1,n,m,v) ;
}

int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    int m,i ;
    cin >>m >>i ;
    vector<int> v ;
    v = findAllIndex(a,0,n,m,v) ;
    cout << v[i] ;
}