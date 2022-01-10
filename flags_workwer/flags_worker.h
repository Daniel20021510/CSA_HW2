//
// Created by Даниил Лесь on 08.01.2022.
//

#ifndef CSA_HW2_FLAGS_WORKER_H
#define CSA_HW2_FLAGS_WORKER_H

#include <unistd.h>

#define HELP_MESSAGE    "CSA Homework 2. Plants with Straight Insertion.\n"                                 \
                        "Task: 13, Function: 10\n\n"                                                        \
                        "Program options:\n\n"                                                              \
                        "\t-i - Set input file\n"                                                           \
                        "\t-o - Set output file\n"                                                          \
                        "\t-r - Generate random input\n\n"                                                  \
                        "Examples: "                                                                        \
                        "\t-i input.txt -o output.txt\n"                                                    \
                        "\t-r 20 -o output.txt\n\n"                                                         \
                        "Input file specification:\n"                                                       \
                        "Input file starts with number of plants with int_32 type\n"                        \
                        "Plants contain fields:\n"                                                          \
                        "\tplant type: 1 - TREE, 2 - BUSH, 3 - FLOWER\n"                                    \
                        "\tplant name with char[] type and 255 max length\n"                                \
                        "\tEvery plant contain fields:\n"                                                   \
                        "\t\t TREE: age with int_64 type.\n"                                                \
                        "\t\t\t  example: `1 Christmas_tree 12` -> tree: (name = Christmas_tree, age = 12)\n"\
                        "\t\t BUSH: flowering month with int_32 type.\n"                                    \
                        "\t\t\t  example: `2 Raspberry 11` -> bush: (name = Raspberry, flowering month = November)\n"\
                        "\t\t Flower: flower type with int_32 type. (1 - home, 2 - garden, 3- wild)\n"      \
                        "\t\t\t  example: `3 Clever 1` -> flower: (name = Clever, flower type = home)\n"    \
                        "See example at /tests/example.txt"                                                 \

#define INPUT_FLAG_EXCEPTION_MESSAGE    "Error: Incorrect input flag syntax\n" \
                                        "Try '-h' command for more information.\n"

#define OUTPUT_FLAG_EXCEPTION_MESSAGE    "Error: Incorrect Output flag syntax\n" \
                                         "Try '-h' command for more information.\n"

#define RANDOM_FLAG_EXCEPTION_MESSAGE "Error: Incorrect random input flag syntax\n" \
                                        "Try '-h' command for more information.\n"


#define INPUT_FILE_NOT_EXIST_MESSAGE "Input file does not exist\n"


// Возможные флаги программы
const char* kHelpFlag = "-h";

const char* kInputFlag = "-i";

const char* kOutputFlag = "-o";

const char* kRandomFlag = "-r";

/*
 * Проверка флага на корректность
 * @param: input_flag - флаг, полученный программой
 * @param: right_flag - флаг, который соответствует возможному флагу
 * @returns: 0 - если произошла ошибка, 0 - ОК
 */
int IsFlagCorrect(const char* input_flag, const char* right_flag){
        if (strcmp(input_flag, right_flag) == 0)
            return 1;
    return 0;
}

/*
 * Найти флаг в аргументах, полученных программой
 * @param: argc - кол-во полученных флагов
 * @param: argv - полученные флаги
 * @returns: позиция флага в массиве аргументов
 */
int FindFlag(int argc, char* argv[], const char* right_flag){
    for (int i = 0; i < argc; ++i) {
        if (IsFlagCorrect(argv[i], right_flag))
            return i;
    }
    return -1;
}

/*
 * Открыть входной файл на чтение
 * @param: argc - кол-во полученных флагов
 * @param: argv - полученные флаги
 * @returns: Файл ввода открытый для чтения - ОК. Ошибка - завершение программы.
 *
 */
FILE* GetInputFile(int argc, char* argv[]){
    int input_flag_position = FindFlag(argc, argv, kInputFlag);

    if (input_flag_position != -1) {
        if (input_flag_position + 1 < argc) {
            if (access(argv[input_flag_position + 1], F_OK) != -1)
                return fopen(argv[input_flag_position + 1], "r");
            else{
                printf(INPUT_FILE_NOT_EXIST_MESSAGE);
                exit(1);
            }
        }
    }

    printf(INPUT_FLAG_EXCEPTION_MESSAGE);
    exit(1);
}

/*
 * Открыть выходной файл на запись. Если файл не существует, то он будет создан автоматически.
 * @param: argc - кол-во полученных флагов
 * @param: argv - полученные флаги
 * @returns: Файл ввода открытый для записи - ОК. Ошибка - завершение программы.
 *
 */
FILE* GetOutputFile(int argc, char* argv[]){
    int output_flag_position = FindFlag(argc, argv, kOutputFlag);
    if (output_flag_position != -1) {
        if (output_flag_position + 1 < argc) {
            return fopen(argv[output_flag_position + 1], "w");
        }
    }
    printf(OUTPUT_FLAG_EXCEPTION_MESSAGE);
    exit(1);
}

/*
 * Считать количество объектов для случайной генерации в контейнер
 * @param: argc - кол-во полученных флагов
 * @param: argv - полученные флаги
 * @returns: кол-во элементов для случайной генерации или -1 если генерация не требуется - ОК. Ошибка - завершение программы.
 *
 */
int GetRandomSize(int argc, char* argv[]){
    int random_flag_position = FindFlag(argc, argv, kRandomFlag);
    if (random_flag_position != -1){
        if (random_flag_position + 1 < argc) {
            int size = atoi(argv[random_flag_position + 1]);

            if (size <= 0){
                printf(RANDOM_FLAG_EXCEPTION_MESSAGE);
                printf("Size could not be equal or less then 0\n");
                exit(1);
            }
            return size;
        }
    }
    return -1;
}

#endif //CSA_HW2_FLAGS_WORKER_H
