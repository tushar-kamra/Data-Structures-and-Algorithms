#include<iostream>
#include<queue>
#include<map>
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

Node* insertNode(Node* root, int x){
    if(root == NULL){
        root = createNode(x) ;
        return root ;
    }
    queue<Node*> q ;
    q.push(root) ;
    while(!q.empty()){
        Node* temp = q.front() ;
        q.pop() ;
        if(!temp->left){
            temp->left = createNode(x) ;
            break ;
        }
        else {
            q.push(temp->left) ;
        }
        if(!temp->right){
            temp->right = createNode(x) ;
            break ;
        }
        else {
            q.push(temp->right) ;
        }
    }
    return root ;
}



void bt2dll(Node* root, Node** head){
    queue<Node*> q ;
    Node* prev = NULL ;
    q.push(root) ;
    while(!q.empty()){
        root = q.front() ;
        Node* temp = createNode(root->data) ;
        q.pop() ;
        if(*head == NULL){
            *head = temp ;
        }
        else {
            temp->left = prev ;
            prev->right = temp ;
        }
        prev = temp ;
        if(root->left) q.push(root->left) ;
        if(root->right) q.push(root->right) ;
    }
}

void print(Node* root){
    Node* temp ;
    while(root!=NULL){
        cout << root->data <<" " ;
        if(root->right == NULL){
            temp = root ;
        }
        root = root->right ;
    }
    cout << endl ;
    while(temp!=NULL){
        cout << temp->data <<" " ;
        temp = temp->left ;
    }
}

void preorder(Node* root){
    if(root == NULL) return ;
    cout << root->data <<" " ;
    preorder(root->left) ;
    preorder(root->right) ;
}

int main(){
    Node* root = NULL ;
    root = insertNode(root,2);
    root = insertNode(root,4);
    root = insertNode(root,1);
    root = insertNode(root,8);
    root = insertNode(root,6);
    root = insertNode(root,5);
    root = insertNode(root,7);
    root = insertNode(root,9);
    root = insertNode(root,11);
    root = insertNode(root,16);
    root = insertNode(root,25);
    root = insertNode(root,27);
    root = insertNode(root,3);
    root = insertNode(root,17);
    Node* head = NULL ;
    preorder(root);
    cout << endl ;
    bt2dll(root,&head) ;
    print(head) ;
    cout<<endl ;
    preorder(root);
    cout << endl ;
}