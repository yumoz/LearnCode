//��Ŀ���� :
//ͨѶ¼1
//��Ŀ���� :
//ʵ��һ��ͨѶ¼��
//
//ͨѶ¼���������洢1000���˵���
//ÿ���˵���Ϣ�������������Ա����䡢�绰��סַ
//
//�ṩ������
//
//�����ϵ����Ϣ
//ɾ��ָ����ϵ����Ϣ
//����ָ����ϵ����Ϣ
//�޸�ָ����ϵ����Ϣ
//��ʾ������ϵ����Ϣ
//���������ϵ��
//����������������ϵ��
#include "contract.h"

int main()
{
	contact_t *ct = InitContact();
	int quit = 0;
	int select = 0;
	while (!quit){
		Menu();//���ò˵�
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			//AddPerson(&ct);
			break;
		case 2:
			//DelPerson(ct);
			break;
		default:
			quit = 1;
			break;
		}
	}
	printf("SEE YOU!\n");
	system("pause");
	return 0;
}
