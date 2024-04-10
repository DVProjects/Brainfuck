#include <stdio.h>
#include <stdlib.h>

unsigned char data_pointer[30000] = {0};
FILE* file;

void execute(void){
	while (1) {
		if (feof(file))break;
		fgetc(file);
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
