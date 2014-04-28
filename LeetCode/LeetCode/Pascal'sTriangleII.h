//
//  Pascal'sTriangleII.h
//  LeetCode
//
//  Created by Barry on 14-4-27.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__Pascal_sTriangleII__
#define __LeetCode__Pascal_sTriangleII__

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //累加法，利用一个last数组存储上一行的结果
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        vector<int> last(2,1);
        if (!rowIndex) {
            result.push_back(1);
            return result;
        }
        if (rowIndex == 1) {
            return last;
        }
        int n = rowIndex;
        while (last.size() <= n) {
            for (int i = 0; i <= last.size(); i++) {
                if (i == 0||i == last.size()) {
                    result.push_back(1);
                }
                else {
                    result.push_back(last.at(i)+last.at(i-1));
                }
            }
            last = result;
            result.clear();
        }
        return last;
    }
    //组合公式法，惜败于乘法溢出。。。
    vector<int> getRow2(int rowIndex) {
        vector<int> result;
        if (!rowIndex) {
            result.push_back(1);
            return result;
        }
        if (rowIndex == 1) {
            result.push_back(1);
            result.push_back(1);
            return result;
        }
        int n = rowIndex,cur,begin;
        for (int k = 0; k <= rowIndex/2; k++) {
            cur = multiply(n-k+1,n)/multiply(1, k);
            result.push_back(cur);
        }
        begin = rowIndex/2-1;
        if (rowIndex%2 == 0) {
            begin = rowIndex/2-2;
        }
        for (int k = begin; k >= 0; k--) {
            result.push_back(result.at(k));
        }
        return result;
    }
    int multiply(int begin,int end) {
        int result = 1;
        if (end == 0) {
            return result;
        }
        for (int i = begin; i <= end; i++) {
            result *= i;
        }
        return result;
    }
};
#endif /* defined(__LeetCode__Pascal_sTriangleII__) */
