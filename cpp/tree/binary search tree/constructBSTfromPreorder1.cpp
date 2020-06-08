#include<iostream>
#include<climits>
using namespace std ;

struct Node {
    int data ;
    Node* left ;
    Node* right ;
};

Node* createNode(int x){
    Node* temp = new Node() ;
    temp->data = x ;
    temp->left = NULL ;
    temp->right = NULL ;
    return temp ;
}

Node* constructBST(int a[], int n,int* preidx,int min,int max, int key){
    if(*preidx >= n){
        return NULL ;
    }
    Node* root = NULL ;
    if(key > min && key < max){
        root = createNode(key) ;
        *preidx += 1 ;
        if(*preidx < n){
            root->left = constructBST(a,n,preidx,min,key,a[*preidx]) ;
            root->right = constructBST(a,n,preidx,key,max,a[*preidx]) ;
        }
    }
    return root ;
}

void inorder(Node* root){
    if(root == NULL) return ;
    cout << root->data <<" " ;
    inorder(root->left);
    inorder(root->right) ;
}

int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    int preidx = 0 ;
    Node* root = constructBST(a,n,&preidx,INT_MIN,INT_MAX,a[0]) ;
    inorder(root) ;
}