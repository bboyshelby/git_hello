#include <iostream>

// Ошибки по стилю кода:
// Правлю первый и последний раз
// 1. Необходимо использовать camelCase либо under_score
// 2. Необходимо использовать const там, где это возможно
// 3. Добавляйте в .gitignore файлы, которые не должны попадать в репозиторий к примеру файлы сборки

// Можем собраться и подумать
// getbanka - название функции не соответствует ее действию -> правильно getIntLength
// Нужна ли нам эта функция вообще
// Максимальное int число 17777777777 -> 11 символов, следовательно мы можем выделить 11 + 3 символов
// 11 для числа 1 для знака два для 0x и один для \0
// Зато сложность нашего алгоритма будет O(n) где n - длина числа
// Мы же проходим по числу дважды, следовательно сложность O(2n), что конечно в глобальном смысле роли не играет
// Но все же

// Программа не собирается
// Имя файла не соответствует содержимому new.cpp??? мне вообще не понятно
// Отсутствует CMake проект
// Необходимо добавить в .gitignore файлы сборки
// Необходимо написать тесты используя assert()

// хау ту юз ассерт ?
// #include <cassert>
// assert(1 == 2);

int num_lenght(int num) { // length :)
    if (num == 0) {
        return 1;
    }

    int result = 0;
    while (num != 0) {
        result += 1;
        num /= 8;
    }
    return result;
}


char *from_oct_to_str(int num) {

    int need_add_memory;

    bool negative;
    if (num < 0) {
        need_add_memory = 2;
        negative = true;
        num = -num;
    } else {
        need_add_memory = 1;
        negative = false;
    }

    int start_lenght = 3;
    if (negative) {
        start_lenght += 1;
    }

    start_lenght += num_lenght(num);

    char *result = new char[start_lenght];


    for (int index = start_lenght - 2; index > need_add_memory; --index) {
        int res = num % 8;
        char symbol = res + '0';
        result[index] = symbol;
        num /= 8;
    }


    if (negative) {
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

int main() {
    int n;
    std::cin >> n;
    std::cout << from_oct_to_str((int)0x80000000) << std::endl;
    return 0;
}