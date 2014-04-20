//
//  main.cpp
//  LeetCode
//
//  Created by Barry on 14-3-30.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "BinaryTreePostorderTraversal .h"
#include "TreeNode.h"

using namespace std;
int main(int argc, const char * argv[])
{
    Solution s;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    s.postorderTraversal(root);
//    cout << (unsigned int)INT64_MAX << "\n";
//    cout << (unsigned int)-1 << "\n";
}

