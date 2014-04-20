//
//  BinaryTreeLevelOrderTraversal.h
//  LeetCode
//
//  Created by Barry on 14-4-20.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__BinaryTreeLevelOrderTraversal__
#define __LeetCode__BinaryTreeLevelOrderTraversal__

#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        vector<TreeNode*> level;
        if (!root) {
            return result;
        }
        level.push_back(root);
        traverse(result, level);
        return result;
    }
    void traverse(vector<vector<int>>& result,vector<TreeNode*> level) {
        vector<int> tmp;
        if (level.empty()) {
            return;
        }
        //记录此时level的元素个数
        int length = level.size();
        //记得循环只需要遍历当前层次的元素！
        //由于会新增元素，所以需要使用固定长度进行遍历！
        for (int i = 0;i < length;i++) {
            TreeNode* tmpNode = level.front();
            tmp.push_back(tmpNode->val);
            if (tmpNode->left) {
                level.push_back(tmpNode->left);
            }
            if (tmpNode->right) {
                level.push_back(tmpNode->right);
            }
            level.erase(find(level.begin(), level.end(), tmpNode));
        }
        result.push_back(tmp);
        //遍历下一层
        traverse(result, level);
    }
};
#endif /* defined(__LeetCode__BinaryTreeLevelOrderTraversal__) */
