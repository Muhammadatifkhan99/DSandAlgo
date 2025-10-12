#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

struct Node{
    int data;

    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }

    void preOrder(Node *root){
        if(root == NULL) return;

        cout << root->data << "->";
        preOrder(root->left);
        preOrder(root->right);

    }

    void inOrder(Node *root){
        if(root == NULL) return;

        preOrder(root->left);
        cout << root->data << "->";
        preOrder(root->right);

    }

    void postOrder(Node *root){
        if(root == NULL) return;

        preOrder(root->left);
        preOrder(root->right);
        cout << root->data << "->";

    }

    //BFS Traversal

    vector<vector<int>> levelOrder(Node *root){
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i{0};i<size;i++){
                Node* root = q.front();
                q.pop();
                if(root->left != NULL) q.push(root->left);
                if(root->right != NULL) q.push(root->right);
                level.push_back(root->data);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

class Node1{
public:
    int data;

    Node1 *left1;
    Node1 *right1;

    Node1(int val){
        data = val;
        left1 = right1 = NULL;
    }

    void preOrder(Node1 *root){
    if(root == NULL) return;

    cout << root->data << endl;
    preOrder(root->left1);
    preOrder(root->right1);

}

    // void preOrder(Node1 node){
    //     if(node == NULL) return;

    // }
};

int main(){

    //###################################################################
    cout<<"Play ground is up and running" << endl;
    //###################################################################

    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    root->preOrder(root);
    cout << endl;
    root->inOrder(root);
    cout << endl;
    root->postOrder(root);
    root->levelOrder(root);


    Node1 *root1 = new Node1(1);

    root1->left1 = new Node1(2);
    root1->right1 = new Node1(3);
    root1->left1->right1 = new Node1(5);

    // vector<int> ans = {2,3,6,7,9};
    // vector<int> ans1 = {1,4,8,10};
    // cout << median(ans,ans1,4) << endl;
    return 0;
}