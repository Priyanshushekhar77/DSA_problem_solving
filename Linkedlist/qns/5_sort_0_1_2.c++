/*Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Example 1:

Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.*/

// method 1-> data replacement in ll by storeing cnt of 0,1,2;

// method2 -> keep track of 0,1,2

Node *segregate(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    Node *dummyZero = new Node(-1); // Dummy node for 0
    Node *dummyOne = new Node(-1);  // Dummy node for 1
    Node *dummyTwo = new Node(-1);  // Dummy node for 2

    Node *zero = dummyZero;
    Node *one = dummyOne;
    Node *two = dummyTwo;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        { // temp->data == 2
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    // Connect the lists: 0 -> 1 -> 2
    one->next = dummyTwo->next;  // Connect 1's list to 2's list
    zero->next = dummyOne->next; // Connect 0's list to 1's list
    two->next = NULL;            // Terminate the 2's list

    // Head of the segregated list will be the next of dummyZero
    head = dummyZero->next;

    // Free dummy nodes
    delete dummyZero;
    delete dummyOne;
    delete dummyTwo;

    return head;
}