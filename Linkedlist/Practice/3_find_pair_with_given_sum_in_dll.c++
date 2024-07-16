/*1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
target = 7
Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs
(1, 6) and (2,5) with sum 7.*/

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{

    vector<pair<int, int>> ans;
    Node *front = head, *back = head;

    // Move back pointer to end of LL
    while (back->next)
        back = back->next; // end point

    while (front->data < back->data)
    {

        int sum = front->data + back->data;

        if (sum == target)
        {
            ans.push_back({front->data, back->data});
            front = front->next;
            back = back->prev;
        }

        else if (sum > target)
        {
            back = back->prev;
        }
        else
        { // sum<target
            front = front->next;
        }
    }

    return ans;
}