//
//  GenarateParentheses.h
//  LeetCode
//
//  Created by Barry on 14-4-15.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__GenarateParentheses__
#define __LeetCode__GenarateParentheses__

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        return generate(result, n);
    }
    vector<string> generate(vector<string>& result,int n) {
        if (n == 0) {
            vector<string> tmp;
            tmp.push_back("");
            return tmp;
        }
        if (n == 1) {
            vector<string> tmp;
            tmp.push_back("()");
            return tmp;
        }
        for (int i = 0; i < n; i++) {
            vector<string> inner,outer;
            inner = generate(inner, i);
            outer = generate(outer, n-1-i);
            for (vector<string>::iterator In = inner.begin();In != inner.end(); ++In) {
                for (vector<string>::iterator Out = outer.begin(); Out != outer.end(); ++Out) {
                    result.push_back("("+(*In)+")"+(*Out));
                }
            }
        }
        return result;
    }
};
#endif /* defined(__LeetCode__GenarateParentheses__) */
