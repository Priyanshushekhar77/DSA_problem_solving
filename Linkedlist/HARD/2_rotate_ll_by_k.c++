/* Example 1:
Input:
    head = [1,2,3,4,5]
    k = 2
Output:
 head = [4,5,1,2,3]
Explanation:
 We have to rotate the list to the right twice.

 steps->1.Calculate the length of the list.
2.Connect the last node to the first node, converting it to a circular linked list.
3.traverse till temp= (lenth-k%length) of the list  and than make new head of ll is head=temp->next and disconnect the connection temp->next=NULL
*/

ListNode *find(ListNode *temp, int k)
{
    int cnt = 1;
    while (temp != NULL)
    {
        if (cnt == k)
            return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || k == 0)
        return head;
    ListNode *temp = head;
    int len = 1;
    // FIND LENGTH OF LL
    while (temp->next != NULL)
    {
        len++;
        temp = temp->next;
    }
    // IF REM IS 0
    if (k % len == 0)
        return head;
    // FIND ROTATION PLACE
    k = k % len;
    // MAKE LL TO CIRCULAR-> JOINING END PT WITH STARTING PT
    temp->next = head;
    // finding node of rotation point
    ListNode *newstart = find(head, len - k);
    // making new connection with head
    head = newstart->next;
    // breaking connection
    newstart->next = NULL;
    return head;
}