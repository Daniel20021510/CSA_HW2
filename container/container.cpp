//
// Created by Даниил Лесь on 09.01.2022.
//

#include <cstring>
#include "container.h"
#include "../functions/additional_functions .h"


container::container() {
    size = 0;
    plants = new plant*[10000];
    for (int i = 0; i < 10000; ++i) {
        plants[i] = nullptr;
    }
}

container::~container() {
    for (int i = 0; i < size; ++i) {
        delete plants[i];
    }
    size = 0;
    delete plants;
}

int container::Add(plant *plant) {
    if (size > 10000) {
        printf("Container is full, cannot add any new plant\n");
        return 1;
    }
    plants[size++] = plant;
    return 0;
}

int container::ReadInput(FILE* input_file){
    int plants_number;
    int argc = fscanf(input_file, "%d\n", &plants_number);
    if (argc != 1){
        printf("Error: Could not read plants number.\n");
        return 1;
    }

    if (plants_number > 10000){
        printf("Error: Plants number too big. More then 10000.\n");
        return 1;
    }

    if (plants_number <= 0){
        printf("Error: Plants number cannot be less then 1.\n");
        return 1;
    }

    for(int i = 0; i < plants_number; ++i){
        plant* plant = plant::CreatePlant(input_file);
        if (!plant){
            printf("%d plant resulted in error.\n", i + 1);
            return 1;
        }
        Add(plant);
    }
    return 0;
}

int container::GetSize(){
    return size;
}

void container::RandomInput(int size){
    if (size > 10000){
        printf("Error: Plants number too big. More then 10000.\n");
        return;
    }

    if (size <= 0){
        printf("Error: Plants number cannot be less then 1.\n");
        return;
    }

    printf("%d\n", size);
    for(int i = 0; i < size; ++i) {
        plant* plant;
        int plant_type = RandomInt(4);

        switch (plant_type) {
            case plant::TREE:
                plant = new tree();
                break;
            case plant::BUSH:
                plant = new bush();
                break;
            case plant::FLOWER:
                plant = new flower();
                break;
        }

        plant->RandomInput();
        Add(plant);
    }
}

void container::StraightInsertion()
{
    for(int i = 0; i < size; ++i){
        plant* plant = plants[i];
        int j = i;
        while(j > 0 && plants[j-1]->VowelsPerSize() > plant->VowelsPerSize()){
            plants[j] = plants[j-1];
            j--;
        }
        plants[j] = plant;
    }
}

void container::Out(FILE* output_file) {
    for(int i = 0; i < size; ++i){
        fprintf(output_file, "[%d] ", i);
        plants[i]->Out(output_file);
    }
}
