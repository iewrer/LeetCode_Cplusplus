//
//  MaxSubArray.cpp
//  LeetCode
//
//  Created by Barry on 14-3-30.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#include "MaxSubArray.h"
int Solution::print()
{
    // insert code here...
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    maxSubArray(A, 9);
    maxSubArray2(A, 9);
    std::cout << "Hello, World!\n";
    return 0;
}