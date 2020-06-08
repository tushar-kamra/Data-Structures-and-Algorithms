#include<iostream>
using namespace std ;

int main(){
    string s ;
    cin >> s ;
    int a[256]={} ;
    for(int i=0; i<s.length(); i++){
        a[s[i]]++ ;
    }
    int max1 = 0, max2 = 0 ;
    char ch ;
    for(int i=0; i<256; i++){
        if(a[i]>a[max1]){
            max2 = max1 ;
            max1 = i ;
        }
        else if(a[i]>a[max2] && a[i] != a[max1]){
            max2 = i ;
        }
    }
    cout << max1 <<" "<<max2<<endl ;
    ch = NULL+max2 ;
    cout << ch ;
}