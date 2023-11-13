#include <gtest/gtest.h>
#include <cassert>
#include "src/code_practise/leetcode/cpp/lib/slist.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy;
        ListNode *head = &dummy;
        
        while (carry || l1 || l2) {
            int v = carry;
            if (l1) {
                v += l1->val; l1 = l1->next;
            }
            if (l2) {
                v += l2->val; l2 = l2->next;
            }
            head->next = new ListNode(v%10);
            carry = v / 10;
            head = head->next;
        }
        
        return dummy.next;
    }
};

TEST(Basic, BasicAssertions) {
    Solution s;

    ListNode l1 = ListNode(1);
    ListNode l2 = ListNode(2);

    ListNode *rst = s.addTwoNumbers(&l1, &l2);

    EXPECT_EQ(rst->val, 3);
}
