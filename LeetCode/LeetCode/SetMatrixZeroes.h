//
//  SetMatrixZeroes.h
//  LeetCode
//
//  Created by Barry on 14-4-27.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__SetMatrixZeroes__
#define __LeetCode__SetMatrixZeroes__

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix.front().size();
        if (matrix.empty()) {
            return;
        }
        //将第一行/列用于存储第i行/列中是否有0
        //这样复用之后，可以将空间复杂度限制为常数级
        //另外一种做法是直接用O(m+n)的空间来存储这些信息，要更直观一些
        
        //为了留存第一行/列中本来应有的是否被清除的信息
        //优先处理第一行/列：
        //采用两个标志位，用于标示第一行/列中是否有0
        bool row = false,column = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                row = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                column = true;
            }
        }
        //扫描除开第一行/列的矩阵，获取第i行/列是否有0的信息，并填入第一行/列
        //这样做不会破坏第一行/列原本的信息
        //因为如果a[i][j]==0，那么a[0][j]和a[i][0]本来就需要被重置为0
        //现在只是相当于提前重置了而已，而且还记录下了该点的行列信息，一举两得
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //设置除开第一行/列矩阵外的所有需要置0的行/列
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int k = 0; k < n; k++) {
                    matrix[i][k] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (matrix[0][i] == 0) {
                for (int k = 0; k < m; k++) {
                    matrix[k][i] = 0;
                }
            }
        }
        //若需要将第一行/列置0，则置之
        if (row) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (column) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};
#endif /* defined(__LeetCode__SetMatrixZeroes__) */
