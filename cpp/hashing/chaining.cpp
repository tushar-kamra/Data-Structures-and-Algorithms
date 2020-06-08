#include<iostream>
using namespace std ;

struct Node {
    int data ;
    Node* next ;
} *save;

Node* createNode(int x){
    Node* temp = new Node() ;
    temp->data = x ;
    temp->next = NULL ;
    return temp ;
}

Node* insert(Node* root, int x){
    Node* temp = root ;
    if(root == NULL){
        root = createNode(x) ;
        return root ;
    }
    while(temp->next != NULL){
        temp = temp->next ;
    }
    temp->next = createNode(x) ;
    return root ;
}

void print(Node* root){
    while(root!= NULL){
        cout << root->data <<" " ;
        root = root->next ;
        if(root == NULL) cout << endl ;
    }
}

int main(){
    int n, m ;
    cout << "Enter number of keys : " ;
    cin >> n ;
    cout << "Enter number of slots : " ;
    cin >> m ;
    cout << "Loading factor = " << n/m << endl ;
    Node **arr ;
    int e ;
    arr = new Node *[m] ;
    for(int i=0; i<m; i++){
        arr[i] = NULL ;
    }
    for(int i=0 ; i<n; i++){
        cin >> e ;
        arr[e%m] = insert(arr[e%m],e) ;
    }
    for(int i=0; i<m; i++){
        print(arr[i]) ;
    }
}