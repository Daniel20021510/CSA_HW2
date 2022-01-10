//
// Created by Даниил Лесь on 07.01.2022.
//

#ifndef CSA_HW1_VOWELS_FUNCTIONS_H
#define CSA_HW1_VOWELS_FUNCTIONS_H

const char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};

/*
 * Узнать длину строки.
 * @param: string - строка, длину которой нужно вычислить.
 * @returns: число с плавающей точкой - длина строки.
 */
double StringSize(char string[]) {
    int chars_number = 0;
    while (string[chars_number] != '\0') {
        chars_number++;
    }
    return chars_number;
}

/*
 * Узнать количество гласных букв в строке.
 * @param: string - строка, количество гласных букв которой нужно вычислить.
 * @returns: число с плавающей точкой - количество гласных букв строки.
 */
double CountVowels(char string[]) {
    int vowels_number = 0;
    for (int i = 0; i < StringSize(string); ++i) {
        for (int j = 0; j < 12; ++j) {
            if (string[i] == vowels[j])
                vowels_number++;
        }
    }
    return vowels_number;
}

#endif //CSA_HW1_VOWELS_FUNCTIONS_H
