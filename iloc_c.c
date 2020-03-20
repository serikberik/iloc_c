#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "magic.h"

//return token from line[index]
char* iloc(char* line, int index)
{
	char* tok = strtok(line, "<> \t");
	while(tok!=NULL)
	{
		//countdown while not zero
		if(!index--)
		{
				//printf("%s\n",tok); //lldbg
				return tok;
		}

		tok=strtok(NULL,"<> \t\n");
	}
	return NULL;
}

int main(int argc, char* argv[])
{
    //2 arg = path to dataFile
    //3 arg = column index
	
	//file line
    char curLine[256];

	//column width
	int cell_size = 10;

	//column_heigth
	int column_nums = 10000000; 
	
	
    //speedtest
    clock_t start = clock();

    FILE* hFile = fopen(argv[1], "r");
    if (hFile == NULL) 
	{
			printf("fopen error\n"); 
			exit(1);
	}

	//allocate mem 7.9million line approx without relloc
	double *buffer = calloc(column_nums, sizeof(double));
	if(buffer==NULL)
	{
			printf("calloc error\n");
			exit(1);
	}
	
    //printf("read column index %s\n", argv[2]);

	int i = 0;
	double val=0;

	//walk through all line in file
    while (fgets(curLine, sizeof(curLine), hFile))
	{
        //printf("%s", curLine);
        char* tmp = strdup(curLine);
		char* token = iloc( tmp, atoi(argv[2]) );
		val = strtod(token, NULL);
		buffer[i++] = val;
        free(tmp);    
    }

	printf("current len(buffer): [%d]\n", i);
	//somecalculation(buffer, i, column_nums, cell_size);

    fclose(hFile);
	free(buffer);

    clock_t end = clock();
    printf("elapsed time: [%.2f]ms\n", (double)((end-start)*1000/CLOCKS_PER_SEC));

    return 0;
}
