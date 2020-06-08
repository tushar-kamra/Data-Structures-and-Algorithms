#include<iostream>
#include<vector>
using namespace std ;

vector<string> v ;
void ratmaze(int x1, int y1, int x2, int y2, string ans){
    if(x1 == x2 && y1 == y2){
        v.push_back(ans) ;
        return ;
    }
    
    if(y1<y2){
        ratmaze(x1,y1+1,x2,y2,ans+"H") ;
    }
    if(x1<x2){
        ratmaze(x1+1,y1,x2,y2,ans+"V") ;
    }
    
    if(x1<x2 && y1<y2){
        ratmaze(x1+1,y1+1,x2,y2,ans+"D") ;
    }
    
    return ;
}


int main(){
    int m,n ;
    cin >> m >> n ;
    ratmaze(0,0,m-1,n-1,"");
    cout << v.size()<<endl ;
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] <<" " ;
    }
    
}