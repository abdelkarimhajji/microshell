// #include <unistd.h>

//    #include <stdio.h>

// int main() {
//     pid_t child_pid = fork();

//     if (child_pid == 0) {
//         // Code for the child process
//         printf("Hello from the child process!\n");
//     } else if (child_pid > 0) {
//         // Code for the parent process
//         printf("Hello from the parent process! Child PID: %d\n", child_pid);
//     } else {
//         // An error occurred
//         perror("fork");
//         return 1;
//     }

//     // This code will be executed by both the parent and child processes

//     return 0;
// }


#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pid_t pid;

    // Create the pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        close(fd[1]); // Close the write end of the pipe

        char buffer[128];
        read(fd[0], buffer, sizeof(buffer)); // Read from the pipe
        printf("Child read: %s\n", buffer);

        close(fd[0]); // Close the read end of the pipe
    } else {
        int fff;
 
        // Parent process
        close(fd[0]); // Close the read end of the pipe

        const char *message = "Hello, child!";
        write(fd[1], message, strlen(message) + 1); // Write to the pipe

        // waitpid(pid, &fff, 0);
        close(fd[1]); // Close the write end of the pipe
    }

    return 0;
}