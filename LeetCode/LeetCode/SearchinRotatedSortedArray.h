//
//  SearchinRotatedSortedArray.h
//  LeetCode
//
//  Created by Barry on 14-4-29.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__SearchinRotatedSortedArray__
#define __LeetCode__SearchinRotatedSortedArray__

#include <iostream>
class Solution {
public:
    //假设A=[A1,A2]因为A是部分有序，且A1>A2
    //所以可以找到分割A1和A2的中间点
    //然后分段做二分查找
    int search(int A[], int n, int target) {
        int middle = 0;
        for (int i = 0; i < n; i++) {
            //找到分割点，即A[i]>A[i+1]
            //注意数组下标越界！
            if (i+1 < n&&A[i] > A[i+1]) {
                middle = i;
            }
        }
        //先找左半段
        int left = binarySearch(A,0,middle,target);
        //没有找到的话再去右半段找
        if (left == -1) {
            return binarySearch(A,middle+1,n-1,target);
        }
        //否则返回在左半段找到的下标
        return left;
    }
    //标准二分查找
    int binarySearch(int A[],int begin,int end,int target) {
        if (begin > end) {
            return -1;
        }
        if (begin == end) {
            if (target == A[begin]) {
                return begin;
            }
            return -1;
        }
        int middle = (begin+end)/2;
        if (A[middle] == target) {
            return middle;
        }
        if (A[middle] < target) {
            return binarySearch(A,middle+1,end,target);
        }
        else {
            return binarySearch(A,begin,middle-1,target);
        }
    }
};
#endif /* defined(__LeetCode__SearchinRotatedSortedArray__) */
