#include"LinkedList.h"
#include"func.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>

void menu() {
	printf("*******�˵�*******\n");
	printf("1.��ʼ������\n");
	printf("2.�������\n");
	printf("3.ɾ�����\n");
	printf("4.��������\n");
	printf("5.Ѱ���м���ֵ\n");
	printf("6.��������\n");
	printf("7.��żλȡ��\n");
	printf("8.�ж������Ƿ�ɻ�\n");
	printf("9.��������\n");
	printf("0.�˳�\n");
}


void insert(LinkedList* head) {
	printf("������һ����ȷ��intֵ(�����벻�Ϸ����ᵼ���޷�����򴢴�����ֵ):");

	char str[12] = {'\0'};    //�������������
	int number[12] = { 0 };  //��������ȷ������Ӧ���ַ�ת�������ֱ���������number��
	int total = 0;          //��number�����е���������û����������

	bool totalflag = 1;    //�����벻�Ϸ���������ѭ������ı�־

	while(totalflag)        
	{
		bool flag = 0;  //�ж��Ƿ�����Ϸ��ı�־

		//scanf_s("%s", str);
		while (1)
		{
			scanf_s("%11s", str);
			if (strlen(str)!= 11)break;
		}
		
		//�ж��Ƿ�����Ϸ�
		if (str[0] != '-')
		{
			int n = 0;
			for (int i = 0; i < 11; i++)
			{
				int a = str[i];
				if (a < 48 || a>57)
				{
					break;
				}
				n++;
				if (n > 11)
				{
					flag = 0;
					break;
				}

				if ((str[n ] > 48 && str[n ]<57)||str[n]=='\0')
				{
					flag = 1;
				}
				else
				{
					flag = 0;
				}
				
			}

			//��flagȷ���Ƿ�string�е��ַ�ת��Ϊ����Ӧ�����֣���ƴ���û����������
			if (flag)
			{
				totalflag = 0;
				int i,j;
				for ( i = 0;i<n; i++)
				{
					
					number[i] = str[i] - 48;
				}

				for (j = 0; j <n; j++)
				{
					total = total + (number[j]) * getten(n-j-1);
				}
			}
			else
			{
				printf("������������������:");
			}
		}


		if (str[0] == '-')
		{
			int n = 0;
			for (int i = 1; i < 11; i++)
			{
				int a = str[i];
				if (a < 48 || a>57)
				{
					break;
				}
				n++;
				
				if ((str[n+1 ] > 48 && str[n + 1] < 57)||str[n+1]=='\0')
				{
					flag = 1;
				}
				else
				{
					flag = 0;
				}
			}

			//��flagȷ���Ƿ�string�е��ַ�ת��Ϊ����Ӧ�����֣���ƴ���û����������
			if (flag)
			{
				totalflag = 0;
				int i, j;
				for (i = 1; i <= n; i++)
				{

					number[i] = str[i] - 48;
				}

				for (j = 1; j <= n; j++)
				{
					total = total + (number[j]) * getten(n - j);
				}
				total = -total;
			}
			else
			{
				printf("������������������:");
			}
		}
	}

	LinkedList p = (LinkedList)malloc(sizeof(LNode));
	p->data = total;
	p->next = NULL;
	InsertList(*head, p);
	printf("��ӳɹ�\n");

	system("pause");
	system("cls");
}

void drop(LinkedList* head) {
	if ((*head)->next==NULL)
	{
		printf("����Ϊ�ա�\n");
		return;
	}
	printf("��ǰ�������н��ֵΪ��");
	TraverseList(*head, &visit);
	printf("\n");
	printf("������Ҫɾ���ڼ�����㣺");
	int num;
	scanf_s("%d", &num);
	LinkedList p = *head;
	int j = 1;
	while (j < num && p->next) {
		p = p->next;
		j++;
	}
	int e;
	DeleteList(p, &e);
	system("pause");
	system("cls");
}

//��ӡ
void visit(ElemType e) {
	printf("%11d", e);
}

//10�Ľ׳�
int getten(int n)
{
	int i;
	int total = 1;
	for (i = 1; i <= n;i++)
	{
		total = total * 10;
	}
	return total;
}