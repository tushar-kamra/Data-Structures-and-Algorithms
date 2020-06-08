#include<iostream>
#include<vector>

using namespace std ;

vector<string> coinchange(vector<int> denom, int amount, int idx){
    if(amount == 0){
        vector<string> temp ;
        temp.push_back("") ;
        return temp ;
    }
    if(amount < 0){
        vector<string> temp ;
        return temp ;
    }
    vector<string> myAns ;
    for(int i=idx; i<denom.size(); i++){
        vector<string> recAns = coinchange(denom,amount-denom[i],i) ;
        for(string s : recAns){
            myAns.push_back(to_string(denom[i])+s) ;
        }
    }
    return myAns ;
}

int main(){
    int n, amount ;
    cin >> n >> amount ;
    vector<int> denom(n);
    for(int i=0; i<n; i++){
        cin >> denom[i] ;
    }
    vector<string> ans = coinchange(denom,amount,0) ;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << endl ;
    }
}