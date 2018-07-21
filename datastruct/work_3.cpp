//把一个十进制的数转换为一个二进制的数，例如9转换为二进制是1001，可以使用栈来实现。
//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

#include<iostream>
#include<stack>
#include<stdlib.h>

int main(){
    std::stack<int> binary;
    int decimal = 19;
    int temp = decimal;
    ldiv_t result;
    do{
        result = ldiv(temp, 2);
        //std::cout << result.quot << " " << result.rem << std::endl;
        temp = result.quot;
        binary.push(result.rem);
    }while(temp >= 1);

    std::cout << "The binary of decimal " << decimal << " is ";
    while(!binary.empty()){
        std::cout << binary.top();
        binary.pop();
    }
    std::cout << std::endl;
}
