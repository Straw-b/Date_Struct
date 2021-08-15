#include "Stack.h"

//int main()
//{
//	TestStack();
//	return 0;
//}





#if 0
//1. ����ƥ������
//����һ��ֻ���� '('��')'��'{'��'}'��'['��']'?���ַ������ж��ַ����Ƿ���Ч��
//��Ч�ַ��������㣺
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ע����ַ����ɱ���Ϊ����Ч�ַ�����


typedef char SDataType;

// ֧�ֶ�̬������ջ
typedef struct Stack
{
	SDataType* array;
	int capacity; // ����
	int size; // ջ��Ԫ�صĸ���--ջ��
}Stack;

// ��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (SDataType*)malloc(sizeof(SDataType) * 10);
	if (NULL == ps->array)
	{
		assert(0);
		return;
	}

	ps->capacity = 10;
	ps->size = 0;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}

//����
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		//1.�����¿ռ�
		SDataType* temp = (SDataType*)malloc(sizeof(SDataType)*ps->size * 2);
		if (temp == NULL)
		{
			assert(0);
			return;
		}

		//2.����Ԫ��
		memcpy(temp, ps->array, sizeof(SDataType)*ps->size);

		//3.�ͷžɿռ�
		free(ps->array);

		//4.ʹ���¿ռ�
		ps->array = temp;
		ps->capacity *= 2;
	}
}

// ��ջ��β��
void StackPush(Stack* ps, SDataType data)
{
	assert(ps);
	CheckCapacity(ps);//����Ƿ���Ҫ����
	ps->array[ps->size++] = data;
}

// ��ջ��βɾ
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
		return;

	ps->size--;
}

// ��ȡջ��Ԫ��
SDataType StackTop(Stack* ps)
{
	assert(!StackEmpty(ps));
	return ps->array[ps->size - 1];
}

// ��ȡջ����ЧԪ�صĸ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}

// ����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->array = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

bool isValid(char * s)
{
	Stack st;
	StackInit(&st);

	bool ret = true; //���б��
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
	{
		if ('(' == s[i] || '[' == s[i] || '{' == s[i])
			StackPush(&st, s[i]);
		else
		{
			//��ǰ�����������ţ���ջ�ǿյģ�û����֮��Ӧ��������
			if (StackEmpty(&st))
			{
				//return false; //����ջû�����٣������ڴ�й©
				ret = false;
				break;
			}

			//��ǰ������������
			char ch = StackTop(&st);

			//�õ�ǰ�����ż���Ƿ���ջ����������ƥ��
			if ((ch == '('&&')' == s[i]) || (ch == '['&&']' == s[i]) || (ch == '{'&&'}' == s[i]))
			{
				StackPop(&st);//�Ƴ�ջ��Ԫ��
				continue;
			}
			else
			{
				//return false; //����ջû�����٣������ڴ�й©
				ret = false;
				break;
			}
		}
	}

	//�����ű������Ŷ�
	if (!StackEmpty(&st))
		ret = false;

	StackDestroy(&st);
	return ret;
}






// ����������ӡ
void ReverseList(ListNode* head)
{
	ListNode* cur = head;
	Stack s;
	StackInit(&s);
	while (cur) //�����������ڵ�ĵ�ַ����ջ��
	{
		StackPush(cur);
		cur = cur->next;
	}

	while (!StackEmpty(&s))
	{
		cur = StackTop(&s);
		printf("%d", cur->data);
		StackPop(&s);
	}
}
#endif