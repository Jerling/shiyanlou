/*
 输入一组整数，求出这组数字子序列和中的最大值，只要求出最大子序列的和，不必求出最大值对应的序列。
最大子序列和：整数序列A1， A2，... An （可能有负数），求A1~An的一个子序列Ai~Aj，使得Ai到Aj的和最大。

例如：

序列：-2, 11, -4, 13, -5, 2, -5, -3, 12, -9，则最大子序列和为21。

序列：0, -3, 6, 8, -20, 21, 8, -9, 10, -1, 3, 6, 5，则最大子序列和为43。
*/ 

#include<iostream>
#include<list>

int findMax(const std::list<int> str){
    int curmax = 0;
    int max = 0;
    for (std::list<int>::const_iterator it = str.begin();
            it != str.end(); it++){
        curmax += *it;
        if(curmax > max)
            max = curmax;
        else if(curmax < 0)
            curmax = 0;
    }
    return max;
}

int main(){
    std::list<int> str1 = {-2, 11, -4, 13, -5, 2, -5, -3, 12, -9};
    std::list<int> str2 = {0, -3, 6, 8, -20, 21, 8, -9, 10, -1, 3, 6, 5};

    std::cout << "str1: " << findMax(str1) << "\nstr2: " << findMax(str2) << std::endl;
    return 0;
}
