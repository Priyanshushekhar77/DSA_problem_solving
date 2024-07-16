/*  https://leetcode.com/problems/sort-list/
Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
*/
// method1) put in additional array sort them and convert the array into ll;

// method 2)
//  findmiddle od ll
ListNode *findmiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
// merge the ll of parttion
ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *head1 = l1;
    ListNode *head2 = l2;
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

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *middle = findmiddle(head);
    ListNode *left = head;
    ListNode *right = middle->next;
    middle->next = NULL; // MAKING PARTITION
    ListNode *leftpart = sortList(left);
    ListNode *rightpart = sortList(right);
    return merge(leftpart, rightpart);
}