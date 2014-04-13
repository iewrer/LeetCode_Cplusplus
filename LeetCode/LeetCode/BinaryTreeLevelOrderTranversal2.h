//
//  BinaryTreeLevelOrderTranversal2.h
//  LeetCode
//
//  Created by Barry on 14-4-13.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__BinaryTreeLevelOrderTranversal2__
#define __LeetCode__BinaryTreeLevelOrderTranversal2__

#include <iostream>
#include "TreeNode.h"
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    void tranverse(vector<TreeNode*>& node,vector<vector<int>>& result) {
        if (node.empty()) {
            return;
        }
        vector<int> val;
        //记录当前层次的节点数
        //因为插入下一层节点会改变容器中元素的数量
        int length = node.size();
        //遍历当前层次的所有节点：
        //1.将队首元素的值加入当前层次的值容器中
        //2.将其孩子放入队列末端
        //3.删除队首元素
        for (int i = 0; i < length; i++) {
            val.push_back(node.front()->val);
            if (node.front()->left!=NULL) {
                node.push_back(node.front()->left);
            }
            if (node.front()->right!=NULL) {
                node.push_back(node.front()->right);
            }
            node.erase(node.begin());
        }
        //在队首插入该层节点的值容器
        result.insert(result.begin(), val);
        //遍历下一层节点
        tranverse(node, result);
    }
    //遍历一遍所有节点，时间复杂度O(n)
    //需要记录当前层次的节点和节点值的两个容器，以及记录所有节点值的二维容器
    //额外空间O(3n)
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<TreeNode*> all;
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        all.push_back(root);
        tranverse(all, result);
        return result;
    }
};
#endif /* defined(__LeetCode__BinaryTreeLevelOrderTranversal2__) */
