#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<wait.h>
#include<unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int Err = 0,andFlag=0;



void handler(int sig)
{
 if(!Err){
FILE* file = open_log_file();
  fputs("command\n",file);
  close_log_file();
}

  //printf("Pid exited.\n");
}








void parse_command( const char* command )
{  siginfo_t childstat;
   char *tmpCommand = strdup(command);

   const char s[2] = " ";
    char* commandParts[513];
    char *token;
    int i = 0 ;
    /* get the first token */
            andFlag=0;
            if(strlen(command)>0 && (char*)command[strlen(command)-1]=='&'){
             andFlag=1;
             printf("%d",andFlag);
            }
    token = strtok(command, s);


    FILE* file;

    /* walk through other tokens */
    while( token !='\0' )
    {    file = open_history_file();
        fputs(token,file);

        //commandParts[i] = malloc(513*sizeof(char));//each word is 30 chars
            commandParts[i] = token ;
            printf("here  %s \n",commandParts[i]);
            i++;
            token = strtok('\0', s);
            fputs(" ",file);
            close_history_file();

    }


    // check if not empty string
    if(i!=0){
                //printf("%c",command[strlen(command)-2]);

            file = open_history_file();
            fputs("\n",file);
            close_history_file();


            if(strcmp(commandParts[0],"cd") == 0||strcmp(commandParts[0],"echo") == 0){
                    if(strcmp(commandParts[0],"cd") == 0){
                    cd(commandParts[1]);
                    }
                    else {


                    echo(tmpCommand);

                    }

                    }


            else if (strstr(commandParts[0],"=\"")){
            //x="  hello "
            printf("what has just happened");
            const char s1[2] = "=\"";
            char* temp[513];
            int count = 0 ;
            token = strtok(tmpCommand, s1);
                    while( token !='\0' )
                    {

                    temp[count] = token ;
                    puts(temp[count]);
                    count++;
                    token = strtok('\0', s1);
                    }


            printf("\n\n",temp[0],temp[1]);
            set_variable( temp[0] , temp[1] );


            }


            else if (strstr(commandParts[0], "=") && (i==1 || i==2) ){
            //printf("try sth %d \n" , strstr(commandParts[0],"=\""));
            const char s1[2] = "=";
            char* temp[513];
            int count = 0 ;


            if (i==2 && strcmp(commandParts[1],"&")==0){
            // x=5 &
            /* walk through other tokens */
              printf("%s commandparts \n",commandParts[0]);
                    token = strtok(commandParts[0], s1);
                    while( token !='\0' )
                    {
                   //printf(" %s token \n",token);

                    //commandParts[i] = malloc(513*sizeof(char));//each word is 30 chars
                    temp[count] = token ;
                    printf("temp is count = %s",temp[count]);

                    count++;
                    token = strtok('\0', s1);

                    }
            }
            else if (i==1) {
            if(strstr(commandParts[0],"&")){

            //x=5&
            int x, j = 0;
            int size;
            char ch;

            char ch1[2] = "&";
            char str1[10];

            size = strlen(commandParts[0]);
            char *str;
            str = commandParts[0];

            for (x = 0; x < size; x++) {
            //printf("\n\n %d \n\n" ,);
                if (str[x]!='&') {
                    ch = str[x];
                    str1[j] = ch;
                    j++;

                }
                else {
                break ;
                }
            }
            str1[j] = '\0';
            printf(" >>>>> %s am ia ",str1);
            token = strtok(str1, s1);
           //working
           count = 0;
                    while( token !='\0' )
                    {
                     printf("\n %s token \n",token);
                    temp[count] = token ;
                    printf("temp is count = %s",temp[count]);

                    count++;
                    token = strtok('\0', s1);

                    }

            }
            else {
            //x=5
            token = strtok(commandParts[0], s1);
           //working
           count = 0;
                    while( token !='\0' )
                    {
                     printf("\n %s token \n",token);
                    temp[count] = token ;
                    printf("temp is count = %s",temp[count]);

                    count++;
                    token = strtok('\0', s1);

                    }

            }


            }

            printf("here before go ");
            set_variable( temp[0] , temp[1] );
             }
            else if(strstr(commandParts[0],"gedit")||strstr(commandParts[0],"vi")
            ||strstr(commandParts[0],"vim"))
            {
            signal(SIGCHLD,handler);
            pid_t pid = fork();
            if(!pid){
            system(tmpCommand);

            }
            else {
            if(!andFlag)
            waitid(P_PID,pid,&childstat,WEXITED);

            }

            }

            else if (i==1 && strcmp(commandParts[0],"history") == 0){
                    FILE* file = get_history_file();
                    char c ;
                    c = getc(file);

                    while(c!=EOF){
                       printf("%c",c);
                       c = getc(file);

                    }

                        close_history_file();


            }
            else if (*commandParts[0]=='#'){
            }
            else {
                commandParts[i]=NULL;
                // check is has \bin
                if (!strstr(commandParts[0], "/bin/")){
                        printf("aywa\n");
                        char *tmp = strdup(commandParts[0]);
                        commandParts[0]= malloc(30*sizeof(char));
                    strcpy(commandParts[0], "/bin/"); //Put str2 or anyother string that you want at the begining
                    strcat(commandParts[0], tmp);  //concatenate previous str1
                    free(tmp); //free the memory

                }
                // this directory as parameter
                signal(SIGCHLD,handler);
                pid_t pid = fork();
                if(pid == 0){
                //printf(">>>>>>>>>>> %d",andFlag);

                if(andFlag){
                int x, j = 0;
            int size;
            char ch;

            char ch1[2] = "&";
            char str1[10];

            size = strlen(commandParts[i-1]);
            char *str;
            str = commandParts[i-1];

            for (x = 0; x < size; x++) {
            //printf("\n\n %d \n\n" ,);
                if (str[x]!='&') {
                    ch = str[x];
                    str1[j] = ch;
                    j++;

                }
                else {
                break ;
                }
            }
            if(strcmp(str1,"")!=0){
            commandParts[i-1]=str1;
           // printf(">%s", commandParts[i-1]);
           }

            else{
                        //printf("%s", commandParts[i-1]);
                       commandParts[i-1]=NULL;
            }
                execv(commandParts[0],commandParts);
                perror ("execv");
                 Err = 1;
                }
                else{
                printf("%s",commandParts[1]);
                execv(commandParts[0],commandParts);
                perror ("execv");
                 Err = 1;
                }

                }

                else {

                  if(!andFlag)
                waitid(P_PID,pid,&childstat,WEXITED);

                }





            }



    }

}

