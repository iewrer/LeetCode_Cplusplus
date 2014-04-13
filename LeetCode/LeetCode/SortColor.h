//
//  SortColor.h
//  LeetCode
//
//  Created by Barry on 14-4-13.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__SortColor__
#define __LeetCode__SortColor__

#include <iostream>
class Solution {
public:
    //计数排序
    //先收集0、1、2的个数
    //然后按顺序和个数重新输出到原数组中
    void sortColors(int A[], int n) {
        if (n == 0) {
            return;
        }
        int count[3] = {0 , 0 , 0};
        for (int i = 0; i < n; i++) {
            if (A[i] == 0) {
                count[0]++;
            }
            if (A[i] == 1) {
                count[1]++;
            }
            if (A[i] == 2) {
                count[2]++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (count[0] > 0) {
                A[i] = 0;
                count[0]--;
            }
            else if (count[1] > 0) {
                A[i] = 1;
                count[1]--;
            }
            else {
                A[i] = 2;
            }
        }
    }
};
#endif /* defined(__LeetCode__SortColor__) */
