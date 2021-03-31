#pragma once
#include"duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>

void menu();

void insertbefore(DuLinkedList* head);

void insertafter(DuLinkedList* head);

void drop(DuLinkedList* head);

void visit(ElemType e);

int getten(int n);