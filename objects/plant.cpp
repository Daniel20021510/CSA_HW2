//
// Created by Даниил Лесь on 09.01.2022.
//

#include "plant.h"
#include "tree.h"
#include "bush.h"
#include "flower.h"
#include "../functions/vowels_functions.h"

plant* plant::CreatePlant(FILE *input_file) {
    int plant_type = -1;

    int argc = fscanf(input_file, "%d ", &plant_type);

    if (argc != 1) {
        printf("Error: Could not read plant type or plant name.\n");
        return NULL;
    }

    plant* plant;

    switch (plant_type) {
        case TREE:
            plant = new tree();
            break;
        case BUSH:
            plant = new bush();
            break;
        case FLOWER:
            plant = new flower();
            break;
        default:
            printf("Incorrect plant type.\n");
            return NULL;
    }

    if (plant->ReadInput(input_file)){
        printf("Error: Such error while reading plant\n");
        return NULL;
    }

    return plant;
}

double plant::VowelsPerSize(){
    return (CountVowels(name) * 1.0) / StringSize(name);
}

int plant::ReadInput(FILE *input_file) {
    char name[255];

    int argc = fscanf(input_file, "%s ", name);
    if (argc != 1){
        printf("Error: Could not read plant name.\n");
        return 1;
    }

    this->name = (char *) malloc(255);
    strcpy(this->name, name);
}