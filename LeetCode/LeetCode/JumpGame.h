//
//  JumpGame.h
//  LeetCode
//
//  Created by Barry on 14-5-2.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__JumpGame__
#define __LeetCode__JumpGame__

#include <iostream>
class Solution {
public:
    bool canJump(int A[], int n) {
        //设状态为F[i],表示从第0层出发,走到A[i]时剩余的最大步数
        int F[n];
        F[0] = 0;
        //状态转移方程为：
        //f[i] = max(f[i−1],A[i−1])−1,i > 0
        //因为A[i-1]表示第i-1层上的最大能跳跃步数
        //F[i-1]表示从第0层走到第i-1层时能还剩下的能跳跃的最大步数
        for (int i = 1; i < n; i++) {
            F[i] = std::max(A[i-1], F[i-1])-1;
            if (F[i] < 0) {
                return false;
            }
        }
        return F[n-1]>=0;
    }
    //我的动态规划思想的正确解法
    //更直观一些
    bool canJump2(int A[], int n) {
        int F[n];
        F[0] = A[0];
        //处理形如[0,2,...]这样以0开始的情况，必然无法到达
        if (F[0] == 0&& n > 1) {
            return false;
        }
        //令F[i] = 第i层上能跳跃到的最大层号
        for (int i = 1; i < n; i++) {
            F[i] = std::max(A[i]+i,F[i-1]);
            //如果在非最后一层时，第i层上就跳跃不出第i层了，则显然无法跳跃到最后一层
            //因为前i-1层也必然无法跳跃出第i层
            if (F[i] <= i && i != n-1) {
                return false;
            }
        }
        return true;
    }
    
};
#endif /* defined(__LeetCode__JumpGame__) */
