//
//  PathSum.h
//  LeetCode
//
//  Created by Barry on 14-4-27.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__PathSum__
#define __LeetCode__PathSum__

#include <iostream>
#include "TreeNode.h"
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) {
            return false;
        }
        return dfs(root,sum,0);
    }
    bool dfs(TreeNode* root, int sum, int cur) {
        //如果走到空节点，则返回false
        //因为必须在叶子节点处有sum==cur才满足题目要求
        //此时空节点的父节点不一定为叶子节点，无需理会
        if (!root) {
            return false;
        }
        //如果走到叶子节点，此时找到了sum==cur，才能返回true
        //否则还是返回false
        if (!root->left&&!root->right) {
            cur += root->val;
            if (cur == sum) {
                return true;
            }
            else {
                return false;
            }
        }
        cur += root->val;
        //只要有一条路径找到了sum==cur就可以了
        return dfs(root->left, sum, cur)||dfs(root->right, sum, cur);
    }
};
#endif /* defined(__LeetCode__PathSum__) */
