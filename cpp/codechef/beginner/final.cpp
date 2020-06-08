#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define MOD 1000000007

ll power(ll a, ll b){
    if(b == 0){
        return 1 ;
    }
    else if(b%2 == 0){
        return ((power(a,b/2)%MOD)*(power(a,b/2)%MOD))%MOD ;
    }
    else {
        return (a*((power(a,b/2)%MOD)*(power(a,b/2)%MOD))%MOD)%MOD ;
    }
}

int main(){
    int t ;
    cin >> t ;
    while(t--){
        ll n, a,  ans = 0 ;
        cin >> n >> a ;
        ans = a ;
        if(n == 1){
            cout << ans%MOD << "\n" ;
        }
        else {
            for(int j=1; j<=n; j+=2){
                cout << "z";
                ll x = power(2,j) ;
                ll y = j+2 ;
                ll z = (x*y)%MOD ;
                ans = (ans + power(a,z))%MOD ;
            }
            cout << ans%MOD << "\n" ;
        }
        
    }
}