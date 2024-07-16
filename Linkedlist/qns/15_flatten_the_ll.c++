Node *flattenLinkedList(Node *head)
{
    // If head is null or there
    // is no next node, return head
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Recursively flatten the
    // rest of the linked list
    Node *mergedHead = flattenLinkedList(head->next);
    head = mergell(head, mergedHead);
    return head;
}

// merge the ll of parttion
ListNode *mergell(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }
    }
    if (l1)
        temp->next = l1;
    else
        temp->next = l2;
    return dummy->next;
}