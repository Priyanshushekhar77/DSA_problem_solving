/*Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]*/

// method 1-> find length of ll than determine (length-n)pos from starting and delete it


// method 2 slow and fast pointer
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // nth node from end=(l-n+1) from start
    if (head == NULL)
        return NULL;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *slow = dummy;
    ListNode *fast = dummy;
    // fast ptr reach to nth pos
    for (int i = 0; i <= n; i++)
    {
        if (fast == NULL)
            return NULL;
        fast = fast->next;
    }
    // slow reach at (length-n)th pos and fast reach at length pos
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode *delnode = slow->next;
    slow->next = slow->next->next;
    delete (delnode);
    return dummy->next;
}