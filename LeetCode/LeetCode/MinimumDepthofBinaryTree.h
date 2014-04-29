//
//  MinimumDepthofBinaryTree.h
//  LeetCode
//
//  Created by Barry on 14-4-29.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__MinimumDepthofBinaryTree__
#define __LeetCode__MinimumDepthofBinaryTree__

#include <iostream>
#include "TreeNode.h"
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        //根节点深度为1
        return minimumDepth(root,1);
    }
    int minimumDepth(TreeNode* root,int depth) {
        //如果是叶子节点，则返回当前深度
        if (!root->left&&!root->right) {
            return depth;
        }
        //如果有左/右孩子，则返回其最小深度，否则返回INT32_MAX
        //因为只有从根->叶子的路径算做深度
        //程序走到这里时必定至少有一个孩子
        int left = !root->left?INT32_MAX:minimumDepth(root->left, depth+1);
        int right = !root->right?INT32_MAX:minimumDepth(root->right, depth+1);
        //返回左右孩子深度的最小值
        return left<right?left:right;
    }
};
#endif /* defined(__LeetCode__MinimumDepthofBinaryTree__) */
