#include<iostream>
using namespace std;

typedef struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
}ListNode;

ListNode* Creat(int arr[], int len)
{
	ListNode* head = new ListNode;
	head->val = arr[0];
	head->next = NULL;
	ListNode* p = head;
	for (int i = 1; i < len; i++)
	{
		ListNode* temp = new ListNode;
		temp->val = arr[i];
		temp->next = NULL;
		p->next = temp;
		p = p->next;
	}
	return head;
}

void Print(ListNode* head)
{
	while (head != NULL)
	{
		cout << head->val << "-->";
		head = head->next;
	}
	cout <<"NULL"<< endl;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* ret = new ListNode;
	ListNode* p = ret;
	int sum = 0;
	bool flag = false;
	while (l1 != NULL || l2 != NULL)
	{
		sum = 0;
		if (l1 != NULL)
		{
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL)
		{
			sum += l2->val;
			l2 = l2->next;
		}
		if (flag)
			sum++;
		p->next = new ListNode(sum % 10);
		p = p->next;
		flag = sum >= 10 ? true : false;
	}
	if (flag)
		p->next = new ListNode(1);
	return ret->next;
}


int main()
{
	int arr1[3] = { 2,4,3 };
	int arr2[3] = { 5,6,4 };
	ListNode* L1 = Creat(arr1, 3);
	ListNode* L2 = Creat(arr2, 3);
	cout << "链表L1:";
	Print(L1);
	cout << "链表L2:";
	Print(L2);
	cout << "相加后：";
	ListNode* ret = addTwoNumbers(L1, L2);
	Print(ret);
	system("pause");
	return 0;
}