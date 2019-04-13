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
	return a->L[a->top];
}

int push(sqstack a, char s)
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

int get(int x, int y, char c)
{
	if (c == '+')
	{
		return x + y;
	}
	else if (c == '-')
	{
		return x - y;
	}
	else if (c == '*')
	{
		return x * y;
	}
	else
	{
		return x / y;
	}
}

int solve(char* s)
{
	sqstack a = (sqstack)malloc(sizeof(stack));
	a->L = (char*)malloc(sizeof(char)*MAX);
	a->max = MAX;
	a->top = 0;
	push(a, '#');
	int *num = (int*)malloc(sizeof(int)*MAX);
	int n = strlen(s);
	s[n] = '#';
	s[n + 1] = '\0';
	int i = 0, j = 0;
	int x, y;
	char temp;
	while (s[i] != '\0')
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			num[j++] = s[i] - '0';
			i++;
		}
		else if (s[i] == '#')
		{
			while (gettop(a) != '#')
			{
				x = num[--j];
				y = num[--j];
				temp = pop(a);
				printf("%d\n", get(y, x, temp));
				num[j++] = get(y, x, temp);
			}
			break;
		}
		else
		{
			if (s[i] == ')')
			{
				do
				{
					x = num[--j];
					y = num[--j];
					temp = pop(a);
					printf("%d\n", get(y, x, temp));
					num[j++] = get(y, x, temp);
				} while (gettop(a)!='(');
				pop(a);
				i++;
				continue;
			}
			else if (s[i] == '(')
			{
			}
			else if (pri(s[i]) <= pri(gettop(a)))
			{
				do
				{
					x = num[--j];
					y = num[--j];
					temp = pop(a);
					printf("%c\n", temp);
					printf("y=%d,x=%d,end=%d\n",y,x, get(y, x, temp));
					num[j++]= get(y, x,temp);
				} while (pri(s[i]) <= pri(gettop(a)));
			}
			push(a, s[i]);
			i++;
		}
		
		printf("i=%d,j=%d,result=%d\n",i,j ,num[0]);
	}
	return num[0];
}

int main()
{
	char* S = (char*)malloc(sizeof(char)*MAX);
	scanf("%s", S);
	int result = solve(S);
	printf("%d\n", result);
	return 0;
}