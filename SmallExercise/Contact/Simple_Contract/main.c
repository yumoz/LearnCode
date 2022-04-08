//此代码来源：https://github.com/shiyingai/address_book_management/blob/master/%E9%80%9A%E8%AE%AF%E5%BD%95.c
#define N 5
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#pragma  warning(disable:4996)
int length = 0, length1 = 0;

struct person
{
	char name[30];   //姓名 
	char sex[5];
	int birth;       //生日 
	char tel[12];     //号码 
	char QQ[15];    //QQ 
	char dizhi[20];   //地址 
	char email[20];    //电子邮件 	 
};
struct person tel[200], tel1[200], temp[200];

void add()  //添加 
{
	int x, i, j;
	printf("请输入一次性要添加的人数个数(<=200)：");
	scanf("%d", &x);
	for (i = length; i < length + x; i++)
	{
		printf("第%d组信息\n", i + 1);
		printf("姓名:");
		scanf("%s", tel[i].name);
		for (j = 0; j < i; j++)
		{
			if (strcmp(tel[j].name, tel[i].name) == 0)
			{
				printf("该联系人已有，请重新输入\n");
				printf("姓名:");
				scanf("%s", tel[i].name);
				break;
			}
		}
		printf("性别:");
		scanf("%s", tel[i].sex);
		printf("出生日期(例:20190101):");
		scanf("%d", &tel[i].birth);
		printf("号码:");
		scanf("%s", tel[i].tel);
		printf("QQ:");
		scanf("%s", tel[i].QQ);
		printf("地址:");
		scanf("%s", tel[i].dizhi);
		printf("电子邮件:");
		scanf("%s", tel[i].email);
	}
	printf("联系人已添加！\n");
	length += x;
}
void del(int j)   //删除 
{
	if (j < length)
	{
		for (; j < length - 1; j++)
			tel[j] = tel[j + 1];
		//strcpy(tel[j].name,tel[j+1].name);
		//strcpy(tel[j].tel,tel[j+1].tel);
		//strcpy(tel[j].QQ,tel[j+1].QQ);
		//strcpy(tel[j].dizhi,tel[j+1].dizhi);
		//strcpy(tel[j].email,tel[j+1].email);
		system("cls");
		printf("该联系人已删除!\n");
		length--;
	}
	else
		printf("查无此人！\n");
}
void update(int m)   //修改 
{
	char xm[10];
	int x;
	if (m < length)
	{
		updateshow();
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			printf("请输入修改后的姓名:");
			scanf("%s", tel[m].name);
			break;
		case 2:
			printf("请输入修改后的性别:");
			scanf("%s", tel[m].sex);
		case 3:
			printf("请输入修改后的出生日期:");
			scanf("%d", &tel[m].birth);
			break;
		case 4:
			printf("请输入修改后的号码:");
			scanf("%s", tel[m].tel);
			break;
		case 5:
			printf("请输入修改后的QQ:");
			scanf("%s", tel[m].QQ);
			break;
		case 6:
			printf("请输入修改后的地址:");
			scanf("%s", tel[m].dizhi);
			break;
		case 7:
			printf("请输入修改后的电子邮件:");
			scanf("%s", tel[m].email);
			break;
		default:
			printf("输入选项错误！\n");
			break;
		}
		system("cls");
		printf("已修改!\n");
	}
	else
		printf("查无此人!\n");
}
void chazhao(int m)  //查找某个联系人 
{
	if (m < length)
	{
		printf("------------------------------------------\n");
		printf("|   姓名     |        %s             \n", tel[m].name);
		printf("|   性别     |        %s             \n", tel[m].sex);
		printf("|   年龄     |        %d             \n", 2019 - (tel[m].birth / 10000));
		printf("|   号码     |        %s             \n", tel[m].tel);
		printf("|   QQ       |        %s             \n", tel[m].QQ);
		printf("|   地址     |        %s             \n", tel[m].dizhi);
		printf("|   电子邮件 |        %s             \n", tel[m].email);
		printf("-------------------------------------------\n");
	}
	else
		printf("查无此人！\n");
}
void display()   //显示全部联系人
{
	int i;
	FILE *fp;
	fp = fopen("tongxunlu.txt", "r");
	if (fp != NULL)
	{
		printf("姓名\t  性别\t   年龄\t      号码\t\t   QQ\t\t    地址\t电子邮件\n");
		for (i = 0; i < length; i++)
			printf("%-10s%-10s%-10d%-20s%-20s%-10s%-20s\n", tel[i].name, tel[i].sex, 2019 - (tel[i].birth / 10000), tel[i].tel, tel[i].QQ, tel[i].dizhi, tel[i].email);
		printf("-------------------------------------------------------------------------------------------\n");
	}
	else
		printf("打开失败，无文件!\n");
}
int add_tbgx()  //添加（特别关心） 
{
	int i = length1, x;
	printf("请输入已有联系人的姓名:");
	x = find();
	if (x < length)
	{
		tel1[i] = tel[x];
		length1++;
		printf("已添加到特别关心!\n");
	}
	else
		printf("查无此人!\n");
}
int show_tbgx()  //显示(特别关心) 
{
	int i;
	FILE *fp1;
	fp1 = fopen("tbgx.txt", "r");
	if (fp1 != NULL)
	{
		printf("姓名\t  性别\t  年龄\t      号码\t\t   QQ\t\t    地址\t电子邮件\n");
		for (i = 0; i < length1; i++)
		{
			printf("%-10s%-10s%-10d%-20s%-20s%-10s%-20s\n", tel1[i].name, tel1[i].sex, 2019 - (tel1[i].birth / 10000), tel1[i].tel, tel1[i].QQ, tel1[i].dizhi, tel1[i].email);
		}
		printf("-------------------------------------------------------------------------------------------\n");
	}
	else
		printf("无特别关心!\n");
}
void mh()  //模糊查找(姓名) 
{
	printf("请输入查询条件(姓名,性别,号码,地址):");
	int i, f = 0;
	char c[50];
	scanf("%s", c);
	for (i = 0; i < length; i++)
	{
		if (strstr(tel[i].name, c) != NULL || strstr(tel[i].sex, c) != NULL || strstr(tel[i].tel, c) != NULL || strstr(tel[i].dizhi, c) != NULL)
		{
			f++;
			printf("姓名\t  性别\t  年龄\t      号码\t\t   QQ\t\t    地址\t电子邮件\n");
			break;
		}
	}
	for (i = 0; i < length; i++)
	{
		if (strstr(tel[i].name, c) != NULL || strstr(tel[i].sex, c) != NULL || strstr(tel[i].tel, c) != NULL || strstr(tel[i].dizhi, c) != NULL)
		{
			printf("%-10s%-10s%-10d%-20s%-20s%-10s%-20s\n", tel[i].name, tel[i].sex, 2019 - (tel[i].birth / 10000), tel[i].tel, tel[i].QQ, tel[i].dizhi, tel[i].email);
		}
	}
	if (f == 0)
		printf("未找到类似信息!\n");
}
int sort()  //排序(按姓氏) 
{
	int i, j;
	for (i = 0; i < length - 1; i++)
		for (j = 0; j < length - 1 - i; j++)
			if (strcmp(tel[j].name, tel[j + 1].name) > 0)
			{
		temp[j] = tel[j];
		tel[j] = tel[j + 1];
		tel[j + 1] = temp[j];
			}
}
int find()    //查找联系人下标 
{
	char ch[20]; int i;
	scanf("%s", ch);
	for (i = 0; i < length; i++)
	{
		if (strcmp(ch, tel[i].name) == 0)
			break;
	}
	return i;
}
int main1()
{
	system("color 78");
	int choice;
	load();
	load1();
	while (1)
	{
		menu();
		printf("请输入一个选择项:");
		scanf("%d", &choice);//输入一个选择项 choice
		switch (choice)
		{
		case 1:
			system("cls");
			add(); save(); break;
		case 2:
			system("cls");
			add_tbgx(); save1();
			break;
		case 3:
			if (length != 0)
			{
				printf("请输入要删除的联系人姓名:");
				del(find()); save(); break;
			}
			else
			{
				system("cls");
				printf("删除失败，文件中没有数据！\n"); break;
			}
		case 4:
			if (length != 0)
			{
				system("cls");
				printf("请输入要修改的联系人姓名:");
				update(find()); save(); break;
			}
			else
			{
				system("cls");
				printf("修改失败，文件中没有数据！\n"); break;
			}
		case 5:
			if (length != 0)
			{
				system("cls");
				printf("请输入要查找联系人的姓名:");
				chazhao(find()); break;
			}
			else
			{
				system("cls");
				printf("查找失败，文件中没有数据！\n"); break;
			}
		case 6:
			system("cls");
			if (length1 != 0)
			{
				show_tbgx();
				break;
			}
			else
				printf("查找失败，文件中没有数据！\n"); break;
		case 7:
			system("cls");
			mh();
			break;
		case 8:
			system("cls");
			sort();
			printf("排序成功!\n");
			display();
			break;
		case 9:
			if (length != 0)
			{
				system("cls");
				printf("所有联系人：\n");
				display(); break;
			}
			else
			{
				system("cls");
				printf("文件中没有数据！\n"); break;
			}
		case 10:
			memset(tel, 0, sizeof(struct person));
			memset(tel1, 0, sizeof(struct person));
			length = 0;
			length1 = 0;
			save();
			save1();
			system("cls");
			printf("已清空数据\n");
			break;
		case 11:
			exit(0);
			break;
		default:printf("输入错误！\n");
			break;
		}
	}
}
void yzm(char str[], int n)  //验证码 
{
	int i, j, len;
	char pstr[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJLMNOPQRSTUVWXYZ";
	len = strlen(pstr);         //求字符串pstr的长度
	srand(time(0));
	for (i = 0; i < n; i++) {
		j = rand() % len;        //生成0~len-1的随机数
		str[i] = pstr[j];
	}
	str[i] = '\0';
}
int save1()//保存特别关心 
{
	int i;
	FILE *fp1;
	fp1 = fopen("tbgx.txt", "w");
	if (fp1 != NULL)
	{
		for (i = 0; i < length1; i++)
			fwrite(&tel1[i], sizeof(struct person), 1, fp1);
		//fwrite("\r\n",1,2,fp1); 
		fclose(fp1);
	}
}
int save()   //保存 
{
	int i;
	FILE*fp;
	fp = fopen("tongxunlu.txt", "w");
	if (fp != NULL)
	{
		for (i = 0; i < length; i++)
		{
			fwrite(&tel[i], sizeof(struct person), 1, fp);
			//fwrite("\r\n",1,2,fp);
		}
		// fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",tel[i].name,tel[i].birth,tel[i].tel,tel[i].QQ,tel[i].dizhi,tel[i].email);
		fclose(fp);
	}
}
int load1()//初始化载入特别关心 
{
	int j1 = 0;
	FILE *fp1;
	fp1 = fopen("tbgx.txt", "r");
	if (fp1 != NULL)
	{
		while (fread(&tel1[j1], sizeof(struct person), 1, fp1))  //载入特别关心联系人 
			j1++;
		length1 = j1;
		printf("已加载%d条特别关心\n", length1);
		fclose(fp1);
	}
	else
		printf("文件中没有数据！\n");
}
int load()   //初始化载入数据 
{
	int j = 0;
	FILE*fp;
	fp = fopen("tongxunlu.txt", "r");
	if (fp != NULL)
	{
		while (fread(&tel[j], sizeof(struct person), 1, fp))  //载入所有联系人 
			j++;
		length = j;
		printf("已加载%d条数据\n", length);
		fclose(fp);
	}
	else
		printf("文件中没有数据！\n");
}
int menu()  //菜单 
{
	printf("\t\t\t\t\t\t通讯录\n");
	printf("                    --------------------------1.添加-----------------------\n");
	printf("                    --------------------------2.添加(特别关心)-------------\n");
	printf("                    --------------------------3.删除-----------------------\n");
	printf("                    --------------------------4.修改-----------------------\n");
	printf("                    --------------------------5.查找-----------------------\n");
	printf("                    --------------------------6.查找(特别关心)-------------\n");
	printf("                    --------------------------7.模糊查找-------------------\n");
	printf("                    --------------------------8.排序(按姓氏)---------------\n");
	printf("                    --------------------------9.显示全部-------------------\n");
	printf("                    --------------------------10.清空----------------------\n");
	printf("                    --------------------------11.退出----------------------\n");
	//	printf("--该通讯录具备对（姓名 电话 QQ  地址 电子邮件）的编辑--\n");
	printf("                    -------------------欢迎使用本通讯录系统----------------\n");
}
int updateshow()
{
	printf("\n");
	printf("                  ---请输入要选择修改的选项---\n");
	printf("                  ------------1.姓名----------\n");
	printf("                  ------------2.性别----------\n");
	printf("                  ------------3.出生日期------\n");
	printf("                  ------------4.号码----------\n");
	printf("                  ------------5.QQ------------\n");
	printf("                  ------------6.地址----------\n");
	printf("                  ------------7.电子邮箱------\n");
	printf("你的选择是:");
}
int main()
{
	time_t t;
	struct tm * lt;
	time(&t);
	lt = localtime(&t);
	printf("当前时间:%d/%d/%d\n", lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday);
	int n = 3;
	int flag = 0;
	char code[N + 1], str[N + 1];
	while (n)
	{
		yzm(code, N);
		printf("请输入验证码,区分大小写<您还剩%d次机会>:%s\n", n, code);
		scanf("%s", str);
		n--;
		if (strcmp(code, str) == 0)
		{            //区分大小写的验证码
			n = 0;
			flag = 1;
			printf("验证正确.\n");
			main1();
		}
	}
	if (flag == 0)
		printf("对不起，次数已用完，程序已锁定.\n");
	return 0;
}