#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//几种工作量计算方法
char sample1[11] = "#***Tabc";
char sample2[11] = "#***6abc";


//计算工资的方法
char income[11] = "#+*d*e##jt";//teacher.job*teacher.timevalue * 10 + 5500;d=5500,e=10

typedef struct data
{
	char name[11];
	char password[11];
	int worktime;//工作时间
	double job;//岗位
	int workyear;//教龄
	char usercode[11];//教工号
	char workvalue[11];//工作量的计算
	float timevalue;//存储工作量
	float income;//工资
	int chioce;//1或0，工作量计算方法,1为课时,2为天数：https://wenku.baidu.com/view/020b148fec3a87c24028c414.html
	float K[3];//工作量系数:https://wenku.baidu.com/view/fd74d5a9b8d528ea81c758f5f61fb7360b4c2b3d.html
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
	printf("用户:%s,教工号:%s,教龄:%d", c.name, c.usercode,c.workyear);
	if (c.chioce == '2')
	{
		printf("记课方式为天\n");
	}
	else
	{
		printf("记课方式为课时\n");
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
		printf("失败,系统尚未初始化\n");
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
	printf("请注意,内部信息字符串均不能大于10字符\n");
	data save;
	char u[11];
	char a[11],b[11];

	printf("请输入您的用户名\n");
	scanf("%s", a);
	getchar();
	user1 = fopen(a, "r");

	FILE *add=fopen("user","a+");
	fprintf(add, "%s\n", a);
	fclose(add);

	while (user1 != NULL)
	{
		printf("用户名已经存在,重新输入\n");
		printf("请输入您的用户名:\n");
		scanf("%s", a);
		getchar();
		user1 = fopen(a, "r");

	}
	strcpy(save.name, a);//存储用户名
	printf("请输入您的教工号：\n");
	scanf("%s",u );
	getchar();
	strcpy(save.usercode,u);//存储教工号

	printf("请输入密码:\n");
	scanf("%s", b);
	getchar();
	strcpy(save.password, b);//存储密码

	printf("请输入您的教师岗位:1.高职 2.副高职 3.中职 4.初职\n");
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
	//存储岗位系数

	printf("请问您的课时工作量计算单位是天数还是课时?\n1.天数 2.课时\n");
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
	//存储工作量计算公式
	save.worktime = 0;//更新工作时间
	save.timevalue = 0;//初始化工作量(尚未计算)
	printf("请输入您的教龄:\n");
	int temp2;
	scanf("%d", &temp2);
	getchar();
	save.workyear = temp2;

	printf("接下来输入您的教师工作量系数:\n");

	printf("选择您的课程类型:\n1.公共课（思想政治理论教研部课,公共外语教研部课基础教研部课,计算机文化基础计算机应用,基础和外国语公共类课）\n2.专业课、专业基础课和外国语（非公共类）课\n3.体育课、公共选修课\n");
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
	//存储课程类型系数

	printf("选择您的授课班额:\n1.0-40\n2.40-60\n3.60-80\n4.80-100\n5.100-120\n6.120-\n");
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
	//存储授课班额系数

	printf("选择您的重复班数量:\n1.一个班\n2.两个班\n3.三个班及以上(公共外语班)\n4.三个班及以上(非公共外语班)\n");
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
	//存储重复班系数

	save.income = 0;//初始化工资
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
		printf("请输入密码:\n");
		char code[11];
		scanf("%s",&code);
		getchar();
		if (strcmp(code, temp.password) != 0)
		{
			printf("密码错误\n");
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
	printf("您的基本信息为:\n");
	fread(&teacher, sizeof(teacher), 1, user);
	fclose(user);
	printf("您的教工号为:%s\n", teacher.usercode);
	printf("您的教职岗位系数为%.1f\n", teacher.job);
	printf("您的教职岗位为:");
	switch (int(teacher.job*10))
	{
	case 13:printf("高职\n");
		break;
	case 12:printf("副高职\n");
		break;
	case 11:printf("中职\n");
		break;
	case 10:printf("初职\n");
	}

	if (teacher.timevalue<0.1)
	{
		printf("您的工作量尚未初始化\n");
	}
	else
	{
		printf("您的工作量为:%.2f\n",teacher.timevalue);
	}

	if (teacher.chioce == '2')
	{
		printf("您的记课方式为天\n");
		printf("您的当月工作时间为:%d\n", teacher.worktime*6);
	}
	else
	{
		printf("您的记课方式为课时\n");
		printf("您的当月工作时间为:%d\n", teacher.worktime);
	}

	if (teacher.income == 0 && teacher.worktime == 0)
	{
		printf("当月您尚未授课\n");
	}
	else if (teacher.income == 0)
	{
		printf("您尚未计算过工资\n");
	}
	else
	{
		printf("您当前工资为%.2f\n", teacher.income);
	}
	printf("您的的教龄为:%d\n", teacher.workyear);
	printf("您的课程类型,授课班额,重复班数量三者系数为:%.2f,%.2f,%.2f\n",teacher.K[0],teacher.K[1],teacher.K[2]);
	
	return 0;
}

float calculate(char* s,data *t,int i)//计算
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
		printf("操作失败\n");
		return 0;
	}
	data teacher;
	int time;
	fread(&teacher, sizeof(teacher), 1, user);
	fclose(user);
	if (teacher.chioce == '1')
	{
		printf("请输入当天授课课时:\n");
		scanf("%d", &time);
		getchar();
		teacher.worktime += time;
		printf("您当前授课%d课时\n", teacher.worktime);
	}
	else
	{
		teacher.worktime++;
		printf("您当前授课%d天,记作%d课时\n", teacher.worktime, teacher.worktime * 6);
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
	printf("用户%s的工作量为:%.2f\n",s, teacher.timevalue);
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
		printf("用户%s尚未计算当月工作量,正在计算\n",s);
		get_worktime(s);
		user = fopen(s, "rb");
	}
	fread(&teacher, sizeof(teacher), 1, user);
	teacher.income = calculate(income, &teacher,1);
	printf("教工号%s的工资为%.2f\n\n",teacher.usercode,teacher.income);
	fclose(user);
	user = fopen(s, "w+");
	fwrite(&teacher, sizeof(teacher), 1, user);
	fclose(user);
	return teacher.income;
}

int menu(char* s)
{
	system("cls");
	printf("欢迎使用教师津贴管理系统\n请问您想进行什么操作?\n0.退出当前账户 1.输出账户信息\n2.计算当前工作量 3.计算工资\n4.教学打卡\n");
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
		default:printf("输入错误,请重新输入\n");
		}
		printf("请按回车进行下一操作\n");
		getchar();
		
		system("cls");
		printf("欢迎使用教师津贴管理系统\n请问您想进行什么操作?\n0.退出当前账户 1.输出账户信息\n2.计算当前工作量 3.计算工资\n4.教学打卡\n");
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
	printf("初始化管理员密码:\n");
	char* a[11];
	scanf("%s", a);
	getchar();
	fprintf(ad, "%s", a);
	fclose(ad);
	if (fp != NULL)
	{
		printf("初始化成功\n");
	}
	else
	{
		printf("初始化失败");
	}
	fclose(fp);
	return 0;
}

int count_user()
{
	FILE *user = fopen("user", "r");
	if (user == NULL)
	{
		printf("失败,系统尚未初始化\n");
		return 0;
	}
	int num = 0;
	char a[16],b[16];
	while (!feof(user))
	{
		fgets(a,16,user);
		if (strcmp(a, b) == 0)
			continue;
		printf("用户%d:%s\n",num+1, a);
		num++;
		strcpy(b, a);
	}
	printf("共有%d个用户注册\n", num );
	fclose(user);
	return 0;
}

int ad_check()
{
	char s[11], a[11];
	printf("请输入管理员密码:\n");
	scanf("%s", s);
	getchar();
	FILE *ad = fopen("administration", "r");
	if (ad == NULL)
	{
		printf("尚未初始化系统\n");
		return 0;
	}
	fgets(a, 11, ad);
	if (strcmp(a, s) != 0)
	{
		printf("密码错误\n");
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
		printf("失败,系统尚未初始化\n");
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
		fprintf(ad,"教工号:%s 用户:%s 当月工资:%.2f\n",d,c , temp);
		clear(c);
		strcpy(b, a);
	}
	printf("所有账户已清零,当月工资已输出在目录下的result.txt文档中\n");
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
	printf("欢迎使用教师津贴管理系统\n====您的身份为管理员====\n请输入您的操作:\n1.查看当前所有用户 2.计算所有用户工资并清零数据\n3.退出登录 4.输出所有用户基本信息\n");
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
		default:printf("输入错误,请重新输入\n");
		}
		printf("请按回车进行下一操作\n");
		getchar();

		system("cls");
		printf("欢迎使用教师津贴管理系统\n====您的身份为管理员====\n请输入您的操作:\n1.查看当前所有用户 2.计算所有用户工资并清零数据\n3.退出登录 4.输出所有用户基本信息\n");
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
	printf("欢迎使用教师津贴管理系统\n请问您要进行的是:\n1.注册 2.登陆 3.退出系统\n4.初始化系统 5.登入管理员账号\n");
	scanf("%d", &temp);
	getchar();
	while (temp != 3)
	{
		if (temp == 1)//注册
		{
			Register();
		}
		else if (temp == 2)//登录
		{
			printf("请输入您的用户名:\n");
			scanf("%s", s);
			getchar();
			result = login(s);
			if (result ==0)
			{
				printf("信息输入有误\n");
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
		printf("请按回车进行下一操作\n");
		getchar();
		system("cls");
		printf("欢迎使用教师津贴管理系统\n请问您要进行的是:\n1.注册 2.登陆 3.退出系统\n4.初始化系统 5.登入管理员账号\n");
		scanf("%d", &temp);
		getchar();
	}
	printf("感谢您的使用");
	return 0;
}