#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* iloc(char* line, int index)
{
    return NULL;
}
int main(int argc, char* argv[])
{
    //test
    clock_t start =  clock();
    //2 arg = path to dataFile
    char const* const dataFile = argv[1];
    //3 arg = column index
    long index = strtol(argv[2], NULL, 10);

    FILE* hFile = fopen(dataFile, "r") ;
    
    char curLine[256];
    printf("read column index %ld\n", index);

    while (fgets(curLine, sizeof(curLine), hFile)){
        //printf("%s", curLine);
        char* tmp = strdup(curLine);

        free(tmp);    
    }
    fclose(hFile);

    clock_t end = clock();
    printf("elapsed time: [%.2f]ms\n", (double)((end-start)*1000/CLOCKS_PER_SEC));

    return 0;
}