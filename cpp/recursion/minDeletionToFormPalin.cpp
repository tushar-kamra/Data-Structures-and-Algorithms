#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int minDeletion(string s, int i, int j, vector<vector<int>>& dp){
    if(i == j) return 0 ;
    if(i == j-1){
        if(s[i] == s[j]) return 0 ;
        return 1 ;
    }
    if(dp[i][j] != 0) return dp[i][j] ;
    int c = INT_MAX ;
    if(s[i] == s[j]){
        c = minDeletion(s,i+1,j-1,dp) ;
    }
    else {
        c = min(minDeletion(s,i+1,j,dp),minDeletion(s,i,j-1,dp))+1 ;
    }
    dp[i][j] = c ;
    return c ;
}

int main() {
	int t ;
	cin >> t ;
	while(t--){
	    string s ;
	    cin >> s ;
        vector<vector<int>> dp(10000,vector<int>(10000,0)) ;
	    cout << minDeletion(s,0,s.length()-1,dp) << endl ;
	}
	return 0;
}