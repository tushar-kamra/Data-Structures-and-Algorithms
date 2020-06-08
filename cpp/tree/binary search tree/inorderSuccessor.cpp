#include<iostream>
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

Node* insertion(Node*& root, int x){
    if(root == NULL){
        root = createNode(x) ;
        return root ;
    }
    else if(x <= root->data){
        root->left = insertion(root->left,x) ;
    }
    else{
        root->right = insertion(root->right,x) ;
    }
    return root ;
}

Node* findNode(Node* root, int x){
    if(root == NULL){
        return NULL ;
    }
    if(root->data == x){
        return root ;
    }
    else if(root->data > x){
        return findNode(root->left,x) ;
    }
    return findNode(root->right,x) ;
}

int inorderSuccessor(Node* root, Node* temp){
    if(temp == NULL){
        return 0;
    }
    else if(temp->right){
        temp = temp->right ;
        while(temp->left != NULL){
            temp = temp->left ;
        }
        return temp->data ;
    }
    else {
        Node* store = NULL ;
        while(root->data != temp->data){
            if(root->data > temp->data){
                store = root ;
                root = root->left ;
            }
            else {
                root = root->right ;
            }
        }
        if(store) return store->data ;
    }
    return 0 ;
}

void inorder(Node* root){
    if(root == NULL) return ;
    inorder(root->left) ;
    cout << root->data <<" " ;
    inorder(root->right) ;
}

int main(){
    Node* root = NULL ;
    insertion(root,6) ;
    insertion(root,4) ;
    insertion(root,1) ;
    insertion(root,3) ;
    insertion(root,2) ;
    insertion(root,7) ;
    insertion(root,5) ;
    insertion(root,11) ;
    insertion(root,13) ;
    insertion(root,9) ;
    cout << "Indorder : " ;
    inorder(root) ;
    cout << endl ;
    int n ;
    cin >> n ;
    Node* temp = findNode(root,n) ;
    int ans = inorderSuccessor(root,temp) ;
    if(ans){
        cout << "Inorder Successor of "<<n<<" is "<<ans ;
    }
    else {
        cout << "Not found !" ;
    }
}