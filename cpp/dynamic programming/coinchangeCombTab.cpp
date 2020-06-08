#include<iostream>
#include<vector>

using namespace std ;

int main(){
    int n, amount ;
    cin >> n >> amount;
    int denom[n] ;
    vector<int> dp(amount+1,0) ;
    vector<vector<string>> path(amount+1,vector<string>()) ;

    for(int i=0; i<n; i++){
        cin >> denom[i] ;
    }
    dp[0] = 1 ;
    path[0].push_back("") ;
    for(int i=0; i<n; i++){
        for(int j=denom[i]; j<=amount; j++){
            dp[j] = dp[j] + dp[j-denom[i]] ;
            for(int k=0; k<path[j-denom[i]].size(); k++){
                path[j].push_back(path[j-denom[i]][k]+to_string(denom[i]));
            }
        }
    }
    for(int i=0; i<=amount; i++){
        cout << dp[i] <<" " ;
    }
    cout << endl ;
    cout <<"Number of ways : " << dp[amount] << endl ;
    for(int i=0; i<path[amount].size(); i++){
        cout << path[amount][i] << endl ;
    }
}