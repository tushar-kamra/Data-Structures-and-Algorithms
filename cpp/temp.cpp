#include<iostream>
#include<climits>
using namespace std ;

int main(){
	int t ;
	cin >> t ;
	while(t--){
		int n, m ;
		cin >> n >> m ;
		int f[n+1]={0}, p[n+1]={0}, a[m+1]={0}, ans = INT_MAX ;
		for(int i=1; i<=n; i++){
			cin >> f[i] ;
		}
		for(int i=1; i<=n; i++){
			cin >> p[i] ;
		}
		for(int i=1; i<=n; i++){
			a[f[i]] += p[i] ;
		}
		for(int i=1; i<=m; i++){
			if(a[i] && a[i] < ans ){
				ans = a[i] ;
			}
		}
		if(ans == INT_MAX){
			cout << 0 << endl ;
		}
		else {
			cout << ans << endl ;
		}
	}
}