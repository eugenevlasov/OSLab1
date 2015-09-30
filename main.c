#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main( int argc , char * argv[])
{
    
    pid_t pid;
    pid = fork();
    
    if(pid)
    {
        pid_t parentPID = getpid();
        pid_t parentCPID = pid;
        
        char parentNameFile[20];
        sprintf(parentNameFile, "file_%d.txt", parentPID);
        FILE *parentFile = fopen(parentNameFile, "wt");
        
        if(parentFile != NULL)
        {
            
            char innerParentFile[100];
            sprintf(innerParentFile, "Мой PID %d\n, PID моего ребенка %d\n.", parentPID, parentCPID);
            fputs(innerParentFile, parentFile);
            fclose(parentFile);
        }
        else
        {
            printf("Файл батюни не создался\n");
        }
        sleep(100);
    }
    else
    {
        pid_t childPID = getpid();
        pid_t childPPID = getppid();
        
        char childNameFile[20];
        sprintf(childNameFile, "file_%d.txt", childPID);
        FILE *childFile = fopen(childNameFile, "wt");
        
        if(childFile != NULL)
        {
            char innerChildFile[100];
            sprintf(innerChildFile, "Мой PID %d\n, PID моего батюни %d\n.", childPID, childPPID);
            fputs(innerChildFile, childFile);
            fclose(childFile);
        }
        else
        {
            printf("Файл ребенка не создался\n");
        }
        sleep(100);
    }
}
