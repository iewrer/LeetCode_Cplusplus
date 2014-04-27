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
#include "RemoveDuplicatesFromSortedArrayII.h"

using namespace std;
int main(int argc, const char * argv[])
{
    Solution s;
    int y[3] = {1,1,1};
//    x.push_back(y);
    int size = s.removeDuplicates(y, 3);
    for (int i = 0; i < size; i++) {
        cout << y[i] << " ";
    }
}

