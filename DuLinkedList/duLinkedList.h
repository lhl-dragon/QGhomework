#pragma once
#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

#define OVERFLOW -1

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior, * next;
} DuLNode, * DuLinkedList;

// define status
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;

Status InitList_DuL(DuLinkedList* L);

void DestroyList_DuL(DuLinkedList* L);

Status InsertList_DuLByIndex(DuLinkedList* L, int index, ElemType e);

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q);

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q);

Status DeleteList_DuL(DuLNode* p, ElemType* e);

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));

int LengthofLinkedList(DuLinkedList L);

#endif