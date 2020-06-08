#include<iostream>
using namespace std ;

static int c = 0 ;

int lps(string s, int i, int j, int dp[][100]){
    if(i > j) return 0 ;
    if(i == j) return 1 ;
    if(dp[i][j] != 0) return dp[i][j] ;
    int count = 0 ;
    cout << c++ << endl ;
    if(s[i] == s[j]){
        count = 2+lps(s,i+1,j-1,dp) ;
    }
    count = max(count,max(lps(s,i+1,j,dp),lps(s,i,j-1,dp)));
    dp[i][j] = count ;
    return count ;
}

int main(){
    string s;
    cin >> s ;
    int dp[100][100] = {} ;
    cout << lps(s,0,s.length()-1,dp) ;
}