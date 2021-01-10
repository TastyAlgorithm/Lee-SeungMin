#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef enum _bool {
	FALSE,
	TRUE
} bool;
#define FALSE 0
#define TRUE 1

typedef struct TreeNode {
	char key;
	struct TreeNode *left1, *left2, *right1, *right2;
	bool chk;
} TreeNode;

TreeNode* root = NULL;

TreeNode* newNode(char data) {
	TreeNode* newT;
	newT = (TreeNode*)malloc(sizeof(TreeNode));

	newT->key = data;
	newT->left1 = NULL;
	newT->left2 = NULL;
	newT->right1 = NULL;
	newT->right2 = NULL;
	newT->chk = FALSE;

	return newT;
}

void addTree(TreeNode* P, char data) {
	TreeNode* ptr;
	TreeNode* newT = newNode(data);
	if (data != 'x') { newT->chk = TRUE; }

	if (P == NULL) { root = newT; return; }

	ptr = P;
	while (ptr) {
		//left1
		if(ptr->left1 == NULL) { 
			ptr->left1 = newT;
			break; 
		}
		else if (ptr->left1->key == 'x' && !(ptr->left1->chk)) {
			ptr = ptr->left1;
			continue;
		}

		//left2
		if (ptr->left2 == NULL) {
			ptr->left2 = newT;
			break;
		}
		else if (ptr->left2->key == 'x' && !(ptr->left2->chk)) {
			ptr = ptr->left2;
			continue;
		}

		//right1
		if (ptr->right1 == NULL) {
			ptr->right1 = newT;
			break;
		}
		else if (ptr->right1->key == 'x' && !(ptr->right1->chk)) {
			ptr = ptr->right1;
			continue;
		}

		//right2
		if (ptr->right2 == NULL) {
			ptr->chk = TRUE;
			ptr->right2 = newT;
			break;
		}
		else if (ptr->right2->key == 'x' && !(ptr->right2->chk)) {
			ptr = ptr->right2;
			continue;
		}
	}
}

void UpsideDown(TreeNode* T) {
	printf("%c", T->key);
	if (T->right1) { UpsideDown(T->right1); }
	if (T->right2) { UpsideDown(T->right2); }
	if (T->left1) { UpsideDown(T->left1); }
	if (T->left2) { UpsideDown(T->left2); }
}

void delTree(TreeNode* T) {
	if (T->left1) { delTree(T->left1); }
	if (T->left2) { delTree(T->left2); }
	if (T->right1) { delTree(T->right1); }
	if (T->right2) { delTree(T->right2); }
}
int main()
{
	TreeNode* ptr;
	int C;
	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		char S[1001];			//문자열 마지막은 NULL
		scanf("%s", S);

		for (int j = 0; j < strlen(S); j++) {
			addTree(root, S[i]);
		}

		ptr = root;
		UpsideDown(ptr);
		printf("\n");

		delTree(root);
		root = NULL;

	}

	return 0;
}
