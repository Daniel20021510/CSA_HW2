//
// Created by Даниил Лесь on 09.01.2022.
//

#include "bush.h"
#include "../functions/additional_functions .h"

const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int bush::ReadInput(FILE *input_file) {
    plant::ReadInput(input_file);
    int flowering_month;

    int argc = fscanf(input_file, "%d\n", &flowering_month);

    if (argc != 1){
        printf("Error: Could not read bush flowering month.\n");
        return 1;
    }

    if (flowering_month < 1 || flowering_month > 12){
        printf("Error: Incorrect bush flowering month.\n");
        return 1;
    }

    this->flowering_month = (bush::Flowering_month) flowering_month;

    return 0;
}

void bush::Out(FILE* output_file){
    fprintf(output_file, "Bush: name - %s, vowels per length = %f, flowering month - %s.\n", name, VowelsPerSize(), PrintFloweringMonth());
}

void bush::RandomInput(){
    flowering_month =(bush::Flowering_month) RandomInt(13);
    name = RandomString();
    printf("2 %s %d\n", name, flowering_month);
}

const char* bush::PrintFloweringMonth() {
    switch (flowering_month) {
        case bush::Jan:
            return months[0];
        case bush::Feb:
            return months[1];
        case bush::Mar:
            return months[2];
        case bush::Apr:
            return months[3];
        case bush::May:
            return months[4];
        case bush::Jun:
            return months[5];
        case bush::Jul:
            return months[6];
        case bush::Aug:
            return months[7];
        case bush::Sep:
            return months[8];
        case bush::Oct:
            return months[9];
        case bush::Nov:
            return months[10];
        case bush::Dec:
            return months[11];
    }
}