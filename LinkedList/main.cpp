#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"
#include"func.h"
#include<string.h>


int main()
{
	LinkedList head = NULL;
	InitList(&head);
	char choice[10];
	while (true) {
		menu();
		printf("\n");

		bool flag = 1; //判断是否输入合法的标志
		
		while (flag)
		{
			printf("请输入1-10之间的一个数:");
			scanf_s("%s", choice);
			char string[2] = {48};
			for (int i=48; i <= 57; i++,string[0]=i)
			{
				if (!strcmp(choice,string))
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
		switch (choice[0]) {
		case '1':DestroyList(&head);
			InitList(&head); 
			printf("初始化成功！\n");
			system("pause");
			system("cls");
			break;
		case '2':insert(&head);
			break;
		case '3':drop(&head);
			break;
		case '4':TraverseList(head,&visit);
			printf("\n");
			system("pause");
			system("cls");
			break;
		case '5':
			if (FindMidNode(&head))
			{
				printf("中间结点值为：%5d\n", FindMidNode(&head)->data);
			}
			else
			{
				printf("链表为空.\n");
			}

			system("pause");
			system("cls");
			break;
		case '6':ReverseList(&head);
			printf("反转成功\n");
			system("pause");
			system("cls");
			break;
		case '7':ReverseEvenList(&head);
			printf("奇偶位调换成功\n");
			system("pause");
			system("cls");
			break;
		case '8':if (IsLoopList(head))printf("成环\n");
			  else printf("不成环\n");
			system("pause");
			system("cls");
			break;
		case '9':DestroyList(&head);
			printf("摧毁成功\n");
			system("pause");
			system("cls");
			break;
		case '0':exit(1);
			break;
		default:
			break;
		}
	}
	return 0;
}

