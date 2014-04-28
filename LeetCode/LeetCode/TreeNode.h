//
//  TreeNode.h
//  LeetCode
//
//  Created by Barry on 14-4-5.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef LeetCode_TreeNode_h
#define LeetCode_TreeNode_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
#endif
