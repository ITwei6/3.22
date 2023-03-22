#include "Queue.h"
//初始化队列
void  QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
//销毁队列
void  QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	//保存下一个释放，保存下一个释放
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
//入队列
void  QueuePush(Queue* pq, QDatatype x)
{
	assert(pq);
	//入队，就是尾插一个结点，首先生成一个新结点
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->next = NULL;//需要置空，不然会出现野指针
	newnode->data = x;//将数据赋值
	if (newnode == NULL)
	{
		perror("malloc");
	}
	//不带哨兵，所以一开始head和tail都为空，第一步直接将结点赋值过去，然后后面才是真正的尾插
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		//尾插
		pq->tail->next = newnode;
		pq->tail = newnode;//找尾--更新
	}
	pq->size++;
}
//出队列
void  QueuePop(Queue* pq)
{
	assert(pq);
	//在删除数据之前需要考虑队列是否为空;
	assert(!pq->head==NULL);
	//出队列其实就是头删，头删就是让头指针不断改变，让头指针前面的结点释放
	
	
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	//不断的头删
	//但要注意tail是指向最后一个结点的指针。
	//当head指向最后一个结点后释放，那么tail指向的空间被释放，那tail就变成野指针了
	//所以最后需要将tail置NULL
	//有两中方式：第一种，，只管头删，最后再将tail置NULL
	//第二中，一开始就考虑二种情况，最后一个结点之前，和最后一个结点
	// //分为一个结点和多个结点
	//方法1：
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
	//////第二种方法：
	//if (pq->head->next == NULL)
	//{
	//	//直接释放最后一个结点
	//	free(pq->head);
	//	pq->head = pq->tail = NULL;
	//}
	//else
	//{
	//	//头删
	//}
	pq->size--;
}
//获取队列的有效数据的大小 
void  QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;//如果刚刚在分装结构体中不加size的话，要想得到队列的长度，是需要遍历链表的，那时间复杂度O（N）
	//而该方法加上去后就是O（1），不需要遍历。在链表中我们如果想快速得到链表的大小，
	//也可以使用该方法，将头指针和size分装成一个结构体，将该结构体传给push和pop操作函数。
	//还有在链表哨兵头里放size是不可以的 ，不知道数据类型
}

//谈一谈柔性数组与顺序表的区别?
// 空间开辟的位置2.14
//判断队列是否为空
bool  QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}
//获取队头数据
QDatatype  QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
//获取队尾数据
QDatatype  QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;

}