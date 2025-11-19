//Q1
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

class bst{
    public:
    void preorder(Node *root){
        if(root!=NULL){
            cout<<root->data;
            preorder(root->left);
            preorder(root->right);
        }
    }

     void inorder(Node *root){
        if(root!=NULL){
            inorder(root->left);
            cout<<root->data;
            inorder(root->right);
        }
    }

     void postorder(Node *root){
        if(root!=NULL){
            postorder(root->left);
            postorder(root->right);
            cout<<root->data;
         }
    }


};

int main(){
    //creating a tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    bst bt;

    cout << "Pre-order Traversal: ";
    bt.preorder(root);
    cout << endl;

    cout << "In-order Traversal: ";
    bt.inorder(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    bt.postorder(root);
    cout << endl;

    return 0;
}

//Q2
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

class bst{
   //(a) searching element
   //(i) Non iterative
    Node* searchni(Node *root, int key){
        if(root == NULL || root->data == key){
            return  root;
        }
        if (key< root->data){
            return searchni(root->left,key);
        }
        else{
            return searchni(root->right,key);
        }
    }

    //(ii) Iterative
    Node* searchi(Node * root, int key){
        while(root!=NULL && key != root->data){
            if(key<root->data){
                root= root->left;
            }
            else{
                root= root->right;
            }
            return root;
        }
        return NULL;
    }

    //(b)  min element
    Node* minelement(Node*root){
        while(root->left!=NULL){
            root=root->left;
            return root;
        }
    }

    //(c)max element
    Node* maxelement(Node*root){
        while(root->right!=NULL){
            root=root->right;
            return root;
        }
    }
     
    //(d) inorder successor

    Node* insuc(Node *root, Node *target){
        Node* successor = NULL;
        while(root!=NULL){
            if(target->data < root->data){
                successor=root;
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
        return successor;
    }

    //(e) inorder predecessor 
    Node * inpre(Node *root, Node *target){
        Node* predecessor = NULL;
        while(root!=NULL){
            if(target->data > root -> data){
                predecessor=root;
                root=root->right;
            }
            else{
                root= root->left;
            }
        }
        return predecessor;
    }

};

//Q3
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

class bst{

    //(a) insert an element 
     Node* insert(Node* root, int key) {
        if (root == NULL) {
            return new Node(key);   // Insert first node
        }

        if (key < root->data) {
            root->left = insert(root->left, key);
        }
        else if (key > root->data) {
            root->right = insert(root->right, key);
        }
        else {
            cout << "Duplicate not allowed: " << key << endl;
        }

        return root;
    }

    //(b) delete an element
    Node* deleteNode(Node* root, int key) {
        if (root == NULL) {
            cout << "Element not found.\n";
            return root;
        }

        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Case 1: No child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: One child
            else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Two children
            Node* temp = minelement(root->right); 
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }

    //(c) max depth of bst (height)
     int maxDepth(Node* root) {
        if (root == NULL) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }

    //(d) min depth of bst
     int minDepth(Node* root) {
        if (root == NULL) return 0;

        
        if (root->left == NULL)
            return 1 + minDepth(root->right);

        if (root->right == NULL)
            return 1 + minDepth(root->left);

        
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

//Q4
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Tree {
public:
    Node* prev = NULL;   // will store previous node in inorder traversal

    // Inorder BST checker
    bool isBST(Node* root) {
        if (root == NULL)
            return true;

        // Check left subtree
        if (!isBST(root->left))
            return false;

        // Compare current node with previous visited node
        if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;  // update previous node

        // Check right subtree
        return isBST(root->right);
    }
};

//--------------ADDITIONAL QUES--------------------------//

//Q1
include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Tree {
public:
 
    bool isLeaf(Node* node) {
        return (node != NULL && node->left == NULL && node->right == NULL);
    }

   
    int sumOfLeaves(Node* root) {
        if (root == NULL)
            return 0;

        int sum = 0;

        // If left child is a leaf, add it
        if (isLeaf(root->left))
            sum += root->left->data;

        // Recur for left and right subtrees
        return sum + sumOfLeaves(root->left) + sumOfLeaves(root->right);
    }
};



