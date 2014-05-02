//
//  PathSumII.h
//  LeetCode
//
//  Created by Barry on 14-5-2.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__PathSumII__
#define __LeetCode__PathSumII__

#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        if (!root) {
            return result;
        }
        return findPaths(root,result,path,sum,0);
    }
    vector<vector<int>> findPaths(TreeNode *root,vector<vector<int>>& result,vector<int>& path,int sum,int cur) {
        //如果找到叶子节点了
        if (!root->left&&!root->right) {
            //累加当前节点值
            cur += root->val;
            //记录path
            path.push_back(root->val);
            //如果得到了sum值，则找到了一条符合条件的路径，加入之
            if (cur == sum) {
                result.push_back(path);
            }
            //否则直接返回
            return result;
        }
        //累加该节点值
        cur += root->val;
        //记录path
        path.push_back(root->val);
        //往左子树找路径
        //找完后回退path记录，将左子树记录抹去，准备找右子树
        if (root->left) {
            result = findPaths(root->left, result, path, sum, cur);
            path.pop_back();
        }
        //往右子树找路径
        //找完后回退path记录，将由子树记录抹去，准备回到root的上层节点
        if (root->right) {
            result = findPaths(root->right, result, path, sum, cur);
            path.pop_back();
        }
        return result;
    }
};
#endif /* defined(__LeetCode__PathSumII__) */
