#include <iostream>

struct Node;
struct BST;


int main(){

}

struct Node {
	Node *left;
	Node *right
	int val;
}

struct Tree {
	Node *root;
	int numberofVals;
}



void PreOrder(Node *root){
	std::cout << root->val << " ";
	if(root->left != none){PreOrder(root->left);}
	if(root->right != none){PreOrder(root->right);}
}

// post order is when we go from the ground up
void PostOrder(Node * root){
	if(root->left != none){PostOrder(root->left);}
	if(root->right != none){PostOrder(root->right);}
	std::cout << root->val << "\n";
}

// takes the values after the last structure from left to right has been read
void inOrder(Node *root){
	if(root->left != none){inOrder(root->left);}
	std::cout << root->val << "\n";
	if(root->right != none){inOrder(root->right)}
}

