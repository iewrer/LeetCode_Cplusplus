//
//  UnitPath.h
//  LeetCode
//
//  Created by Barry on 14-4-20.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__UnitPath__
#define __LeetCode__UnitPath__

#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        //实际上它求的是m*n矩阵中格子的移动方式
        //而不是从左上角顶点到右下角顶点的移动方式
        //所以可以先对m,n自减，变为顶点移动
        m--;
        n--;
        //边界情况，减到0的话说明只有1种移动方式（因为往右/下走的时候动弹不得）
        if (!m||!n) {
            return 1;
        }
        //尽可能的减少计算量
        //公式：C(m+n,m)=(m+n)!/(m!*n!)
        //可以将m+n!和m!或n!进行抵消，减少阶乘次数
        if (n < m) {
            return factorial(m+1,m+n)/factorial(1,n);
        }
        return factorial(n+1,m+n)/factorial(1,m);
    }
    //求从begin连乘到end的辅助函数
    long long factorial(int begin,int end) {
        long long fac = 1;
        for (int i = begin; i <= end; i++) {
            fac *= i;
        }
        return fac;
    }
};
#endif /* defined(__LeetCode__UnitPath__) */
