#include<iostream>
#include<vector>
using namespace std ;

void LIS(int a[], int dp[], int n){
    string path[n] ;
    dp[0] = 1 ;
    path[0] = to_string(a[0]) ;
    for(int i=1; i<n; i++){
        dp[i] = 0 ;
        for(int j=0; j<i; j++){
            if(a[j]<a[i]){
                if(dp[j]>dp[i]){
                    dp[i] = dp[j] ;
                    path[i] = path[j] + " " ;
                }
            }
        }
        dp[i] += 1 ;
        path[i] += to_string(a[i]);
    }
    for(int i=0 ; i<n; i++){
        cout << path[i] << endl ;
    }
}

int main(){
    int n;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    int dp[n] = {} ;
    LIS(a,dp,n);
    for(int i=0; i<n; i++){
        cout << dp[i] << " " ;
    }
}