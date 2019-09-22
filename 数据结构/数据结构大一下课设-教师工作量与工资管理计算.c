#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//���ֹ��������㷽��
char sample1[11] = "#***Tabc";
char sample2[11] = "#***6abc";


//���㹤�ʵķ���
char income[11] = "#+*d*e##jt";//teacher.job*teacher.timevalue * 10 + 5500;d=5500,e=10

typedef struct data
{
	char name[11];
	char password[11];
	int worktime;//����ʱ��
	double job;//��λ
	int workyear;//����
	char usercode[11];//�̹���
	char workvalue[11];//�������ļ���
	float timevalue;//�洢������
	float income;//����
	int chioce;//1��0�����������㷽��,1Ϊ��ʱ,2Ϊ������https://wenku.baidu.com/view/020b148fec3a87c24028c414.html
	float K[3];//������ϵ��:https://wenku.baidu.com/view/fd74d5a9b8d528ea81c758f5f61fb7360b4c2b3d.html
}data;

typedef struct link
{
	data node;
	struct link* next;
}link,*linklist;

char* char_ex(char* s)
{
	int i = 0;
	char a[16];
	strcpy(a, s);
	while (a[i] != '\n')
	{
		i++;
	}
	a[i] = '\0';
	return a;
}

int create_list(linklist *L)
{
	*L = (linklist)malloc(sizeof(link));
	(*L)->next = NULL;
	return 0;
}

int print_node(data c)
{
	printf("�û�:%s,�̹���:%s,����:%d", c.name, c.usercode,c.workyear);
	if (c.chioce == '2')
	{
		printf("�ǿη�ʽΪ��\n");
	}
	else
	{
		printf("�ǿη�ʽΪ��ʱ\n");
	}
	return 0;
}

int display_list(linklist L)
{
	linklist temp = L->next;
	while (temp != NULL)
	{
		print_node(temp->node);
		temp = temp->next;
	}
	return 0;
}

int get_data(linklist *L)
{
	linklist temp = (*L);
	temp->next = NULL;
	FILE *user = fopen("user", "r");
	FILE *u;
	data teacher;
	if (user == NULL)
	{
		printf("ʧ��,ϵͳ��δ��ʼ��\n");
		return 0;
	}
	int num = 0;
	char a[16], b[16],c[16];
	while (!feof(user))
	{
		fgets(a, 16, user);
		if (strcmp(a, b) == 0 || strcmp(a, "administration\n") == 0)
			continue;
		strcpy(c, char_ex(a));
		strcpy(b, a);

		u = fopen(c, "r");
		fread(&teacher, sizeof(teacher), 1, u);
		temp->next = (linklist)malloc(sizeof(link));
		temp->next->node = teacher;
		fclose(u);
		temp = temp->next;
	}
	temp->next = NULL;
	fclose(user);
	return 0;
}

int Register()
{
	FILE *user1;
	printf("��ע��,�ڲ���Ϣ�ַ��������ܴ���10�ַ�\n");
	data save;
	char u[11];
	char a[11],b[11];

	printf("�����������û���\n");
	scanf("%s", a);
	getchar();
	user1 = fopen(a, "r");

	FILE *add=fopen("user","a+");
	fprintf(add, "%s\n", a);
	fclose(add);

	while (user1 != NULL)
	{
		printf("�û����Ѿ�����,��������\n");
		printf("�����������û���:\n");
		scanf("%s", a);
		getchar();
		user1 = fopen(a, "r");

	}
	strcpy(save.name, a);//�洢�û���
	printf("���������Ľ̹��ţ�\n");
	scanf("%s",u );
	getchar();
	strcpy(save.usercode,u);//�洢�̹���

	printf("����������:\n");
	scanf("%s", b);
	getchar();
	strcpy(save.password, b);//�洢����

	printf("���������Ľ�ʦ��λ:1.��ְ 2.����ְ 3.��ְ 4.��ְ\n");
	char temp1;
	scanf("%c", &temp1);
	getchar();
	switch (temp1)
	{
	case '1':save.job = 1.3;
		break;
	case '2':save.job = 1.2;
		break;
	case '3':save.job = 1.1;
		break;
	case '4':save.job = 1.0;
		break;
	default:printf("error\n");
	};
	//�洢��λϵ��

	printf("�������Ŀ�ʱ���������㵥λ���������ǿ�ʱ?\n1.���� 2.��ʱ\n");
	scanf("%c", &temp1);
	getchar();
	if (temp1 == '1')
	{
		save.chioce = '2';
		strcpy(save.workvalue,sample2);
	}
	else
	{
		save.chioce = '1';
		strcpy(save.workvalue, sample1);
	}
	//�洢���������㹫ʽ
	save.worktime = 0;//���¹���ʱ��
	save.timevalue = 0;//��ʼ��������(��δ����)
	printf("���������Ľ���:\n");
	int temp2;
	scanf("%d", &temp2);
	getchar();
	save.workyear = temp2;

	printf("�������������Ľ�ʦ������ϵ��:\n");

	printf("ѡ�����Ŀγ�����:\n1.�����Σ�˼���������۽��в���,����������в��λ������в���,������Ļ����������Ӧ��,����������﹫����Σ�\n2.רҵ�Ρ�רҵ�����κ������ǹ����ࣩ��\n3.�����Ρ�����ѡ�޿�\n");
	scanf("%c", &temp1);
	getchar();
	switch (temp1)
	{
	case '1':save.K[0] = 1.0;
		break;
	case '2':save.K[0] = 1.2;
		break;
	case '3':save.K[0] = 0.8;
		break;
	default:printf("error\n");
	};
	//�洢�γ�����ϵ��

	printf("ѡ�������ڿΰ��:\n1.0-40\n2.40-60\n3.60-80\n4.80-100\n5.100-120\n6.120-\n");
	scanf("%c", &temp1);
	getchar();
	if (temp1 == '1')
	{
		save.K[1] = 1;
	}
	else if (temp1 == '2')
	{
		save.K[1] = 1.1;
	}
	else if (temp1 == '3')
	{
		save.K[1] = 1.15;
	}
	else if (temp1 == '4')
	{
		save.K[1] = 1.2;
	}
	else if (temp1 == '5')
	{
		save.K[1] = 1.25;
	}
	else
	{
		save.K[1] = 1.3;
	}
	//�洢�ڿΰ��ϵ��

	printf("ѡ�������ظ�������:\n1.һ����\n2.������\n3.�����༰����(���������)\n4.�����༰����(�ǹ��������)\n");
	scanf("%c", &temp1);
	getchar();
	if (temp1 == '1')
	{
		save.K[2] = 1;
	}
	else if (temp1 == '2')
	{
		save.K[2] = 0.85;
	}
	else if (temp1 == '3')
	{
		save.K[2] = 0.8;
	}
	else if (temp1 == '4')
	{
		save.K[2] = 0.75;
	}
	//�洢�ظ���ϵ��

	save.income = 0;//��ʼ������
	FILE *user;
	user = fopen(a, "wb+");
	fwrite(&save, sizeof(save), 1, user);
	fclose(user);
	return 0;
}

int login(char *s)
{
	FILE *user=fopen(s, "rb");
	data temp;
	if (user != NULL)
	{
		fread(&temp, sizeof(temp), 1, user);
		printf("����������:\n");
		char code[11];
		scanf("%s",&code);
		getchar();
		if (strcmp(code, temp.password) != 0)
		{
			printf("�������\n");
			return 0;
		}
		fclose(user);
		return 1;
	}
	else
	{
		printf("User not found\n");
	}
	return 0;
}

int print_data(char *s)
{
	FILE *user = fopen(s, "rb");
	data teacher;
	printf("���Ļ�����ϢΪ:\n");
	fread(&teacher, sizeof(teacher), 1, user);
	fclose(user);
	printf("���Ľ̹���Ϊ:%s\n", teacher.usercode);
	printf("���Ľ�ְ��λϵ��Ϊ%.1f\n", teacher.job);
	printf("���Ľ�ְ��λΪ:");
	switch (int(teacher.job*10))
	{
	case 13:printf("��ְ\n");
		break;
	case 12:printf("����ְ\n");
		break;
	case 11:printf("��ְ\n");
		break;
	case 10:printf("��ְ\n");
	}

	if (teacher.timevalue<0.1)
	{
		printf("���Ĺ�������δ��ʼ��\n");
	}
	else
	{
		printf("���Ĺ�����Ϊ:%.2f\n",teacher.timevalue);
	}

	if (teacher.chioce == '2')
	{
		printf("���ļǿη�ʽΪ��\n");
		printf("���ĵ��¹���ʱ��Ϊ:%d\n", teacher.worktime*6);
	}
	else
	{
		printf("���ļǿη�ʽΪ��ʱ\n");
		printf("���ĵ��¹���ʱ��Ϊ:%d\n", teacher.worktime);
	}

	if (teacher.income == 0 && teacher.worktime == 0)
	{
		printf("��������δ�ڿ�\n");
	}
	else if (teacher.income == 0)
	{
		printf("����δ���������\n");
	}
	else
	{
		printf("����ǰ����Ϊ%.2f\n", teacher.income);
	}
	printf("���ĵĽ���Ϊ:%d\n", teacher.workyear);
	printf("���Ŀγ�����,�ڿΰ��,�ظ�����������ϵ��Ϊ:%.2f,%.2f,%.2f\n",teacher.K[0],teacher.K[1],teacher.K[2]);
	
	return 0;
}

float calculate(char* s,data *t,int i)//����
{
	if (s[i] != '+'&&s[i] != '-'&&s[i] != '*'&&s[i] != '/'&&s[i]!='#')
	{
		switch (s[i])
		{
		case '6':return 6.0 * t->worktime;
		case 'T':return t->worktime;
		case 'a':return t->K[0];
		case 'b':return t->K[1];
		case 'c':return t->K[2];
		case 'd':return 5500;
		case 'e':return 10;
		case 't':return t->timevalue;
		case 'j':return t->job;
		}
	}
	else
	{
		if (s[i] == '+')
		{
			return calculate(s,t,2*i) + calculate(s, t, 2 * i+1);
		}
		else if (s[i] == '-')
		{
			return calculate(s, t, 2 * i) - calculate(s, t, 2 * i+1);
		}
		else if (s[i] == '*')
		{
			return calculate(s, t, 2 * i) * calculate(s, t, 2 * i+1);
		}
		else
		{
			return calculate(s, t, 2 * i) / calculate(s, t, 2 * i+1);
		}
	}
}

int checktime(char *s)
{
	FILE *user = fopen(s, "rb");
	if (user == NULL)
	{
		printf("����ʧ��\n");
		return 0;
	}
	data teacher;
	int time;
	fread(&teacher, sizeof(teacher), 1, user);
	fclose(user);
	if (teacher.chioce == '1')
	{
		printf("�����뵱���ڿο�ʱ:\n");
		scanf("%d", &time);
		getchar();
		teacher.worktime += time;
		printf("����ǰ�ڿ�%d��ʱ\n", teacher.worktime);
	}
	else
	{
		teacher.worktime++;
		printf("����ǰ�ڿ�%d��,����%d��ʱ\n", teacher.worktime, teacher.worktime * 6);
	}
	user = fopen(s, "w+");
	fwrite(&teacher, sizeof(teacher), 1, user);
	fclose(user);
	return 0;
}

int get_worktime(char* s)
{
	FILE *user = fopen(s, "rb");
	data teacher;
	fread(&teacher, sizeof(teacher), 1, user);
	float time;
	time=calculate(teacher.workvalue, &teacher,1);
	fclose(user);
	teacher.timevalue = time;
	user = fopen(s, "w+");
	fwrite(&teacher, sizeof(teacher), 1, user);
	printf("�û�%s�Ĺ�����Ϊ:%.2f\n",s, teacher.timevalue);
	fclose(user);
	return 0;
}

float get_income(char *s)
{
	FILE *user = fopen(s, "rb");
	data teacher;
	fread(&teacher, sizeof(teacher), 1, user);
	if (teacher.timevalue == 0)
	{
		fclose(user);
		printf("�û�%s��δ���㵱�¹�����,���ڼ���\n",s);
		get_worktime(s);
		user = fopen(s, "rb");
	}
	fread(&teacher, sizeof(teacher), 1, user);
	teacher.income = calculate(income, &teacher,1);
	printf("�̹���%s�Ĺ���Ϊ%.2f\n\n",teacher.usercode,teacher.income);
	fclose(user);
	user = fopen(s, "w+");
	fwrite(&teacher, sizeof(teacher), 1, user);
	fclose(user);
	return teacher.income;
}

int menu(char* s)
{
	system("cls");
	printf("��ӭʹ�ý�ʦ��������ϵͳ\n�����������ʲô����?\n0.�˳���ǰ�˻� 1.����˻���Ϣ\n2.���㵱ǰ������ 3.���㹤��\n4.��ѧ��\n");
	int temp;
	scanf("%d", &temp);
	getchar();
	while (temp != 0)
	{
		switch (temp)
		{
		
		case 1:print_data(s);
			break;
		case 2:get_worktime(s);
			break;
		case 3:get_income(s);
			break;
		case 4:checktime(s);
			break;
		default:printf("�������,����������\n");
		}
		printf("�밴�س�������һ����\n");
		getchar();
		
		system("cls");
		printf("��ӭʹ�ý�ʦ��������ϵͳ\n�����������ʲô����?\n0.�˳���ǰ�˻� 1.����˻���Ϣ\n2.���㵱ǰ������ 3.���㹤��\n4.��ѧ��\n");
		scanf("%d", &temp);
		getchar();
		
	}
	return 0;
}

int init_sys()
{
	FILE *fp = fopen("user", "w+");
	fprintf(fp, "administration\n");
	FILE *ad = fopen("administration", "w+");
	printf("��ʼ������Ա����:\n");
	char* a[11];
	scanf("%s", a);
	getchar();
	fprintf(ad, "%s", a);
	fclose(ad);
	if (fp != NULL)
	{
		printf("��ʼ���ɹ�\n");
	}
	else
	{
		printf("��ʼ��ʧ��");
	}
	fclose(fp);
	return 0;
}

int count_user()
{
	FILE *user = fopen("user", "r");
	if (user == NULL)
	{
		printf("ʧ��,ϵͳ��δ��ʼ��\n");
		return 0;
	}
	int num = 0;
	char a[16],b[16];
	while (!feof(user))
	{
		fgets(a,16,user);
		if (strcmp(a, b) == 0)
			continue;
		printf("�û�%d:%s\n",num+1, a);
		num++;
		strcpy(b, a);
	}
	printf("����%d���û�ע��\n", num );
	fclose(user);
	return 0;
}

int ad_check()
{
	char s[11], a[11];
	printf("���������Ա����:\n");
	scanf("%s", s);
	getchar();
	FILE *ad = fopen("administration", "r");
	if (ad == NULL)
	{
		printf("��δ��ʼ��ϵͳ\n");
		return 0;
	}
	fgets(a, 11, ad);
	if (strcmp(a, s) != 0)
	{
		printf("�������\n");
		return 0;
	}
	fclose(ad);
	return 1;
}

int clear(char *s)
{
	FILE *user = fopen(s, "r+");
	data teacher;
	fread(&teacher, sizeof(teacher), 1, user);
	fclose(user);
	teacher.income = teacher.worktime = teacher.timevalue = 0;
	user = fopen(s, "w+");
	fwrite(&teacher, sizeof(teacher), 1, user);
	fclose(user);
	return 0;
}

char* get_usercode(char *s,char* save)
{
	FILE *user = fopen(s, "r");
	data teacher;
	fread(&teacher, sizeof(teacher), 1, user);
	fclose(user);
	strcpy(save, teacher.usercode);
	return teacher.usercode;
}

int weekly_income()
{
	FILE *user = fopen("user", "r");
	FILE *ad = fopen("result.txt", "wt+");
	if (user == NULL)
	{
		printf("ʧ��,ϵͳ��δ��ʼ��\n");
		return 0;
	}
	float temp;
	char a[16], b[16],c[16],d[16];
	while(!feof(user))
	{
		fgets(a, 16, user);
		
		if (strcmp(a, b) == 0 || strcmp(a, "administration\n") == 0)
			continue;
		strcpy(c, char_ex(a));
		temp=get_income(c);
		get_usercode(c,d);
		fprintf(ad,"�̹���:%s �û�:%s ���¹���:%.2f\n",d,c , temp);
		clear(c);
		strcpy(b, a);
	}
	printf("�����˻�������,���¹����������Ŀ¼�µ�result.txt�ĵ���\n");
	fclose(user);
	fclose(ad);
	return 0;
}

int ad_menu()
{
	linklist L;
	create_list(&L); 
	get_data(&L);
	system("cls");
	printf("��ӭʹ�ý�ʦ��������ϵͳ\n====�������Ϊ����Ա====\n���������Ĳ���:\n1.�鿴��ǰ�����û� 2.���������û����ʲ���������\n3.�˳���¼ 4.��������û�������Ϣ\n");
	int temp;
	scanf("%d", &temp);
	getchar();
	while (temp != 0)
	{
		switch (temp)
		{
		case 1:count_user();
			break;
		case 2:weekly_income();
			break;
		case 3:return 0;
		case 4:display_list(L);
			break;
		default:printf("�������,����������\n");
		}
		printf("�밴�س�������һ����\n");
		getchar();

		system("cls");
		printf("��ӭʹ�ý�ʦ��������ϵͳ\n====�������Ϊ����Ա====\n���������Ĳ���:\n1.�鿴��ǰ�����û� 2.���������û����ʲ���������\n3.�˳���¼ 4.��������û�������Ϣ\n");
		scanf("%d", &temp);
		getchar();
	}
	return 0;
}

int main()
{
	FILE *user;
	char s[11];
	int temp;
	int result;
	printf("��ӭʹ�ý�ʦ��������ϵͳ\n������Ҫ���е���:\n1.ע�� 2.��½ 3.�˳�ϵͳ\n4.��ʼ��ϵͳ 5.�������Ա�˺�\n");
	scanf("%d", &temp);
	getchar();
	while (temp != 3)
	{
		if (temp == 1)//ע��
		{
			Register();
		}
		else if (temp == 2)//��¼
		{
			printf("�����������û���:\n");
			scanf("%s", s);
			getchar();
			result = login(s);
			if (result ==0)
			{
				printf("��Ϣ��������\n");
			}
			else
			{
				menu(s);
			}
		}
		else if (temp == 4)
		{
			init_sys();
		}
		else if (temp == 5)
		{
			if (ad_check() == 1)
			{
				ad_menu();
			}
		}
		printf("�밴�س�������һ����\n");
		getchar();
		system("cls");
		printf("��ӭʹ�ý�ʦ��������ϵͳ\n������Ҫ���е���:\n1.ע�� 2.��½ 3.�˳�ϵͳ\n4.��ʼ��ϵͳ 5.�������Ա�˺�\n");
		scanf("%d", &temp);
		getchar();
	}
	printf("��л����ʹ��");
	return 0;
}