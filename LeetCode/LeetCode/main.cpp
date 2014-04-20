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
#include "PlusOne.h"

using namespace std;
int main(int argc, const char * argv[])
{
    Solution s;
    vector<int> x = {9,9};
    x = s.plusOne(x);
    for (int i = 0; i < x.size(); i++) {
        cout << x.at(i) << "\n";
    }

}

