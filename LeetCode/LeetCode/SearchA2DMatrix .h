//
//  SearchA2DMatrix .h
//  LeetCode
//
//  Created by Barry on 14-4-26.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__SearchA2DMatrix___
#define __LeetCode__SearchA2DMatrix___

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //solution1
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = (*matrix.begin()).size();
        if (matrix.empty()) {
            return false;
        }
        //先二分查找m行中所有最大值，以确定具体行号
        //然后到该行中进行二分查找
        int low = 0,high = m-1;
        int mid,val;
        //二分判定
        while (low < high) {
            mid = (low + high)/2;
            val = matrix.at(mid).at(n-1);
            if (val == target) {
                return true;
            }
            if (val < target) {
                low = mid +1;
            }
            else {
                high = mid - 1;
            }
        }
        //如果找到最后的那个元素为target，直接返回
        if (low == high) {
            mid = (low + high)/2;
            val = matrix.at(mid).at(n-1);
            if (val == target) {
                return true;
            }
        }
        //否则如果target>val，则说明target应该在val那行的下一行
        //因为val代表该行的最大值，所以需要向更大的一行中进行查找
        if (target > val) {
            //防止溢出判断
            if (mid+1>=m) {
                mid = mid-1;
            }
            return binarySearch(matrix.at(mid+1), 0, n-1, target);
        }
        //如果target<val，则说明target就在val这一行
        //因为val代表该行的最大值
        //而之前的搜索已经否决掉了val的上一行
        else {
            return binarySearch(matrix.at(mid), 0, n-1, target);
        }
        return false;
    }
    //solution2
    bool searchMatrix2(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = (*matrix.begin()).size();
        if (matrix.empty()) {
            return false;
        }
        //先遍历m行中所有的最大数以确定该数应该在哪行
        //然后到该行中进行二分查找
        //所以这里是制约因素
        //可以考虑这里也做二分查找
        for (int i = 0; i < m; i++) {
            if (target <= matrix.at(i).at(n-1)) {
                return binarySearch(matrix.at(i), 0, n-1, target);
            }
        }
        return false;
    }
    bool binarySearch(vector<int>& line,int low,int high,int target) {
        if (low > high) {
            return false;
        }
        if (low == high) {
            return line.at(low)==target;
        }
        int mid = (low + high)/2;
        if (line.at(mid)  == target) {
            return true;
        }
        else if (line.at(mid) > target) {
            return binarySearch(line, low, mid - 1, target);
        }
        else {
            return binarySearch(line, mid + 1, high, target);
        }
    }
};
#endif /* defined(__LeetCode__SearchA2DMatrix___) */
