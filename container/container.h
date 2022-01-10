//
// Created by Даниил Лесь on 09.01.2022.
//

#ifndef CSA_HW2_CONTAINER_H
#define CSA_HW2_CONTAINER_H


#include <cstdio>
#include "../objects/plant.h"
#include "../objects/tree.h"
#include "../objects/bush.h"
#include "../objects/flower.h"

/*
 * Класс контейнера для хранения растений: дерево, куст и цветок.
 * максимальный размер хранения - 10000 элементов
 */
class container {
public:
    container();
    ~container();

    /*
     * Чтение элементов контейнера из входного файла.
     * @param: input_file - указатель на входной файл
     * @returns: 1 - если при чтении произошла ошибка, 0 - ОК.
    */
    int ReadInput(FILE *input_file);

    /*
     * Генерация рандомных элементов контейнера.
     * @param: size - кол-во элементов для рандомной генерации
     */
    void RandomInput(int size);

    /*
     * Получить текущий размер контейнера.
     * @returns: текущий размер контейнера.
     */
    int GetSize();

    /*
     * Добавление элемента в контейнер
     * @param: plant - указатель на объект Plant, который будет помещен в контейнер.
    */
    int Add(plant* plant);

    /*
     * Вывод элементов контейнера в выходной файл.
     * @param: output_file - указатель на выходной файл
    */
    void Out(FILE *output_file);


    /*
     * Сортировка элементов контейнера
     * @param: container - указатель на объект Container, элементы которого будут сортироваться.
    */
    void StraightInsertion();

private:
    int size;
    plant** plants;
};


#endif //CSA_HW2_CONTAINER_H
