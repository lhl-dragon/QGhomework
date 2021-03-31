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

		bool flag = 1; //�ж��Ƿ�����Ϸ��ı�־
		
		while (flag)
		{
			printf("������1-10֮���һ����:");
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
				printf("������������������\n");
			}
			else
			{
				break;
			}
		}
		switch (choice[0]) {
		case '1':DestroyList(&head);
			InitList(&head); 
			printf("��ʼ���ɹ���\n");
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
				printf("�м���ֵΪ��%5d\n", FindMidNode(&head)->data);
			}
			else
			{
				printf("����Ϊ��.\n");
			}

			system("pause");
			system("cls");
			break;
		case '6':ReverseList(&head);
			printf("��ת�ɹ�\n");
			system("pause");
			system("cls");
			break;
		case '7':ReverseEvenList(&head);
			printf("��żλ�����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case '8':if (IsLoopList(head))printf("�ɻ�\n");
			  else printf("���ɻ�\n");
			system("pause");
			system("cls");
			break;
		case '9':DestroyList(&head);
			printf("�ݻٳɹ�\n");
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

