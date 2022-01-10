//
// Created by Даниил Лесь on 09.01.2022.
//

#include "tree.h"
#include "../functions/additional_functions .h"

int tree::ReadInput(FILE *input_file)  {
    plant::ReadInput(input_file);
    long long age;

    int argc = fscanf(input_file, "%lld\n", &age);

    if (argc != 1){
        printf("Error: Could not read tree age.\n");
        return 1;
    }

    this->age = age;

    return 0;
}

void tree::Out(FILE* output_file){
    fprintf(output_file, "Tree: name - %s, vowels per length = %f, age - %lld.\n", name, VowelsPerSize(), age);
}

void tree::RandomInput(){
    age = RandomInt(10000);
    name = RandomString();
    printf("1 %s %lld\n", name, age);
}