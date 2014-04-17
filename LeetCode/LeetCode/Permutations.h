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
        vector<vector<int>> result;
        generateAll(result, num);
        return result;
    }
    //该方法可以处理有重复元素的排列
    void generateAll(vector<vector<int>>& result,vector<int>& num) {
        if (num.empty()) {
            return;
        }
        if (num.size() == 1) {
            result.push_back(num);
            return;
        }
        //直到没有下一个字典序排列可以生成为止
        while (true) {
            if (find(result.begin(), result.end(), num)==result.end()) {
                result.push_back(num);
            }
            else {
                return;
            }
            next_permutation(num);
        }
    }
    //用于生成下一个排列
    void next_permutation(vector<int>& num) {
        vector<int>::iterator i,ii;
        //从尾端开始往前
        //找到两个相邻的元素i和ii，如果满足i<ii:
        //那么再从尾端开始找到第一个比i大的元素j
        //交换i和j
        //再将ii到尾端这段元素逆序
        //即获得下一个字典序全排列
        i = num.end()-1;
        while (true) {
            //i和ii是相邻的两个元素，每次均向前走一步
            ii = i;
            i--;
            if ((*i)<(*ii)) {
                //从尾部开始往前找到第一个比i大得元素j
                vector<int>::iterator j = num.end()-1;
                while ((*i)>=(*j)) {
                    j--;
                }
                //交换i,j
                swap(*i, *j);
                //将ii到尾部逆序
                for (vector<int>::iterator m = ii,n=num.end()-1; m < n; m++,n--) {
                    int tmp = *m;
                    *m = *n;
                    *n = tmp;
                }
                return;
            }
            //如果已经找到头了
            //那么此时是最后一个全排列，直接全体逆序即可获得最开始的一个字典序排列
            //此时返回false，则不会插入新的字典序排列了
            if (i == num.begin()) {
                for (vector<int>::iterator m = i,n=num.end()-1; m < n; m++,n--) {
                    int tmp = *m;
                    *m = *n;
                    *n = tmp;
                }
                return;
            }
        }
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
