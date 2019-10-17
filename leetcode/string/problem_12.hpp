/*
* Copyright (C) 2018 by Sensetime Group Limited. All rights reserved.
* Liu Xin <liuxin@sensetime.com>
*/
class Solution {
    public:
        string intToRoman(int num) {
                if (num <= 10) {
                        return dict[num - 1];
                }
                std::string result = "";
                int res = num;
                int ratio = 0;
                if ((ratio = res / 1000) != 0) {
                        res = res - ratio * 1000;
                        result += std::string(ratio, 'M');
                }
                if ((ratio = res / 100) != 0) {
                        res -= ratio * 100;
                        if (ratio == 4) {
                                result += "CD";
                        } else if (ratio == 9) {
                                result += "CM";
                        } else if (ratio < 4) {
                                result += std::string(ratio, 'C');
                        } else {
                                int ratio_ = ratio - 5;
                                result += "D";
                                result += std::string(ratio_, 'C');
                        }
                }
                if ((ratio = res / 10) != 0) {
                        res -= ratio * 10;
                        if (ratio == 4) {
                                result += "XL";
                        } else if (ratio < 4) {
                                result += std::string(ratio, 'X');
                                }
                        else if (ratio == 9) {
                                result += "XC";
                        } else {
                                int ratio_ = ratio - 5;
                                result += "L";
                                result += std::string(ratio_, 'X');
                        } 
                }
                if (res != 0) {
                        result += dict[res - 1];
                        return result;
                } else {
                        return result;
                }
        }

    private:
        std::vector<string> dict = {"I",  "II",  "III",  "IV", "V",
                                    "VI", "VII", "VIII", "IX", "X"};
        };
