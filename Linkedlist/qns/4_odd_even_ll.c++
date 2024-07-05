/*Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
*/

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *odd = head;
    ListNode *oddhead = head;
    ListNode *even = head->next;
    ListNode *evenhead = head->next;
    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenhead;
    return oddhead;
}