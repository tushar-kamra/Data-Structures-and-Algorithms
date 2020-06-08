#include<iostream>
using namespace std ;

int main(){
    int n ;
    cin >> n ;
    int k=0 ;
    for(int i=1; i<=n; i++){
        (i<=(n+1)/2)?k++:k-- ;
        for(int j=1; j<=n; j++){
            if(j<=k || j>=n-k+1){
                cout<<"*" ;
            }
            else {
                cout<<" " ;
            }
        }
        cout<<endl ;
    }
    
}