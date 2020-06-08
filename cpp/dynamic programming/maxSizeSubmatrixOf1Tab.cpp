#include <iostream>
#include <vector>
using namespace std ;

int main(){
    int r,c ;
    cin >> r >> c ;
    vector<vector<int>> v(r,vector<int>(c)) ;
    vector<vector<int>> dp(r,vector<int>(c)) ;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> v[i][j] ;
        }
    }
    int size = 0 ;
    for(int i=r-1; i>=0; i--){
        for(int j=c-1; j>=0; j--){
            if(i == r-1 && j == c-1){
                dp[i][j] = v[i][j] ;
            }
            else if(i == r-1){
                dp[i][j] = v[i][j] ;
            }
            else if(j == c-1){
                dp[i][j] = v[i][j] ;
            }
            else {
                if(v[i][j] == 0){
                    dp[i][j] = 0 ;
                }
                else {
                    dp[i][j] = min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1])) + 1 ;
                }
            }
            if(dp[i][j] > size){
                size = dp[i][j] ;
            }
        }
    }
    cout << size << endl ;
}