#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Lstack {
	char c;
	struct Lstack *next;
}Lstack,*stack;

int push(stack *L, char c)
{
	stack p = (stack)malloc(sizeof(Lstack));
	p->next = *L;
	p->c = c;
	*L = p;
	return 0;
}

char pop(stack *L)
{
	stack temp = *L;
	char c = (*L)->c;
	*L = (*L)->next;
	free(temp);
	return c;
}

int gettop(stack L)
{
	if (L == NULL || L->c == '\0')
		return 0;
	else
		return 1;
}

int check()
{
	printf("Please type in:\n");
	char *a = (char*)malloc(sizeof(char)*MAX);
	scanf("%s", a);
	stack L = (stack)malloc(sizeof(Lstack));
	L->c='\0';
	L->next = NULL;
	char temp;
	while (*a != '\0')
	{
		
		if (*a != '(' && *a != '{' && *a != '[' && *a != ')' && *a != '}' & *a != ']')
		{
			if (!gettop(L))
			{
				return 0;
			}
			*a++;
			continue;
		}
		if (*a == '(' || *a == '{' || *a == '[')
		{
			push(&L, *a);
		}
		else
		{
			if (!gettop(L))
			{
				return 0;
			}
			temp = pop(&L);
			switch (*a)
			{
			case ')':
				if (temp != '(')
				{
					return 0;
				}
				break;
			case '}':
				if (temp != '{')
				{
					return 0;
				}
				break;
			case '[':
				if (temp != ']')
				{
					return 0;
				}
				
			}
		}
		a++;
	}
	if (gettop(L))
	{
		return 0;
	}
	return 1;
}

int main()
{
	if (check())
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
}