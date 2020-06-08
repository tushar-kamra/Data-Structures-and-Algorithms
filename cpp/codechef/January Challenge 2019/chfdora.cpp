#include<iostream>
using namespace std ;

typedef long long ll ;

int main(){
    ll t ;
    cin >> t ;
    while(t--){
        ll n, m ;
        cin >> n >> m ;
        ll a[n][m] ;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                cin >> a[i][j] ;
            }
        }
        ll k,count = 0 ;
        for(ll i=1; i<n-1; i++){
            for(ll j=1; j<m-1; j++){
                k = min(i,min(j,min(n-1-i,m-i-j))) ;
                while(k){
                    if(a[i-k][j] == a[i+k][j] && a[i][j-k] == a[i][j+k]){
                        count += k ;
                        break ;
                    }
                    else {
                        k-- ;
                    }
                }
            }
        }
        count += n*m ;
        cout << count  << endl ;
    }
}