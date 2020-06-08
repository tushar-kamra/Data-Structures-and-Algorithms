// #include<iostream>
// using namespace std;

// typedef long long ll ;

// int main(){
//     int t ;
//     cin >> t ;
//     while(t--){
//         ll n, sum = 0, ans = 0 ;
//         cin >> n ;
//         ll a[n] ;
//         for(ll i=0; i<n; i++){
//             cin >> a[i];
//             sum += a[i] ; 
//         }
//         ll subsum = 0 ;
//         for(ll i=0; i<n; i++){
//             if((sum-a[i])%2 == 0){
//                 for(int j=0; j<n; j++){
//                     if(j!=i){
//                         subsum += a[j] ;
//                     }
//                     if(subsum == (sum-a[i])/2){
//                         ans++ ;
//                     }
//                     if(subsum > (sum-a[i])/2){
//                         break ;
//                     }
//                 }
//             }
//         }
//         cout<<ans<<endl ;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a[mxN];

void solve() {
	cin >> n;
	ll ts=0;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		ts+=a[i];
	}
	unordered_map<ll, int> mp;
	ll ans=0, s=0;
	for(int i=0; i<n; ++i) {
		if((ts-a[i])%2==0) {
			ll ps=(ts-a[i])/2;
			ans+=mp[ps];
		}
		s+=a[i];
		++mp[s];
	}
	mp.clear();
	s=0;
	for(int i=n-1; ~i; --i) {
		if((ts-a[i])%2==0) {
			ll ps=(ts-a[i])/2;
			ans+=mp[ps];
		}
		s+=a[i];
		++mp[s];
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}
