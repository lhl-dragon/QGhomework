#include"duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>

Status InitList_DuL(DuLinkedList* L) {
	DuLinkedList head = (DuLinkedList)malloc(sizeof(DuLNode));
	head->prior = NULL;
	head->next = NULL;
	*L = head;
	return SUCCESS;
}

void DestroyList_DuL(DuLinkedList* L) {
	if (*L == NULL) return;
	DuLinkedList p = (*L)->next, q = NULL;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	*L = NULL;
}

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
	if (p->next == NULL && p->prior == NULL) return ERROR;
	q->prior = p->prior;
	q->next = p;
	p->prior->next = q;
	p->prior = q;
	return SUCCESS;
}

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
	if (p->next == NULL && p->prior == NULL) {
		q->prior = p;
		q->next = NULL;
		p->next = q;
	}
	else {
		if (p->next == NULL && p->prior != NULL) {
			q->prior = p;
			q->next = NULL;
			p->next = q;
		}
		else
		{
			q->prior = p;
			q->next = p->next;
			p->next->prior = q;
			p->next = q;
		}
	}
	return SUCCESS;
}

Status InsertList_DuLByIndex(DuLinkedList* L, int index, ElemType e) {
	if (index<0 || index>LengthofLinkedList(*L) + 1) return ERROR;
	if (index == 1 && (*L)->next == NULL) {
		DuLinkedList addNode = (DuLinkedList)malloc(sizeof(DuLNode));
		addNode->data = e;
		addNode->prior = *L;
		addNode->next = NULL;
		(*L)->next = addNode;
	}
	else {
		DuLinkedList p = *L;
		for (int i = 1; p && i < index; i++) {
			p = p->next;
		}
		if (p->next == NULL) {
			DuLinkedList addNode = (DuLinkedList)malloc(sizeof(DuLNode));
			addNode->data = e;
			addNode->prior = p;
			addNode->next = NULL;
			p->next = addNode;
		}
		else {
			DuLinkedList addNode = (DuLinkedList)malloc(sizeof(DuLNode));
			addNode->data = e;
			addNode->prior = p;
			addNode->next = p->next;
			p->next->prior = addNode;
			p->next = addNode;
		}
	}
	return SUCCESS;
}

Status DeleteList_DuL(DuLNode* p, ElemType* e) {
	if (p->next == NULL && p->prior == NULL) return ERROR;
	if (p->next->next == NULL) {
		DuLinkedList q = p->next;
		(*e) = q->data;
		p->next = NULL;
		free(q);
	}
	else {
		DuLinkedList q = p->next;
		(*e) = q->data;
		q->next->prior = p;
		p->next = q->next;
		free(q);
		return SUCCESS;
	}
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	if (L == NULL) return;
	DuLinkedList p = L->next;
	while (p) {
		(*visit)(p->data);
		p = p->next;
	}
}

int LengthofLinkedList(DuLinkedList L) {
	DuLinkedList p = L->next;
	int size = 0;
	while (p) {
		size++;
		p = p->next;
	}
	return size;
}
