//
//  BalancedBinaryTree.h
//  LeetCode
//
//  Created by Barry on 14-4-5.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__BalancedBinaryTree__
#define __LeetCode__BalancedBinaryTree__

#include <iostream>
#include "TreeNode.h"
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (isBalancedTree(root)<0) {
            return false;
        }
        return true;
    }
    int isBalancedTree(TreeNode *root) {
        if (!root) {
            return 0;
        }
        if (!root->left&&!root->right) {
            return 1;
        }
        int left = isBalancedTree(root->left);
        int right = isBalancedTree(root->right);
        if(left<0||right<0) {
            return -1;
        }
        int differ = left-right;
        if (differ>1||differ<-1) {
            return -1;
        }
        else {
            return left>right?left+1:right+1;
        }
    }
};
#endif /* defined(__LeetCode__BalancedBinaryTree__) */
