#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

uint64_t is_number(char* argv[])
{
    uint64_t number;
    char symbol;
    int result = sscanf(argv[1], "%lu%c", &number, &symbol);

    if (result == 1) {
        return number;
    } else {
        printf("Error. You must enter number!\n");
        exit(EXIT_FAILURE);
    }
}


uint64_t check_available_input(int argc, char* argv[])
{
    if (argc > 2) {
        printf("Error. You must enter only one argument!\n");
        exit(EXIT_FAILURE);
    }

    if (argc == 1) {
        srand(time(NULL));

        uint64_t number = 
            ((uint64_t) rand()) << 48 | 
            ((uint64_t) rand()) << 32 |
            ((uint64_t) rand()) << 16 |
            ((uint64_t) rand());
            
        return number;
    }

    uint64_t number = is_number(argv);
    return number;
}


void get_binary_number(uint64_t number)
{
    /* 
    "У нас есть 64-битное число. Мы 64 раза проходим по циклу, каждый раз сдвигая число так, чтобы очередной бит (начиная со старшего) оказался самым правым. 
    Затем с помощью операции И с 1 мы 'вырезаем' только этот правый бит и записываем в переменную bit значение 0 или 1.
    Таким образом, мы по одному биту собираем всё двоичное представление, добавляя пробелы каждые 8 бит для удобства."
    */

    // Определяем количество бит в числе
    int bits = sizeof(number) * 8;

    // Проходим по всем битам от старшего к младшему
    for (int i = bits - 1; i >= 0; i--) {
        // Получаем 1-й бит с помощью сдвига и маски
        int bit = (number >> i) & 1;
        printf("%d", bit);

        // Добавляем пробел для удобства чтения каждые 8 бит
        if (i % 8 == 0 && i != 0) printf(" ");
    }
    printf("\n");

}

int main(int argc, char* argv[])
{
    uint64_t number = check_available_input(argc, argv);
    get_binary_number(number);

    
    return 0;
}