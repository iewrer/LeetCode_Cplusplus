//
//  removeNthFromEnd.h
//  LeetCode
//
//  Created by Barry on 14-4-28.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__removeNthFromEnd__
#define __LeetCode__removeNthFromEnd__

#include <iostream>
#include "TreeNode.h"
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        //用两个指针，first先走n步，然后两个指针一起后移，以获得n的间隔差距
        ListNode *first = head;
        ListNode *second = head;
        //记录second指针的前驱，取下second指向节点用
        ListNode *pre = head;
        //边界条件
        if (!head||!head->next) {
            return NULL;
        }
        int step = n;
        //first先走n步
        while (step > 0) {
            first = first->next;
            step--;
        }
        //一起后移，直到first走到表尾，此时second即指向倒数第n个节点
        while (first) {
            pre = second;
            first = first->next;
            second = second->next;
        }
        //取下倒数第n个节点
        pre->next = second->next;
        //如果pre==second，说明此时second指向头部，取下头结点即可
        if (pre == second) {
            head = head->next;
        }
        return head;
    }
};
#endif /* defined(__LeetCode__removeNthFromEnd__) */
