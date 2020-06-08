#include<iostream>
#include<climits>
#include<algorithm>
using namespace std ;

void klargest(int a[], int n, int k){
    int temp[k] ;
    for(int i=0; i<k; i++){
        temp[i] = a[i];
    }
    for(int i=k; i<n; i++){
        int idx, min = INT_MAX ;
        for(int j=0; j<k; j++){
            if(temp[j] < min){
                min = temp[j] ;
                idx = j ;
            }
        }
        if(a[i] > min){
            temp[idx] = a[i] ;
        }
    }
    sort(temp,temp+k) ;
    for(int i=0; i<k; i++){
        cout << temp[i]<<" " ;
    }
}

int main(){
    int n, k ;
    cin >> n >> k ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    klargest(a,n,k) ;
}