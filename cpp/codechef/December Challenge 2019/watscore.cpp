#include<iostream>
#include<unordered_map>

using namespace std ;

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int t ;
    cin >> t ;
    while(t--){
        unordered_map<int, int> m ;
        int n, sum = 0 ;
        cin >> n ;
        for(int i=0; i<n; i++){
            int a, b ;
            cin >> a >> b ;
            if(a <= 8){
                if(m.find(a)!=m.end()){
                    if(m[a] < b){
                        m[a] = b ;
                    }
                }
                else {
                    m[a] = b ;
                }
            }
        }
        for(auto it=m.begin(); it!=m.end(); it++){
            sum += it->second ;
        }
        cout << sum << endl ;
    }
}