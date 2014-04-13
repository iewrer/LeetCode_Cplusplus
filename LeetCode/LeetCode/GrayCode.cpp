//
//  GrayCode.cpp
//  LeetCode
//
//  Created by Barry on 14-4-11.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#include "GrayCode.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> x;
        makeCode(n,x);
        return x;
    }
    void makeCode(int n,vector<int>& code) {
        if (n==0) {
            code.push_back(0);
            return;
        }
        makeCode(n-1, code);
        //反向增加新元素
        for (int i = code.size()-1;i >= 0;i--) {
            //获得在当前位数加上前缀1的数high
            int high = 1 << (n-1);
            //将high与原有元素做或运算，相当于在原有元素的二进制表示上增加了前缀1
            code.push_back(high|code[i]);
        }
    }
};