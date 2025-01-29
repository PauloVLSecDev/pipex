/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:41:36 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/28 16:36:38 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main (int argc, char *argv[], char **env)
{
	int	pipe_fd[2];
	pid_t	pid;

	if(argc != 5)
		exit_code("expectade: infile, cmd cmd2 outfile", 2);
	if (pipe(pipe_fd) == -1)
		exit_code("error in function pipe", 111);
	pid = fork();
	if (pid == -1)
		exit_code("pid filed", 1);
	if (pid == 0)
		child_process(pipe_fd, argv, env);
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0); 
		parent_process(pipe_fd, argv,  env);
	}
	return (0);
}
