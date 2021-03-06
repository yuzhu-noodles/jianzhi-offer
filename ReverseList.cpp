#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

//创建链表
ListNode* Creat()
{
    ListNode* temp;  //头指针
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = 1;
    node->next = NULL;
    temp = node;
    //生成链表
    for (int i = 2; i <= 5; i++)
    {
        ListNode* p = (ListNode*)malloc(sizeof(ListNode));
        p->val = i;
        p->next = NULL;
        temp->next = p;
        temp = temp->next;
    }
    return node;
}
void Print(ListNode* header)
{
    ListNode* a = header;
    while (a != NULL)
    {
        cout << a->val << " ";
        a = a->next;
    }
    cout << endl;
}

//反转链表
ListNode* ReverseList(ListNode* pHead)
{
    if (pHead == NULL || pHead->next == NULL)
    {
        return pHead;
    }
    ListNode* node = pHead;  //当前结点
    ListNode* pre = NULL;   //前结点
    ListNode* next = NULL;  //后结点
    ListNode* NewHead = NULL; //新头结点

    //反转
    while (node != NULL)
    {
        next = node->next;
        if (next == NULL)
        {
            NewHead = node;
        }
        node->next = pre;
        pre = node;
        node = next;
    }
    return NewHead;
}
int main()
{
    ListNode* p = Creat();
    cout << "原链表:";
    Print(p);
    cout << endl;
    ListNode* new_p = ReverseList(p);
    cout << "反转后的链表：";
    Print(new_p);
    cout << endl;
	system("pause");
	return 0;
}