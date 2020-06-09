#pragma once

//带头+双向+循环链表
typedef int DLDataType;

typedef struct DHCListNode
{
	DLDataType data;
	struct DHCListNode* next;//指向当前节点的下一个节点
	struct DHCListNode* prev;//指向当前节点的前一个节点
}DHCLNode;


//初始化--将头节点创建好
DHCLNode* DHCListInit();

//尾插
void DHCListPushBack(DHCLNode* pHead, DLDataType data);
//尾删
void DHCListPopBack(DHCLNode* pHead);

//头插
void DHCListPushFront(DHCLNode* pHead, DLDataType data);
//头删
void DHCListPopFront(DHCLNode* pHead);

//任意位置插入
void DHCListInsert(DHCLNode* pos, DLDataType data);
//任意位置删除
void DHCListErase(DHCLNode* pos);

//查找
DHCLNode* DHCListFind(DHCLNode* pHead, DLDataType data);

int DHCListSize(DHCLNode* pHead);
int DHCListEmpty(DHCLNode* pHead);
void DHCListClear(DHCLNode* pHead);
void DHCListDestroy(DHCLNode* pHead);

void TestDHCList();