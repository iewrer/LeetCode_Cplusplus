//
//  MergeSortedArray.h
//  LeetCode
//
//  Created by Barry on 14-4-6.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef LeetCode_MergeSortedArray_h
#define LeetCode_MergeSortedArray_h

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (n == 0) {
            return;
        }
        if (B[n-1]<A[0]) {
            //将A向后挪B的长度个位置
            for (int i = m-1; i >= 0; i--) {
                A[i+n] = A[i];
            }
            //将B中的元素依次从A的头部开始填入
            for (int i = 0; i < n; i++) {
                A[i] = B[i];
            }
            return;
        }
        if (A[m]<B[0]||m == 0) {
            //直接将B中的元素依次填入到A的尾部
            for (int i = 0; i < n; i++) {
                A[i+m] = B[i];
            }
            return;
        }
        //处理其他的合并情况
        int lengthA = m;
        int i = 0,j = 0;
        for (; i < n&&j < lengthA;j++) {
            if (B[i] <= A[j]) {
                //将A中j以后的元素向后挪一个位置
                for (int k = lengthA-1; k >= j; k--) {
                    A[k+1] = A[k];
                }
                //将A[j]赋值为B[i]
                A[j] = B[i++];
                lengthA++;
            }
        }
        for (; i < n; i++,j++) {
            A[j] = B[i];
        }
    }
};

#endif
