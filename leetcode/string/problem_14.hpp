/*
* Copyright (C) 2018 by Sensetime Group Limited. All rights reserved.
* Liu Xin <liuxin@sensetime.com>
*/
// time 4ms
// time complexity O(m*n),m is size of strs,n is size of longest string
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
                if (strs.size() == 0) {
                        return "";
                }
                if (strs.size() == 1) {
                        return strs[0];
                }
                auto& str = strs[0];
                if (str.size() == 0) {
                        return "";
                } else {
                        for (size_t i = 0; i < str.size(); i++) {
                                for (size_t j = 1; j < strs.size(); j++) {
                                        if (strs[j].size() <= i ||
                                            str[i] != strs[j][i]) {
                                                return str.substr(0, i);
                                        }
                                }
                        }
                        return str;
                }
        }
};
