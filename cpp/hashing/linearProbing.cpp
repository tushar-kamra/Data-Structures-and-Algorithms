#include<iostream>
using namespace std ;

int hashing(int key, int m){
    return key%m ;
}

int linearProbe(int a[], int key, int m){
    int index = hashing(key,m) ;
    int i = 0;
    while(a[(index+i)%m] != 0){
        i++ ;
    }
    return (index+i)%m ;
}

void insert(int a[], int key, int m){
    int index = hashing(key,m) ;
    if(a[index]!=0){
        index = linearProbe(a,key,m) ;
    }
    a[index] = key ;
}

void print(int a[], int m){
    for(int i=0; i<m; i++){
        cout << a[i] << " " ;
    }
}

int main(){
    int n,m,key ;
    cin >> n >> m ;
    int a[m] = {} ;
    for(int i=0; i<n; i++){
        cin >> key ;
        insert(a,key,m) ;
    }
    print(a,m) ;
}