//
//  UniquePath2.h
//  LeetCode
//
//  Created by Barry on 14-5-19.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__UniquePath2__
#define __LeetCode__UniquePath2__

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size()-1;
        int n = obstacleGrid.front().size()-1;
        //为了防止边界溢出（第一行和第一列），多申请了一行一列
        vector<vector<int>> memo(m+2,vector<int>(n+2,0));
        if (obstacleGrid.empty()) {
            return 0;
        }
        return searchPath(obstacleGrid,memo,m+1,n+1);
    }
    int searchPath(vector<vector<int> > &obstacleGrid,vector<vector<int>> &memo,int i,int j) {
        //边界条件
        if (i < 1 || j < 1|| obstacleGrid.at(i-1).at(j-1) == 1) {
            return 0;
        }
        //找到合适的路径
        if (1 == i && 1 == j) {
            return 1;
        }
        //往上找
        int left = memo.at(i).at(j-1) == 0 ? searchPath(obstacleGrid, memo, i, j-1):memo.at(i).at(j-1);
        //记录之
        memo.at(i).at(j-1) = left;
        //往左找
        int right = memo.at(i-1).at(j) == 0 ? searchPath(obstacleGrid, memo, i-1, j):memo.at(i-1).at(j);
        //记录之
        memo.at(i-1).at(j) = right;
        //返回所有路径数
        return left+right;
    }
};
#endif /* defined(__LeetCode__UniquePath2__) */
