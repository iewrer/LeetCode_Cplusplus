//
//  BestTimeToBuyAndSellStock.h
//  LeetCode
//
//  Created by Barry on 14-4-17.
//  Copyright (c) 2014年 Barry. All rights reserved.
//

#ifndef __LeetCode__BestTimeToBuyAndSellStock__
#define __LeetCode__BestTimeToBuyAndSellStock__

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        vector<int> mins;
        if (prices.empty()) {
            return profit;
        }
        if (prices.size() == 1) {
            return profit;
        }
        mins.push_back(prices.at(0));
        for (int i = 1;i < prices.size();i++) {
            if (prices.at(i) < mins.at(i-1)) {
                mins.push_back(prices.at(i));
            }
            else {
                mins.push_back(mins.at(i-1));
            }
            profit = max(profit,prices.at(i)-mins.at(i));
        }
        return profit;
    }
};
#endif /* defined(__LeetCode__BestTimeToBuyAndSellStock__) */
