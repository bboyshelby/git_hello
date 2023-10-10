#include <iostream>

int num_lenght(int num){
    if (num == 0){
        return 1;
    }

    int result = 0;
    while (num != 0){
        result += 1;
        num /= 8;
    }
    return result;
}


char* from_oct_to_str(int num) {
  
    int need_add_memory;

    bool negative;
    if (num < 0){
        need_add_memory = 2;
        negative = true;
        num = -num;
    } else {
        need_add_memory = 1;
        negative = false;
    }

    int start_lenght = 3;
    if (negative){
        start_lenght += 1;
    }

    start_lenght += num_lenght(num);

    char* result = new char[start_lenght];


    for (int index = start_lenght - 2; index > need_add_memory; --index){
        int res = num % 8;
        char symbol = res + '0';
        result[index] = symbol;
        num /= 8;
    }


    if (negative){
        result[0] = '-';
        result[1] = '0';
        result[2] = 'o';
    } else {
        result[0] = '0';
        result[1] = 'o';
    }

    result[start_lenght - 1] = '\0';


    return result;
}

int main(){
    int n;
    std::cin >> n;
    std::cout << from_oct_to_str(n) << std::endl;
    return 0;
}