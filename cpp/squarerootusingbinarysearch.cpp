#include<iostream>
#include<iomanip>
using namespace std ;

void sqrt(int n, int k){
    int l = 0, r = n ;
    double ans ;
    while(l<=r){
        int mid = (l+r)/2 ;
        if(mid*mid == n){
            ans = mid ;
            break ;
        }
        else if(mid*mid < n){
            l = mid+1 ;
            ans = mid ;
        }
        else {
            r = mid-1 ;
        }
    }
    cout << ans << " " ;
    double inc = 0.1 ;
    for(int i=0; i<k; i++){
        while(ans*ans <= n) {
            ans += inc ;
        }
        ans -= inc ;
        inc = inc/10 ;
    }
    cout << fixed << setprecision(k) << ans ;
}

int main(){
    int n, k ;
    cin >> n >> k ;
    sqrt(n,k) ;
}