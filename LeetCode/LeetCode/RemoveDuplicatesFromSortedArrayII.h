//
//  RemoveDuplicatesFromSortedArrayII.h
//  LeetCode
//
//  Created by Barry on 14-4-27.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__RemoveDuplicatesFromSortedArrayII__
#define __LeetCode__RemoveDuplicatesFromSortedArrayII__

#include <iostream>
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int count = 0;
        int last = count;
        int size = n;
        //如果连续出现了至少2次
        //则将size缩小，数组前移count-1位
        //因为可以有一次重复
        //更新count和last
        for (int i = 0; i < size; i++) {
            if (i+1 < size && A[i] == A[i+1]) {
                count++;
            }
            if (count > 1 && last == count) {
                size = size - count + 1;
                //注意这里是将开始重复的那段挪到从i-count开始
                for (int j = i - count; j < size; j++) {
                    A[j] = A[j+count-1];
                }
                i = i - count;
                count = 0;
                last = count;
            }
            else if (last == count) {
                count = 0;
            }
            last = count;
        }
        //处理最后的重复数字
        if (count > 1) {
            size = size - count + 1;
            for (int j = 0; j < size; j++) {
                A[j] = A[j+count-1];
            }
        }
        return size;
    }
};
#endif /* defined(__LeetCode__RemoveDuplicatesFromSortedArrayII__) */
