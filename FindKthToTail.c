//链表中倒数第K个节点
//1、循环两次，第一次计算出链表的长度，再计算出倒数的第K个结点length-k+1；
struct ListNode* FindKthToTail(struct ListNode* head, int k)
{
    int count = 1;
    struct ListNode* node = head;
    while (node->next != NULL)
    {
        node = node->next;
        count++;
    }
    struct ListNode* find = head;
    for (int i = 1; i < count - k + 1; i++)
    {
        find = find->next;
    }
    return find;
}

//2、循环一次，双指针，设置前后两个指针，间距为k-1,当前指针指向链表尾结点时，后指针刚好指向倒数第k个结点
struct ListNode* FindKthToTail(struct ListNode* head, int k)
{
    if (head == NULL || k == 0)
        return NULL;
    struct ListNode* p1 = head;
    struct ListNode* p2 = NULL;
    for (int i = 0; i < k - 1; i++)
    {
        if (p1->next != NULL)
            p1 = p1->next;
        else
            return NULL;
    }
    p2 = head;
    while (p1->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}