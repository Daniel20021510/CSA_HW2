//
// Created by Даниил Лесь on 09.01.2022.
//

#ifndef CSA_HW2_BUSH_H
#define CSA_HW2_BUSH_H


#include <cstdio>
#include "plant.h"

/*
 * Класс растения типа куст.
 */
class bush : public plant{
private:
    enum Flowering_month {
        Jan = 1,
        Feb = 2,
        Mar = 3,
        Apr = 4,
        May = 5,
        Jun = 6,
        Jul = 7,
        Aug = 8,
        Sep = 9,
        Oct = 10,
        Nov = 11,
        Dec = 12,
    } flowering_month;

public:

    /*
     * Чтение полей куста из входного файла.
     * @param: input_file - указатель на входной файл
     * @returns: 1 - если при чтении произошла ошибка, 0 - ОК.
    */
    int ReadInput(FILE* input_file) override;

    /*
     * Вывод полей куста в выходной файл.
     * @param: output_file - указатель на входной файл
    */
    void Out(FILE* output_file) override;

    /*
     * Генерация рандомных полей куста для записи в контейнер.
    */
    void RandomInput() override;

    /*
     * Название месяца цветения (из перечеслителя в строку).
     * @returns: Строка - название месяца цветения куста
    */
    const char* PrintFloweringMonth();
    
};


#endif //CSA_HW2_BUSH_H
