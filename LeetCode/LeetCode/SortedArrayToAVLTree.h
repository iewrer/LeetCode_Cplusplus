//
//  SortedArrayToAVLTree.h
//  LeetCode
//
//  Created by Barry on 14-4-8.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__SortedArrayToAVLTree__
#define __LeetCode__SortedArrayToAVLTree__

#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        TreeNode *root = insertBST(0,num.size(),num);
        return root;
    }
    TreeNode *insertBST(size_t low,size_t high,const vector<int>& num) {
        if (low == high) {
            return NULL;
        }
        if (high-low==1) {
            TreeNode* leaf = new TreeNode(num.at(low));
            return leaf;
        }
        size_t mid = (low + high)/2;
        TreeNode* midNode = new TreeNode(num.at(mid));
        midNode->left = insertBST(low, mid, num);
        midNode->right = insertBST(mid+1, high, num);
        return midNode;
    }
    /*
     *建立一颗平衡二叉树——AVL树
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.empty()) {
            return NULL;
        }
        TreeNode *root = NULL;
        for (vector<int>::iterator it = num.begin(); it != num.end(); ++it) {
            root = insertAVL((*it),root);
        }
        return root;
    }
    TreeNode *insertAVL(int val,TreeNode* root) {
        if (root == NULL) {
            root = new TreeNode(val);
            return root;
        }
        //如果root值比val小，说明val需要插入root的左子树
        if (root->val < val) {
            root->left = insertAVL(val, root->left);
            if(!isBalancedTree(root)) {
                //如果左子树的值比val小，说明val被插入root左子树的左子树
                //需要一次左侧的单旋转
                if (root->left->val < val) {
                    root = singleRotateLeft(root);
                }
                //否则说明val被插入左子树的右子树
                //需要一次左侧的双旋转
                else {
                    root = doubleRotateLeft(root);
                }
            }
        }
        //否则，说明val被插入root的右子树
        if (root->val > val) {
            root->right = insertAVL(val, root);
            if (!isBalancedTree(root)) {
                //如果右子树的值比val小，说明val被插入右子树的右子树
                //需要一次右侧单旋转
                if (root->right->val < val) {
                    root = singleRotateRight(root);
                }
                //否则，val被插入右子树的左子树
                //需要一次右侧双旋转
                else {
                    root = doubleRotateRight(root);
                }
            }
        }
        return root;
    }
    TreeNode *singleRotateLeft(TreeNode* root) {
        TreeNode *newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;
        return newRoot;
    }
    TreeNode *singleRotateRight(TreeNode* root) {
        TreeNode *newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;
        return newRoot;
    }
    TreeNode *doubleRotateLeft(TreeNode* root) {
        TreeNode *newRoot = root->left->right;
        
        root->left->right = newRoot->left;
        newRoot->left = root->left;
        
        root->left = newRoot->right;
        newRoot->right = root;
        
        return newRoot;
    }
    TreeNode *doubleRotateRight(TreeNode* root) {
        TreeNode *newRoot = root->right->left;
        
        root->right->left = newRoot->right;
        newRoot->right = root->right;
        
        root->right = newRoot->left;
        newRoot->left = root;
        
        return newRoot;
    }
    int isBalancedTree(TreeNode *root) {
        if (!root) {
            return 0;
        }
        if (!root->left&&!root->right) {
            return 1;
        }
        int left = isBalancedTree(root->left);
        int right = isBalancedTree(root->right);
        if(left<0||right<0) {
            return -1;
        }
        int differ = left-right;
        if (differ>1||differ<-1) {
            return -1;
        }
        else {
            return left>right?left+1:right+1;
        }
    }
    */
};

#endif /* defined(__LeetCode__SortedArrayToAVLTree__) */
