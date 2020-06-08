#include<iostream>
#include<climits>
#include<cmath>

using namespace std ;

int minCostPath(int x1, int y1, int x2, int y2, int cost[][100], int dp[][100]){
    if(x1 == x2 && y1 == y2){
        return cost[x1][y1] ;
    }
    if(dp[x1][y1] != 0){
        return dp[x1][y1] ;
    }
    int minPath = 0 ;
    int minH = INT_MAX ;
    int minV = INT_MAX ;
    if(x1 < x2){
        minH = minCostPath(x1+1,y1,x2,y2,cost,dp) ;
    }
    if(y1 < y2){
        minV = minCostPath(x1,y1+1,x2,y2,cost,dp) ;
    }
    minPath = cost[x1][y1] + min(minH,minV) ;
    dp[x1][y1] = minPath ;
    return minPath ;
}

int main(){
    int x1,y1,x2,y2 ;
    cin >> x1 >> y1 >> x2 >> y2 ;
    int cost[x2+1][100] ;
    int dp[x2+1][100] = {} ;
    for(int i=0; i<=x2; i++){
        for(int j=0; j<=y2; j++){
            cin >> cost[i][j] ;
        }
    }
    cout << minCostPath(x1,y1,x2,y2,cost,dp) ;
}