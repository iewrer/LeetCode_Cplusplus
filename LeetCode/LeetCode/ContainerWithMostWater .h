//
//  ContainerWithMostWater .h
//  LeetCode
//
//  Created by Barry on 14-4-26.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__ContainerWithMostWater___
#define __LeetCode__ContainerWithMostWater___

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxArea = 0;
        int begin = 0,end = height.size()-1;
        if (height.size()<=1) {
            return NULL;
        }
        while (begin <= end) {
            int area = (end-begin)*min(height.at(end),height.at(begin));
            maxArea = max(area, maxArea);
            if (height.at(begin)<height.at(end)) {
                begin++;
            }
            else {
                end--;
            }
        }
        return maxArea;
    }
};
#endif /* defined(__LeetCode__ContainerWithMostWater___) */
