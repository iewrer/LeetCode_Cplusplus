//
//  SumRoottoLeafNumbers.h
//  LeetCode
//
//  Created by Barry on 14-4-29.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__SumRoottoLeafNumbers__
#define __LeetCode__SumRoottoLeafNumbers__

#include <iostream>
#include <math.h>
#include "TreeNode.h"
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return SumRoottoLeafNumbers(root,0);
    }
    //计算时进行累加，每次将之前的值*10，然后加上本层节点的值，即为到该层该节点时所代表的十进制值
    int SumRoottoLeafNumbers(TreeNode *root,int sum) {
        //只有叶子节点才返回最后的累加值
        if (!root->left&&!root->right) {
            return sum*10+root->val;
        }
        //如果没有左/右孩子，则左/右孩子提供的值为0
        int left = 0,right = 0;
        //计算该层该节点代表的值
        sum = sum*10+root->val;
        if (root->left) {
            left = SumRoottoLeafNumbers(root->left, sum);
        }
        if (root->right) {
            right = SumRoottoLeafNumbers(root->right, sum);
        }
        //将左右孩子代表的值加起来，即为所求
        return left+right;
    }
};
#endif /* defined(__LeetCode__SumRoottoLeafNumbers__) */
