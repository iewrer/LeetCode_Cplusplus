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
#include "Permutations.h"
//#include "BinaryTreeLevelOrderTranversal2.h"
using namespace std;
int main(int argc, const char * argv[])
{
    Solution s;
    vector<int> x = {1,2,3,1};
    vector<vector<int>> result = s.permute(x);
    for (int i = 0; i < result.size(); i++) {
        cout << i << ".";
        for (int j = 0; j < result.at(i).size(); j++) {
            cout << result.at(i).at(j);
        }
        cout << "\n";
    }
}

