#pragma once
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#define OVERFLOW -1

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;

Status InitList(LinkedList* L);

void DestroyList(LinkedList* L);

Status InsertList(LNode* p, LNode* q);

Status InsertListByIndex(LinkedList* L, int i, ElemType e);

Status DeleteList(LNode* p, ElemType* e);

Status DeleteListByIndex(LinkedList* L, int i);

void TraverseList(LinkedList L, void (*visit)(ElemType e));

Status SearchList(LinkedList L, ElemType e);

Status ReverseList(LinkedList* L);

Status IsLoopList(LinkedList L);

LNode* ReverseEvenList(LinkedList* L);

LNode* FindMidNode(LinkedList* L);

int LengthofLinkedList(LinkedList L);

//void menu();
//
//void add();
//
//void drop(LinkedList* head);

#endif