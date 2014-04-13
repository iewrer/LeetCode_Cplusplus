//
//  Pascal'sTriangle.h
//  LeetCode
//
//  Created by Barry on 14-4-7.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef LeetCode_Pascal_sTriangle_h
#define LeetCode_Pascal_sTriangle_h

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) {
            return result;
        }
        vector<int> first = {1};
        result.push_back(first);
        if (numRows == 1) {
            return result;
        }
        vector<int> second = {1,1};
        result.push_back(second);
        //计算第2-n行
        for (int i = 2; i < numRows; i++) {
            vector<int> numRow;
            insert_iterator<vector<int>> column(numRow,numRow.begin());
            //第i行的开头和结尾都未1
            (*column) = 1;
            //第i行有i个元素
            for (int j = 1; j < i; j++) {
                //计算出新的result[i][j]，填入当前行的vector中
                (*column) = result[i-1][j] + result[i-1][j-1];
            }
            (*column) = 1;
            result.push_back(numRow);
        }
        return result;
    }
    /*
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) {
            return result;
        }
        vector<int> first = {1};
        result.push_back(first);
        if (numRows == 1) {
            return result;
        }
        vector<int> second = {1,1};
        result.push_back(second);
        //建立一个用于辅助计算的矩阵，因为vector不能随机访问
        int compute[numRows][numRows];
        compute[0][0] = 1;
        compute[1][0] = 1;
        compute[1][1] = 1;
        for (int i = 2; i < numRows; i++) {
            vector<int> numRow;
            insert_iterator<vector<int>> column(numRow,numRow.begin());
            compute[i][0] = 1;
            (*column) = compute[i][0];
            for (int j = 1; j < i; j++) {
                compute[i][j] = compute[i-1][j]+compute[i-1][j-1];
                (*column) = compute[i][j];
            }
            compute[i][i] = 1;
            (*column) = compute[i][i];
            result.push_back(numRow);
        }
        return result;
    }
     */
};

#endif
