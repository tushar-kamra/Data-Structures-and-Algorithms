#include<iostream>
#include<vector>
using namespace std ;

int rodcutting(int price[], int n, vector<int> dp){
    if(n == 0){
        return 0 ;
    }
    if(dp[n] != 0){
        return dp[n] ;
    }

    int ans = price[n];
    int left = 1 ;
    int right = n-1 ;

    while(left <= right){
        int lsum = rodcutting(price, left, dp) ;
        int rsum = rodcutting(price, right, dp) ;
        if(lsum+rsum > ans){
            ans = lsum+rsum ;
        }
        left++ ;
        right-- ;
    }
    dp[n] = ans ;
    return ans ;
}

int main(){
    int n ;
    cin >> n ;
    int price[n] ;
    for(int i=0; i<n; i++){
        cin >> price[i] ;
    }
    vector<int> dp(n,0) ;
    cout << rodcutting(price,8,dp) ;
}