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
//定义结点结构
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;
//将头指针和尾指针分装起来 
//初始化队列
void  QueueInit(Queue* pq);
//销毁队列
void  QueueDestroy(Queue* pq);
//入队列
void  QueuePush(Queue* pq,QDatatype x);
//出队列
void  QueuePop(Queue* pq);
//获取队列的有效数据的大小
void  QueueSize(Queue* pq);
//判断队列是否为空
bool  QueueEmpty(Queue* pq);
//获取队头数据
QDatatype  QueueFront(Queue* pq);
//获取队尾数据
QDatatype  QueueBack(Queue* pq);