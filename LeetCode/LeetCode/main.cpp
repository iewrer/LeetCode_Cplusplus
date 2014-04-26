//
//  main.cpp
//  LeetCode
//
//  Created by Barry on 14-3-30.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "SearchA2DMatrix .h"

using namespace std;
int main(int argc, const char * argv[])
{
    Solution s;
    vector<vector<int>> x = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    vector<int> y;
//    x.push_back(y);
    s.searchMatrix(x,23);
}

