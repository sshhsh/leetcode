#include <listnode.h>
#include <vector>
#include <queue>

using namespace std;
using namespace LeetCode;

class Solution {
public:
    ListNode* nextN(ListNode* head, int k) {
        for (int i = 0; i < k; ++i){
            if(head != nullptr) {
                head = head->next;
            }
            else {
                return nullptr;
            }
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;

        ListNode *start = nullptr;
        ListNode *a = nullptr;
        ListNode *b = nullptr;
        ListNode *end = nullptr;
        start = fakeHead;
        end = nextN(start, k);
        while (end != nullptr)
        {
            a = start->next;
            b = a->next;
            a->next = end->next;
            start->next = end;
            end = a;
            for (int i = 0; i < k - 1; ++i) {
                ListNode* tmp = b->next;
                b->next = a;
                a = b;
                b = tmp;
            }
            start = end;
            end = nextN(start, k);
        }
        ListNode* res = fakeHead->next;
        delete fakeHead;
        return res;
    }
};

int main() {
    auto s = Solution();
    auto real = new ListNode(1);
    real->next = new ListNode(2);
    real->next->next = new ListNode(3);
    real->next->next->next = new ListNode(4);
    auto in = new ListNode(2);
    in->next = new ListNode(1);
    in->next->next = new ListNode(4);
    in->next->next->next = new ListNode(3);
    auto test = s.reverseKGroup(in, 2);
    assert(is_same_list(real, test));
    return 0;
}