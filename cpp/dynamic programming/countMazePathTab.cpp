#include<iostream>
using namespace std ;

int main(){
    int x1,y1,x2,y2 ;
    cin >> x1 >> y1 >> x2 >> y2 ;
    int dp[100][100] = {} ;
    dp[x2][y2] = 1 ;
    for(int i=x2; i>=0; i--){
        for(int j=y2; j>=0; j--){
            if(i == x2 && j == y2){
                continue ;
            }
            dp[i][j] = dp[i+1][j] + dp[i][j+1] ;
        }
    }
    cout << dp[0][0] ;
}