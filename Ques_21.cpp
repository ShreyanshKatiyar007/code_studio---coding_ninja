/*You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.
Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k', then the last group of nodes should remain unchanged.*/

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *kReverse(Node *head, int k)
{
    // base call
    if (head == NULL)
    {
        return NULL;
    }

    // Check if there are at least k nodes left in the list
    Node *temp = head;
    int count = 0;
    while (temp != NULL && count < k)
    {
        temp = temp->next;
        count++;
    }

    // If there are less than k nodes, return the head without reversing
    if (count < k)
    {
        return head;
    }

    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    count = 0;

    // Reverse the first k nodes
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Recursively reverse the remaining part and link it to the current head
    if (next != NULL)
    {
        head->next = kReverse(next, k);
    }

    return prev;
}
