#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct student
{
	int num;	
	char sex;
	char *name;
}STD;

typedef struct node
{
	STD data;
	struct node *next;
}Node, *Link;

int create(Link* aL)	//create
{
	(*aL) = (Link)malloc(sizeof(Node));
	if (*aL == NULL)
	{
		printf("ERROR\n");
		return 0;
	}
	(*aL)->next = NULL;
	return 1;
}

int insert(Link aL, STD x)	//insert the node in the front
{
	if (aL == NULL)
	{
		printf("Unset list\n");
		return 0;
	}
	Link New = (Link)malloc(sizeof(Node));
	New->data = x;
	New->next = aL->next;
	aL->next = New;
	printf("Success\n");
	return 1;
}

int display(Link aL)	//print out the while list
{
	if (aL == NULL)
	{
		printf("Unset list\n");
		return 0;
	}
	Link cur = aL->next;
	while (cur != NULL)
	{
		printf("Number:%d Name:%s Sex:%c\n", cur->data.num, cur->data.name, cur->data.sex);
		cur = cur->next;
	}
	return 1;
}

int Delete(Link aL, int n)
{
	Link New = aL;
	if (aL == NULL || aL->next == NULL)
	{
		printf("Error list\n");
		return 0;
	}
	while (New->next->data.num != n)
	{
		New = New->next;
		if (New->next == NULL)
		{
			printf("Elem not found\n");
		}
	}
	Link temp = New->next;
	New->next = New->next->next;
	free(temp);
	return 1;

}

int clear(Link aL)
{
	if (aL == NULL)
	{
		printf("Already empty");
		return 0;
	}
	aL = aL->next;
	Link temp = aL;
	while (aL != NULL)
	{
		temp = aL;
		aL = aL->next;
		free(temp);
	}
	return 1;
}

int update(Link aL, STD x)
{
	Link New = aL;
	if (aL == NULL || aL->next == NULL)
	{
		printf("Error list\n");
		return 0;
	}
	while (New->next->data.num != x.num)
	{
		New = New->next;
		if (New->next == NULL)
		{
			printf("Elem not found\n");
		}
	}
	New->next->data = x;
	return 1;
}

int menu()
{
	int n;
	while (1)
	{
		system("cls");
		printf("Choose\n");
		printf("1.Create list	2.Inset elem	3.Display list\n");
		printf("4.Delete elem by num	5.Delete list	6.Update elem by num\n");
		printf("0.Exit\n");
		scanf("%d", &n);
		getchar();

		return n;
	}
}

int main()
{
	char a[100];
	Link L;
	STD s;
	int n,q;
	while (1)
	{
		n = menu();
		switch (n)
		{
		case 1:create(&L);
			printf("Press to continue\n");
			getch();
			break;


		case 2:printf("Please type in the name, num, sex of the student\n");
			scanf("%s %d %c", a, &(s.num), &(s.sex));
			getchar();
			s.name = (char*)malloc(sizeof(char)*(strlen(a)+1));
			strcpy(s.name, a);
			insert(L, s);
			printf("Press to continue\n");
			getchar();
			break;


		case 3:display(L);
			printf("Press to continue\n");
			getch();
			break;


		case 4:printf("Please type in the number of the student that you want to delete from the list\n");
			scanf("%d", &q);
			getchar();
			Delete(L, q);
			printf("Press to continue\n");
			getchar();
			break;

		case 5:clear(L);
			printf("Press to continue\n");
			getch();
			break;

		case 6:printf("Please type in the name, num, sex of the student you want to renew\n");
			scanf("%s %d %c", a, &(s.num), &(s.sex));
			getchar();
			s.name = (char*)malloc(sizeof(char)*(strlen(a) + 1));
			strcpy(s.name, a);
			update(L, s);
			printf("Press to continue\n");
			getchar();
			break;

		case 0:exit(0);
		}
	}
	return 0;
}