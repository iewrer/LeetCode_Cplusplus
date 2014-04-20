//
//  PlusOne.h
//  LeetCode
//
//  Created by Barry on 14-4-19.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__PlusOne__
#define __LeetCode__PlusOne__

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.empty()) {
            return digits;
        }
        vector<int>::iterator it = digits.end()-1;
        plus(digits, it, 10);
        return digits;
    }
    //从后往前遍历，如果加1后需要向前进位，则继续递归
    //如果到最开始时仍需进位，则在头部插入新的1
    void plus(vector<int>& digits,vector<int>::iterator it,int base) {
        (*it) = (*it)+1;
        if ((*it)>=10) {
            (*it) = (*it)%base;
            if (it==digits.begin()) {
                digits.insert(digits.begin(), 1);
                return;
            }
            else {
                plus(digits, it-1, base);
            }
        }
    }
};
#endif /* defined(__LeetCode__PlusOne__) */
