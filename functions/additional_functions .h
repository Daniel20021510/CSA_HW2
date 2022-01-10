//
// Created by Даниил Лесь on 07.01.2022.
//

#ifndef CSA_HW2_ADDITIONAL_FUNCTIONS_H
#define CSA_HW2_ADDITIONAL_FUNCTIONS_H

#include "random"

const char alphabet[] = "qwertyuiopasdfghjklzxcvbnm";

/*
 * Сгенерировать рандомное целое число типа int_32.
 * @param: min - левая граница - включена.
 * @param: max - правая граница - не включена.
 * @returns: рандомное целое число.
 */
static int RandomInt(int max, int min = 1){
    return min + rand() % (max - min);
}

/*
 * Сгенерировать рандомную строку.
 * @returns: рандомная строка.
 */
static char *RandomString(){
    int len = RandomInt(15);
    char *string = new char[len];
    for (int i = 0; i <= len; ++i) {
        string[i] = alphabet[RandomInt(25, 0)];
    }
    return string;
}

#endif //CSA_HW2_ADDITIONAL_FUNCTIONS_H
