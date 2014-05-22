//
//  SearchforaRange.h
//  LeetCode
//
//  Created by Barry on 14-5-22.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__SearchforaRange__
#define __LeetCode__SearchforaRange__

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> range(2,-1);
        if (n == 0) {
            return range;
        }
        binarySearch_Range(A,range,0,n-1,target);
        return range;
    }
    void binarySearch_Range(int A[],vector<int> &range,int low ,int high,int target) {
        if (low > high) {
            return;
        }
        if (low == high) {
            //如果找到了，则更新range
            //注意添加初始条件，即一进来就找到了的情况
            if (A[low] == target) {
                if (low < range.at(0) || range.at(0) < 0) {
                    range.at(0) = low;
                }
                if (range.at(1) < low) {
                    range.at(1) = low;
                }
            }
            return;
        }
        int mid = (low + high)/2;
        //如果找到了，则可以继续往两侧找range
        if (A[mid] == target) {
            if (range.at(0) > mid || range.at(0) < 0) {
                range.at(0) = mid;
            }
            if (range.at(1) < mid) {
                range.at(1) = mid;
            }
            binarySearch_Range(A, range, mid+1, high, target);
            binarySearch_Range(A, range, low, mid -1, target);
        }
        //否则往合适的一侧找range
        if (A[mid] < target) {
            binarySearch_Range(A, range, mid+1, high, target);
        }
        else {
            binarySearch_Range(A, range, low, mid -1, target);
        }
    }
};
#endif /* defined(__LeetCode__SearchforaRange__) */
