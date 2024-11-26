
#include <iostream>
#include "Project4.h"
using namespace std;
struct node{
int data;
struct node* left;
struct node* right;
};
struct node* newNode(int data){
struct node* node = new struct node;
node->data = data;
node->left = NULL;
node->right = NULL;
return node;
}
/* 1. If the tree is empty, set rootRef to the address of newly created node
* 2. Otherwise, recur down the tree
*/
void insert(struct node** rootRef, int data){
if(*rootRef == NULL){
*rootRef = newNode(data);
}else{
if(data <= (*rootRef)->data ){
insert( &((*rootRef)->left), data);
}else{
insert( &((*rootRef)->right), data);
}
}
}
/*
* sorted printing
* left-root-right
*/
void printTreeInOrder(struct node* root){
if(root == NULL){
return;
}
printTreeInOrder(root->left);
cout << (root->data) << " ";
printTreeInOrder(root->right);
}
/*
* root-left-right
*/
void printTreePreOrder(struct node* root){
if(root == NULL){
return;
}
cout << (root->data) << " ";
printTreePreOrder(root->left);
printTreePreOrder(root->right);
}
int size(struct node* root){
if(root == NULL) return 0;
return( size(root->left) + size(root->right) + 1 );
}
int maxDepth(struct node* root){
if(root == NULL){
return 0;
}
int lheight = maxDepth(root->left);
int rheight = maxDepth(root->right);
if(lheight > rheight){
return (lheight+1);
}else{
return (rheight+1);
}
}
bool lookup(struct node* root, int target){
if(root == NULL) return false;
if(root->data == target) return true;
if(root->data > target){
return (lookup(root->left, target));
}else
return (lookup(root->right, target));
}


int findMinValue(struct node* root) {
struct node* temp = root;
while (temp->left != NULL) {
	temp = temp->left;
}
return temp->data;
}

struct node* findMin(struct node* root) {
struct node* temp = root;
while (temp->left != NULL) {
	temp = temp->left;
}
return temp;
}

int findMaxValue(struct node* root){
struct node* temp = root;
while(temp->right != NULL){
temp = temp->right;
}
return temp->data;
}

struct node* findMax(struct node* root) {
struct node* temp = root;
while (temp->right != NULL) {
	temp = temp->right;
}
return temp;
}

int findMaxAbsDiff(struct node* root) {
	if (root == NULL) {
		return 0;
	}
	int minValue = findMinValue(root);
	int maxValue = findMaxValue(root);
	return abs(minValue - maxValue);
}


struct node* deleteNode(struct node* root, int target) {

	 if (target < root->data) {
	        // Key is smaller than root's data, go to the left subtree
	        root->left = deleteNode(root->left, target);
	    } else if (target > root->data) {
	        // Key is larger than root's data, go to the right subtree
	        root->right = deleteNode(root->right, target);
	    } else {

		if(root->left == NULL && root->right == NULL) {
			// Case 1 (no child)
			//cout >> "Node " >> deleteNode >> " has been deleted. \n";
			delete root;
			return nullptr;

		} else if (root->left == NULL) {
			// Case 2 (right child)
			//cout >> "Node " >> deleteNode >> " has been deleted. \n";
			struct node* temp = root->right;
			delete root;
			return temp;




		} else if (root->right == NULL) {
			//Case 2 (left child)
			//cout >> "Node " >> deleteNode >> " has been deleted. \n";
			struct node* temp = root->left;
			delete root;
			return temp;

		} else {
			//Case 3 (two children)
			//cout >> "Node " >> deleteNode >> " has been deleted. \n";
			struct node* temp = findMin(root->right);

			root->data = temp->data;

			root->right = deleteNode(root->right, temp->data);

		}
	}
return root;
}



