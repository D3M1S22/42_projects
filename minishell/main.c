
// #include "include/minishell.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// void test(int a)
// {
// 	printf("%d\n", a);
// }


// int	main(int argc, char const **argv, char **const envp)
// {
// 	// int		f1;
// 	// int		f2;
// 	// t_pipex	*pipex_s;
// 	// char *args[] = {"infile", ">", "damiano.txt", NULL};
// 	// execve("/bin/cat", args , NULL);
// 	// if (argc < 5)
// 	// {
// 	// 	msg("Not enough arguments\n");
// 	// 	return (1);
// 	// }
	
// 	// pipex_s = (t_pipex *)malloc(sizeof(t_pipex));
// 	// if (handle_files(argv[1], pipex_s, argv[2], argv[argc - 1]) == 1)
// 	// {
// 	// 	free(pipex_s);
// 	// 	return (-1);
// 	// }
// 	char *res;
// 	while(1)
// 	{
// 		res = readline("Minishell >");
// 		// pipex_s->here_doc = 0; // TO REMOVE
// 		// pipex_s->n_cmds = argc - 3 - pipex_s->here_doc;
// 		// pipex_s->n_pipes = 2 * (pipex_s->n_cmds - 1);
// 		// pipex_s->log_files = create_log_files(pipex_s->n_cmds);
// 		pipex(res, envp);
// 		free(res);
// 	}
// 	return (0);
// }


#include <stdlib.h>   
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 100

#define MAX_NUM_PARAMS 10

int parsecmd(char* cmd, char** params) { //split cmd into array of params
    int i,n=-1;
    for(i=0; i<MAX_NUM_PARAMS; i++) {
        params[i] = strsep(&cmd, " ");
        n++;
        if(params[i] == NULL) break;
    }
    return(n);
};

int executecmd(char** params) {
    pid_t pid = fork(); //fork process

    if (pid == -1) { //error
        char *error = strerror(errno);
        printf("error fork!!\n");
        return 1;
    } else if (pid == 0) { // child process
        execvp(params[0], params); //exec cmd
        char *error = strerror(errno);
        printf("unknown command\n");
        return 0;
    } else { // parent process
        int childstatus;
        waitpid(pid, &childstatus, 0);    
        return 1;
    }
};

int execpipe (char ** argv1, char ** argv2) {
    int fds[2];
    pipe(fds);
    int i;
    pid_t pid = fork();
    if (pid == -1) { //error
        char *error = strerror(errno);
        printf("error fork!!\n");
        return 1;
    } 
    if (pid == 0) { // child process
        close(fds[1]);
        dup2(fds[0], 0);
        //close(fds[0]);
        execvp(argv2[0], argv2); // run command AFTER pipe character in userinput
        char *error = strerror(errno);
        printf("unknown command\n");
        return 0;
    } else { // parent process
        close(fds[0]);
        dup2(fds[1], 1);
        //close(fds[1]);
        execvp(argv1[0], argv1); // run command BEFORE pipe character in userinput
        char *error = strerror(errno);
        printf("unknown command\n");
        return 0;
    }
};


int main() {    
    char cmd[MAX_CMD_LENGTH+1];    
    char * params[MAX_NUM_PARAMS+1];    
    char * argv1[MAX_NUM_PARAMS+1] = {0};    
    char * argv2[MAX_NUM_PARAMS+1] = {0};    
    int k, y, x;    
    int f = 1;    
    while(1) {
        printf("$"); //prompt    
        if(fgets(cmd, sizeof(cmd), stdin) == NULL) break; //read command, ctrl+D exit       
        if(cmd[strlen(cmd)-1] == '\n') { //remove newline char    
            cmd[strlen(cmd)-1] = '\0';    
        }    
        int j=parsecmd(cmd, params); //split cmd into array of params           
        if (strcmp(params[0], "exit") == 0) break; //exit   
        for (k=0; k <j; k++) { //elegxos gia uparksi pipes    
            if (strcmp(params[k], "|") == 0) {    
                f = 0; y = k;      
               printf("pipe found\n");
               break;
            }               
        }
        if (f==0) {
            for (x=0; x<k; x++) {    
               argv1[x]=params[x];
            }     
            int z = 0;     
            for (x=k+1; x< j; x++) {     
                argv2[z]=params[x];
                z++;
            }     
            if (execpipe(argv1, argv2) == 0) break;    
         } else if (f==1) {     
             if (executecmd(params) == 0) break;
         }
    } // end while
    return 0;
}