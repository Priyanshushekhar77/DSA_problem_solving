/*2<->2<->10<->8<->4<->2<->5<->2
2
Output:
10<->8<->4<->5
Explanation:
All Occurences of 2 have been deleted.

Example2:

Input:
9<->1<->3<->4<->5<->1<->8<->4
9
Output:
1<->3<->4<->5<->1<->8<->4
Explanation:
All Occurences of 9 have been deleted.
*/
void deleteAllOccurOfX(struct Node **head_ref, int x)
{
    Node *temp = *head_ref;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            if (temp == *head_ref)
                *head_ref = temp->next;
            Node *prevnode = temp->prev;
            Node *nextnode = temp->next;
            if (nextnode)
                nextnode->prev = prevnode;
            if (prevnode)
                prevnode->next = nextnode;
            free(temp);
            temp = nextnode;
        }
        else
            temp = temp->next;
    }
}