/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:41:36 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/01/24 15:39:50 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main (int argc, char *argv[], char **env)
{
	int	pipe_fd[2];
	pid_t	pid;
	int		status;

	//ft_printf("socorro\n ");
	if(argc != 5)
		perror("teste");
	if (pipe(pipe_fd) == -1)
		exit_with_menssage("error in function pipe", 111);
	pid = fork();
	if (pid == 0)
		child_process(pipe_fd, argv, env);//child
	else if (pid == 1)
	{
		waitpid(pid, &status, 0); 
		parent_process(pipe_fd, argv,  env);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
	}
	else
		perror(" erro ao fazer o fork");
	return (0);
}
