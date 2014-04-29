//
//  LengthofLastWord.h
//  LeetCode
//
//  Created by Barry on 14-4-29.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__LengthofLastWord__
#define __LeetCode__LengthofLastWord__

#include <iostream>
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (!s) {
            return 0;
        }
        int n = 0;
        //假设s = s1+' '+s2
        while (*s!='\0') {
            //每次碰到空格符，就递归计算s2的最后一个单词的长度
            if (*s == ' ') {
                //这里递归时不要对采用++s，会改变s指针，可以采用指针运算传递一个新的指针过去
                int length = lengthOfLastWord(s+1);
                //如果s2不为空，则返回这个长度
                if (length) {
                    return length;
                }
            }
            //如果没有碰到空格符，则持续计算单词长度
            else {
                n++;
            }
            s++;
        }
        //如果s2为空，则返回s1的长度
        return n;
    }
};
#endif /* defined(__LeetCode__LengthofLastWord__) */
