//
//  LongestCommonPrefix.h
//  LeetCode
//
//  Created by Barry on 14-5-21.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__LongestCommonPrefix__
#define __LeetCode__LongestCommonPrefix__

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }
        //纵向扫描
        //对每个字符串扫描第index位是否相同
        //如果不相同，则直接返回前0-(index-1)位即可
        //否则第index位是公共前缀的一部分，继续找第index+1位
        for (int index = 0; index < strs.at(0).size(); index++) {
            for (int i = 1; i < strs.size(); i++) {
                //此处有一个退出条件为index超过了某个字符串的长度限制
                //说明该字符串即为所求的最长公共前缀
                if (index >= strs.at(i).size() || strs.at(i).at(index) != strs.at(0).at(index)) {
                    return strs.at(0).substr(0,index);
                }
            }
        }
        return strs.at(0);
    }
};
#endif /* defined(__LeetCode__LongestCommonPrefix__) */
