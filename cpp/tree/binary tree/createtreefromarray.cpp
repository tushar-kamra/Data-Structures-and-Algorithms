#include<iostream>
using namespace std ;

class Node {
    public :
        int data ;
        Node* left ;
        Node* right ;
    
        Node* createNode(int x){
            Node* temp = new Node ;
            temp->data = x ;
            temp->left = NULL ;
            temp->right = NULL ;
            return temp ;
        }

        Node* createBT(int a[],int l, int r, Node* root){
            if(root == NULL){
                if(a[l] == -1) return NULL ;
                root = createNode(a[l]);
            }
            if(2*l+1 <= r){
                root->left = createBT(a,2*l+1,r,root->left) ;
            }
            if(2*l+2 <= r){
                root->right = createBT(a,2*l+2,r,root->right) ;
            }
            return root ;
        }

        void print(Node* root){
            if(root == NULL){
                return ;
            }
            cout << root->data <<" " ;
            print(root->left);
            print(root->right);
        }
};

int main(){
    int n ;
    cin >> n ;
    Node* root = NULL ;
    Node obj ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    root = obj.createBT(a,0,n-1,root) ;
    obj.print(root);
}