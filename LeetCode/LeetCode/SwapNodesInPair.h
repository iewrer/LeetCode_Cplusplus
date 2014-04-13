//
//  SwapNodesInPair.h
//  LeetCode
//
//  Created by Barry on 14-4-10.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__SwapNodesInPair__
#define __LeetCode__SwapNodesInPair__

#include <iostream>
#include "TreeNode.h"

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        if(head->next==NULL) {
            return head;
        }
        ListNode *p = new ListNode(-1);
        p->next = head;
        ListNode *pre = p;
        //如果已走到头或者剩下一个（即还剩一个节点，无法调换）
        while (head != NULL && head->next != NULL) {
            //交换相邻节点
            //记得修改前驱的指向！
            ListNode *tmp = head->next;
            head->next = tmp->next;
            tmp->next = head;
            pre->next = tmp;
            //往后走
            pre = head;
            head = head->next;
        }
        return p->next;
    }
};
#endif /* defined(__LeetCode__SwapNodesInPair__) */
