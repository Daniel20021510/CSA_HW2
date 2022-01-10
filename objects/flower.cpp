//
// Created by Даниил Лесь on 09.01.2022.
//

#include "flower.h"
#include "../functions/additional_functions .h"

int flower::ReadInput(FILE *input_file) {
    plant::ReadInput(input_file);
    int flower_type;

    int argc = fscanf(input_file, "%d\n", &flower_type);

    if (argc != 1){
        printf("Error: Could not read bush flowering month.\n");
        return 1;
    }

    if (flower_type < 1 || flower_type > 3){
        printf("Error: Incorrect bush flowering month.\n");
        return 1;
    }

    this->flower_type = (flower::Flower_type) flower_type;

    return 0;
}

void flower::Out(FILE* output_file){
    fprintf(output_file, "Flower: name - %s, vowels per length = %f, flower type - %s.\n", name, VowelsPerSize(), PrintFlowerType());
}

void flower::RandomInput(){
    flower_type =(flower::Flower_type) RandomInt(4);
    name = RandomString();
    printf("3 %s %d\n", name, flower_type);
}

const char * flower::PrintFlowerType() {
    switch (flower_type) {
        case flower::Home:
            return "home";
        case flower::Garden:
            return "garden";
        case flower::Wild:
            return "wild";
    }
};
