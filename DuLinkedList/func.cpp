#include"duLinkedList.h"
#include"func.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void menu() {
	printf("*******菜单*******\n");
	printf("1.初始化链表\n");
	printf("2.添加结点\n");
	printf("3.删除结点\n");
	printf("4.遍历结点\n");
	printf("5.摧毁链表\n");
	printf("0.退出\n");
}

void insertafter(DuLinkedList* head) {
	printf("请输入一个int值(若输入不合法，会导致无法储存或储存错误的值):");

	char str[12] = { '\0' };    //保存输入的内容
	int number[12] = { 0 };  //若输入正确，将对应的字符转换成数字保存在数组number中
	int total = 0;          //将number数组中的数字组成用户输入的数字

	bool totalflag = 1;    //若输入不合法，用来做循环输入的标志

	while (totalflag)
	{
		bool flag = 0;  //判断是否输入合法的标志

		//scanf_s("%s", str);
		while (1)
		{
			scanf_s("%11s", str);
			if (strlen(str) != 11)break;
		}

		//判断是否输入合法
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

			//由flag确定是否将string中的字符转化为所对应的数字，并拼成用户输入的数字
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
				printf("输入有误，请重新输入:");
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

			//由flag确定是否将string中的字符转化为所对应的数字，并拼成用户输入的数字
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
				printf("输入有误，请重新输入:");
			}
		}

	}
	DuLinkedList p = (DuLinkedList)malloc(sizeof(DuLNode));
	p->data = total;
	p->prior =NULL;
	p->next = NULL;
	InsertAfterList_DuL(*head, p);
	printf("添加成功\n");
	system("pause");
	system("cls");
}

void drop(DuLinkedList* head) {
	printf("当前链表所有结点值为：");
	TraverseList_DuL(*head, &visit);
	printf("\n");
	printf("请输入要删除第几个结点：");
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
	printf("删除成功!\n");
	system("pause");
	system("cls");
}

//打印
void visit(ElemType e) {
	printf("%5d", e);
}

//10的阶乘
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