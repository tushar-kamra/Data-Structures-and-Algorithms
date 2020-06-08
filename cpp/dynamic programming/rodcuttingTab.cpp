#include<iostream>
#include<vector>
using namespace std ;

int main(){
    int n ;
    cin >> n ;
    int price[n], dp[n] ;
    vector<string> path(n) ;
    for(int i=0; i<n; i++){
        cin >> price[i] ;
    }
    dp[0] = 0 ;
    dp[1] = price[1] ;
    path[0] = "0 " ;
    path[1] = "1 " ;
    string ans = "" ;
    for(int i=2; i<n; i++){
        int x=1, y=i-1 ;
        dp[i] = price[i] ;
        path[i] = char('0'+i);
        while(x<=y){
            int one = dp[x] ;
            int two = dp[y] ;
            if(one+two > dp[i]){
                dp[i] = one+two ;
                path[i] = path[x] + path[y] ;
            }
            x++ ;
            y-- ;
        }
    }
    for(int i=0; i<n; i++){
        cout << dp[i] <<" @ " << path[i] << endl ;
    }
}