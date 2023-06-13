#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    //Fork a child process using vfork()
    pid=vfork();
    if(pid==-1)
    {
        perror("vfork");
        return 1;
    }
    else if(pid==0)
    {
        //Forking 
    printf("Child process:Hello I'm the child\n");
     printf("Child process:My pid is %d\n",getpid());
      printf("Child process:My Parent's pid is %d\n",getpid());
      _exit(0);
}
else 
{
    printf("Parent process:Hello,I'm the parent!\n");
     printf("Parent process:My pid is %d\n",getpid());
      printf("Parent process:My Child's pid is %d\n",pid);
      int status;
      waitpid(pid,&status,0);
      if(WIFEXITED(status)){
        printf("Parent process:Child process terminated abnoormally.\n");
      }
      }
      return 0;
}




