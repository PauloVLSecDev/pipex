/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:41:36 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/24 20:05:07 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main (int argc, char *argv[], char **env)
{
	int	pipe_fd[2];
	pid_t	pid;

	if(argc != 5)
		exit_with_menssage("erro nos parametros passados", 2);
	if (pipe(pipe_fd) == -1)
		exit_with_menssage("error in function pipe", 111);
	pid = fork();
	if (pid == 0)
		child_process(pipe_fd, argv, env);
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0); 
		parent_process(pipe_fd, argv,  env);
	}
	else
		perror(" erro ao fazer o fork");
	return (0);
}
