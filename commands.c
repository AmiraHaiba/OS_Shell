#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void cd( const char* path )
{   char *myPath;
	// you should implement this function
            int x, j = 0;
            int size;
            char ch;

            char str1[10];

            size = strlen(path);
            char *str;
            str = path;

            for (x = 0; x < size; x++) {
            //printf("\n\n %d \n\n" ,);
                if (str[x]!='&') {
                    ch = str[x];
                    str1[j] = ch;
                    j++;

                }

            }
            path = str1;
            //printf("3aaaaaaaaaaaaaaaaaaa %s        ",path);

	if(chdir(path)==-1)
	printf("No such directory");
	else{
	 myPath = path;
    //printf("my directory is %s", path);
	}

}


void echo( const char* message )
{           int x, j = 0,flag = 1;
            int size;
            char ch;
            char str1[10];
            printf("%s",message);
            size = strlen(message);
            char *str;
            str = message;

            for (x = 0; x < size; x++) {
            //printf("\n\n %d \n\n" ,);
                 if(flag){
                 if (str[x]!='$'||str[x]!='"' ) {
                    printf("%c",str[x]);

                }
                else if (str[x]=='$') flag=0;
                 }

                else {
                if (str[x]!=' ' ) {
                    ch=str[x];
                    str1[j]=ch;
                    j++;

                }
                else {
            printf("%c",str[x]);
            flag = 1 ;

                }

                }
            }
            str1[j] = '\0';

	// you should implement this function
}
