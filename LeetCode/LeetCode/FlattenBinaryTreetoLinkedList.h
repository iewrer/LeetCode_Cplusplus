//
//  FlattenBinaryTreetoLinkedList.h
//  LeetCode
//
//  Created by Barry on 14-5-21.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__FlattenBinaryTreetoLinkedList__
#define __LeetCode__FlattenBinaryTreetoLinkedList__

#include <iostream>
#include "TreeNode.h"

class Solution {
public:
    void flatten(TreeNode *root) {
        flattenTree(root,NULL);
    }
    TreeNode* flattenTree(TreeNode* root,TreeNode* tail) {
        //如果根节点为空，则返回tail作为此时子树的根指针
        //如果一开始root即为空，则返回NULL
        if (!root) {
            return tail;
        }
        //先flatten右子树，并把tail作为右子树的右孩子（即添加在其后面）
        //然后再返回此时右子树的根节点
        //此时flatten左子树，并将右子树的根节点作为flatten过的左子树的右孩子
        root->right = flattenTree(root->left, flattenTree(root->right, tail));
        //将左孩子悬空
        root->left = NULL;
        //返回此时根节点
        return root;
    }
};
#endif /* defined(__LeetCode__FlattenBinaryTreetoLinkedList__) */
