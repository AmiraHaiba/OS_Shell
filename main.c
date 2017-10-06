#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum{ false = 0 , true = 1 } bool ;

void start_shell(bool read_from_file);
void shell_loop(bool input_from_file);
char command[513];
char fileName[14] ;


int main(int argc, char *argv[])
{

 //   setup_environment();

    // any other early configuration should be here
        printf("here");

    if(true){
    //if( argc > 1 ){
    printf("here");
        start(true);
    }
    else{
        start(false);
    }

    return 0;
}

void start(bool read_from_file)
{
	cd(getenv("HOME")); // let shell starts from home
	if(read_from_file){

		// file processing functions should be called from here


		shell_loop(true);
	}
	else{

		shell_loop(false);
	}
}

void shell_loop(bool input_from_file)
{
	bool from_file = input_from_file;

	while(true){
        // azawed w a check >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

		if(from_file){
		strcpy(fileName,"/home/amira/Desktop/batchFile.txt");
		FILE* file ;
		file = fopen(fileName,"r");
		const size_t line_size = 513;
        char* line = malloc(line_size);
        while(fgets(line, line_size, file) != NULL)  {
        printf(line);
        parse_command(line);
        }
        free(line);
			//read next instruction from file

			from_file = false; continue;
		}
		else{
			//read next instruction from console
			printf("\nShell>");
            gets(command);
            parse_command(command);

		}


		//parse your command here

		//execute your command here

		/*
			you don't need to write all logic here, a better practice is to call functions,
			each one contains a coherent set of logical instructions
		*/


	}
}
