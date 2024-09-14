#include <iostream>

using namespace std;
//attributes of node stored here
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {} //inline construct
};

TreeNode* invertBST(TreeNode* root) { //takes in root

    //base case
    if(!root) return nullptr;

    //basic swap
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    //invert recursively both sides
    invertBST(root->left);
    invertBST(root->right);

    return root; //return new bST

}

//for visual purposes to see new tree
void inorderPrint(TreeNode* root) {
    //in order logic for bst, standard
    if(root) {
        inorderPrint(root->left);
        cout << root->val << " ";
        inorderPrint(root->right);
    }
}

int main() {
    //add data to tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(3);

    cout << "Original Inorder BST: ";
    inorderPrint(root);
    cout << endl;
    
    invertBST(root); //pass in the tree and invert it

    cout << "Inverted Inorder BST: ";
    inorderPrint(root);
    cout << endl;

    return 0;
}