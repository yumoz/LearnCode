//�˴�����Դ��https://github.com/shiyingai/address_book_management/blob/master/%E9%80%9A%E8%AE%AF%E5%BD%95.c
#define N 5
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#pragma  warning(disable:4996)
int length = 0, length1 = 0;

struct person
{
	char name[30];   //���� 
	char sex[5];
	int birth;       //���� 
	char tel[12];     //���� 
	char QQ[15];    //QQ 
	char dizhi[20];   //��ַ 
	char email[20];    //�����ʼ� 	 
};
struct person tel[200], tel1[200], temp[200];

void add()  //��� 
{
	int x, i, j;
	printf("������һ����Ҫ��ӵ���������(<=200)��");
	scanf("%d", &x);
	for (i = length; i < length + x; i++)
	{
		printf("��%d����Ϣ\n", i + 1);
		printf("����:");
		scanf("%s", tel[i].name);
		for (j = 0; j < i; j++)
		{
			if (strcmp(tel[j].name, tel[i].name) == 0)
			{
				printf("����ϵ�����У�����������\n");
				printf("����:");
				scanf("%s", tel[i].name);
				break;
			}
		}
		printf("�Ա�:");
		scanf("%s", tel[i].sex);
		printf("��������(��:20190101):");
		scanf("%d", &tel[i].birth);
		printf("����:");
		scanf("%s", tel[i].tel);
		printf("QQ:");
		scanf("%s", tel[i].QQ);
		printf("��ַ:");
		scanf("%s", tel[i].dizhi);
		printf("�����ʼ�:");
		scanf("%s", tel[i].email);
	}
	printf("��ϵ������ӣ�\n");
	length += x;
}
void del(int j)   //ɾ�� 
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
		printf("����ϵ����ɾ��!\n");
		length--;
	}
	else
		printf("���޴��ˣ�\n");
}
void update(int m)   //�޸� 
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
			printf("�������޸ĺ������:");
			scanf("%s", tel[m].name);
			break;
		case 2:
			printf("�������޸ĺ���Ա�:");
			scanf("%s", tel[m].sex);
		case 3:
			printf("�������޸ĺ�ĳ�������:");
			scanf("%d", &tel[m].birth);
			break;
		case 4:
			printf("�������޸ĺ�ĺ���:");
			scanf("%s", tel[m].tel);
			break;
		case 5:
			printf("�������޸ĺ��QQ:");
			scanf("%s", tel[m].QQ);
			break;
		case 6:
			printf("�������޸ĺ�ĵ�ַ:");
			scanf("%s", tel[m].dizhi);
			break;
		case 7:
			printf("�������޸ĺ�ĵ����ʼ�:");
			scanf("%s", tel[m].email);
			break;
		default:
			printf("����ѡ�����\n");
			break;
		}
		system("cls");
		printf("���޸�!\n");
	}
	else
		printf("���޴���!\n");
}
void chazhao(int m)  //����ĳ����ϵ�� 
{
	if (m < length)
	{
		printf("------------------------------------------\n");
		printf("|   ����     |        %s             \n", tel[m].name);
		printf("|   �Ա�     |        %s             \n", tel[m].sex);
		printf("|   ����     |        %d             \n", 2019 - (tel[m].birth / 10000));
		printf("|   ����     |        %s             \n", tel[m].tel);
		printf("|   QQ       |        %s             \n", tel[m].QQ);
		printf("|   ��ַ     |        %s             \n", tel[m].dizhi);
		printf("|   �����ʼ� |        %s             \n", tel[m].email);
		printf("-------------------------------------------\n");
	}
	else
		printf("���޴��ˣ�\n");
}
void display()   //��ʾȫ����ϵ��
{
	int i;
	FILE *fp;
	fp = fopen("tongxunlu.txt", "r");
	if (fp != NULL)
	{
		printf("����\t  �Ա�\t   ����\t      ����\t\t   QQ\t\t    ��ַ\t�����ʼ�\n");
		for (i = 0; i < length; i++)
			printf("%-10s%-10s%-10d%-20s%-20s%-10s%-20s\n", tel[i].name, tel[i].sex, 2019 - (tel[i].birth / 10000), tel[i].tel, tel[i].QQ, tel[i].dizhi, tel[i].email);
		printf("-------------------------------------------------------------------------------------------\n");
	}
	else
		printf("��ʧ�ܣ����ļ�!\n");
}
int add_tbgx()  //��ӣ��ر���ģ� 
{
	int i = length1, x;
	printf("������������ϵ�˵�����:");
	x = find();
	if (x < length)
	{
		tel1[i] = tel[x];
		length1++;
		printf("����ӵ��ر����!\n");
	}
	else
		printf("���޴���!\n");
}
int show_tbgx()  //��ʾ(�ر����) 
{
	int i;
	FILE *fp1;
	fp1 = fopen("tbgx.txt", "r");
	if (fp1 != NULL)
	{
		printf("����\t  �Ա�\t  ����\t      ����\t\t   QQ\t\t    ��ַ\t�����ʼ�\n");
		for (i = 0; i < length1; i++)
		{
			printf("%-10s%-10s%-10d%-20s%-20s%-10s%-20s\n", tel1[i].name, tel1[i].sex, 2019 - (tel1[i].birth / 10000), tel1[i].tel, tel1[i].QQ, tel1[i].dizhi, tel1[i].email);
		}
		printf("-------------------------------------------------------------------------------------------\n");
	}
	else
		printf("���ر����!\n");
}
void mh()  //ģ������(����) 
{
	printf("�������ѯ����(����,�Ա�,����,��ַ):");
	int i, f = 0;
	char c[50];
	scanf("%s", c);
	for (i = 0; i < length; i++)
	{
		if (strstr(tel[i].name, c) != NULL || strstr(tel[i].sex, c) != NULL || strstr(tel[i].tel, c) != NULL || strstr(tel[i].dizhi, c) != NULL)
		{
			f++;
			printf("����\t  �Ա�\t  ����\t      ����\t\t   QQ\t\t    ��ַ\t�����ʼ�\n");
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
		printf("δ�ҵ�������Ϣ!\n");
}
int sort()  //����(������) 
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
int find()    //������ϵ���±� 
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
		printf("������һ��ѡ����:");
		scanf("%d", &choice);//����һ��ѡ���� choice
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
				printf("������Ҫɾ������ϵ������:");
				del(find()); save(); break;
			}
			else
			{
				system("cls");
				printf("ɾ��ʧ�ܣ��ļ���û�����ݣ�\n"); break;
			}
		case 4:
			if (length != 0)
			{
				system("cls");
				printf("������Ҫ�޸ĵ���ϵ������:");
				update(find()); save(); break;
			}
			else
			{
				system("cls");
				printf("�޸�ʧ�ܣ��ļ���û�����ݣ�\n"); break;
			}
		case 5:
			if (length != 0)
			{
				system("cls");
				printf("������Ҫ������ϵ�˵�����:");
				chazhao(find()); break;
			}
			else
			{
				system("cls");
				printf("����ʧ�ܣ��ļ���û�����ݣ�\n"); break;
			}
		case 6:
			system("cls");
			if (length1 != 0)
			{
				show_tbgx();
				break;
			}
			else
				printf("����ʧ�ܣ��ļ���û�����ݣ�\n"); break;
		case 7:
			system("cls");
			mh();
			break;
		case 8:
			system("cls");
			sort();
			printf("����ɹ�!\n");
			display();
			break;
		case 9:
			if (length != 0)
			{
				system("cls");
				printf("������ϵ�ˣ�\n");
				display(); break;
			}
			else
			{
				system("cls");
				printf("�ļ���û�����ݣ�\n"); break;
			}
		case 10:
			memset(tel, 0, sizeof(struct person));
			memset(tel1, 0, sizeof(struct person));
			length = 0;
			length1 = 0;
			save();
			save1();
			system("cls");
			printf("���������\n");
			break;
		case 11:
			exit(0);
			break;
		default:printf("�������\n");
			break;
		}
	}
}
void yzm(char str[], int n)  //��֤�� 
{
	int i, j, len;
	char pstr[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJLMNOPQRSTUVWXYZ";
	len = strlen(pstr);         //���ַ���pstr�ĳ���
	srand(time(0));
	for (i = 0; i < n; i++) {
		j = rand() % len;        //����0~len-1�������
		str[i] = pstr[j];
	}
	str[i] = '\0';
}
int save1()//�����ر���� 
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
int save()   //���� 
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
int load1()//��ʼ�������ر���� 
{
	int j1 = 0;
	FILE *fp1;
	fp1 = fopen("tbgx.txt", "r");
	if (fp1 != NULL)
	{
		while (fread(&tel1[j1], sizeof(struct person), 1, fp1))  //�����ر������ϵ�� 
			j1++;
		length1 = j1;
		printf("�Ѽ���%d���ر����\n", length1);
		fclose(fp1);
	}
	else
		printf("�ļ���û�����ݣ�\n");
}
int load()   //��ʼ���������� 
{
	int j = 0;
	FILE*fp;
	fp = fopen("tongxunlu.txt", "r");
	if (fp != NULL)
	{
		while (fread(&tel[j], sizeof(struct person), 1, fp))  //����������ϵ�� 
			j++;
		length = j;
		printf("�Ѽ���%d������\n", length);
		fclose(fp);
	}
	else
		printf("�ļ���û�����ݣ�\n");
}
int menu()  //�˵� 
{
	printf("\t\t\t\t\t\tͨѶ¼\n");
	printf("                    --------------------------1.���-----------------------\n");
	printf("                    --------------------------2.���(�ر����)-------------\n");
	printf("                    --------------------------3.ɾ��-----------------------\n");
	printf("                    --------------------------4.�޸�-----------------------\n");
	printf("                    --------------------------5.����-----------------------\n");
	printf("                    --------------------------6.����(�ر����)-------------\n");
	printf("                    --------------------------7.ģ������-------------------\n");
	printf("                    --------------------------8.����(������)---------------\n");
	printf("                    --------------------------9.��ʾȫ��-------------------\n");
	printf("                    --------------------------10.���----------------------\n");
	printf("                    --------------------------11.�˳�----------------------\n");
	//	printf("--��ͨѶ¼�߱��ԣ����� �绰 QQ  ��ַ �����ʼ����ı༭--\n");
	printf("                    -------------------��ӭʹ�ñ�ͨѶ¼ϵͳ----------------\n");
}
int updateshow()
{
	printf("\n");
	printf("                  ---������Ҫѡ���޸ĵ�ѡ��---\n");
	printf("                  ------------1.����----------\n");
	printf("                  ------------2.�Ա�----------\n");
	printf("                  ------------3.��������------\n");
	printf("                  ------------4.����----------\n");
	printf("                  ------------5.QQ------------\n");
	printf("                  ------------6.��ַ----------\n");
	printf("                  ------------7.��������------\n");
	printf("���ѡ����:");
}
int main()
{
	time_t t;
	struct tm * lt;
	time(&t);
	lt = localtime(&t);
	printf("��ǰʱ��:%d/%d/%d\n", lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday);
	int n = 3;
	int flag = 0;
	char code[N + 1], str[N + 1];
	while (n)
	{
		yzm(code, N);
		printf("��������֤��,���ִ�Сд<����ʣ%d�λ���>:%s\n", n, code);
		scanf("%s", str);
		n--;
		if (strcmp(code, str) == 0)
		{            //���ִ�Сд����֤��
			n = 0;
			flag = 1;
			printf("��֤��ȷ.\n");
			main1();
		}
	}
	if (flag == 0)
		printf("�Բ��𣬴��������꣬����������.\n");
	return 0;
}