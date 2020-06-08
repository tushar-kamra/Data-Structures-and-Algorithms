#include<iostream>
#include<vector>

using namespace std ;

int LIS(int a[], int dp[], int idx){
    if(idx == 0){
        return 1 ;
    }
    if(dp[idx]!=0){
        return dp[idx] ;
    }
    int ans = 0 ;
    for(int i=0; i<idx; i++){
        if(a[i] < a[idx]){
            int temp = LIS(a,dp,i) ;
            if(temp > ans){
                ans = temp ;
            }
        }
    }
    ans += 1 ;
    dp[idx] = ans ;
    return ans ;
}

int main(){
    int n ;
    cin >> n ;
    int a[n] , dp[n] = {} ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    int maxi = 0 ;
    for(int i=0; i<n; i++){
        int temp = LIS(a,dp,i) ;
        if(temp > maxi){
            maxi = temp ;
        }
    }
    cout << maxi ;
}