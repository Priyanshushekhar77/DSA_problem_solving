/*n = 6
1<->1<->1<->2<->3<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurance of node with value 1 is
retained, rest nodes with value = 1 are deleted.
Example 2:

Input:
n = 7
1<->2<->2<->3<->3<->4<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurance of nodes with values 2,3 and 4 are
retained, rest repeating nodes are deleted.*/

Node *removeDuplicates(struct Node *head)
{
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        Node *nextnode = temp->next;
        while (nextnode != NULL && nextnode->data == temp->data)
        {
            Node *duplicate = nextnode;
            nextnode = nextnode->next;
            free(duplicate);
        }
        temp->next = nextnode;
        if (nextnode)
            nextnode->prev = temp;
        temp = temp->next;
    }
    return head;
}