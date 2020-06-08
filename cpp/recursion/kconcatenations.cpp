#include<iostream>
#include<vector>
using namespace std ;

int kadane(vector<int> v){
    int csum = 0, fsum = 0 ;
    for(int i=0; i<v.size(); i++){
        csum += v[i] ;
        if(fsum < csum){
            fsum = csum ;
        }
        if(csum < 0){
            csum = 0 ;
        }
    }
    return fsum ;
}

int main(){
    int t ;
    cin >> t ;
    while(t--){
        int n, k ;
        cin >> n >> k ;
        vector<int> v(n,0) ;
        int a[n], tsum = 0 ;
        for(int i=0; i<n; i++){
            cin >> v[i] ;
            tsum += a[i] ;
        }
        int osum = kadane(v) ;
        if(k == 1){
            cout << osum << endl ;
            continue ;
        }
        for(int i=0; i<n; i++){
            v.push_back(v[i]) ;
        }
        int dsum = kadane(v) ;
        if(tsum > 0){
            dsum += (k-2)*tsum ;
        }
        cout << dsum << endl ;
    }
}