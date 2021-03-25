#include<iostream>
using namespace std;

typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

ListNode* CreatList()
{
	ListNode* p = NULL;
	ListNode* temp = new ListNode;
	cout << "请输入节点：";
	int num1;
	cin >> num1;
	temp->val = num1;
	temp->next = NULL;
	p = temp;
	int num2 = 0;
	while (num2 != -1)
	{
		ListNode* P = new ListNode;
		cin >> num2;
		P->val = num2;
		P->next = NULL;
		temp->next = P;
		temp = temp->next;
	}
	return p;
}

void PrintList(ListNode* head)
{
	if (!head)
		return;
	while (head->next != NULL)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << endl;
}

ListNode* deleteDuplication(ListNode* pHead)
{
	if (!pHead)
		return pHead;
	ListNode* left = NULL;
	ListNode* temp = pHead;
	ListNode* right = NULL;
	while (temp)
	{
		if (temp->next != NULL && temp->val == temp->next->val)
		{
			right = temp->next;
			while (right != NULL && right->next != NULL && right->next->val == temp->val)
			{
				right = right->next;
			}
			if (temp == pHead)
				pHead = right->next;
			else
				left->next = right->next;
			temp = right->next;
		}
		else
		{
			left = temp;
			temp = temp->next;
		}
	}
	return pHead;
}

int main()
{
	ListNode* head = CreatList();
	cout << "删除前：";
	PrintList(head);
	cout << "删除后：";
	ListNode* ret = deleteDuplication(head);
	PrintList(head);
	system("pause");
	return 0;
}