//
//  PalindromeNumber.h
//  LeetCode
//
//  Created by Barry on 14-4-29.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__PalindromeNumber__
#define __LeetCode__PalindromeNumber__

#include <iostream>
#include <math.h>
class Solution {
public:
    bool isPalindrome(int x) {
        //负数直接返回false
        if (x < 0) {
            return false;
        }
        //记录x的十进制位数n
        int divisor = x,n = 0;
        while (divisor) {
            divisor = divisor/10;
            n++;
        }
        //一位数显然为回文数
        if (n == 1) {
            return true;
        }
        //设置两个指针，从两头往中间走
        int begin = --n,end = 0,left,right;
        //设置两个除数，分别用于获取最左侧和最右侧的数字
        int divisorL = x,divisorR = x;
        //走到中间时退出
        while (begin > end) {
            //左侧数字是除数除以10的(n-1)倍，这里n已经预先减过
            left = divisorL/pow(10, n);
            //右侧数字直接除10
            right = divisorR%10;
            if (left!=right) {
                return false;
            }
            //左侧除数为除数除以10的(n-1)倍，这里n已经预先减过
            divisorL = divisorL%(int)pow(10, n);
            divisorR = divisorR/10;
            n--;begin--;end++;
        }
        //只剩下中间一个数或者中间没有数的时候即为回文数
        return true;
    }
};
#endif /* defined(__LeetCode__PalindromeNumber__) */
