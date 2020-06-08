#include<iostream>
using namespace std ;

int main(){
    int n ;
    cin >> n ;
    for(int i=1; i<=3*n; i++){
        for(int j=1; j<=2*n-1; j++){
            if(i<=n){
                if(j>=2*n-i){
                    cout<<"*" ;
                }
                else {
                    cout<<" " ;
                }
            }
            else if(i<=2*n){
                if(j==n){
                    cout<<"|" ;
                }
                else if(j>=i || j<=i-n-1){
                    cout<<"*" ;
                }
                else {
                    cout<<" " ;
                }
            }
            else {
                if(j<=3*n-i+1){
                    cout<<"*";
                }
                else {
                    cout<<" " ;
                }
            }
        }
        cout<<endl ;
    }
}