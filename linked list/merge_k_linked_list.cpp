struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  struct compare
  {
    bool operator()(ListNode *a, ListNode *b)
    {
      return a->val > b->val;
    }
  };

  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;

    // Insert initial nodes into minHeap
    for (ListNode *node : lists)
    {
      if (node)
      {
        minHeap.push(node);
      }
    }

    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;

    // Merge process
    while (!minHeap.empty())
    {
      ListNode *minNode = minHeap.top();
      minHeap.pop();
      tail->next = minNode;
      tail = minNode;
      if (minNode->next)
      {
        minHeap.push(minNode->next);
      }
    }

    return dummy->next;
  }
};
