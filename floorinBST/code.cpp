#include<iostream>
#include<vector>


using namespace std;


class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node (int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left,val);
    } else {
        root->right = insert(root->right,val);
    }
    return root;
}

Node* buildBST(vector<int> arr){
    Node* root = NULL;

    for(int val: arr){
        root= insert(root,val);
    }
    return root;
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

///searching in BST

Node* searchBST(Node* root, int val){
    while(root != NULL && root->data != val){
        root = val < root->data ? root->left : root ->right;
    }
    cout << root->data<<endl;
    return root;
}

bool searchBSTRec(Node* root,int key){
    if(root == NULL) return false;
    if(root->data == key) return true;

    if(key > root->data){
        return searchBSTRec(root->right,key);
    } else return searchBSTRec(root->left,key);
}

//deleting a node in BST

Node* findLastRight(Node* root){
    if(root->right == NULL){
        return root;
    }
    return findLastRight(root->right);
}

Node* helper(Node* root){
    if(root == NULL) return NULL;
    if(root->left == NULL) return root->right;
    else if (root->right == NULL) return root->left;

    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

Node* delNode(Node* root,int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return helper(root);
    }
    Node* dummy = root;
    while(root != NULL){
        if(root->data > key){
            if(root->data != NULL && root->left->data == key){
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if(root->data != NULL && root->right->data == key){
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return dummy;
}
//ceil of Binary Tree 

int ceilBinaryTree(Node* root,int key){
    int ceil = -1;
    while(root){
        if(root->data == key){
            ceil = root->data;
            return ceil;
        }
        if(key > root->data){
            root = root->left;
        } else {
            ceil = root->data;
            root = root->right;
        }
    }
    return ceil;
}

//floor of Binary Tree
int floorBinaryTree(Node* root,int key){
    int floor = -1;
    while(root){
        if(root->data == key){
            floor = root->data;
            return floor;
        }
        if(key > root->data){
            floor = root->data;
            root =root->left;
        } else {
            root =root->right;
        }
    }
    return floor;
}


int main(){
    vector<int> arr = {3,2,1,5,6,4};
    Node* root = buildBST(arr);

    inOrder(root);
    cout << endl;

    Node* node = searchBST(root,5);
    if(node) cout << node->data << endl;
    else cout << "Key not found" << endl;

    // Node* node2 = searchBSTRec(root,5);
    // if(node2) cout << node2->data << endl;
    // else cout << "Key not found" << endl;

    cout << "Ceil and Floor of BST" << endl;
    cout << ceilBinaryTree(root,3) << endl;
    cout << floorBinaryTree(root,3) << endl;

    return 0;
}