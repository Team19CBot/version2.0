#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "abstractDataType.h"
#include "function.h"
using namespace std;

#define MAXLEN 1024*4

char* getcgidata(FILE* fp, char* requestmethod);

int main(){
        
        T_BST *head = cons_topic_from_file();
        printf( "Content-type: text/html;charset=utf-8\n\n" );
        
        char *req_method = getenv("REQUEST_METHOD");
        char *cgi_str = getcgidata(stdin, req_method);
        string question = cgi_str;
        string answer = match2(question, head);
        
        fprintf(stdout,"%s",answer.c_str());
        
        // 接收到关闭的信号
        // 调用 free_all(head);
        
}

char* getcgidata(FILE* fp, char *requestmethod)
{
        char* input;
        int len;
        int size = MAXLEN;
        int i = 0;
        
        if (!strcmp(requestmethod, "GET"))
        {
                input = getenv("QUERY_STRING");
                return input;
        }
        else if (!strcmp(requestmethod, "POST"))
        {
                len = atoi(getenv("CONTENT_LENGTH"));
                input = (char*)malloc(sizeof(char)*(size + 1));
                
                if (len == 0)
                {
                        input[0] = '\0';
                        return input;
                }
                
                while(1)
                {
                        input[i] = (char)fgetc(fp);
                        if (i == size)
                        {
                                input[i+1] = '\0';
                                return input;
                        }
                        
                        --len;
                        if (feof(fp) || (!(len)))
                        {
                                i++;
                                input[i] = '\0';
                                return input;
                        }
                        i++;
                        
                }
        }
        return NULL;
}
