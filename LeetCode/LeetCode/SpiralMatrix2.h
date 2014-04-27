//
//  SpiralMatrix2.h
//  LeetCode
//
//  Created by Barry on 14-4-27.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__SpiralMatrix2__
#define __LeetCode__SpiralMatrix2__

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        int begin = 0,end = n-1;
        int num = 1;
        //模拟螺旋过程
        //每次都顺时针填满外圈：（注意这4步的衔接位置）
        //1.a[begin][begin]->a[begin][end-1]
        //2.a[begin][end]->a[end-1][end]
        //3.a[end][end]->a[end][begin-1]
        //4.a[end][begin]->a[begin-1][begin]
        //每次循环完毕后，向里缩一圈，继续填充外圈:begin--&&end--
        //如果最后begin==end，说明最里面还有一个元素待填
        //如果最后begin>end，说明已经完全填满
        while (begin < end) {
            for (int i = begin; i < end; i++) {
                matrix[begin][i] = num++;
            }
            for (int i = begin; i < end; i++) {
                matrix[i][end] = num++;
            }
            for (int i = end; i > begin; i--) {
                matrix[end][i] = num++;
            }
            for (int i = end; i > begin; i--) {
                matrix[i][begin] = num++;
            }
            begin++;end--;
        }
        if (begin == end) {
            matrix[begin][end] = num;
        }
        return matrix;
    }
};
#endif /* defined(__LeetCode__SpiralMatrix2__) */
