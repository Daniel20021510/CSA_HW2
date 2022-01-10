#include <iostream>
#include <stdio.h>
#include  <time.h>
#include "container/container.h"
#include "flags_workwer/flags_worker.h"

int error_code;

int main(int argc, char* argv[]){
    time_t start, end;

    start = clock();

    if (argc < 5){
        if (argc == 2) {
            if (IsFlagCorrect(argv[1], kHelpFlag)) {
                printf(HELP_MESSAGE);
                exit(0);
            }
        }
        printf("Error: Incorrect flags or flags number");
        exit(1);
    }

    printf("Start\n");
    container container;

    int random_size = GetRandomSize(argc, argv);

    if (random_size == -1){
        printf("Read input file\n");
        FILE *input_file = GetInputFile(argc, argv);
        error_code = container.ReadInput(input_file);
        fclose(input_file);
    }else{
        printf("Generate random plants\n");
        // Для более лучшей генерации рандомных значений при разных запусках
        srand(static_cast<unsigned int>(time(0)));
        container.RandomInput(random_size);
    }

    if (error_code){
        printf("It was some error\n");
        return error_code;
    }

    FILE *output_file = GetOutputFile(argc, argv);
    fprintf(output_file, "Container contains: %d elements\n\n", container.GetSize());
    container.Out(output_file);

    fprintf(output_file, "\n===================================================================================\n");
    fprintf(output_file, "\n=============================== Straight Insertion  ===============================\n\n");
    printf("Sorting elements\n");
    container.StraightInsertion();
    container.Out(output_file);
    fclose(output_file);
    end = clock();
    printf("Stop\n");
    printf("Work time: %f\n", difftime(end, start) / CLOCKS_PER_SEC);

    return 0;
}
