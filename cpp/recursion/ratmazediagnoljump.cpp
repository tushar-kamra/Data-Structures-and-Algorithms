#include<iostream>
#include<vector>
using namespace std ;

vector<string> v ;
void ratmaze(int x1, int y1, int x2, int y2, string ans){
    if(x1 == x2 && y1 == y2){
        v.push_back(ans) ;
        return ;
    }
    for(int jump=1; y1+jump <= y2; jump++){
        if(y1+jump<=y2){
        string temp = "H"+to_string(jump) ;
        ratmaze(x1,y1+jump,x2,y2,ans+temp) ;
        }
    }

    for(int jump=1; x1+jump <= x2 ; jump++){
        if(x1+jump<=x2){
            string temp = "V"+to_string(jump) ;
            ratmaze(x1+jump,y1,x2,y2,ans+temp) ;
        }
    }

    for(int jump=1; x1+jump <= x2 && y1+jump <= y2; jump++){
        if(x1+jump<=x2 && y1+jump<=y2){
            string temp = "D"+to_string(jump) ;
            ratmaze(x1+jump,y1+jump,x2,y2,ans+temp) ;
        }
    }
    
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