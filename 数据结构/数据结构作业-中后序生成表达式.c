#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct tree
{
	char c;
	struct tree *left;
	struct tree *right;
}tree,*treenode;

int check(char *s, char c)
{
	int n = 0;
	while (1)
	{
		if (s[n] == c)
			return n;
		if (s[n] == '\0')
			return -1;
		n++;
	}
}

void crtbt(treenode *T, char *m, char *b, int mn, int bn, int n)
{
	int k;
	if (n == 0)
		*T = NULL;
	else
	{
		k = check(m, b[bn]);
		if (k == -1)
		{
			*T = NULL;
		}
		else
		{
			*T = (treenode)malloc(sizeof(tree));
			(*T)->c = b[bn];
			if (k == mn)
			{
				(*T)->left = NULL;
			}
			else
			{
				crtbt(&(*T)->left, m, b, mn, bn - 1 - (bn-k), k - mn);
			}
			if (k == mn + n - 1)
			{
				(*T)->right = NULL;
			}
			else
			{
				crtbt(&(*T)->right, m, b, k + 1, bn - 1, n - (k - mn) - 1);
			}
		}
	}
}

int pre(treenode T)
{
	if (T != NULL)
	{
		printf("%c", T->c);
		pre(T->left);
		pre(T->right);
	}
	return 0;
}

int main()
{
	char *m, *b;
	treenode t;
	m = (char*)malloc(sizeof(char)*MAX);
	b = (char*)malloc(sizeof(char)*MAX);
	printf("请输入中序表达式：");
	scanf("%s", m);
	printf("请输入后续表达式：");
	scanf("%s", b);
	int n = strlen(b);
	crtbt(&t, m, b, 0, n-1, n);
	pre(t);
	return 0;
}