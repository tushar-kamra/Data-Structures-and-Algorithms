// #include<iostream>
// #include<vector>
// #include<climits>

// using namespace std ;

// bool isPalin(string s, int si, int ei){
//     int left = si ;
//     int right = ei ;
//     while(left < right){
//         if(s[left] != s[right]){
//             return false ;
//         }
//         left++;
//         right-- ;
//     }
//     return true ;
// }

// static int counter = 0 ;
// int mpc(string s, int si, int ei, vector<vector<int>>& dp){
//     if(isPalin(s,si,ei)){
//         return 0 ;
//     }
//     if(dp[si][ei] != 0){
//         return dp[si][ei] ;
//     }
//     cout << counter++ <<endl ;
//     int ans = INT_MAX ;
//     for(int cp=si; cp<ei; cp++){
//         int mpcSubstring1 = mpc(s,si,cp,dp) ;
//         int mpcSubstring2 = mpc(s,cp+1,ei,dp) ;
//         int total = mpcSubstring1 + mpcSubstring2 + 1 ;
//         if(total < ans){
//             ans = total ;
//         }
//     }
//     dp[si][ei] = ans ;
//     return ans ;
// }

// int main(){
//     string s ;
//     cin >> s ;
//     vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
//     int ans = mpc(s,0,s.length()-1,dp) ;
//     cout << "Min no. of cut = " << ans ;
// }

#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001] ;

bool isPalin(string s, int i, int j){
    while(i < j){
        if(s[i] != s[j]){
            return false ;
        }
        i++ ;
        j-- ;
    }
    return true ;
}

static int counter =0  ;
int minCut(string s, int i, int j){
    if(isPalin(s,i,j)) return 0 ;
    if(dp[i][j] != 0){
        return dp[i][j] ;
    }
    cout << counter++ << endl ;
    int ans = INT_MAX ; 
    int left, right ;
    for(int k=i; k<=j-1; k++){
        if(dp[i][k]!=0){
            left = dp[i][k] ;
        }
        else {
            left = minCut(s,i,k) ;
            dp[i][k] = left ;
        }
        if(dp[k+1][j] != 0){
            right = dp[k+1][j] ;
        }
        else {
            right = minCut(s,k+1,j);
            dp[k+1][j] = right ;
        }
        int temp = 1 + left + right ;
        ans = min(ans,temp) ;
    }
    dp[i][j] = ans ;
    return ans ;
}

int main() {
	int t ;
	cin >> t ;
	while(t--){
	    string s ;
	    cin >> s ;
	    int n = s.length()-1 ;
	    memset(dp,0,sizeof dp);
	    cout << minCut(s,0,n) << "\n" ;
	}
	return 0;
}