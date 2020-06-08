#include<iostream>
#include<stack>
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

void printStack(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop() ;
    }
}

void printVector(vector<int> v, int j){
    for(int i=j; i<v.size(); i++){
        cout << v[i] << " " ;
    }
    cout << endl ;
}

void kSumPathUtil(Node* root, vector<int>& v, int k){
    if(root == NULL) return ;
    v.push_back(root->data) ;
    kSumPathUtil(root->left,v,k) ;
    kSumPathUtil(root->right,v,k) ;
    int sum = 0 ;
    for(int i = v.size()-1; i>=0; i--){
        sum += v[i] ;
        if(sum == k){
            printVector(v,i) ;
            break ;
        }
    }
    v.pop_back() ;
}

void kSumPath(Node* root, int k){
    vector<int> v ;
    kSumPathUtil(root,v,k) ;
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
    root = insertNode(root,15);
    root = insertNode(root,25);
    root = insertNode(root,27);
    root = insertNode(root,3);
    root = insertNode(root,17);

    stack<int> s ;
    int k ;
    cin >> k ;
    kSumPath(root,k) ;
}