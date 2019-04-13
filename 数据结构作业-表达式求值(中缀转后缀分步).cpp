#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


typedef struct stack {
	char *L;
	int top;
	int max;
}*sqstack;

char pop(sqstack a)
{
	a->top--;
	return a->L[a->top + 1];
}

int push(sqstack a,char s)
{
	a->L[a->top] = s;
	a->top++;
	return 0;
}

int pri(char a)
{
	if (a == '*' || a == '/')
		return 4;
	else if (a == '+' || a == '-')
		return 3;
	else if (a == '(')
		return 2;
	else if (a == '#')
		return 1;
	else
		return 0;
}

char gettop(sqstack a)
{
	return a->L[a->top - 1];
}

int transform(char *s, char *end)
{
	sqstack a=(sqstack)malloc(sizeof(stack));
	a->L = (char*)malloc(sizeof(char)*MAX);
	a->max = MAX;
	a->top = 0;
	push(a, '#');
	int i = 0, j = 0;
	char temp;
	int n = strlen(s);
	a->L[n] = '#';
	a->L[n + 1] = '\0';
	while (s[i] != '\0')
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			end[j++] = s[i];
		}
		else if (s[i] == '(')
		{
			push(a, s[i]);
		}
		else if (s[i] == ')')
		{
			temp = pop(a);

			while (temp != '(')
			{
				end[j++] = temp;
				temp = pop(a);
			}
		}
		else
		{
			temp = gettop(a);
			while (pri(temp) >= pri(s[i]))
			{
				end[j++] = temp;
				pop(a);
				temp = gettop(a);
			}
			if (s[i] != '#')
				push(a, s[i]);
		}
		i++;
	}
	temp = gettop(a);
	while (temp != '#')
	{
		end[j++] = temp;
		pop(a);
		temp = gettop(a);
	}
	end[j] = '\0';
	return 1;
}

int solve(char *s)
{
	int *a=(int *)malloc(sizeof(int)*MAX);
	char temp;
	int top = 0;
	int i = 0,sum;
	while (s[i] != '\0')
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			s[i] = s[i] - '0';
		}
		i++;
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 0 && s[i] <= 9)
		{
			a[top++] = s[i];
		}
		else if (s[i] == '+')
		{
			temp = a[--top];
			temp = a[--top] + temp;
			a[top++] = temp;
		}
		else if (s[i] == '-')
		{
			temp = a[--top];
			temp = a[--top] - temp;
			a[top++] = temp;
		}
		else if (s[i] == '*')
		{
			temp = a[--top];
			temp = a[--top] * temp;
			a[top++] = temp;
		}
		else if (s[i] == '/')
		{
			temp = a[--top];
			temp = a[--top] + temp;
			a[top++] = temp;
		}
		i++;
	}
	return a[0];
}

int main()
{
	char* S = (char*)malloc(sizeof(char)*MAX);
	scanf("%s", S);
	char* end = (char*)malloc(sizeof(char)*MAX);
	transform(S, end);
	printf("%s\n", end);
	int result = solve(end);
	printf("%d\n", result);
	return 0;
}