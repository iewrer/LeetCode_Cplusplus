//
//  LinkedListCycle.h
//  LeetCode
//
//  Created by Barry on 14-4-18.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__LinkedListCycle__
#define __LeetCode__LinkedListCycle__

#include <iostream>
#include "TreeNode.h"
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* i = head;
        ListNode* j = head;
        if (!head) {
            return NULL;
        }
        if (!head->next) {
            return NULL;
        }
        i = i->next;
        j = j->next->next;
        while (j&&j->next&&i!=j) {
            i = i->next;
            j = j->next->next;
        }
        if (!j||!j->next) {
            return NULL;
        }
        else {
            ListNode* m = i;
            ListNode* n = head;
            while (m!=n) {
                m = m->next;
                n = n->next;
            }
            return m;
        }
    }
};
#endif /* defined(__LeetCode__LinkedListCycle__) */
