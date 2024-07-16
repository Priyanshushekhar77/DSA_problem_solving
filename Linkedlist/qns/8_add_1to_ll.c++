/*Input: LinkedList: 4->5->6
Output: 457
Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457.
Input: LinkedList: 1->2->3
Output: 124
Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124.

*/

// reversell
Node *reversell(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *prev = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        Node *curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
    }
    return prev;
}
Node *addOne(Node *head)
{
    // 1. reverse the ll
    // 2. add the 1 to head
    // 3. reverse the ll after add oprn
    // 4. if carry present than joins it to head and return newhead
    head = reversell(head);
    Node *temp = head;
    int carry = 1;
    while (temp != NULL)
    {
        temp->data += carry;
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            temp->data = 0;
            carry = 1;
            // if (temp->next == nullptr)
            // {
            //     temp->next = new Node(0);
            // }
        }
        temp = temp->next;
    }

    if (carry == 1)
    {
        head = reversell(head);
        Node *newhead = new Node(1);
        newhead->next = head;
        return newhead;
    }
    // if carry not present reversell and return the head
    head = reversell(head);
    return head;
}