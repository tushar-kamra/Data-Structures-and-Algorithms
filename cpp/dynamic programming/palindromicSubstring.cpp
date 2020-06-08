#include<iostream>
#include<vector>

using namespace std ;

int main(){
    string str ;
    cin >> str ;
    int n = str.length();
    int c = 0 ;
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    for(int gap=0; gap<n; gap++){
        for(int i=0,j=gap; i<n && j<n; i++,j++){
            if(gap == 0){
                dp[i][j] = true ;
                c++ ;
            }
            else if(gap == 1){
                if(str[i] == str[j]){
                    dp[i][j] = true ;
                    c++ ;
                }
                else {
                    dp[i][j] = false ;
                }
            }
            else {
                if(str[i] == str[j] && dp[i+1][j-1]){
                    dp[i][j] = true ;
                    c++ ;
                }
                else {
                    dp[i][j] = false ;
                }
            }
        }
    }
    cout << c ;
}