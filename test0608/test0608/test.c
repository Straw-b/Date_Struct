#include "Queue.h"

int main()
{
	TestQueue();
	return 0;
}
	



#if 0
//4. ���ѭ������

typedef struct
{
	int *data; //������
	int front; //����ͷ
	int rear; //����β
	int size; //���д�С,���Ա�������Խ��  
	int flag; //��־�����Ƿ��� ,1 ��, 0 ����
			  //������ô˱�־λ�Ļ���������Ҫ����һλ��λ�����б�����Ƿ���
			  //������ͷָ����βָ�����һ��λ�ã���Ŀ�λ��ʱ��������
} MyCircularQueue;//��������ʵ��

//����
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

//����һ�����Դ��k��Ԫ�ص�ѭ������
MyCircularQueue* myCircularQueueCreate(int k)
{
	if (k < 0)
		return NULL;//���μ��
	
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (obj == NULL)
		return NULL;
	
	obj->data = (int*)malloc(k * sizeof(int));
	if (obj->data == NULL)
		return NULL;
	
	//�������ֵ
	obj->front = obj->rear = 0;
	obj->size = k;
	obj->flag = 0;
	return obj;
}

//��ѭ�����в���һ��Ԫ��,����ɹ������򷵻���
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
		return false;//�ж϶����Ƿ���

	obj->data[obj->rear] = value;//��������
	obj->rear = ((obj->rear + 1) < obj->size) ? (obj->rear + 1) : 0;
	//�ж��Ƿ񵽴�����߽磬��βָ��+1
	if (obj->rear == obj->front)
		//�ڲ�����Ԫ�غ���ָ��ָ����ͬ��ֻ�ж�����һ�����
		obj->flag = 1;//��������
	
	return true;
}

//��ѭ��������ɾ��һ��Ԫ��,����ɹ������򷵻���
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return false;//�ж϶����Ƿ��
	
	obj->data[obj->front] = 0;//�����ͷ������
	obj->front = ((obj->front + 1) < obj->size) ? (obj->front + 1) : 0;
	//�ж��Ƿ񵽴�����߽�,��ͷָ��+1
	obj->flag = 0;//ֻҪɾ����Ԫ�أ����оͲ�������
	return true;
}

//�Ӷ��׻�ȡԪ��
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	
	return obj->data[obj->front];
}

//��ȡ��βԪ��
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	
	//��βԪ����rear������ǰһ��λ�ã����rearΪ0�����βԪ������������һ��λ��
	//βָ��ָ�����ĩβ���ݵ���һ��λ�ã��˴���������Խ��
	if (obj->rear == 0)
		return obj->data[obj->size - 1];
	else
		return obj->data[obj->rear - 1];
}

//���ѭ�������Ƿ�Ϊ��
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	if (obj->flag == 0 && obj->front == obj->rear)
		//����δ�� �� ��βָ��ָ����ͬ����������п�
		return true;
	else
		return false;
}

//���ѭ�������Ƿ�����
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	if (obj->flag == 1)
		return true;
	else
		return false;
}

//�ͷ�ѭ������
void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->data);
	obj->data = NULL;
	free(obj);
	obj = NULL;
}
#endif