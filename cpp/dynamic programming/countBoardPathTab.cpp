#include<iostream>
using namespace std ;

int main(){
    int d ;
    cin >> d ;
    int dp[d+1] = {} ;
    dp[d] = 1 ;
    for(int i=d-1; i>=0; i--){
        for(int dice=1; dice<=6; dice++){
            if(i+dice <= d){
                dp[i] += dp[i+dice] ;
            }
        }
    }
    cout << dp[0] << endl ;
}