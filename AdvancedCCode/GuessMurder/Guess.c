#include<stdio.h>
//A˵�������ҡ�B˵����C��C˵����D��D˵��C�ں�˵  ����֪3����˵���滰��1����˵���Ǽٻ�
#if 0
int main()
{
	int killer;
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
			//����һ�٣������߼��ж�
		{
			printf("������%c", killer);
		}
	}
	return 0;
}
#endif

int main()
{
	int murder[4] = { 0 }; //Ĭ��4���˶���������

	int i;
	for (i = 0; i < 4; i++) //���������ĸ����е�ĳ����������
	{
		murder[i] = 1; //����ĳ����������
		if ((murder[0] != 1) +
			(murder[2] == 1) +
			(murder[3] == 1) +
			(murder[3] != 1) == 3)
		{
			break; //����ʹ���������ˣ�
		}
		murder[i] = 0; //�����㻹�����
	}

	putchar('A' + i); //��ӡ���ֵı�š����ǵı����0 1 2 3������'A'����A B C D��
	return 0;
}