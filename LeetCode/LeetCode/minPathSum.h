//
//  minPathSum.h
//  LeetCode
//
//  Created by Barry on 14-4-26.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__minPathSum__
#define __LeetCode__minPathSum__

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = (*grid.begin()).size();
        if (grid.empty()) {
            return NULL;
        }
        int up = INT32_MAX,left = INT32_MAX;
        //动态规划
        //minPathSum[i][j] = min{minPathSum[i-1][j],minPathSum[i][j-1]}+grid[i][j]
        //这里可以就地重用grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //获得上方和左方的最短路径和
                //如果超出数组范围则设置为最大值
                up = i>0?grid.at(i-1).at(j):INT32_MAX;
                left = j>0?grid.at(i).at(j-1):INT32_MAX;
                //如果为第一个元素，则不变
                if (i==0&&j==0) {
                    grid.at(i).at(j) = grid.at(i).at(j);
                }
                //否则取上方和左方的较小最短路径和，并加上自身
                //即得到grid[i][j]的最短路径和
                else {
                    grid.at(i).at(j) += min(up,left);
                }
            }
        }
        return grid.at(m-1).at(n-1);
    }
};
#endif /* defined(__LeetCode__minPathSum__) */
