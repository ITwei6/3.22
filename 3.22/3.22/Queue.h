#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int QDatatype;
typedef struct QNode
{
	struct QNode* next;
	QDatatype data;
}QNode;
//������ṹ
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;
//��ͷָ���βָ���װ���� 
//��ʼ������
void  QueueInit(Queue* pq);
//���ٶ���
void  QueueDestroy(Queue* pq);
//�����
void  QueuePush(Queue* pq,QDatatype x);
//������
void  QueuePop(Queue* pq);
//��ȡ���е���Ч���ݵĴ�С
void  QueueSize(Queue* pq);
//�ж϶����Ƿ�Ϊ��
bool  QueueEmpty(Queue* pq);
//��ȡ��ͷ����
QDatatype  QueueFront(Queue* pq);
//��ȡ��β����
QDatatype  QueueBack(Queue* pq);