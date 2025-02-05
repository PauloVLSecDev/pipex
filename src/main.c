/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:41:36 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/02/04 19:22:08 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char *argv[], char **env)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		status;

	if (argc != 5)
		exit_code("expectade: infile, cmd cmd2 outfile", 2, NULL);
	if (pipe(pipe_fd) == -1)
		close_pipe(pipe_fd);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		child_process(pipe_fd, argv, env);
	}
	else if (pid > 0)
	{
		close(pipe_fd[1]);
		parent_process(pipe_fd, argv, env);
		waitpid(pid, &status, 0);
	}
	return (0);
}
