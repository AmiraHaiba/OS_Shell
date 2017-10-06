char *keys[5000];
char *values[5000];
int counter = 0,flag = 0;
const char* lookup_variable( const char* key )
{
	// you should implement this function
	int i = 0 ;
	for(int i=0; i <counter ; i++){
        if(strcmp(keys[i],key)==0){
            return keys[i];
        }
	}
	return "Variable is not found" ;
}

void set_variable( const char* key , const char* value )
{
	// you should implement this function
	if(counter == 0){
	keys[counter]=key;
	values[counter]=value;

	}
	else{
	for(int i=0; i <counter ; i++){
        if(strcmp(keys[i],key)==0){
            printf("\n before %s %d\n ",values[i],i);
            values[i]=value;
            printf("\n afteer %s \n",values[i]);
            counter--;
            flag = 1;
        }
	}
	if (flag==0){
	keys[counter]=key;
	values[counter]=value;
	}
	flag=0;
	}
	printf("ana gowaa %s %s",keys[counter],values[counter]);
    counter++;

}

void print_all_variables( void )
{
	// you should implement this function
}
