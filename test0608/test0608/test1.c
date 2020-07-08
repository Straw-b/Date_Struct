//4. ���ѭ������һ

typedef struct
{
	int *data;//������
	int front;//����ͷ
	int rear;//����β
	int size;//���д�С,���Ա�������Խ��  
	int flag;//��־�����Ƿ��� ,1 ��, 0 ����
	//������ô˱�־λ�Ļ���������Ҫ����һλ��λ�����б�����Ƿ���
	//������ͷָ����βָ�����һ��λ�ã���Ŀ�λ��ʱ��������
} MyCircularQueue;//��������ʵ��

//��������
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

//����һ�����Դ��k��Ԫ�ص�ѭ������
MyCircularQueue* myCircularQueueCreate(int k)
{
	if (k < 0)
	{
		//���μ��
		return NULL;
	}
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (obj == NULL)
	{
		return NULL;
	}
	obj->data = (int*)malloc(k * sizeof(int));
	if (obj->data == NULL)
	{
		return NULL;
	}
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
	{
		//�ж϶����Ƿ���
		return false;
	}
	obj->data[obj->rear] = value;//��������
	obj->rear = ((obj->rear + 1) < obj->size) ? (obj->rear + 1) : 0;
	//�ж��Ƿ񵽴�����߽磬��βָ��+1
	if (obj->rear == obj->front)
	{
		//�ڲ�����Ԫ�غ���ָ��ָ����ͬ��ֻ�ж�����һ�����
		obj->flag = 1;//��������
	}
	return true;
}

//��ѭ��������ɾ��һ��Ԫ��,����ɹ������򷵻���
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		//�ж϶����Ƿ��
		return false;
	}
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
	{
		return -1;
	}
	return obj->data[obj->front];
}

//��ȡ��βԪ��
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	int i = (obj->rear == 0) ? (obj->size - 1) : (obj->rear - 1);
	//βָ��ָ�����ĩβ���ݵ���һ��λ�ã��˴���������Խ��
	return obj->data[i];
}

//���ѭ�������Ƿ�Ϊ��
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	if (obj->flag == 0 && obj->front == obj->rear)
	{
		//����δ�� �� ��βָ��ָ����ͬ����������п�
		return true;
	}
	else
	{
		return false;
	}
}

//���ѭ�������Ƿ�����
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	if (obj->flag == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->data);
	obj->data = NULL;
	free(obj);
	obj = NULL;
}





////////////////////////////////////////////////////////////////
//4. ���ѭ�����ж�

//����˼·��
//ͨ��һ����������ʵ��ѭ������
//��ӣ�����Ҫ�ж϶����Ƿ��������ٽ�����ӵĲ�������Ӳ�����Ҫ��������ѭ�������⣬������Խ�磬��Ҫ���������Сֵ
//���ӣ�����Ҫ�ж϶����Ƿ�Ϊ�գ��ٽ��г��Ӳ���������Ҳ��Ҫ��������ѭ��������
//�пգ� ��ͷ == ��β
//������ ��β + 1 == ��ͷ

typedef struct {
	int* queue;
	int front;
	int rear;
	int k
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
//����һ�����Դ��k��Ԫ�ص�ѭ�����У�ʵ������Ŀռ�Ϊk + 1
MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* pcq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	pcq->queue = (int*)malloc(sizeof(int)*(k + 1));
	pcq->front = 0;
	pcq->rear = 0;
	pcq->k = k;

	return pcq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	//����
	if ((obj->rear + 1) % (obj->k + 1) == obj->front)
	{
		return false;
	}
	//��β���
	obj->queue[obj->rear++] = value;
	//�����βԽ�磬����Ϊ��Сֵ
	if (obj->rear == obj->k + 1)
		obj->rear = 0;

	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	//�п�
	if (obj->front == obj->rear)
		return false;
	//��ͷ����
	++obj->front;
	//�����ͷԽ�磬����Ϊ��Сֵ
	if (obj->front == obj->k + 1)
		obj->front = 0;

	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return -1;
	else
		return obj->queue[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return -1;
	//��βԪ����rear������ǰһ��λ�ã����rearΪ0��
	//���βԪ������������һ��λ��
	if (obj->rear == 0)
		return obj->queue[obj->k];
	else
		return obj->queue[obj->rear - 1];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->queue);
	free(obj);
}

