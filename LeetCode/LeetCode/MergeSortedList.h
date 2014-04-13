//
//  MergeSortedList.h
//  LeetCode
//
//  Created by Barry on 14-4-2.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__MergeSortedList__
#define __LeetCode__MergeSortedList__

#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *longer,*shorter,*h1=l1,*h2=l2;
        //边界条件
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        //找到哪个是更短的链表
        while (true) {
            if (h1 == NULL) {
                shorter = l1;
                longer = l2;
                break;
            }
            if (h2 == NULL) {
                shorter = l2;
                longer = l1;
                break;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        //记录前驱节点（其实pre1没有用处）
        ListNode *pre1 = shorter,*pre2 = longer;
        //记录头节点（其实h2没有用处）
        h1 = longer,h2 = shorter;
        //处理头结点
        if (shorter->val>longer->val) {
            longer = longer->next;
        }
        else {
            ListNode* temp = shorter;
            shorter = shorter->next;
            temp->next = longer;
            //重定向头结点（此时是因为longer头结点变为被插入的shorter节点，所以需要重置）
            h1 = temp;
            //将当前前驱指向被插入的节点，即前驱后移
            pre2 = temp;
        }
        //处理其他节点
        while (shorter!=NULL) {
            //shorter节点值比longer大时，longer向后移动直到找到合适的让shorter节点插入的位置
            while (longer!=NULL&&shorter->val>longer->val) {
                pre2 = longer;
                longer = longer->next;
            }
            if (longer!=NULL) {
                //若找到合适的插入位置，则将shorter链表的节点插入到longer中去
                ListNode* temp = shorter;
                //shorter链表向后移动
                shorter = shorter->next;
                //被摘下来的待插入节点指向longer链表的当前节点
                temp->next = longer;
                //将longer中当前前驱的后继指向待插入节点
                pre2->next = temp;
                //将当前前驱后移，指向被插入的节点
                pre2 = temp;
                //                pre1->next = shorter->next;
                //                shorter->next = longer;
                //                pre2->next = shorter;
            }
            else {
                pre2->next = shorter;
                break;
            }
        }
        //返回longer链表的头结点
        return h1;
    }
};
#endif /* defined(__LeetCode__MergeSortedList__) */
