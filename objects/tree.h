//
// Created by Даниил Лесь on 09.01.2022.
//

#ifndef CSA_HW2_TREE_H
#define CSA_HW2_TREE_H

#include <fstream>
#include "plant.h"

/*
 * Класс растения типа дерево.
 */
class tree : public plant{
public:

    /*
     * Чтение полей дерева из входного файла.
     * @param: input_file - указатель на входной файл
     * @returns: 1 - если при чтении произошла ошибка, 0 - ОК.
    */
    int ReadInput(FILE* input_file) override;

    /*
     * Вывод полей дерева в выходной файл.
     * @param: output_file - указатель на входной файл
    */
    void Out(FILE* output_file) override;

    /*
     * Генерация рандомных полей дерева для записи в контейнер.
    */
    void RandomInput() override;


private:
    long long age;
};

#endif //CSA_HW2_TREE_H
