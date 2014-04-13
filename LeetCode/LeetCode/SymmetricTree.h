//
//  SymmetricTree.h
//  LeetCode
//
//  Created by Barry on 14-4-5.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__SymmetricTree__
#define __LeetCode__SymmetricTree__

#include <iostream>
namespace SymmetricTree {
    /**
     * Definition for binary tree
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     * };
     */
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    class Solution {
    public:
        bool isSymmetric(TreeNode *root) {
            if (root==NULL) {
                return true;
            }
            return isSymmetricTree(root->left,root->right);
        }
        bool isSymmetricTree(TreeNode *left,TreeNode *right) {
            if (!left&&!right) {
                return true;
            }
            if (!left||!right) {
                return false;
            }
            if (left->val==right->val) {
                return isSymmetricTree(left->left,right->right)&&isSymmetricTree(left->right,right->left);
            }
            else {
                return false;
            }
        }
    };
}
#endif /* defined(__LeetCode__SymmetricTree__) */
