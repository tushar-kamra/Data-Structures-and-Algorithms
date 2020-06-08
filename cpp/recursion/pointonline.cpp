#include<iostream>
using namespace std ;

bool pointonline(int a[][2], int n, int idx){
    if(idx == n-1){
        return true ;
    }
    if(a[idx][0] == a[idx+1][0]){
        return pointonline(a,n,idx+1);
    }
    else if(a[idx][1] == a[idx+1][1]){
        return pointonline(a,n,idx+1);
    }
    return false ;
}

int main(){
    int n ;
    cin >> n ;
    int a[n][2] ;
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cin >> a[i][j] ;
        }
    }
    (pointonline(a,n,0))?cout<<"YES":cout<<"NO" ;
}