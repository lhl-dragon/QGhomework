#include"duLinkedList.h"
#include"func.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void menu() {
	printf("*******�˵�*******\n");
	printf("1.��ʼ������\n");
	printf("2.��ӽ��\n");
	printf("3.ɾ�����\n");
	printf("4.�������\n");
	printf("5.�ݻ�����\n");
	printf("0.�˳�\n");
}

void insertafter(DuLinkedList* head) {
	printf("������һ��intֵ(�����벻�Ϸ����ᵼ���޷�����򴢴�����ֵ):");

	char str[12] = { '\0' };    //�������������
	int number[12] = { 0 };  //��������ȷ������Ӧ���ַ�ת�������ֱ���������number��
	int total = 0;          //��number�����е���������û����������

	bool totalflag = 1;    //�����벻�Ϸ���������ѭ������ı�־

	while (totalflag)
	{
		bool flag = 0;  //�ж��Ƿ�����Ϸ��ı�־

		//scanf_s("%s", str);
		while (1)
		{
			scanf_s("%11s", str);
			if (strlen(str) != 11)break;
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

				if ((str[n] > 48 && str[n] < 57)||str[n]=='\0')
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
				for (i = 0; i < n; i++)
				{

					number[i] = str[i] - 48;
				}

				for (j = 0; j < n; j++)
				{
					total = total + (number[j]) * getten(n - j - 1);
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

				if ((str[n+1] > 48 && str[n+1] < 57) || str[n+1] == '\0')
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
	DuLinkedList p = (DuLinkedList)malloc(sizeof(DuLNode));
	p->data = total;
	p->prior =NULL;
	p->next = NULL;
	InsertAfterList_DuL(*head, p);
	printf("��ӳɹ�\n");
	system("pause");
	system("cls");
}

void drop(DuLinkedList* head) {
	printf("��ǰ�������н��ֵΪ��");
	TraverseList_DuL(*head, &visit);
	printf("\n");
	printf("������Ҫɾ���ڼ�����㣺");
	int num;
	scanf_s("%d", &num);
	DuLinkedList p = (DuLinkedList)malloc(sizeof(DuLNode));
	p = *head;
	int j = 1;
	while (j < num && p->next) {
		p = p->next;
		j++;
	}
	int e;
	DeleteList_DuL(*head, &e);
	printf("ɾ���ɹ�!\n");
	system("pause");
	system("cls");
}

//��ӡ
void visit(ElemType e) {
	printf("%5d", e);
}

//10�Ľ׳�
int getten(int n)
{
	int i;
	int total = 1;
	for (i = 1; i <= n; i++)
	{
		total = total * 10;
	}
	return total;
}