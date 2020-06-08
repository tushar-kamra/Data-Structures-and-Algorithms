#include <iostream>
using namespace std;

int main() {
	int t ;
	cin >> t ;
	while(t--){
	    int n,m ;
	    cin >> n >> m ;
	    int a[n], b[m], sum1=0, sum2=0, i=0,j=0, ans = 0 ;
	    for(int i=0; i<n; i++){
	        cin >> a[i] ;
	    }
	    for(int i=0; i<m; i++){
	        cin >> b[i] ;
	    }
	    while(i<n && j<m){
            if(a[i] < b[j]){
                sum1 += a[i] ;
                i++ ;
            }
            else if(b[j] < a[i]){
                sum2 += b[j] ;
                j++ ;
            }
            else {
                ans += max(sum1,sum2) + a[i] ;
                int temp = a[i] ;
                i++ ;
                j++ ;
                while(i<n && temp == a[i]){
                    ans += a[i] ;
                    i++ ;
                }
                while(j<m && temp == b[j]){
                    ans += b[j] ;
                    j++ ;
                }
                sum1 = 0 ;
                sum2 = 0 ;
            }
        }
        while(i <n){
            sum1 += a[i] ;
            i++ ;
        }
        while(j < m){
            sum2 += b[j];
            j++ ;
        }
	    ans += max(sum1,sum2) ;
        cout << ans << endl ;
	}
	return 0;
}