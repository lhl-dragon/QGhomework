#include "linkedList.h"
#include<stdio.h>
#include<stdlib.h>

Status InitList(LinkedList* L) {
    LinkedList head = (LinkedList)malloc(sizeof(LNode));
    head->next = NULL;
    *L = head;
    return SUCCESS;
}

void DestroyList(LinkedList* L) {
    if (*L == NULL) return;
    LinkedList p = (*L)->next, q = NULL;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L) = NULL;
}

Status InsertList(LNode* p, LNode* q) {
    q->next = p->next;
    p->next = q;
    return SUCCESS;
}

Status InsertListByIndex(LinkedList* L, int i, ElemType e) {
    LinkedList p;
    p = *L;
    for (int j = 1; p && j < i; j++) {
        p = p->next;
    }
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return SUCCESS;
}

Status DeleteList(LNode* p, ElemType* e) {
    if (p ->next== NULL) return ERROR;
    LinkedList q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return SUCCESS;
}

Status DeleteListByIndex(LinkedList* L, int i) {
    if (i<0 || i>LengthofLinkedList(*L)) return ERROR;
    LinkedList p = *L;
    int j = 1;
    while (j < i && p->next) {
        p = p->next;
        j++;
    }
    LinkedList q = p->next;
    p->next = q->next;
    free(q);
    return SUCCESS;
}

void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    if (!L) return;
    LinkedList p = L->next;
    while (p) {
        (*visit)(p->data);
        p = p->next;
    }
}

Status SearchList(LinkedList L, ElemType e) {
    LinkedList p = L->next;
    while (p) {
        if (p->data == e) return SUCCESS;
        else {
            p = p->next;
        }
    }
    return ERROR;
}

Status ReverseList(LinkedList* L) {
    if (*L == NULL || (*L)->next == NULL) return ERROR;
    LinkedList pre = NULL, next = NULL, cur = (*L)->next;
    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    (*L)->next = pre;

    return SUCCESS;
}

Status IsLoopList(LinkedList L) {
    if (L->next == NULL) return ERROR;
    LinkedList fast = L, slow = L;
    while (fast) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) return SUCCESS;
    }
    return ERROR;
}

LNode* ReverseEvenList(LinkedList* L) {
    LinkedList pre = *L, cur = (*L)->next;
    while (cur && cur->next) {
        pre->next = cur->next;
        cur->next = pre->next->next;
        pre->next->next = cur;
        pre = cur;
        cur = cur->next;
    }
    return *L;
}

LNode* FindMidNode(LinkedList* L) {
    if ((*L)->next == NULL) return NULL;
    LinkedList fast = *L, slow = *L;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int LengthofLinkedList(LinkedList L) {
    LinkedList p = L->next;
    int size = 0;
    while (p) {
        size++;
        p = p->next;
    }
    return size;
}