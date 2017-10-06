#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	history file section
*/
FILE * historyFile;
FILE * logFile;
FILE * batchFile;


void open_history_file()
{
   //strcpy(history,"historyFile");
   //strcpy(file2,getenv("HOME"));
	//strcat(history,file2);
    historyFile = fopen ("/home/amira/Desktop/historyFile.txt","a");

}

FILE* get_history_file()
{
	// you should implement this function
    historyFile = fopen ("/home/amira/Desktop/historyFile.txt","r");
    if(historyFile==NULL){
        printf("YeS");
        open_history_file();
        historyFile = fopen ("/home/amira/Desktop/historyFile.txt","r");

    }

	return historyFile;
}

void close_history_file()
{
	// you should implement this function
	fclose(historyFile);
}


/*
	log file section
*/
void open_log_file()
{
	// you should implement this function

		logFile = fopen("/home/amira/Desktop/logFile.txt","a");

}

FILE* get_log_file()
{
	// you should implement this function
		logFile = fopen ("/home/amira/Desktop/logFile.txt","r");
    if(logFile==NULL){
        open_log_file();
        logFile = fopen ("/home/amira/Desktop/logFile.txt","r");

    }
        return logFile;
}


void close_log_file()
{
	// you should implement this function
	fclose(logFile);
}


/*
	CommandsBatch file section
*/
void open_commands_batch_file()
{
	// you should implement this function
		batchFile = fopen("batchFile,txt","a");

}

FILE* get_commands_batch_file()
{
	// you should implement this function
		batchFile = fopen ("batchFile.txt","r");
    if(batchFile==NULL){
        printf("YeS");
        open_commands_batch_file();
        batchFile = fopen ("batchFile.txt","r");

    }


	return batchFile;
}


void close_commands_batch_file()
{
	// you should implement this function
	fclose(batchFile);
}
