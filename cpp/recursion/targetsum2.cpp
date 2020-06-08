#include<iostream>
using namespace std ;

void targetsum(int a[], int idx, int target, string ans, int n){
    if(idx == n || target == 0){
        if(target == 0){
            cout << ans << endl ;
        }
        return ;
    }
    for(int i=idx; i<n; i++){
        if(target-a[i] >= 0){
            targetsum(a,i+1,target-a[i],ans+to_string(a[i]),n) ;
        }
    }
}

int main(){
    int n, target ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    cin >> target ;
    targetsum(a,0,target,"",n) ;
}