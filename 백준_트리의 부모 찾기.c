#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Treenode
{
	int data;
	struct Treenode * next;
}node;

node * list[10001];
int visit[10001];
int parent[10001];

void push(int a, int b)
{
	node* ins = (node*)malloc(sizeof(node));
	ins->next = NULL;
	ins->data = b;
	if (list[a] == NULL)
	{
		list[a] = ins;
	}
	else
	{
		ins->next = list[a];
		list[a] = ins;
	}
}

void dfs(int num)
{
	visit[num] = 1;
	node* ins;
	for (ins = list[num]; ins != NULL; ins = ins->next)
	{
		if (visit[ins->data] == 0)
		{
			parent[ins->data] = num;
			dfs(ins->data);
		}
	}
	return;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		push(a, b);
		push(b, a);
	}
	parent[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0)
		{
			dfs(i);
		}
	}
	for (int i = 2; i < n; i++)
	{
		printf("%d\n", parent[i]);
	}
}
