#include "Queue.h"
//��ʼ������
void  QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
//���ٶ���
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
	//������һ���ͷţ�������һ���ͷ�
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
//�����
void  QueuePush(Queue* pq, QDatatype x)
{
	assert(pq);
	//��ӣ�����β��һ����㣬��������һ���½��
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->next = NULL;//��Ҫ�ÿգ���Ȼ�����Ұָ��
	newnode->data = x;//�����ݸ�ֵ
	if (newnode == NULL)
	{
		perror("malloc");
	}
	//�����ڱ�������һ��ʼhead��tail��Ϊ�գ���һ��ֱ�ӽ���㸳ֵ��ȥ��Ȼ��������������β��
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		//β��
		pq->tail->next = newnode;
		pq->tail = newnode;//��β--����
	}
	pq->size++;
}
//������
void  QueuePop(Queue* pq)
{
	assert(pq);
	//��ɾ������֮ǰ��Ҫ���Ƕ����Ƿ�Ϊ��;
	assert(!pq->head==NULL);
	//��������ʵ����ͷɾ��ͷɾ������ͷָ�벻�ϸı䣬��ͷָ��ǰ��Ľ���ͷ�
	
	
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	//���ϵ�ͷɾ
	//��Ҫע��tail��ָ�����һ������ָ�롣
	//��headָ�����һ�������ͷţ���ôtailָ��Ŀռ䱻�ͷţ���tail�ͱ��Ұָ����
	//���������Ҫ��tail��NULL
	//�����з�ʽ����һ�֣���ֻ��ͷɾ������ٽ�tail��NULL
	//�ڶ��У�һ��ʼ�Ϳ��Ƕ�����������һ�����֮ǰ�������һ�����
	// //��Ϊһ�����Ͷ�����
	//����1��
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
	//////�ڶ��ַ�����
	//if (pq->head->next == NULL)
	//{
	//	//ֱ���ͷ����һ�����
	//	free(pq->head);
	//	pq->head = pq->tail = NULL;
	//}
	//else
	//{
	//	//ͷɾ
	//}
	pq->size--;
}
//��ȡ���е���Ч���ݵĴ�С 
void  QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;//����ո��ڷ�װ�ṹ���в���size�Ļ���Ҫ��õ����еĳ��ȣ�����Ҫ��������ģ���ʱ�临�Ӷ�O��N��
	//���÷�������ȥ�����O��1��������Ҫ�������������������������ٵõ�����Ĵ�С��
	//Ҳ����ʹ�ø÷�������ͷָ���size��װ��һ���ṹ�壬���ýṹ�崫��push��pop����������
	//�����������ڱ�ͷ���size�ǲ����Ե� ����֪����������
}

//̸һ̸����������˳��������?
// �ռ俪�ٵ�λ��2.14
//�ж϶����Ƿ�Ϊ��
bool  QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}
//��ȡ��ͷ����
QDatatype  QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
//��ȡ��β����
QDatatype  QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;

}