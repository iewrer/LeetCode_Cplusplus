//
//  BinaryTreePostorderTraversal .h
//  LeetCode
//
//  Created by Barry on 14-4-20.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__BinaryTreePostorderTraversal___
#define __LeetCode__BinaryTreePostorderTraversal___

#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> stack;
        vector<int> result;
        if (!root) {
            return result;
        }
        stack.push(root);
        while (!stack.empty()) {
            TreeNode* now = stack.top();
            //如果栈顶元素没有左右孩子了，则弹出并访问之
            if (!now->left&&!now->right) {
                result.push_back(now->val);
                stack.pop();
            }
            //否则
            else {
                //如果栈顶元素有左孩子
                //将栈顶元素的左孩子取出，标记栈顶元素的左孩子为空
                //持续将左孩子入栈，直到没有左孩子为止
                TreeNode* next = now->left;
                if (next) {
                    now->left = NULL;
                    stack.pop();
                    stack.push(now);
                    while (next) {
                        //每次将next入栈时都要记得修改它的左孩子为NULL
                        //因此此时我们已经开始访问next的左子树部分了
                        //注意这里的指针操作！
                        TreeNode *tmp = next;
                        next = next->left;
                        tmp->left = NULL;
                        stack.push(tmp);
                    }
                }
                //如果此时栈顶元素有右孩子
                //那么取出栈顶，将其右孩子取出之后赋值为空，再将右孩子入栈
                now = stack.top();
                next = now->right;
                if (next) {
                    now->right = NULL;
                    stack.pop();
                    stack.push(now);
                    stack.push(next);
                }
            }
        }
        return result;
    }
};
#endif /* defined(__LeetCode__BinaryTreePostorderTraversal___) */
