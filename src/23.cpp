#include <listnode.h>
#include <vector>
#include <queue>

using namespace std;
using namespace LeetCode;

class Solution {
public:
    struct cmp{
        bool operator()(const ListNode* a, const ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = nullptr;
        ListNode* itr = nullptr;
        priority_queue<ListNode*, vector<ListNode*>, cmp > q;
        for (int i = 0; i < lists.size(); ++i){
            ListNode* list = lists[i];
            if (list != nullptr) {
                q.push(list);
            }
        }
        if (!q.empty()){
            root = q.top();
            q.pop();
            itr = root;
            if (root->next != nullptr) {
                q.push(root->next);
            }
        }
        while (!q.empty())
        {
            ListNode* tmp = q.top();
            q.pop();
            itr->next = tmp;
            itr = tmp;
            if (tmp->next != nullptr) {
                q.push(tmp->next);
            }
        }
        if (itr != nullptr)
            itr->next = nullptr;
        return root;
    }
};

int main() {
    auto s = Solution();
    auto real = new ListNode(1);
    real->next = new ListNode(1);
    real->next->next = new ListNode(2);
    real->next->next->next = new ListNode(2);
    vector<ListNode*> input;
    auto a = new ListNode(1);
    a->next = new ListNode(2);
    auto b = new ListNode(1);
    b->next = new ListNode(2);
    input.push_back(a);
    input.push_back(b);
    auto test = s.mergeKLists(input);
    assert(is_same_list(real, test));
    return 0;
}