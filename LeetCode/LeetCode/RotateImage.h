//
//  RotateImage.h
//  LeetCode
//
//  Created by Barry on 14-4-19.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__RotateImage__
#define __LeetCode__RotateImage__

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        //先水平翻转
        //只需遍历前n/2行
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }
        //再按照主对角线翻转
        //只需遍历左下角(a[i][j],i<j)的部分
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //也可以先按副对角线翻转，再水平翻转
        //（也就是先求转置矩阵，再将每行reverse）
        //不过我觉得这种情况比较好算些
        
        //也可以从外到内，将每一圈顺时针移动90°
    }
};
#endif /* defined(__LeetCode__RotateImage__) */
