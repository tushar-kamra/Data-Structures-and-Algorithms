#include<iostream>
#include<climits>
#include<stack>
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

Node* constructBst(int pre[], int size){
    stack<Node*> s ;
    Node* root = createNode(pre[0]) ;
    s.push(root) ;
    Node* temp ;
    for(int i=1; i<size; i++){
        temp = NULL ;
        while(!s.empty() && pre[i] > s.top()->data){
            temp = s.top() ;
            s.pop() ;
        }
        if(temp!=NULL){
            temp->right = createNode(pre[i]) ;
            s.push(temp->right) ;
        }
        else{
            s.top()->left = createNode(pre[i]) ;
            s.push(s.top()->left) ;
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
    Node* root = constructBst(a,n) ;
    inorder(root) ;
}