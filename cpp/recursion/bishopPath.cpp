// #include<iostream>
// #include<vector>
// #include<utility>

// using namespace std ;

// void print(vector<pair<int,int>> v){
//     for(int i=0; i<v.size(); i++){
//         cout << v[i].first <<" " << v[i].second << endl ;
//     }
// }

// bool canMove(int r, int c){
//     if(r>=0 && r<8 && c>=0 && c<8) return true;
//     return false ;
// }

// void bishopPath(vector<pair<int,int>> &v, int r, int c){
//     if(r == 7 && c == 7){
//         v.push_back({8,8}) ;
//         return ;
//     }
//     v.push_back({r+1,c+1}) ;
//     for(int i=7; i>=0; i--){
//         if(canMove(r+i,c-i)){
//             v.push_back({r+i+1,c-i+1});
//             v.push_back({c-i+1,r+i+1});
//             v.push_back({r+1,c+1});
//             break ;
//         }
//     }
//     bishopPath(v,r+1,c+1) ;
// }
  

// int main(){
//     int t ;
//     cin >> t ;
//     while(t--){
//         int r,c ;
//         cin >> r >> c ;
//         vector<pair<int,int>> v ;
//         if(r!=1 && c!=1 && r!=c){
//             int mid = (r+c)/2 ;
//             v.push_back({mid,mid}) ;
//             v.push_back({1,1}) ;
//         }
//         if(r!=1 && c!=1 && r == c){
//             v.push_back({1,1}) ;
//         }
//         bishopPath(v,1,1) ;
//         cout << v.size() << endl ;
//         print(v) ;
//     }
// }

#include<iostream>
#include<vector>
#include<utility>

using namespace std ;

void print(vector<pair<int,int>> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i].first <<" " << v[i].second << endl ;
    }
}

bool canMove(int r, int c){
    if(r>=0 && r<8 && c>=0 && c<8) return true;
    return false ;
}

void bishopPath(vector<pair<int,int>> &v, int r, int c){
    if(r == 4 && c == 4){
        v.push_back({8,8}) ;
        return ;
    }
    v.push_back({r+1,c+1}) ;
    for(int i=7; i>=0; i--){
        if(canMove(r+i,c-i)){
            v.push_back({r+i+1,c-i+1});
            for(int j=7; j>=0; j--){
                if(canMove(r+i+j,c-i+j)){
                    v.push_back({r+i+j+1,c-i+j+1});
                    v.push_back({c-i+j+1,r+i+j+1});
                    break ;
                }
            }
            v.push_back({c-i+1,r+i+1});
            v.push_back({r+1,c+1});
            break ;
        }
    }
    bishopPath(v,r+1,c+1) ;
}
  

int main(){
    int t ;
    cin >> t ;
    while(t--){
        int r,c ;
        cin >> r >> c ;
        vector<pair<int,int>> v ;
        if(r!=c){
            int mid = (r+c)/2 ;
            v.push_back({mid,mid}) ;
            v.push_back({1,1}) ;
        }
        if(r!=1 && c!=1 && r == c){
            v.push_back({1,1}) ;
        }
        bishopPath(v,1,1) ;
        cout << v.size() << endl ;
        print(v) ;
    }
}