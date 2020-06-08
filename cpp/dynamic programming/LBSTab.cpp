// Longest Bitonic Subsequence

#include<iostream>
#include<vector>
using namespace std ;

int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    int lis[n] = {} , lds[n] = {} ;
    vector<string> pathLis,pathLDS ;
    lis[0] = 1 ;
    pathLis[0] = to_string(a[0]) ;
    lds[n-1] = 1 ;
    pathLDS[n-1] = to_string(a[n-1]) ;
    for(int i=0; i<n; i++){
        for(int j=0; j<i ; j++){
            if(a[j] < a[i]){
                if(lis[j] > lis[i]){
                    lis[i] = lis[j] ;
                    pathLis[i] = pathLis[j] +" " ;
                }
            }
        }
        lis[i] +=1 ;
        pathLis[i] += to_string(a[i]) ;
    }
    for(int i=n-2; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(a[j] < a[i]){
                if(lds[j] > lds[i]){
                    lds[i] = lds[j] ;
                    pathLDS[i] = pathLDS[j]+" " ;
                }
            }
        }
        lds[i] += 1 ;
        pathLDS[i] = to_string(a[i]) + pathLDS[i] ;
    }
    int idx, maxi=0 ;
    for(int i=0; i<n; i++){
        if(lis[i]+lds[i]-1 > maxi){
            maxi = lis[i]+lds[i]-1 ;
            idx = i ;
        }
    }
    cout << pathLis[idx]+" "+pathLDS[idx] ;
}