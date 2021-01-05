#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;

}TreeNode;

void initTree(TreeNode* tr)
{
	tr->key = NULL;
	tr->left = NULL;
	tr->right = NULL;
}

/*
TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;

	else if (key < node->key)
		return search(node->left, key);
	else if (key > node->key)
		return search(node->right, key);
}
*/

TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	if (node == NULL) return new_node(key);

	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	return node;
}

// 후위 순회
void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);// 왼쪽서브트리 순회
		postorder(root->right);// 오른쪽서브트리순회
		printf("[%d] ", root->key);// 노드 방문
	}
}

int main(void) 
{	
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	int C;				//case
	scanf("%d", &C);

	for (int i = 0; i < C; i++) {

		int N;			// node 수
		scanf("%d", &N);
		
		int preorder_arr[100];
		int inorder_arr[100];
		
		for (int j = 0; j < N; j++)
		{		
			scanf("%d", &preorder_arr[j]);
		}
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &inorder_arr[j]);
		}
		for (int k = 0; k < N; k++)
			root = insert_node(root, preorder_arr[k]);

		postorder(root);
		initTree(root);
		printf("\n");
	}
	
}
