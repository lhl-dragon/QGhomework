#include"duLinkedList.h"
#include"func.h"
#include<stdio.h>
#include<stdlib.h>
#include<string>

int main()
{
	DuLinkedList head = NULL;
	InitList_DuL(&head);
	char choice[10];
	while (1)
	{
		menu();
		printf("\n");

		bool flag = 1; //判断是否输入合法的标志

		while (flag)
		{
			printf("请输入1-10之间的一个数:");
			scanf_s("%s", choice);
			char string[2] = { 48 };
			for (int i = 48; i <= 57; i++, string[0] = i)
			{
				if (!strcmp(choice, string))
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				printf("输入有误，请重新输入\n");
			}
			else
			{
				break;
			}
		}

		switch (choice[0])
		{
		case '1':DestroyList_DuL(&head);
			InitList_DuL(&head);
			printf("初始化成功！\n");
			system("pause");
			system("cls");
			break;
		case '2':insertafter(&head);
			break;
		case '3':drop(&head);
			break;
		case '4':TraverseList_DuL(head, &visit);
			printf("\n");
			system("pause");
			system("cls");
			break;
		case '5':DestroyList_DuL(&head);
			printf("摧毁成功！\n");
			system("pause");
			system("cls");
			break;
		case '0':exit(1);
			break;
		default:break;
		}
	}
}