#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *arraytoll(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int lenofll(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
bool searchinll(Node *head, int ele)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == ele)
            return 1;
        temp = temp->next;
    }
    return 0;
}
void print(Node *temp)
{
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *removehead(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
Node *removetail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}
Node *removekth(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    if (k == 1)
        removehead(head);
    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;//temp->next
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node *removeele(Node *head, int val)
{
    if (head == NULL)
        return NULL;
    if (head->data == val)
        removehead(head);
    Node *temp = head;
    Node *prev = NULL;
    while (temp)
    {
        if (temp->data == val)
        {
            prev->next = prev->next->next;//temp->next
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node *inserthead(Node *head, int val)
{
    Node *temp = new Node(val, head);
    // Node *temp=new Node(val);
    //temp-next=head;
    return temp;
}
Node *inserttail(Node *head, int val)
{
    if (head == NULL)
        return new Node(val);
    Node *temp = head;
    ;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *tail = new Node(val);
    temp->next = tail;
    return head;
}
Node *insertkth(Node *head, int k, int val)
{
    if (head == NULL)
    {
        if (k == 1)
            return inserthead(head, val);
        else
            return NULL;
    }
    if (k == 1)
        return inserthead(head, val);
    Node *temp = head;
    int cnt = 0;
    while (temp->next != NULL)
    {
        cnt++;
        if (cnt == k - 1)
        {
            Node *newnode = new Node(val, temp->next);
            //newnode->next=temp->next
            temp->next = newnode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
Node *insertbeforeele(Node *head, int ele, int val)
{
    if (head == NULL)
        return NULL;

    if (head->data == ele)
        return inserthead(head, val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == ele)
        {
            Node *newnode = new Node(val, temp->next);
            //newnode->temp->next;
            temp->next = newnode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {2, 3, 4, 5, 7, 8};
    Node *head = arraytoll(arr);
    // cout<<head->data<<" "<<head->next<<endl;
    print(head);
    int len = lenofll(head);
    cout << len << endl;
    bool find = searchinll(head, 4);
    cout << find << endl;
    // head=removehead(head);
    // print(head);
    //  head=removetail(head);
    // print(head);
    // head=removekth(head,3);
    // print(head);
    // head=removeele(head,5);
    // print(head);
    head = inserthead(head, 1);
    print(head);
    head = inserttail(head, 11);
    print(head);
    head = insertkth(head, 3, 17);
    print(head);
    head = insertbeforeele(head, 5, 18);
    print(head);

    return 0;
}