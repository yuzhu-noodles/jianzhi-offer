#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* Creat()
{
    //创建头结点
    ListNode* header = (ListNode*)malloc(sizeof(ListNode));
    ListNode* temp = header;
    //生成链表
    for (int i = 1; i <= 5; i++)
    {
        ListNode* p = (ListNode*)malloc(sizeof(ListNode));
        p->val = i;
        p->next = NULL;
        temp->next = p;
        temp = temp->next;
    }
    return header;
}

void Print(ListNode* header)
{
    ListNode* a = header;
    while (a->next != NULL)
    {
        a = a->next;
        cout << a->val <<" " ;
    }
    cout << endl;
}

ListNode* FindKthToTail(ListNode* pHead, int k)
{
    if (!pHead || k < 0)
    {
        return NULL;
    }
    ListNode* fast = pHead;
    ListNode* slow = pHead;
    while (k > 0)
    {
        if (!fast)
            return NULL;
        fast = fast->next;
        k--;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    ListNode* p = Creat();
    Print(p);
    int k = 0;
    cin >> k;
    cout << "倒数第" << k << "个结点：" << FindKthToTail(p, k)->val << endl;
	system("pause");
	return 0;
}