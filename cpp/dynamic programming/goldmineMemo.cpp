#include<iostream>
#include<vector>

using namespace std ;

int maxi = -1 ;
int goldmine(int x, int y, vector<vector<int>> v, vector<vector<int>>& dp){
    if(x < 0 || x > v.size()-1){
        return -1 ;
    }
    if(y == v[0].size()-1){
        return v[x][y] ;
    }
    if(dp[x][y]!=0){
        return dp[x][y] ;
    }
    int a = goldmine(x-1,y+1,v,dp) ;
    int b = goldmine(x,y+1,v,dp) ;
    int c = goldmine(x+1,y+1,v,dp) ;
    int ans = v[x][y]+max(a,max(b,c)) ;
    dp[x][y] = ans ;
    return ans ;
}

int main(){
    int r,c ;
    cin >> r >> c ;
    vector<vector<int>> v(r,vector<int>(c));
    vector<vector<int>> dp(r,vector<int>(c,0));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> v[i][j] ;
        }
    }
    for(int i=0; i<r; i++){
        maxi = max(maxi,goldmine(i,0,v,dp)) ;
    }
    cout << maxi;
}