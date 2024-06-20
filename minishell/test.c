/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:02:22 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/20 14:02:29 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>

#define MAX_CMD_LEN 100
#define MAX_ARGS 10

// Function to find the full path of a command
char* find_command_in_path(char *command, char **envp) {
    char *path_env = NULL;
    for (int i = 0; envp[i] != NULL; i++) {
        if (strncmp(envp[i], "PATH=", 5) == 0) {
            path_env = envp[i] + 5;
            break;
        }
    }

    if (path_env == NULL) {
        return NULL;
    }

    char *path = strdup(path_env);
    char *token = strtok(path, ":");
    char full_path[1024];

    while (token != NULL) {
        snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
        if (access(full_path, X_OK) == 0) {
            free(path);
            return strdup(full_path);
        }
        token = strtok(NULL, ":");
    }

    free(path);
    return NULL;
}

void execute_command(char *cmd, char **envp) {
    char *args[MAX_ARGS];
    int i = 0;

    // Split command into arguments
    args[i++] = strtok(cmd, " ");
    while ((args[i++] = strtok(NULL, " ")) != NULL) {
        if (i >= MAX_ARGS - 1) break;
    }
    args[i] = NULL;

    if (args[0] != NULL) {
        char *path = find_command_in_path(args[0], envp);

        if (path != NULL) {
            // Use execve to execute the command
            if (execve(path, args, envp) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else {
            fprintf(stderr, "Command not found: %s\n", args[0]);
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char *argv[], char *envp[]) {
    char *command;

    while (1) {
        command = readline("Shell> ");
        if (!command) {
            break;
        }
        if (strlen(command) > 0) {
            add_history(command);
        }

        char *commands[MAX_CMD_LEN];
        int num_pipes = 0;

        // Split by pipes
        char *token;
        token = strtok(command, "|");
        while (token != NULL) {
            commands[num_pipes++] = token;
            token = strtok(NULL, "|");
        }
        commands[num_pipes] = NULL;

        int pipefds[2 * (num_pipes - 1)];
        pid_t pid;
        int status;
        int i;

        // Set up pipes
        for (i = 0; i < num_pipes - 1; i++) {
            if (pipe(pipefds + i * 2) == -1) {
                perror("pipe");
                exit(EXIT_FAILURE);
            }
        }

        for (i = 0; i < num_pipes; i++) {
            pid = fork();
            if (pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                // Child process

                // If not the first command, get input from previous pipe
                if (i > 0) {
                    if (dup2(pipefds[(i - 1) * 2], 0) == -1) {
                        perror("dup2");
                        exit(EXIT_FAILURE);
                    }
                }

                // If not the last command, send output to next pipe
                if (i < num_pipes - 1) {
                    if (dup2(pipefds[i * 2 + 1], 1) == -1) {
                        perror("dup2");
                        exit(EXIT_FAILURE);
                    }
                }

                // Close all pipe fds
                for (int j = 0; j < 2 * (num_pipes - 1); j++) {
                    close(pipefds[j]);
                }

                // Execute command
                execute_command(commands[i], envp);
            }
        }

        // Parent process
        // Close all pipe fds
        for (i = 0; i < 2 * (num_pipes - 1); i++) {
            close(pipefds[i]);
        }

        // Wait for all child processes
        for (i = 0; i < num_pipes; i++) {
            wait(&status);
        }

        free(command);
    }

    return 0;
}
