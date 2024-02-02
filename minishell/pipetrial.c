#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }
// void	ft_putstr_fd(char *s, int fd)
// {
// 	int	i;

// 	i = -1;
// 	if (!s)
// 		return ;
// 	while (s[++i])
// 		ft_putchar_fd(s[i], fd);
// }

// void	ft_putnbr_fd(int n, int fd)
// {
// 	char	c;

// 	if (n == -2147483648)
// 		ft_putstr_fd("-2147483648", fd);
// 	else if (n < 0)
// 	{
// 		ft_putchar_fd('-', fd);
// 		n *= -1;
// 		ft_putnbr_fd(n, fd);
// 	}
// 	else if (n < 10)
// 	{
// 		c = n + 48;
// 		ft_putchar_fd(c, fd);
// 	}
// 	else
// 	{
// 		ft_putnbr_fd(n / 10, fd);
// 		c = (n % 10) + 48;
// 		ft_putchar_fd(c, fd);
// 	}
// }
// Function to write an error message to standard error (file descriptor 2)
int err(char *str) 
{
    while (*str)
        write(2, str++, 1); // Writing each character of the string to stderr
    return 1;
}

// Function to change the current directory
int cd(char **argv, int i) 
{
    if (i != 2)
        return err("error: cd: bad arguments\n"); // Return an error if the argument count is not 2
    else if (chdir(argv[1]) == -1)
        return err("error: cd: cannot change directory to "), err(argv[1]), err("\n"); // Return an error if directory change fails
    return 0; // Return 0 on success
}

// Function to execute a command
int exec(char **argv, char **envp, int i, int fd_in, int fd_out) 
{
    int fd[2];
    int status; 


    if (pipe(fd) == -1)
        return err("error: fatal\n"); // Return an error if pipe creation fails
    if (fd_in)
        dup2(fd_in, 0);
   
    int pid = fork(); // Create a child process
    if (!pid) 
    {
        argv[i] = 0; // Set the element after the pipe or semicolon to null
        if (fd_out)
            dup2(fd_out, 1);
        else if ((dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return err("error: fatal\n"); // Return an error if pipe redirection or closing fails
        execve(*argv, argv, envp); // Execute the command
        return err("error: cannot execute "), err(*argv), err("\n"); // Return an error if execution fails
    }
    waitpid(pid, &status, 0); // Wait for the child process to finish
    if ((dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return err("error: fatal\n"); // Return an error if pipe redirection or closing fails

    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **envp) 
{
    int    i = 0;
    int    status = 0;
    int     x = 0;
    int     y = 0;

    if (argc > 1) 
    {
        while (argv[i] && argv[++i]) 
        {
            argv += i; // Move the argv pointer forward by i
            i = 0; // Reset i to 0
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++; // Find the next pipe or semicolon or end of arguments
            if (!strcmp(*argv, "cd"))
                status = cd(argv, i); // Execute cd command
            else if (i)
                status = exec(argv, envp, i, x, open("test2.txt", O_RDWR)); // Execute other commands
        }
    }
    printf("%d", status);
    return status; // Return the status of the last executed command
}


// int main(void)
// {
//     int fd[2];
//     int pid1;
    

//     // if (pipe(fd) == -1)
//     //     return 1;

//     pid1 = fork();
    
//     if (pid1 < 0)
//         return 2;

//     if (pid1 == 0)
//     {
//         close(fd[0]);
//         // dup2(fd[1], STDOUT_FILENO);
//         execlp("/bin/bash", "bin/bash", (void*)0);
//         close(fd[1]);
//     }
//     waitpid(pid1, (void*)0, 0);
//     // return WIFEXITED(status) && WEXITSTATUS(status);
//     // dup2(fd[0], STDIN_FILENO);
//     close(fd[0]);
//     close(fd[1]);
//     // pipe(fd);
//     // pid1 = fork();

//     // if(pid1 < 0)
//     //     return 3;

//     // if (pid1 == 0)
//     // { 
//     //     close(fd[0]);
//     //     dup2(fd[1], STDOUT_FILENO);
//     //     execlp("grep", "grep","64" ,(void*)0);
//     //     close(fd[1]);
//     // }
//     // waitpid(pid1, (void*)0, 0);
//     // dup2(fd[0], STDIN_FILENO);
//     // close(fd[0]);
//     // close(fd[1]);

//     // pid1 = fork();

//     // if(pid1 < 0)
//     //     return 3;

//     // if (pid1 == 0)
//     // {
//     //     execlp("grep", "grep", "icmp_seq=3", (void*)0);
//     // }
    
//     waitpid(pid1, (void*)0, 0);
    
//     // waitpid(pid3, (void*)0, 0);
//     return 0;
// }


// // int main ()
// // {
// //     int pid;
// //     int fd[2] = pipe();

// //     while(next != NULL){
// //         pid = fork();
// //         if(pid == 0)
// //           child_work();
// //         else
// //             waitpid(pid, NULL, 0);
// //     }
    
// // }


// LISTA,  ,ENVP

