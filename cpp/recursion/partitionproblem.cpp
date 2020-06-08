#include<iostream>
#include<vector>
using namespace std ;

vector<int> v1,v2,v3,v4 ;
int flag = 1, d, g=0 ;
void print(vector<int> v1, vector<int> v2){
    g++ ;
    if(flag){
        cout <<"[" ;
        flag = !flag;
    }
    for(int i=0; i<v1.size(); i++){
        cout << v1[i]<<" " ;
    }
    cout << "and " ;
    for(int i=0; i<v2.size(); i++){
        cout << v2[i]<<" " ;
    }
    if(g!=d){
        cout <<", " ;
    }
    else {
        cout <<"]\n" ;
    }
}

int func1(int a[], int n, int sum1, int sum2, int pos){
    if(pos == n ){
        if(sum1 == sum2){
            return 1 ;
        }
        return 0;
    }
    int count = 0 ;
    count += func1(a,n,sum1+a[pos],sum2,pos+1) ;
    count += func1(a,n,sum1,sum2+a[pos],pos+1) ;
    return count ;
}

void partition(int a[], int n,int sum1, int sum2, int pos){
    if(pos == n ){
        if(sum1 == sum2){
            print(v1,v2);
        }
        return ;
    }
    v1.push_back(a[pos]) ;
    partition(a,n,sum1+a[pos],sum2,pos+1) ;
    v1.pop_back();
    v2.push_back(a[pos]) ;
    partition(a,n,sum1,sum2+a[pos],pos+1) ;
    v2.pop_back() ;
}

void partition2(int a[], int n,int sum1, int sum2, int pos){
    if(pos == n ){
        if(sum1 == sum2){
            for(int i=0; i<v3.size(); i++){
                cout << v3[i]<<" ";
            }
            cout <<"\t" ;
            for(int i=0; i<v4.size(); i++){
                cout << v4[i]<<" ";
            }
            cout << endl ;
        }
        return ;
    }
    v3.push_back(a[pos]) ;
    partition2(a,n,sum1+a[pos],sum2,pos+1) ;
    v3.pop_back();
    v4.push_back(a[pos]) ;
    partition2(a,n,sum1,sum2+a[pos],pos+1) ;
    v4.pop_back() ;
}

int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    d = func1(a,n,0,0,0) ;
    cout << d << endl ;
    partition(a,n,0,0,0);
    partition2(a,n,0,0,0) ;
}