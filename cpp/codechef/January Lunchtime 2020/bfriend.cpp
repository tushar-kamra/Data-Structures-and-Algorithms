#include <iostream>
#include <climits>
using namespace std;

typedef long long ll ;

int main() {
	ll t ;
	cin >> t ;
	while(t--){
	    ll n,a,b,c, mini = LLONG_MAX ;
	    int flag = 0 ;
	    cin >> n >> a >> b >> c ;
	    ll f[n] ;
	    for(ll i=0; i<n; i++){
	        cin >> f[i] ;
	    }
	    for(ll i=0; i<n; i++){
	        if(a < b){
	            if(a < f[i]  && f[i] < b){
	                cout << b-a+c << endl ;
	                flag = 1 ;
	                break ;
	            }
	            else if(f[i] > b){
	                mini = min(mini,(f[i]-b+f[i]-a+c)) ;
	            }
	            else {
	                mini = min(mini,(b-f[i]+a-f[i]+c)) ;
	            }
	        }
	        else {
	            if(b < f[i] && f[i] < a){
	                cout << a-b+c << endl ;
	                flag = 1 ;
	                break ;
	            }
	            else if(f[i] > a){
	                mini = min(mini,(f[i]-b+f[i]-a+c)) ;
	            }
	            else {
	                mini = min(mini,(b-f[i]+a-f[i]+c)) ;
	            }
	        }
	    }
	    if(!flag){
	        cout << mini << endl ;
	    }
	    
	}
	return 0;
}
