//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//
//测试样例：
//1->2->2->1
//返回：true

#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
typedef struct ListNode
{
	int val;
	struct ListNode *next;
}SListNode;
bool isPalindrome(struct ListNode* head){
	if (head == NULL || head->next == NULL){//判断是否为空，或者只有一个值，如果是那么仍然是回文
		return true;
	}
	struct ListNode* mid1 = head;
	struct ListNode* tmp = head->next;
	while (tmp && tmp->next != NULL){
		mid1 = mid1->next;
		tmp = tmp->next->next;
	}
	struct ListNode* mid2 = mid1->next;
	struct ListNode* cur = mid2->next;
	while (cur != NULL){
		mid2->next = cur->next;
		cur->next = mid1->next;
		mid1->next = cur;
		cur = mid2->next;
	}
	mid2 = mid1->next;
	cur = head;
	while (mid2 != NULL){
		if (cur->val != mid2->val){
			return false;
		}
		cur = cur->next;
		mid2 = mid2->next;
	}
	return true;
}

void test()
{
	struct ListNode*n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 1;
	struct ListNode*n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n2->val = 2;
	struct ListNode*n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n3->val = 3;
	struct ListNode*n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n4->val = 4;
	struct ListNode*n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n5->val = 3;
	struct ListNode*n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n6->val = 2;
	struct ListNode*n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n7->val = 0;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = NULL;

	printf("是否为回文数：\n");
	//isPalindrome(n1)
	if (isPalindrome(n1)==true)
		printf("是\n");
	else
		printf("不是回文\n");

}

int main()
{
	test();
	system("pause");
	return 0;
}