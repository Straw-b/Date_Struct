#pragma once

//��ͷ+˫��+ѭ������
typedef int DLDataType;

typedef struct DHCListNode
{
	DLDataType data;
	struct DHCListNode* next;//ָ��ǰ�ڵ����һ���ڵ�
	struct DHCListNode* prev;//ָ��ǰ�ڵ��ǰһ���ڵ�
}DHCLNode;


//��ʼ��--��ͷ�ڵ㴴����
DHCLNode* DHCListInit();

//β��
void DHCListPushBack(DHCLNode* pHead, DLDataType data);
//βɾ
void DHCListPopBack(DHCLNode* pHead);

//ͷ��
void DHCListPushFront(DHCLNode* pHead, DLDataType data);
//ͷɾ
void DHCListPopFront(DHCLNode* pHead);

//����λ�ò���
void DHCListInsert(DHCLNode* pos, DLDataType data);
//����λ��ɾ��
void DHCListErase(DHCLNode* pos);

//����
DHCLNode* DHCListFind(DHCLNode* pHead, DLDataType data);

int DHCListSize(DHCLNode* pHead);
int DHCListEmpty(DHCLNode* pHead);
void DHCListClear(DHCLNode* pHead);
void DHCListDestroy(DHCLNode* pHead);

void TestDHCList();