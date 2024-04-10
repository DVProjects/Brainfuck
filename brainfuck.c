#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DATA_SIZE 30000

uint8_t data[DATA_SIZE] = {0};
uint8_t *data_ptr = data;
uint8_t *data_start = data;
uint8_t *data_end = data+DATA_SIZE;
FILE* file;

void execute(void){
	int c;
	while (1) {
		if (feof(file))break;
		c = fgetc(file);
		switch (c) {
			case '+':
				(*data_ptr)++;
				break;
			case '-':
				(*data_ptr)--;
				break;
			case '>':
				if (data_ptr != data_end)data_ptr++;
				break;
			case '<':
				if (data_ptr != data_start)data_ptr--;
				break;
			case '.':
				putchar(*data_ptr);
				break;
			default://comment found
		}
	}
}

int main(int argc, char *argv[]){
	for (int i = 1; i < argc; i++){
		file = fopen(argv[i],"r");
		if (!file){
			fprintf(stderr, "\"%s\" not found\n",argv[i]);
			break;
		}
		execute();
		fclose(file);
	}
	return 0;
}
