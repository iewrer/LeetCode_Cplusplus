//
//  MaxSubArray.h
//  LeetCode
//
//  Created by Barry on 14-3-30.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__MaxSubArray__
#define __LeetCode__MaxSubArray__

#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        return mcss(A, n);
    }
    int maxSubArray2(int A[], int n) {
        int result = INT_MIN, f = 0;
        for (int i = 0; i < n; ++i) {
            f = max(f + A[i], A[i]);
            cout << result << " ";
            result = max(result, f);
        }
        cout << "\n";
        return result;
    }
    int print();
private:
    // 思路 5,求最大连续子序列和
    static int mcss(int A[], int n) {
    int i, result, cur_min; int* sum= new int[n+1]; // 前 n 项和
    sum[0] = 0;
    result = INT_MIN;
    cur_min = sum[0];
    for (i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + A[i - 1];
    }
    for (i = 1; i <= n; i++) {
        result = max(result, sum[i] - cur_min);
        cout << result << " ";
        cur_min = min(cur_min, sum[i]);
    }
    cout << "\n";
    delete[] sum;
    return result;
} };


#endif /* defined(__LeetCode__MaxSubArray__) */
