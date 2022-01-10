//
// Created by Даниил Лесь on 09.01.2022.
//

#ifndef CSA_HW2_FLOWER_H
#define CSA_HW2_FLOWER_H


#include <cstdio>
#include "plant.h"

/*
 * Класс растения типа цветок.
 */
class flower : public plant {
private:
    enum Flower_type {
        Home = 1,
        Garden = 2,
        Wild = 3,
    } flower_type;

public:

    /*
     * Чтение полей цветка из входного файла.
     * @param: input_file - указатель на входной файл
     * @returns: 1 - если при чтении произошла ошибка, 0 - ОК.
    */
    int ReadInput(FILE *input_file) override;

    /*
     * Вывод полей цветка в выходной файл.
     * @param: output_file - указатель на входной файл
    */
    void Out(FILE * output_file) override;

    /*
     * Генерация рандомных полей цветка для записи в контейнер.
    */
    void RandomInput() override;

    /*
     * Название типа цветка (из перечеслителя в строку).
     * @returns: Строка - название месяца цветения куста
    */
    const char *PrintFlowerType();
};


#endif //CSA_HW2_FLOWER_H
