//
//  PopulatingNextRightPointersinEachNodeII.h
//  LeetCode
//
//  Created by Barry on 14-4-28.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__PopulatingNextRightPointersinEachNodeII__
#define __LeetCode__PopulatingNextRightPointersinEachNodeII__

#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode*> level;
        if (!root) {
            return;
        }
        level.push_back(root);
        levelTraverse(level);
    }
    void levelTraverse(vector<TreeLinkNode*>& level) {
        if (level.empty()) {
            return;
        }
        int size = level.size();
        //层次遍历之
        for (int i = 0; i < size; i++) {
            //如果没有遍历到该层最后一个元素，则将front和front后面的元素连起来
            if (i+1 < size) {
                level.front()->next = level.at(1);
            }
            //否则已到该层末尾，设为NULL
            else {
                level.front()->next = NULL;
            }
            //添加下一层元素
            if (level.front()->left) {
                level.push_back(level.front()->left);
            }
            if (level.front()->right) {
                level.push_back(level.front()->right);
            }
            level.erase(level.begin());
        }
        //层次遍历下一层
        levelTraverse(level);
    }
};
#endif /* defined(__LeetCode__PopulatingNextRightPointersinEachNodeII__) */
