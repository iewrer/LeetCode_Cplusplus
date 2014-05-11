//
//  Subsets.h
//  LeetCode
//
//  Created by Barry on 14-5-11.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__Subsets__
#define __LeetCode__Subsets__

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //我觉得还有一种增量式的方法：
    //例如，对于[1,2,3]
    //1.先求出[1]的子集{[],[1]}
    //2.再在子集的基础上添加2，试图构造[1,2]的子集{[],[2],[1],[1,2]}
    //3.再在子集的基础上添加3，构造出{[],[3],[2],[2,3],[1],[1,3],[1,2],[1,2,3]}
    vector<vector<int>> subsets(vector<int> &S) {
        vector<vector<int>> result;
        vector<int> path;
        //先排序，保证有序
        sort(S.begin(), S.end());
        return searchSub(S,path,result,0);
    }
    //遍历2^n种所有情况
    vector<vector<int>>& searchSub(vector<int> &S,vector<int> path,
                                  vector<vector<int>> &result,int length) {
        //如果该分支已遍历到头，则将路径添加进来
        if (length == S.size()) {
            result.push_back(path);
            return result;
        }
        //将当前搜索路径分叉
        //1.路径中不选择当前步，继续搜索
        result = searchSub(S, path, result, length+1);
        //2.路径中选择当前步记录之，继续搜索
        path.push_back(S.at(length));
        result = searchSub(S, path, result, length+1);
        //清除当前步，恢复到该层原本的path记录
        path.pop_back();
        //返回上一层
        return result;
    }
};
#endif /* defined(__LeetCode__Subsets__) */
