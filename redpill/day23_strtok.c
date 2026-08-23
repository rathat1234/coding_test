# include <stdio.h>
# include <stdbool.h>

void my_strtok(const char* data, char delimiter){
    static const char* func_data = NULL;
    static int num = 1;

    bool isDelimiter = false;
    int index = 0;

    if(func_data==NULL)
        func_data = data;
    
    while(!isDelimiter)
    {
        if(func_data[index]==','||func_data[index]=='\0'){
            isDelimiter = true;
            printf("Token %d : %.*s\r\n",num,index,func_data);
            func_data = func_data + (++index);
            num++;
        }
        else{
            index++;
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("=== Day 23: Safe String Tokenizer (static) ===\r\n\r\n");

    char mydata[46] = "GPS,37.5665,126.9780,20260213";
    char delimiter = ',';

    printf("Input Data: \"%s\"\r\n",mydata);
    printf("Delimiter : \'%c\'\r\n\r\n",delimiter);

    my_strtok(mydata, delimiter);
    my_strtok(NULL, delimiter);
    my_strtok(NULL, delimiter);
    my_strtok(NULL, delimiter);
    
    printf("\r\n");
    printf("Input Data: \"%s\"\r\n",mydata);
    printf(">> (Original string remains unmodified)");

    return 0;
}



