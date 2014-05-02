//
//  ValidParentheses.h
//  LeetCode
//
//  Created by Barry on 14-4-30.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__ValidParentheses__
#define __LeetCode__ValidParentheses__

#include <iostream>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    //中心思想是利用栈来进行匹配
    bool isValid(string s) {
        map<char, char> pair;
        stack<char> str;
        //记录成对的组合
        pair.insert(make_pair(')', '('));
        pair.insert(make_pair(']', '['));
        pair.insert(make_pair('}', '{'));
        //遍历s
        for (string::iterator it = s.begin(); it != s.end(); ++it) {
            //如果是左括号则入栈
            if (*it == '(' || *it == '[' || *it == '{') {
                str.push(*it);
                continue;
            }
            //否则如果此时栈里没有东西，说明出现了类似"]"的状态
            if (str.empty()) {
                return false;
            }
            //如果栈顶和下一个符号不匹配，则false
            if (str.top() != (pair.find(*it)->second)){
                return false;
            }
            //否则将栈顶出栈
            else {
                str.pop();
            }
        }
        //如果栈为空，则说明全部匹配上
        if (str.empty()) {
            return true;
        }
        //否则也为false
        return false;
    }
};
#endif /* defined(__LeetCode__ValidParentheses__) */
