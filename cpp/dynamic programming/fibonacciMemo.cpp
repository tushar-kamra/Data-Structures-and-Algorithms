#include<iostream>
using namespace std ;

int fib(int n, int dp[]){
    if(n == 0 || n == 1 ){
        return n ;
    }
    if(dp[n] != 0){
        return dp[n] ;
    }
    int a = fib(n-1,dp) ;
    int b = fib(n-2,dp) ;
    int ans = a+b ;
    dp[n] = ans ;
    return ans ;
}

int main(){
    int n ;
    cin >> n ;
    int dp[n+1] = {0} ;
    cout << fib(n,dp) ;
}