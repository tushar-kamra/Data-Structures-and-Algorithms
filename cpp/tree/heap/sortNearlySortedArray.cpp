#include<iostream>
#include<queue>
using namespace std ;

void sortKsorted(int a[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq(a,a+k+1) ;
    int idx = 0 ;
    for(int i=k+1; i<n; i++){
        a[idx++] = pq.top() ;
        pq.pop() ;
        pq.push(a[i]) ;
    }
    while(!pq.empty()){
        a[idx++] = pq.top() ;
        pq.pop() ;
    }
}

void print(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] <<" " ;
    }
}

int main(){
    int n, k ;
    cin >> n >> k ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    sortKsorted(a,n,k) ;
    print(a,n) ;
}