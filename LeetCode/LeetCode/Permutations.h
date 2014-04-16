//
//  Permutations.h
//  LeetCode
//
//  Created by Barry on 14-4-16.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__Permutations__
#define __LeetCode__Permutations__

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int> &num) {
        return generate(num);
    }
    //该方法无法处理有重复元素的情况
    //如果num带有重复元素，则结果全排列也会出现重复
    vector<vector<int>> generate(vector<int>& num) {
        vector<vector<int>> result;
        //当num为空或只有一个元素时收敛
        if (num.empty()) {
            return result;
        }
        if (num.size() == 1) {
            result.push_back(num);
            return result;
        }
        //假设当前num中有n个数字
        //对于num中第i个数字，获取除去它的其他n-1个数字的全排列
        //然后将第i个数字逐次附加在这些全排列的尾端，即获得所有以第i个数字结尾的全排列
        for (int i = 0; i < num.size(); i++) {
            int tmp = num.at(i);
            //临时的num数组，表示除去第i个数字的剩下其他元素
            vector<int> tmpNum = num;
            tmpNum.erase(find(tmpNum.begin(), tmpNum.end(), tmp));
            //临时的n-1个数字的全排列组合
            vector<vector<int>> tmpResult;
            tmpResult = generate(tmpNum);
            //将n-1个数字的全排列组合尾部加上第i个数字
            //再将获得的n个数字的新排列加入到n个数字的全排列数组中
            for (int j = 0; j < tmpResult.size(); j++) {
                tmpResult.at(j).push_back(tmp);
                result.push_back(tmpResult.at(j));
            }
        }
        return result;
    }
};
#endif /* defined(__LeetCode__Permutations__) */
