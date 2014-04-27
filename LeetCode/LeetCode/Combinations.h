//
//  Combinations.h
//  LeetCode
//
//  Created by Barry on 14-4-27.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__Combinations__
#define __LeetCode__Combinations__

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> num;
        vector<vector<int>> result;
        if (!n) {
            return result;
        }
        //先构造1..n的数列
        for (int i = 0; i < n; i++) {
            num.push_back(i+1);
        }
        return generComb(num,n,k);
    }
    //主要思想是利用递推式：
    //C(n,k) = C(n-1,k-1)+C(n,k-1)
    //即分为两步：
    //1.先将num的头部取出待用，递归获取C(n-1,k-1)的组合情况，([xs1,xs2...]|xs为一个集合)，再将num的头部依次添加到这些组合的头部,[front:xs1,front:xs2...]
    //2.递归获取C(n,k-1)的组合情况
    //然后将这两步获取的组合情况均添加到结果集合中即可
    //递归终止条件也分两种：
    //1.k==0:此时没有可以组合的数了，返回空集，返回后将头部直接添加到空集合中即可,[[front]]
    //2.n==k:此时只有唯一的组合情况，即为当前的num集合,[[1..n]]
    vector<vector<int>> generComb(vector<int> num,int n,int k) {
        vector<vector<int>> result;
        if (k == 0) {
            return result;
        }
        if (n == k) {
            return vector<vector<int>>(1,num);
        }
        int front = num.front();
        num.erase(num.begin());
        vector<vector<int>> tmp = generComb(num, n-1, k-1);
        //step 1:
        //处理递归终止为空的情况
        if (tmp.empty()) {
            result.push_back(vector<int>(1,front));
        }
        //其他情况
        else {
            for (int i = 0; i < tmp.size(); i++) {
                tmp.at(i).insert(tmp.at(i).begin(), front);
                result.push_back(tmp.at(i));
            }
        }
        //step 2:
        tmp = generComb(num, n-1, k);
        for (int i = 0; i < tmp.size(); i++) {
            result.push_back(tmp.at(i));
        }
        return result;
    }
};
#endif /* defined(__LeetCode__Combinations__) */
