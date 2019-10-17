class Solution {
    public:
        string numberToWords(int num) {
                if (num == 0) return "Zero";
                string str;  //=to_string(num);
                int num_;    //=str.size();
                int base_;   //=base[num_];
                string result = "";
                int res = num;

                while (res > 0) {
                        str = to_string(res);
                        num_ = str.size();
                        base_ = base[num_ - 1];
                        int rate = res / base_;
                        int left = res % base_;

                        if (base_ == 10) {
                                result += convert_two(res);
                                break;
                        }

                        if (base_ == 100) {
                                result += " " + dict_1[rate - 1] + " Hundred";
                        }


                        if (base_==1000||base_ == 1000000) {
                                if (10 <= rate && rate <= 99) {
                                        result += convert_two(rate);
                                } else if (100 <= rate && rate <= 999) {
                                        result +=
                                            (" " + dict_1[rate / 100 - 1] +
                                             " Hundred");
                                        result += convert_two(rate % 100);
                                } else {
                                        result += (" " + dict_1[rate - 1]);
                                }
                                result +=(base_==1000?" Thousand":" Million");
                        }

                        if (base_ == 1000000000) {
                                result += (" " + dict_1[rate - 1] + " Billion");
                        }

                        res = left;
                }

                return result.substr(1, result.size() - 1);
        }
        string convert_two(int res) {
                if (res == 0) return "";
                int rate = res / 10;
                int left = res % 10;
                string result = "";
                        if (rate == 1 && left != 0) {  // 1x
                                result += (" " + dict_2[left - 1]);
                        } else if (rate >= 1 && left == 0) {  // x0
                                result += (" " + dict_3[rate - 1]);
                        } else if (rate == 0) {  //<10
                                result += (" " + dict_1[res - 1]);
                        } else {
                                result += (" " + dict_3[rate - 1] + " " +
                                           dict_1[left - 1]);
                        }
                return result;
        }
        vector<int> base = {10,   10,      100,     1000,    1000,
                            1000, 1000000, 1000000, 1000000, 1000000000};
        vector<string> dict_3 = {"Ten",   "Twenty",  "Thirty", "Forty", "Fifty",
                                 "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> dict_2 = {"Eleven",    "Twelve",   "Thirteen",
                                 "Fourteen",  "Fifteen",  "Sixteen",
                                 "Seventeen", "Eighteen", "Nineteen"};
        vector<string> dict_1 = {"One", "Two",   "Three", "Four", "Five",
                                 "Six", "Seven", "Eight", "Nine"};
};
