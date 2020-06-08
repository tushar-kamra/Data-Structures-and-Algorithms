#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

int main(){
    int t ;
    cin >> t ;
    while(t--){
        int s ;
        vector<int> v(3) ;
        cin >> s ;
        for(int i=0; i<3; i++){
            cin >> v[i] ;
        }
        int total = 1, sum = 0 ;
        for(int i=0; i<3; i++){
            sum += v[i] ;
            if(sum > s){
                total++ ;
                i-- ;
                sum = 0 ;
            }
        }
        cout << total << endl ;
    }
}