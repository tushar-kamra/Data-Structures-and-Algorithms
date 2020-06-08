#include<iostream>
#include<climits>
using namespace std ;

int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    int path[n] ;
    int res[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
        res[i] = INT_MAX ;
    }
    path[0] = -1 ;
    res[0] = 0 ;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(i <= j+a[j]){
                if(res[i] > res[j]+1){
                    res[i] = res[j]+1 ;
                    path[i] = j ;
                }
            }
        }
    }
    cout << "Jump array : \n" ;
    for(int i=0; i<n; i++){
        cout << res[i] <<" " ;
    }
    cout << "Path array : \n" ;
    for(int i=0; i<n; i++){
        cout << path[i] <<" " ;
    }
}