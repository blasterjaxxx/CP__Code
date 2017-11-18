#include <iostream>
#include <algorithm>
#include <climits>

int minnum=INT_MAX;

using namespace std;
struct node {
	int data;
	struct node * left;
	struct node * right;
} * root = NULL;

struct node * insertNode(struct node * tNode, int value) {
	if(tNode == NULL) {
		struct node * newNode = (struct node *)malloc(sizeof(struct node));
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	if(tNode->data > value)
		tNode->left = insertNode(tNode->left, value);
	else
		tNode->right = insertNode(tNode->right, value);
	return tNode;
}

void buildTree(int a[], int N) {
	for(int i = 0; i < N; i++) {
		if(i) {
			insertNode(root, a[i]);
		} else {
			root = insertNode(NULL, a[i]);
		}
	}
}

int findMaxInBST(struct node * tnode) {
    if(tnode==NULL){
        return 1;
    }
	if(tnode->data < minnum){
	    minnum=tnode->data;
	}
	findMaxInBST(tnode->left);
	findMaxInBST(tnode->right);
	return minnum;
}

int main() {
	int N;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	buildTree(arr, N);
	cout << findMaxInBST(root) << endl;
}
