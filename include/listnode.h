/**
 * 
 * Copyright (c) 2019 NUAA Jiang Yang
 * 
 * @file
 * @author   Jiang Yang (pokerpoke@qq.com)
 * @date     2018-08
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-08-03
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#ifndef _LISTNODE_H_
#define _LISTNODE_H_

#include <iostream>
#include <vector>
#include <initializer_list>

namespace LeetCode
{
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *p = nullptr) : val(x), next(nullptr){};
};

void print_list(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val;
        if (head->next != nullptr)
            std::cout << "->";
        head = head->next;
    }
    std::cout << std::endl;
}

bool is_same_list(ListNode *l1, ListNode *l2)
{
    while (l1 != nullptr && l2 != nullptr && l1->val == l2->val)
    {
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == l2 ? true : false;
}
} // namespace LeetCode

#endif //!_LISTNODE_H_