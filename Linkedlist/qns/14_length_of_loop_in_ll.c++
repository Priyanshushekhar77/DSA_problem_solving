// https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop

int findlength(Node *slow, Node *fast)
{
    int cnt = 1;
    fast = fast->next;
    while (slow != fast)
    {
        cnt++;
        fast = fast->next;
    }
    return cnt;
}
int countNodesinLoop(struct Node *head)
{

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        // detects a cycle
        if (slow == fast)
        {
            return findlength(slow, fast);
        }
    }
    return 0;
}