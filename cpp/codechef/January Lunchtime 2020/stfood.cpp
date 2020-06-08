#include<iostream>
#include <climits>
using namespace std ;

typedef long long ll ;

int main(){
    ll t ;
    cin >> t ;
    while(t--){
        ll ans = LLONG_MIN ;
        ll n ;
        cin >> n ;
        while(n--){
            ll s,p,v ;
            cin >> s >> p >> v ;
            s++ ;
            ans = max(ans,(p/s)*v) ;
        }
        cout << ans << endl ;
    }
}