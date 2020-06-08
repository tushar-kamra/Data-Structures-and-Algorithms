#include<iostream>
using namespace std ;

int bp(int s, int e, int dp[]){
    if(s == e){
        dp[s] = 1 ;
        return 1 ;
    }
    if(dp[s] != 0){
        return dp[s] ;
    }
    int count = 0 ;
    for(int dice=1; dice<=6; dice++){
        if(s+dice <= e){
            count += bp(s+dice,e,dp) ;
        }
    }
    dp[s] = count ;
    return count ;
}

int main(){
    int d ;
    cin >> d ;
    int dp[d+1] = {} ;
    cout << bp(0,d,dp) ;
}