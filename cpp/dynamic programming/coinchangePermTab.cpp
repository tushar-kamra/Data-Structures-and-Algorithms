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


    for(int i=1; i<=amount; i++){
        for(int j=0; j<n; j++){
            if(i-denom[j] >= 0){
                dp[i] = dp[i] + dp[i-denom[j]] ;
                for(int k=0; k<path[i-denom[j]].size(); k++){
                    path[i].push_back(path[i-denom[j]][k]+to_string(denom[j]));
                }
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