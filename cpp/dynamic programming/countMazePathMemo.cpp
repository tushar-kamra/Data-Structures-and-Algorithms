#include<iostream>

using namespace std ;

int mazePath(int x1, int y1, int x2, int y2, int dp[][100]){
    if(x1 == x2 && y1 == y2){
        dp[x2][y2] = 1 ;
        return 1 ;
    }
    if(dp[x1][y1] != 0) {
        return dp[x1][y1] ;
    }
    int c = 0 ;
    if(x1 < x2){
        c += mazePath(x1+1,y1,x2,y2,dp) ;
    }
    if(y1 < y2){
        c += mazePath(x1,y1+1,x2,y2,dp);
    }
    dp[x1][y1] = c ;
    return c ;
}

int main(){
    int x1,y1,x2,y2 ;
    cin >> x1 >> y1 >> x2 >> y2 ;
    int dp[100][100] = {} ;
    cout << mazePath(x1,y1,x2,y2,dp) << endl ;
}